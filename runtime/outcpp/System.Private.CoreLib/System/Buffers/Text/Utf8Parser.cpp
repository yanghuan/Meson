#include "Utf8Parser-dep.h"

#include <System.Private.CoreLib/System/Buffers/Text/Utf8Parser-dep.h>

namespace System::Private::CoreLib::System::Buffers::Text::Utf8ParserNamespace {
Boolean Utf8Parser::TimeSpanSplitter::TrySplitTimeSpan(ReadOnlySpan<Byte> source, Boolean periodUsedToSeparateDay, Int32& bytesConsumed) {
  return Boolean();
};

Utf8Parser::ComponentParseResult Utf8Parser::TimeSpanSplitter::ParseComponent(ReadOnlySpan<Byte> source, Boolean neverParseAsFraction, Int32& srcIndex, UInt32& value) {
  return Utf8Parser::ComponentParseResult::ParseFailure;
};

Boolean Utf8Parser::TryParse(ReadOnlySpan<Byte> source, Boolean& value, Int32& bytesConsumed, Char standardFormat) {
  return Boolean();
};

Boolean Utf8Parser::TryParse(ReadOnlySpan<Byte> source, DateTime& value, Int32& bytesConsumed, Char standardFormat) {
  return Boolean();
};

Boolean Utf8Parser::TryParse(ReadOnlySpan<Byte> source, DateTimeOffset& value, Int32& bytesConsumed, Char standardFormat) {
  return Boolean();
};

Boolean Utf8Parser::TryParseDateTimeOffsetDefault(ReadOnlySpan<Byte> source, DateTimeOffset& value, Int32& bytesConsumed) {
  return Boolean();
};

Boolean Utf8Parser::TryParseDateTimeG(ReadOnlySpan<Byte> source, DateTime& value, DateTimeOffset& valueAsOffset, Int32& bytesConsumed) {
  return Boolean();
};

Boolean Utf8Parser::TryCreateDateTimeOffset(DateTime dateTime, Boolean offsetNegative, Int32 offsetHours, Int32 offsetMinutes, DateTimeOffset& value) {
  return Boolean();
};

Boolean Utf8Parser::TryCreateDateTimeOffset(Int32 year, Int32 month, Int32 day, Int32 hour, Int32 minute, Int32 second, Int32 fraction, Boolean offsetNegative, Int32 offsetHours, Int32 offsetMinutes, DateTimeOffset& value) {
  return Boolean();
};

Boolean Utf8Parser::TryCreateDateTimeOffsetInterpretingDataAsLocalTime(Int32 year, Int32 month, Int32 day, Int32 hour, Int32 minute, Int32 second, Int32 fraction, DateTimeOffset& value) {
  return Boolean();
};

Boolean Utf8Parser::TryCreateDateTime(Int32 year, Int32 month, Int32 day, Int32 hour, Int32 minute, Int32 second, Int32 fraction, DateTimeKind kind, DateTime& value) {
  return Boolean();
};

Boolean Utf8Parser::TryParseDateTimeOffsetO(ReadOnlySpan<Byte> source, DateTimeOffset& value, Int32& bytesConsumed, DateTimeKind& kind) {
  return Boolean();
};

Boolean Utf8Parser::TryParseDateTimeOffsetR(ReadOnlySpan<Byte> source, UInt32 caseFlipXorMask, DateTimeOffset& dateTimeOffset, Int32& bytesConsumed) {
  return Boolean();
};

Boolean Utf8Parser::TryParse(ReadOnlySpan<Byte> source, Decimal& value, Int32& bytesConsumed, Char standardFormat) {
  return Boolean();
};

Boolean Utf8Parser::TryParse(ReadOnlySpan<Byte> source, Single& value, Int32& bytesConsumed, Char standardFormat) {
  return Boolean();
};

Boolean Utf8Parser::TryParse(ReadOnlySpan<Byte> source, Double& value, Int32& bytesConsumed, Char standardFormat) {
  return Boolean();
};

Boolean Utf8Parser::TryParseNormalAsFloatingPoint(ReadOnlySpan<Byte> source, Number::NumberBuffer& number, Int32& bytesConsumed, Char standardFormat) {
  return Boolean();
};

Boolean Utf8Parser::TryParse(ReadOnlySpan<Byte> source, Guid& value, Int32& bytesConsumed, Char standardFormat) {
  return Boolean();
};

Boolean Utf8Parser::TryParseGuidN(ReadOnlySpan<Byte> text, Guid& value, Int32& bytesConsumed) {
  return Boolean();
};

Boolean Utf8Parser::TryParseGuidCore(ReadOnlySpan<Byte> source, Guid& value, Int32& bytesConsumed, Int32 ends) {
  return Boolean();
};

Boolean Utf8Parser::TryParse(ReadOnlySpan<Byte> source, SByte& value, Int32& bytesConsumed, Char standardFormat) {
  return Boolean();
};

Boolean Utf8Parser::TryParse(ReadOnlySpan<Byte> source, Int16& value, Int32& bytesConsumed, Char standardFormat) {
  return Boolean();
};

Boolean Utf8Parser::TryParse(ReadOnlySpan<Byte> source, Int32& value, Int32& bytesConsumed, Char standardFormat) {
  return Boolean();
};

Boolean Utf8Parser::TryParse(ReadOnlySpan<Byte> source, Int64& value, Int32& bytesConsumed, Char standardFormat) {
  return Boolean();
};

Boolean Utf8Parser::TryParseSByteD(ReadOnlySpan<Byte> source, SByte& value, Int32& bytesConsumed) {
  return Boolean();
};

Boolean Utf8Parser::TryParseInt16D(ReadOnlySpan<Byte> source, Int16& value, Int32& bytesConsumed) {
  return Boolean();
};

Boolean Utf8Parser::TryParseInt32D(ReadOnlySpan<Byte> source, Int32& value, Int32& bytesConsumed) {
  return Boolean();
};

Boolean Utf8Parser::TryParseInt64D(ReadOnlySpan<Byte> source, Int64& value, Int32& bytesConsumed) {
  return Boolean();
};

Boolean Utf8Parser::TryParseSByteN(ReadOnlySpan<Byte> source, SByte& value, Int32& bytesConsumed) {
  return Boolean();
};

Boolean Utf8Parser::TryParseInt16N(ReadOnlySpan<Byte> source, Int16& value, Int32& bytesConsumed) {
  return Boolean();
};

Boolean Utf8Parser::TryParseInt32N(ReadOnlySpan<Byte> source, Int32& value, Int32& bytesConsumed) {
  return Boolean();
};

Boolean Utf8Parser::TryParseInt64N(ReadOnlySpan<Byte> source, Int64& value, Int32& bytesConsumed) {
  return Boolean();
};

Boolean Utf8Parser::TryParse(ReadOnlySpan<Byte> source, Byte& value, Int32& bytesConsumed, Char standardFormat) {
  return Boolean();
};

Boolean Utf8Parser::TryParse(ReadOnlySpan<Byte> source, UInt16& value, Int32& bytesConsumed, Char standardFormat) {
  return Boolean();
};

Boolean Utf8Parser::TryParse(ReadOnlySpan<Byte> source, UInt32& value, Int32& bytesConsumed, Char standardFormat) {
  return Boolean();
};

Boolean Utf8Parser::TryParse(ReadOnlySpan<Byte> source, UInt64& value, Int32& bytesConsumed, Char standardFormat) {
  return Boolean();
};

Boolean Utf8Parser::TryParseByteD(ReadOnlySpan<Byte> source, Byte& value, Int32& bytesConsumed) {
  return Boolean();
};

Boolean Utf8Parser::TryParseUInt16D(ReadOnlySpan<Byte> source, UInt16& value, Int32& bytesConsumed) {
  return Boolean();
};

Boolean Utf8Parser::TryParseUInt32D(ReadOnlySpan<Byte> source, UInt32& value, Int32& bytesConsumed) {
  return Boolean();
};

Boolean Utf8Parser::TryParseUInt64D(ReadOnlySpan<Byte> source, UInt64& value, Int32& bytesConsumed) {
  return Boolean();
};

Boolean Utf8Parser::TryParseByteN(ReadOnlySpan<Byte> source, Byte& value, Int32& bytesConsumed) {
  return Boolean();
};

Boolean Utf8Parser::TryParseUInt16N(ReadOnlySpan<Byte> source, UInt16& value, Int32& bytesConsumed) {
  return Boolean();
};

Boolean Utf8Parser::TryParseUInt32N(ReadOnlySpan<Byte> source, UInt32& value, Int32& bytesConsumed) {
  return Boolean();
};

Boolean Utf8Parser::TryParseUInt64N(ReadOnlySpan<Byte> source, UInt64& value, Int32& bytesConsumed) {
  return Boolean();
};

Boolean Utf8Parser::TryParseByteX(ReadOnlySpan<Byte> source, Byte& value, Int32& bytesConsumed) {
  return Boolean();
};

Boolean Utf8Parser::TryParseUInt16X(ReadOnlySpan<Byte> source, UInt16& value, Int32& bytesConsumed) {
  return Boolean();
};

Boolean Utf8Parser::TryParseUInt32X(ReadOnlySpan<Byte> source, UInt32& value, Int32& bytesConsumed) {
  return Boolean();
};

Boolean Utf8Parser::TryParseUInt64X(ReadOnlySpan<Byte> source, UInt64& value, Int32& bytesConsumed) {
  return Boolean();
};

Boolean Utf8Parser::TryParseNumber(ReadOnlySpan<Byte> source, Number::NumberBuffer& number, Int32& bytesConsumed, ParseNumberOptions options, Boolean& textUsedExponentNotation) {
  return Boolean();
};

Boolean Utf8Parser::TryParseTimeSpanBigG(ReadOnlySpan<Byte> source, TimeSpan& value, Int32& bytesConsumed) {
  return Boolean();
};

Boolean Utf8Parser::TryParseTimeSpanC(ReadOnlySpan<Byte> source, TimeSpan& value, Int32& bytesConsumed) {
  return Boolean();
};

Boolean Utf8Parser::TryParse(ReadOnlySpan<Byte> source, TimeSpan& value, Int32& bytesConsumed, Char standardFormat) {
  return Boolean();
};

Boolean Utf8Parser::TryParseTimeSpanFraction(ReadOnlySpan<Byte> source, UInt32& value, Int32& bytesConsumed) {
  return Boolean();
};

Boolean Utf8Parser::TryCreateTimeSpan(Boolean isNegative, UInt32 days, UInt32 hours, UInt32 minutes, UInt32 seconds, UInt32 fraction, TimeSpan& timeSpan) {
  return Boolean();
};

Boolean Utf8Parser::TryParseTimeSpanLittleG(ReadOnlySpan<Byte> source, TimeSpan& value, Int32& bytesConsumed) {
  return Boolean();
};

void Utf8Parser::SCtor() {
};

} // namespace System::Private::CoreLib::System::Buffers::Text::Utf8ParserNamespace
