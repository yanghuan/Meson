#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Int32)
FORWARDS(IntPtr)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::StubHelpers {
namespace AnsiBSTRMarshalerNamespace {
class AnsiBSTRMarshaler {
  public: static IntPtr ConvertToNative(Int32 flags, String strManaged);
  public: static String ConvertToManaged(IntPtr bstr);
  public: static void ClearNative(IntPtr pNative);
};
} // namespace AnsiBSTRMarshalerNamespace
using AnsiBSTRMarshaler = AnsiBSTRMarshalerNamespace::AnsiBSTRMarshaler;
} // namespace System::Private::CoreLib::System::StubHelpers
