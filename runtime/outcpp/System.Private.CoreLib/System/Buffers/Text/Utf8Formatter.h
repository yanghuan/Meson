#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Byte.h>
#include <System.Private.CoreLib/System/Guid.h>
#include <System.Private.CoreLib/System/Number.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
FORWARDS(DateTime)
FORWARDS(DateTimeOffset)
FORWARDS(Decimal)
FORWARDS(Double)
FORWARDS(Int16)
FORWARDS(Int32)
FORWARDS(Int64)
FORWARDS(SByte)
FORWARDS(Single)
FORWARDS(Span, T)
FORWARDS(TimeSpan)
FORWARDS(UInt16)
FORWARDS(UInt32)
FORWARDS(UInt64)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Buffers {
FORWARDS(StandardFormat)
} // namespace System::Private::CoreLib::System::Buffers
namespace System::Private::CoreLib::System::Buffers::Text {
namespace Utf8FormatterNamespace {
class Utf8Formatter {
  private: struct DecomposedGuid {
    public: Guid Guid;
    public: Byte Byte00;
    public: Byte Byte01;
    public: Byte Byte02;
    public: Byte Byte03;
    public: Byte Byte04;
    public: Byte Byte05;
    public: Byte Byte06;
    public: Byte Byte07;
    public: Byte Byte08;
    public: Byte Byte09;
    public: Byte Byte10;
    public: Byte Byte11;
    public: Byte Byte12;
    public: Byte Byte13;
    public: Byte Byte14;
    public: Byte Byte15;
  };
  public: static Boolean TryFormat(Boolean value, Span<Byte> destination, Int32& bytesWritten, StandardFormat format);
  public: static Boolean TryFormat(DateTimeOffset value, Span<Byte> destination, Int32& bytesWritten, StandardFormat format);
  public: static Boolean TryFormat(DateTime value, Span<Byte> destination, Int32& bytesWritten, StandardFormat format);
  private: static Boolean TryFormatDateTimeG(DateTime value, TimeSpan offset, Span<Byte> destination, Int32& bytesWritten);
  private: static Boolean TryFormatDateTimeL(DateTime value, Span<Byte> destination, Int32& bytesWritten);
  private: static Boolean TryFormatDateTimeO(DateTime value, TimeSpan offset, Span<Byte> destination, Int32& bytesWritten);
  private: static Boolean TryFormatDateTimeR(DateTime value, Span<Byte> destination, Int32& bytesWritten);
  public: static Boolean TryFormat(Decimal value, Span<Byte> destination, Int32& bytesWritten, StandardFormat format);
  private: static Boolean TryFormatDecimalE(Number::NumberBuffer& number, Span<Byte> destination, Int32& bytesWritten, Byte precision, Byte exponentSymbol);
  private: static Boolean TryFormatDecimalF(Number::NumberBuffer& number, Span<Byte> destination, Int32& bytesWritten, Byte precision);
  private: static Boolean TryFormatDecimalG(Number::NumberBuffer& number, Span<Byte> destination, Int32& bytesWritten);
  public: static Boolean TryFormat(Double value, Span<Byte> destination, Int32& bytesWritten, StandardFormat format);
  public: static Boolean TryFormat(Single value, Span<Byte> destination, Int32& bytesWritten, StandardFormat format);
  public: static Boolean TryFormat(Guid value, Span<Byte> destination, Int32& bytesWritten, StandardFormat format);
  public: static Boolean TryFormat(Byte value, Span<Byte> destination, Int32& bytesWritten, StandardFormat format);
  public: static Boolean TryFormat(SByte value, Span<Byte> destination, Int32& bytesWritten, StandardFormat format);
  public: static Boolean TryFormat(UInt16 value, Span<Byte> destination, Int32& bytesWritten, StandardFormat format);
  public: static Boolean TryFormat(Int16 value, Span<Byte> destination, Int32& bytesWritten, StandardFormat format);
  public: static Boolean TryFormat(UInt32 value, Span<Byte> destination, Int32& bytesWritten, StandardFormat format);
  public: static Boolean TryFormat(Int32 value, Span<Byte> destination, Int32& bytesWritten, StandardFormat format);
  public: static Boolean TryFormat(UInt64 value, Span<Byte> destination, Int32& bytesWritten, StandardFormat format);
  public: static Boolean TryFormat(Int64 value, Span<Byte> destination, Int32& bytesWritten, StandardFormat format);
  private: static Boolean TryFormatInt64(Int64 value, UInt64 mask, Span<Byte> destination, Int32& bytesWritten, StandardFormat format);
  private: static Boolean TryFormatInt64D(Int64 value, Byte precision, Span<Byte> destination, Int32& bytesWritten);
  private: static Boolean TryFormatInt64Default(Int64 value, Span<Byte> destination, Int32& bytesWritten);
  private: static Boolean TryFormatInt64MultipleDigits(Int64 value, Span<Byte> destination, Int32& bytesWritten);
  private: static Boolean TryFormatInt64N(Int64 value, Byte precision, Span<Byte> destination, Int32& bytesWritten);
  private: static Boolean TryFormatUInt64(UInt64 value, Span<Byte> destination, Int32& bytesWritten, StandardFormat format);
  private: static Boolean TryFormatUInt64D(UInt64 value, Byte precision, Span<Byte> destination, Boolean insertNegationSign, Int32& bytesWritten);
  private: static Boolean TryFormatUInt64Default(UInt64 value, Span<Byte> destination, Int32& bytesWritten);
  private: static Boolean TryFormatUInt32SingleDigit(UInt32 value, Span<Byte> destination, Int32& bytesWritten);
  private: static Boolean TryFormatUInt64MultipleDigits(UInt64 value, Span<Byte> destination, Int32& bytesWritten);
  private: static Boolean TryFormatUInt64N(UInt64 value, Byte precision, Span<Byte> destination, Boolean insertNegationSign, Int32& bytesWritten);
  private: static Boolean TryFormatUInt64X(UInt64 value, Byte precision, Boolean useLower, Span<Byte> destination, Int32& bytesWritten);
  public: static Boolean TryFormat(TimeSpan value, Span<Byte> destination, Int32& bytesWritten, StandardFormat format);
  private: static Array<UInt32> s_dayAbbreviations;
  private: static Array<UInt32> s_dayAbbreviationsLowercase;
  private: static Array<UInt32> s_monthAbbreviations;
  private: static Array<UInt32> s_monthAbbreviationsLowercase;
};
} // namespace Utf8FormatterNamespace
using Utf8Formatter = Utf8FormatterNamespace::Utf8Formatter;
} // namespace System::Private::CoreLib::System::Buffers::Text
