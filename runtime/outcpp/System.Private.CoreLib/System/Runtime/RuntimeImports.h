#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Byte)
FORWARDS(UInt64)
FORWARDS(IntPtr)
FORWARDS(UIntPtr)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime {
namespace RuntimeImportsNamespace {
CLASS(RuntimeImports) {
  public: static void RhZeroMemory(Byte& b, UInt64 byteLength);
  public: static void RhZeroMemory(IntPtr p, UIntPtr byteLength);
  private: static void RhZeroMemory(void* b, UInt64 byteLength);
  public: static void RhBulkMoveWithWriteBarrier(Byte& destination, Byte& source, UInt64 byteCount);
};
} // namespace RuntimeImportsNamespace
using RuntimeImports = RuntimeImportsNamespace::RuntimeImports;
} // namespace System::Private::CoreLib::System::Runtime
