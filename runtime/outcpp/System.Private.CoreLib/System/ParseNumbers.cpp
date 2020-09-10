#include "ParseNumbers-dep.h"

#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/Boolean-dep.h>
#include <System.Private.CoreLib/System/FormatException-dep.h>
#include <System.Private.CoreLib/System/Math-dep.h>
#include <System.Private.CoreLib/System/Number-dep.h>
#include <System.Private.CoreLib/System/OverflowException-dep.h>
#include <System.Private.CoreLib/System/Span-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/TypeCode.h>
#include <System.Private.CoreLib/System/UInt32-dep.h>
#include <System.Private.CoreLib/System/UInt64-dep.h>

namespace System::Private::CoreLib::System::ParseNumbersNamespace {
Int64 ParseNumbers::StringToLong(ReadOnlySpan<Char> s, Int32 radix, Int32 flags) {
  Int32 currPos = 0;
  return StringToLong(s, radix, flags, currPos);
}

Int64 ParseNumbers::StringToLong(ReadOnlySpan<Char> s, Int32 radix, Int32 flags, Int32& currPos) {
  Int32 i = currPos;
  Int32 num = (-1 == radix) ? 10 : radix;
  if (num != 2 && num != 10 && num != 8 && num != 16) {
    rt::throw_exception<ArgumentException>(SR::get_Arg_InvalidBase(), "radix");
  }
  Int32 length = s.get_Length();
  if (i < 0 || i >= length) {
    rt::throw_exception<ArgumentOutOfRangeException>(SR::get_ArgumentOutOfRange_Index());
  }
  if ((flags & 4096) == 0 && (flags & 8192) == 0) {
    EatWhiteSpace(s, i);
    if (i == length) {
      rt::throw_exception<FormatException>(SR::get_Format_EmptyInputString());
    }
  }
  Int32 num2 = 1;
  if (s[i] == '-') {
    if (num != 10) {
      rt::throw_exception<ArgumentException>(SR::get_Arg_CannotHaveNegativeValue());
    }
    if ((flags & 512) != 0) {
      rt::throw_exception<OverflowException>(SR::get_Overflow_NegativeUnsigned());
    }
    num2 = -1;
    i++;
  } else if (s[i] == '+') {
    i++;
  }

  if ((radix == -1 || radix == 16) && i + 1 < length && s[i] == '0' && (s[i + 1] == 'x' || s[i + 1] == 'X')) {
    num = 16;
    i += 2;
  }
  Int32 num3 = i;
  Int64 num4 = GrabLongs(num, s, i, (flags & 512) != 0);
  if (i == num3) {
    rt::throw_exception<FormatException>(SR::get_Format_NoParsibleDigits());
  }
  if ((flags & 4096) != 0 && i < length) {
    rt::throw_exception<FormatException>(SR::get_Format_ExtraJunkAtEnd());
  }
  currPos = i;
  if (num4 == Int64::MinValue && num2 == 1 && num == 10 && (flags & 512) == 0) {
    Number::ThrowOverflowException(TypeCode::Int64);
  }
  if (num == 10) {
    num4 *= num2;
  }
  return num4;
}

Int32 ParseNumbers::StringToInt(ReadOnlySpan<Char> s, Int32 radix, Int32 flags) {
  Int32 currPos = 0;
  return StringToInt(s, radix, flags, currPos);
}

Int32 ParseNumbers::StringToInt(ReadOnlySpan<Char> s, Int32 radix, Int32 flags, Int32& currPos) {
  Int32 i = currPos;
  Int32 num = (-1 == radix) ? 10 : radix;
  if (num != 2 && num != 10 && num != 8 && num != 16) {
    rt::throw_exception<ArgumentException>(SR::get_Arg_InvalidBase(), "radix");
  }
  Int32 length = s.get_Length();
  if (i < 0 || i >= length) {
    rt::throw_exception<ArgumentOutOfRangeException>(SR::get_ArgumentOutOfRange_Index());
  }
  if ((flags & 4096) == 0 && (flags & 8192) == 0) {
    EatWhiteSpace(s, i);
    if (i == length) {
      rt::throw_exception<FormatException>(SR::get_Format_EmptyInputString());
    }
  }
  Int32 num2 = 1;
  if (s[i] == '-') {
    if (num != 10) {
      rt::throw_exception<ArgumentException>(SR::get_Arg_CannotHaveNegativeValue());
    }
    if ((flags & 512) != 0) {
      rt::throw_exception<OverflowException>(SR::get_Overflow_NegativeUnsigned());
    }
    num2 = -1;
    i++;
  } else if (s[i] == '+') {
    i++;
  }

  if ((radix == -1 || radix == 16) && i + 1 < length && s[i] == '0' && (s[i + 1] == 'x' || s[i + 1] == 'X')) {
    num = 16;
    i += 2;
  }
  Int32 num3 = i;
  Int32 num4 = GrabInts(num, s, i, (flags & 512) != 0);
  if (i == num3) {
    rt::throw_exception<FormatException>(SR::get_Format_NoParsibleDigits());
  }
  if ((flags & 4096) != 0 && i < length) {
    rt::throw_exception<FormatException>(SR::get_Format_ExtraJunkAtEnd());
  }
  currPos = i;
  if ((flags & 1024) != 0) {
    if ((UInt32)num4 > 255u) {
      Number::ThrowOverflowException(TypeCode::SByte);
    }
  } else if ((flags & 2048) != 0) {
    if ((UInt32)num4 > 65535u) {
      Number::ThrowOverflowException(TypeCode::Int16);
    }
  } else if (num4 == Int32::MinValue && num2 == 1 && num == 10 && (flags & 512) == 0) {
    Number::ThrowOverflowException(TypeCode::Int32);
  }


  if (num == 10) {
    num4 *= num2;
  }
  return num4;
}

String ParseNumbers::IntToString(Int32 n, Int32 radix, Int32 width, Char paddingChar, Int32 flags) {
  Char as[66] = {};
  Span<Char> span = as;
  if (radix < 2 || radix > 36) {
    rt::throw_exception<ArgumentException>(SR::get_Arg_InvalidBase(), "radix");
  }
  Boolean flag = false;
  UInt32 num;
  if (n < 0) {
    flag = true;
    num = (UInt32)((10 == radix) ? (-n) : n);
  } else {
    num = (UInt32)n;
  }
  if ((flags & 64) != 0) {
    num &= 255;
  } else if ((flags & 128) != 0) {
    num &= 65535;
  }

  Int32 num2;
  if (num == 0) {
    span[0] = '0';
    num2 = 1;
  } else {
    num2 = 0;
    for (Int32 i = 0; i < span.get_Length(); i++) {
      UInt32 num3 = num / (UInt32)radix;
      UInt32 num4 = num - (UInt32)((Int32)num3 * radix);
      num = num3;
      span[i] = ((num4 < 10) ? ((Char)(num4 + 48)) : ((Char)(num4 + 97 - 10)));
      if (num == 0) {
        num2 = i + 1;
        break;
      }
    }
  }
  if (radix != 10 && (flags & 32) != 0) {
    if (16 == radix) {
      span[num2++] = 'x';
      span[num2++] = '0';
    } else if (8 == radix) {
      span[num2++] = '0';
    }

  }
  if (10 == radix) {
    if (flag) {
      span[num2++] = '-';
    } else if ((flags & 16) != 0) {
      span[num2++] = '+';
    } else if ((flags & 8) != 0) {
      span[num2++] = ' ';
    }


  }
  String text = String::in::FastAllocateString(Math::Max(width, num2));
  {
    Char* ptr = text;
    Char* ptr2 = ptr;
    Char* ptr3 = ptr2;
    Int32 num5 = text->get_Length() - num2;
    if ((flags & 1) != 0) {
      for (Int32 j = 0; j < num5; j++) {
        Char* intPtr = ptr3;
        ptr3 = intPtr + 1;
        *intPtr = paddingChar;
      }
      for (Int32 k = 0; k < num2; k++) {
        Char* intPtr2 = ptr3;
        ptr3 = intPtr2 + 1;
        *intPtr2 = span[num2 - k - 1];
      }
    } else {
      for (Int32 l = 0; l < num2; l++) {
        Char* intPtr3 = ptr3;
        ptr3 = intPtr3 + 1;
        *intPtr3 = span[num2 - l - 1];
      }
      for (Int32 m = 0; m < num5; m++) {
        Char* intPtr4 = ptr3;
        ptr3 = intPtr4 + 1;
        *intPtr4 = paddingChar;
      }
    }
  }
  return text;
}

String ParseNumbers::LongToString(Int64 n, Int32 radix, Int32 width, Char paddingChar, Int32 flags) {
  Char as[67] = {};
  Span<Char> span = as;
  if (radix < 2 || radix > 36) {
    rt::throw_exception<ArgumentException>(SR::get_Arg_InvalidBase(), "radix");
  }
  Boolean flag = false;
  UInt64 num;
  if (n < 0) {
    flag = true;
    num = (UInt64)((10 == radix) ? (-n) : n);
  } else {
    num = (UInt64)n;
  }
  if ((flags & 64) != 0) {
    num &= 255;
  } else if ((flags & 128) != 0) {
    num &= 65535;
  } else if ((flags & 256) != 0) {
    num &= UInt32::MaxValue;
  }


  Int32 num2;
  if (num == 0) {
    span[0] = '0';
    num2 = 1;
  } else {
    num2 = 0;
    for (Int32 i = 0; i < span.get_Length(); i++) {
      UInt64 num3 = num / (UInt64)radix;
      Int32 num4 = (Int32)((Int64)num - (Int64)num3 * (Int64)radix);
      num = num3;
      span[i] = ((num4 < 10) ? ((Char)(num4 + 48)) : ((Char)(num4 + 97 - 10)));
      if (num == 0) {
        num2 = i + 1;
        break;
      }
    }
  }
  if (radix != 10 && (flags & 32) != 0) {
    if (16 == radix) {
      span[num2++] = 'x';
      span[num2++] = '0';
    } else if (8 == radix) {
      span[num2++] = '0';
    } else if ((flags & 16384) != 0) {
      span[num2++] = '#';
      span[num2++] = (Char)(radix % 10 + 48);
      span[num2++] = (Char)(radix / 10 + 48);
    }


  }
  if (10 == radix) {
    if (flag) {
      span[num2++] = '-';
    } else if ((flags & 16) != 0) {
      span[num2++] = '+';
    } else if ((flags & 8) != 0) {
      span[num2++] = ' ';
    }


  }
  String text = String::in::FastAllocateString(Math::Max(width, num2));
  {
    Char* ptr = text;
    Char* ptr2 = ptr;
    Char* ptr3 = ptr2;
    Int32 num5 = text->get_Length() - num2;
    if ((flags & 1) != 0) {
      for (Int32 j = 0; j < num5; j++) {
        Char* intPtr = ptr3;
        ptr3 = intPtr + 1;
        *intPtr = paddingChar;
      }
      for (Int32 k = 0; k < num2; k++) {
        Char* intPtr2 = ptr3;
        ptr3 = intPtr2 + 1;
        *intPtr2 = span[num2 - k - 1];
      }
    } else {
      for (Int32 l = 0; l < num2; l++) {
        Char* intPtr3 = ptr3;
        ptr3 = intPtr3 + 1;
        *intPtr3 = span[num2 - l - 1];
      }
      for (Int32 m = 0; m < num5; m++) {
        Char* intPtr4 = ptr3;
        ptr3 = intPtr4 + 1;
        *intPtr4 = paddingChar;
      }
    }
  }
  return text;
}

void ParseNumbers::EatWhiteSpace(ReadOnlySpan<Char> s, Int32& i) {
  Int32 j;
  for (j = i; j < s.get_Length() && Char::IsWhiteSpace(s[j]); j++) {
  }
  i = j;
}

Int64 ParseNumbers::GrabLongs(Int32 radix, ReadOnlySpan<Char> s, Int32& i, Boolean isUnsigned) {
  UInt64 num = 0;
  if (radix == 10 && !isUnsigned) {
    UInt64 num2 = 922337203685477580;
    Int32 result;
    while (i < s.get_Length() && IsDigit(s[i], radix, result)) {
      if (num > num2 || (Int64)num < 0) {
        Number::ThrowOverflowException(TypeCode::Int64);
      }
      num = (UInt64)((Int64)num * (Int64)radix + result);
      i++;
    }
    if ((Int64)num < 0 && num != 9223372036854775808) {
      Number::ThrowOverflowException(TypeCode::Int64);
    }
  } else {
    Int64 num3;
    switch (radix.get()) {
      default:
        num3 = Int64::MaxValue;
        break;
      case 8:
        num3 = 2305843009213693951;
        break;
      case 16:
        num3 = 1152921504606846975;
        break;
      case 10:
        num3 = 1844674407370955161;
        break;
    }
    UInt64 num2 = (UInt64)num3;
    Int32 result2;
    while (i < s.get_Length() && IsDigit(s[i], radix, result2)) {
      if (num > num2) {
        Number::ThrowOverflowException(TypeCode::UInt64);
      }
      UInt64 num4 = (UInt64)((Int64)num * (Int64)radix + result2);
      if (num4 < num) {
        Number::ThrowOverflowException(TypeCode::UInt64);
      }
      num = num4;
      i++;
    }
  }
  return (Int64)num;
}

Int32 ParseNumbers::GrabInts(Int32 radix, ReadOnlySpan<Char> s, Int32& i, Boolean isUnsigned) {
  UInt32 num = 0u;
  if (radix == 10 && !isUnsigned) {
    UInt32 num2 = 214748364u;
    Int32 result;
    while (i < s.get_Length() && IsDigit(s[i], radix, result)) {
      if (num > num2 || (Int32)num < 0) {
        Number::ThrowOverflowException(TypeCode::Int32);
      }
      num = (UInt32)((Int32)num * radix + result);
      i++;
    }
    if ((Int32)num < 0 && num != 2147483648u) {
      Number::ThrowOverflowException(TypeCode::Int32);
    }
  } else {
    Int32 num3;
    switch (radix.get()) {
      default:
        num3 = Int32::MaxValue;
        break;
      case 8:
        num3 = 536870911;
        break;
      case 16:
        num3 = 268435455;
        break;
      case 10:
        num3 = 429496729;
        break;
    }
    UInt32 num2 = (UInt32)num3;
    Int32 result2;
    while (i < s.get_Length() && IsDigit(s[i], radix, result2)) {
      if (num > num2) {
        Number::ThrowOverflowException(TypeCode::UInt32);
      }
      UInt32 num4 = (UInt32)((Int32)num * radix + result2);
      if (num4 < num) {
        Number::ThrowOverflowException(TypeCode::UInt32);
      }
      num = num4;
      i++;
    }
  }
  return (Int32)num;
}

Boolean ParseNumbers::IsDigit(Char c, Int32 radix, Int32& result) {
  Int32 num;
  switch (c.get()) {
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
      num = (result = c - 48);
      break;
    case 'A':
    case 'B':
    case 'C':
    case 'D':
    case 'E':
    case 'F':
    case 'G':
    case 'H':
    case 'I':
    case 'J':
    case 'K':
    case 'L':
    case 'M':
    case 'N':
    case 'O':
    case 'P':
    case 'Q':
    case 'R':
    case 'S':
    case 'T':
    case 'U':
    case 'V':
    case 'W':
    case 'X':
    case 'Y':
    case 'Z':
      num = (result = c - 65 + 10);
      break;
    case 'a':
    case 'b':
    case 'c':
    case 'd':
    case 'e':
    case 'f':
    case 'g':
    case 'h':
    case 'i':
    case 'j':
    case 'k':
    case 'l':
    case 'm':
    case 'n':
    case 'o':
    case 'p':
    case 'q':
    case 'r':
    case 's':
    case 't':
    case 'u':
    case 'v':
    case 'w':
    case 'x':
    case 'y':
    case 'z':
      num = (result = c - 97 + 10);
      break;
    default:
      result = -1;
      return false;
  }
  return num < radix;
}

} // namespace System::Private::CoreLib::System::ParseNumbersNamespace
