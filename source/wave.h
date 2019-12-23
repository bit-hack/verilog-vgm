//  ____     ___ _________  __      __  _________   ____
// |    |   |   |______   \/  \    /  \/  _  \   \ /   /\
// |    |   |   ||    |  _/\   \/\/   /  /_\  \   Y   / /
// |    |___|   ||    |   \ \        /    |    \     / /
// |________|___||________/\ \__/\__/\____|____/\___/ /
// \________\____\\_______\/  \_\/\_\/\___\____\/\__\/
//

#pragma once
#include <cassert>
#include <cstdint>
#include <memory>

struct wave_info_t {
  uint32_t samples;
  uint32_t channels;
  uint32_t depth;
  uint32_t rate;
};

struct wave_t {

  bool create(const wave_info_t &info);
  bool save(const char *path);
  bool load(const char *path);

  uint32_t num_frames() const {
    const uint32_t sample_size = bit_depth_ / 8;
    assert(sample_size);
    const uint32_t num_samples = uint32_t(sample_bytes_) / sample_size;
    assert(channels_);
    const uint32_t num_frames = num_samples / channels_;
    return num_frames;
  }

  uint32_t num_channels() const { return channels_; }

  uint32_t bit_depth() const { return bit_depth_; }

  uint32_t sample_rate() const { return sample_rate_; }

  // todo: set sample rate

  template <typename type_t> type_t *get() {
    return reinterpret_cast<type_t *>(samples_.get());
  }

  template <typename type_t> const type_t *get() const {
    return reinterpret_cast<const type_t *>(samples_.get());
  }

  uint32_t length() const { return uint32_t(sample_bytes_); }

  wave_t()
      : sample_bytes_(0), samples_(), sample_rate_(0), bit_depth_(0),
        channels_(0) {}

protected:
  size_t sample_bytes_;
  std::unique_ptr<uint8_t[]> samples_;
  uint32_t sample_rate_;
  uint32_t bit_depth_;
  uint32_t channels_;
};
