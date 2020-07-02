#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Char)
FORWARDS(UInt16)
FORWARDS(Boolean)
FORWARD(String)
FORWARDS(Int32)
FORWARD_(Array, T1, T2)
FORWARDS(Int16)
FORWARDS(Span, T)
FORWARDS(Byte)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Text {
FORWARD(Encoding)
} // namespace System::Private::CoreLib::System::Text
namespace System::Private::Uri::System {
enum class UnescapeMode;
FORWARD(UriParser)
namespace UriHelperNamespace {
using namespace ::System::Private::CoreLib::System;
using namespace ::System::Private::CoreLib::System::Text;
class UriHelper {
  public: static Boolean TestForSubPath(Char* selfPtr, UInt16 selfLength, Char* otherPtr, UInt16 otherLength, Boolean ignoreCase);
  public: static Array<Char> EscapeString(String input, Int32 start, Int32 end, Array<Char> dest, Int32& destPos, Boolean isUriString, Char force1, Char force2, Char rsvd);
  private: static Array<Char> EnsureDestinationSize(Char* pStr, Array<Char> dest, Int32 currentInputPos, Int16 charsToAdd, Int16 minReallocateChars, Int32& destPos, Int32 prevInputPos);
  public: static Array<Char> UnescapeString(String input, Int32 start, Int32 end, Array<Char> dest, Int32& destPosition, Char rsvd1, Char rsvd2, Char rsvd3, UnescapeMode unescapeMode, UriParser syntax, Boolean isQuery);
  public: static Array<Char> UnescapeString(Char* pStr, Int32 start, Int32 end, Array<Char> dest, Int32& destPosition, Char rsvd1, Char rsvd2, Char rsvd3, UnescapeMode unescapeMode, UriParser syntax, Boolean isQuery);
  public: static void MatchUTF8Sequence(Char* pDest, Array<Char> dest, Int32& destOffset, Span<Char> unescapedChars, Int32 charCount, Array<Byte> bytes, Int32 byteCount, Boolean isQuery, Boolean iriParsing);
  public: static void EscapeAsciiChar(Char ch, Array<Char> to, Int32& pos);
  public: static Char EscapedAscii(Char digit, Char next);
  public: static Boolean IsNotSafeForUnescape(Char ch);
  private: static Boolean IsReservedUnreservedOrHash(Char c);
  public: static Boolean IsUnreserved(Char c);
  public: static Boolean Is3986Unreserved(Char c);
  public: static Boolean IsGenDelim(Char ch);
  public: static Boolean IsLWS(Char ch);
  public: static Boolean IsAsciiLetter(Char character);
  public: static Boolean IsAsciiLetterOrDigit(Char character);
  public: static Boolean IsBidiControlCharacter(Char ch);
  public: static String StripBidiControlCharacter(Char* strToClean, Int32 start, Int32 length);
  public: static Array<Char> s_hexUpperChars;
  public: static Encoding s_noFallbackCharUTF8;
  public: static Array<Char> s_WSchars;
};
} // namespace UriHelperNamespace
using UriHelper = UriHelperNamespace::UriHelper;
} // namespace System::Private::Uri::System
