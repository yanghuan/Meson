#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
FORWARDS(Byte)
FORWARDS(Int32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Buffers::Text {
namespace ParserHelpersNamespace {
class ParserHelpers {
  public: static Boolean IsDigit(Int32 i);
  public: static Boolean TryParseThrowFormatException(Int32& bytesConsumed);
  public: static Array<Byte> s_hexLookup;
};
} // namespace ParserHelpersNamespace
using ParserHelpers = ParserHelpersNamespace::ParserHelpers;
} // namespace System::Private::CoreLib::System::Buffers::Text
