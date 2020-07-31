#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(Byte)
FORWARDS(Int32)
FORWARDS(ReadOnlySpan, T)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Buffers::Text {
namespace ParserHelpersNamespace {
class ParserHelpers : public Object::in {
  public: static ReadOnlySpan<Byte> get_HexLookup();
  public: static Boolean IsDigit(Int32 i);
  public: static Boolean TryParseThrowFormatException(Int32& bytesConsumed);
  public: template <class T>
  static Boolean TryParseThrowFormatException(T& value, Int32& bytesConsumed);
  public: template <class T>
  static Boolean TryParseThrowFormatException(ReadOnlySpan<Byte> source, T& value, Int32& bytesConsumed);
};
} // namespace ParserHelpersNamespace
using ParserHelpers = ParserHelpersNamespace::ParserHelpers;
} // namespace System::Private::CoreLib::System::Buffers::Text
