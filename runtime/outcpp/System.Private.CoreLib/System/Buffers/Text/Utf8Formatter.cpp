#include "Utf8Formatter-dep.h"

#include <System.Private.CoreLib/System/Buffers/Binary/BinaryPrimitives-dep.h>
#include <System.Private.CoreLib/System/Buffers/Text/FormattingHelpers-dep.h>
#include <System.Private.CoreLib/System/Buffers/Text/Utf8Constants-dep.h>
#include <System.Private.CoreLib/System/Buffers/Text/Utf8Formatter-dep.h>
#include <System.Private.CoreLib/System/Char-dep.h>
#include <System.Private.CoreLib/System/DateTimeKind.h>
#include <System.Private.CoreLib/System/HexConverter-dep.h>
#include <System.Private.CoreLib/System/IntPtr-dep.h>
#include <System.Private.CoreLib/System/Math-dep.h>
#include <System.Private.CoreLib/System/NotSupportedException-dep.h>
#include <System.Private.CoreLib/System/Number-dep.h>
#include <System.Private.CoreLib/System/ReadOnlySpan-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/TimeSpan-dep.h>
#include <System.Private.CoreLib/System/TimeZoneInfo-dep.h>
#include <System.Private.CoreLib/System/UInt32-dep.h>

namespace System::Private::CoreLib::System::Buffers::Text::Utf8FormatterNamespace {
using namespace System::Buffers::Binary;

template <>
Boolean Utf8Formatter::TryFormat(Boolean value, Span<Byte> destination, Int32& bytesWritten, StandardFormat format) {
  Char symbolOrDefault = FormattingHelpers::GetSymbolOrDefault(format, 'G');
  if (value) {
    if (symbolOrDefault == 'G') {
      if (BinaryPrimitives::TryWriteUInt32BigEndian(destination, 1416787301u)) {
        goto IL_0033;
      }
    } else {
      if (symbolOrDefault != 'l') {
        goto IL_0083;
      }
      if (BinaryPrimitives::TryWriteUInt32BigEndian(destination, 1953658213u)) {
        goto IL_0033;
      }
    }
  } else if (symbolOrDefault == 'G') {
    if (4u < (UInt32)destination.get_Length()) {
      BinaryPrimitives::WriteUInt32BigEndian(destination, 1180789875u);
      goto IL_006e;
    }
  } else {
    if (symbolOrDefault != 'l') {
      goto IL_0083;
    }
    if (4u < (UInt32)destination.get_Length()) {
      BinaryPrimitives::WriteUInt32BigEndian(destination, 1717660787u);
      goto IL_006e;
    }
  }

  bytesWritten = 0;
  return false;

IL_0033:
  bytesWritten = 4;
  return true;

IL_0083:
  return FormattingHelpers::TryFormatThrowFormatException(bytesWritten);

IL_006e:
  destination[4] = 101;
  bytesWritten = 5;
  return true;
}

template <>
Boolean Utf8Formatter::TryFormat(DateTimeOffset value, Span<Byte> destination, Int32& bytesWritten, StandardFormat format) {
  TimeSpan offset = Utf8Constants::NullUtcOffset;
  Char c = format.get_Symbol();
  if (format.get_IsDefault()) {
    c = 'G';
    offset = value.get_Offset();
  }
  switch (c.get()) {
    case 'R':
      return TryFormatDateTimeR(value.get_UtcDateTime(), destination, bytesWritten);
    case 'l':
      return TryFormatDateTimeL(value.get_UtcDateTime(), destination, bytesWritten);
    case 'O':
      return TryFormatDateTimeO(value.get_DateTime(), value.get_Offset(), destination, bytesWritten);
    case 'G':
      return TryFormatDateTimeG(value.get_DateTime(), offset, destination, bytesWritten);
    default:
      return FormattingHelpers::TryFormatThrowFormatException(bytesWritten);
  }
}

template <>
Boolean Utf8Formatter::TryFormat(DateTime value, Span<Byte> destination, Int32& bytesWritten, StandardFormat format) {
  switch (FormattingHelpers::GetSymbolOrDefault(format, 'G').get()) {
    case 'R':
      return TryFormatDateTimeR(value, destination, bytesWritten);
    case 'l':
      return TryFormatDateTimeL(value, destination, bytesWritten);
    case 'O':
      return TryFormatDateTimeO(value, Utf8Constants::NullUtcOffset, destination, bytesWritten);
    case 'G':
      return TryFormatDateTimeG(value, Utf8Constants::NullUtcOffset, destination, bytesWritten);
    default:
      return FormattingHelpers::TryFormatThrowFormatException(bytesWritten);
  }
}

Boolean Utf8Formatter::TryFormatDateTimeG(DateTime value, TimeSpan offset, Span<Byte> destination, Int32& bytesWritten) {
  Int32 num = 19;
  if (offset != Utf8Constants::NullUtcOffset) {
    num += 7;
  }
  if (destination.get_Length() < num) {
    bytesWritten = 0;
    return false;
  }
  bytesWritten = num;
  Byte b = destination[18];
  Int32 year;
  Int32 month;
  Int32 day;
  value.GetDate(year, month, day);
  Int32 hour;
  Int32 minute;
  Int32 second;
  value.GetTime(hour, minute, second);
  FormattingHelpers::WriteTwoDecimalDigits((UInt32)month, destination);
  destination[2] = 47;
  FormattingHelpers::WriteTwoDecimalDigits((UInt32)day, destination, 3);
  destination[5] = 47;
  FormattingHelpers::WriteFourDecimalDigits((UInt32)year, destination, 6);
  destination[10] = 32;
  FormattingHelpers::WriteTwoDecimalDigits((UInt32)hour, destination, 11);
  destination[13] = 58;
  FormattingHelpers::WriteTwoDecimalDigits((UInt32)minute, destination, 14);
  destination[16] = 58;
  FormattingHelpers::WriteTwoDecimalDigits((UInt32)second, destination, 17);
  if (offset != Utf8Constants::NullUtcOffset) {
    Int32 num2 = (Int32)(offset.get_Ticks() / 600000000);
    Byte b2;
    if (num2 < 0) {
      b2 = 45;
      num2 = -num2;
    } else {
      b2 = 43;
    }
    Int32 result;
    Int32 value2 = Math::DivRem(num2, 60, result);
    FormattingHelpers::WriteTwoDecimalDigits((UInt32)result, destination, 24);
    destination[23] = 58;
    FormattingHelpers::WriteTwoDecimalDigits((UInt32)value2, destination, 21);
    destination[20] = b2;
    destination[19] = 32;
  }
  return true;
}

Boolean Utf8Formatter::TryFormatDateTimeL(DateTime value, Span<Byte> destination, Int32& bytesWritten) {
  if (28u >= (UInt32)destination.get_Length()) {
    bytesWritten = 0;
    return false;
  }
  Int32 year;
  Int32 month;
  Int32 day;
  value.GetDate(year, month, day);
  Int32 hour;
  Int32 minute;
  Int32 second;
  value.GetTime(hour, minute, second);
  UInt32 num = s_dayAbbreviationsLowercase[(Int32)value.get_DayOfWeek()];
  destination[0] = (Byte)num;
  num >>= 8;
  destination[1] = (Byte)num;
  num >>= 8;
  destination[2] = (Byte)num;
  destination[3] = 44;
  destination[4] = 32;
  FormattingHelpers::WriteTwoDecimalDigits((UInt32)day, destination, 5);
  destination[7] = 32;
  UInt32 num2 = s_monthAbbreviationsLowercase[month - 1];
  destination[8] = (Byte)num2;
  num2 >>= 8;
  destination[9] = (Byte)num2;
  num2 >>= 8;
  destination[10] = (Byte)num2;
  destination[11] = 32;
  FormattingHelpers::WriteFourDecimalDigits((UInt32)year, destination, 12);
  destination[16] = 32;
  FormattingHelpers::WriteTwoDecimalDigits((UInt32)hour, destination, 17);
  destination[19] = 58;
  FormattingHelpers::WriteTwoDecimalDigits((UInt32)minute, destination, 20);
  destination[22] = 58;
  FormattingHelpers::WriteTwoDecimalDigits((UInt32)second, destination, 23);
  destination[25] = 32;
  destination[26] = 103;
  destination[27] = 109;
  destination[28] = 116;
  bytesWritten = 29;
  return true;
}

Boolean Utf8Formatter::TryFormatDateTimeO(DateTime value, TimeSpan offset, Span<Byte> destination, Int32& bytesWritten) {
  Int32 num = 27;
  DateTimeKind dateTimeKind = DateTimeKind::Local;
  if (offset == Utf8Constants::NullUtcOffset) {
    dateTimeKind = value.get_Kind();
    switch (dateTimeKind) {
      case DateTimeKind::Local:
        offset = TimeZoneInfo::in::get_Local()->GetUtcOffset(value);
        num += 6;
        break;
      case DateTimeKind::Utc:
        num++;
        break;
    }
  } else {
    num += 6;
  }
  if (destination.get_Length() < num) {
    bytesWritten = 0;
    return false;
  }
  bytesWritten = num;
  Byte& reference = destination[26];
  Int32 year;
  Int32 month;
  Int32 day;
  value.GetDate(year, month, day);
  Int32 hour;
  Int32 minute;
  Int32 second;
  Int32 tick;
  value.GetTimePrecise(hour, minute, second, tick);
  FormattingHelpers::WriteFourDecimalDigits((UInt32)year, destination);
  destination[4] = 45;
  FormattingHelpers::WriteTwoDecimalDigits((UInt32)month, destination, 5);
  destination[7] = 45;
  FormattingHelpers::WriteTwoDecimalDigits((UInt32)day, destination, 8);
  destination[10] = 84;
  FormattingHelpers::WriteTwoDecimalDigits((UInt32)hour, destination, 11);
  destination[13] = 58;
  FormattingHelpers::WriteTwoDecimalDigits((UInt32)minute, destination, 14);
  destination[16] = 58;
  FormattingHelpers::WriteTwoDecimalDigits((UInt32)second, destination, 17);
  destination[19] = 46;
  FormattingHelpers::WriteDigits((UInt32)tick, destination.Slice(20, 7));
  switch (dateTimeKind) {
    case DateTimeKind::Local:
      {
        Int32 num2 = (Int32)(offset.get_Ticks() / 600000000);
        Byte b;
        if (num2 < 0) {
          b = 45;
          num2 = -num2;
        } else {
          b = 43;
        }
        Int32 result;
        Int32 value2 = Math::DivRem(num2, 60, result);
        FormattingHelpers::WriteTwoDecimalDigits((UInt32)result, destination, 31);
        destination[30] = 58;
        FormattingHelpers::WriteTwoDecimalDigits((UInt32)value2, destination, 28);
        destination[27] = b;
        break;
      }case DateTimeKind::Utc:
      destination[27] = 90;
      break;
  }
  return true;
}

Boolean Utf8Formatter::TryFormatDateTimeR(DateTime value, Span<Byte> destination, Int32& bytesWritten) {
  if (28u >= (UInt32)destination.get_Length()) {
    bytesWritten = 0;
    return false;
  }
  Int32 year;
  Int32 month;
  Int32 day;
  value.GetDate(year, month, day);
  Int32 hour;
  Int32 minute;
  Int32 second;
  value.GetTime(hour, minute, second);
  UInt32 num = s_dayAbbreviations[(Int32)value.get_DayOfWeek()];
  destination[0] = (Byte)num;
  num >>= 8;
  destination[1] = (Byte)num;
  num >>= 8;
  destination[2] = (Byte)num;
  destination[3] = 44;
  destination[4] = 32;
  FormattingHelpers::WriteTwoDecimalDigits((UInt32)day, destination, 5);
  destination[7] = 32;
  UInt32 num2 = s_monthAbbreviations[month - 1];
  destination[8] = (Byte)num2;
  num2 >>= 8;
  destination[9] = (Byte)num2;
  num2 >>= 8;
  destination[10] = (Byte)num2;
  destination[11] = 32;
  FormattingHelpers::WriteFourDecimalDigits((UInt32)year, destination, 12);
  destination[16] = 32;
  FormattingHelpers::WriteTwoDecimalDigits((UInt32)hour, destination, 17);
  destination[19] = 58;
  FormattingHelpers::WriteTwoDecimalDigits((UInt32)minute, destination, 20);
  destination[22] = 58;
  FormattingHelpers::WriteTwoDecimalDigits((UInt32)second, destination, 23);
  destination[25] = 32;
  destination[26] = 71;
  destination[27] = 77;
  destination[28] = 84;
  bytesWritten = 29;
  return true;
}

template <>
Boolean Utf8Formatter::TryFormat(Decimal value, Span<Byte> destination, Int32& bytesWritten, StandardFormat format) {
  if (format.get_IsDefault()) {
    format = 'G';
  }
  switch (format.get_Symbol().get()) {
    case 'G':
    case 'g':
      {
        if (format.get_Precision() != Byte::MaxValue) {
          rt::throw_exception<NotSupportedException>(SR::get_Argument_GWithPrecisionNotSupported());
        }
        Byte as[31] = {};
        Byte* digits3 = as;
        Number::NumberBuffer number3 = Number::NumberBuffer(Number::NumberBufferKind::Decimal, digits3, 31);
        Number::DecimalToNumber(value, number3);
        if (number3.Digits[0] == 0) {
          number3.IsNegative = false;
        }
        return TryFormatDecimalG(number3, destination, bytesWritten);
      }case 'F':
    case 'f':
      {
        Byte as[31] = {};
        Byte* digits2 = as;
        Number::NumberBuffer number2 = Number::NumberBuffer(Number::NumberBufferKind::Decimal, digits2, 31);
        Number::DecimalToNumber(value, number2);
        Byte b2 = (Byte)((format.get_Precision() == Byte::MaxValue) ? 2 : format.get_Precision());
        Number::RoundNumber(number2, number2.Scale + b2, false);
        return TryFormatDecimalF(number2, destination, bytesWritten, b2);
      }case 'E':
    case 'e':
      {
        Byte as[31] = {};
        Byte* digits = as;
        Number::NumberBuffer number = Number::NumberBuffer(Number::NumberBufferKind::Decimal, digits, 31);
        Number::DecimalToNumber(value, number);
        Byte b = (Byte)((format.get_Precision() == Byte::MaxValue) ? 6 : format.get_Precision());
        Number::RoundNumber(number, b + 1, false);
        return TryFormatDecimalE(number, destination, bytesWritten, b, (Byte)format.get_Symbol());
      }default:
      return FormattingHelpers::TryFormatThrowFormatException(bytesWritten);
  }
}

Boolean Utf8Formatter::TryFormatDecimalE(Number::NumberBuffer& number, Span<Byte> destination, Int32& bytesWritten, Byte precision, Byte exponentSymbol) {
  Int32 scale = number.Scale;
  ReadOnlySpan<Byte> readOnlySpan = number.Digits;
  Int32 num = (number.IsNegative ? 1 : 0) + 1 + ((precision != 0) ? (precision + 1) : 0) + 2 + 3;
  if (destination.get_Length() < num) {
    bytesWritten = 0;
    return false;
  }
  Int32 num2 = 0;
  Int32 num3 = 0;
  if (number.IsNegative) {
    destination[num2++] = 45;
  }
  Byte b = readOnlySpan[num3];
  Int32 num4;
  if (b == 0) {
    destination[num2++] = 48;
    num4 = 0;
  } else {
    destination[num2++] = b;
    num3++;
    num4 = scale - 1;
  }
  if (precision > 0) {
    destination[num2++] = 46;
    for (Int32 i = 0; i < precision; i++) {
      Byte b2 = readOnlySpan[num3];
      if (b2 == 0) {
        while (i++ < precision) {
          destination[num2++] = 48;
        }
        break;
      }
      destination[num2++] = b2;
      num3++;
    }
  }
  destination[num2++] = exponentSymbol;
  if (num4 >= 0) {
    destination[num2++] = 43;
  } else {
    destination[num2++] = 45;
    num4 = -num4;
  }
  destination[num2++] = 48;
  destination[num2++] = (Byte)(num4 / 10 + 48);
  destination[num2++] = (Byte)(num4 % 10 + 48);
  bytesWritten = num;
  return true;
}

Boolean Utf8Formatter::TryFormatDecimalF(Number::NumberBuffer& number, Span<Byte> destination, Int32& bytesWritten, Byte precision) {
  Int32 scale = number.Scale;
  ReadOnlySpan<Byte> readOnlySpan = number.Digits;
  Int32 num = (number.IsNegative ? 1 : 0) + ((scale <= 0) ? 1 : scale) + ((precision != 0) ? (precision + 1) : 0);
  if (destination.get_Length() < num) {
    bytesWritten = 0;
    return false;
  }
  Int32 i = 0;
  Int32 num2 = 0;
  if (number.IsNegative) {
    destination[num2++] = 45;
  }
  if (scale <= 0) {
    destination[num2++] = 48;
  } else {
    for (; i < scale; i++) {
      Byte b = readOnlySpan[i];
      if (b == 0) {
        Int32 num3 = scale - i;
        for (Int32 j = 0; j < num3; j++) {
          destination[num2++] = 48;
        }
        break;
      }
      destination[num2++] = b;
    }
  }
  if (precision > 0) {
    destination[num2++] = 46;
    Int32 k = 0;
    if (scale < 0) {
      Int32 num4 = Math::Min(precision, -scale);
      for (Int32 l = 0; l < num4; l++) {
        destination[num2++] = 48;
      }
      k += num4;
    }
    for (; k < precision; k++) {
      Byte b2 = readOnlySpan[i];
      if (b2 == 0) {
        while (k++ < precision) {
          destination[num2++] = 48;
        }
        break;
      }
      destination[num2++] = b2;
      i++;
    }
  }
  bytesWritten = num;
  return true;
}

Boolean Utf8Formatter::TryFormatDecimalG(Number::NumberBuffer& number, Span<Byte> destination, Int32& bytesWritten) {
  Int32 scale = number.Scale;
  ReadOnlySpan<Byte> readOnlySpan = number.Digits;
  Int32 digitsCount = number.DigitsCount;
  Boolean flag = scale < digitsCount;
  Int32 num;
  if (flag) {
    num = digitsCount + 1;
    if (scale <= 0) {
      num += 1 + -scale;
    }
  } else {
    num = ((scale <= 0) ? 1 : scale);
  }
  if (number.IsNegative) {
    num++;
  }
  if (destination.get_Length() < num) {
    bytesWritten = 0;
    return false;
  }
  Int32 i = 0;
  Int32 num2 = 0;
  if (number.IsNegative) {
    destination[num2++] = 45;
  }
  if (scale <= 0) {
    destination[num2++] = 48;
  } else {
    for (; i < scale; i++) {
      Byte b = readOnlySpan[i];
      if (b == 0) {
        Int32 num3 = scale - i;
        for (Int32 j = 0; j < num3; j++) {
          destination[num2++] = 48;
        }
        break;
      }
      destination[num2++] = b;
    }
  }
  if (flag) {
    destination[num2++] = 46;
    if (scale < 0) {
      Int32 num4 = -scale;
      for (Int32 k = 0; k < num4; k++) {
        destination[num2++] = 48;
      }
    }
    Byte b2;
    while ((b2 = readOnlySpan[i++]) != 0) {
      destination[num2++] = b2;
    }
  }
  bytesWritten = num;
  return true;
}

template <>
Boolean Utf8Formatter::TryFormat(Double value, Span<Byte> destination, Int32& bytesWritten, StandardFormat format) {
  return TryFormatFloatingPoint(value, destination, bytesWritten, format);
}

template <>
Boolean Utf8Formatter::TryFormat(Single value, Span<Byte> destination, Int32& bytesWritten, StandardFormat format) {
  return TryFormatFloatingPoint(value, destination, bytesWritten, format);
}

template <>
Boolean Utf8Formatter::TryFormat(Guid value, Span<Byte> destination, Int32& bytesWritten, StandardFormat format) {
  Int32 num;
  switch (FormattingHelpers::GetSymbolOrDefault(format, 'D').get()) {
    case 'D':
      num = -2147483612;
      break;
    case 'B':
      num = -2139260122;
      break;
    case 'P':
      num = -2144786394;
      break;
    case 'N':
      num = 32;
      break;
    default:
      return FormattingHelpers::TryFormatThrowFormatException(bytesWritten);
  }
  if ((Byte)num > destination.get_Length()) {
    bytesWritten = 0;
    return false;
  }
  bytesWritten = (Byte)num;
  num >>= 8;
  if ((Byte)num != 0) {
    destination[0] = (Byte)num;
    destination = destination.Slice(1);
  }
  num >>= 8;
  DecomposedGuid decomposedGuid;
  decomposedGuid.Guid = value;
  Byte& reference = destination[8];
  HexConverter::ToBytesBuffer(decomposedGuid.Byte03, destination, 0, HexConverter::Casing::Lower);
  HexConverter::ToBytesBuffer(decomposedGuid.Byte02, destination, 2, HexConverter::Casing::Lower);
  HexConverter::ToBytesBuffer(decomposedGuid.Byte01, destination, 4, HexConverter::Casing::Lower);
  HexConverter::ToBytesBuffer(decomposedGuid.Byte00, destination, 6, HexConverter::Casing::Lower);
  if (num < 0) {
    destination[8] = 45;
    destination = destination.Slice(9);
  } else {
    destination = destination.Slice(8);
  }
  Byte& reference2 = destination[4];
  HexConverter::ToBytesBuffer(decomposedGuid.Byte05, destination, 0, HexConverter::Casing::Lower);
  HexConverter::ToBytesBuffer(decomposedGuid.Byte04, destination, 2, HexConverter::Casing::Lower);
  if (num < 0) {
    destination[4] = 45;
    destination = destination.Slice(5);
  } else {
    destination = destination.Slice(4);
  }
  Byte& reference3 = destination[4];
  HexConverter::ToBytesBuffer(decomposedGuid.Byte07, destination, 0, HexConverter::Casing::Lower);
  HexConverter::ToBytesBuffer(decomposedGuid.Byte06, destination, 2, HexConverter::Casing::Lower);
  if (num < 0) {
    destination[4] = 45;
    destination = destination.Slice(5);
  } else {
    destination = destination.Slice(4);
  }
  Byte& reference4 = destination[4];
  HexConverter::ToBytesBuffer(decomposedGuid.Byte08, destination, 0, HexConverter::Casing::Lower);
  HexConverter::ToBytesBuffer(decomposedGuid.Byte09, destination, 2, HexConverter::Casing::Lower);
  if (num < 0) {
    destination[4] = 45;
    destination = destination.Slice(5);
  } else {
    destination = destination.Slice(4);
  }
  Byte& reference5 = destination[11];
  HexConverter::ToBytesBuffer(decomposedGuid.Byte10, destination, 0, HexConverter::Casing::Lower);
  HexConverter::ToBytesBuffer(decomposedGuid.Byte11, destination, 2, HexConverter::Casing::Lower);
  HexConverter::ToBytesBuffer(decomposedGuid.Byte12, destination, 4, HexConverter::Casing::Lower);
  HexConverter::ToBytesBuffer(decomposedGuid.Byte13, destination, 6, HexConverter::Casing::Lower);
  HexConverter::ToBytesBuffer(decomposedGuid.Byte14, destination, 8, HexConverter::Casing::Lower);
  HexConverter::ToBytesBuffer(decomposedGuid.Byte15, destination, 10, HexConverter::Casing::Lower);
  if ((Byte)num != 0) {
    destination[12] = (Byte)num;
  }
  return true;
}

template <>
Boolean Utf8Formatter::TryFormat(Byte value, Span<Byte> destination, Int32& bytesWritten, StandardFormat format) {
  return TryFormatUInt64(value, destination, bytesWritten, format);
}

template <>
Boolean Utf8Formatter::TryFormat(SByte value, Span<Byte> destination, Int32& bytesWritten, StandardFormat format) {
  return TryFormatInt64(value, 255, destination, bytesWritten, format);
}

template <>
Boolean Utf8Formatter::TryFormat(UInt16 value, Span<Byte> destination, Int32& bytesWritten, StandardFormat format) {
  return TryFormatUInt64(value, destination, bytesWritten, format);
}

template <>
Boolean Utf8Formatter::TryFormat(Int16 value, Span<Byte> destination, Int32& bytesWritten, StandardFormat format) {
  return TryFormatInt64(value, 65535, destination, bytesWritten, format);
}

template <>
Boolean Utf8Formatter::TryFormat(UInt32 value, Span<Byte> destination, Int32& bytesWritten, StandardFormat format) {
  return TryFormatUInt64(value, destination, bytesWritten, format);
}

template <>
Boolean Utf8Formatter::TryFormat(Int32 value, Span<Byte> destination, Int32& bytesWritten, StandardFormat format) {
  return TryFormatInt64(value, 4294967295, destination, bytesWritten, format);
}

template <>
Boolean Utf8Formatter::TryFormat(UInt64 value, Span<Byte> destination, Int32& bytesWritten, StandardFormat format) {
  return TryFormatUInt64(value, destination, bytesWritten, format);
}

template <>
Boolean Utf8Formatter::TryFormat(Int64 value, Span<Byte> destination, Int32& bytesWritten, StandardFormat format) {
  return TryFormatInt64(value, UInt64::MaxValue, destination, bytesWritten, format);
}

Boolean Utf8Formatter::TryFormatInt64(Int64 value, UInt64 mask, Span<Byte> destination, Int32& bytesWritten, StandardFormat format) {
  if (format.get_IsDefault()) {
    return TryFormatInt64Default(value, destination, bytesWritten);
  }
  switch (format.get_Symbol().get()) {
    case 'G':
    case 'g':
      if (format.get_HasPrecision()) {
        rt::throw_exception<NotSupportedException>(SR::get_Argument_GWithPrecisionNotSupported());
      }
      return TryFormatInt64D(value, format.get_Precision(), destination, bytesWritten);
    case 'D':
    case 'd':
      return TryFormatInt64D(value, format.get_Precision(), destination, bytesWritten);
    case 'N':
    case 'n':
      return TryFormatInt64N(value, format.get_Precision(), destination, bytesWritten);
    case 'x':
      return TryFormatUInt64X((UInt64)value & mask, format.get_Precision(), true, destination, bytesWritten);
    case 'X':
      return TryFormatUInt64X((UInt64)value & mask, format.get_Precision(), false, destination, bytesWritten);
    default:
      return FormattingHelpers::TryFormatThrowFormatException(bytesWritten);
  }
}

Boolean Utf8Formatter::TryFormatInt64D(Int64 value, Byte precision, Span<Byte> destination, Int32& bytesWritten) {
  Boolean insertNegationSign = false;
  if (value < 0) {
    insertNegationSign = true;
    value = -value;
  }
  return TryFormatUInt64D((UInt64)value, precision, destination, insertNegationSign, bytesWritten);
}

Boolean Utf8Formatter::TryFormatInt64Default(Int64 value, Span<Byte> destination, Int32& bytesWritten) {
  if ((UInt64)value < 10) {
    return TryFormatUInt32SingleDigit((UInt32)value, destination, bytesWritten);
  }
  Int32 size = IntPtr::get_Size();
  return TryFormatInt64MultipleDigits(value, destination, bytesWritten);
}

Boolean Utf8Formatter::TryFormatInt64MultipleDigits(Int64 value, Span<Byte> destination, Int32& bytesWritten) {
  if (value < 0) {
    value = -value;
    Int32 num = FormattingHelpers::CountDigits((UInt64)value);
    if (num >= destination.get_Length()) {
      bytesWritten = 0;
      return false;
    }
    destination[0] = 45;
    bytesWritten = num + 1;
    FormattingHelpers::WriteDigits((UInt64)value, destination.Slice(1, num));
    return true;
  }
  return TryFormatUInt64MultipleDigits((UInt64)value, destination, bytesWritten);
}

Boolean Utf8Formatter::TryFormatInt64N(Int64 value, Byte precision, Span<Byte> destination, Int32& bytesWritten) {
  Boolean insertNegationSign = false;
  if (value < 0) {
    insertNegationSign = true;
    value = -value;
  }
  return TryFormatUInt64N((UInt64)value, precision, destination, insertNegationSign, bytesWritten);
}

Boolean Utf8Formatter::TryFormatUInt64(UInt64 value, Span<Byte> destination, Int32& bytesWritten, StandardFormat format) {
  if (format.get_IsDefault()) {
    return TryFormatUInt64Default(value, destination, bytesWritten);
  }
  switch (format.get_Symbol().get()) {
    case 'G':
    case 'g':
      if (format.get_HasPrecision()) {
        rt::throw_exception<NotSupportedException>(SR::get_Argument_GWithPrecisionNotSupported());
      }
      return TryFormatUInt64D(value, format.get_Precision(), destination, false, bytesWritten);
    case 'D':
    case 'd':
      return TryFormatUInt64D(value, format.get_Precision(), destination, false, bytesWritten);
    case 'N':
    case 'n':
      return TryFormatUInt64N(value, format.get_Precision(), destination, false, bytesWritten);
    case 'x':
      return TryFormatUInt64X(value, format.get_Precision(), true, destination, bytesWritten);
    case 'X':
      return TryFormatUInt64X(value, format.get_Precision(), false, destination, bytesWritten);
    default:
      return FormattingHelpers::TryFormatThrowFormatException(bytesWritten);
  }
}

Boolean Utf8Formatter::TryFormatUInt64D(UInt64 value, Byte precision, Span<Byte> destination, Boolean insertNegationSign, Int32& bytesWritten) {
  Int32 num = FormattingHelpers::CountDigits(value);
  Int32 num2 = ((precision != Byte::MaxValue) ? precision : 0) - num;
  if (num2 < 0) {
    num2 = 0;
  }
  Int32 num3 = num + num2;
  if (insertNegationSign) {
    num3++;
  }
  if (num3 > destination.get_Length()) {
    bytesWritten = 0;
    return false;
  }
  bytesWritten = num3;
  if (insertNegationSign) {
    destination[0] = 45;
    destination = destination.Slice(1);
  }
  if (num2 > 0) {
    FormattingHelpers::FillWithAsciiZeros(destination.Slice(0, num2));
  }
  FormattingHelpers::WriteDigits(value, destination.Slice(num2, num));
  return true;
}

Boolean Utf8Formatter::TryFormatUInt64Default(UInt64 value, Span<Byte> destination, Int32& bytesWritten) {
  if (value < 10) {
    return TryFormatUInt32SingleDigit((UInt32)value, destination, bytesWritten);
  }
  Int32 size = IntPtr::get_Size();
  return TryFormatUInt64MultipleDigits(value, destination, bytesWritten);
}

Boolean Utf8Formatter::TryFormatUInt32SingleDigit(UInt32 value, Span<Byte> destination, Int32& bytesWritten) {
  if (destination.get_Length() == 0) {
    bytesWritten = 0;
    return false;
  }
  destination[0] = (Byte)(48 + value);
  bytesWritten = 1;
  return true;
}

Boolean Utf8Formatter::TryFormatUInt64MultipleDigits(UInt64 value, Span<Byte> destination, Int32& bytesWritten) {
  Int32 num = FormattingHelpers::CountDigits(value);
  if (num > destination.get_Length()) {
    bytesWritten = 0;
    return false;
  }
  bytesWritten = num;
  FormattingHelpers::WriteDigits(value, destination.Slice(0, num));
  return true;
}

Boolean Utf8Formatter::TryFormatUInt64N(UInt64 value, Byte precision, Span<Byte> destination, Boolean insertNegationSign, Int32& bytesWritten) {
  Int32 num = FormattingHelpers::CountDigits(value);
  Int32 num2 = (num - 1) / 3;
  Int32 num3 = (precision == Byte::MaxValue) ? 2 : precision;
  Int32 num4 = num + num2;
  if (num3 > 0) {
    num4 += num3 + 1;
  }
  if (insertNegationSign) {
    num4++;
  }
  if (num4 > destination.get_Length()) {
    bytesWritten = 0;
    return false;
  }
  bytesWritten = num4;
  if (insertNegationSign) {
    destination[0] = 45;
    destination = destination.Slice(1);
  }
  FormattingHelpers::WriteDigitsWithGroupSeparator(value, destination.Slice(0, num + num2));
  if (num3 > 0) {
    destination[num + num2] = 46;
    FormattingHelpers::FillWithAsciiZeros(destination.Slice(num + num2 + 1, num3));
  }
  return true;
}

Boolean Utf8Formatter::TryFormatUInt64X(UInt64 value, Byte precision, Boolean useLower, Span<Byte> destination, Int32& bytesWritten) {
  Int32 num = FormattingHelpers::CountHexDigits(value);
  Int32 num2 = (precision == Byte::MaxValue) ? num : Math::Max(precision, num);
  if (destination.get_Length() < num2) {
    bytesWritten = 0;
    return false;
  }
  bytesWritten = num2;
  if (useLower) {
    while ((UInt32)(--num2) < (UInt32)destination.get_Length()) {
      destination[num2] = (Byte)HexConverter::ToCharLower((Int32)value);
      value >>= 4;
    }
  } else {
    while ((UInt32)(--num2) < (UInt32)destination.get_Length()) {
      destination[num2] = (Byte)HexConverter::ToCharUpper((Int32)value);
      value >>= 4;
    }
  }
  return true;
}

template <>
Boolean Utf8Formatter::TryFormat(TimeSpan value, Span<Byte> destination, Int32& bytesWritten, StandardFormat format) {
  Char c = FormattingHelpers::GetSymbolOrDefault(format, 'c');
  switch (c.get()) {
    case 'T':
    case 't':
      c = 'c';
      break;
    default:
      return FormattingHelpers::TryFormatThrowFormatException(bytesWritten);
    case 'G':
    case 'c':
    case 'g':
      break;
  }
  Int32 num = 8;
  Int64 ticks = value.get_Ticks();
  UInt32 valueWithoutTrailingZeros;
  UInt64 num2;
  if (ticks < 0) {
    ticks = -ticks;
    if (ticks < 0) {
      valueWithoutTrailingZeros = 4775808u;
      num2 = 922337203685;
      goto IL_0082;
    }
  }
  UInt64 modulo;
  num2 = FormattingHelpers::DivMod((UInt64)Math::Abs(value.get_Ticks()), 10000000, modulo);
  valueWithoutTrailingZeros = (UInt32)modulo;
  goto IL_0082;

IL_0082:
  Int32 num3 = 0;
  switch (c.get()) {
    case 'c':
      if (valueWithoutTrailingZeros != 0) {
        num3 = 7;
      }
      break;
    case 'G':
      num3 = 7;
      break;
    default:
      if (valueWithoutTrailingZeros != 0) {
        num3 = 7 - FormattingHelpers::CountDecimalTrailingZeros(valueWithoutTrailingZeros, valueWithoutTrailingZeros);
      }
      break;
  }
  if (num3 != 0) {
    num += num3 + 1;
  }
  UInt64 num4 = 0;
  UInt64 modulo2 = 0;
  if (num2 != 0) {
    num4 = FormattingHelpers::DivMod(num2, 60, modulo2);
  }
  UInt64 num5 = 0;
  UInt64 modulo3 = 0;
  if (num4 != 0) {
    num5 = FormattingHelpers::DivMod(num4, 60, modulo3);
  }
  UInt32 num6 = 0u;
  UInt32 modulo4 = 0u;
  if (num5 != 0) {
    num6 = FormattingHelpers::DivMod((UInt32)num5, 24u, modulo4);
  }
  Int32 num7 = 2;
  if (modulo4 < 10 && c == 'g') {
    num7--;
    num--;
  }
  Int32 num8 = 0;
  if (num6 == 0) {
    if (c == 'G') {
      num += 2;
      num8 = 1;
    }
  } else {
    num8 = FormattingHelpers::CountDigits(num6);
    num += num8 + 1;
  }
  if (value.get_Ticks() < 0) {
    num++;
  }
  if (destination.get_Length() < num) {
    bytesWritten = 0;
    return false;
  }
  bytesWritten = num;
  Int32 num9 = 0;
  if (value.get_Ticks() < 0) {
    destination[num9++] = 45;
  }
  if (num8 > 0) {
    FormattingHelpers::WriteDigits(num6, destination.Slice(num9, num8));
    num9 += num8;
    destination[num9++] = (Byte)((c == 'c') ? 46 : 58);
  }
  FormattingHelpers::WriteDigits(modulo4, destination.Slice(num9, num7));
  num9 += num7;
  destination[num9++] = 58;
  FormattingHelpers::WriteDigits((UInt32)modulo3, destination.Slice(num9, 2));
  num9 += 2;
  destination[num9++] = 58;
  FormattingHelpers::WriteDigits((UInt32)modulo2, destination.Slice(num9, 2));
  num9 += 2;
  if (num3 > 0) {
    destination[num9++] = 46;
    FormattingHelpers::WriteDigits(valueWithoutTrailingZeros, destination.Slice(num9, num3));
    num9 += num3;
  }
  return true;
}

void Utf8Formatter::cctor() {
  s_dayAbbreviations = rt::newarr<Array<UInt32>>(7);
  s_dayAbbreviationsLowercase = rt::newarr<Array<UInt32>>(7);
  s_monthAbbreviations = rt::newarr<Array<UInt32>>(12);
  s_monthAbbreviationsLowercase = rt::newarr<Array<UInt32>>(12);
}

} // namespace System::Private::CoreLib::System::Buffers::Text::Utf8FormatterNamespace
