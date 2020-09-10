#pragma once

#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/Number.h>
#include <System.Private.CoreLib/System/UInt32.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System {
enum class DateTimeKind : int32_t;
FORWARD_(Array, T1, T2)
FORWARDS(Byte)
FORWARDS(Char)
FORWARDS(DateTime)
FORWARDS(DateTimeOffset)
FORWARDS(Decimal)
FORWARDS(Double)
FORWARDS(Guid)
FORWARDS(Int16)
FORWARDS(Int32)
FORWARDS(Int64)
FORWARDS(ReadOnlySpan, T)
FORWARDS(SByte)
FORWARDS(Single)
FORWARDS(TimeSpan)
FORWARDS(UInt16)
FORWARDS(UInt64)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Buffers::Text {
namespace Utf8ParserNamespace {
class Utf8Parser {
  private: enum class ParseNumberOptions : int32_t {
    AllowExponent = 1,
  };
  private: enum class ComponentParseResult : uint8_t {
    NoMoreData = 0,
    Colon = 1,
    Period = 2,
    ParseFailure = 3,
  };
  private: struct TimeSpanSplitter : public valueType<TimeSpanSplitter> {
    public: Boolean TrySplitTimeSpan(ReadOnlySpan<Byte> source, Boolean periodUsedToSeparateDay, Int32& bytesConsumed);
    private: static ComponentParseResult ParseComponent(ReadOnlySpan<Byte> source, Boolean neverParseAsFraction, Int32& srcIndex, UInt32& value);
    public: UInt32 V1;
    public: UInt32 V2;
    public: UInt32 V3;
    public: UInt32 V4;
    public: UInt32 V5;
    public: Boolean IsNegative;
    public: UInt32 Separators;
  };
  public: static Boolean TryParse(ReadOnlySpan<Byte> source, Boolean& value, Int32& bytesConsumed, Char standardFormat = '\0');
  public: static Boolean TryParse(ReadOnlySpan<Byte> source, DateTime& value, Int32& bytesConsumed, Char standardFormat = '\0');
  public: static Boolean TryParse(ReadOnlySpan<Byte> source, DateTimeOffset& value, Int32& bytesConsumed, Char standardFormat = '\0');
  private: static Boolean TryParseDateTimeOffsetDefault(ReadOnlySpan<Byte> source, DateTimeOffset& value, Int32& bytesConsumed);
  private: static Boolean TryParseDateTimeG(ReadOnlySpan<Byte> source, DateTime& value, DateTimeOffset& valueAsOffset, Int32& bytesConsumed);
  private: static Boolean TryCreateDateTimeOffset(DateTime dateTime, Boolean offsetNegative, Int32 offsetHours, Int32 offsetMinutes, DateTimeOffset& value);
  private: static Boolean TryCreateDateTimeOffset(Int32 year, Int32 month, Int32 day, Int32 hour, Int32 minute, Int32 second, Int32 fraction, Boolean offsetNegative, Int32 offsetHours, Int32 offsetMinutes, DateTimeOffset& value);
  private: static Boolean TryCreateDateTimeOffsetInterpretingDataAsLocalTime(Int32 year, Int32 month, Int32 day, Int32 hour, Int32 minute, Int32 second, Int32 fraction, DateTimeOffset& value);
  private: static Boolean TryCreateDateTime(Int32 year, Int32 month, Int32 day, Int32 hour, Int32 minute, Int32 second, Int32 fraction, DateTimeKind kind, DateTime& value);
  private: static Boolean TryParseDateTimeOffsetO(ReadOnlySpan<Byte> source, DateTimeOffset& value, Int32& bytesConsumed, DateTimeKind& kind);
  private: static Boolean TryParseDateTimeOffsetR(ReadOnlySpan<Byte> source, UInt32 caseFlipXorMask, DateTimeOffset& dateTimeOffset, Int32& bytesConsumed);
  public: static Boolean TryParse(ReadOnlySpan<Byte> source, Decimal& value, Int32& bytesConsumed, Char standardFormat = '\0');
  public: static Boolean TryParse(ReadOnlySpan<Byte> source, Single& value, Int32& bytesConsumed, Char standardFormat = '\0');
  public: static Boolean TryParse(ReadOnlySpan<Byte> source, Double& value, Int32& bytesConsumed, Char standardFormat = '\0');
  private: static Boolean TryParseNormalAsFloatingPoint(ReadOnlySpan<Byte> source, Number::NumberBuffer& number, Int32& bytesConsumed, Char standardFormat);
  private: template <class T>
  static Boolean TryParseAsSpecialFloatingPoint(ReadOnlySpan<Byte> source, T positiveInfinity, T negativeInfinity, T nan, T& value, Int32& bytesConsumed);
  public: static Boolean TryParse(ReadOnlySpan<Byte> source, Guid& value, Int32& bytesConsumed, Char standardFormat = '\0');
  private: static Boolean TryParseGuidN(ReadOnlySpan<Byte> text, Guid& value, Int32& bytesConsumed);
  private: static Boolean TryParseGuidCore(ReadOnlySpan<Byte> source, Guid& value, Int32& bytesConsumed, Int32 ends);
  public: static Boolean TryParse(ReadOnlySpan<Byte> source, SByte& value, Int32& bytesConsumed, Char standardFormat = '\0');
  public: static Boolean TryParse(ReadOnlySpan<Byte> source, Int16& value, Int32& bytesConsumed, Char standardFormat = '\0');
  public: static Boolean TryParse(ReadOnlySpan<Byte> source, Int32& value, Int32& bytesConsumed, Char standardFormat = '\0');
  public: static Boolean TryParse(ReadOnlySpan<Byte> source, Int64& value, Int32& bytesConsumed, Char standardFormat = '\0');
  private: static Boolean TryParseSByteD(ReadOnlySpan<Byte> source, SByte& value, Int32& bytesConsumed);
  private: static Boolean TryParseInt16D(ReadOnlySpan<Byte> source, Int16& value, Int32& bytesConsumed);
  private: static Boolean TryParseInt32D(ReadOnlySpan<Byte> source, Int32& value, Int32& bytesConsumed);
  private: static Boolean TryParseInt64D(ReadOnlySpan<Byte> source, Int64& value, Int32& bytesConsumed);
  private: static Boolean TryParseSByteN(ReadOnlySpan<Byte> source, SByte& value, Int32& bytesConsumed);
  private: static Boolean TryParseInt16N(ReadOnlySpan<Byte> source, Int16& value, Int32& bytesConsumed);
  private: static Boolean TryParseInt32N(ReadOnlySpan<Byte> source, Int32& value, Int32& bytesConsumed);
  private: static Boolean TryParseInt64N(ReadOnlySpan<Byte> source, Int64& value, Int32& bytesConsumed);
  public: static Boolean TryParse(ReadOnlySpan<Byte> source, Byte& value, Int32& bytesConsumed, Char standardFormat = '\0');
  public: static Boolean TryParse(ReadOnlySpan<Byte> source, UInt16& value, Int32& bytesConsumed, Char standardFormat = '\0');
  public: static Boolean TryParse(ReadOnlySpan<Byte> source, UInt32& value, Int32& bytesConsumed, Char standardFormat = '\0');
  public: static Boolean TryParse(ReadOnlySpan<Byte> source, UInt64& value, Int32& bytesConsumed, Char standardFormat = '\0');
  private: static Boolean TryParseByteD(ReadOnlySpan<Byte> source, Byte& value, Int32& bytesConsumed);
  private: static Boolean TryParseUInt16D(ReadOnlySpan<Byte> source, UInt16& value, Int32& bytesConsumed);
  private: static Boolean TryParseUInt32D(ReadOnlySpan<Byte> source, UInt32& value, Int32& bytesConsumed);
  private: static Boolean TryParseUInt64D(ReadOnlySpan<Byte> source, UInt64& value, Int32& bytesConsumed);
  private: static Boolean TryParseByteN(ReadOnlySpan<Byte> source, Byte& value, Int32& bytesConsumed);
  private: static Boolean TryParseUInt16N(ReadOnlySpan<Byte> source, UInt16& value, Int32& bytesConsumed);
  private: static Boolean TryParseUInt32N(ReadOnlySpan<Byte> source, UInt32& value, Int32& bytesConsumed);
  private: static Boolean TryParseUInt64N(ReadOnlySpan<Byte> source, UInt64& value, Int32& bytesConsumed);
  private: static Boolean TryParseByteX(ReadOnlySpan<Byte> source, Byte& value, Int32& bytesConsumed);
  private: static Boolean TryParseUInt16X(ReadOnlySpan<Byte> source, UInt16& value, Int32& bytesConsumed);
  private: static Boolean TryParseUInt32X(ReadOnlySpan<Byte> source, UInt32& value, Int32& bytesConsumed);
  private: static Boolean TryParseUInt64X(ReadOnlySpan<Byte> source, UInt64& value, Int32& bytesConsumed);
  private: static Boolean TryParseNumber(ReadOnlySpan<Byte> source, Number::NumberBuffer& number, Int32& bytesConsumed, ParseNumberOptions options, Boolean& textUsedExponentNotation);
  private: static Boolean TryParseTimeSpanBigG(ReadOnlySpan<Byte> source, TimeSpan& value, Int32& bytesConsumed);
  private: static Boolean TryParseTimeSpanC(ReadOnlySpan<Byte> source, TimeSpan& value, Int32& bytesConsumed);
  public: static Boolean TryParse(ReadOnlySpan<Byte> source, TimeSpan& value, Int32& bytesConsumed, Char standardFormat = '\0');
  private: static Boolean TryParseTimeSpanFraction(ReadOnlySpan<Byte> source, UInt32& value, Int32& bytesConsumed);
  private: static Boolean TryCreateTimeSpan(Boolean isNegative, UInt32 days, UInt32 hours, UInt32 minutes, UInt32 seconds, UInt32 fraction, TimeSpan& timeSpan);
  private: static Boolean TryParseTimeSpanLittleG(ReadOnlySpan<Byte> source, TimeSpan& value, Int32& bytesConsumed);
  public: static void cctor();
  private: static Array<Int32> s_daysToMonth365;
  private: static Array<Int32> s_daysToMonth366;
};
} // namespace Utf8ParserNamespace
using Utf8Parser = Utf8ParserNamespace::Utf8Parser;
} // namespace System::Private::CoreLib::System::Buffers::Text
