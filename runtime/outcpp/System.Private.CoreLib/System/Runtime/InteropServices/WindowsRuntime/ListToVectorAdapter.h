#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Int32)
FORWARDS(UInt32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices::WindowsRuntime {
namespace ListToVectorAdapterNamespace {
CLASS(ListToVectorAdapter) {
  private: static void EnsureIndexInt32(UInt32 index, Int32 listCapacity);
};
} // namespace ListToVectorAdapterNamespace
using ListToVectorAdapter = ListToVectorAdapterNamespace::ListToVectorAdapter;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices::WindowsRuntime
