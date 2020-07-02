#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
FORWARDS(IntPtr)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices::WindowsRuntime {
FORWARDS(HSTRING_HEADER)
} // namespace System::Private::CoreLib::System::Runtime::InteropServices::WindowsRuntime
namespace System::Private::CoreLib::System::StubHelpers {
namespace HStringMarshalerNamespace {
using namespace ::System::Private::CoreLib::System::Runtime::InteropServices::WindowsRuntime;
class HStringMarshaler {
  public: static IntPtr ConvertToNative(String managed);
  public: static IntPtr ConvertToNativeReference(String managed, HSTRING_HEADER* hstringHeader);
  public: static String ConvertToManaged(IntPtr hstring);
  public: static void ClearNative(IntPtr hstring);
};
} // namespace HStringMarshalerNamespace
using HStringMarshaler = HStringMarshalerNamespace::HStringMarshaler;
} // namespace System::Private::CoreLib::System::StubHelpers
