#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(IntPtr)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::StubHelpers {
namespace BSTRMarshalerNamespace {
class BSTRMarshaler {
  public: static IntPtr ConvertToNative(String strManaged, IntPtr pNativeBuffer);
  public: static String ConvertToManaged(IntPtr bstr);
  public: static void ClearNative(IntPtr pNative);
};
} // namespace BSTRMarshalerNamespace
using BSTRMarshaler = BSTRMarshalerNamespace::BSTRMarshaler;
} // namespace System::Private::CoreLib::System::StubHelpers
