#include "TimeSpanParse-dep.h"

#include <System.Private.CoreLib/System/Globalization/TimeSpanParse-dep.h>

namespace System::Private::CoreLib::System::Globalization::TimeSpanParseNamespace {
Boolean TimeSpanParse::TimeSpanToken::NormalizeAndValidateFraction() {
  return Boolean();
};

Boolean TimeSpanParse::TimeSpanResult::SetNoFormatSpecifierFailure() {
  return Boolean();
};

Boolean TimeSpanParse::TimeSpanResult::SetBadQuoteFailure(Char failingCharacter) {
  return Boolean();
};

Boolean TimeSpanParse::TimeSpanResult::SetInvalidStringFailure() {
  return Boolean();
};

Boolean TimeSpanParse::TimeSpanResult::SetArgumentNullFailure(String argumentName) {
  return Boolean();
};

Boolean TimeSpanParse::TimeSpanResult::SetOverflowFailure() {
  return Boolean();
};

Boolean TimeSpanParse::TimeSpanResult::SetBadTimeSpanFailure() {
  return Boolean();
};

Boolean TimeSpanParse::TimeSpanResult::SetBadFormatSpecifierFailure(Nullable<Char> formatSpecifierCharacter) {
  return Boolean();
};

Boolean TimeSpanParse::TimeSpanTokenizer::get_EOL() {
  return Boolean();
};

Char TimeSpanParse::TimeSpanTokenizer::get_NextChar() {
  return Char();
};

TimeSpanParse::TimeSpanToken TimeSpanParse::TimeSpanTokenizer::GetNextToken() {
  return TimeSpanParse::TimeSpanToken();
};

void TimeSpanParse::TimeSpanTokenizer::BackOne() {
};

TimeSpanFormat::FormatLiterals TimeSpanParse::TimeSpanRawInfo::get_PositiveLocalized() {
  return TimeSpanFormat::FormatLiterals();
};

TimeSpanFormat::FormatLiterals TimeSpanParse::TimeSpanRawInfo::get_NegativeLocalized() {
  return TimeSpanFormat::FormatLiterals();
};

Boolean TimeSpanParse::TimeSpanRawInfo::FullAppCompatMatch(TimeSpanFormat::FormatLiterals pattern) {
  return Boolean();
};

Boolean TimeSpanParse::TimeSpanRawInfo::PartialAppCompatMatch(TimeSpanFormat::FormatLiterals pattern) {
  return Boolean();
};

Boolean TimeSpanParse::TimeSpanRawInfo::FullMatch(TimeSpanFormat::FormatLiterals pattern) {
  return Boolean();
};

Boolean TimeSpanParse::TimeSpanRawInfo::FullDMatch(TimeSpanFormat::FormatLiterals pattern) {
  return Boolean();
};

Boolean TimeSpanParse::TimeSpanRawInfo::FullHMMatch(TimeSpanFormat::FormatLiterals pattern) {
  return Boolean();
};

Boolean TimeSpanParse::TimeSpanRawInfo::FullDHMMatch(TimeSpanFormat::FormatLiterals pattern) {
  return Boolean();
};

Boolean TimeSpanParse::TimeSpanRawInfo::FullHMSMatch(TimeSpanFormat::FormatLiterals pattern) {
  return Boolean();
};

Boolean TimeSpanParse::TimeSpanRawInfo::FullDHMSMatch(TimeSpanFormat::FormatLiterals pattern) {
  return Boolean();
};

Boolean TimeSpanParse::TimeSpanRawInfo::FullHMSFMatch(TimeSpanFormat::FormatLiterals pattern) {
  return Boolean();
};

void TimeSpanParse::TimeSpanRawInfo::Init(DateTimeFormatInfo dtfi) {
};

Boolean TimeSpanParse::TimeSpanRawInfo::ProcessToken(TimeSpanToken& tok, TimeSpanResult& result) {
  return Boolean();
};

Boolean TimeSpanParse::TimeSpanRawInfo::AddSep(ReadOnlySpan<Char> sep, TimeSpanResult& result) {
  return Boolean();
};

Boolean TimeSpanParse::TimeSpanRawInfo::AddNum(TimeSpanToken num, TimeSpanResult& result) {
  return Boolean();
};

void TimeSpanParse::StringParser::NextChar() {
};

Char TimeSpanParse::StringParser::NextNonDigit() {
  return Char();
};

Boolean TimeSpanParse::StringParser::TryParse(ReadOnlySpan<Char> input, TimeSpanResult& result) {
  return Boolean();
};

Boolean TimeSpanParse::StringParser::ParseInt(Int32 max, Int32& i, TimeSpanResult& result) {
  return Boolean();
};

Boolean TimeSpanParse::StringParser::ParseTime(Int64& time, TimeSpanResult& result) {
  return Boolean();
};

void TimeSpanParse::StringParser::SkipBlanks() {
};

Int64 TimeSpanParse::Pow10(Int32 pow) {
  return Int64();
};

Boolean TimeSpanParse::TryTimeToTicks(Boolean positive, TimeSpanToken days, TimeSpanToken hours, TimeSpanToken minutes, TimeSpanToken seconds, TimeSpanToken fraction, Int64& result) {
  return Boolean();
};

TimeSpan TimeSpanParse::Parse(ReadOnlySpan<Char> input, IFormatProvider formatProvider) {
  return TimeSpan();
};

Boolean TimeSpanParse::TryParse(ReadOnlySpan<Char> input, IFormatProvider formatProvider, TimeSpan& result) {
  return Boolean();
};

TimeSpan TimeSpanParse::ParseExact(ReadOnlySpan<Char> input, ReadOnlySpan<Char> format, IFormatProvider formatProvider, TimeSpanStyles styles) {
  return TimeSpan();
};

Boolean TimeSpanParse::TryParseExact(ReadOnlySpan<Char> input, ReadOnlySpan<Char> format, IFormatProvider formatProvider, TimeSpanStyles styles, TimeSpan& result) {
  return Boolean();
};

TimeSpan TimeSpanParse::ParseExactMultiple(ReadOnlySpan<Char> input, Array<String> formats, IFormatProvider formatProvider, TimeSpanStyles styles) {
  return TimeSpan();
};

Boolean TimeSpanParse::TryParseExactMultiple(ReadOnlySpan<Char> input, Array<String> formats, IFormatProvider formatProvider, TimeSpanStyles styles, TimeSpan& result) {
  return Boolean();
};

Boolean TimeSpanParse::TryParseTimeSpan(ReadOnlySpan<Char> input, TimeSpanStandardStyles style, IFormatProvider formatProvider, TimeSpanResult& result) {
  return Boolean();
};

Boolean TimeSpanParse::ProcessTerminalState(TimeSpanRawInfo& raw, TimeSpanStandardStyles style, TimeSpanResult& result) {
  return Boolean();
};

Boolean TimeSpanParse::ProcessTerminal_DHMSF(TimeSpanRawInfo& raw, TimeSpanStandardStyles style, TimeSpanResult& result) {
  return Boolean();
};

Boolean TimeSpanParse::ProcessTerminal_HMS_F_D(TimeSpanRawInfo& raw, TimeSpanStandardStyles style, TimeSpanResult& result) {
  return Boolean();
};

Boolean TimeSpanParse::ProcessTerminal_HM_S_D(TimeSpanRawInfo& raw, TimeSpanStandardStyles style, TimeSpanResult& result) {
  return Boolean();
};

Boolean TimeSpanParse::ProcessTerminal_HM(TimeSpanRawInfo& raw, TimeSpanStandardStyles style, TimeSpanResult& result) {
  return Boolean();
};

Boolean TimeSpanParse::ProcessTerminal_D(TimeSpanRawInfo& raw, TimeSpanStandardStyles style, TimeSpanResult& result) {
  return Boolean();
};

Boolean TimeSpanParse::TryParseExactTimeSpan(ReadOnlySpan<Char> input, ReadOnlySpan<Char> format, IFormatProvider formatProvider, TimeSpanStyles styles, TimeSpanResult& result) {
  return Boolean();
};

Boolean TimeSpanParse::TryParseByFormat(ReadOnlySpan<Char> input, ReadOnlySpan<Char> format, TimeSpanStyles styles, TimeSpanResult& result) {
  return Boolean();
};

Boolean TimeSpanParse::ParseExactDigits(TimeSpanTokenizer& tokenizer, Int32 minDigitLength, Int32& result) {
  return Boolean();
};

Boolean TimeSpanParse::ParseExactDigits(TimeSpanTokenizer& tokenizer, Int32 minDigitLength, Int32 maxDigitLength, Int32& zeroes, Int32& result) {
  return Boolean();
};

Boolean TimeSpanParse::ParseExactLiteral(TimeSpanTokenizer& tokenizer, StringBuilder enquotedString) {
  return Boolean();
};

Boolean TimeSpanParse::TryParseTimeSpanConstant(ReadOnlySpan<Char> input, TimeSpanResult& result) {
  return Boolean();
};

Boolean TimeSpanParse::TryParseExactMultipleTimeSpan(ReadOnlySpan<Char> input, Array<String> formats, IFormatProvider formatProvider, TimeSpanStyles styles, TimeSpanResult& result) {
  return Boolean();
};

} // namespace System::Private::CoreLib::System::Globalization::TimeSpanParseNamespace
