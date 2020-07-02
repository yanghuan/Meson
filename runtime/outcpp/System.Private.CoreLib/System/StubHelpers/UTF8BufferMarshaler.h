#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Text {
FORWARD(StringBuilder)
} // namespace System::Private::CoreLib::System::Text
namespace System::Private::CoreLib::System {
FORWARDS(IntPtr)
FORWARDS(Int32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::StubHelpers {
namespace UTF8BufferMarshalerNamespace {
using namespace ::System::Private::CoreLib::System::Text;
class UTF8BufferMarshaler {
  public: static IntPtr ConvertToNative(StringBuilder sb, IntPtr pNativeBuffer, Int32 flags);
  public: static void ConvertToManaged(StringBuilder sb, IntPtr pNative);
};
} // namespace UTF8BufferMarshalerNamespace
using UTF8BufferMarshaler = UTF8BufferMarshalerNamespace::UTF8BufferMarshaler;
} // namespace System::Private::CoreLib::System::StubHelpers
