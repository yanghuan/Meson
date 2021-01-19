#pragma once

#include <System.Private.CoreLib/System/IntPtr.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System::Runtime::CompilerServices {
FORWARDS(PortableTailCallFrame)
namespace TailCallTlsNamespace {
struct TailCallTls : public valueType<TailCallTls> {
  public: PortableTailCallFrame* Frame;
  public: IntPtr ArgBuffer;
};
} // namespace TailCallTlsNamespace
using TailCallTls = TailCallTlsNamespace::TailCallTls;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
