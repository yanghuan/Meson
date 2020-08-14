#include "Utf8Parser-dep.h"

#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/Buffers/Binary/BinaryPrimitives-dep.h>
#include <System.Private.CoreLib/System/Buffers/Text/ParserHelpers-dep.h>
#include <System.Private.CoreLib/System/Buffers/Text/Utf8Parser-dep.h>
#include <System.Private.CoreLib/System/DateTimeKind.h>
#include <System.Private.CoreLib/System/DateTimeOffset-dep.h>
#include <System.Private.CoreLib/System/Int64-dep.h>
#include <System.Private.CoreLib/System/Number-dep.h>
#include <System.Private.CoreLib/System/Span-dep.h>
#include <System.Private.CoreLib/System/ThrowHelper-dep.h>
#include <System.Private.CoreLib/System/TimeSpan-dep.h>
#include <System.Private.CoreLib/System/UInt64-dep.h>

namespace System::Private::CoreLib::System::Buffers::Text::Utf8ParserNamespace {
using namespace System::Buffers::Binary;

Boolean Utf8Parser::TimeSpanSplitter::TrySplitTimeSpan(ReadOnlySpan<Byte> source, Boolean periodUsedToSeparateDay, Int32& bytesConsumed) {
  Int32 i = 0;
  Byte b = 0;
  for (; i != source.get_Length(); i++) {
    b = source[i];
    if (b != 32 && b != 9) {
      break;
    }
  }
  if (i == source.get_Length()) {
    bytesConsumed = 0;
    return false;
  }
  if (b == 45) {
    IsNegative = true;
    i++;
    if (i == source.get_Length()) {
      bytesConsumed = 0;
      return false;
    }
  }
}

Utf8Parser::ComponentParseResult Utf8Parser::TimeSpanSplitter::ParseComponent(ReadOnlySpan<Byte> source, Boolean neverParseAsFraction, Int32& srcIndex, UInt32& value) {
  if (srcIndex == source.get_Length()) {
    value = 0u;
    return ComponentParseResult::NoMoreData;
  }
  Byte b = source[srcIndex];
  if (b == 58 || (b == 46 && neverParseAsFraction)) {
    srcIndex++;
  }
  if (b == 46) {
    srcIndex++;
  }
  value = 0u;
  return ComponentParseResult::NoMoreData;
}

Boolean Utf8Parser::TryParse(ReadOnlySpan<Byte> source, Boolean& value, Int32& bytesConsumed, Char standardFormat) {
  if (standardFormat != 0 && standardFormat != 71 && standardFormat != 108) {
    ThrowHelper::ThrowFormatException_BadFormatSpecifier();
  }
  if (source.get_Length() >= 4) {
  }
  bytesConsumed = 0;
  value = false;
  return false;
}

Boolean Utf8Parser::TryParse(ReadOnlySpan<Byte> source, DateTime& value, Int32& bytesConsumed, Char standardFormat) {
  switch (standardFormat.get()) {
    case 82:
      {
      }case 108:
      {
      }case 79:
      {
      }case 0:
    case 71:
      {
        DateTimeOffset valueAsOffset;
        return TryParseDateTimeG(source, value, valueAsOffset, bytesConsumed);
      }default:
      return ParserHelpers::TryParseThrowFormatException(value, bytesConsumed);
  }
}

Boolean Utf8Parser::TryParse(ReadOnlySpan<Byte> source, DateTimeOffset& value, Int32& bytesConsumed, Char standardFormat) {
  switch (standardFormat.get()) {
    case 82:
      return TryParseDateTimeOffsetR(source, 0u, value, bytesConsumed);
    case 108:
      return TryParseDateTimeOffsetR(source, 32u, value, bytesConsumed);
    case 79:
      {
        DateTimeKind kind;
        return TryParseDateTimeOffsetO(source, value, bytesConsumed, kind);
      }case 0:
      return TryParseDateTimeOffsetDefault(source, value, bytesConsumed);
    case 71:
      {
        DateTime value2;
        return TryParseDateTimeG(source, value2, value, bytesConsumed);
      }default:
      return ParserHelpers::TryParseThrowFormatException(value, bytesConsumed);
  }
}

Boolean Utf8Parser::TryParseDateTimeOffsetDefault(ReadOnlySpan<Byte> source, DateTimeOffset& value, Int32& bytesConsumed) {
  if (source.get_Length() < 26) {
    bytesConsumed = 0;
    value = DateTimeOffset();
    return false;
  }
}

Boolean Utf8Parser::TryParseDateTimeG(ReadOnlySpan<Byte> source, DateTime& value, DateTimeOffset& valueAsOffset, Int32& bytesConsumed) {
  if (source.get_Length() < 19) {
    bytesConsumed = 0;
    value = DateTime();
    valueAsOffset = DateTimeOffset();
    return false;
  }
  UInt32 num = (UInt32)(source[0] - 48);
  UInt32 num2 = (UInt32)(source[1] - 48);
  if (num > 9 || num2 > 9) {
    bytesConsumed = 0;
    value = DateTime();
    valueAsOffset = DateTimeOffset();
    return false;
  }
  Int32 month = (Int32)(num * 10 + num2);
  if (source[2] != 47) {
    bytesConsumed = 0;
    value = DateTime();
    valueAsOffset = DateTimeOffset();
    return false;
  }
  UInt32 num3 = (UInt32)(source[3] - 48);
  UInt32 num4 = (UInt32)(source[4] - 48);
  if (num3 > 9 || num4 > 9) {
    bytesConsumed = 0;
    value = DateTime();
    valueAsOffset = DateTimeOffset();
    return false;
  }
  Int32 day = (Int32)(num3 * 10 + num4);
  if (source[5] != 47) {
    bytesConsumed = 0;
    value = DateTime();
    valueAsOffset = DateTimeOffset();
    return false;
  }
  UInt32 num5 = (UInt32)(source[6] - 48);
  UInt32 num6 = (UInt32)(source[7] - 48);
  UInt32 num7 = (UInt32)(source[8] - 48);
  UInt32 num8 = (UInt32)(source[9] - 48);
  if (num5 > 9 || num6 > 9 || num7 > 9 || num8 > 9) {
    bytesConsumed = 0;
    value = DateTime();
    valueAsOffset = DateTimeOffset();
    return false;
  }
  Int32 year = (Int32)(num5 * 1000 + num6 * 100 + num7 * 10 + num8);
  if (source[10] != 32) {
    bytesConsumed = 0;
    value = DateTime();
    valueAsOffset = DateTimeOffset();
    return false;
  }
  UInt32 num9 = (UInt32)(source[11] - 48);
  UInt32 num10 = (UInt32)(source[12] - 48);
  if (num9 > 9 || num10 > 9) {
    bytesConsumed = 0;
    value = DateTime();
    valueAsOffset = DateTimeOffset();
    return false;
  }
  Int32 hour = (Int32)(num9 * 10 + num10);
  if (source[13] != 58) {
    bytesConsumed = 0;
    value = DateTime();
    valueAsOffset = DateTimeOffset();
    return false;
  }
  UInt32 num11 = (UInt32)(source[14] - 48);
  UInt32 num12 = (UInt32)(source[15] - 48);
  if (num11 > 9 || num12 > 9) {
    bytesConsumed = 0;
    value = DateTime();
    valueAsOffset = DateTimeOffset();
    return false;
  }
  Int32 minute = (Int32)(num11 * 10 + num12);
  if (source[16] != 58) {
    bytesConsumed = 0;
    value = DateTime();
    valueAsOffset = DateTimeOffset();
    return false;
  }
  UInt32 num13 = (UInt32)(source[17] - 48);
  UInt32 num14 = (UInt32)(source[18] - 48);
  if (num13 > 9 || num14 > 9) {
    bytesConsumed = 0;
    value = DateTime();
    valueAsOffset = DateTimeOffset();
    return false;
  }
  Int32 second = (Int32)(num13 * 10 + num14);
  if (!TryCreateDateTimeOffsetInterpretingDataAsLocalTime(year, month, day, hour, minute, second, 0, valueAsOffset)) {
    bytesConsumed = 0;
    value = DateTime();
    valueAsOffset = DateTimeOffset();
    return false;
  }
  bytesConsumed = 19;
  value = valueAsOffset.get_DateTime();
  return true;
}

Boolean Utf8Parser::TryCreateDateTimeOffset(DateTime dateTime, Boolean offsetNegative, Int32 offsetHours, Int32 offsetMinutes, DateTimeOffset& value) {
  if ((UInt32)offsetHours > 14u) {
    value = DateTimeOffset();
    return false;
  }
  if ((UInt32)offsetMinutes > 59u) {
    value = DateTimeOffset();
    return false;
  }
  if (offsetHours == 14 && offsetMinutes != 0) {
    value = DateTimeOffset();
    return false;
  }
  Int64 num = ((Int64)offsetHours * 3600 + (Int64)offsetMinutes * 60) * 10000000;
  if (offsetNegative) {
  }
  try{
    value = DateTimeOffset(dateTime.get_Ticks(), TimeSpan(num));
  } catch (ArgumentOutOfRangeException) {
  }
  return true;
}

Boolean Utf8Parser::TryCreateDateTimeOffset(Int32 year, Int32 month, Int32 day, Int32 hour, Int32 minute, Int32 second, Int32 fraction, Boolean offsetNegative, Int32 offsetHours, Int32 offsetMinutes, DateTimeOffset& value) {
}

Boolean Utf8Parser::TryCreateDateTimeOffsetInterpretingDataAsLocalTime(Int32 year, Int32 month, Int32 day, Int32 hour, Int32 minute, Int32 second, Int32 fraction, DateTimeOffset& value) {
}

Boolean Utf8Parser::TryCreateDateTime(Int32 year, Int32 month, Int32 day, Int32 hour, Int32 minute, Int32 second, Int32 fraction, DateTimeKind kind, DateTime& value) {
  if (year == 0) {
    value = DateTime();
    return false;
  }
  if ((UInt32)(month - 1) >= 12u) {
    value = DateTime();
    return false;
  }
  UInt32 num = (UInt32)(day - 1);
  if (num >= 28 && num >= DateTime::DaysInMonth(year, month)) {
    value = DateTime();
    return false;
  }
  if ((UInt32)hour > 23u) {
    value = DateTime();
    return false;
  }
  if ((UInt32)minute > 59u) {
    value = DateTime();
    return false;
  }
  if ((UInt32)second > 59u) {
    value = DateTime();
    return false;
  }
  Array<Int32> array = DateTime::IsLeapYear(year) ? s_daysToMonth366 : s_daysToMonth365;
  Int32 num2 = year - 1;
  Int32 num3 = num2 * 365 + num2 / 4 - num2 / 100 + num2 / 400 + array[month - 1] + day - 1;
  Int64 num4 = num3 * 864000000000;
  Int32 num5 = hour * 3600 + minute * 60 + second;
  num4 += (Int64)num5 * 10000000;
  num4 += fraction;
  value = DateTime(num4, kind);
  return true;
}

Boolean Utf8Parser::TryParseDateTimeOffsetO(ReadOnlySpan<Byte> source, DateTimeOffset& value, Int32& bytesConsumed, DateTimeKind& kind) {
  if (source.get_Length() < 27) {
    value = DateTimeOffset();
    bytesConsumed = 0;
    kind = DateTimeKind::Unspecified;
    return false;
  }
  UInt32 num = (UInt32)(source[0] - 48);
  UInt32 num2 = (UInt32)(source[1] - 48);
  UInt32 num3 = (UInt32)(source[2] - 48);
  UInt32 num4 = (UInt32)(source[3] - 48);
  if (num > 9 || num2 > 9 || num3 > 9 || num4 > 9) {
    value = DateTimeOffset();
    bytesConsumed = 0;
    kind = DateTimeKind::Unspecified;
    return false;
  }
  Int32 year = (Int32)(num * 1000 + num2 * 100 + num3 * 10 + num4);
  if (source[4] != 45) {
    value = DateTimeOffset();
    bytesConsumed = 0;
    kind = DateTimeKind::Unspecified;
    return false;
  }
  UInt32 num5 = (UInt32)(source[5] - 48);
  UInt32 num6 = (UInt32)(source[6] - 48);
  if (num5 > 9 || num6 > 9) {
    value = DateTimeOffset();
    bytesConsumed = 0;
    kind = DateTimeKind::Unspecified;
    return false;
  }
  Int32 month = (Int32)(num5 * 10 + num6);
  if (source[7] != 45) {
    value = DateTimeOffset();
    bytesConsumed = 0;
    kind = DateTimeKind::Unspecified;
    return false;
  }
  UInt32 num7 = (UInt32)(source[8] - 48);
  UInt32 num8 = (UInt32)(source[9] - 48);
  if (num7 > 9 || num8 > 9) {
    value = DateTimeOffset();
    bytesConsumed = 0;
    kind = DateTimeKind::Unspecified;
    return false;
  }
  Int32 day = (Int32)(num7 * 10 + num8);
  if (source[10] != 84) {
    value = DateTimeOffset();
    bytesConsumed = 0;
    kind = DateTimeKind::Unspecified;
    return false;
  }
  UInt32 num9 = (UInt32)(source[11] - 48);
  UInt32 num10 = (UInt32)(source[12] - 48);
  if (num9 > 9 || num10 > 9) {
    value = DateTimeOffset();
    bytesConsumed = 0;
    kind = DateTimeKind::Unspecified;
    return false;
  }
  Int32 hour = (Int32)(num9 * 10 + num10);
  if (source[13] != 58) {
    value = DateTimeOffset();
    bytesConsumed = 0;
    kind = DateTimeKind::Unspecified;
    return false;
  }
  UInt32 num11 = (UInt32)(source[14] - 48);
  UInt32 num12 = (UInt32)(source[15] - 48);
  if (num11 > 9 || num12 > 9) {
    value = DateTimeOffset();
    bytesConsumed = 0;
    kind = DateTimeKind::Unspecified;
    return false;
  }
  Int32 minute = (Int32)(num11 * 10 + num12);
  if (source[16] != 58) {
    value = DateTimeOffset();
    bytesConsumed = 0;
    kind = DateTimeKind::Unspecified;
    return false;
  }
  UInt32 num13 = (UInt32)(source[17] - 48);
  UInt32 num14 = (UInt32)(source[18] - 48);
  if (num13 > 9 || num14 > 9) {
    value = DateTimeOffset();
    bytesConsumed = 0;
    kind = DateTimeKind::Unspecified;
    return false;
  }
  Int32 second = (Int32)(num13 * 10 + num14);
  if (source[19] != 46) {
    value = DateTimeOffset();
    bytesConsumed = 0;
    kind = DateTimeKind::Unspecified;
    return false;
  }
  UInt32 num15 = (UInt32)(source[20] - 48);
  UInt32 num16 = (UInt32)(source[21] - 48);
  UInt32 num17 = (UInt32)(source[22] - 48);
  UInt32 num18 = (UInt32)(source[23] - 48);
  UInt32 num19 = (UInt32)(source[24] - 48);
  UInt32 num20 = (UInt32)(source[25] - 48);
  UInt32 num21 = (UInt32)(source[26] - 48);
  if (num15 > 9 || num16 > 9 || num17 > 9 || num18 > 9 || num19 > 9 || num20 > 9 || num21 > 9) {
    value = DateTimeOffset();
    bytesConsumed = 0;
    kind = DateTimeKind::Unspecified;
    return false;
  }
  Int32 fraction = (Int32)(num15 * 1000000 + num16 * 100000 + num17 * 10000 + num18 * 1000 + num19 * 100 + num20 * 10 + num21);
  Byte b = (Byte)((source.get_Length() > 27) ? source[27] : 0);
  if (b != 90 && b != 43 && b != 45) {
    if (!TryCreateDateTimeOffsetInterpretingDataAsLocalTime(year, month, day, hour, minute, second, fraction, value)) {
      value = DateTimeOffset();
      bytesConsumed = 0;
      kind = DateTimeKind::Unspecified;
      return false;
    }
    bytesConsumed = 27;
    kind = DateTimeKind::Unspecified;
    return true;
  }
  if (b == 90) {
    if (!TryCreateDateTimeOffset(year, month, day, hour, minute, second, fraction, false, 0, 0, value)) {
      value = DateTimeOffset();
      bytesConsumed = 0;
      kind = DateTimeKind::Unspecified;
      return false;
    }
    bytesConsumed = 28;
    kind = DateTimeKind::Utc;
    return true;
  }
  if (source.get_Length() < 33) {
    value = DateTimeOffset();
    bytesConsumed = 0;
    kind = DateTimeKind::Unspecified;
    return false;
  }
  UInt32 num22 = (UInt32)(source[28] - 48);
  UInt32 num23 = (UInt32)(source[29] - 48);
  if (num22 > 9 || num23 > 9) {
    value = DateTimeOffset();
    bytesConsumed = 0;
    kind = DateTimeKind::Unspecified;
    return false;
  }
  Int32 offsetHours = (Int32)(num22 * 10 + num23);
  if (source[30] != 58) {
    value = DateTimeOffset();
    bytesConsumed = 0;
    kind = DateTimeKind::Unspecified;
    return false;
  }
  UInt32 num24 = (UInt32)(source[31] - 48);
  UInt32 num25 = (UInt32)(source[32] - 48);
  if (num24 > 9 || num25 > 9) {
    value = DateTimeOffset();
    bytesConsumed = 0;
    kind = DateTimeKind::Unspecified;
    return false;
  }
  Int32 offsetMinutes = (Int32)(num24 * 10 + num25);
  if (!TryCreateDateTimeOffset(year, month, day, hour, minute, second, fraction, b == 45, offsetHours, offsetMinutes, value)) {
    value = DateTimeOffset();
    bytesConsumed = 0;
    kind = DateTimeKind::Unspecified;
    return false;
  }
  bytesConsumed = 33;
  kind = DateTimeKind::Local;
  return true;
}

Boolean Utf8Parser::TryParseDateTimeOffsetR(ReadOnlySpan<Byte> source, UInt32 caseFlipXorMask, DateTimeOffset& dateTimeOffset, Int32& bytesConsumed) {
  if (source.get_Length() < 29) {
    bytesConsumed = 0;
    dateTimeOffset = DateTimeOffset();
    return false;
  }
}

Boolean Utf8Parser::TryParse(ReadOnlySpan<Byte> source, Decimal& value, Int32& bytesConsumed, Char standardFormat) {
  ParseNumberOptions options;
  switch (standardFormat.get()) {
    case 0:
    case 69:
    case 71:
    case 101:
    case 103:
      options = ParseNumberOptions::AllowExponent;
      break;
    case 70:
    case 102:
      options = (ParseNumberOptions)0;
      break;
    default:
      return ParserHelpers::TryParseThrowFormatException(value, bytesConsumed);
  }
  Byte default[31] = {};
  Byte* digits = default;
  Number::NumberBuffer number = Number::NumberBuffer(Number::NumberBufferKind::Decimal, digits, 31);
}

Boolean Utf8Parser::TryParse(ReadOnlySpan<Byte> source, Single& value, Int32& bytesConsumed, Char standardFormat) {
  Byte default[114] = {};
  Byte* digits = default;
  Number::NumberBuffer number = Number::NumberBuffer(Number::NumberBufferKind::FloatingPoint, digits, 114);
  if (TryParseNormalAsFloatingPoint(source, number, bytesConsumed, standardFormat)) {
    value = Number::NumberToSingle(number);
    return true;
  }
  return TryParseAsSpecialFloatingPoint(source, Single::PositiveInfinity, Single::NegativeInfinity, Single::NaN, value, bytesConsumed);
}

Boolean Utf8Parser::TryParse(ReadOnlySpan<Byte> source, Double& value, Int32& bytesConsumed, Char standardFormat) {
  Byte default[769] = {};
  Byte* digits = default;
  Number::NumberBuffer number = Number::NumberBuffer(Number::NumberBufferKind::FloatingPoint, digits, 769);
  if (TryParseNormalAsFloatingPoint(source, number, bytesConsumed, standardFormat)) {
    value = Number::NumberToDouble(number);
    return true;
  }
  return TryParseAsSpecialFloatingPoint(source, Double::PositiveInfinity, Double::NegativeInfinity, Double::NaN, value, bytesConsumed);
}

Boolean Utf8Parser::TryParseNormalAsFloatingPoint(ReadOnlySpan<Byte> source, Number::NumberBuffer& number, Int32& bytesConsumed, Char standardFormat) {
  ParseNumberOptions options;
  switch (standardFormat.get()) {
    case 0:
    case 69:
    case 71:
    case 101:
    case 103:
      options = ParseNumberOptions::AllowExponent;
      break;
    case 70:
    case 102:
      options = (ParseNumberOptions)0;
      break;
    default:
      return ParserHelpers::TryParseThrowFormatException(bytesConsumed);
  }
}

Boolean Utf8Parser::TryParse(ReadOnlySpan<Byte> source, Guid& value, Int32& bytesConsumed, Char standardFormat) {
  while (true) {
    switch (standardFormat.get()) {
      case 0:
        return TryParseGuidCore(source, value, bytesConsumed, 0);
      case 68:
        break;
      case 66:
        return TryParseGuidCore(source, value, bytesConsumed, 32123);
      case 80:
        return TryParseGuidCore(source, value, bytesConsumed, 10536);
      case 78:
        return TryParseGuidN(source, value, bytesConsumed);
      default:
        return ParserHelpers::TryParseThrowFormatException(source, value, bytesConsumed);
    }
    standardFormat = 0;
  }
}

Boolean Utf8Parser::TryParseGuidN(ReadOnlySpan<Byte> text, Guid& value, Int32& bytesConsumed) {
  if (text.get_Length() < 32) {
    value = Guid();
    bytesConsumed = 0;
    return false;
  }
}

Boolean Utf8Parser::TryParseGuidCore(ReadOnlySpan<Byte> source, Guid& value, Int32& bytesConsumed, Int32 ends) {
  Int32 num = 36 + ((ends != 0) ? 2 : 0);
  if (source.get_Length() < num) {
    value = Guid();
    bytesConsumed = 0;
    return false;
  }
  if (ends != 0) {
    if (source[0] != (Byte)ends) {
      value = Guid();
      bytesConsumed = 0;
      return false;
    }
    source = source.Slice(1);
    ends >>= 8;
  }
}

Boolean Utf8Parser::TryParse(ReadOnlySpan<Byte> source, SByte& value, Int32& bytesConsumed, Char standardFormat) {
  while (standardFormat != 0) {
  }
  return TryParseSByteD(source, value, bytesConsumed);
}

Boolean Utf8Parser::TryParse(ReadOnlySpan<Byte> source, Int16& value, Int32& bytesConsumed, Char standardFormat) {
  while (standardFormat != 0) {
  }
  return TryParseInt16D(source, value, bytesConsumed);
}

Boolean Utf8Parser::TryParse(ReadOnlySpan<Byte> source, Int32& value, Int32& bytesConsumed, Char standardFormat) {
  while (standardFormat != 0) {
  }
  return TryParseInt32D(source, value, bytesConsumed);
}

Boolean Utf8Parser::TryParse(ReadOnlySpan<Byte> source, Int64& value, Int32& bytesConsumed, Char standardFormat) {
  while (standardFormat != 0) {
  }
  return TryParseInt64D(source, value, bytesConsumed);
}

Boolean Utf8Parser::TryParseSByteD(ReadOnlySpan<Byte> source, SByte& value, Int32& bytesConsumed) {
  Int32 num;
  Int32 num2;
  Int32 num4;
  Int32 num3;
  if (source.get_Length() >= 1) {
    num = 1;
    num2 = 0;
    num3 = source[num2];
    if (num3 == 45) {
      num = -1;
      num2++;
      if ((UInt32)num2 >= (UInt32)source.get_Length()) {
      }
      num3 = source[num2];
    } else if (num3 == 43) {
      num2++;
      if ((UInt32)num2 >= (UInt32)source.get_Length()) {
      }
      num3 = source[num2];
    }

    num4 = 0;
    if (ParserHelpers::IsDigit(num3)) {
      if (num3 != 48) {
      }
      while (true) {
        num2++;
        if ((UInt32)num2 >= (UInt32)source.get_Length()) {
          break;
        }
        num3 = source[num2];
        if (num3 == 48) {
        }
      }
    }
  }
}

Boolean Utf8Parser::TryParseInt16D(ReadOnlySpan<Byte> source, Int16& value, Int32& bytesConsumed) {
  Int32 num;
  Int32 num2;
  Int32 num4;
  Int32 num3;
  if (source.get_Length() >= 1) {
    num = 1;
    num2 = 0;
    num3 = source[num2];
    if (num3 == 45) {
      num = -1;
      num2++;
      if ((UInt32)num2 >= (UInt32)source.get_Length()) {
      }
      num3 = source[num2];
    } else if (num3 == 43) {
      num2++;
      if ((UInt32)num2 >= (UInt32)source.get_Length()) {
      }
      num3 = source[num2];
    }

    num4 = 0;
    if (ParserHelpers::IsDigit(num3)) {
      if (num3 != 48) {
      }
      while (true) {
        num2++;
        if ((UInt32)num2 >= (UInt32)source.get_Length()) {
          break;
        }
        num3 = source[num2];
        if (num3 == 48) {
        }
      }
    }
  }
}

Boolean Utf8Parser::TryParseInt32D(ReadOnlySpan<Byte> source, Int32& value, Int32& bytesConsumed) {
  Int32 num;
  Int32 num2;
  Int32 num4;
  Int32 num3;
  if (source.get_Length() >= 1) {
    num = 1;
    num2 = 0;
    num3 = source[num2];
    if (num3 == 45) {
      num = -1;
      num2++;
      if ((UInt32)num2 >= (UInt32)source.get_Length()) {
      }
      num3 = source[num2];
    } else if (num3 == 43) {
      num2++;
      if ((UInt32)num2 >= (UInt32)source.get_Length()) {
      }
      num3 = source[num2];
    }

    num4 = 0;
    if (ParserHelpers::IsDigit(num3)) {
      if (num3 != 48) {
      }
      while (true) {
        num2++;
        if ((UInt32)num2 >= (UInt32)source.get_Length()) {
          break;
        }
        num3 = source[num2];
        if (num3 == 48) {
        }
      }
    }
  }
}

Boolean Utf8Parser::TryParseInt64D(ReadOnlySpan<Byte> source, Int64& value, Int32& bytesConsumed) {
  if (source.get_Length() < 1) {
    bytesConsumed = 0;
    value = 0;
    return false;
  }
  Int32 num = 0;
  Int32 num2 = 1;
  if (source[0] == 45) {
    num = 1;
    num2 = -1;
    if (source.get_Length() <= num) {
      bytesConsumed = 0;
      value = 0;
      return false;
    }
  } else if (source[0] == 43) {
    num = 1;
    if (source.get_Length() <= num) {
      bytesConsumed = 0;
      value = 0;
      return false;
    }
  }

  Int32 num3 = 19 + num;
  Int64 num4 = source[num] - 48;
  if (num4 < 0 || num4 > 9) {
    bytesConsumed = 0;
    value = 0;
    return false;
  }
  UInt64 num5 = (UInt64)num4;
  if (source.get_Length() < num3) {
    for (Int32 i = num + 1; i < source.get_Length(); i++) {
      Int64 num6 = source[i] - 48;
      if (num6 < 0 || num6 > 9) {
        bytesConsumed = i;
        value = (Int64)num5 * (Int64)num2;
        return true;
      }
      num5 = num5 * 10 + (UInt64)num6;
    }
  } else {
    for (Int32 j = num + 1; j < num3 - 1; j++) {
      Int64 num7 = source[j] - 48;
      if (num7 < 0 || num7 > 9) {
        bytesConsumed = j;
        value = (Int64)num5 * (Int64)num2;
        return true;
      }
      num5 = num5 * 10 + (UInt64)num7;
    }
    for (Int32 k = num3 - 1; k < source.get_Length(); k++) {
      Int64 num8 = source[k] - 48;
      if (num8 < 0 || num8 > 9) {
        bytesConsumed = k;
        value = (Int64)num5 * (Int64)num2;
        return true;
      }
      Boolean flag = num2 > 0;
      Boolean flag2 = num8 > 8 || (flag && num8 > 7);
      if (num5 > 922337203685477580 || (num5 == 922337203685477580 && flag2)) {
        bytesConsumed = 0;
        value = 0;
        return false;
      }
      num5 = num5 * 10 + (UInt64)num8;
    }
  }
  bytesConsumed = source.get_Length();
  value = (Int64)num5 * (Int64)num2;
  return true;
}

Boolean Utf8Parser::TryParseSByteN(ReadOnlySpan<Byte> source, SByte& value, Int32& bytesConsumed) {
  Int32 num;
  Int32 num2;
  Int32 num4;
  Int32 num3;
  if (source.get_Length() >= 1) {
    num = 1;
    num2 = 0;
    num3 = source[num2];
    if (num3 == 45) {
      num = -1;
      num2++;
      if ((UInt32)num2 >= (UInt32)source.get_Length()) {
      }
      num3 = source[num2];
    } else if (num3 == 43) {
      num2++;
      if ((UInt32)num2 >= (UInt32)source.get_Length()) {
      }
      num3 = source[num2];
    }

    if (num3 != 46) {
      if (ParserHelpers::IsDigit(num3)) {
        num4 = num3 - 48;
        while (true) {
          num2++;
          if ((UInt32)num2 >= (UInt32)source.get_Length()) {
            break;
          }
          num3 = source[num2];
          if (num3 == 44) {
          }
          if (num3 == 46) {
          }
          if (!ParserHelpers::IsDigit(num3)) {
            break;
          }
          num4 = num4 * 10 + num3 - 48;
          if (num4 <= 127 + (-1 * num + 1) / 2) {
          }
        }
      }
    } else {
      num4 = 0;
      num2++;
      if ((UInt32)num2 < (UInt32)source.get_Length() && source[num2] == 48) {
      }
    }
  }
}

Boolean Utf8Parser::TryParseInt16N(ReadOnlySpan<Byte> source, Int16& value, Int32& bytesConsumed) {
  Int32 num;
  Int32 num2;
  Int32 num4;
  Int32 num3;
  if (source.get_Length() >= 1) {
    num = 1;
    num2 = 0;
    num3 = source[num2];
    if (num3 == 45) {
      num = -1;
      num2++;
      if ((UInt32)num2 >= (UInt32)source.get_Length()) {
      }
      num3 = source[num2];
    } else if (num3 == 43) {
      num2++;
      if ((UInt32)num2 >= (UInt32)source.get_Length()) {
      }
      num3 = source[num2];
    }

    if (num3 != 46) {
      if (ParserHelpers::IsDigit(num3)) {
        num4 = num3 - 48;
        while (true) {
          num2++;
          if ((UInt32)num2 >= (UInt32)source.get_Length()) {
            break;
          }
          num3 = source[num2];
          if (num3 == 44) {
          }
          if (num3 == 46) {
          }
          if (!ParserHelpers::IsDigit(num3)) {
            break;
          }
          num4 = num4 * 10 + num3 - 48;
          if (num4 <= 32767 + (-1 * num + 1) / 2) {
          }
        }
      }
    } else {
      num4 = 0;
      num2++;
      if ((UInt32)num2 < (UInt32)source.get_Length() && source[num2] == 48) {
      }
    }
  }
}

Boolean Utf8Parser::TryParseInt32N(ReadOnlySpan<Byte> source, Int32& value, Int32& bytesConsumed) {
  Int32 num;
  Int32 num2;
  Int32 num4;
  Int32 num3;
  if (source.get_Length() >= 1) {
    num = 1;
    num2 = 0;
    num3 = source[num2];
    if (num3 == 45) {
      num = -1;
      num2++;
      if ((UInt32)num2 >= (UInt32)source.get_Length()) {
      }
      num3 = source[num2];
    } else if (num3 == 43) {
      num2++;
      if ((UInt32)num2 >= (UInt32)source.get_Length()) {
      }
      num3 = source[num2];
    }

    if (num3 != 46) {
      if (ParserHelpers::IsDigit(num3)) {
        num4 = num3 - 48;
        while (true) {
          num2++;
          if ((UInt32)num2 >= (UInt32)source.get_Length()) {
            break;
          }
          num3 = source[num2];
          if (num3 == 44) {
          }
          if (num3 == 46) {
          }
          if (!ParserHelpers::IsDigit(num3)) {
            break;
          }
          if ((UInt32)num4 <= 214748364u) {
            num4 = num4 * 10 + num3 - 48;
            if ((UInt32)num4 <= 2147483647 + (Int64)((-1 * num + 1) / 2)) {
            }
          }
        }
      }
    } else {
      num4 = 0;
      num2++;
      if ((UInt32)num2 < (UInt32)source.get_Length() && source[num2] == 48) {
      }
    }
  }
}

Boolean Utf8Parser::TryParseInt64N(ReadOnlySpan<Byte> source, Int64& value, Int32& bytesConsumed) {
  Int32 num;
  Int32 num2;
  Int64 num4;
  Int32 num3;
  if (source.get_Length() >= 1) {
    num = 1;
    num2 = 0;
    num3 = source[num2];
    if (num3 == 45) {
      num = -1;
      num2++;
      if ((UInt32)num2 >= (UInt32)source.get_Length()) {
      }
      num3 = source[num2];
    } else if (num3 == 43) {
      num2++;
      if ((UInt32)num2 >= (UInt32)source.get_Length()) {
      }
      num3 = source[num2];
    }

    if (num3 != 46) {
      if (ParserHelpers::IsDigit(num3)) {
        num4 = num3 - 48;
        while (true) {
          num2++;
          if ((UInt32)num2 >= (UInt32)source.get_Length()) {
            break;
          }
          num3 = source[num2];
          if (num3 == 44) {
          }
          if (num3 == 46) {
          }
          if (!ParserHelpers::IsDigit(num3)) {
            break;
          }
          if ((UInt64)num4 <= 922337203685477580) {
            num4 = num4 * 10 + num3 - 48;
            if ((UInt64)num4 <= (UInt64)(Int64::MaxValue + (-1 * num + 1) / 2)) {
            }
          }
        }
      }
    } else {
      num4 = 0;
      num2++;
      if ((UInt32)num2 < (UInt32)source.get_Length() && source[num2] == 48) {
      }
    }
  }
}

Boolean Utf8Parser::TryParse(ReadOnlySpan<Byte> source, Byte& value, Int32& bytesConsumed, Char standardFormat) {
  while (standardFormat != 0) {
  }
  return TryParseByteD(source, value, bytesConsumed);
}

Boolean Utf8Parser::TryParse(ReadOnlySpan<Byte> source, UInt16& value, Int32& bytesConsumed, Char standardFormat) {
  while (standardFormat != 0) {
  }
  return TryParseUInt16D(source, value, bytesConsumed);
}

Boolean Utf8Parser::TryParse(ReadOnlySpan<Byte> source, UInt32& value, Int32& bytesConsumed, Char standardFormat) {
  while (standardFormat != 0) {
  }
  return TryParseUInt32D(source, value, bytesConsumed);
}

Boolean Utf8Parser::TryParse(ReadOnlySpan<Byte> source, UInt64& value, Int32& bytesConsumed, Char standardFormat) {
  while (standardFormat != 0) {
  }
  return TryParseUInt64D(source, value, bytesConsumed);
}

Boolean Utf8Parser::TryParseByteD(ReadOnlySpan<Byte> source, Byte& value, Int32& bytesConsumed) {
  Int32 num;
  Int32 num3;
  Int32 num2;
  if (source.get_Length() >= 1) {
    num = 0;
    num2 = source[num];
    num3 = 0;
    if (ParserHelpers::IsDigit(num2)) {
      if (num2 != 48) {
      }
      while (true) {
        num++;
        if ((UInt32)num >= (UInt32)source.get_Length()) {
          break;
        }
        num2 = source[num];
        if (num2 == 48) {
        }
      }
    }
  }
}

Boolean Utf8Parser::TryParseUInt16D(ReadOnlySpan<Byte> source, UInt16& value, Int32& bytesConsumed) {
  Int32 num;
  Int32 num3;
  Int32 num2;
  if (source.get_Length() >= 1) {
    num = 0;
    num2 = source[num];
    num3 = 0;
    if (ParserHelpers::IsDigit(num2)) {
      if (num2 != 48) {
      }
      while (true) {
        num++;
        if ((UInt32)num >= (UInt32)source.get_Length()) {
          break;
        }
        num2 = source[num];
        if (num2 == 48) {
        }
      }
    }
  }
}

Boolean Utf8Parser::TryParseUInt32D(ReadOnlySpan<Byte> source, UInt32& value, Int32& bytesConsumed) {
  Int32 num;
  Int32 num3;
  Int32 num2;
  if (source.get_Length() >= 1) {
    num = 0;
    num2 = source[num];
    num3 = 0;
    if (ParserHelpers::IsDigit(num2)) {
      if (num2 != 48) {
      }
      while (true) {
        num++;
        if ((UInt32)num >= (UInt32)source.get_Length()) {
          break;
        }
        num2 = source[num];
        if (num2 == 48) {
        }
      }
    }
  }
}

Boolean Utf8Parser::TryParseUInt64D(ReadOnlySpan<Byte> source, UInt64& value, Int32& bytesConsumed) {
  if (source.get_Length() < 1) {
    bytesConsumed = 0;
    value = 0;
    return false;
  }
  UInt64 num = (UInt32)(source[0] - 48);
  if (num > 9) {
    bytesConsumed = 0;
    value = 0;
    return false;
  }
  UInt64 num2 = num;
  if (source.get_Length() < 19) {
    for (Int32 i = 1; i < source.get_Length(); i++) {
      UInt64 num3 = (UInt32)(source[i] - 48);
      if (num3 > 9) {
        bytesConsumed = i;
        value = num2;
        return true;
      }
      num2 = num2 * 10 + num3;
    }
  } else {
    for (Int32 j = 1; j < 18; j++) {
      UInt64 num4 = (UInt32)(source[j] - 48);
      if (num4 > 9) {
        bytesConsumed = j;
        value = num2;
        return true;
      }
      num2 = num2 * 10 + num4;
    }
    for (Int32 k = 18; k < source.get_Length(); k++) {
      UInt64 num5 = (UInt32)(source[k] - 48);
      if (num5 > 9) {
        bytesConsumed = k;
        value = num2;
        return true;
      }
      if (num2 > 1844674407370955161 || (num2 == 1844674407370955161 && num5 > 5)) {
        bytesConsumed = 0;
        value = 0;
        return false;
      }
      num2 = num2 * 10 + num5;
    }
  }
  bytesConsumed = source.get_Length();
  value = num2;
  return true;
}

Boolean Utf8Parser::TryParseByteN(ReadOnlySpan<Byte> source, Byte& value, Int32& bytesConsumed) {
  Int32 num;
  Int32 num3;
  Int32 num2;
  if (source.get_Length() >= 1) {
    num = 0;
    num2 = source[num];
    if (num2 == 43) {
      num++;
      if ((UInt32)num >= (UInt32)source.get_Length()) {
      }
      num2 = source[num];
    }
    if (num2 != 46) {
      if (ParserHelpers::IsDigit(num2)) {
        num3 = num2 - 48;
        while (true) {
          num++;
          if ((UInt32)num >= (UInt32)source.get_Length()) {
            break;
          }
          num2 = source[num];
          if (num2 == 44) {
          }
          if (num2 == 46) {
          }
          if (!ParserHelpers::IsDigit(num2)) {
            break;
          }
          num3 = num3 * 10 + num2 - 48;
          if (num3 <= 255) {
          }
        }
      }
    } else {
      num3 = 0;
      num++;
      if ((UInt32)num < (UInt32)source.get_Length() && source[num] == 48) {
      }
    }
  }
}

Boolean Utf8Parser::TryParseUInt16N(ReadOnlySpan<Byte> source, UInt16& value, Int32& bytesConsumed) {
  Int32 num;
  Int32 num3;
  Int32 num2;
  if (source.get_Length() >= 1) {
    num = 0;
    num2 = source[num];
    if (num2 == 43) {
      num++;
      if ((UInt32)num >= (UInt32)source.get_Length()) {
      }
      num2 = source[num];
    }
    if (num2 != 46) {
      if (ParserHelpers::IsDigit(num2)) {
        num3 = num2 - 48;
        while (true) {
          num++;
          if ((UInt32)num >= (UInt32)source.get_Length()) {
            break;
          }
          num2 = source[num];
          if (num2 == 44) {
          }
          if (num2 == 46) {
          }
          if (!ParserHelpers::IsDigit(num2)) {
            break;
          }
          num3 = num3 * 10 + num2 - 48;
          if (num3 <= 65535) {
          }
        }
      }
    } else {
      num3 = 0;
      num++;
      if ((UInt32)num < (UInt32)source.get_Length() && source[num] == 48) {
      }
    }
  }
}

Boolean Utf8Parser::TryParseUInt32N(ReadOnlySpan<Byte> source, UInt32& value, Int32& bytesConsumed) {
  Int32 num;
  Int32 num3;
  Int32 num2;
  if (source.get_Length() >= 1) {
    num = 0;
    num2 = source[num];
    if (num2 == 43) {
      num++;
      if ((UInt32)num >= (UInt32)source.get_Length()) {
      }
      num2 = source[num];
    }
    if (num2 != 46) {
      if (ParserHelpers::IsDigit(num2)) {
        num3 = num2 - 48;
        while (true) {
          num++;
          if ((UInt32)num >= (UInt32)source.get_Length()) {
            break;
          }
          num2 = source[num];
          if (num2 == 44) {
          }
          if (num2 == 46) {
          }
          if (!ParserHelpers::IsDigit(num2)) {
            break;
          }
          if ((UInt32)num3 <= 429496729u && (num3 != 429496729 || num2 <= 53)) {
            num3 = num3 * 10 + num2 - 48;
          }
        }
      }
    } else {
      num3 = 0;
      num++;
      if ((UInt32)num < (UInt32)source.get_Length() && source[num] == 48) {
      }
    }
  }
}

Boolean Utf8Parser::TryParseUInt64N(ReadOnlySpan<Byte> source, UInt64& value, Int32& bytesConsumed) {
  Int32 num;
  Int64 num3;
  Int32 num2;
  if (source.get_Length() >= 1) {
    num = 0;
    num2 = source[num];
    if (num2 == 43) {
      num++;
      if ((UInt32)num >= (UInt32)source.get_Length()) {
      }
      num2 = source[num];
    }
    if (num2 != 46) {
      if (ParserHelpers::IsDigit(num2)) {
        num3 = num2 - 48;
        while (true) {
          num++;
          if ((UInt32)num >= (UInt32)source.get_Length()) {
            break;
          }
          num2 = source[num];
          if (num2 == 44) {
          }
          if (num2 == 46) {
          }
          if (!ParserHelpers::IsDigit(num2)) {
            break;
          }
          if ((UInt64)num3 <= 1844674407370955161 && (num3 != 1844674407370955161 || num2 <= 53)) {
            num3 = num3 * 10 + num2 - 48;
          }
        }
      }
    } else {
      num3 = 0;
      num++;
      if ((UInt32)num < (UInt32)source.get_Length() && source[num] == 48) {
      }
    }
  }
}

Boolean Utf8Parser::TryParseByteX(ReadOnlySpan<Byte> source, Byte& value, Int32& bytesConsumed) {
  if (source.get_Length() < 1) {
    bytesConsumed = 0;
    value = 0;
    return false;
  }
  ReadOnlySpan<Byte> hexLookup = ParserHelpers::get_HexLookup();
  Byte index = source[0];
  Byte b = hexLookup[index];
  if (b == Byte::MaxValue) {
    bytesConsumed = 0;
    value = 0;
    return false;
  }
  UInt32 num = b;
  if (source.get_Length() <= 2) {
    for (Int32 i = 1; i < source.get_Length(); i++) {
      index = source[i];
      b = hexLookup[index];
      if (b == Byte::MaxValue) {
        bytesConsumed = i;
        value = (Byte)num;
        return true;
      }
      num = (num << 4) + b;
    }
  } else {
    for (Int32 j = 1; j < 2; j++) {
      index = source[j];
      b = hexLookup[index];
      if (b == Byte::MaxValue) {
        bytesConsumed = j;
        value = (Byte)num;
        return true;
      }
      num = (num << 4) + b;
    }
    for (Int32 k = 2; k < source.get_Length(); k++) {
      index = source[k];
      b = hexLookup[index];
      if (b == Byte::MaxValue) {
        bytesConsumed = k;
        value = (Byte)num;
        return true;
      }
      if (num > 15) {
        bytesConsumed = 0;
        value = 0;
        return false;
      }
      num = (num << 4) + b;
    }
  }
  bytesConsumed = source.get_Length();
  value = (Byte)num;
  return true;
}

Boolean Utf8Parser::TryParseUInt16X(ReadOnlySpan<Byte> source, UInt16& value, Int32& bytesConsumed) {
  if (source.get_Length() < 1) {
    bytesConsumed = 0;
    value = 0;
    return false;
  }
  ReadOnlySpan<Byte> hexLookup = ParserHelpers::get_HexLookup();
  Byte index = source[0];
  Byte b = hexLookup[index];
  if (b == Byte::MaxValue) {
    bytesConsumed = 0;
    value = 0;
    return false;
  }
  UInt32 num = b;
  if (source.get_Length() <= 4) {
    for (Int32 i = 1; i < source.get_Length(); i++) {
      index = source[i];
      b = hexLookup[index];
      if (b == Byte::MaxValue) {
        bytesConsumed = i;
        value = (UInt16)num;
        return true;
      }
      num = (num << 4) + b;
    }
  } else {
    for (Int32 j = 1; j < 4; j++) {
      index = source[j];
      b = hexLookup[index];
      if (b == Byte::MaxValue) {
        bytesConsumed = j;
        value = (UInt16)num;
        return true;
      }
      num = (num << 4) + b;
    }
    for (Int32 k = 4; k < source.get_Length(); k++) {
      index = source[k];
      b = hexLookup[index];
      if (b == Byte::MaxValue) {
        bytesConsumed = k;
        value = (UInt16)num;
        return true;
      }
      if (num > 4095) {
        bytesConsumed = 0;
        value = 0;
        return false;
      }
      num = (num << 4) + b;
    }
  }
  bytesConsumed = source.get_Length();
  value = (UInt16)num;
  return true;
}

Boolean Utf8Parser::TryParseUInt32X(ReadOnlySpan<Byte> source, UInt32& value, Int32& bytesConsumed) {
  if (source.get_Length() < 1) {
    bytesConsumed = 0;
    value = 0u;
    return false;
  }
  ReadOnlySpan<Byte> hexLookup = ParserHelpers::get_HexLookup();
  Byte index = source[0];
  Byte b = hexLookup[index];
  if (b == Byte::MaxValue) {
    bytesConsumed = 0;
    value = 0u;
    return false;
  }
  UInt32 num = b;
  if (source.get_Length() <= 8) {
    for (Int32 i = 1; i < source.get_Length(); i++) {
      index = source[i];
      b = hexLookup[index];
      if (b == Byte::MaxValue) {
        bytesConsumed = i;
        value = num;
        return true;
      }
      num = (num << 4) + b;
    }
  } else {
    for (Int32 j = 1; j < 8; j++) {
      index = source[j];
      b = hexLookup[index];
      if (b == Byte::MaxValue) {
        bytesConsumed = j;
        value = num;
        return true;
      }
      num = (num << 4) + b;
    }
    for (Int32 k = 8; k < source.get_Length(); k++) {
      index = source[k];
      b = hexLookup[index];
      if (b == Byte::MaxValue) {
        bytesConsumed = k;
        value = num;
        return true;
      }
      if (num > 268435455) {
        bytesConsumed = 0;
        value = 0u;
        return false;
      }
      num = (num << 4) + b;
    }
  }
  bytesConsumed = source.get_Length();
  value = num;
  return true;
}

Boolean Utf8Parser::TryParseUInt64X(ReadOnlySpan<Byte> source, UInt64& value, Int32& bytesConsumed) {
  if (source.get_Length() < 1) {
    bytesConsumed = 0;
    value = 0;
    return false;
  }
  ReadOnlySpan<Byte> hexLookup = ParserHelpers::get_HexLookup();
  Byte index = source[0];
  Byte b = hexLookup[index];
  if (b == Byte::MaxValue) {
    bytesConsumed = 0;
    value = 0;
    return false;
  }
  UInt64 num = b;
  if (source.get_Length() <= 16) {
    for (Int32 i = 1; i < source.get_Length(); i++) {
      index = source[i];
      b = hexLookup[index];
      if (b == Byte::MaxValue) {
        bytesConsumed = i;
        value = num;
        return true;
      }
      num = (num << 4) + b;
    }
  } else {
    for (Int32 j = 1; j < 16; j++) {
      index = source[j];
      b = hexLookup[index];
      if (b == Byte::MaxValue) {
        bytesConsumed = j;
        value = num;
        return true;
      }
      num = (num << 4) + b;
    }
    for (Int32 k = 16; k < source.get_Length(); k++) {
      index = source[k];
      b = hexLookup[index];
      if (b == Byte::MaxValue) {
        bytesConsumed = k;
        value = num;
        return true;
      }
      if (num > 1152921504606846975) {
        bytesConsumed = 0;
        value = 0;
        return false;
      }
      num = (num << 4) + b;
    }
  }
  bytesConsumed = source.get_Length();
  value = num;
  return true;
}

Boolean Utf8Parser::TryParseNumber(ReadOnlySpan<Byte> source, Number::NumberBuffer& number, Int32& bytesConsumed, ParseNumberOptions options, Boolean& textUsedExponentNotation) {
  textUsedExponentNotation = false;
  if (source.get_Length() == 0) {
    bytesConsumed = 0;
    return false;
  }
  Span<Byte> digits = number.Digits;
  Int32 i = 0;
  Int32 num = 0;
  Byte b = source[i];
  if (b != 43) {
    if (b != 45) {
    }
    number.IsNegative = true;
  }
  i++;
  if (i == source.get_Length()) {
    bytesConsumed = 0;
    return false;
  }
  b = source[i];
}

Boolean Utf8Parser::TryParseTimeSpanBigG(ReadOnlySpan<Byte> source, TimeSpan& value, Int32& bytesConsumed) {
  Int32 i = 0;
  Byte b = 0;
  for (; i != source.get_Length(); i++) {
    b = source[i];
    if (b != 32 && b != 9) {
      break;
    }
  }
  if (i == source.get_Length()) {
    value = TimeSpan();
    bytesConsumed = 0;
    return false;
  }
  Boolean isNegative = false;
  if (b == 45) {
    isNegative = true;
    i++;
    if (i == source.get_Length()) {
      value = TimeSpan();
      bytesConsumed = 0;
      return false;
    }
  }
}

Boolean Utf8Parser::TryParseTimeSpanC(ReadOnlySpan<Byte> source, TimeSpan& value, Int32& bytesConsumed) {
  TimeSpanSplitter timeSpanSplitter = TimeSpanSplitter();
  if (!timeSpanSplitter.TrySplitTimeSpan(source, true, bytesConsumed)) {
    value = TimeSpan();
    return false;
  }
  Boolean isNegative = timeSpanSplitter.IsNegative;
  Boolean flag;
  switch (timeSpanSplitter.Separators.get()) {
    case 0u:
      flag = TryCreateTimeSpan(isNegative, timeSpanSplitter.V1, 0u, 0u, 0u, 0u, value);
      break;
    case 16777216u:
      flag = TryCreateTimeSpan(isNegative, 0u, timeSpanSplitter.V1, timeSpanSplitter.V2, 0u, 0u, value);
      break;
    case 33619968u:
      flag = TryCreateTimeSpan(isNegative, timeSpanSplitter.V1, timeSpanSplitter.V2, timeSpanSplitter.V3, 0u, 0u, value);
      break;
    case 16842752u:
      flag = TryCreateTimeSpan(isNegative, 0u, timeSpanSplitter.V1, timeSpanSplitter.V2, timeSpanSplitter.V3, 0u, value);
      break;
    case 33620224u:
      flag = TryCreateTimeSpan(isNegative, timeSpanSplitter.V1, timeSpanSplitter.V2, timeSpanSplitter.V3, timeSpanSplitter.V4, 0u, value);
      break;
    case 16843264u:
      flag = TryCreateTimeSpan(isNegative, 0u, timeSpanSplitter.V1, timeSpanSplitter.V2, timeSpanSplitter.V3, timeSpanSplitter.V4, value);
      break;
    case 33620226u:
      flag = TryCreateTimeSpan(isNegative, timeSpanSplitter.V1, timeSpanSplitter.V2, timeSpanSplitter.V3, timeSpanSplitter.V4, timeSpanSplitter.V5, value);
      break;
    default:
      value = TimeSpan();
      flag = false;
      break;
  }
  if (!flag) {
    bytesConsumed = 0;
    return false;
  }
  return true;
}

Boolean Utf8Parser::TryParse(ReadOnlySpan<Byte> source, TimeSpan& value, Int32& bytesConsumed, Char standardFormat) {
  switch (standardFormat.get()) {
    case 0:
    case 84:
    case 99:
    case 116:
      return TryParseTimeSpanC(source, value, bytesConsumed);
    case 71:
      return TryParseTimeSpanBigG(source, value, bytesConsumed);
    case 103:
      return TryParseTimeSpanLittleG(source, value, bytesConsumed);
    default:
      return ParserHelpers::TryParseThrowFormatException(value, bytesConsumed);
  }
}

Boolean Utf8Parser::TryParseTimeSpanFraction(ReadOnlySpan<Byte> source, UInt32& value, Int32& bytesConsumed) {
  Int32 num = 0;
  if (num == source.get_Length()) {
    value = 0u;
    bytesConsumed = 0;
    return false;
  }
  UInt32 num2 = (UInt32)(source[num] - 48);
  if (num2 > 9) {
    value = 0u;
    bytesConsumed = 0;
    return false;
  }
  num++;
  UInt32 num3 = num2;
  Int32 num4 = 1;
  while (num != source.get_Length()) {
    num2 = (UInt32)(source[num] - 48);
    if (num2 > 9) {
      break;
    }
    num++;
    num4++;
    if (num4 > 7) {
      value = 0u;
      bytesConsumed = 0;
      return false;
    }
    num3 = 10 * num3 + num2;
  }
  switch (num4.get()) {
    case 6:
      num3 *= 10;
      break;
    case 5:
      num3 *= 100;
      break;
    case 4:
      num3 *= 1000;
      break;
    case 3:
      num3 *= 10000;
      break;
    case 2:
      num3 *= 100000;
      break;
    default:
      num3 *= 1000000;
      break;
    case 7:
      break;
  }
  value = num3;
  bytesConsumed = num;
  return true;
}

Boolean Utf8Parser::TryCreateTimeSpan(Boolean isNegative, UInt32 days, UInt32 hours, UInt32 minutes, UInt32 seconds, UInt32 fraction, TimeSpan& timeSpan) {
  if (hours > 23 || minutes > 59 || seconds > 59) {
    timeSpan = TimeSpan();
    return false;
  }
  Int64 num = ((Int64)days * 3600 * 24 + (Int64)hours * 3600 + (Int64)minutes * 60 + seconds) * 1000;
  Int64 ticks;
  if (isNegative) {
  } else {
    if (num > 922337203685477) {
      timeSpan = TimeSpan();
      return false;
    }
    Int64 num3 = num * 10000;
    if (num3 > Int64::MaxValue - (Int64)fraction) {
      timeSpan = TimeSpan();
      return false;
    }
    ticks = num3 + fraction;
  }
  timeSpan = TimeSpan(ticks);
  return true;
}

Boolean Utf8Parser::TryParseTimeSpanLittleG(ReadOnlySpan<Byte> source, TimeSpan& value, Int32& bytesConsumed) {
  TimeSpanSplitter timeSpanSplitter = TimeSpanSplitter();
  if (!timeSpanSplitter.TrySplitTimeSpan(source, false, bytesConsumed)) {
    value = TimeSpan();
    return false;
  }
  Boolean isNegative = timeSpanSplitter.IsNegative;
  Boolean flag;
  switch (timeSpanSplitter.Separators.get()) {
    case 0u:
      flag = TryCreateTimeSpan(isNegative, timeSpanSplitter.V1, 0u, 0u, 0u, 0u, value);
      break;
    case 16777216u:
      flag = TryCreateTimeSpan(isNegative, 0u, timeSpanSplitter.V1, timeSpanSplitter.V2, 0u, 0u, value);
      break;
    case 16842752u:
      flag = TryCreateTimeSpan(isNegative, 0u, timeSpanSplitter.V1, timeSpanSplitter.V2, timeSpanSplitter.V3, 0u, value);
      break;
    case 16843008u:
      flag = TryCreateTimeSpan(isNegative, timeSpanSplitter.V1, timeSpanSplitter.V2, timeSpanSplitter.V3, timeSpanSplitter.V4, 0u, value);
      break;
    case 16843264u:
      flag = TryCreateTimeSpan(isNegative, 0u, timeSpanSplitter.V1, timeSpanSplitter.V2, timeSpanSplitter.V3, timeSpanSplitter.V4, value);
      break;
    case 16843010u:
      flag = TryCreateTimeSpan(isNegative, timeSpanSplitter.V1, timeSpanSplitter.V2, timeSpanSplitter.V3, timeSpanSplitter.V4, timeSpanSplitter.V5, value);
      break;
    default:
      value = TimeSpan();
      flag = false;
      break;
  }
  if (!flag) {
    bytesConsumed = 0;
    return false;
  }
  return true;
}

void Utf8Parser::cctor() {
  s_daysToMonth365 = rt::newarr<Array<Int32>>(13);
  s_daysToMonth366 = rt::newarr<Array<Int32>>(13);
}

} // namespace System::Private::CoreLib::System::Buffers::Text::Utf8ParserNamespace
