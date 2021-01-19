#include "FastRandom-dep.h"

#include <System.Private.CoreLib/System/UInt32-dep.h>

namespace System::Private::CoreLib::System::Threading::FastRandomNamespace {
FastRandom::FastRandom(Int32 seed) {
  _x = (UInt32)seed;
  _w = 88675123u;
  _y = 362436069u;
  _z = 521288629u;
}

Int32 FastRandom::Next(Int32 maxValue) {
  UInt32 num = _x ^ (_x << 11);
  _x = _y;
  _y = _z;
  _z = _w;
  _w = _w ^ (_w >> 19) ^ (num ^ (num >> 8));
  return (Int32)(_w % (UInt32)maxValue);
}

} // namespace System::Private::CoreLib::System::Threading::FastRandomNamespace
