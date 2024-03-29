#pragma once

#include <System.Private.CoreLib/System/Byte.h>
#include <System.Private.CoreLib/System/Int16.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array)
FORWARDS(Boolean)
FORWARDS(Char)
FORWARD_(IComparable)
FORWARD(IEquatable, T)
FORWARD(IFormatProvider)
FORWARD(IFormattable)
FORWARD(ISpanFormattable)
FORWARD(Object)
FORWARDS(ReadOnlySpan, T)
FORWARDS(Span, T)
FORWARD(String)
FORWARDS(UInt16)
FORWARDS(UInt32)
namespace GuidNamespace {
struct Guid : public valueType<Guid> {
  public: using interface = rt::TypeList<IFormattable, IComparable<>, IComparable<Guid>, IEquatable<Guid>, ISpanFormattable>;
  private: enum class GuidParseThrowStyle : uint8_t {
    None = 0,
    All = 1,
    AllButOverflow = 2,
  };
  private: FRIENDNS(GuidResult)
  public: explicit Guid(Array<Byte> b);
  public: explicit Guid(ReadOnlySpan<Byte> b);
  public: explicit Guid(UInt32 a, UInt16 b, UInt16 c, Byte d, Byte e, Byte f, Byte g, Byte h, Byte i, Byte j, Byte k);
  public: explicit Guid(Int32 a, Int16 b, Int16 c, Array<Byte> d);
  public: explicit Guid(Int32 a, Int16 b, Int16 c, Byte d, Byte e, Byte f, Byte g, Byte h, Byte i, Byte j, Byte k);
  public: explicit Guid(String g);
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
  public: static Boolean op_Equality(Guid a, Guid b);
  public: static Boolean op_Inequality(Guid a, Guid b);
  public: String ToString(String format);
  private: static Int32 HexsToChars(Char* guidChars, Int32 a, Int32 b);
  private: static Int32 HexsToCharsHexOutput(Char* guidChars, Int32 a, Int32 b);
  public: String ToString(String format, IFormatProvider provider);
  public: template <class T0 = ReadOnlySpan<Char>>
  Boolean TryFormat(Span<Char> destination, Int32& charsWritten, T0 format = rt::default__);
  private: Boolean TryFormatOfISpanFormattable(Span<Char> destination, Int32& charsWritten, ReadOnlySpan<Char> format, IFormatProvider provider);
  public: static Guid NewGuid();
  public: explicit Guid() {}
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
struct GuidResult : public valueType<GuidResult> {
  public: explicit GuidResult(Guid::GuidParseThrowStyle canThrow);
  public: void SetFailure(Boolean overflow, String failureMessageID);
  public: explicit GuidResult() {}
  private: Guid::GuidParseThrowStyle _throwStyle;
  public: Guid _parsedGuid;
};
} // namespace GuidNamespace
using Guid = GuidNamespace::Guid;
} // namespace System::Private::CoreLib::System
