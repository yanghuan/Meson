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
  if (s[i] == 45) {
    if (num != 10) {
      rt::throw_exception<ArgumentException>(SR::get_Arg_CannotHaveNegativeValue());
    }
    if ((flags & 512) != 0) {
      rt::throw_exception<OverflowException>(SR::get_Overflow_NegativeUnsigned());
    }
    num2 = -1;
    i++;
  } else if (s[i] == 43) {
    i++;
  }

  if ((radix == -1 || radix == 16) && i + 1 < length && s[i] == 48 && (s[i + 1] == 120 || s[i + 1] == 88)) {
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
  if (s[i] == 45) {
    if (num != 10) {
      rt::throw_exception<ArgumentException>(SR::get_Arg_CannotHaveNegativeValue());
    }
    if ((flags & 512) != 0) {
      rt::throw_exception<OverflowException>(SR::get_Overflow_NegativeUnsigned());
    }
    num2 = -1;
    i++;
  } else if (s[i] == 43) {
    i++;
  }

  if ((radix == -1 || radix == 16) && i + 1 < length && s[i] == 48 && (s[i + 1] == 120 || s[i + 1] == 88)) {
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
  Char default[66] = {};
  Span<Char> span = default;
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
    span[0] = 48;
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
      span[num2++] = 120;
      span[num2++] = 48;
    } else if (8 == radix) {
      span[num2++] = 48;
    }

  }
  if (10 == radix) {
    if (flag) {
      span[num2++] = 45;
    } else if ((flags & 16) != 0) {
      span[num2++] = 43;
    } else if ((flags & 8) != 0) {
      span[num2++] = 32;
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
        Char* num6 = ptr3;
        ptr3 = num6 + 1;
        *num6 = paddingChar;
      }
      for (Int32 k = 0; k < num2; k++) {
        Char* num7 = ptr3;
        ptr3 = num7 + 1;
        *num7 = span[num2 - k - 1];
      }
    } else {
      for (Int32 l = 0; l < num2; l++) {
        Char* num8 = ptr3;
        ptr3 = num8 + 1;
        *num8 = span[num2 - l - 1];
      }
      for (Int32 m = 0; m < num5; m++) {
        Char* num9 = ptr3;
        ptr3 = num9 + 1;
        *num9 = paddingChar;
      }
    }
  }
  return text;
}

String ParseNumbers::LongToString(Int64 n, Int32 radix, Int32 width, Char paddingChar, Int32 flags) {
  Char default[67] = {};
  Span<Char> span = default;
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
    span[0] = 48;
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
      span[num2++] = 120;
      span[num2++] = 48;
    } else if (8 == radix) {
      span[num2++] = 48;
    } else if ((flags & 16384) != 0) {
      span[num2++] = 35;
      span[num2++] = (Char)(radix % 10 + 48);
      span[num2++] = (Char)(radix / 10 + 48);
    }


  }
  if (10 == radix) {
    if (flag) {
      span[num2++] = 45;
    } else if ((flags & 16) != 0) {
      span[num2++] = 43;
    } else if ((flags & 8) != 0) {
      span[num2++] = 32;
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
        Char* num6 = ptr3;
        ptr3 = num6 + 1;
        *num6 = paddingChar;
      }
      for (Int32 k = 0; k < num2; k++) {
        Char* num7 = ptr3;
        ptr3 = num7 + 1;
        *num7 = span[num2 - k - 1];
      }
    } else {
      for (Int32 l = 0; l < num2; l++) {
        Char* num8 = ptr3;
        ptr3 = num8 + 1;
        *num8 = span[num2 - l - 1];
      }
      for (Int32 m = 0; m < num5; m++) {
        Char* num9 = ptr3;
        ptr3 = num9 + 1;
        *num9 = paddingChar;
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
    case 48:
    case 49:
    case 50:
    case 51:
    case 52:
    case 53:
    case 54:
    case 55:
    case 56:
    case 57:
      num = (result = c - 48);
      break;
    case 65:
    case 66:
    case 67:
    case 68:
    case 69:
    case 70:
    case 71:
    case 72:
    case 73:
    case 74:
    case 75:
    case 76:
    case 77:
    case 78:
    case 79:
    case 80:
    case 81:
    case 82:
    case 83:
    case 84:
    case 85:
    case 86:
    case 87:
    case 88:
    case 89:
    case 90:
      num = (result = c - 65 + 10);
      break;
    case 97:
    case 98:
    case 99:
    case 100:
    case 101:
    case 102:
    case 103:
    case 104:
    case 105:
    case 106:
    case 107:
    case 108:
    case 109:
    case 110:
    case 111:
    case 112:
    case 113:
    case 114:
    case 115:
    case 116:
    case 117:
    case 118:
    case 119:
    case 120:
    case 121:
    case 122:
      num = (result = c - 97 + 10);
      break;
    default:
      result = -1;
      return false;
  }
  return num < radix;
}

} // namespace System::Private::CoreLib::System::ParseNumbersNamespace
