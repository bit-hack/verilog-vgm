//  ____     ___ _________  __      __  _________   ____
// |    |   |   |______   \/  \    /  \/  _  \   \ /   /\
// |    |   |   ||    |  _/\   \/\/   /  /_\  \   Y   / /
// |    |___|   ||    |   \ \        /    |    \     / /
// |________|___||________/\ \__/\__/\____|____/\___/ /
// \________\____\\_______\/  \_\/\_\/\___\____\/\__\/
//

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

#include "wave.h"

#if !defined(_MSC_VER)
#define PACK__ __attribute__((__packed__))
#else
#define PACK__
#pragma pack(push, 1)
#endif

namespace {

constexpr uint32_t fourcc(uint8_t a, uint8_t b, uint8_t c, uint8_t d) {
  return (d << 24) | (c << 16) | (b << 8) | a;
}

enum {
  FMT_PCM = 1,
  FCC_RIFF = fourcc('R', 'I', 'F', 'F'),
  FCC_WAVE = fourcc('W', 'A', 'V', 'E'),
  FCC_FMT = fourcc('f', 'm', 't', ' '),
  FCC_DATA = fourcc('d', 'a', 't', 'a'),
};

struct chunk_t {
  uint32_t chunk_id_;
  uint32_t chunk_size_;
};

struct PACK__ riff_t {
  uint32_t format_;
};

struct PACK__ fmt_t {
  uint16_t format_;
  uint16_t channels_;
  uint32_t sample_rate_;
  uint32_t byte_rate_;
  uint16_t block_align_;
  uint16_t bit_depth_;
};

#if defined(_MSC_VER)
#pragma pack(pop)
#endif

struct file_t {

  file_t(const char *path, const char *mode) : _fd(fopen(path, mode)) {}

  ~file_t() { fclose(_fd); }

  FILE *operator()() const { return _fd; }

  operator bool() const { return _fd != nullptr; }

  template <typename type_t> bool read(type_t &out) const {
    return fread(&out, sizeof(type_t), 1, _fd) == 1;
  }

  template <typename type_t> bool write(const type_t &out) const {
    return fwrite(&out, sizeof(type_t), 1, _fd) == 1;
  }

protected:
  FILE *_fd;
};

} // namespace

bool wave_t::load(const char *path) {

  file_t fd{path, "rb"};
  if (!fd) {
    return false;
  }

  riff_t riff;
  fmt_t fmt;

  // read riff header
  const auto on_riff = [&](uint32_t id, uint32_t size) {
    if (!fd.read(riff)) {
      return false;
    }
    if (riff.format_ != FCC_WAVE) {
      return false;
    }
    return true;
  };

  // read format chunk
  const auto on_fmt = [&](uint32_t id, uint32_t size) {
    if (!fd.read(fmt)) {
      return false;
    }
    if (fmt.format_ != FMT_PCM) {
      return false;
    }
    if (fmt.bit_depth_ & 7 /* multiple of 8 */) {
      return false;
    }
    if (fmt.channels_ != 1 && fmt.channels_ != 2) {
      return false;
    }
    bit_depth_ = fmt.bit_depth_;
    sample_rate_ = fmt.sample_rate_;
    channels_ = fmt.channels_;
    return true;
  };

  // parse a data chunk
  const auto on_data = [&](uint32_t id, uint32_t size) {
    // read sample data
    sample_bytes_ = size;
    samples_ = std::make_unique<uint8_t[]>(size);
    if (fread(samples_.get(), size, 1, fd()) != 1) {
      return false;
    }
    return true;
  };

  // parse chunks
  uint32_t done = 0;
  while (done != 0x7) {

    // read chunk header
    chunk_t hdr;
    if (!fd.read(hdr)) {
      return false;
    }

    // switch on fourcc code
    switch (hdr.chunk_id_) {
    case FCC_RIFF:
      if (!on_riff(hdr.chunk_id_, hdr.chunk_size_)) {
        return false;
      }
      done |= 0x1;
      break;
    case FCC_FMT: {
      const long pos = ftell(fd());
      if (!on_fmt(hdr.chunk_id_, hdr.chunk_size_)) {
        return false;
      }
      fseek(fd(), pos + hdr.chunk_size_, SEEK_SET);
      done |= 0x2;
      break;
    }
    case FCC_DATA:
      if (!on_data(hdr.chunk_id_, hdr.chunk_size_)) {
        return false;
      }
      done |= 0x4;
      break;
    default:
      fseek(fd(), hdr.chunk_size_, SEEK_CUR);
      break;
    }
  }

  // success
  return true;
}

bool wave_t::save(const char *path) {

  file_t file(path, "wb");
  if (!file) {
    return false;
  }

  // write riff header
  chunk_t riff_hdr;
  riff_hdr.chunk_id_ = FCC_RIFF;
  riff_hdr.chunk_size_ = 20 + sizeof(fmt_t) + sample_bytes_;
  file.write(riff_hdr);

  riff_t riff;
  riff.format_ = FCC_WAVE;
  file.write(riff);

  // write format block
  chunk_t fmt_hdr;
  fmt_hdr.chunk_id_ = FCC_FMT;
  fmt_hdr.chunk_size_ = sizeof(fmt_t);
  file.write(fmt_hdr);

  fmt_t fmt;
  fmt.format_ = FMT_PCM;
  fmt.bit_depth_ = bit_depth_;
  fmt.sample_rate_ = sample_rate_;
  fmt.channels_ = channels_;
  fmt.byte_rate_ = sample_rate_ * channels_ * bit_depth_ / 8;
  fmt.block_align_ = channels_ * bit_depth_ / 8;
  file.write(fmt);

  // write data block
  file.write<uint32_t>(FCC_DATA);
  file.write<uint32_t>(sample_bytes_); // chunk size
  if (fwrite(samples_.get(), sample_bytes_, 1, file()) != 1) {
    return false;
  }

  return true;
}

bool wave_t::create(const wave_info_t &info) {

  // validate channel count
  if (info.channels != 1 && info.channels != 2) {
    return false;
  }
  channels_ = info.channels;

  // validate bit depth
  if (info.depth != 8 && info.depth != 16) {
    return false;
  }
  bit_depth_ = info.depth;

  // validate sample rate
  switch (info.rate) {
  case 44100:
  case 22050:
  case 11025:
    break;
  default:
    return false;
  }
  sample_rate_ = info.rate;

  // allocate space for samples
  sample_bytes_ = info.depth / 8 * info.samples;
  samples_ = std::make_unique<uint8_t[]>(sample_bytes_);

  return true;
}
