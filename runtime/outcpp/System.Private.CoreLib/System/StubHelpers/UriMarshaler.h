#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Char)
FORWARDS(Int32)
FORWARDS(IntPtr)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::StubHelpers {
namespace UriMarshalerNamespace {
class UriMarshaler {
  public: static String GetRawUriFromNative(IntPtr pUri);
  public: static IntPtr CreateNativeUriInstanceHelper(Char* rawUri, Int32 strLen);
  public: static IntPtr CreateNativeUriInstance(String rawUri);
};
} // namespace UriMarshalerNamespace
using UriMarshaler = UriMarshalerNamespace::UriMarshaler;
} // namespace System::Private::CoreLib::System::StubHelpers
