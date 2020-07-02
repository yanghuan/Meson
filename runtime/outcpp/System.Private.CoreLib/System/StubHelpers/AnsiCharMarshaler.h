#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
FORWARDS(Boolean)
FORWARDS(Int32)
FORWARD_(Array, T1, T2)
FORWARDS(Byte)
FORWARDS(Char)
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
