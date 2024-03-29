#include "IdnMapping-dep.h"

#include <System.Private.CoreLib/Interop-dep.h>
#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/Char-dep.h>
#include <System.Private.CoreLib/System/Globalization/CharUnicodeInfo-dep.h>
#include <System.Private.CoreLib/System/Globalization/GlobalizationMode-dep.h>
#include <System.Private.CoreLib/System/Globalization/IdnMapping-dep.h>
#include <System.Private.CoreLib/System/Globalization/Ordinal-dep.h>
#include <System.Private.CoreLib/System/Globalization/StrongBidiCategory.h>
#include <System.Private.CoreLib/System/Int64-dep.h>
#include <System.Private.CoreLib/System/Math-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/Marshal-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/StringComparison.h>
#include <System.Private.CoreLib/System/Text/StringBuilder-dep.h>

namespace System::Private::CoreLib::System::Globalization::IdnMappingNamespace {
using namespace System::Runtime::InteropServices;
using namespace System::Text;

Boolean IdnMapping___::get_AllowUnassigned() {
  return _allowUnassigned;
}

void IdnMapping___::set_AllowUnassigned(Boolean value) {
  _allowUnassigned = value;
}

Boolean IdnMapping___::get_UseStd3AsciiRules() {
  return _useStd3AsciiRules;
}

void IdnMapping___::set_UseStd3AsciiRules(Boolean value) {
  _useStd3AsciiRules = value;
}

UInt32 IdnMapping___::get_IcuFlags() {
  return (get_AllowUnassigned() ? 1u : 0u) | (get_UseStd3AsciiRules() ? 2u : 0u);
}

UInt32 IdnMapping___::get_NlsFlags() {
  return (get_AllowUnassigned() ? 1u : 0u) | (get_UseStd3AsciiRules() ? 2u : 0u);
}

void IdnMapping___::ctor() {
}

String IdnMapping___::GetAscii(String unicode) {
  return GetAscii(unicode, 0);
}

String IdnMapping___::GetAscii(String unicode, Int32 index) {
  if (unicode == nullptr) {
    rt::throw_exception<ArgumentNullException>("unicode");
  }
  return GetAscii(unicode, index, unicode->get_Length() - index);
}

String IdnMapping___::GetAscii(String unicode, Int32 index, Int32 count) {
  if (unicode == nullptr) {
    rt::throw_exception<ArgumentNullException>("unicode");
  }
  if (index < 0 || count < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>((index < 0) ? "index" : "count", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  if (index > unicode->get_Length()) {
    rt::throw_exception<ArgumentOutOfRangeException>("index", SR::get_ArgumentOutOfRange_Index());
  }
  if (index > unicode->get_Length() - count) {
    rt::throw_exception<ArgumentOutOfRangeException>("unicode", SR::get_ArgumentOutOfRange_IndexCountBuffer());
  }
  if (count == 0) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_IdnBadLabelSize(), "unicode");
  }
  if (unicode[index + count - 1] == u'\0') {
    rt::throw_exception<ArgumentException>(SR::Format(SR::get_Argument_InvalidCharSequence(), index + count - 1), "unicode");
  }
  if (GlobalizationMode::get_Invariant()) {
    return GetAsciiInvariant(unicode, index, count);
  }
  {
    Char* ptr = rt::fixed(unicode);
    Char* ptr2 = ptr;
    if (!GlobalizationMode::get_UseNls()) {
      return IcuGetAsciiCore(unicode, ptr2 + index, count);
    }
    return NlsGetAsciiCore(unicode, ptr2 + index, count);
  }
}

String IdnMapping___::GetUnicode(String ascii) {
  return GetUnicode(ascii, 0);
}

String IdnMapping___::GetUnicode(String ascii, Int32 index) {
  if (ascii == nullptr) {
    rt::throw_exception<ArgumentNullException>("ascii");
  }
  return GetUnicode(ascii, index, ascii->get_Length() - index);
}

String IdnMapping___::GetUnicode(String ascii, Int32 index, Int32 count) {
  if (ascii == nullptr) {
    rt::throw_exception<ArgumentNullException>("ascii");
  }
  if (index < 0 || count < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>((index < 0) ? "index" : "count", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  if (index > ascii->get_Length()) {
    rt::throw_exception<ArgumentOutOfRangeException>("index", SR::get_ArgumentOutOfRange_Index());
  }
  if (index > ascii->get_Length() - count) {
    rt::throw_exception<ArgumentOutOfRangeException>("ascii", SR::get_ArgumentOutOfRange_IndexCountBuffer());
  }
  if (count > 0 && ascii[index + count - 1] == u'\0') {
    rt::throw_exception<ArgumentException>(SR::get_Argument_IdnBadPunycode(), "ascii");
  }
  if (GlobalizationMode::get_Invariant()) {
    return GetUnicodeInvariant(ascii, index, count);
  }
  {
    Char* ptr = rt::fixed(ascii);
    Char* ptr2 = ptr;
    if (!GlobalizationMode::get_UseNls()) {
      return IcuGetUnicodeCore(ascii, ptr2 + index, count);
    }
    return NlsGetUnicodeCore(ascii, ptr2 + index, count);
  }
}

Boolean IdnMapping___::Equals(Object obj) {
  IdnMapping idnMapping = rt::as<IdnMapping>(obj);
  if (idnMapping != nullptr && _allowUnassigned == idnMapping->_allowUnassigned) {
    return _useStd3AsciiRules == idnMapping->_useStd3AsciiRules;
  }
  return false;
}

Int32 IdnMapping___::GetHashCode() {
  return (_allowUnassigned ? 100 : 200) + (_useStd3AsciiRules ? 1000 : 2000);
}

String IdnMapping___::GetStringForOutput(String originalString, Char* input, Int32 inputLength, Char* output, Int32 outputLength) {
  if (originalString->get_Length() == inputLength && inputLength == outputLength && Ordinal::EqualsIgnoreCase(*input, *output, inputLength)) {
    return originalString;
  }
  return rt::newstr<String>(output, 0, outputLength);
}

String IdnMapping___::GetAsciiInvariant(String unicode, Int32 index, Int32 count) {
  if (index > 0 || count < unicode->get_Length()) {
    unicode = unicode->Substring(index, count);
  }
  if (ValidateStd3AndAscii(unicode, get_UseStd3AsciiRules(), true)) {
    return unicode;
  }
  String text = unicode;
  Int32 index2 = text->get_Length() - 1;
  if (text[index2] <= u'\x001f') {
    rt::throw_exception<ArgumentException>(SR::Format(SR::get_Argument_InvalidCharSequence(), unicode->get_Length() - 1), "unicode");
  }
  if (get_UseStd3AsciiRules()) {
    ValidateStd3AndAscii(unicode, true, false);
  }
  return PunycodeEncode(unicode);
}

Boolean IdnMapping___::ValidateStd3AndAscii(String unicode, Boolean bUseStd3, Boolean bCheckAscii) {
  if (unicode->get_Length() == 0) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_IdnBadLabelSize(), "unicode");
  }
  Int32 num = -1;
  for (Int32 i = 0; i < unicode->get_Length(); i++) {
    if (unicode[i] <= u'\x001f') {
      rt::throw_exception<ArgumentException>(SR::Format(SR::get_Argument_InvalidCharSequence(), i), "unicode");
    }
    if (bCheckAscii && unicode[i] >= u'\x007f') {
      return false;
    }
    if (IsDot(unicode[i])) {
      if (i == num + 1) {
        rt::throw_exception<ArgumentException>(SR::get_Argument_IdnBadLabelSize(), "unicode");
      }
      if (i - num > 64) {
        rt::throw_exception<ArgumentException>(SR::get_Argument_IdnBadLabelSize(), "unicode");
      }
      if (bUseStd3 && i > 0) {
        ValidateStd3(unicode[i - 1], true);
      }
      num = i;
    } else if (bUseStd3) {
      ValidateStd3(unicode[i], i == num + 1);
    }

  }
  if (num == -1 && unicode->get_Length() > 63) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_IdnBadLabelSize(), "unicode");
  }
  Int32 length = unicode->get_Length();
  Int32 index = unicode->get_Length() - 1;
  if (length > 255 - ((!IsDot(unicode[index])) ? 1 : 0)) {
    String argument_IdnBadNameSize = SR::get_Argument_IdnBadNameSize();
    index = unicode->get_Length() - 1;
    rt::throw_exception<ArgumentException>(SR::Format(argument_IdnBadNameSize, 255 - ((!IsDot(unicode[index])) ? 1 : 0)), "unicode");
  }
  if (bUseStd3) {
    index = unicode->get_Length() - 1;
    if (!IsDot(unicode[index])) {
      index = unicode->get_Length() - 1;
      ValidateStd3(unicode[index], true);
    }
  }
  return true;
}

String IdnMapping___::PunycodeEncode(String unicode) {
  if (unicode->get_Length() == 0) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_IdnBadLabelSize(), "unicode");
  }
  StringBuilder stringBuilder = rt::newobj<StringBuilder>(unicode->get_Length());
  Int32 num = 0;
  Int32 num2 = 0;
  Int32 num3 = 0;
  while (num < unicode->get_Length()) {
    num = unicode->IndexOfAny(s_dotSeparators, num2);
    if (num < 0) {
      num = unicode->get_Length();
    }
    if (num == num2) {
      if (num == unicode->get_Length()) {
        break;
      }
      rt::throw_exception<ArgumentException>(SR::get_Argument_IdnBadLabelSize(), "unicode");
    }
    stringBuilder->Append((String)"xn--");
    Boolean flag = false;
    StrongBidiCategory bidiCategory = CharUnicodeInfo::GetBidiCategory(unicode, num2);
    if (bidiCategory == StrongBidiCategory::StrongRightToLeft) {
      flag = true;
      Int32 num4 = num - 1;
      if (Char::IsLowSurrogate(unicode, num4)) {
        num4--;
      }
      bidiCategory = CharUnicodeInfo::GetBidiCategory(unicode, num4);
      if (bidiCategory != StrongBidiCategory::StrongRightToLeft) {
        rt::throw_exception<ArgumentException>(SR::get_Argument_IdnBadBidi(), "unicode");
      }
    }
    Int32 num5 = 0;
    for (Int32 i = num2; i < num; i++) {
      StrongBidiCategory bidiCategory2 = CharUnicodeInfo::GetBidiCategory(unicode, i);
      if (flag && bidiCategory2 == StrongBidiCategory::StrongLeftToRight) {
        rt::throw_exception<ArgumentException>(SR::get_Argument_IdnBadBidi(), "unicode");
      }
      if (!flag && bidiCategory2 == StrongBidiCategory::StrongRightToLeft) {
        rt::throw_exception<ArgumentException>(SR::get_Argument_IdnBadBidi(), "unicode");
      }
      if (Basic(unicode[i])) {
        stringBuilder->Append(EncodeBasic(unicode[i]));
        num5++;
      } else if (Char::IsSurrogatePair(unicode, i)) {
        i++;
      }

    }
    Int32 num6 = num5;
    if (num6 == num - num2) {
      stringBuilder->Remove(num3, "xn--"->get_Length());
    } else {
      if (unicode->get_Length() - num2 >= "xn--"->get_Length() && unicode->Substring(num2, "xn--"->get_Length())->Equals("xn--", StringComparison::OrdinalIgnoreCase)) {
        rt::throw_exception<ArgumentException>(SR::get_Argument_IdnBadPunycode(), "unicode");
      }
      Int32 num7 = 0;
      if (num6 > 0) {
        stringBuilder->Append((Char)u'-');
      }
      Int32 num8 = 128;
      Int32 num9 = 0;
      Int32 num10 = 72;
      while (num5 < num - num2) {
        Int32 num11 = 0;
        Int32 num12 = 134217727;
        for (Int32 j = num2; j < num; j += ((!IsSupplementary(num11)) ? 1 : 2)) {
          num11 = Char::ConvertToUtf32(unicode, j);
          if (num11 >= num8 && num11 < num12) {
            num12 = num11;
          }
        }
        num9 += (num12 - num8) * (num5 - num7 + 1);
        num8 = num12;
        for (Int32 j = num2; j < num; j += ((!IsSupplementary(num11)) ? 1 : 2)) {
          num11 = Char::ConvertToUtf32(unicode, j);
          if (num11 < num8) {
            num9++;
          }
          if (num11 != num8) {
            continue;
          }
          Int32 num13 = num9;
          Int32 num14 = 36;
          while (true) {
            Int32 num15 = ((num14 <= num10) ? 1 : ((num14 >= num10 + 26) ? 26 : (num14 - num10)));
            if (num13 < num15) {
              break;
            }
            stringBuilder->Append(EncodeDigit(num15 + (num13 - num15) % (36 - num15)));
            num13 = (num13 - num15) / (36 - num15);
            num14 += 36;
          }
          stringBuilder->Append(EncodeDigit(num13));
          num10 = Adapt(num9, num5 - num7 + 1, num5 == num6);
          num9 = 0;
          num5++;
          if (IsSupplementary(num12)) {
            num5++;
            num7++;
          }
        }
        num9++;
        num8++;
      }
    }
    if (stringBuilder->get_Length() - num3 > 63) {
      rt::throw_exception<ArgumentException>(SR::get_Argument_IdnBadLabelSize(), "unicode");
    }
    if (num != unicode->get_Length()) {
      stringBuilder->Append((Char)u'.');
    }
    num2 = num + 1;
    num3 = stringBuilder->set_Length();
  }
  Int32 length = stringBuilder->get_Length();
  Int32 index = unicode->get_Length() - 1;
  if (length > 255 - ((!IsDot(unicode[index])) ? 1 : 0)) {
    String argument_IdnBadNameSize = SR::get_Argument_IdnBadNameSize();
    index = unicode->get_Length() - 1;
    rt::throw_exception<ArgumentException>(SR::Format(argument_IdnBadNameSize, 255 - ((!IsDot(unicode[index])) ? 1 : 0)), "unicode");
  }
  return stringBuilder->ToString();
}

Boolean IdnMapping___::IsDot(Char c) {
  if (c != u'.' && c != u'\u3002' && c != u'\uff0e') {
    return c == u'\uff61';
  }
  return true;
}

Boolean IdnMapping___::IsSupplementary(Int32 cTest) {
  return cTest >= 65536;
}

Boolean IdnMapping___::Basic(UInt32 cp) {
  return cp < 128;
}

void IdnMapping___::ValidateStd3(Char c, Boolean bNextToDot) {
  if (c > u',') {
    switch (c.get()) {
      default:
        if ((c < u'[' || c > u'`') && (c < u'{' || c > u'\x007f') && !(c == u'-' && bNextToDot)) {
          return;
        }
        break;
      case u'/':
      case u':':
      case u';':
      case u'<':
      case u'=':
      case u'>':
      case u'?':
      case u'@':
        break;
    }
  }
  rt::throw_exception<ArgumentException>(SR::Format(SR::get_Argument_IdnBadStd3(), c), "c");
}

String IdnMapping___::GetUnicodeInvariant(String ascii, Int32 index, Int32 count) {
  if (index > 0 || count < ascii->get_Length()) {
    ascii = ascii->Substring(index, count);
  }
  String text = PunycodeDecode(ascii);
  if (!ascii->Equals(GetAscii(text), StringComparison::OrdinalIgnoreCase)) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_IdnIllegalName(), "ascii");
  }
  return text;
}

String IdnMapping___::PunycodeDecode(String ascii) {
  if (ascii->get_Length() == 0) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_IdnBadLabelSize(), "ascii");
  }
  Int32 length = ascii->get_Length();
  Int32 index = ascii->get_Length() - 1;
  if (length > 255 - ((!IsDot(ascii[index])) ? 1 : 0)) {
    String argument_IdnBadNameSize = SR::get_Argument_IdnBadNameSize();
    index = ascii->get_Length() - 1;
    rt::throw_exception<ArgumentException>(SR::Format(argument_IdnBadNameSize, 255 - ((!IsDot(ascii[index])) ? 1 : 0)), "ascii");
  }
  StringBuilder stringBuilder = rt::newobj<StringBuilder>(ascii->get_Length());
  Int32 num = 0;
  Int32 num2 = 0;
  Int32 num3 = 0;
  while (num < ascii->get_Length()) {
    num = ascii->IndexOf(u'.', num2);
    if (num < 0 || num > ascii->get_Length()) {
      num = ascii->get_Length();
    }
    if (num == num2) {
      if (num == ascii->get_Length()) {
        break;
      }
      rt::throw_exception<ArgumentException>(SR::get_Argument_IdnBadLabelSize(), "ascii");
    }
    if (num - num2 > 63) {
      rt::throw_exception<ArgumentException>(SR::get_Argument_IdnBadLabelSize(), "ascii");
    }
    if (ascii->get_Length() < "xn--"->get_Length() + num2 || String::in::Compare(ascii, num2, "xn--", 0, "xn--"->get_Length(), StringComparison::OrdinalIgnoreCase) != 0) {
      stringBuilder->Append(ascii, num2, num - num2);
    } else {
      num2 += "xn--"->get_Length();
      Int32 num4 = ascii->LastIndexOf(u'-', num - 1);
      if (num4 == num - 1) {
        rt::throw_exception<ArgumentException>(SR::get_Argument_IdnBadPunycode(), "ascii");
      }
      Int32 num5;
      if (num4 <= num2) {
        num5 = 0;
      } else {
        num5 = num4 - num2;
        for (Int32 i = num2; i < num2 + num5; i++) {
          if (ascii[i] > u'\x007f') {
            rt::throw_exception<ArgumentException>(SR::get_Argument_IdnBadPunycode(), "ascii");
          }
          stringBuilder->Append((Char)((ascii[i] >= u'A' && ascii[i] <= u'Z') ? (ascii[i] - 65 + 97) : ascii[i]));
        }
      }
      Int32 num6 = num2 + ((num5 > 0) ? (num5 + 1) : 0);
      Int32 num7 = 128;
      Int32 num8 = 72;
      Int32 num9 = 0;
      Int32 num10 = 0;
      while (num6 < num) {
        Int32 num11 = num9;
        Int32 num12 = 1;
        Int32 num13 = 36;
        while (true) {
          if (num6 >= num) {
            rt::throw_exception<ArgumentException>(SR::get_Argument_IdnBadPunycode(), "ascii");
          }
          Int32 num14 = DecodeDigit(ascii[num6++]);
          if (num14 > (134217727 - num9) / num12) {
            rt::throw_exception<ArgumentException>(SR::get_Argument_IdnBadPunycode(), "ascii");
          }
          num9 += num14 * num12;
          Int32 num15 = ((num13 <= num8) ? 1 : ((num13 >= num8 + 26) ? 26 : (num13 - num8)));
          if (num14 < num15) {
            break;
          }
          if (num12 > 134217727 / (36 - num15)) {
            rt::throw_exception<ArgumentException>(SR::get_Argument_IdnBadPunycode(), "ascii");
          }
          num12 *= 36 - num15;
          num13 += 36;
        }
        num8 = Adapt(num9 - num11, stringBuilder->get_Length() - num3 - num10 + 1, num11 == 0);
        if (num9 / (stringBuilder->get_Length() - num3 - num10 + 1) > 134217727 - num7) {
          rt::throw_exception<ArgumentException>(SR::get_Argument_IdnBadPunycode(), "ascii");
        }
        num7 += num9 / (stringBuilder->get_Length() - num3 - num10 + 1);
        num9 %= stringBuilder->get_Length() - num3 - num10 + 1;
        if (num7 < 0 || num7 > 1114111 || (num7 >= 55296 && num7 <= 57343)) {
          rt::throw_exception<ArgumentException>(SR::get_Argument_IdnBadPunycode(), "ascii");
        }
        String value = Char::ConvertFromUtf32(num7);
        Int32 num17;
        if (num10 > 0) {
          Int32 num16 = num9;
          num17 = num3;
          while (num16 > 0) {
            if (num17 >= stringBuilder->get_Length()) {
              rt::throw_exception<ArgumentException>(SR::get_Argument_IdnBadPunycode(), "ascii");
            }
            if (Char::IsSurrogate(stringBuilder[num17])) {
              num17++;
            }
            num16--;
            num17++;
          }
        } else {
          num17 = num3 + num9;
        }
        stringBuilder->Insert(num17, value);
        if (IsSupplementary(num7)) {
          num10++;
        }
        num9++;
      }
      Boolean flag = false;
      StrongBidiCategory bidiCategory = CharUnicodeInfo::GetBidiCategory(stringBuilder, num3);
      if (bidiCategory == StrongBidiCategory::StrongRightToLeft) {
        flag = true;
      }
      for (Int32 j = num3; j < stringBuilder->get_Length(); j++) {
        if (!Char::IsLowSurrogate(stringBuilder[j])) {
          bidiCategory = CharUnicodeInfo::GetBidiCategory(stringBuilder, j);
          if ((flag && bidiCategory == StrongBidiCategory::StrongLeftToRight) || (!flag && bidiCategory == StrongBidiCategory::StrongRightToLeft)) {
            rt::throw_exception<ArgumentException>(SR::get_Argument_IdnBadBidi(), "ascii");
          }
        }
      }
      if (flag && bidiCategory != StrongBidiCategory::StrongRightToLeft) {
        rt::throw_exception<ArgumentException>(SR::get_Argument_IdnBadBidi(), "ascii");
      }
    }
    if (num - num2 > 63) {
      rt::throw_exception<ArgumentException>(SR::get_Argument_IdnBadLabelSize(), "ascii");
    }
    if (num != ascii->get_Length()) {
      stringBuilder->Append((Char)u'.');
    }
    num2 = num + 1;
    num3 = stringBuilder->set_Length();
  }
  if (stringBuilder->get_Length() > 255 - ((!IsDot(stringBuilder[stringBuilder->get_Length() - 1])) ? 1 : 0)) {
    rt::throw_exception<ArgumentException>(SR::Format(SR::get_Argument_IdnBadNameSize(), 255 - ((!IsDot(stringBuilder[stringBuilder->get_Length() - 1])) ? 1 : 0)), "ascii");
  }
  return stringBuilder->ToString();
}

Int32 IdnMapping___::DecodeDigit(Char cp) {
  if (cp >= u'0' && cp <= u'9') {
    return cp - 48 + 26;
  }
  if (cp >= u'a' && cp <= u'z') {
    return cp - 97;
  }
  if (cp >= u'A' && cp <= u'Z') {
    return cp - 65;
  }
  rt::throw_exception<ArgumentException>(SR::get_Argument_IdnBadPunycode(), "cp");
}

Int32 IdnMapping___::Adapt(Int32 delta, Int32 numpoints, Boolean firsttime) {
  delta = (firsttime ? (delta / 700) : (delta / 2));
  delta += delta / numpoints;
  UInt32 num = 0u;
  while (delta > 455) {
    delta /= 35;
    num += 36;
  }
  return (Int32)(num + 36 * delta / (delta + 38));
}

Char IdnMapping___::EncodeBasic(Char bcp) {
  if (HasUpperCaseFlag(bcp)) {
    bcp = (Char)(bcp + 32);
  }
  return bcp;
}

Boolean IdnMapping___::HasUpperCaseFlag(Char punychar) {
  if (punychar >= u'A') {
    return punychar <= u'Z';
  }
  return false;
}

Char IdnMapping___::EncodeDigit(Int32 d) {
  if (d > 25) {
    return (Char)(d - 26 + 48);
  }
  return (Char)(d + 97);
}

String IdnMapping___::IcuGetAsciiCore(String unicodeString, Char* unicode, Int32 count) {
  UInt32 icuFlags = get_IcuFlags();
  CheckInvalidIdnCharacters(unicode, count, icuFlags, "unicode");
  Int32 num = (Int32)Math::Min((Int64)count * 3 + 4, 512);
  Int32 num2;
  if (num < 512) {
    Char as[num] = {};
    Char* ptr = as;
    num2 = Interop::Globalization::ToAscii(icuFlags, unicode, count, ptr, num);
    if (num2 > 0 && num2 <= num) {
      return GetStringForOutput(unicodeString, unicode, count, ptr, num2);
    }
  } else {
    num2 = Interop::Globalization::ToAscii(icuFlags, unicode, count, nullptr, 0);
  }
  if (num2 == 0) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_IdnIllegalName(), "unicode");
  }
  Array<Char> array = rt::newarr<Array<Char>>(num2);
  {
    Char* ptr2 = rt::fixed(&array[0]);
    num2 = Interop::Globalization::ToAscii(icuFlags, unicode, count, ptr2, num2);
    if (num2 == 0 || num2 > array->get_Length()) {
      rt::throw_exception<ArgumentException>(SR::get_Argument_IdnIllegalName(), "unicode");
    }
    return GetStringForOutput(unicodeString, unicode, count, ptr2, num2);
  }
}

String IdnMapping___::IcuGetUnicodeCore(String asciiString, Char* ascii, Int32 count) {
  UInt32 icuFlags = get_IcuFlags();
  CheckInvalidIdnCharacters(ascii, count, icuFlags, "ascii");
  if (count < 512) {
    Char as[count] = {};
    Char* output = as;
    return IcuGetUnicodeCore(asciiString, ascii, count, icuFlags, output, count, true);
  }
  Array<Char> array = rt::newarr<Array<Char>>(count);
  {
    Char* output2 = rt::fixed(&array[0]);
    return IcuGetUnicodeCore(asciiString, ascii, count, icuFlags, output2, count, true);
  }
}

String IdnMapping___::IcuGetUnicodeCore(String asciiString, Char* ascii, Int32 count, UInt32 flags, Char* output, Int32 outputLength, Boolean reattempt) {
  Int32 num = Interop::Globalization::ToUnicode(flags, ascii, count, output, outputLength);
  if (num == 0) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_IdnIllegalName(), "ascii");
  }
  if (num <= outputLength) {
    return GetStringForOutput(asciiString, ascii, count, output, num);
  }
  if (reattempt) {
    {
      Char* output2 = rt::fixed(rt::newarr<Array<Char>>(num));
      return IcuGetUnicodeCore(asciiString, ascii, count, flags, output2, num, false);
    }
  }
  rt::throw_exception<ArgumentException>(SR::get_Argument_IdnIllegalName(), "ascii");
}

void IdnMapping___::CheckInvalidIdnCharacters(Char* s, Int32 count, UInt32 flags, String paramName) {
  if ((flags & 2u) != 0) {
    return;
  }
  for (Int32 i = 0; i < count; i++) {
    Char c = *(s + i);
    if (c <= u'\x001f' || c == u'\x007f') {
      rt::throw_exception<ArgumentException>(SR::get_Argument_IdnIllegalName(), paramName);
    }
  }
}

String IdnMapping___::NlsGetAsciiCore(String unicodeString, Char* unicode, Int32 count) {
  UInt32 nlsFlags = get_NlsFlags();
  Int32 num = Interop::Normaliz::IdnToAscii(nlsFlags, unicode, count, nullptr, 0);
  if (num == 0) {
    ThrowForZeroLength(true);
  }
  if (num < 512) {
    Char as[num] = {};
    Char* output = as;
    return NlsGetAsciiCore(unicodeString, unicode, count, nlsFlags, output, num);
  }
  Array<Char> array = rt::newarr<Array<Char>>(num);
  {
    Char* output2 = rt::fixed(&array[0]);
    return NlsGetAsciiCore(unicodeString, unicode, count, nlsFlags, output2, num);
  }
}

String IdnMapping___::NlsGetAsciiCore(String unicodeString, Char* unicode, Int32 count, UInt32 flags, Char* output, Int32 outputLength) {
  Int32 num = Interop::Normaliz::IdnToAscii(flags, unicode, count, output, outputLength);
  if (num == 0) {
    ThrowForZeroLength(true);
  }
  return GetStringForOutput(unicodeString, unicode, count, output, num);
}

String IdnMapping___::NlsGetUnicodeCore(String asciiString, Char* ascii, Int32 count) {
  UInt32 nlsFlags = get_NlsFlags();
  Int32 num = Interop::Normaliz::IdnToUnicode(nlsFlags, ascii, count, nullptr, 0);
  if (num == 0) {
    ThrowForZeroLength(false);
  }
  if (num < 512) {
    Char as[num] = {};
    Char* output = as;
    return NlsGetUnicodeCore(asciiString, ascii, count, nlsFlags, output, num);
  }
  Array<Char> array = rt::newarr<Array<Char>>(num);
  {
    Char* output2 = rt::fixed(&array[0]);
    return NlsGetUnicodeCore(asciiString, ascii, count, nlsFlags, output2, num);
  }
}

String IdnMapping___::NlsGetUnicodeCore(String asciiString, Char* ascii, Int32 count, UInt32 flags, Char* output, Int32 outputLength) {
  Int32 num = Interop::Normaliz::IdnToUnicode(flags, ascii, count, output, outputLength);
  if (num == 0) {
    ThrowForZeroLength(false);
  }
  return GetStringForOutput(asciiString, ascii, count, output, num);
}

void IdnMapping___::ThrowForZeroLength(Boolean unicode) {
  Int32 lastWin32Error = Marshal::GetLastWin32Error();
  rt::throw_exception<ArgumentException>((lastWin32Error == 123) ? SR::get_Argument_IdnIllegalName() : (unicode ? SR::get_Argument_InvalidCharSequenceNoIndex() : SR::get_Argument_IdnBadPunycode()), unicode ? "unicode" : "ascii");
}

void IdnMapping___::cctor() {
  s_dotSeparators = rt::newarr<Array<Char>>(4);
}

} // namespace System::Private::CoreLib::System::Globalization::IdnMappingNamespace
