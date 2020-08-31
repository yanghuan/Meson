#include "Unsafe-dep.h"

namespace System::Private::CoreLib::Internal::Runtime::CompilerServices::UnsafeNamespace {
void Unsafe::InitBlockUnaligned(Byte& startAddress, Byte value, UInt32 byteCount) {
  for (UInt32 num = 0u; num < byteCount; num++) {
    AddByteOffset(startAddress, (UIntPtr)num) = value;
  }
}

} // namespace System::Private::CoreLib::Internal::Runtime::CompilerServices::UnsafeNamespace
