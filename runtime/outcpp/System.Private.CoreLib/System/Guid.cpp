#include "Guid-dep.h"

#include <System.Private.CoreLib/Internal/Runtime/CompilerServices/Unsafe-dep.h>
#include <System.Private.CoreLib/Interop-dep.h>
#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/BitConverter-dep.h>
#include <System.Private.CoreLib/System/Char-dep.h>
#include <System.Private.CoreLib/System/Exception-dep.h>
#include <System.Private.CoreLib/System/FormatException-dep.h>
#include <System.Private.CoreLib/System/Globalization/NumberStyles.h>
#include <System.Private.CoreLib/System/Guid-dep.h>
#include <System.Private.CoreLib/System/HexConverter-dep.h>
#include <System.Private.CoreLib/System/Int16-dep.h>
#include <System.Private.CoreLib/System/Int32-dep.h>
#include <System.Private.CoreLib/System/MemoryExtensions-dep.h>
#include <System.Private.CoreLib/System/Number-dep.h>
#include <System.Private.CoreLib/System/OverflowException-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/MemoryMarshal-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>

namespace System::Private::CoreLib::System::GuidNamespace {
using namespace Internal::Runtime::CompilerServices;
using namespace System::Globalization;
using namespace System::Runtime::InteropServices;

GuidResult::GuidResult(Guid::GuidParseThrowStyle canThrow) {
  *this = GuidResult();
  _throwStyle = canThrow;
}

void GuidResult::SetFailure(Boolean overflow, String failureMessageID) {
  if (_throwStyle == Guid::GuidParseThrowStyle::None) {
    return;
  }
  if (overflow) {
    if (_throwStyle == Guid::GuidParseThrowStyle::All) {
      rt::throw_exception<OverflowException>(SR::GetResourceString(failureMessageID));
    }
    rt::throw_exception<FormatException>(SR::get_Format_GuidUnrecognized());
  }
  rt::throw_exception<FormatException>(SR::GetResourceString(failureMessageID));
}

Guid::Guid(Array<Byte> b) {
}

Guid::Guid(ReadOnlySpan<Byte> b) {
  if (b.get_Length() != 16) {
    rt::throw_exception<ArgumentException>(SR::Format(SR::get_Arg_GuidArrayCtor(), "16"), "b");
  }
  if (BitConverter::IsLittleEndian) {
    *this = MemoryMarshal::Read<Guid>(b);
    return;
  }
  _k = b[15];
}

Guid::Guid(UInt32 a, UInt16 b, UInt16 c, Byte d, Byte e, Byte f, Byte g, Byte h, Byte i, Byte j, Byte k) {
  _a = (Int32)a;
  _b = (Int16)b;
  _c = (Int16)c;
  _d = d;
  _e = e;
  _f = f;
  _g = g;
  _h = h;
  _i = i;
  _j = j;
  _k = k;
}

Guid::Guid(Int32 a, Int16 b, Int16 c, Array<Byte> d) {
  if (d == nullptr) {
    rt::throw_exception<ArgumentNullException>("d");
  }
  if (d->get_Length() != 8) {
    rt::throw_exception<ArgumentException>(SR::Format(SR::get_Arg_GuidArrayCtor(), "8"), "d");
  }
  _a = a;
  _b = b;
  _c = c;
  _k = d[7];
  _d = d[0];
  _e = d[1];
  _f = d[2];
  _g = d[3];
  _h = d[4];
  _i = d[5];
  _j = d[6];
}

Guid::Guid(Int32 a, Int16 b, Int16 c, Byte d, Byte e, Byte f, Byte g, Byte h, Byte i, Byte j, Byte k) {
  _a = a;
  _b = b;
  _c = c;
  _d = d;
  _e = e;
  _f = f;
  _g = g;
  _h = h;
  _i = i;
  _j = j;
  _k = k;
}

Guid::Guid(String g) {
  if (g == nullptr) {
    rt::throw_exception<ArgumentNullException>("g");
  }
  GuidResult result = GuidResult(GuidParseThrowStyle::All);
  Boolean flag = TryParseGuid(g, result);
  *this = result._parsedGuid;
}

Guid Guid::Parse(String input) {
  if (input == nullptr) {
    rt::throw_exception<ArgumentNullException>("input");
  }
  return Parse((ReadOnlySpan<Char>)input);
}

Guid Guid::Parse(ReadOnlySpan<Char> input) {
  GuidResult result = GuidResult(GuidParseThrowStyle::AllButOverflow);
  Boolean flag = TryParseGuid(input, result);
  return result._parsedGuid;
}

Boolean Guid::TryParse(String input, Guid& result) {
  if (input == nullptr) {
    result = Guid();
    return false;
  }
  return TryParse((ReadOnlySpan<Char>)input, result);
}

Boolean Guid::TryParse(ReadOnlySpan<Char> input, Guid& result) {
  GuidResult result2 = GuidResult(GuidParseThrowStyle::None);
  if (TryParseGuid(input, result2)) {
    result = result2._parsedGuid;
    return true;
  }
  result = Guid();
  return false;
}

Guid Guid::ParseExact(String input, String format) {
  if (input == nullptr) {
    rt::throw_exception<ArgumentNullException>("input");
  }
  ReadOnlySpan<Char> input2 = input;
  if (format == nullptr) {
    rt::throw_exception<ArgumentNullException>("format");
  }
  return ParseExact(input2, format);
}

Guid Guid::ParseExact(ReadOnlySpan<Char> input, ReadOnlySpan<Char> format) {
  if (format.get_Length() != 1) {
    rt::throw_exception<FormatException>(SR::get_Format_InvalidGuidFormatSpecification());
  }
  input = MemoryExtensions::Trim(input);
  GuidResult result = GuidResult(GuidParseThrowStyle::AllButOverflow);
  Boolean flag;
}

Boolean Guid::TryParseExact(String input, String format, Guid& result) {
  if (input == nullptr) {
    result = Guid();
    return false;
  }
  return TryParseExact((ReadOnlySpan<Char>)input, (ReadOnlySpan<Char>)format, result);
}

Boolean Guid::TryParseExact(ReadOnlySpan<Char> input, ReadOnlySpan<Char> format, Guid& result) {
  if (format.get_Length() != 1) {
    result = Guid();
    return false;
  }
  input = MemoryExtensions::Trim(input);
  GuidResult result2 = GuidResult(GuidParseThrowStyle::None);
  Boolean flag = false;
}

Boolean Guid::TryParseGuid(ReadOnlySpan<Char> guidString, GuidResult& result) {
  guidString = MemoryExtensions::Trim(guidString);
  if (guidString.get_Length() == 0) {
    result.SetFailure(false, "Format_GuidUnrecognized");
    return false;
  }
  switch (guidString[0].get()) {
    case 40:
      return TryParseExactP(guidString, result);
    case 123:
      return MemoryExtensions::Contains(guidString, 45) ? TryParseExactB(guidString, result) : TryParseExactX(guidString, result);
    default:
      return MemoryExtensions::Contains(guidString, 45) ? TryParseExactD(guidString, result) : TryParseExactN(guidString, result);
  }
}

Boolean Guid::TryParseExactB(ReadOnlySpan<Char> guidString, GuidResult& result) {
  if (guidString.get_Length() != 38 || guidString[0] != 123 || guidString[37] != 125) {
    result.SetFailure(false, "Format_GuidInvLen");
    return false;
  }
  return TryParseExactD(guidString.Slice(1, 36), result);
}

Boolean Guid::TryParseExactD(ReadOnlySpan<Char> guidString, GuidResult& result) {
  if (guidString.get_Length() != 36) {
    result.SetFailure(false, "Format_GuidInvLen");
    return false;
  }
  if (guidString[8] != 45 || guidString[13] != 45 || guidString[18] != 45 || guidString[23] != 45) {
    result.SetFailure(false, "Format_GuidDashes");
    return false;
  }
  Guid& parsedGuid = result._parsedGuid;
}

Boolean Guid::TryParseExactN(ReadOnlySpan<Char> guidString, GuidResult& result) {
  if (guidString.get_Length() != 32) {
    result.SetFailure(false, "Format_GuidInvLen");
    return false;
  }
  Guid& parsedGuid = result._parsedGuid;
}

Boolean Guid::TryParseExactP(ReadOnlySpan<Char> guidString, GuidResult& result) {
  if (guidString.get_Length() != 38 || guidString[0] != 40 || guidString[37] != 41) {
    result.SetFailure(false, "Format_GuidInvLen");
    return false;
  }
  return TryParseExactD(guidString.Slice(1, 36), result);
}

Boolean Guid::TryParseExactX(ReadOnlySpan<Char> guidString, GuidResult& result) {
  guidString = EatAllWhitespace(guidString);
  if (guidString.get_Length() == 0 || guidString[0] != 123) {
    result.SetFailure(false, "Format_GuidBrace");
    return false;
  }
  if (!IsHexPrefix(guidString, 1)) {
    result.SetFailure(false, "Format_GuidHexPrefix");
    return false;
  }
  Int32 num = 3;
  Int32 num2 = MemoryExtensions::IndexOf(guidString.Slice(num), 44);
  if (num2 <= 0) {
    result.SetFailure(false, "Format_GuidComma");
    return false;
  }
  Boolean overflow = false;
  if (!TryParseHex(guidString.Slice(num, num2), Unsafe::As<Int32, UInt32>(result._parsedGuid._a), overflow) || overflow) {
    result.SetFailure(overflow, overflow ? "Overflow_UInt32" : "Format_GuidInvalidChar");
    return false;
  }
  if (!IsHexPrefix(guidString, num + num2 + 1)) {
    result.SetFailure(false, "Format_GuidHexPrefix");
    return false;
  }
  num = num + num2 + 3;
  num2 = MemoryExtensions::IndexOf(guidString.Slice(num), 44);
  if (num2 <= 0) {
    result.SetFailure(false, "Format_GuidComma");
    return false;
  }
  if (!TryParseHex(guidString.Slice(num, num2), result._parsedGuid._b, overflow) || overflow) {
    result.SetFailure(overflow, overflow ? "Overflow_UInt32" : "Format_GuidInvalidChar");
    return false;
  }
  if (!IsHexPrefix(guidString, num + num2 + 1)) {
    result.SetFailure(false, "Format_GuidHexPrefix");
    return false;
  }
  num = num + num2 + 3;
  num2 = MemoryExtensions::IndexOf(guidString.Slice(num), 44);
  if (num2 <= 0) {
    result.SetFailure(false, "Format_GuidComma");
    return false;
  }
  if (!TryParseHex(guidString.Slice(num, num2), result._parsedGuid._c, overflow) || overflow) {
    result.SetFailure(overflow, overflow ? "Overflow_UInt32" : "Format_GuidInvalidChar");
    return false;
  }
  if ((UInt32)guidString.get_Length() <= (UInt32)(num + num2 + 1) || guidString[num + num2 + 1] != 123) {
    result.SetFailure(false, "Format_GuidBrace");
    return false;
  }
  num2++;
  for (Int32 i = 0; i < 8; i++) {
    if (!IsHexPrefix(guidString, num + num2 + 1)) {
      result.SetFailure(false, "Format_GuidHexPrefix");
      return false;
    }
    num = num + num2 + 3;
    if (i < 7) {
      num2 = MemoryExtensions::IndexOf(guidString.Slice(num), 44);
      if (num2 <= 0) {
        result.SetFailure(false, "Format_GuidComma");
        return false;
      }
    } else {
      num2 = MemoryExtensions::IndexOf(guidString.Slice(num), 125);
      if (num2 <= 0) {
        result.SetFailure(false, "Format_GuidBraceAfterLastNumber");
        return false;
      }
    }
  }
  if (num + num2 + 1 >= guidString.get_Length() || guidString[num + num2 + 1] != 125) {
    result.SetFailure(false, "Format_GuidEndBrace");
    return false;
  }
  if (num + num2 + 1 != guidString.get_Length() - 1) {
    result.SetFailure(false, "Format_ExtraJunkAtEnd");
    return false;
  }
  return true;
}

Boolean Guid::TryParseHex(ReadOnlySpan<Char> guidString, Int16& result, Boolean& overflow) {
  UInt32 result2;
  Boolean result3 = TryParseHex(guidString, result2, overflow);
  result = (Int16)result2;
  return result3;
}

Boolean Guid::TryParseHex(ReadOnlySpan<Char> guidString, UInt32& result) {
  Boolean overflow = false;
  return TryParseHex(guidString, result, overflow);
}

Boolean Guid::TryParseHex(ReadOnlySpan<Char> guidString, UInt32& result, Boolean& overflow) {
  if (guidString.get_Length() != 0) {
    if (guidString[0] == 43) {
      guidString = guidString.Slice(1);
    }
  }
  Int32 i;
  for (i = 0; i < guidString.get_Length() && guidString[i] == 48; i++) {
  }
  Int32 num = 0;
  ReadOnlySpan<Byte> charToHexLookup = Number::get_CharToHexLookup();
  UInt32 num2 = 0u;
  for (; i < guidString.get_Length(); i++) {
    Char c = guidString[i];
    Int32 num3;
    if ((UInt32)c >= (UInt32)charToHexLookup.get_Length() || (num3 = charToHexLookup[c]) == 255) {
      if (num > 8) {
        overflow = true;
      }
      result = 0u;
      return false;
    }
    num2 = num2 * 16 + (UInt32)num3;
    num++;
  }
  if (num > 8) {
    overflow = true;
  }
  result = num2;
  return true;
}

ReadOnlySpan<Char> Guid::EatAllWhitespace(ReadOnlySpan<Char> str) {
  Int32 i;
  for (i = 0; i < str.get_Length() && !Char::IsWhiteSpace(str[i]); i++) {
  }
  if (i == str.get_Length()) {
    return str;
  }
  Array<Char> array = rt::newarr<Array<Char>>(str.get_Length());
  Int32 length = 0;
  if (i > 0) {
    length = i;
    str.Slice(0, i).CopyTo(array);
  }
  for (; i < str.get_Length(); i++) {
    Char c = str[i];
    if (!Char::IsWhiteSpace(c)) {
      array[length++] = c;
    }
  }
  return ReadOnlySpan<Char>(array, 0, length);
}

Boolean Guid::IsHexPrefix(ReadOnlySpan<Char> str, Int32 i) {
  if (i + 1 < str.get_Length() && str[i] == 48) {
  }
  return false;
}

Array<Byte> Guid::ToByteArray() {
  Array<Byte> array = rt::newarr<Array<Byte>>(16);
  if (BitConverter::IsLittleEndian) {
    MemoryMarshal::TryWrite(array, *this);
  } else {
    TryWriteBytes(array);
  }
  return array;
}

Boolean Guid::TryWriteBytes(Span<Byte> destination) {
  if (BitConverter::IsLittleEndian) {
    return MemoryMarshal::TryWrite(destination, *this);
  }
  if (destination.get_Length() < 16) {
    return false;
  }
  destination[15] = _k;
  destination[0] = (Byte)_a;
  destination[1] = (Byte)(_a >> 8);
  destination[2] = (Byte)(_a >> 16);
  destination[3] = (Byte)(_a >> 24);
  destination[4] = (Byte)_b;
  destination[5] = (Byte)(_b >> 8);
  destination[6] = (Byte)_c;
  destination[7] = (Byte)(_c >> 8);
  destination[8] = _d;
  destination[9] = _e;
  destination[10] = _f;
  destination[11] = _g;
  destination[12] = _h;
  destination[13] = _i;
  destination[14] = _j;
  return true;
}

String Guid::ToString() {
  return ToString("D", nullptr);
}

Int32 Guid::GetHashCode() {
}

Boolean Guid::Equals(Object o) {
  if (o == nullptr || !rt::is<Guid>(o)) {
    return false;
  }
  Guid guid = (Guid)o;
  if (guid._a == _a && Unsafe::Add(guid._a, 1) == Unsafe::Add(_a, 1) && Unsafe::Add(guid._a, 2) == Unsafe::Add(_a, 2)) {
    return Unsafe::Add(guid._a, 3) == Unsafe::Add(_a, 3);
  }
  return false;
}

Boolean Guid::Equals(Guid g) {
  if (g._a == _a && Unsafe::Add(g._a, 1) == Unsafe::Add(_a, 1) && Unsafe::Add(g._a, 2) == Unsafe::Add(_a, 2)) {
    return Unsafe::Add(g._a, 3) == Unsafe::Add(_a, 3);
  }
  return false;
}

Int32 Guid::GetResult(UInt32 me, UInt32 them) {
  if (me >= them) {
    return 1;
  }
  return -1;
}

Int32 Guid::CompareTo(Object value) {
  if (value == nullptr) {
    return 1;
  }
  if (!rt::is<Guid>(value)) {
    rt::throw_exception<ArgumentException>(SR::get_Arg_MustBeGuid(), "value");
  }
  Guid guid = (Guid)value;
  if (guid._a != _a) {
    return GetResult((UInt32)_a, (UInt32)guid._a);
  }
  if (guid._b != _b) {
    return GetResult((UInt32)_b, (UInt32)guid._b);
  }
  if (guid._c != _c) {
    return GetResult((UInt32)_c, (UInt32)guid._c);
  }
  if (guid._d != _d) {
    return GetResult(_d, guid._d);
  }
  if (guid._e != _e) {
    return GetResult(_e, guid._e);
  }
  if (guid._f != _f) {
    return GetResult(_f, guid._f);
  }
  if (guid._g != _g) {
    return GetResult(_g, guid._g);
  }
  if (guid._h != _h) {
    return GetResult(_h, guid._h);
  }
  if (guid._i != _i) {
    return GetResult(_i, guid._i);
  }
  if (guid._j != _j) {
    return GetResult(_j, guid._j);
  }
  if (guid._k != _k) {
    return GetResult(_k, guid._k);
  }
  return 0;
}

Int32 Guid::CompareTo(Guid value) {
  if (value._a != _a) {
    return GetResult((UInt32)_a, (UInt32)value._a);
  }
  if (value._b != _b) {
    return GetResult((UInt32)_b, (UInt32)value._b);
  }
  if (value._c != _c) {
    return GetResult((UInt32)_c, (UInt32)value._c);
  }
  if (value._d != _d) {
    return GetResult(_d, value._d);
  }
  if (value._e != _e) {
    return GetResult(_e, value._e);
  }
  if (value._f != _f) {
    return GetResult(_f, value._f);
  }
  if (value._g != _g) {
    return GetResult(_g, value._g);
  }
  if (value._h != _h) {
    return GetResult(_h, value._h);
  }
  if (value._i != _i) {
    return GetResult(_i, value._i);
  }
  if (value._j != _j) {
    return GetResult(_j, value._j);
  }
  if (value._k != _k) {
    return GetResult(_k, value._k);
  }
  return 0;
}

Boolean Guid::op_Equality(Guid a, Guid b) {
  if (a._a == b._a && Unsafe::Add(a._a, 1) == Unsafe::Add(b._a, 1) && Unsafe::Add(a._a, 2) == Unsafe::Add(b._a, 2)) {
    return Unsafe::Add(a._a, 3) == Unsafe::Add(b._a, 3);
  }
  return false;
}

Boolean Guid::op_Inequality(Guid a, Guid b) {
  if (a._a == b._a && Unsafe::Add(a._a, 1) == Unsafe::Add(b._a, 1) && Unsafe::Add(a._a, 2) == Unsafe::Add(b._a, 2)) {
    return Unsafe::Add(a._a, 3) != Unsafe::Add(b._a, 3);
  }
  return true;
}

String Guid::ToString(String format) {
  return ToString(format, nullptr);
}

Int32 Guid::HexsToChars(Char* guidChars, Int32 a, Int32 b) {
  *guidChars = HexConverter::ToCharLower(a >> 4);
  guidChars[1] = HexConverter::ToCharLower(a);
  guidChars[2] = HexConverter::ToCharLower(b >> 4);
  guidChars[3] = HexConverter::ToCharLower(b);
  return 4;
}

Int32 Guid::HexsToCharsHexOutput(Char* guidChars, Int32 a, Int32 b) {
  *guidChars = 48;
  guidChars[1] = 120;
  guidChars[2] = HexConverter::ToCharLower(a >> 4);
  guidChars[3] = HexConverter::ToCharLower(a);
  guidChars[4] = 44;
  guidChars[5] = 48;
  guidChars[6] = 120;
  guidChars[7] = HexConverter::ToCharLower(b >> 4);
  guidChars[8] = HexConverter::ToCharLower(b);
  return 9;
}

String Guid::ToString(String format, IFormatProvider provider) {
  if (String::in::IsNullOrEmpty(format)) {
    format = "D";
  }
  if (format->get_Length() != 1) {
    rt::throw_exception<FormatException>(SR::get_Format_InvalidGuidFormatSpecification());
  }
  Int32 length;
  switch (format[0].get()) {
    case 68:
    case 100:
      length = 36;
      break;
    case 78:
    case 110:
      length = 32;
      break;
    case 66:
    case 80:
    case 98:
    case 112:
      length = 38;
      break;
    case 88:
    case 120:
      length = 68;
      break;
    default:
      rt::throw_exception<FormatException>(SR::get_Format_InvalidGuidFormatSpecification());
  }
  String text = String::in::FastAllocateString(length);
  Int32 charsWritten;
  Boolean flag = TryFormat(Span<Char>(text->GetRawStringData(), text->get_Length()), charsWritten, format);
  return text;
}

Boolean Guid::TryFormat(Span<Char> destination, Int32& charsWritten, ReadOnlySpan<Char> format) {
  if (format.get_Length() == 0) {
    format = "D";
  }
  if (format.get_Length() != 1) {
    rt::throw_exception<FormatException>(SR::get_Format_InvalidGuidFormatSpecification());
  }
  Boolean flag = true;
  Boolean flag2 = false;
  Int32 num = 0;
  Int32 num2;
  switch (format[0].get()) {
    case 68:
    case 100:
      num2 = 36;
      break;
    case 78:
    case 110:
      flag = false;
      num2 = 32;
      break;
    case 66:
    case 98:
      num = 8192123;
      num2 = 38;
      break;
    case 80:
    case 112:
      num = 2687016;
      num2 = 38;
      break;
    case 88:
    case 120:
      num = 8192123;
      flag = false;
      flag2 = true;
      num2 = 68;
      break;
    default:
      rt::throw_exception<FormatException>(SR::get_Format_InvalidGuidFormatSpecification());
  }
  if (destination.get_Length() < num2) {
    charsWritten = 0;
    return false;
  }
  {
    Char* ptr = &MemoryMarshal::GetReference(destination);
    Char* ptr2 = ptr;
    if (num != 0) {
      Char* num3 = ptr2;
      ptr2 = num3 + 1;
      *num3 = (Char)num;
    }
    if (flag2) {
      Char* num4 = ptr2;
      ptr2 = num4 + 1;
      *num4 = 48;
      Char* num5 = ptr2;
      ptr2 = num5 + 1;
      *num5 = 120;
      ptr2 += HexsToChars(ptr2, _a >> 24, _a >> 16);
      ptr2 += HexsToChars(ptr2, _a >> 8, _a);
      Char* num6 = ptr2;
      ptr2 = num6 + 1;
      *num6 = 44;
      Char* num7 = ptr2;
      ptr2 = num7 + 1;
      *num7 = 48;
      Char* num8 = ptr2;
      ptr2 = num8 + 1;
      *num8 = 120;
      ptr2 += HexsToChars(ptr2, _b >> 8, _b);
      Char* num9 = ptr2;
      ptr2 = num9 + 1;
      *num9 = 44;
      Char* num10 = ptr2;
      ptr2 = num10 + 1;
      *num10 = 48;
      Char* num11 = ptr2;
      ptr2 = num11 + 1;
      *num11 = 120;
      ptr2 += HexsToChars(ptr2, _c >> 8, _c);
      Char* num12 = ptr2;
      ptr2 = num12 + 1;
      *num12 = 44;
      Char* num13 = ptr2;
      ptr2 = num13 + 1;
      *num13 = 123;
      ptr2 += HexsToCharsHexOutput(ptr2, _d, _e);
      Char* num14 = ptr2;
      ptr2 = num14 + 1;
      *num14 = 44;
      ptr2 += HexsToCharsHexOutput(ptr2, _f, _g);
      Char* num15 = ptr2;
      ptr2 = num15 + 1;
      *num15 = 44;
      ptr2 += HexsToCharsHexOutput(ptr2, _h, _i);
      Char* num16 = ptr2;
      ptr2 = num16 + 1;
      *num16 = 44;
      ptr2 += HexsToCharsHexOutput(ptr2, _j, _k);
      Char* num17 = ptr2;
      ptr2 = num17 + 1;
      *num17 = 125;
    } else {
      ptr2 += HexsToChars(ptr2, _a >> 24, _a >> 16);
      ptr2 += HexsToChars(ptr2, _a >> 8, _a);
      if (flag) {
        Char* num18 = ptr2;
        ptr2 = num18 + 1;
        *num18 = 45;
      }
      ptr2 += HexsToChars(ptr2, _b >> 8, _b);
      if (flag) {
        Char* num19 = ptr2;
        ptr2 = num19 + 1;
        *num19 = 45;
      }
      ptr2 += HexsToChars(ptr2, _c >> 8, _c);
      if (flag) {
        Char* num20 = ptr2;
        ptr2 = num20 + 1;
        *num20 = 45;
      }
      ptr2 += HexsToChars(ptr2, _d, _e);
      if (flag) {
        Char* num21 = ptr2;
        ptr2 = num21 + 1;
        *num21 = 45;
      }
      ptr2 += HexsToChars(ptr2, _f, _g);
      ptr2 += HexsToChars(ptr2, _h, _i);
      ptr2 += HexsToChars(ptr2, _j, _k);
    }
    if (num != 0) {
      Char* num22 = ptr2;
      ptr2 = num22 + 1;
      *num22 = (Char)(num >> 16);
    }
  }
  charsWritten = num2;
  return true;
}

Guid Guid::NewGuid() {
  Guid guid;
  Int32 num = Interop::Ole32::CoCreateGuid(guid);
  if (num != 0) {
    Exception ex = rt::newobj<Exception>();
    ex->set_HResult = num;
    rt::throw_exception(ex);
  }
  return guid;
}

} // namespace System::Private::CoreLib::System::GuidNamespace
