#include "StandardFormat-dep.h"

#include <System.Private.CoreLib/System/Buffers/StandardFormat-dep.h>
#include <System.Private.CoreLib/System/FormatException-dep.h>
#include <System.Private.CoreLib/System/Int32-dep.h>
#include <System.Private.CoreLib/System/Math-dep.h>
#include <System.Private.CoreLib/System/MemoryExtensions-dep.h>
#include <System.Private.CoreLib/System/Span-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/ThrowHelper-dep.h>
#include <System.Private.CoreLib/System/UInt32-dep.h>

namespace System::Private::CoreLib::System::Buffers::StandardFormatNamespace {
Char StandardFormat::get_Symbol() {
  return (Char)_format;
}

Byte StandardFormat::get_Precision() {
  return _precision;
}

Boolean StandardFormat::get_HasPrecision() {
  return _precision != Byte::MaxValue;
}

Boolean StandardFormat::get_IsDefault() {
  if (_format == 0) {
    return _precision == 0;
  }
  return false;
}

StandardFormat::StandardFormat(Char symbol, Byte precision) {
  if (precision != Byte::MaxValue && precision > 99) {
    ThrowHelper::ThrowArgumentOutOfRangeException_PrecisionTooLarge();
  }
  if (symbol != (Byte)symbol) {
    ThrowHelper::ThrowArgumentOutOfRangeException_SymbolDoesNotFit();
  }
  _format = (Byte)symbol;
  _precision = precision;
}

StandardFormat StandardFormat::op_Implicit(Char symbol) {
  return StandardFormat(symbol);
}

StandardFormat StandardFormat::Parse(ReadOnlySpan<Char> format) {
  StandardFormat standardFormat;
  ParseHelper(format, standardFormat, true);
  return standardFormat;
}

StandardFormat StandardFormat::Parse(String format) {
  if (format != nullptr) {
    return Parse(MemoryExtensions::AsSpan(format));
  }
  return rt::default__;
}

Boolean StandardFormat::TryParse(ReadOnlySpan<Char> format, StandardFormat& result) {
  return ParseHelper(format, result);
}

Boolean StandardFormat::ParseHelper(ReadOnlySpan<Char> format, StandardFormat& standardFormat, Boolean throws) {
  standardFormat = rt::default__;
  if (format.get_Length() == 0) {
    return true;
  }
  Char symbol = format[0];
  Byte precision;
  if (format.get_Length() == 1) {
    precision = Byte::MaxValue;
  } else {
    UInt32 num = 0u;
    for (Int32 i = 1; i < format.get_Length(); i++) {
      UInt32 num2 = (UInt32)(format[i] - 48);
      if (num2 > 9) {
        if (!throws) {
          return false;
        }
        rt::throw_exception<FormatException>(SR::Format(SR::get_Argument_CannotParsePrecision(), (Byte)(Int32)99));
      }
      num = num * 10 + num2;
      if (num > 99) {
        if (!throws) {
          return false;
        }
        rt::throw_exception<FormatException>(SR::Format(SR::get_Argument_PrecisionTooLarge(), (Byte)(Int32)99));
      }
    }
    precision = (Byte)num;
  }
  standardFormat = StandardFormat(symbol, precision);
  return true;
}

Boolean StandardFormat::Equals(Object obj) {
  if (rt::is<StandardFormat>(obj)) {
    StandardFormat other = (StandardFormat)obj;
    return Equals(other);
  }
  return false;
}

Int32 StandardFormat::GetHashCode() {
  return _format.GetHashCode() ^ _precision.GetHashCode();
}

Boolean StandardFormat::Equals(StandardFormat other) {
  if (_format == other._format) {
    return _precision == other._precision;
  }
  return false;
}

String StandardFormat::ToString() {
  Char as[3] = {};
  Span<Char> destination = as;
  Int32 length = Format(destination);
  return rt::newstr<String>(destination.Slice(0, length));
}

Int32 StandardFormat::Format(Span<Char> destination) {
  Int32 num = 0;
  Char symbol = get_Symbol();
  if (symbol != 0 && destination.get_Length() == 3) {
    destination[0] = symbol;
    num = 1;
    UInt32 result = get_Precision();
    if (result != 255) {
      if (result >= 10) {
        UInt32 num2 = Math::DivRem(result, 10u, result);
        destination[1] = (Char)(48 + num2 % 10u);
        num = 2;
      }
      destination[num] = (Char)(48 + result);
      num++;
    }
  }
  return num;
}

Boolean StandardFormat::op_Equality(StandardFormat left, StandardFormat right) {
  return left.Equals(right);
}

Boolean StandardFormat::op_Inequality(StandardFormat left, StandardFormat right) {
  return !left.Equals(right);
}

} // namespace System::Private::CoreLib::System::Buffers::StandardFormatNamespace
