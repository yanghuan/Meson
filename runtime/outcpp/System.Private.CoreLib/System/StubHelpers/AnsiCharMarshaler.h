#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array)
FORWARDS(Boolean)
FORWARDS(Byte)
FORWARDS(Char)
FORWARDS(Int32)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::StubHelpers {
namespace AnsiCharMarshalerNamespace {
class AnsiCharMarshaler {
  public: static Array<Byte> DoAnsiConversion(String str, Boolean fBestFit, Boolean fThrowOnUnmappableChar, Int32& cbLength);
  public: static Byte ConvertToNative(Char managedChar, Boolean fBestFit, Boolean fThrowOnUnmappableChar);
  public: static Char ConvertToManaged(Byte nativeChar);
};
} // namespace AnsiCharMarshalerNamespace
using AnsiCharMarshaler = AnsiCharMarshalerNamespace::AnsiCharMarshaler;
} // namespace System::Private::CoreLib::System::StubHelpers
