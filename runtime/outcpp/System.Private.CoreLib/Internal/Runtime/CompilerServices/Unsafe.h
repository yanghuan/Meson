#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Byte)
FORWARDS(UInt32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::Internal::Runtime::CompilerServices {
namespace UnsafeNamespace {
using namespace ::System::Private::CoreLib::System;
class Unsafe {
  public: static void InitBlockUnaligned(Byte& startAddress, Byte value, UInt32 byteCount);
};
} // namespace UnsafeNamespace
using Unsafe = UnsafeNamespace::Unsafe;
} // namespace System::Private::CoreLib::Internal::Runtime::CompilerServices
