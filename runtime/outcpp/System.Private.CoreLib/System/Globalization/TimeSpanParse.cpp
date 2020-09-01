#include "TimeSpanParse-dep.h"

#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/DateTimeFormat-dep.h>
#include <System.Private.CoreLib/System/DateTimeParse-dep.h>
#include <System.Private.CoreLib/System/Double-dep.h>
#include <System.Private.CoreLib/System/FormatException-dep.h>
#include <System.Private.CoreLib/System/Globalization/TimeSpanParse-dep.h>
#include <System.Private.CoreLib/System/Int64-dep.h>
#include <System.Private.CoreLib/System/Math-dep.h>
#include <System.Private.CoreLib/System/MemoryExtensions-dep.h>
#include <System.Private.CoreLib/System/MidpointRounding.h>
#include <System.Private.CoreLib/System/OverflowException-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/Text/StringBuilder-dep.h>
#include <System.Private.CoreLib/System/Text/StringBuilderCache-dep.h>
#include <System.Private.CoreLib/System/UInt16-dep.h>
#include <System.Private.CoreLib/System/UInt32-dep.h>

namespace System::Private::CoreLib::System::Globalization::TimeSpanParseNamespace {
using namespace System::Text;

TimeSpanParse::TimeSpanToken::TimeSpanToken(TTT type) {
}

TimeSpanParse::TimeSpanToken::TimeSpanToken(Int32 number) {
}

TimeSpanParse::TimeSpanToken::TimeSpanToken(Int32 number, Int32 leadingZeroes) {
}

TimeSpanParse::TimeSpanToken::TimeSpanToken(TTT type, Int32 number, Int32 leadingZeroes, ReadOnlySpan<Char> separator) {
  _ttt = type;
  _num = number;
  _zeroes = leadingZeroes;
  _sep = separator;
}

Boolean TimeSpanParse::TimeSpanToken::NormalizeAndValidateFraction() {
  if (_num == 0) {
    return true;
  }
  if (_zeroes == 0 && _num > 9999999) {
    return false;
  }
  Int32 num = (Int32)Math::Floor(Math::Log10(_num)) + 1 + _zeroes;
  if (num == 7) {
    return true;
  }
  if (num < 7) {
    _num *= (Int32)Pow10(7 - num);
    return true;
  }
  _num = (Int32)Math::Round((Double)_num / (Double)Pow10(num - 7), MidpointRounding::AwayFromZero);
  return true;
}

TimeSpanParse::TimeSpanResult::TimeSpanResult(Boolean throwOnFailure, ReadOnlySpan<Char> originalTimeSpanString) {
  parsedTimeSpan = rt::default__;
  _throwOnFailure = throwOnFailure;
  _originalTimeSpanString = originalTimeSpanString;
}

Boolean TimeSpanParse::TimeSpanResult::SetNoFormatSpecifierFailure() {
  if (!_throwOnFailure) {
    return false;
  }
  rt::throw_exception<FormatException>(SR::get_Format_NoFormatSpecifier());
}

Boolean TimeSpanParse::TimeSpanResult::SetBadQuoteFailure(Char failingCharacter) {
  if (!_throwOnFailure) {
    return false;
  }
  rt::throw_exception<FormatException>(SR::Format(SR::get_Format_BadQuote(), failingCharacter));
}

Boolean TimeSpanParse::TimeSpanResult::SetInvalidStringFailure() {
  if (!_throwOnFailure) {
    return false;
  }
  rt::throw_exception<FormatException>(SR::get_Format_InvalidString());
}

Boolean TimeSpanParse::TimeSpanResult::SetArgumentNullFailure(String argumentName) {
  if (!_throwOnFailure) {
    return false;
  }
  rt::throw_exception<ArgumentNullException>(argumentName, SR::get_ArgumentNull_String());
}

Boolean TimeSpanParse::TimeSpanResult::SetOverflowFailure() {
  if (!_throwOnFailure) {
    return false;
  }
  rt::throw_exception<OverflowException>(SR::Format(SR::get_Overflow_TimeSpanElementTooLarge(), rt::newobj<String>(_originalTimeSpanString)));
}

Boolean TimeSpanParse::TimeSpanResult::SetBadTimeSpanFailure() {
  if (!_throwOnFailure) {
    return false;
  }
  rt::throw_exception<FormatException>(SR::Format(SR::get_Format_BadTimeSpan(), rt::newobj<String>(_originalTimeSpanString)));
}

template <>
Boolean TimeSpanParse::TimeSpanResult::SetBadFormatSpecifierFailure(Nullable<Char> formatSpecifierCharacter) {
  if (!_throwOnFailure) {
    return false;
  }
  rt::throw_exception<FormatException>(SR::Format(SR::get_Format_BadFormatSpecifier(), formatSpecifierCharacter));
}

Boolean TimeSpanParse::TimeSpanTokenizer::get_EOL() {
  return _pos >= _value.get_Length() - 1;
}

Char TimeSpanParse::TimeSpanTokenizer::get_NextChar() {
  Int32 num = ++_pos;
  if ((UInt32)num >= (UInt32)_value.get_Length()) {
    return 0;
  }
  return _value[num];
}

TimeSpanParse::TimeSpanTokenizer::TimeSpanTokenizer(ReadOnlySpan<Char> input) {
}

TimeSpanParse::TimeSpanTokenizer::TimeSpanTokenizer(ReadOnlySpan<Char> input, Int32 startPosition) {
  _value = input;
  _pos = startPosition;
}

TimeSpanParse::TimeSpanToken TimeSpanParse::TimeSpanTokenizer::GetNextToken() {
  Int32 pos = _pos;
  if (pos >= _value.get_Length()) {
    return TimeSpanToken(TTT::End);
  }
  Int32 num = _value[pos] - 48;
  if ((UInt32)num <= 9u) {
    Int32 num2 = 0;
    if (num == 0) {
      num2 = 1;
      Int32 num3;
      while (true) {
        if (++_pos >= _value.get_Length() || (UInt32)(num3 = _value[_pos] - 48) > 9u) {
          return TimeSpanToken(TTT::Num, 0, num2, rt::default__);
        }
        if (num3 != 0) {
          break;
        }
        num2++;
      }
      num = num3;
    }
    while (++_pos < _value.get_Length()) {
      Int32 num4 = _value[_pos] - 48;
      if ((UInt32)num4 > 9u) {
        break;
      }
      num = num * 10 + num4;
      if ((num & 4026531840u) != 0) {
        return TimeSpanToken(TTT::NumOverflow);
      }
    }
    return TimeSpanToken(TTT::Num, num, num2, rt::default__);
  }
  Int32 num5 = 1;
  while (++_pos < _value.get_Length() && (UInt32)(_value[_pos] - 48) > 9u) {
    num5++;
  }
  return TimeSpanToken(TTT::Sep, 0, 0, _value.Slice(pos, num5));
}

void TimeSpanParse::TimeSpanTokenizer::BackOne() {
  if (_pos > 0) {
    _pos--;
  }
}

TimeSpanFormat::FormatLiterals TimeSpanParse::TimeSpanRawInfo::get_PositiveLocalized() {
  if (!_posLocInit) {
    _posLoc = rt::default__;
    _posLoc.Init(_fullPosPattern, false);
    _posLocInit = true;
  }
  return _posLoc;
}

TimeSpanFormat::FormatLiterals TimeSpanParse::TimeSpanRawInfo::get_NegativeLocalized() {
  if (!_negLocInit) {
    _negLoc = rt::default__;
    _negLoc.Init(_fullNegPattern, false);
    _negLocInit = true;
  }
  return _negLoc;
}

Boolean TimeSpanParse::TimeSpanRawInfo::FullAppCompatMatch(TimeSpanFormat::FormatLiterals pattern) {
  if (_sepCount == 5 && _numCount == 4 && MemoryExtensions::EqualsOrdinal(_literals0, pattern.get_Start()) && MemoryExtensions::EqualsOrdinal(_literals1, pattern.get_DayHourSep()) && MemoryExtensions::EqualsOrdinal(_literals2, pattern.get_HourMinuteSep()) && MemoryExtensions::EqualsOrdinal(_literals3, pattern.AppCompatLiteral)) {
    return MemoryExtensions::EqualsOrdinal(_literals4, pattern.get_End());
  }
  return false;
}

Boolean TimeSpanParse::TimeSpanRawInfo::PartialAppCompatMatch(TimeSpanFormat::FormatLiterals pattern) {
  if (_sepCount == 4 && _numCount == 3 && MemoryExtensions::EqualsOrdinal(_literals0, pattern.get_Start()) && MemoryExtensions::EqualsOrdinal(_literals1, pattern.get_HourMinuteSep()) && MemoryExtensions::EqualsOrdinal(_literals2, pattern.AppCompatLiteral)) {
    return MemoryExtensions::EqualsOrdinal(_literals3, pattern.get_End());
  }
  return false;
}

Boolean TimeSpanParse::TimeSpanRawInfo::FullMatch(TimeSpanFormat::FormatLiterals pattern) {
  if (_sepCount == 6 && _numCount == 5 && MemoryExtensions::EqualsOrdinal(_literals0, pattern.get_Start()) && MemoryExtensions::EqualsOrdinal(_literals1, pattern.get_DayHourSep()) && MemoryExtensions::EqualsOrdinal(_literals2, pattern.get_HourMinuteSep()) && MemoryExtensions::EqualsOrdinal(_literals3, pattern.get_MinuteSecondSep()) && MemoryExtensions::EqualsOrdinal(_literals4, pattern.get_SecondFractionSep())) {
    return MemoryExtensions::EqualsOrdinal(_literals5, pattern.get_End());
  }
  return false;
}

Boolean TimeSpanParse::TimeSpanRawInfo::FullDMatch(TimeSpanFormat::FormatLiterals pattern) {
  if (_sepCount == 2 && _numCount == 1 && MemoryExtensions::EqualsOrdinal(_literals0, pattern.get_Start())) {
    return MemoryExtensions::EqualsOrdinal(_literals1, pattern.get_End());
  }
  return false;
}

Boolean TimeSpanParse::TimeSpanRawInfo::FullHMMatch(TimeSpanFormat::FormatLiterals pattern) {
  if (_sepCount == 3 && _numCount == 2 && MemoryExtensions::EqualsOrdinal(_literals0, pattern.get_Start()) && MemoryExtensions::EqualsOrdinal(_literals1, pattern.get_HourMinuteSep())) {
    return MemoryExtensions::EqualsOrdinal(_literals2, pattern.get_End());
  }
  return false;
}

Boolean TimeSpanParse::TimeSpanRawInfo::FullDHMMatch(TimeSpanFormat::FormatLiterals pattern) {
  if (_sepCount == 4 && _numCount == 3 && MemoryExtensions::EqualsOrdinal(_literals0, pattern.get_Start()) && MemoryExtensions::EqualsOrdinal(_literals1, pattern.get_DayHourSep()) && MemoryExtensions::EqualsOrdinal(_literals2, pattern.get_HourMinuteSep())) {
    return MemoryExtensions::EqualsOrdinal(_literals3, pattern.get_End());
  }
  return false;
}

Boolean TimeSpanParse::TimeSpanRawInfo::FullHMSMatch(TimeSpanFormat::FormatLiterals pattern) {
  if (_sepCount == 4 && _numCount == 3 && MemoryExtensions::EqualsOrdinal(_literals0, pattern.get_Start()) && MemoryExtensions::EqualsOrdinal(_literals1, pattern.get_HourMinuteSep()) && MemoryExtensions::EqualsOrdinal(_literals2, pattern.get_MinuteSecondSep())) {
    return MemoryExtensions::EqualsOrdinal(_literals3, pattern.get_End());
  }
  return false;
}

Boolean TimeSpanParse::TimeSpanRawInfo::FullDHMSMatch(TimeSpanFormat::FormatLiterals pattern) {
  if (_sepCount == 5 && _numCount == 4 && MemoryExtensions::EqualsOrdinal(_literals0, pattern.get_Start()) && MemoryExtensions::EqualsOrdinal(_literals1, pattern.get_DayHourSep()) && MemoryExtensions::EqualsOrdinal(_literals2, pattern.get_HourMinuteSep()) && MemoryExtensions::EqualsOrdinal(_literals3, pattern.get_MinuteSecondSep())) {
    return MemoryExtensions::EqualsOrdinal(_literals4, pattern.get_End());
  }
  return false;
}

Boolean TimeSpanParse::TimeSpanRawInfo::FullHMSFMatch(TimeSpanFormat::FormatLiterals pattern) {
  if (_sepCount == 5 && _numCount == 4 && MemoryExtensions::EqualsOrdinal(_literals0, pattern.get_Start()) && MemoryExtensions::EqualsOrdinal(_literals1, pattern.get_HourMinuteSep()) && MemoryExtensions::EqualsOrdinal(_literals2, pattern.get_MinuteSecondSep()) && MemoryExtensions::EqualsOrdinal(_literals3, pattern.get_SecondFractionSep())) {
    return MemoryExtensions::EqualsOrdinal(_literals4, pattern.get_End());
  }
  return false;
}

void TimeSpanParse::TimeSpanRawInfo::Init(DateTimeFormatInfo dtfi) {
  _lastSeenTTT = TTT::None;
  _tokenCount = 0;
  _sepCount = 0;
  _numCount = 0;
  _fullPosPattern = dtfi->get_FullTimeSpanPositivePattern();
  _fullNegPattern = dtfi->get_FullTimeSpanNegativePattern();
  _posLocInit = false;
  _negLocInit = false;
}

Boolean TimeSpanParse::TimeSpanRawInfo::ProcessToken(TimeSpanToken& tok, TimeSpanResult& result) {
  switch (tok._ttt) {
    case TTT::Num:
      if ((_tokenCount == 0 && !AddSep(rt::default__, result)) || !AddNum(tok, result)) {
        return false;
      }
      break;
    case TTT::Sep:
      if (!AddSep(tok._sep, result)) {
        return false;
      }
      break;
    case TTT::NumOverflow:
      return result.SetOverflowFailure();
    default:
      return result.SetBadTimeSpanFailure();
  }
  _lastSeenTTT = tok._ttt;
  return true;
}

Boolean TimeSpanParse::TimeSpanRawInfo::AddSep(ReadOnlySpan<Char> sep, TimeSpanResult& result) {
  if (_sepCount >= 6 || _tokenCount >= 11) {
    return result.SetBadTimeSpanFailure();
  }
  switch (_sepCount++.get()) {
    case 0:
      _literals0 = sep;
      break;
    case 1:
      _literals1 = sep;
      break;
    case 2:
      _literals2 = sep;
      break;
    case 3:
      _literals3 = sep;
      break;
    case 4:
      _literals4 = sep;
      break;
    default:
      _literals5 = sep;
      break;
  }
  _tokenCount++;
  return true;
}

Boolean TimeSpanParse::TimeSpanRawInfo::AddNum(TimeSpanToken num, TimeSpanResult& result) {
  if (_numCount >= 5 || _tokenCount >= 11) {
    return result.SetBadTimeSpanFailure();
  }
  switch (_numCount++.get()) {
    case 0:
      _numbers0 = num;
      break;
    case 1:
      _numbers1 = num;
      break;
    case 2:
      _numbers2 = num;
      break;
    case 3:
      _numbers3 = num;
      break;
    default:
      _numbers4 = num;
      break;
  }
  _tokenCount++;
  return true;
}

void TimeSpanParse::StringParser::NextChar() {
  if (_pos < _len) {
    _pos++;
  }
  _ch = ((_pos < _len) ? _str[_pos] : 0);
}

Char TimeSpanParse::StringParser::NextNonDigit() {
  for (Int32 i = _pos; i < _len; i++) {
    Char c = _str[i];
    if (c < 48 || c > 57) {
      return c;
    }
  }
  return 0;
}

Boolean TimeSpanParse::StringParser::TryParse(ReadOnlySpan<Char> input, TimeSpanResult& result) {
  result.parsedTimeSpan = rt::default__;
  _str = input;
  _len = input.get_Length();
  _pos = -1;
  NextChar();
  SkipBlanks();
  Boolean flag = false;
  if (_ch == 45) {
    flag = true;
    NextChar();
  }
  Int64 time;
  if (NextNonDigit() == 58) {
    if (!ParseTime(time, result)) {
      return false;
    }
  } else {
    Int32 i;
    if (!ParseInt(10675199, i, result)) {
      return false;
    }
    time = i * 864000000000;
    if (_ch == 46) {
      NextChar();
      Int64 time2;
      if (!ParseTime(time2, result)) {
        return false;
      }
      time += time2;
    }
  }
  if (flag) {
    time = -time;
    if (time > 0) {
      return result.SetOverflowFailure();
    }
  } else if (time < 0) {
    return result.SetOverflowFailure();
  }

  SkipBlanks();
  if (_pos < _len) {
    return result.SetBadTimeSpanFailure();
  }
  result.parsedTimeSpan = TimeSpan(time);
  return true;
}

Boolean TimeSpanParse::StringParser::ParseInt(Int32 max, Int32& i, TimeSpanResult& result) {
  i = 0;
  Int32 pos = _pos;
  while (_ch >= 48 && _ch <= 57) {
    if ((i & 4026531840u) != 0) {
      return result.SetOverflowFailure();
    }
    i = i * 10 + _ch - 48;
    if (i < 0) {
      return result.SetOverflowFailure();
    }
    NextChar();
  }
  if (pos == _pos) {
    return result.SetBadTimeSpanFailure();
  }
  if (i > max) {
    return result.SetOverflowFailure();
  }
  return true;
}

Boolean TimeSpanParse::StringParser::ParseTime(Int64& time, TimeSpanResult& result) {
  time = 0;
  Int32 i;
  if (!ParseInt(23, i, result)) {
    return false;
  }
  time = i * 36000000000;
  if (_ch != 58) {
    return result.SetBadTimeSpanFailure();
  }
  NextChar();
  if (!ParseInt(59, i, result)) {
    return false;
  }
  time += (Int64)i * 600000000;
  if (_ch == 58) {
    NextChar();
    if (_ch != 46) {
      if (!ParseInt(59, i, result)) {
        return false;
      }
      time += (Int64)i * 10000000;
    }
    if (_ch == 46) {
      NextChar();
      Int32 num = 10000000;
      while (num > 1 && _ch >= 48 && _ch <= 57) {
        num /= 10;
        time += (_ch - 48) * num;
        NextChar();
      }
    }
  }
  return true;
}

void TimeSpanParse::StringParser::SkipBlanks() {
  while (_ch == 32 || _ch == 9) {
    NextChar();
  }
}

Int64 TimeSpanParse::Pow10(Int32 pow) {
  switch (pow.get()) {
    case 0:
      return 1;
    case 1:
      return 10;
    case 2:
      return 100;
    case 3:
      return 1000;
    case 4:
      return 10000;
    case 5:
      return 100000;
    case 6:
      return 1000000;
    case 7:
      return 10000000;
    default:
      return (Int64)Math::Pow(10, pow);
  }
}

Boolean TimeSpanParse::TryTimeToTicks(Boolean positive, TimeSpanToken days, TimeSpanToken hours, TimeSpanToken minutes, TimeSpanToken seconds, TimeSpanToken fraction, Int64& result) {
  if (days._num > 10675199 || hours._num > 23 || minutes._num > 59 || seconds._num > 59 || !fraction.NormalizeAndValidateFraction()) {
    result = 0;
    return false;
  }
  Int64 num = ((Int64)days._num * 3600 * 24 + (Int64)hours._num * 3600 + (Int64)minutes._num * 60 + seconds._num) * 1000;
  if (num > 922337203685477 || num < -922337203685477) {
    result = 0;
    return false;
  }
  result = num * 10000 + fraction._num;
  if (positive && result < 0) {
    result = 0;
    return false;
  }
  return true;
}

TimeSpan TimeSpanParse::Parse(ReadOnlySpan<Char> input, IFormatProvider formatProvider) {
  TimeSpanResult result = TimeSpanResult(true, input);
  Boolean flag = TryParseTimeSpan(input, TimeSpanStandardStyles::Any, formatProvider, result);
  return result.parsedTimeSpan;
}

Boolean TimeSpanParse::TryParse(ReadOnlySpan<Char> input, IFormatProvider formatProvider, TimeSpan& result) {
  TimeSpanResult result2 = TimeSpanResult(false, input);
  if (TryParseTimeSpan(input, TimeSpanStandardStyles::Any, formatProvider, result2)) {
    result = result2.parsedTimeSpan;
    return true;
  }
  result = rt::default__;
  return false;
}

TimeSpan TimeSpanParse::ParseExact(ReadOnlySpan<Char> input, ReadOnlySpan<Char> format, IFormatProvider formatProvider, TimeSpanStyles styles) {
  TimeSpanResult result = TimeSpanResult(true, input);
  Boolean flag = TryParseExactTimeSpan(input, format, formatProvider, styles, result);
  return result.parsedTimeSpan;
}

Boolean TimeSpanParse::TryParseExact(ReadOnlySpan<Char> input, ReadOnlySpan<Char> format, IFormatProvider formatProvider, TimeSpanStyles styles, TimeSpan& result) {
  TimeSpanResult result2 = TimeSpanResult(false, input);
  if (TryParseExactTimeSpan(input, format, formatProvider, styles, result2)) {
    result = result2.parsedTimeSpan;
    return true;
  }
  result = rt::default__;
  return false;
}

TimeSpan TimeSpanParse::ParseExactMultiple(ReadOnlySpan<Char> input, Array<String> formats, IFormatProvider formatProvider, TimeSpanStyles styles) {
  TimeSpanResult result = TimeSpanResult(true, input);
  Boolean flag = TryParseExactMultipleTimeSpan(input, formats, formatProvider, styles, result);
  return result.parsedTimeSpan;
}

Boolean TimeSpanParse::TryParseExactMultiple(ReadOnlySpan<Char> input, Array<String> formats, IFormatProvider formatProvider, TimeSpanStyles styles, TimeSpan& result) {
  TimeSpanResult result2 = TimeSpanResult(false, input);
  if (TryParseExactMultipleTimeSpan(input, formats, formatProvider, styles, result2)) {
    result = result2.parsedTimeSpan;
    return true;
  }
  result = rt::default__;
  return false;
}

Boolean TimeSpanParse::TryParseTimeSpan(ReadOnlySpan<Char> input, TimeSpanStandardStyles style, IFormatProvider formatProvider, TimeSpanResult& result) {
  input = MemoryExtensions::Trim(input);
  if (input.get_IsEmpty()) {
    return result.SetBadTimeSpanFailure();
  }
  TimeSpanTokenizer timeSpanTokenizer = TimeSpanTokenizer(input);
  TimeSpanRawInfo raw;
  raw.Init(DateTimeFormatInfo::in::GetInstance(formatProvider));
  TimeSpanToken tok = timeSpanTokenizer.GetNextToken();
  while (tok._ttt != TTT::End) {
    if (!raw.ProcessToken(tok, result)) {
      return result.SetBadTimeSpanFailure();
    }
    tok = timeSpanTokenizer.GetNextToken();
  }
  if (!ProcessTerminalState(raw, style, result)) {
    return result.SetBadTimeSpanFailure();
  }
  return true;
}

Boolean TimeSpanParse::ProcessTerminalState(TimeSpanRawInfo& raw, TimeSpanStandardStyles style, TimeSpanResult& result) {
  if (raw._lastSeenTTT == TTT::Num) {
    TimeSpanToken tok;
    tok._ttt = TTT::Sep;
    if (!raw.ProcessToken(tok, result)) {
      return result.SetBadTimeSpanFailure();
    }
  }
  switch (raw._numCount.get()) {
    case 1:
      return ProcessTerminal_D(raw, style, result);
    case 2:
      return ProcessTerminal_HM(raw, style, result);
    case 3:
      return ProcessTerminal_HM_S_D(raw, style, result);
    case 4:
      return ProcessTerminal_HMS_F_D(raw, style, result);
    case 5:
      return ProcessTerminal_DHMSF(raw, style, result);
    default:
      return result.SetBadTimeSpanFailure();
  }
}

Boolean TimeSpanParse::ProcessTerminal_DHMSF(TimeSpanRawInfo& raw, TimeSpanStandardStyles style, TimeSpanResult& result) {
  if (raw._sepCount != 6) {
    return result.SetBadTimeSpanFailure();
  }
  Boolean flag = (style & TimeSpanStandardStyles::Invariant) != 0;
  Boolean flag2 = (style & TimeSpanStandardStyles::Localized) != 0;
  Boolean flag3 = false;
  Boolean flag4 = false;
  if (flag) {
    if (raw.FullMatch(TimeSpanFormat::PositiveInvariantFormatLiterals)) {
      flag4 = true;
      flag3 = true;
    }
    if (!flag4 && raw.FullMatch(TimeSpanFormat::NegativeInvariantFormatLiterals)) {
      flag4 = true;
      flag3 = false;
    }
  }
  if (flag2) {
    if (!flag4 && raw.FullMatch(raw.get_PositiveLocalized())) {
      flag4 = true;
      flag3 = true;
    }
    if (!flag4 && raw.FullMatch(raw.get_NegativeLocalized())) {
      flag4 = true;
      flag3 = false;
    }
  }
  if (flag4) {
    Int64 result2;
    if (!TryTimeToTicks(flag3, raw._numbers0, raw._numbers1, raw._numbers2, raw._numbers3, raw._numbers4, result2)) {
      return result.SetOverflowFailure();
    }
    if (!flag3) {
      result2 = -result2;
      if (result2 > 0) {
        return result.SetOverflowFailure();
      }
    }
    result.parsedTimeSpan = TimeSpan(result2);
    return true;
  }
  return result.SetBadTimeSpanFailure();
}

Boolean TimeSpanParse::ProcessTerminal_HMS_F_D(TimeSpanRawInfo& raw, TimeSpanStandardStyles style, TimeSpanResult& result) {
  if (raw._sepCount != 5 || (style & TimeSpanStandardStyles::RequireFull) != 0) {
    return result.SetBadTimeSpanFailure();
  }
  Boolean flag = (style & TimeSpanStandardStyles::Invariant) != 0;
  Boolean flag2 = (style & TimeSpanStandardStyles::Localized) != 0;
  Int64 result2 = 0;
  Boolean flag3 = false;
  Boolean flag4 = false;
  Boolean flag5 = false;
  TimeSpanToken timeSpanToken = TimeSpanToken(0);
  if (flag) {
    if (raw.FullHMSFMatch(TimeSpanFormat::PositiveInvariantFormatLiterals)) {
      flag3 = true;
      flag4 = TryTimeToTicks(flag3, timeSpanToken, raw._numbers0, raw._numbers1, raw._numbers2, raw._numbers3, result2);
      flag5 = (flag5 || !flag4);
    }
    if (!flag4 && raw.FullDHMSMatch(TimeSpanFormat::PositiveInvariantFormatLiterals)) {
      flag3 = true;
      flag4 = TryTimeToTicks(flag3, raw._numbers0, raw._numbers1, raw._numbers2, raw._numbers3, timeSpanToken, result2);
      flag5 = (flag5 || !flag4);
    }
    if (!flag4 && raw.FullAppCompatMatch(TimeSpanFormat::PositiveInvariantFormatLiterals)) {
      flag3 = true;
      flag4 = TryTimeToTicks(flag3, raw._numbers0, raw._numbers1, raw._numbers2, timeSpanToken, raw._numbers3, result2);
      flag5 = (flag5 || !flag4);
    }
    if (!flag4 && raw.FullHMSFMatch(TimeSpanFormat::NegativeInvariantFormatLiterals)) {
      flag3 = false;
      flag4 = TryTimeToTicks(flag3, timeSpanToken, raw._numbers0, raw._numbers1, raw._numbers2, raw._numbers3, result2);
      flag5 = (flag5 || !flag4);
    }
    if (!flag4 && raw.FullDHMSMatch(TimeSpanFormat::NegativeInvariantFormatLiterals)) {
      flag3 = false;
      flag4 = TryTimeToTicks(flag3, raw._numbers0, raw._numbers1, raw._numbers2, raw._numbers3, timeSpanToken, result2);
      flag5 = (flag5 || !flag4);
    }
    if (!flag4 && raw.FullAppCompatMatch(TimeSpanFormat::NegativeInvariantFormatLiterals)) {
      flag3 = false;
      flag4 = TryTimeToTicks(flag3, raw._numbers0, raw._numbers1, raw._numbers2, timeSpanToken, raw._numbers3, result2);
      flag5 = (flag5 || !flag4);
    }
  }
  if (flag2) {
    if (!flag4 && raw.FullHMSFMatch(raw.get_PositiveLocalized())) {
      flag3 = true;
      flag4 = TryTimeToTicks(flag3, timeSpanToken, raw._numbers0, raw._numbers1, raw._numbers2, raw._numbers3, result2);
      flag5 = (flag5 || !flag4);
    }
    if (!flag4 && raw.FullDHMSMatch(raw.get_PositiveLocalized())) {
      flag3 = true;
      flag4 = TryTimeToTicks(flag3, raw._numbers0, raw._numbers1, raw._numbers2, raw._numbers3, timeSpanToken, result2);
      flag5 = (flag5 || !flag4);
    }
    if (!flag4 && raw.FullAppCompatMatch(raw.get_PositiveLocalized())) {
      flag3 = true;
      flag4 = TryTimeToTicks(flag3, raw._numbers0, raw._numbers1, raw._numbers2, timeSpanToken, raw._numbers3, result2);
      flag5 = (flag5 || !flag4);
    }
    if (!flag4 && raw.FullHMSFMatch(raw.get_NegativeLocalized())) {
      flag3 = false;
      flag4 = TryTimeToTicks(flag3, timeSpanToken, raw._numbers0, raw._numbers1, raw._numbers2, raw._numbers3, result2);
      flag5 = (flag5 || !flag4);
    }
    if (!flag4 && raw.FullDHMSMatch(raw.get_NegativeLocalized())) {
      flag3 = false;
      flag4 = TryTimeToTicks(flag3, raw._numbers0, raw._numbers1, raw._numbers2, raw._numbers3, timeSpanToken, result2);
      flag5 = (flag5 || !flag4);
    }
    if (!flag4 && raw.FullAppCompatMatch(raw.get_NegativeLocalized())) {
      flag3 = false;
      flag4 = TryTimeToTicks(flag3, raw._numbers0, raw._numbers1, raw._numbers2, timeSpanToken, raw._numbers3, result2);
      flag5 = (flag5 || !flag4);
    }
  }
  if (flag4) {
    if (!flag3) {
      result2 = -result2;
      if (result2 > 0) {
        return result.SetOverflowFailure();
      }
    }
    result.parsedTimeSpan = TimeSpan(result2);
    return true;
  }
  if (!flag5) {
    return result.SetBadTimeSpanFailure();
  }
  return result.SetOverflowFailure();
}

Boolean TimeSpanParse::ProcessTerminal_HM_S_D(TimeSpanRawInfo& raw, TimeSpanStandardStyles style, TimeSpanResult& result) {
  if (raw._sepCount != 4 || (style & TimeSpanStandardStyles::RequireFull) != 0) {
    return result.SetBadTimeSpanFailure();
  }
  Boolean flag = (style & TimeSpanStandardStyles::Invariant) != 0;
  Boolean flag2 = (style & TimeSpanStandardStyles::Localized) != 0;
  Boolean flag3 = false;
  Boolean flag4 = false;
  Boolean flag5 = false;
  TimeSpanToken timeSpanToken = TimeSpanToken(0);
  Int64 result2 = 0;
  if (flag) {
    if (raw.FullHMSMatch(TimeSpanFormat::PositiveInvariantFormatLiterals)) {
      flag3 = true;
      flag4 = TryTimeToTicks(flag3, timeSpanToken, raw._numbers0, raw._numbers1, raw._numbers2, timeSpanToken, result2);
      flag5 = (flag5 || !flag4);
    }
    if (!flag4 && raw.FullDHMMatch(TimeSpanFormat::PositiveInvariantFormatLiterals)) {
      flag3 = true;
      flag4 = TryTimeToTicks(flag3, raw._numbers0, raw._numbers1, raw._numbers2, timeSpanToken, timeSpanToken, result2);
      flag5 = (flag5 || !flag4);
    }
    if (!flag4 && raw.PartialAppCompatMatch(TimeSpanFormat::PositiveInvariantFormatLiterals)) {
      flag3 = true;
      flag4 = TryTimeToTicks(flag3, timeSpanToken, raw._numbers0, raw._numbers1, timeSpanToken, raw._numbers2, result2);
      flag5 = (flag5 || !flag4);
    }
    if (!flag4 && raw.FullHMSMatch(TimeSpanFormat::NegativeInvariantFormatLiterals)) {
      flag3 = false;
      flag4 = TryTimeToTicks(flag3, timeSpanToken, raw._numbers0, raw._numbers1, raw._numbers2, timeSpanToken, result2);
      flag5 = (flag5 || !flag4);
    }
    if (!flag4 && raw.FullDHMMatch(TimeSpanFormat::NegativeInvariantFormatLiterals)) {
      flag3 = false;
      flag4 = TryTimeToTicks(flag3, raw._numbers0, raw._numbers1, raw._numbers2, timeSpanToken, timeSpanToken, result2);
      flag5 = (flag5 || !flag4);
    }
    if (!flag4 && raw.PartialAppCompatMatch(TimeSpanFormat::NegativeInvariantFormatLiterals)) {
      flag3 = false;
      flag4 = TryTimeToTicks(flag3, timeSpanToken, raw._numbers0, raw._numbers1, timeSpanToken, raw._numbers2, result2);
      flag5 = (flag5 || !flag4);
    }
  }
  if (flag2) {
    if (!flag4 && raw.FullHMSMatch(raw.get_PositiveLocalized())) {
      flag3 = true;
      flag4 = TryTimeToTicks(flag3, timeSpanToken, raw._numbers0, raw._numbers1, raw._numbers2, timeSpanToken, result2);
      flag5 = (flag5 || !flag4);
    }
    if (!flag4 && raw.FullDHMMatch(raw.get_PositiveLocalized())) {
      flag3 = true;
      flag4 = TryTimeToTicks(flag3, raw._numbers0, raw._numbers1, raw._numbers2, timeSpanToken, timeSpanToken, result2);
      flag5 = (flag5 || !flag4);
    }
    if (!flag4 && raw.PartialAppCompatMatch(raw.get_PositiveLocalized())) {
      flag3 = true;
      flag4 = TryTimeToTicks(flag3, timeSpanToken, raw._numbers0, raw._numbers1, timeSpanToken, raw._numbers2, result2);
      flag5 = (flag5 || !flag4);
    }
    if (!flag4 && raw.FullHMSMatch(raw.get_NegativeLocalized())) {
      flag3 = false;
      flag4 = TryTimeToTicks(flag3, timeSpanToken, raw._numbers0, raw._numbers1, raw._numbers2, timeSpanToken, result2);
      flag5 = (flag5 || !flag4);
    }
    if (!flag4 && raw.FullDHMMatch(raw.get_NegativeLocalized())) {
      flag3 = false;
      flag4 = TryTimeToTicks(flag3, raw._numbers0, raw._numbers1, raw._numbers2, timeSpanToken, timeSpanToken, result2);
      flag5 = (flag5 || !flag4);
    }
    if (!flag4 && raw.PartialAppCompatMatch(raw.get_NegativeLocalized())) {
      flag3 = false;
      flag4 = TryTimeToTicks(flag3, timeSpanToken, raw._numbers0, raw._numbers1, timeSpanToken, raw._numbers2, result2);
      flag5 = (flag5 || !flag4);
    }
  }
  if (flag4) {
    if (!flag3) {
      result2 = -result2;
      if (result2 > 0) {
        return result.SetOverflowFailure();
      }
    }
    result.parsedTimeSpan = TimeSpan(result2);
    return true;
  }
  if (!flag5) {
    return result.SetBadTimeSpanFailure();
  }
  return result.SetOverflowFailure();
}

Boolean TimeSpanParse::ProcessTerminal_HM(TimeSpanRawInfo& raw, TimeSpanStandardStyles style, TimeSpanResult& result) {
  if (raw._sepCount != 3 || (style & TimeSpanStandardStyles::RequireFull) != 0) {
    return result.SetBadTimeSpanFailure();
  }
  Boolean flag = (style & TimeSpanStandardStyles::Invariant) != 0;
  Boolean flag2 = (style & TimeSpanStandardStyles::Localized) != 0;
  Boolean flag3 = false;
  Boolean flag4 = false;
  if (flag) {
    if (raw.FullHMMatch(TimeSpanFormat::PositiveInvariantFormatLiterals)) {
      flag4 = true;
      flag3 = true;
    }
    if (!flag4 && raw.FullHMMatch(TimeSpanFormat::NegativeInvariantFormatLiterals)) {
      flag4 = true;
      flag3 = false;
    }
  }
  if (flag2) {
    if (!flag4 && raw.FullHMMatch(raw.get_PositiveLocalized())) {
      flag4 = true;
      flag3 = true;
    }
    if (!flag4 && raw.FullHMMatch(raw.get_NegativeLocalized())) {
      flag4 = true;
      flag3 = false;
    }
  }
  if (flag4) {
    TimeSpanToken timeSpanToken = TimeSpanToken(0);
    Int64 result2;
    if (!TryTimeToTicks(flag3, timeSpanToken, raw._numbers0, raw._numbers1, timeSpanToken, timeSpanToken, result2)) {
      return result.SetOverflowFailure();
    }
    if (!flag3) {
      result2 = -result2;
      if (result2 > 0) {
        return result.SetOverflowFailure();
      }
    }
    result.parsedTimeSpan = TimeSpan(result2);
    return true;
  }
  return result.SetBadTimeSpanFailure();
}

Boolean TimeSpanParse::ProcessTerminal_D(TimeSpanRawInfo& raw, TimeSpanStandardStyles style, TimeSpanResult& result) {
  if (raw._sepCount != 2 || (style & TimeSpanStandardStyles::RequireFull) != 0) {
    return result.SetBadTimeSpanFailure();
  }
  Boolean flag = (style & TimeSpanStandardStyles::Invariant) != 0;
  Boolean flag2 = (style & TimeSpanStandardStyles::Localized) != 0;
  Boolean flag3 = false;
  Boolean flag4 = false;
  if (flag) {
    if (raw.FullDMatch(TimeSpanFormat::PositiveInvariantFormatLiterals)) {
      flag4 = true;
      flag3 = true;
    }
    if (!flag4 && raw.FullDMatch(TimeSpanFormat::NegativeInvariantFormatLiterals)) {
      flag4 = true;
      flag3 = false;
    }
  }
  if (flag2) {
    if (!flag4 && raw.FullDMatch(raw.get_PositiveLocalized())) {
      flag4 = true;
      flag3 = true;
    }
    if (!flag4 && raw.FullDMatch(raw.get_NegativeLocalized())) {
      flag4 = true;
      flag3 = false;
    }
  }
  if (flag4) {
    TimeSpanToken timeSpanToken = TimeSpanToken(0);
    Int64 result2;
    if (!TryTimeToTicks(flag3, raw._numbers0, timeSpanToken, timeSpanToken, timeSpanToken, timeSpanToken, result2)) {
      return result.SetOverflowFailure();
    }
    if (!flag3) {
      result2 = -result2;
      if (result2 > 0) {
        return result.SetOverflowFailure();
      }
    }
    result.parsedTimeSpan = TimeSpan(result2);
    return true;
  }
  return result.SetBadTimeSpanFailure();
}

Boolean TimeSpanParse::TryParseExactTimeSpan(ReadOnlySpan<Char> input, ReadOnlySpan<Char> format, IFormatProvider formatProvider, TimeSpanStyles styles, TimeSpanResult& result) {
  if (format.get_Length() == 0) {
    return result.SetBadFormatSpecifierFailure();
  }
  if (format.get_Length() == 1) {
    switch (format[0].get()) {
      case 84:
      case 99:
      case 116:
        return TryParseTimeSpanConstant(input, result);
      case 103:
        return TryParseTimeSpan(input, TimeSpanStandardStyles::Localized, formatProvider, result);
      case 71:
        return TryParseTimeSpan(input, TimeSpanStandardStyles::Localized | TimeSpanStandardStyles::RequireFull, formatProvider, result);
      default:
        return result.SetBadFormatSpecifierFailure(format[0]);
    }
  }
  return TryParseByFormat(input, format, styles, result);
}

Boolean TimeSpanParse::TryParseByFormat(ReadOnlySpan<Char> input, ReadOnlySpan<Char> format, TimeSpanStyles styles, TimeSpanResult& result) {
  Boolean flag = false;
  Boolean flag2 = false;
  Boolean flag3 = false;
  Boolean flag4 = false;
  Boolean flag5 = false;
  Int32 result2 = 0;
  Int32 result3 = 0;
  Int32 result4 = 0;
  Int32 result5 = 0;
  Int32 zeroes = 0;
  Int32 result6 = 0;
  Int32 i = 0;
  TimeSpanTokenizer tokenizer = TimeSpanTokenizer(input, -1);
  Int32 returnValue;
  for (; i < format.get_Length(); i += returnValue) {
    Char c = format[i];
    switch (c.get()) {
      case 104:
        returnValue = DateTimeFormat::ParseRepeatPattern(format, i, c);
        if (returnValue > 2 || flag2 || !ParseExactDigits(tokenizer, returnValue, result3)) {
          return result.SetInvalidStringFailure();
        }
        flag2 = true;
        break;
      case 109:
        returnValue = DateTimeFormat::ParseRepeatPattern(format, i, c);
        if (returnValue > 2 || flag3 || !ParseExactDigits(tokenizer, returnValue, result4)) {
          return result.SetInvalidStringFailure();
        }
        flag3 = true;
        break;
      case 115:
        returnValue = DateTimeFormat::ParseRepeatPattern(format, i, c);
        if (returnValue > 2 || flag4 || !ParseExactDigits(tokenizer, returnValue, result5)) {
          return result.SetInvalidStringFailure();
        }
        flag4 = true;
        break;
      case 102:
        returnValue = DateTimeFormat::ParseRepeatPattern(format, i, c);
        if (returnValue > 7 || flag5 || !ParseExactDigits(tokenizer, returnValue, returnValue, zeroes, result6)) {
          return result.SetInvalidStringFailure();
        }
        flag5 = true;
        break;
      case 70:
        returnValue = DateTimeFormat::ParseRepeatPattern(format, i, c);
        if (returnValue > 7 || flag5) {
          return result.SetInvalidStringFailure();
        }
        ParseExactDigits(tokenizer, returnValue, returnValue, zeroes, result6);
        flag5 = true;
        break;
      case 100:
        {
          returnValue = DateTimeFormat::ParseRepeatPattern(format, i, c);
          Int32 zeroes2;
          if (returnValue > 8 || flag || !ParseExactDigits(tokenizer, (returnValue < 2) ? 1 : returnValue, (returnValue < 2) ? 8 : returnValue, zeroes2, result2)) {
            return result.SetInvalidStringFailure();
          }
          flag = true;
          break;
        }case 34:
      case 39:
        {
          StringBuilder stringBuilder = StringBuilderCache::Acquire();
          if (!DateTimeParse::TryParseQuoteString(format, i, stringBuilder, returnValue)) {
            StringBuilderCache::Release(stringBuilder);
            return result.SetBadQuoteFailure(c);
          }
          if (!ParseExactLiteral(tokenizer, stringBuilder)) {
            StringBuilderCache::Release(stringBuilder);
            return result.SetInvalidStringFailure();
          }
          StringBuilderCache::Release(stringBuilder);
          break;
        }case 37:
        {
          Int32 num = DateTimeFormat::ParseNextChar(format, i);
          if (num >= 0 && num != 37) {
            returnValue = 1;
            break;
          }
          return result.SetInvalidStringFailure();
        }case 92:
        {
          Int32 num = DateTimeFormat::ParseNextChar(format, i);
          if (num >= 0 && tokenizer.get_NextChar() == (UInt16)num) {
            returnValue = 2;
            break;
          }
          return result.SetInvalidStringFailure();
        }default:
        return result.SetInvalidStringFailure();
    }
  }
  if (!tokenizer.get_EOL()) {
    return result.SetBadTimeSpanFailure();
  }
  Boolean flag6 = (styles & TimeSpanStyles::AssumeNegative) == 0;
  Int64 result7;
  if (TryTimeToTicks(flag6, TimeSpanToken(result2), TimeSpanToken(result3), TimeSpanToken(result4), TimeSpanToken(result5), TimeSpanToken(result6, zeroes), result7)) {
    if (!flag6) {
      result7 = -result7;
    }
    result.parsedTimeSpan = TimeSpan(result7);
    return true;
  }
  return result.SetOverflowFailure();
}

Boolean TimeSpanParse::ParseExactDigits(TimeSpanTokenizer& tokenizer, Int32 minDigitLength, Int32& result) {
  Int32 maxDigitLength = (minDigitLength == 1) ? 2 : minDigitLength;
  Int32 zeroes;
  return ParseExactDigits(tokenizer, minDigitLength, maxDigitLength, zeroes, result);
}

Boolean TimeSpanParse::ParseExactDigits(TimeSpanTokenizer& tokenizer, Int32 minDigitLength, Int32 maxDigitLength, Int32& zeroes, Int32& result) {
  Int32 num = 0;
  Int32 num2 = 0;
  Int32 i;
  for (i = 0; i < maxDigitLength; i++) {
    Char nextChar = tokenizer.get_NextChar();
    if (nextChar < 48 || nextChar > 57) {
      tokenizer.BackOne();
      break;
    }
    num = num * 10 + (nextChar - 48);
    if (num == 0) {
      num2++;
    }
  }
  zeroes = num2;
  result = num;
  return i >= minDigitLength;
}

Boolean TimeSpanParse::ParseExactLiteral(TimeSpanTokenizer& tokenizer, StringBuilder enquotedString) {
  for (Int32 i = 0; i < enquotedString->get_Length(); i++) {
    if (enquotedString[i] != tokenizer.get_NextChar()) {
      return false;
    }
  }
  return true;
}

Boolean TimeSpanParse::TryParseTimeSpanConstant(ReadOnlySpan<Char> input, TimeSpanResult& result) {
  StringParser stringParser;
  return stringParser.TryParse(input, result);
}

Boolean TimeSpanParse::TryParseExactMultipleTimeSpan(ReadOnlySpan<Char> input, Array<String> formats, IFormatProvider formatProvider, TimeSpanStyles styles, TimeSpanResult& result) {
  if (formats == nullptr) {
    return result.SetArgumentNullFailure("formats");
  }
  if (input.get_Length() == 0) {
    return result.SetBadTimeSpanFailure();
  }
  if (formats->get_Length() == 0) {
    return result.SetNoFormatSpecifierFailure();
  }
  for (String& value : rt::each(formats)) {
    if (String::in::IsNullOrEmpty(value)) {
      return result.SetBadFormatSpecifierFailure();
    }
    TimeSpanResult result2 = TimeSpanResult(false, input);
    if (TryParseExactTimeSpan(input, value, formatProvider, styles, result2)) {
      result.parsedTimeSpan = result2.parsedTimeSpan;
      return true;
    }
  }
  return result.SetBadTimeSpanFailure();
}

} // namespace System::Private::CoreLib::System::Globalization::TimeSpanParseNamespace
