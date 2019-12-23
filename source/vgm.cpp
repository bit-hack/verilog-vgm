#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#include "vgm.h"


bool vgm_t::_read_file(const char *path) {
  // close old file
  _raw.reset();
  _size = 0;
  // open file
  FILE *fd = fopen(path, "rb");
  if (!fd) {
    return false;
  }
  // get file size
  fseek(fd, 0, SEEK_END);
  size_t sz = ftell(fd);
  fseek(fd, 0, SEEK_SET);
  // check for valid size
  if (sz == 0) {
    fclose(fd);
    return false;
  }
  // read new file
  _raw.reset(new uint8_t[sz]);
  memset(_raw.get(), 0, sz);
  fread(_raw.get(), 1, sz, fd);
  _size = sz;
  // success
  fclose(fd);
  return true;
}

bool vgm_t::load(const char *path) {
  if (!_read_file(path)) {
    return false;
  }
  vgm_hdr_t hdr(*this);
  return hdr.valid();
}

bool vgm_stream_t::advance() {

  const uint8_t op = read<uint8_t>();

  if ((op & 0xf0) == 0x70) {
    delay += op & 0x0f;
    return true;
  }

  switch (op) {
  case 0x61:
  {
    delay += read<uint16_t>();
    break;
  }
  case 0x62:
  {
    delay += 735;
    break;
  }
  case 0x63:
  {
    delay += 882;
    break;
  }
  case 0x66:
  {
    _ptr = _end;
    break;
  }
  case 0xa0:
  {
    const uint8_t reg = read<uint8_t>();
    const uint8_t val = read<uint8_t>();
    write_ay8910(reg, val);
    break;
  }
  default:
    printf("unknown opcode %02x\n", (int)op);
    assert(false);
    return false;
  }

  return true;
}
