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
    if (c == u'\\') {
      currentIndex++;
      if (currentIndex >= pattern->get_Length()) {
        break;
      }
      c = pattern[currentIndex];
      if (c == u'\'') {
        continue;
      }
    }
    if (Char::IsLetter(c) || c == u'\'' || c == u'.') {
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
      case u'.':
        AddIgnorableSymbols(".");
        return;
      case u'-':
      case u'/':
      case u'分':
      case u'年':
      case u'日':
      case u'时':
      case u'時':
      case u'月':
      case u'秒':
      case u'년':
      case u'분':
      case u'시':
      case u'월':
      case u'일':
      case u'초':
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
  Int32 index = str->get_Length() - 1;
  if (str[index] == u'.') {
    Int32 length = str->get_Length();
    index = 0;
    Int32 length2 = length - 1 - index;
    String item2 = str->Substring(index, length2);
    if (!m_dateWords->Contains(item2)) {
      m_dateWords->Add(item2);
    }
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
      case u'\'':
        break;
      case u'\\':
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
      case u'\'':
        num = AddDateWords(pattern, num + 1, nullptr);
        break;
      case u'M':
        num = ScanRepeatChar(pattern, u'M', num, count);
        if (count >= 4 && num < pattern->get_Length() && pattern[num] == u'\'') {
          num = AddDateWords(pattern, num + 1, "MMMM");
        }
        _ymdFlags |= FoundDatePattern::FoundMonthPatternFlag;
        break;
      case u'y':
        {
          Int32 count2;
          num = ScanRepeatChar(pattern, u'y', num, count2);
          _ymdFlags |= FoundDatePattern::FoundYearPatternFlag;
          break;
        }case u'd':
        num = ScanRepeatChar(pattern, u'd', num, count);
        if (count <= 2) {
          _ymdFlags |= FoundDatePattern::FoundDayPatternFlag;
        }
        break;
      case u'\\':
        num += 2;
        break;
      case u'.':
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
  Array<String> allDateTimePatterns = dtfi->GetAllDateTimePatterns(u'D');
  for (Int32 i = 0; i < allDateTimePatterns->get_Length(); i++) {
    ScanDateWord(allDateTimePatterns[i]);
  }
  allDateTimePatterns = dtfi->GetAllDateTimePatterns(u'd');
  for (Int32 i = 0; i < allDateTimePatterns->get_Length(); i++) {
    ScanDateWord(allDateTimePatterns[i]);
  }
  allDateTimePatterns = dtfi->GetAllDateTimePatterns(u'y');
  for (Int32 i = 0; i < allDateTimePatterns->get_Length(); i++) {
    ScanDateWord(allDateTimePatterns[i]);
  }
  ScanDateWord(dtfi->get_MonthDayPattern());
  allDateTimePatterns = dtfi->GetAllDateTimePatterns(u'T');
  for (Int32 i = 0; i < allDateTimePatterns->get_Length(); i++) {
    ScanDateWord(allDateTimePatterns[i]);
  }
  allDateTimePatterns = dtfi->GetAllDateTimePatterns(u't');
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
  fORMATFLAGS |= ((ArrayElementsBeginWithDigit(monthNames) || ArrayElementsBeginWithDigit(genitveMonthNames) || ArrayElementsBeginWithDigit(abbrevMonthNames) || ArrayElementsBeginWithDigit(genetiveAbbrevMonthNames)) ? FORMATFLAGS::UseDigitPrefixInTokens : FORMATFLAGS::None);
  return fORMATFLAGS | ((ArrayElementsHaveSpace(monthNames) || ArrayElementsHaveSpace(genitveMonthNames) || ArrayElementsHaveSpace(abbrevMonthNames) || ArrayElementsHaveSpace(genetiveAbbrevMonthNames)) ? FORMATFLAGS::UseSpacesInMonthNames : FORMATFLAGS::None);
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
    if (array[i]->get_Length() <= 0 || array[i][0] < u'0' || array[i][0] > u'9') {
      continue;
    }
    Int32 j;
    for (j = 1; j < array[i]->get_Length() && array[i][j] >= u'0' && array[i][j] <= u'9'; j++) {
    }
    if (j == array[i]->get_Length()) {
      return false;
    }
    if (j == array[i]->get_Length() - 1) {
      Char c = array[i][j];
      if (c == u'月' || c == u'월') {
        return false;
      }
    }
    if (j == array[i]->get_Length() - 4 && array[i][j] == u'\'' && array[i][j + 1] == u' ' && array[i][j + 2] == u'月' && array[i][j + 3] == u'\'') {
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
