#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARDS(Int32)
FORWARDS(IntPtr)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::StubHelpers {
namespace FixedWSTRMarshalerNamespace {
class FixedWSTRMarshaler : public Object::in {
  public: static void ConvertToNative(String strManaged, IntPtr nativeHome, Int32 length);
};
} // namespace FixedWSTRMarshalerNamespace
using FixedWSTRMarshaler = FixedWSTRMarshalerNamespace::FixedWSTRMarshaler;
} // namespace System::Private::CoreLib::System::StubHelpers
