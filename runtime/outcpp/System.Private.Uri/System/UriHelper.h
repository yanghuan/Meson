#pragma once

#include <System.Private.CoreLib/System/Object.h>
#include <System.Private.CoreLib/System/String.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
FORWARDS(Byte)
FORWARDS(Char)
FORWARDS(Int32)
FORWARDS(IntPtr)
FORWARDS(ReadOnlySpan, T)
FORWARDS(Span, T)
FORWARDS_(ValueTuple, T1, T2, T3, T4, T5, T6, T7, T8, T9)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Buffers {
FORWARD(SpanAction, T, TArg)
} // namespace System::Private::CoreLib::System::Buffers
namespace System::Private::Uri::System::Text {
FORWARDS(ValueStringBuilder)
} // namespace System::Private::Uri::System::Text
namespace System::Private::CoreLib::System::Text {
FORWARD(Encoding)
} // namespace System::Private::CoreLib::System::Text
namespace System::Private::Uri::System {
enum class UnescapeMode : int32_t;
FORWARD(UriParser)
namespace UriHelperNamespace {
using namespace ::System::Private::CoreLib::System;
using namespace ::System::Private::CoreLib::System::Buffers;
using namespace ::System::Private::CoreLib::System::Text;
using namespace System::Text;
using ValueStringBuilder = Text::ValueStringBuilder;
class UriHelper {
  private: CLASS(__c) : public object {
    public: static void cctor();
    public: void ctor();
    public: void _StripBidiControlCharacters_b__27_0(Span<Char> buffer, ValueTuple<IntPtr, Int32> state);
    public: static __c __9;
    public: static SpanAction<Char, ValueTuple<IntPtr, Int32>> __9__27_0;
  };
  public: static ReadOnlySpan<Boolean> get_UnreservedReservedTable();
  public: static ReadOnlySpan<Boolean> get_UnreservedTable();
  public: static Boolean TestForSubPath(Char* selfPtr, Int32 selfLength, Char* otherPtr, Int32 otherLength, Boolean ignoreCase);
  public: static String EscapeString(String stringToEscape, Boolean checkExistingEscaped, ReadOnlySpan<Boolean> unreserved, Char forceEscape1 = '\0', Char forceEscape2 = '\0');
  public: static Array<Char> EscapeString(ReadOnlySpan<Char> stringToEscape, Array<Char> dest, Int32& destPos, Boolean checkExistingEscaped, Char forceEscape1 = '\0', Char forceEscape2 = '\0');
  private: static void EscapeStringToBuilder(ReadOnlySpan<Char> stringToEscape, ValueStringBuilder& vsb, ReadOnlySpan<Boolean> noEscape, Boolean checkExistingEscaped);
  public: static Array<Char> UnescapeString(String input, Int32 start, Int32 end, Array<Char> dest, Int32& destPosition, Char rsvd1, Char rsvd2, Char rsvd3, UnescapeMode unescapeMode, UriParser syntax, Boolean isQuery);
  public: static Array<Char> UnescapeString(Char* pStr, Int32 start, Int32 end, Array<Char> dest, Int32& destPosition, Char rsvd1, Char rsvd2, Char rsvd3, UnescapeMode unescapeMode, UriParser syntax, Boolean isQuery);
  public: static void UnescapeString(String input, Int32 start, Int32 end, ValueStringBuilder& dest, Char rsvd1, Char rsvd2, Char rsvd3, UnescapeMode unescapeMode, UriParser syntax, Boolean isQuery);
  public: static void UnescapeString(Char* pStr, Int32 start, Int32 end, ValueStringBuilder& dest, Char rsvd1, Char rsvd2, Char rsvd3, UnescapeMode unescapeMode, UriParser syntax, Boolean isQuery);
  public: static void MatchUTF8Sequence(ValueStringBuilder& dest, Span<Char> unescapedChars, Int32 charCount, Array<Byte> bytes, Int32 byteCount, Boolean isQuery, Boolean iriParsing);
  public: static void EscapeAsciiChar(Byte b, ValueStringBuilder& to);
  public: static Char DecodeHexChars(Int32 first, Int32 second);
  public: static Boolean IsNotSafeForUnescape(Char ch);
  public: static Boolean IsGenDelim(Char ch);
  public: static Boolean IsLWS(Char ch);
  public: static Boolean IsAsciiLetter(Char character);
  public: static Boolean IsAsciiLetterOrDigit(Char character);
  public: static Boolean IsHexDigit(Char character);
  public: static Boolean IsBidiControlCharacter(Char ch);
  public: static String StripBidiControlCharacters(ReadOnlySpan<Char> strToClean, String backingString = nullptr);
  public: static void cctor();
  public: static void _EscapeString_g__EnsureCapacity3_0(Array<Char> dest, Int32 destSize, Int32 requiredSize);
  public: static Encoding s_noFallbackCharUTF8;
  public: static Array<Char> s_WSchars;
};
} // namespace UriHelperNamespace
using UriHelper = UriHelperNamespace::UriHelper;
} // namespace System::Private::Uri::System
