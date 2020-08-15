#include "TextInfo-dep.h"

#include <System.Private.CoreLib/Interop-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/Byte-dep.h>
#include <System.Private.CoreLib/System/Globalization/CharUnicodeInfo-dep.h>
#include <System.Private.CoreLib/System/Globalization/CompareInfo-dep.h>
#include <System.Private.CoreLib/System/Globalization/CompareOptions.h>
#include <System.Private.CoreLib/System/Globalization/CultureInfo-dep.h>
#include <System.Private.CoreLib/System/Globalization/GlobalizationMode-dep.h>
#include <System.Private.CoreLib/System/Globalization/TextInfo-dep.h>
#include <System.Private.CoreLib/System/Globalization/UnicodeCategory.h>
#include <System.Private.CoreLib/System/IntPtr-dep.h>
#include <System.Private.CoreLib/System/InvalidOperationException-dep.h>
#include <System.Private.CoreLib/System/MemoryExtensions-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/MemoryMarshal-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/StringComparison.h>
#include <System.Private.CoreLib/System/Text/StringBuilder-dep.h>
#include <System.Private.CoreLib/System/Text/UnicodeUtility-dep.h>
#include <System.Private.CoreLib/System/UInt32-dep.h>

namespace System::Private::CoreLib::System::Globalization::TextInfoNamespace {
using namespace System::Runtime::InteropServices;
using namespace System::Text;

Int32 TextInfo___::get_ANSICodePage() {
  return _cultureData->get_ANSICodePage();
}

Int32 TextInfo___::get_OEMCodePage() {
  return _cultureData->get_OEMCodePage();
}

Int32 TextInfo___::get_MacCodePage() {
  return _cultureData->get_MacCodePage();
}

Int32 TextInfo___::get_EBCDICCodePage() {
  return _cultureData->get_EBCDICCodePage();
}

Int32 TextInfo___::get_LCID() {
  return CultureInfo::in::GetCultureInfo(_textInfoName)->get_LCID();
}

String TextInfo___::get_CultureName() {
  return _textInfoName;
}

Boolean TextInfo___::get_IsReadOnly() {
  return _isReadOnly;
}

String TextInfo___::get_ListSeparator() {
  auto& default = _listSeparator;
  return default != nullptr ? default : (_listSeparator = _cultureData->get_ListSeparator());
}

void TextInfo___::set_ListSeparator(String value) {
  if (value == nullptr) {
    rt::throw_exception<ArgumentNullException>("value");
  }
  VerifyWritable();
  _listSeparator = value;
}

Boolean TextInfo___::get_IsAsciiCasingSameAsInvariant() {
  if (_isAsciiCasingSameAsInvariant == Tristate::NotInitialized) {
    PopulateIsAsciiCasingSameAsInvariant();
  }
  return _isAsciiCasingSameAsInvariant == Tristate::True;
}

Boolean TextInfo___::get_IsRightToLeft() {
  return _cultureData->get_IsRightToLeft();
}

Boolean TextInfo___::get_IsInvariant() {
  return _cultureName->get_Length() == 0;
}

void TextInfo___::ctor(CultureData cultureData) {
  _cultureData = cultureData;
  _cultureName = _cultureData->get_CultureName();
  _textInfoName = _cultureData->get_TextInfoName();
  if (GlobalizationMode::get_UseNls()) {
    _sortHandle = CompareInfo::in::NlsGetSortHandle(_textInfoName);
  }
}

void TextInfo___::ctor(CultureData cultureData, Boolean readOnly) {
  SetReadOnlyState(readOnly);
}

Object TextInfo___::Clone() {
  Object obj = MemberwiseClone();
  ((TextInfo)obj)->SetReadOnlyState(false);
  return obj;
}

TextInfo TextInfo___::ReadOnly(TextInfo textInfo) {
  if (textInfo == nullptr) {
    rt::throw_exception<ArgumentNullException>("textInfo");
  }
  if (textInfo->get_IsReadOnly()) {
    return textInfo;
  }
  TextInfo textInfo2 = (TextInfo)textInfo->MemberwiseClone();
  textInfo2->SetReadOnlyState(true);
  return textInfo2;
}

void TextInfo___::VerifyWritable() {
  if (_isReadOnly) {
    rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_ReadOnly());
  }
}

void TextInfo___::SetReadOnlyState(Boolean readOnly) {
  _isReadOnly = readOnly;
}

Char TextInfo___::ToLower(Char c) {
  if (GlobalizationMode::get_Invariant() || (UnicodeUtility::IsAsciiCodePoint(c) && get_IsAsciiCasingSameAsInvariant())) {
    return ToLowerAsciiInvariant(c);
  }
  return ChangeCase(c, false);
}

Char TextInfo___::ToLowerInvariant(Char c) {
  if (GlobalizationMode::get_Invariant() || UnicodeUtility::IsAsciiCodePoint(c)) {
    return ToLowerAsciiInvariant(c);
  }
  return Invariant->ChangeCase(c, false);
}

String TextInfo___::ToLower(String str) {
  if (str == nullptr) {
    rt::throw_exception<ArgumentNullException>("str");
  }
  if (GlobalizationMode::get_Invariant()) {
    return ToLowerAsciiInvariant(str);
  }
  return ChangeCaseCommon<ToLowerConversion>(str);
}

Char TextInfo___::ChangeCase(Char c, Boolean toUpper) {
  Char result = 0;
  ChangeCaseCore(&c, 1, &result, 1, toUpper);
  return result;
}

void TextInfo___::ChangeCaseToLower(ReadOnlySpan<Char> source, Span<Char> destination) {
  ChangeCaseCommon<ToLowerConversion>(MemoryMarshal::GetReference(source), MemoryMarshal::GetReference(destination), source.get_Length());
}

void TextInfo___::ChangeCaseToUpper(ReadOnlySpan<Char> source, Span<Char> destination) {
  ChangeCaseCommon<ToUpperConversion>(MemoryMarshal::GetReference(source), MemoryMarshal::GetReference(destination), source.get_Length());
}

String TextInfo___::ToLowerAsciiInvariant(String s) {
  if (s->get_Length() == 0) {
    return String::in::Empty;
  }
  {
    Char* ptr = s;
    Char* ptr2 = ptr;
    Int32 i;
    for (i = 0; i < s->get_Length() && (UInt32)(ptr2[i] - 65) > 25u; i++) {
    }
    if (i >= s->get_Length()) {
      return s;
    }
    String text = String::in::FastAllocateString(s->get_Length());
    {
      Char* ptr3 = text;
      Char* ptr4 = ptr3;
      for (Int32 j = 0; j < i; j++) {
        ptr4[j] = ptr2[j];
      }
      ptr4[i] = (Char)(ptr2[i] | 32);
      for (i++; i < s->get_Length(); i++) {
        ptr4[i] = ToLowerAsciiInvariant(ptr2[i]);
      }
    }
    return text;
  }
}

void TextInfo___::ToLowerAsciiInvariant(ReadOnlySpan<Char> source, Span<Char> destination) {
  for (Int32 i = 0; i < source.get_Length(); i++) {
    destination[i] = ToLowerAsciiInvariant(source[i]);
  }
}

String TextInfo___::ToUpperAsciiInvariant(String s) {
  if (s->get_Length() == 0) {
    return String::in::Empty;
  }
  {
    Char* ptr = s;
    Char* ptr2 = ptr;
    Int32 i;
    for (i = 0; i < s->get_Length() && (UInt32)(ptr2[i] - 97) > 25u; i++) {
    }
    if (i >= s->get_Length()) {
      return s;
    }
    String text = String::in::FastAllocateString(s->get_Length());
    {
      Char* ptr3 = text;
      Char* ptr4 = ptr3;
      for (Int32 j = 0; j < i; j++) {
        ptr4[j] = ptr2[j];
      }
      ptr4[i] = (Char)(ptr2[i] & -33);
      for (i++; i < s->get_Length(); i++) {
        ptr4[i] = ToUpperAsciiInvariant(ptr2[i]);
      }
    }
    return text;
  }
}

void TextInfo___::ToUpperAsciiInvariant(ReadOnlySpan<Char> source, Span<Char> destination) {
  for (Int32 i = 0; i < source.get_Length(); i++) {
    destination[i] = ToUpperAsciiInvariant(source[i]);
  }
}

Char TextInfo___::ToLowerAsciiInvariant(Char c) {
  if (UnicodeUtility::IsInRangeInclusive(c, 65u, 90u)) {
    c = (Char)(Byte)(c | 32);
  }
  return c;
}

Char TextInfo___::ToUpper(Char c) {
  if (GlobalizationMode::get_Invariant() || (UnicodeUtility::IsAsciiCodePoint(c) && get_IsAsciiCasingSameAsInvariant())) {
    return ToUpperAsciiInvariant(c);
  }
  return ChangeCase(c, true);
}

Char TextInfo___::ToUpperInvariant(Char c) {
  if (GlobalizationMode::get_Invariant() || UnicodeUtility::IsAsciiCodePoint(c)) {
    return ToUpperAsciiInvariant(c);
  }
  return Invariant->ChangeCase(c, true);
}

String TextInfo___::ToUpper(String str) {
  if (str == nullptr) {
    rt::throw_exception<ArgumentNullException>("str");
  }
  if (GlobalizationMode::get_Invariant()) {
    return ToUpperAsciiInvariant(str);
  }
  return ChangeCaseCommon<ToUpperConversion>(str);
}

Char TextInfo___::ToUpperAsciiInvariant(Char c) {
  if (UnicodeUtility::IsInRangeInclusive(c, 97u, 122u)) {
    c = (Char)(c & 95);
  }
  return c;
}

void TextInfo___::PopulateIsAsciiCasingSameAsInvariant() {
  Boolean flag = CultureInfo::in::GetCultureInfo(_textInfoName)->get_CompareInfo()->Compare("abcdefghijklmnopqrstuvwxyz", "ABCDEFGHIJKLMNOPQRSTUVWXYZ", CompareOptions::IgnoreCase) == 0;
  _isAsciiCasingSameAsInvariant = ((!flag) ? Tristate::False : Tristate::True);
}

Boolean TextInfo___::Equals(Object obj) {
  TextInfo textInfo = rt::as<TextInfo>(obj);
  if (textInfo != nullptr) {
    return get_CultureName()->Equals(textInfo->get_CultureName());
  }
  return false;
}

Int32 TextInfo___::GetHashCode() {
  return get_CultureName()->GetHashCode();
}

String TextInfo___::ToString() {
  return "TextInfo - " + _cultureData->get_CultureName();
}

String TextInfo___::ToTitleCase(String str) {
  if (str == nullptr) {
    rt::throw_exception<ArgumentNullException>("str");
  }
  if (str->get_Length() == 0) {
    return str;
  }
  StringBuilder result = rt::newobj<StringBuilder>();
  String text = nullptr;
  Boolean flag = get_CultureName()->StartsWith("nl-", StringComparison::OrdinalIgnoreCase);
  Int32 num;
  for (num = 0; num < str->get_Length(); num++) {
    Int32 charLength;
    UnicodeCategory unicodeCategoryInternal = CharUnicodeInfo::GetUnicodeCategoryInternal(str, num, charLength);
    if (Char::CheckLetter(unicodeCategoryInternal)) {
      if (flag && num < str->get_Length() - 1 && (str[num] == 105 || str[num] == 73) && (str[num + 1] == 106 || str[num + 1] == 74)) {
        result->Append("IJ");
        num += 2;
      } else {
        num = AddTitlecaseLetter(result, str, num, charLength) + 1;
      }
      Int32 num2 = num;
      Boolean flag2 = unicodeCategoryInternal == UnicodeCategory::LowercaseLetter;
      while (num < str->get_Length()) {
        unicodeCategoryInternal = CharUnicodeInfo::GetUnicodeCategoryInternal(str, num, charLength);
        if (IsLetterCategory(unicodeCategoryInternal)) {
          if (unicodeCategoryInternal == UnicodeCategory::LowercaseLetter) {
            flag2 = true;
          }
          num += charLength;
        } else if (str[num] == 39) {
          num++;
          if (flag2) {
            if (text == nullptr) {
              text = ToLower(str);
            }
            result->Append(text, num2, num - num2);
          } else {
            result->Append(str, num2, num - num2);
          }
          num2 = num;
          flag2 = true;
        } else {
          if (IsWordSeparator(unicodeCategoryInternal)) {
            break;
          }
          num += charLength;
        }

      }
      Int32 num3 = num - num2;
      if (num3 > 0) {
        if (flag2) {
          if (text == nullptr) {
            text = ToLower(str);
          }
          result->Append(text, num2, num3);
        } else {
          result->Append(str, num2, num3);
        }
      }
      if (num < str->get_Length()) {
        num = AddNonLetter(result, str, num, charLength);
      }
    } else {
      num = AddNonLetter(result, str, num, charLength);
    }
  }
  return result->ToString();
}

Int32 TextInfo___::AddNonLetter(StringBuilder& result, String& input, Int32 inputIndex, Int32 charLen) {
  if (charLen == 2) {
    result->Append(input[inputIndex++]);
    result->Append(input[inputIndex]);
  } else {
    result->Append(input[inputIndex]);
  }
  return inputIndex;
}

Int32 TextInfo___::AddTitlecaseLetter(StringBuilder& result, String& input, Int32 inputIndex, Int32 charLen) {
  if (charLen == 2) {
    ReadOnlySpan<Char> readOnlySpan = MemoryExtensions::AsSpan(input, inputIndex, 2);
    if (GlobalizationMode::get_Invariant()) {
      result->Append(readOnlySpan);
    } else {
      Char default[2] = {};
      Span<Char> span = default;
      ChangeCaseToUpper(readOnlySpan, span);
      result->Append(span);
    }
    inputIndex++;
  } else {
    switch (input[inputIndex].get()) {
      case 452:
      case 453:
      case 454:
        result->Append(453);
        break;
      case 455:
      case 456:
      case 457:
        result->Append(456);
        break;
      case 458:
      case 459:
      case 460:
        result->Append(459);
        break;
      case 497:
      case 498:
      case 499:
        result->Append(498);
        break;
      default:
        result->Append(ToUpper(input[inputIndex]));
        break;
    }
  }
  return inputIndex;
}

void TextInfo___::ChangeCaseCore(Char* src, Int32 srcLen, Char* dstBuffer, Int32 dstBufferCapacity, Boolean bToUpper) {
  if (GlobalizationMode::get_UseNls()) {
    NlsChangeCase(src, srcLen, dstBuffer, dstBufferCapacity, bToUpper);
  } else {
    IcuChangeCase(src, srcLen, dstBuffer, dstBufferCapacity, bToUpper);
  }
}

Boolean TextInfo___::IsWordSeparator(UnicodeCategory category) {
  return (536672256 & (1 << (Int32)category)) != 0;
}

Boolean TextInfo___::IsLetterCategory(UnicodeCategory uc) {
  if (uc != 0 && uc != UnicodeCategory::LowercaseLetter && uc != UnicodeCategory::TitlecaseLetter && uc != UnicodeCategory::ModifierLetter) {
    return uc == UnicodeCategory::OtherLetter;
  }
  return true;
}

Boolean TextInfo___::NeedsTurkishCasing(String localeName) {
  return CultureInfo::in::GetCultureInfo(localeName)->get_CompareInfo()->Compare("ı", "I", CompareOptions::IgnoreCase) == 0;
}

void TextInfo___::IcuChangeCase(Char* src, Int32 srcLen, Char* dstBuffer, Int32 dstBufferCapacity, Boolean bToUpper) {
  if (get_IsInvariant()) {
    Interop::Globalization::ChangeCaseInvariant(src, srcLen, dstBuffer, dstBufferCapacity, bToUpper);
    return;
  }
  if (_needsTurkishCasing == Tristate::NotInitialized) {
    _needsTurkishCasing = ((!NeedsTurkishCasing(_textInfoName)) ? Tristate::False : Tristate::True);
  }
  if (_needsTurkishCasing == Tristate::True) {
    Interop::Globalization::ChangeCaseTurkish(src, srcLen, dstBuffer, dstBufferCapacity, bToUpper);
  } else {
    Interop::Globalization::ChangeCase(src, srcLen, dstBuffer, dstBufferCapacity, bToUpper);
  }
}

void TextInfo___::NlsChangeCase(Char* pSource, Int32 pSourceLen, Char* pResult, Int32 pResultLen, Boolean toUpper) {
  UInt32 num = (!IsInvariantLocale(_textInfoName)) ? 16777216u : 0u;
  if (Interop::Kernel32::LCMapStringEx((_sortHandle != IntPtr::Zero) ? nullptr : _textInfoName, num | (UInt32)(toUpper ? 512 : 256), pSource, pSourceLen, pResult, pSourceLen, nullptr, nullptr, _sortHandle) == 0) {
    rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_ReadOnly());
  }
}

Boolean TextInfo___::IsInvariantLocale(String localeName) {
  return localeName == "";
}

void TextInfo___::cctor() {
  Invariant = rt::newobj<TextInfo>(CultureData::in::get_Invariant(), true);
}

} // namespace System::Private::CoreLib::System::Globalization::TextInfoNamespace
