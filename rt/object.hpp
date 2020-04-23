#pragma once

#include <cstdint>

typedef unsigned char utf8_char;

const utf8_char test[] = "dddddddddddddd";


struct str
{
  uint16_t len;
  utf8_char data[];
};

const str s = { 4, "dddddd" };