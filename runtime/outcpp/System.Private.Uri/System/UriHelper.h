#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
FORWARDS(Byte)
FORWARDS(Char)
FORWARDS(Int32)
FORWARDS(ReadOnlySpan, T)
FORWARDS(Span, T)
FORWARD(String)
FORWARDS(UInt16)
} // namespace System::Private::CoreLib::System
namespace System::Private::Uri::System::Text {
FORWARDS(ValueStringBuilder)
} // namespace System::Private::Uri::System::Text
namespace System::Private::CoreLib::System::Text {
FORWARD(Encoding)
} // namespace System::Private::CoreLib::System::Text
namespace System::Private::Uri::System {
enum class UnescapeMode;
FORWARD(UriParser)
namespace UriHelperNamespace {
using namespace ::System::Private::CoreLib::System;
using namespace ::System::Private::CoreLib::System::Text;
using namespace ::System::Private::Uri::System::Text;
class UriHelper {
  public: static ReadOnlySpan<Boolean> get_UnreservedReservedTable();
  public: static ReadOnlySpan<Boolean> get_UnreservedTable();
  public: static Boolean TestForSubPath(Char* selfPtr, UInt16 selfLength, Char* otherPtr, UInt16 otherLength, Boolean ignoreCase);
  public: static String EscapeString(String stringToEscape, Boolean checkExistingEscaped, ReadOnlySpan<Boolean> unreserved, Char forceEscape1, Char forceEscape2);
  public: static Array<Char> EscapeString(ReadOnlySpan<Char> stringToEscape, Array<Char> dest, Int32& destPos, Boolean checkExistingEscaped, Char forceEscape1, Char forceEscape2);
  private: static void EscapeStringToBuilder(ReadOnlySpan<Char> stringToEscape, ValueStringBuilder& vsb, ReadOnlySpan<Boolean> noEscape, Boolean checkExistingEscaped);
  public: static Array<Char> UnescapeString(String input, Int32 start, Int32 end, Array<Char> dest, Int32& destPosition, Char rsvd1, Char rsvd2, Char rsvd3, UnescapeMode unescapeMode, UriParser syntax, Boolean isQuery);
  public: static Array<Char> UnescapeString(Char* pStr, Int32 start, Int32 end, Array<Char> dest, Int32& destPosition, Char rsvd1, Char rsvd2, Char rsvd3, UnescapeMode unescapeMode, UriParser syntax, Boolean isQuery);
  public: static void UnescapeString(String input, Int32 start, Int32 end, ValueStringBuilder& dest, Char rsvd1, Char rsvd2, Char rsvd3, UnescapeMode unescapeMode, UriParser syntax, Boolean isQuery);
  public: static void UnescapeString(Char* pStr, Int32 start, Int32 end, ValueStringBuilder& dest, Char rsvd1, Char rsvd2, Char rsvd3, UnescapeMode unescapeMode, UriParser syntax, Boolean isQuery);
  public: static void MatchUTF8Sequence(ValueStringBuilder& dest, Span<Char> unescapedChars, Int32 charCount, Array<Byte> bytes, Int32 byteCount, Boolean isQuery, Boolean iriParsing);
  public: static void EscapeAsciiChar(Byte b, ValueStringBuilder& to);
  public: static Char EscapedAscii(Char digit, Char next);
  public: static Boolean IsNotSafeForUnescape(Char ch);
  public: static Boolean IsUnreserved(Int32 c);
  public: static Boolean IsGenDelim(Char ch);
  public: static Boolean IsLWS(Char ch);
  public: static Boolean IsAsciiLetter(Char character);
  public: static Boolean IsAsciiLetterOrDigit(Char character);
  public: static Boolean IsHexDigit(Char character);
  public: static Boolean IsBidiControlCharacter(Char ch);
  public: static String StripBidiControlCharacter(Char* strToClean, Int32 start, Int32 length);
  public: static Encoding s_noFallbackCharUTF8;
  public: static Array<Char> s_WSchars;
};
} // namespace UriHelperNamespace
using UriHelper = UriHelperNamespace::UriHelper;
} // namespace System::Private::Uri::System
