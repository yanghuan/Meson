#pragma once

#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/IntPtr.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System::Threading {
namespace NativeOverlappedNamespace {
struct NativeOverlapped : public valueType<NativeOverlapped> {
  public: IntPtr InternalLow;
  public: IntPtr InternalHigh;
  public: Int32 OffsetLow;
  public: Int32 OffsetHigh;
  public: IntPtr EventHandle;
};
} // namespace NativeOverlappedNamespace
using NativeOverlapped = NativeOverlappedNamespace::NativeOverlapped;
} // namespace System::Private::CoreLib::System::Threading
