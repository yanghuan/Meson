#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/UInt32.h>

namespace System::Private::CoreLib::System {
FORWARDS(Int32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading {
namespace FastRandomNamespace {
struct FastRandom {
  public: Int32 Next(Int32 maxValue);
  private: UInt32 _w;
  private: UInt32 _x;
  private: UInt32 _y;
  private: UInt32 _z;
};
} // namespace FastRandomNamespace
using FastRandom = FastRandomNamespace::FastRandom;
} // namespace System::Private::CoreLib::System::Threading
