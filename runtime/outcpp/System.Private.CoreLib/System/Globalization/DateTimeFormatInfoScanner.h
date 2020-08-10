#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
FORWARDS(Char)
FORWARDS(Int32)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(List, T)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System::Globalization {
enum class FORMATFLAGS;
FORWARD(DateTimeFormatInfo)
namespace DateTimeFormatInfoScannerNamespace {
using namespace Collections::Generic;
CLASS(DateTimeFormatInfoScanner) : public Object::in {
  private: enum class FoundDatePattern {
    None = 0,
    FoundYearPatternFlag = 1,
    FoundMonthPatternFlag = 2,
    FoundDayPatternFlag = 4,
    FoundYMDPatternFlag = 7,
  };
  public: static Int32 SkipWhiteSpacesAndNonLetter(String pattern, Int32 currentIndex);
  public: void AddDateWordOrPostfix(String formatPostfix, String str);
  public: Int32 AddDateWords(String pattern, Int32 index, String formatPostfix);
  public: static Int32 ScanRepeatChar(String pattern, Char ch, Int32 index, Int32& count);
  public: void AddIgnorableSymbols(String text);
  public: void ScanDateWord(String pattern);
  public: Array<String> GetDateWordsOfDTFI(DateTimeFormatInfo dtfi);
  public: static FORMATFLAGS GetFormatFlagGenitiveMonth(Array<String> monthNames, Array<String> genitveMonthNames, Array<String> abbrevMonthNames, Array<String> genetiveAbbrevMonthNames);
  public: static FORMATFLAGS GetFormatFlagUseSpaceInMonthNames(Array<String> monthNames, Array<String> genitveMonthNames, Array<String> abbrevMonthNames, Array<String> genetiveAbbrevMonthNames);
  public: static FORMATFLAGS GetFormatFlagUseSpaceInDayNames(Array<String> dayNames, Array<String> abbrevDayNames);
  public: static FORMATFLAGS GetFormatFlagUseHebrewCalendar(Int32 calID);
  private: static Boolean EqualStringArrays(Array<String> array1, Array<String> array2);
  private: static Boolean ArrayElementsHaveSpace(Array<String> array);
  private: static Boolean ArrayElementsBeginWithDigit(Array<String> array);
  public: void ctor();
  public: List<String> m_dateWords;
  private: FoundDatePattern _ymdFlags;
};
} // namespace DateTimeFormatInfoScannerNamespace
using DateTimeFormatInfoScanner = DateTimeFormatInfoScannerNamespace::DateTimeFormatInfoScanner;
} // namespace System::Private::CoreLib::System::Globalization
