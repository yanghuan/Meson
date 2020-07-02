#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Byte.h>
#include <System.Private.CoreLib/System/Int16.h>
#include <System.Private.CoreLib/System/Int32.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARD(String)
FORWARDS(ReadOnlySpan, T)
FORWARDS(Char)
FORWARDS(UInt32)
FORWARD_(Array, T1, T2)
FORWARDS(Span, T)
FORWARD(Object)
FORWARD(IFormatProvider)
namespace GuidNamespace {
struct Guid {
  private: enum class GuidParseThrowStyle : uint8_t {
    None = 0,
    All = 1,
    AllButOverflow = 2,
  };
  friend struct GuidResult;
  public: static Guid Parse(String input);
  public: static Guid Parse(ReadOnlySpan<Char> input);
  public: static Boolean TryParse(String input, Guid& result);
  public: static Boolean TryParse(ReadOnlySpan<Char> input, Guid& result);
  public: static Guid ParseExact(String input, String format);
  public: static Guid ParseExact(ReadOnlySpan<Char> input, ReadOnlySpan<Char> format);
  public: static Boolean TryParseExact(String input, String format, Guid& result);
  public: static Boolean TryParseExact(ReadOnlySpan<Char> input, ReadOnlySpan<Char> format, Guid& result);
  private: static Boolean TryParseGuid(ReadOnlySpan<Char> guidString, GuidResult& result);
  private: static Boolean TryParseExactB(ReadOnlySpan<Char> guidString, GuidResult& result);
  private: static Boolean TryParseExactD(ReadOnlySpan<Char> guidString, GuidResult& result);
  private: static Boolean TryParseExactN(ReadOnlySpan<Char> guidString, GuidResult& result);
  private: static Boolean TryParseExactP(ReadOnlySpan<Char> guidString, GuidResult& result);
  private: static Boolean TryParseExactX(ReadOnlySpan<Char> guidString, GuidResult& result);
  private: static Boolean TryParseHex(ReadOnlySpan<Char> guidString, Int16& result, Boolean& overflow);
  private: static Boolean TryParseHex(ReadOnlySpan<Char> guidString, UInt32& result);
  private: static Boolean TryParseHex(ReadOnlySpan<Char> guidString, UInt32& result, Boolean& overflow);
  private: static ReadOnlySpan<Char> EatAllWhitespace(ReadOnlySpan<Char> str);
  private: static Boolean IsHexPrefix(ReadOnlySpan<Char> str, Int32 i);
  public: Array<Byte> ToByteArray();
  public: Boolean TryWriteBytes(Span<Byte> destination);
  public: String ToString();
  public: Int32 GetHashCode();
  public: Boolean Equals(Object o);
  public: Boolean Equals(Guid g);
  private: Int32 GetResult(UInt32 me, UInt32 them);
  public: Int32 CompareTo(Object value);
  public: Int32 CompareTo(Guid value);
  public: String ToString(String format);
  private: static Char HexToChar(Int32 a);
  private: static Int32 HexsToChars(Char* guidChars, Int32 a, Int32 b);
  private: static Int32 HexsToCharsHexOutput(Char* guidChars, Int32 a, Int32 b);
  public: String ToString(String format, IFormatProvider provider);
  public: Boolean TryFormat(Span<Char> destination, Int32& charsWritten, ReadOnlySpan<Char> format);
  public: static Guid NewGuid();
  public: static Guid Empty;
  private: Int32 _a;
  private: Int16 _b;
  private: Int16 _c;
  private: Byte _d;
  private: Byte _e;
  private: Byte _f;
  private: Byte _g;
  private: Byte _h;
  private: Byte _i;
  private: Byte _j;
  private: Byte _k;
};
struct GuidResult {
  public: void SetFailure(Boolean overflow, String failureMessageID);
  private: Guid::GuidParseThrowStyle _throwStyle;
  public: Guid _parsedGuid;
};
} // namespace GuidNamespace
using Guid = GuidNamespace::Guid;
} // namespace System::Private::CoreLib::System
