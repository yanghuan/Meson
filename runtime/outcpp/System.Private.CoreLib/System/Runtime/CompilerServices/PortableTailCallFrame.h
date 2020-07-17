#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/IntPtr.h>

namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace PortableTailCallFrameNamespace {
struct PortableTailCallFrame {
  public: void Ctor();
  public: PortableTailCallFrame* Prev;
  public: IntPtr TailCallAwareReturnAddress;
  public: IntPtr NextCall;
};
} // namespace PortableTailCallFrameNamespace
using PortableTailCallFrame = PortableTailCallFrameNamespace::PortableTailCallFrame;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
