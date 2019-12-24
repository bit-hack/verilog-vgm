#pragma once

#include <cassert>
#include <cstdint>
#include <memory>


struct vgm_t {

  vgm_t()
    : _size(0)
  {}

  const uint8_t *data() const {
    return &_raw[0];
  }

  const size_t size() {
    return _size;
  }

  bool load(const char *path);

protected:
  std::unique_ptr<uint8_t []> _raw;
  size_t _size;

  bool _read_file(const char *path);
};

struct vgm_hdr_t {

  vgm_hdr_t(vgm_t &v)
    : _vgm(v)
  {}

  bool valid() const {
    const uint8_t *src = _vgm.data();
    return memcmp(src, "Vgm ", 4) == 0;
  }

  uint32_t clock_AY8910() const {
    if (version() >= 0x151) {
      // typical 1789750
      const uint8_t *src = _vgm.data() + 0x74;
      return *(uint32_t*)src;
    }
    return 0;
  }

  uint32_t clock_SN76489() const {
    // typical 3579545
    const uint8_t *src = _vgm.data() + 0x0c;
    return *(uint32_t*)src;
  }

  uint32_t data_offset() const {
    if (version() >= 0x150) {
      const uint8_t *src = _vgm.data() + 0x34;
      return 0x34 + *(uint32_t*)src;
    }
    else {
      return 0x40;
    }
  }

  uint32_t version() const {
    const uint8_t *src = _vgm.data() + 0x08;
    return *(uint32_t*)src;
  }

protected:
  vgm_t &_vgm;
};

struct vgm_stream_t {

  vgm_stream_t(vgm_t &v)
    : _vgm(v)
    , _hdr(v)
    , delay(0)
  {
    _start = _vgm.data() + _hdr.data_offset();
    _end = _vgm.data() + _vgm.size();
    _ptr = _start;
  }

  bool advance();

  virtual void write_ay8910(uint8_t reg, uint8_t value) {
    // empty
  }

  virtual void write_sn76489(uint8_t value) {
    // empty
  }

  bool finished() const {
    return _ptr == _end;
  }

  uint32_t delay;

protected:

  vgm_hdr_t _hdr;
  vgm_t &_vgm;

  const uint8_t *_start;
  const uint8_t *_end;

  const uint8_t *_ptr;

  template <typename type_t>
  type_t read() {
    assert(_ptr < _end);
    const type_t out = *(const type_t*)_ptr;
    _ptr += sizeof(type_t);
    return out;
  }
};
