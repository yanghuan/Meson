#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Int32)
FORWARDS(UInt32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices::WindowsRuntime {
namespace IReadOnlyListToIVectorViewAdapterNamespace {
CLASS(IReadOnlyListToIVectorViewAdapter) {
  private: static void EnsureIndexInt32(UInt32 index, Int32 listCapacity);
};
} // namespace IReadOnlyListToIVectorViewAdapterNamespace
using IReadOnlyListToIVectorViewAdapter = IReadOnlyListToIVectorViewAdapterNamespace::IReadOnlyListToIVectorViewAdapter;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices::WindowsRuntime
