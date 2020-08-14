#include "FormattingHelpers-dep.h"

#include <System.Private.CoreLib/System/Numerics/BitOperations-dep.h>
#include <System.Private.CoreLib/System/ThrowHelper-dep.h>
#include <System.Private.CoreLib/System/UInt32-dep.h>

namespace System::Private::CoreLib::System::Buffers::Text::FormattingHelpersNamespace {
using namespace System::Numerics;

Int32 FormattingHelpers::CountDigits(UInt64 value) {
  Int32 num = 1;
  UInt32 num2;
  if (value >= 10000000) {
    if (value >= 100000000000000) {
      num2 = (UInt32)(value / 100000000000000);
      num += 14;
    } else {
      num2 = (UInt32)(value / 10000000);
      num += 7;
    }
  } else {
    num2 = (UInt32)value;
  }
  if (num2 >= 10) {
    num = ((num2 < 100) ? (num + 1) : ((num2 < 1000) ? (num + 2) : ((num2 < 10000) ? (num + 3) : ((num2 < 100000) ? (num + 4) : ((num2 >= 1000000) ? (num + 6) : (num + 5))))));
  }
  return num;
}

Int32 FormattingHelpers::CountDigits(UInt32 value) {
  Int32 num = 1;
  if (value >= 100000) {
    value /= 100000u;
    num += 5;
  }
  if (value >= 10) {
    num = ((value < 100) ? (num + 1) : ((value < 1000) ? (num + 2) : ((value >= 10000) ? (num + 4) : (num + 3))));
  }
  return num;
}

Int32 FormattingHelpers::CountHexDigits(UInt64 value) {
  return (BitOperations::Log2(value) >> 2) + 1;
}

Int32 FormattingHelpers::CountDecimalTrailingZeros(UInt32 value, UInt32& valueWithoutTrailingZeros) {
  Int32 num = 0;
  if (value != 0) {
    while (true) {
      UInt32 num2 = value / 10u;
      if (value != num2 * 10) {
        break;
      }
      value = num2;
      num++;
    }
  }
  valueWithoutTrailingZeros = value;
  return num;
}

Char FormattingHelpers::GetSymbolOrDefault(StandardFormat& format, Char defaultSymbol) {
  Char c = format.get_Symbol();
  if (c == 0 && format.get_Precision() == 0) {
    c = defaultSymbol;
  }
  return c;
}

void FormattingHelpers::FillWithAsciiZeros(Span<Byte> buffer) {
  for (Int32 i = 0; i < buffer.get_Length(); i++) {
    buffer[i] = 48;
  }
}

void FormattingHelpers::WriteDigits(UInt64 value, Span<Byte> buffer) {
  for (Int32 num = buffer.get_Length() - 1; num >= 1; num--) {
    UInt64 num2 = 48 + value;
    value /= 10;
    buffer[num] = (Byte)(num2 - value * 10);
  }
  buffer[0] = (Byte)(48 + value);
}

void FormattingHelpers::WriteDigitsWithGroupSeparator(UInt64 value, Span<Byte> buffer) {
  Int32 num = 0;
  for (Int32 num2 = buffer.get_Length() - 1; num2 >= 1; num2--) {
    UInt64 num3 = 48 + value;
    value /= 10;
    buffer[num2] = (Byte)(num3 - value * 10);
    if (num == 2) {
      buffer[--num2] = 44;
      num = 0;
    } else {
      num++;
    }
  }
  buffer[0] = (Byte)(48 + value);
}

void FormattingHelpers::WriteDigits(UInt32 value, Span<Byte> buffer) {
  for (Int32 num = buffer.get_Length() - 1; num >= 1; num--) {
    UInt32 num2 = 48 + value;
    value /= 10u;
    buffer[num] = (Byte)(num2 - value * 10);
  }
  buffer[0] = (Byte)(48 + value);
}

void FormattingHelpers::WriteFourDecimalDigits(UInt32 value, Span<Byte> buffer, Int32 startingIndex) {
  UInt32 num = 48 + value;
  value /= 10u;
  buffer[startingIndex + 3] = (Byte)(num - value * 10);
  num = 48 + value;
  value /= 10u;
  buffer[startingIndex + 2] = (Byte)(num - value * 10);
  num = 48 + value;
  value /= 10u;
  buffer[startingIndex + 1] = (Byte)(num - value * 10);
  buffer[startingIndex] = (Byte)(48 + value);
}

void FormattingHelpers::WriteTwoDecimalDigits(UInt32 value, Span<Byte> buffer, Int32 startingIndex) {
  UInt32 num = 48 + value;
  value /= 10u;
  buffer[startingIndex + 1] = (Byte)(num - value * 10);
  buffer[startingIndex] = (Byte)(48 + value);
}

UInt64 FormattingHelpers::DivMod(UInt64 numerator, UInt64 denominator, UInt64& modulo) {
  UInt64 num = numerator / denominator;
  modulo = numerator - num * denominator;
  return num;
}

UInt32 FormattingHelpers::DivMod(UInt32 numerator, UInt32 denominator, UInt32& modulo) {
  UInt32 num = numerator / denominator;
  modulo = numerator - num * denominator;
  return num;
}

Boolean FormattingHelpers::TryFormatThrowFormatException(Int32& bytesWritten) {
  bytesWritten = 0;
  ThrowHelper::ThrowFormatException_BadFormatSpecifier();
  return false;
}

} // namespace System::Private::CoreLib::System::Buffers::Text::FormattingHelpersNamespace
