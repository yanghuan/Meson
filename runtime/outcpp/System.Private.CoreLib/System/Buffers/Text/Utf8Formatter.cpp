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

Boolean Utf8Formatter::TryFormat(Boolean value, Span<Byte> destination, Int32& bytesWritten, StandardFormat format) {
  Char symbolOrDefault = FormattingHelpers::GetSymbolOrDefault(format, 71);
  if (value) {
    if (symbolOrDefault == 71) {
      if (BinaryPrimitives::TryWriteUInt32BigEndian(destination, 1416787301u)) {
      }
    } else {
      if (symbolOrDefault != 108) {
      }
      if (BinaryPrimitives::TryWriteUInt32BigEndian(destination, 1953658213u)) {
      }
    }
  } else if (symbolOrDefault == 71) {
    if (4u < (UInt32)destination.get_Length()) {
      BinaryPrimitives::WriteUInt32BigEndian(destination, 1180789875u);
    }
  } else {
    if (symbolOrDefault != 108) {
    }
    if (4u < (UInt32)destination.get_Length()) {
      BinaryPrimitives::WriteUInt32BigEndian(destination, 1717660787u);
    }
  }

  bytesWritten = 0;
  return false;
}

Boolean Utf8Formatter::TryFormat(DateTimeOffset value, Span<Byte> destination, Int32& bytesWritten, StandardFormat format) {
  TimeSpan offset = Utf8Constants::NullUtcOffset;
  Char c = format.get_Symbol();
  if (format.get_IsDefault()) {
    c = 71;
    offset = value.get_Offset();
  }
  switch (c.get()) {
    case 82:
      return TryFormatDateTimeR(value.get_UtcDateTime(), destination, bytesWritten);
    case 108:
      return TryFormatDateTimeL(value.get_UtcDateTime(), destination, bytesWritten);
    case 79:
      return TryFormatDateTimeO(value.get_DateTime(), value.get_Offset(), destination, bytesWritten);
    case 71:
      return TryFormatDateTimeG(value.get_DateTime(), offset, destination, bytesWritten);
    default:
      return FormattingHelpers::TryFormatThrowFormatException(bytesWritten);
  }
}

Boolean Utf8Formatter::TryFormat(DateTime value, Span<Byte> destination, Int32& bytesWritten, StandardFormat format) {
  switch (FormattingHelpers::GetSymbolOrDefault(format, 71).get()) {
    case 82:
      return TryFormatDateTimeR(value, destination, bytesWritten);
    case 108:
      return TryFormatDateTimeL(value, destination, bytesWritten);
    case 79:
      return TryFormatDateTimeO(value, Utf8Constants::NullUtcOffset, destination, bytesWritten);
    case 71:
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
}

Boolean Utf8Formatter::TryFormatDateTimeL(DateTime value, Span<Byte> destination, Int32& bytesWritten) {
  if (28u >= (UInt32)destination.get_Length()) {
    bytesWritten = 0;
    return false;
  }
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
  _ = destination[26];
}

Boolean Utf8Formatter::TryFormatDateTimeR(DateTime value, Span<Byte> destination, Int32& bytesWritten) {
  if (28u >= (UInt32)destination.get_Length()) {
    bytesWritten = 0;
    return false;
  }
}

Boolean Utf8Formatter::TryFormat(Decimal value, Span<Byte> destination, Int32& bytesWritten, StandardFormat format) {
  if (format.get_IsDefault()) {
    format = 71;
  }
  switch (format.get_Symbol().get()) {
    case 71:
    case 103:
      {
        if (format.get_Precision() != Byte::MaxValue) {
          rt::throw_exception<NotSupportedException>(SR::get_Argument_GWithPrecisionNotSupported());
        }
        Byte default[31] = {};
        Byte* digits3 = default;
        Number::NumberBuffer number3 = Number::NumberBuffer(Number::NumberBufferKind::Decimal, digits3, 31);
        Number::DecimalToNumber(value, number3);
        if (number3.Digits[0] == 0) {
          number3.IsNegative = false;
        }
        return TryFormatDecimalG(number3, destination, bytesWritten);
      }case 70:
    case 102:
      {
        Byte default[31] = {};
        Byte* digits2 = default;
        Number::NumberBuffer number2 = Number::NumberBuffer(Number::NumberBufferKind::Decimal, digits2, 31);
        Number::DecimalToNumber(value, number2);
        Byte b2 = (Byte)((format.get_Precision() == Byte::MaxValue) ? 2 : format.get_Precision());
        Number::RoundNumber(number2, number2.Scale + b2, false);
        return TryFormatDecimalF(number2, destination, bytesWritten, b2);
      }case 69:
    case 101:
      {
        Byte default[31] = {};
        Byte* digits = default;
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
    }
    Byte b2;
    while ((b2 = readOnlySpan[i++]) != 0) {
      destination[num2++] = b2;
    }
  }
  bytesWritten = num;
  return true;
}

Boolean Utf8Formatter::TryFormat(Double value, Span<Byte> destination, Int32& bytesWritten, StandardFormat format) {
  return TryFormatFloatingPoint(value, destination, bytesWritten, format);
}

Boolean Utf8Formatter::TryFormat(Single value, Span<Byte> destination, Int32& bytesWritten, StandardFormat format) {
  return TryFormatFloatingPoint(value, destination, bytesWritten, format);
}

Boolean Utf8Formatter::TryFormat(Guid value, Span<Byte> destination, Int32& bytesWritten, StandardFormat format) {
  Int32 num;
  switch (FormattingHelpers::GetSymbolOrDefault(format, 68).get()) {
    case 68:
      num = -2147483612;
      break;
    case 66:
      num = -2139260122;
      break;
    case 80:
      num = -2144786394;
      break;
    case 78:
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
  DecomposedGuid decomposedGuid = DecomposedGuid();
  decomposedGuid.Guid = value;
  _ = destination[8];
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
  _ = destination[4];
  HexConverter::ToBytesBuffer(decomposedGuid.Byte05, destination, 0, HexConverter::Casing::Lower);
  HexConverter::ToBytesBuffer(decomposedGuid.Byte04, destination, 2, HexConverter::Casing::Lower);
  if (num < 0) {
    destination[4] = 45;
    destination = destination.Slice(5);
  } else {
    destination = destination.Slice(4);
  }
  _ = destination[4];
  HexConverter::ToBytesBuffer(decomposedGuid.Byte07, destination, 0, HexConverter::Casing::Lower);
  HexConverter::ToBytesBuffer(decomposedGuid.Byte06, destination, 2, HexConverter::Casing::Lower);
  if (num < 0) {
    destination[4] = 45;
    destination = destination.Slice(5);
  } else {
    destination = destination.Slice(4);
  }
  _ = destination[4];
  HexConverter::ToBytesBuffer(decomposedGuid.Byte08, destination, 0, HexConverter::Casing::Lower);
  HexConverter::ToBytesBuffer(decomposedGuid.Byte09, destination, 2, HexConverter::Casing::Lower);
  if (num < 0) {
    destination[4] = 45;
    destination = destination.Slice(5);
  } else {
    destination = destination.Slice(4);
  }
  _ = destination[11];
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

Boolean Utf8Formatter::TryFormat(Byte value, Span<Byte> destination, Int32& bytesWritten, StandardFormat format) {
  return TryFormatUInt64(value, destination, bytesWritten, format);
}

Boolean Utf8Formatter::TryFormat(SByte value, Span<Byte> destination, Int32& bytesWritten, StandardFormat format) {
  return TryFormatInt64(value, 255, destination, bytesWritten, format);
}

Boolean Utf8Formatter::TryFormat(UInt16 value, Span<Byte> destination, Int32& bytesWritten, StandardFormat format) {
  return TryFormatUInt64(value, destination, bytesWritten, format);
}

Boolean Utf8Formatter::TryFormat(Int16 value, Span<Byte> destination, Int32& bytesWritten, StandardFormat format) {
  return TryFormatInt64(value, 65535, destination, bytesWritten, format);
}

Boolean Utf8Formatter::TryFormat(UInt32 value, Span<Byte> destination, Int32& bytesWritten, StandardFormat format) {
  return TryFormatUInt64(value, destination, bytesWritten, format);
}

Boolean Utf8Formatter::TryFormat(Int32 value, Span<Byte> destination, Int32& bytesWritten, StandardFormat format) {
  return TryFormatInt64(value, 4294967295, destination, bytesWritten, format);
}

Boolean Utf8Formatter::TryFormat(UInt64 value, Span<Byte> destination, Int32& bytesWritten, StandardFormat format) {
  return TryFormatUInt64(value, destination, bytesWritten, format);
}

Boolean Utf8Formatter::TryFormat(Int64 value, Span<Byte> destination, Int32& bytesWritten, StandardFormat format) {
  return TryFormatInt64(value, UInt64::MaxValue, destination, bytesWritten, format);
}

Boolean Utf8Formatter::TryFormatInt64(Int64 value, UInt64 mask, Span<Byte> destination, Int32& bytesWritten, StandardFormat format) {
  if (format.get_IsDefault()) {
    return TryFormatInt64Default(value, destination, bytesWritten);
  }
}

Boolean Utf8Formatter::TryFormatInt64D(Int64 value, Byte precision, Span<Byte> destination, Int32& bytesWritten) {
  Boolean insertNegationSign = false;
  if (value < 0) {
    insertNegationSign = true;
  }
  return TryFormatUInt64D((UInt64)value, precision, destination, insertNegationSign, bytesWritten);
}

Boolean Utf8Formatter::TryFormatInt64Default(Int64 value, Span<Byte> destination, Int32& bytesWritten) {
  if ((UInt64)value < 10) {
    return TryFormatUInt32SingleDigit((UInt32)value, destination, bytesWritten);
  }
  _ = IntPtr::get_Size();
  return TryFormatInt64MultipleDigits(value, destination, bytesWritten);
}

Boolean Utf8Formatter::TryFormatInt64MultipleDigits(Int64 value, Span<Byte> destination, Int32& bytesWritten) {
  if (value < 0) {
  }
  return TryFormatUInt64MultipleDigits((UInt64)value, destination, bytesWritten);
}

Boolean Utf8Formatter::TryFormatInt64N(Int64 value, Byte precision, Span<Byte> destination, Int32& bytesWritten) {
  Boolean insertNegationSign = false;
  if (value < 0) {
    insertNegationSign = true;
  }
  return TryFormatUInt64N((UInt64)value, precision, destination, insertNegationSign, bytesWritten);
}

Boolean Utf8Formatter::TryFormatUInt64(UInt64 value, Span<Byte> destination, Int32& bytesWritten, StandardFormat format) {
  if (format.get_IsDefault()) {
    return TryFormatUInt64Default(value, destination, bytesWritten);
  }
  switch (format.get_Symbol().get()) {
    case 71:
    case 103:
      if (format.get_HasPrecision()) {
        rt::throw_exception<NotSupportedException>(SR::get_Argument_GWithPrecisionNotSupported());
      }
      return TryFormatUInt64D(value, format.get_Precision(), destination, false, bytesWritten);
    case 68:
    case 100:
      return TryFormatUInt64D(value, format.get_Precision(), destination, false, bytesWritten);
    case 78:
    case 110:
      return TryFormatUInt64N(value, format.get_Precision(), destination, false, bytesWritten);
    case 120:
      return TryFormatUInt64X(value, format.get_Precision(), true, destination, bytesWritten);
    case 88:
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
  _ = IntPtr::get_Size();
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

Boolean Utf8Formatter::TryFormat(TimeSpan value, Span<Byte> destination, Int32& bytesWritten, StandardFormat format) {
  Char c = FormattingHelpers::GetSymbolOrDefault(format, 99);
  switch (c.get()) {
    case 84:
    case 116:
      c = 99;
      break;
    default:
      return FormattingHelpers::TryFormatThrowFormatException(bytesWritten);
    case 71:
    case 99:
    case 103:
      break;
  }
  Int32 num = 8;
  Int64 ticks = value.get_Ticks();
  UInt32 valueWithoutTrailingZeros;
  UInt64 num2;
  if (ticks < 0) {
  }
}

void Utf8Formatter::cctor() {
  s_dayAbbreviations = rt::newarr<Array<UInt32>>(7);
  s_dayAbbreviationsLowercase = rt::newarr<Array<UInt32>>(7);
  s_monthAbbreviations = rt::newarr<Array<UInt32>>(12);
  s_monthAbbreviationsLowercase = rt::newarr<Array<UInt32>>(12);
}

} // namespace System::Private::CoreLib::System::Buffers::Text::Utf8FormatterNamespace
