#pragma once

#include <System.Private.CoreLib/System/IntPtr.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace PortableTailCallFrameNamespace {
struct PortableTailCallFrame : public valueType<PortableTailCallFrame> {
  public: PortableTailCallFrame* Prev;
  public: IntPtr TailCallAwareReturnAddress;
  public: delegate* NextCall;
};
} // namespace PortableTailCallFrameNamespace
using PortableTailCallFrame = PortableTailCallFrameNamespace::PortableTailCallFrame;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
