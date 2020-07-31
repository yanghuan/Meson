#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARDS(Int32)
FORWARDS(IntPtr)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::StubHelpers {
namespace UTF8MarshalerNamespace {
class UTF8Marshaler : public Object::in {
  public: static IntPtr ConvertToNative(Int32 flags, String strManaged, IntPtr pNativeBuffer);
  public: static String ConvertToManaged(IntPtr cstr);
  public: static void ClearNative(IntPtr pNative);
};
} // namespace UTF8MarshalerNamespace
using UTF8Marshaler = UTF8MarshalerNamespace::UTF8Marshaler;
} // namespace System::Private::CoreLib::System::StubHelpers
