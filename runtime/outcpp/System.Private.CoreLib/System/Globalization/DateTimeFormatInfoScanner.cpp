#include "DateTimeFormatInfoScanner-dep.h"

#include <System.Private.CoreLib/System/Char-dep.h>
#include <System.Private.CoreLib/System/Collections/Generic/List-dep.h>
#include <System.Private.CoreLib/System/Globalization/DateTimeFormatInfoScanner-dep.h>
#include <System.Private.CoreLib/System/Text/StringBuilder-dep.h>

namespace System::Private::CoreLib::System::Globalization::DateTimeFormatInfoScannerNamespace {
using namespace System::Collections::Generic;
using namespace System::Text;

Int32 DateTimeFormatInfoScanner___::SkipWhiteSpacesAndNonLetter(String pattern, Int32 currentIndex) {
  while (currentIndex < pattern->get_Length()) {
    Char c = pattern[currentIndex];
    if (c == 92) {
      currentIndex++;
      if (currentIndex >= pattern->get_Length()) {
        break;
      }
      c = pattern[currentIndex];
      if (c == 39) {
        continue;
      }
    }
    if (Char::IsLetter(c) || c == 39 || c == 46) {
      break;
    }
    currentIndex++;
  }
  return currentIndex;
}

void DateTimeFormatInfoScanner___::AddDateWordOrPostfix(String formatPostfix, String str) {
  if (str->get_Length() == 0) {
    return;
  }
  if (str->get_Length() == 1) {
    switch (str[0].get()) {
      case 45:
      case 47:
      case 20998:
      case 24180:
      case 26085:
      case 26102:
      case 26178:
      case 26376:
      case 31186:
      case 45380:
      case 48516:
      case 49884:
      case 50900:
      case 51068:
      case 52488:
        return;
      case 46:
        AddIgnorableSymbols(".");
        return;
    }
  }
  if (m_dateWords == nullptr) {
    m_dateWords = rt::newobj<List<String>>();
  }
  if (formatPostfix == "MMMM") {
    String item = "" + str;
    if (!m_dateWords->Contains(item)) {
      m_dateWords->Add(item);
    }
    return;
  }
  if (!m_dateWords->Contains(str)) {
    m_dateWords->Add(str);
  }
}

Int32 DateTimeFormatInfoScanner___::AddDateWords(String pattern, Int32 index, String formatPostfix) {
  Int32 num = SkipWhiteSpacesAndNonLetter(pattern, index);
  if (num != index && formatPostfix != nullptr) {
    formatPostfix = nullptr;
  }
  index = num;
  StringBuilder stringBuilder = rt::newobj<StringBuilder>();
  while (index < pattern->get_Length()) {
    Char c = pattern[index];
    switch (c.get()) {
      case 39:
        break;
      case 92:
        index++;
        if (index < pattern->get_Length()) {
          stringBuilder->Append(pattern[index]);
          index++;
        }
        continue;
      default:
        if (Char::IsWhiteSpace(c)) {
          AddDateWordOrPostfix(formatPostfix, stringBuilder->ToString());
          if (formatPostfix != nullptr) {
            formatPostfix = nullptr;
          }
          stringBuilder->set_Length(0);
          index++;
        } else {
          stringBuilder->Append(c);
          index++;
        }
        continue;
    }
    AddDateWordOrPostfix(formatPostfix, stringBuilder->ToString());
    index++;
    break;
  }
  return index;
}

Int32 DateTimeFormatInfoScanner___::ScanRepeatChar(String pattern, Char ch, Int32 index, Int32& count) {
  count = 1;
  while (++index < pattern->get_Length() && pattern[index] == ch) {
    count++;
  }
  return index;
}

void DateTimeFormatInfoScanner___::AddIgnorableSymbols(String text) {
  if (m_dateWords == nullptr) {
    m_dateWords = rt::newobj<List<String>>();
  }
  String item = "" + text;
  if (!m_dateWords->Contains(item)) {
    m_dateWords->Add(item);
  }
}

void DateTimeFormatInfoScanner___::ScanDateWord(String pattern) {
  _ymdFlags = FoundDatePattern::None;
  Int32 num = 0;
  while (num < pattern->get_Length()) {
    Char c = pattern[num];
    Int32 count;
    switch (c.get()) {
      case 39:
        num = AddDateWords(pattern, num + 1, nullptr);
        break;
      case 77:
        num = ScanRepeatChar(pattern, 77, num, count);
        if (count >= 4 && num < pattern->get_Length() && pattern[num] == 39) {
          num = AddDateWords(pattern, num + 1, "MMMM");
        }
        _ymdFlags |= FoundDatePattern::FoundMonthPatternFlag;
        break;
      case 121:
        {
          Int32 count2;
          num = ScanRepeatChar(pattern, 121, num, count2);
          _ymdFlags |= FoundDatePattern::FoundYearPatternFlag;
          break;
        }case 100:
        num = ScanRepeatChar(pattern, 100, num, count);
        if (count <= 2) {
          _ymdFlags |= FoundDatePattern::FoundDayPatternFlag;
        }
        break;
      case 92:
        num += 2;
        break;
      case 46:
        if (_ymdFlags == FoundDatePattern::FoundYMDPatternFlag) {
          AddIgnorableSymbols(".");
          _ymdFlags = FoundDatePattern::None;
        }
        num++;
        break;
      default:
        if (_ymdFlags == FoundDatePattern::FoundYMDPatternFlag && !Char::IsWhiteSpace(c)) {
          _ymdFlags = FoundDatePattern::None;
        }
        num++;
        break;
    }
  }
}

Array<String> DateTimeFormatInfoScanner___::GetDateWordsOfDTFI(DateTimeFormatInfo dtfi) {
  Array<String> allDateTimePatterns = dtfi->GetAllDateTimePatterns(68);
  for (Int32 i = 0; i < allDateTimePatterns->get_Length(); i++) {
    ScanDateWord(allDateTimePatterns[i]);
  }
  allDateTimePatterns = dtfi->GetAllDateTimePatterns(100);
  for (Int32 i = 0; i < allDateTimePatterns->get_Length(); i++) {
    ScanDateWord(allDateTimePatterns[i]);
  }
  allDateTimePatterns = dtfi->GetAllDateTimePatterns(121);
  for (Int32 i = 0; i < allDateTimePatterns->get_Length(); i++) {
    ScanDateWord(allDateTimePatterns[i]);
  }
  ScanDateWord(dtfi->get_MonthDayPattern());
  allDateTimePatterns = dtfi->GetAllDateTimePatterns(84);
  for (Int32 i = 0; i < allDateTimePatterns->get_Length(); i++) {
    ScanDateWord(allDateTimePatterns[i]);
  }
  allDateTimePatterns = dtfi->GetAllDateTimePatterns(116);
  for (Int32 i = 0; i < allDateTimePatterns->get_Length(); i++) {
    ScanDateWord(allDateTimePatterns[i]);
  }
  Array<String> array = nullptr;
  if (m_dateWords != nullptr && m_dateWords->get_Count() > 0) {
    array = rt::newarr<Array<String>>(m_dateWords->get_Count());
    for (Int32 i = 0; i < m_dateWords->get_Count(); i++) {
      array[i] = m_dateWords[i];
    }
  }
  return array;
}

FORMATFLAGS DateTimeFormatInfoScanner___::GetFormatFlagGenitiveMonth(Array<String> monthNames, Array<String> genitveMonthNames, Array<String> abbrevMonthNames, Array<String> genetiveAbbrevMonthNames) {
  if (EqualStringArrays(monthNames, genitveMonthNames) && EqualStringArrays(abbrevMonthNames, genetiveAbbrevMonthNames)) {
    return FORMATFLAGS::None;
  }
  return FORMATFLAGS::UseGenitiveMonth;
}

FORMATFLAGS DateTimeFormatInfoScanner___::GetFormatFlagUseSpaceInMonthNames(Array<String> monthNames, Array<String> genitveMonthNames, Array<String> abbrevMonthNames, Array<String> genetiveAbbrevMonthNames) {
  FORMATFLAGS fORMATFLAGS = FORMATFLAGS::None;
  fORMATFLAGS = (FORMATFLAGS)((Int32)fORMATFLAGS | ((ArrayElementsBeginWithDigit(monthNames) || ArrayElementsBeginWithDigit(genitveMonthNames) || ArrayElementsBeginWithDigit(abbrevMonthNames) || ArrayElementsBeginWithDigit(genetiveAbbrevMonthNames)) ? 32 : 0));
  return (FORMATFLAGS)((Int32)fORMATFLAGS | ((ArrayElementsHaveSpace(monthNames) || ArrayElementsHaveSpace(genitveMonthNames) || ArrayElementsHaveSpace(abbrevMonthNames) || ArrayElementsHaveSpace(genetiveAbbrevMonthNames)) ? 4 : 0));
}

FORMATFLAGS DateTimeFormatInfoScanner___::GetFormatFlagUseSpaceInDayNames(Array<String> dayNames, Array<String> abbrevDayNames) {
  if (!ArrayElementsHaveSpace(dayNames) && !ArrayElementsHaveSpace(abbrevDayNames)) {
    return FORMATFLAGS::None;
  }
  return FORMATFLAGS::UseSpacesInDayNames;
}

FORMATFLAGS DateTimeFormatInfoScanner___::GetFormatFlagUseHebrewCalendar(Int32 calID) {
  if (calID != 8) {
    return FORMATFLAGS::None;
  }
  return (FORMATFLAGS)10;
}

Boolean DateTimeFormatInfoScanner___::EqualStringArrays(Array<String> array1, Array<String> array2) {
  if (array1 == array2) {
    return true;
  }
  if (array1->get_Length() != array2->get_Length()) {
    return false;
  }
  for (Int32 i = 0; i < array1->get_Length(); i++) {
    if (array1[i] != array2[i]) {
      return false;
    }
  }
  return true;
}

Boolean DateTimeFormatInfoScanner___::ArrayElementsHaveSpace(Array<String> array) {
  for (Int32 i = 0; i < array->get_Length(); i++) {
    for (Int32 j = 0; j < array[i]->get_Length(); j++) {
      if (Char::IsWhiteSpace(array[i][j])) {
        return true;
      }
    }
  }
  return false;
}

Boolean DateTimeFormatInfoScanner___::ArrayElementsBeginWithDigit(Array<String> array) {
  for (Int32 i = 0; i < array->get_Length(); i++) {
    if (array[i]->get_Length() <= 0 || array[i][0] < 48 || array[i][0] > 57) {
      continue;
    }
    Int32 j;
    for (j = 1; j < array[i]->get_Length() && array[i][j] >= 48 && array[i][j] <= 57; j++) {
    }
    if (j == array[i]->get_Length()) {
      return false;
    }
    if (j == array[i]->get_Length() - 1) {
      Char c = array[i][j];
      if (c == 26376 || c == 50900) {
        return false;
      }
    }
    if (j == array[i]->get_Length() - 4 && array[i][j] == 39 && array[i][j + 1] == 32 && array[i][j + 2] == 26376 && array[i][j + 3] == 39) {
      return false;
    }
    return true;
  }
  return false;
}

void DateTimeFormatInfoScanner___::ctor() {
  m_dateWords = rt::newobj<List<String>>();
  Object::in::ctor();
}

} // namespace System::Private::CoreLib::System::Globalization::DateTimeFormatInfoScannerNamespace
