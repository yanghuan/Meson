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
  Int32 num = ((-1 == radix) ? 10 : radix);
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
  if (s[i] == u'-') {
    if (num != 10) {
      rt::throw_exception<ArgumentException>(SR::get_Arg_CannotHaveNegativeValue());
    }
    if (((UInt32)flags & 512u) != 0) {
      rt::throw_exception<OverflowException>(SR::get_Overflow_NegativeUnsigned());
    }
    num2 = -1;
    i++;
  } else if (s[i] == u'+') {
    i++;
  }

  if ((radix == -1 || radix == 16) && i + 1 < length && s[i] == u'0' && (s[i + 1] == u'x' || s[i + 1] == u'X')) {
    num = 16;
    i += 2;
  }
  Int32 num3 = i;
  Int64 num4 = GrabLongs(num, s, i, (flags & 512) != 0);
  if (i == num3) {
    rt::throw_exception<FormatException>(SR::get_Format_NoParsibleDigits());
  }
  if (((UInt32)flags & 4096u) != 0 && i < length) {
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
  Int32 num = ((-1 == radix) ? 10 : radix);
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
  if (s[i] == u'-') {
    if (num != 10) {
      rt::throw_exception<ArgumentException>(SR::get_Arg_CannotHaveNegativeValue());
    }
    if (((UInt32)flags & 512u) != 0) {
      rt::throw_exception<OverflowException>(SR::get_Overflow_NegativeUnsigned());
    }
    num2 = -1;
    i++;
  } else if (s[i] == u'+') {
    i++;
  }

  if ((radix == -1 || radix == 16) && i + 1 < length && s[i] == u'0' && (s[i + 1] == u'x' || s[i + 1] == u'X')) {
    num = 16;
    i += 2;
  }
  Int32 num3 = i;
  Int32 num4 = GrabInts(num, s, i, (flags & 512) != 0);
  if (i == num3) {
    rt::throw_exception<FormatException>(SR::get_Format_NoParsibleDigits());
  }
  if (((UInt32)flags & 4096u) != 0 && i < length) {
    rt::throw_exception<FormatException>(SR::get_Format_ExtraJunkAtEnd());
  }
  currPos = i;
  if (((UInt32)flags & 1024u) != 0) {
    if ((UInt32)num4 > 255u) {
      Number::ThrowOverflowException(TypeCode::SByte);
    }
  } else if (((UInt32)flags & 2048u) != 0) {
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
  if (((UInt32)flags & 64u) != 0) {
    num &= 255u;
  } else if (((UInt32)flags & 128u) != 0) {
    num &= 65535u;
  }

  Int32 num2;
  if (num == 0) {
    span[0] = u'0';
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
  if (radix != 10 && ((UInt32)flags & 32u) != 0) {
    if (16 == radix) {
      span[num2++] = u'x';
      span[num2++] = u'0';
    } else if (8 == radix) {
      span[num2++] = u'0';
    }

  }
  if (10 == radix) {
    if (flag) {
      span[num2++] = u'-';
    } else if (((UInt32)flags & 16u) != 0) {
      span[num2++] = u'+';
    } else if (((UInt32)flags & 8u) != 0) {
      span[num2++] = u' ';
    }


  }
  String text = String::in::FastAllocateString(Math::Max(width, num2));
  {
    Char* ptr = rt::fixed(text);
    Char* ptr2 = ptr;
    Char* ptr3 = ptr2;
    Int32 num5 = text->get_Length() - num2;
    if (((UInt32)flags & (true ? 1u : 0u)) != 0) {
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
  if (((UInt32)flags & 64u) != 0) {
    num &= 255;
  } else if (((UInt32)flags & 128u) != 0) {
    num &= 65535;
  } else if (((UInt32)flags & 256u) != 0) {
    num &= 4294967295u;
  }


  Int32 num2;
  if (num == 0) {
    span[0] = u'0';
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
  if (radix != 10 && ((UInt32)flags & 32u) != 0) {
    if (16 == radix) {
      span[num2++] = u'x';
      span[num2++] = u'0';
    } else if (8 == radix) {
      span[num2++] = u'0';
    } else if (((UInt32)flags & 16384u) != 0) {
      span[num2++] = u'#';
      span[num2++] = (Char)(radix % 10 + 48);
      span[num2++] = (Char)(radix / 10 + 48);
    }


  }
  if (10 == radix) {
    if (flag) {
      span[num2++] = u'-';
    } else if (((UInt32)flags & 16u) != 0) {
      span[num2++] = u'+';
    } else if (((UInt32)flags & 8u) != 0) {
      span[num2++] = u' ';
    }


  }
  String text = String::in::FastAllocateString(Math::Max(width, num2));
  {
    Char* ptr = rt::fixed(text);
    Char* ptr2 = ptr;
    Char* ptr3 = ptr2;
    Int32 num5 = text->get_Length() - num2;
    if (((UInt32)flags & (true ? 1u : 0u)) != 0) {
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
  }
  return (Int32)num;
}

Boolean ParseNumbers::IsDigit(Char c, Int32 radix, Int32& result) {
  Int32 num;
  switch (c.get()) {
    case u'0':
    case u'1':
    case u'2':
    case u'3':
    case u'4':
    case u'5':
    case u'6':
    case u'7':
    case u'8':
    case u'9':
      num = (result = c - 48);
      break;
    case u'A':
    case u'B':
    case u'C':
    case u'D':
    case u'E':
    case u'F':
    case u'G':
    case u'H':
    case u'I':
    case u'J':
    case u'K':
    case u'L':
    case u'M':
    case u'N':
    case u'O':
    case u'P':
    case u'Q':
    case u'R':
    case u'S':
    case u'T':
    case u'U':
    case u'V':
    case u'W':
    case u'X':
    case u'Y':
    case u'Z':
      num = (result = c - 65 + 10);
      break;
    case u'a':
    case u'b':
    case u'c':
    case u'd':
    case u'e':
    case u'f':
    case u'g':
    case u'h':
    case u'i':
    case u'j':
    case u'k':
    case u'l':
    case u'm':
    case u'n':
    case u'o':
    case u'p':
    case u'q':
    case u'r':
    case u's':
    case u't':
    case u'u':
    case u'v':
    case u'w':
    case u'x':
    case u'y':
    case u'z':
      num = (result = c - 97 + 10);
      break;
    default:
      result = -1;
      return false;
  }
  return num < radix;
}

} // namespace System::Private::CoreLib::System::ParseNumbersNamespace
