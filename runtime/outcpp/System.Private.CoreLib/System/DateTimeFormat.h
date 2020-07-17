#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Text {
FORWARD(StringBuilder)
} // namespace System::Private::CoreLib::System::Text
namespace System::Private::CoreLib::System::Globalization {
FORWARD(DateTimeFormatInfo)
} // namespace System::Private::CoreLib::System::Globalization
namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
FORWARDS(Char)
FORWARDS(DateTime)
FORWARD(IFormatProvider)
FORWARDS(Int32)
FORWARDS(ReadOnlySpan, T)
FORWARDS(Span, T)
FORWARD(String)
FORWARDS(TimeSpan)
FORWARDS(UInt32)
FORWARDS(UInt64)
namespace DateTimeFormatNamespace {
using namespace Globalization;
using namespace Text;
class DateTimeFormat {
  public: static void FormatDigits(StringBuilder outputBuffer, Int32 value, Int32 len);
  public: static void FormatDigits(StringBuilder outputBuffer, Int32 value, Int32 len, Boolean overrideLengthLimit);
  private: static void HebrewFormatDigits(StringBuilder outputBuffer, Int32 digits);
  public: static Int32 ParseRepeatPattern(ReadOnlySpan<Char> format, Int32 pos, Char patternChar);
  private: static String FormatDayOfWeek(Int32 dayOfWeek, Int32 repeat, DateTimeFormatInfo dtfi);
  private: static String FormatMonth(Int32 month, Int32 repeatCount, DateTimeFormatInfo dtfi);
  private: static String FormatHebrewMonthName(DateTime time, Int32 month, Int32 repeatCount, DateTimeFormatInfo dtfi);
  public: static Int32 ParseQuoteString(ReadOnlySpan<Char> format, Int32 pos, StringBuilder result);
  public: static Int32 ParseNextChar(ReadOnlySpan<Char> format, Int32 pos);
  private: static Boolean IsUseGenitiveForm(ReadOnlySpan<Char> format, Int32 index, Int32 tokenLen, Char patternToMatch);
  private: static StringBuilder FormatCustomized(DateTime dateTime, ReadOnlySpan<Char> format, DateTimeFormatInfo dtfi, TimeSpan offset, StringBuilder result);
  private: static void FormatCustomizedTimeZone(DateTime dateTime, TimeSpan offset, Int32 tokenLen, Boolean timeOnly, StringBuilder result);
  private: static void FormatCustomizedRoundripTimeZone(DateTime dateTime, TimeSpan offset, StringBuilder result);
  private: static void Append2DigitNumber(StringBuilder result, Int32 val);
  public: static String GetRealFormat(ReadOnlySpan<Char> format, DateTimeFormatInfo dtfi);
  private: static String ExpandPredefinedFormat(ReadOnlySpan<Char> format, DateTime& dateTime, DateTimeFormatInfo& dtfi, TimeSpan offset);
  public: static String Format(DateTime dateTime, String format, IFormatProvider provider);
  public: static String Format(DateTime dateTime, String format, IFormatProvider provider, TimeSpan offset);
  public: static Boolean TryFormat(DateTime dateTime, Span<Char> destination, Int32& charsWritten, ReadOnlySpan<Char> format, IFormatProvider provider);
  public: static Boolean TryFormat(DateTime dateTime, Span<Char> destination, Int32& charsWritten, ReadOnlySpan<Char> format, IFormatProvider provider, TimeSpan offset);
  private: static StringBuilder FormatStringBuilder(DateTime dateTime, ReadOnlySpan<Char> format, DateTimeFormatInfo dtfi, TimeSpan offset);
  private: static Boolean TryFormatO(DateTime dateTime, TimeSpan offset, Span<Char> destination, Int32& charsWritten);
  private: static Boolean TryFormatR(DateTime dateTime, TimeSpan offset, Span<Char> destination, Int32& charsWritten);
  private: static void WriteTwoDecimalDigits(UInt32 value, Span<Char> destination, Int32 offset);
  private: static void WriteFourDecimalDigits(UInt32 value, Span<Char> buffer, Int32 startingIndex);
  private: static void WriteDigits(UInt64 value, Span<Char> buffer);
  public: static Array<String> GetAllDateTimes(DateTime dateTime, Char format, DateTimeFormatInfo dtfi);
  public: static Array<String> GetAllDateTimes(DateTime dateTime, DateTimeFormatInfo dtfi);
  private: static void SCtor();
  public: static Array<Char> allStandardFormats;
  public: static DateTimeFormatInfo InvariantFormatInfo;
  public: static Array<String> InvariantAbbreviatedMonthNames;
  public: static Array<String> InvariantAbbreviatedDayNames;
  public: static Array<String> fixedNumberFormats;
};
} // namespace DateTimeFormatNamespace
using DateTimeFormat = DateTimeFormatNamespace::DateTimeFormat;
} // namespace System::Private::CoreLib::System
