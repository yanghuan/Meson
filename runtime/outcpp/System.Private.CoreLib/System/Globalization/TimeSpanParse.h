#pragma once

#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/Char.h>
#include <System.Private.CoreLib/System/Globalization/TimeSpanFormat.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/ReadOnlySpan.h>
#include <System.Private.CoreLib/System/TimeSpan.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARD(IFormatProvider)
FORWARDS(Int64)
FORWARDS_(Nullable, T1, T2)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Text {
FORWARD(StringBuilder)
} // namespace System::Private::CoreLib::System::Text
namespace System::Private::CoreLib::System::Globalization {
enum class TimeSpanStyles : int32_t;
FORWARD(DateTimeFormatInfo)
namespace TimeSpanParseNamespace {
using namespace System::Text;
class TimeSpanParse {
  private: enum class TimeSpanStandardStyles : uint8_t {
    None = 0,
    Invariant = 1,
    Localized = 2,
    RequireFull = 4,
    Any = 3,
  };
  private: enum class TTT : uint8_t {
    None = 0,
    End = 1,
    Num = 2,
    Sep = 3,
    NumOverflow = 4,
  };
  private: struct TimeSpanToken : public valueType<TimeSpanToken> {
    public: explicit TimeSpanToken(TTT type);
    public: explicit TimeSpanToken(Int32 number);
    public: explicit TimeSpanToken(Int32 number, Int32 leadingZeroes);
    public: explicit TimeSpanToken(TTT type, Int32 number, Int32 leadingZeroes, ReadOnlySpan<Char> separator);
    public: Boolean NormalizeAndValidateFraction();
    public: explicit TimeSpanToken() {}
    public: TTT _ttt;
    public: Int32 _num;
    public: Int32 _zeroes;
    public: ReadOnlySpan<Char> _sep;
  };
  private: struct TimeSpanResult : public valueType<TimeSpanResult> {
    public: explicit TimeSpanResult(Boolean throwOnFailure, ReadOnlySpan<Char> originalTimeSpanString);
    public: Boolean SetNoFormatSpecifierFailure();
    public: Boolean SetBadQuoteFailure(Char failingCharacter);
    public: Boolean SetInvalidStringFailure();
    public: Boolean SetArgumentNullFailure(String argumentName);
    public: Boolean SetOverflowFailure();
    public: Boolean SetBadTimeSpanFailure();
    public: Boolean SetBadFormatSpecifierFailure(Nullable<Char> formatSpecifierCharacter = nullptr);
    public: explicit TimeSpanResult() {}
    public: TimeSpan parsedTimeSpan;
    private: Boolean _throwOnFailure;
    private: ReadOnlySpan<Char> _originalTimeSpanString;
  };
  private: struct TimeSpanTokenizer : public valueType<TimeSpanTokenizer> {
    public: Boolean get_EOL();
    public: Char get_NextChar();
    public: explicit TimeSpanTokenizer(ReadOnlySpan<Char> input);
    public: explicit TimeSpanTokenizer(ReadOnlySpan<Char> input, Int32 startPosition);
    public: TimeSpanToken GetNextToken();
    public: void BackOne();
    public: explicit TimeSpanTokenizer() {}
    private: ReadOnlySpan<Char> _value;
    private: Int32 _pos;
  };
  private: struct TimeSpanRawInfo : public valueType<TimeSpanRawInfo> {
    public: TimeSpanFormat::FormatLiterals get_PositiveLocalized();
    public: TimeSpanFormat::FormatLiterals get_NegativeLocalized();
    public: Boolean FullAppCompatMatch(TimeSpanFormat::FormatLiterals pattern);
    public: Boolean PartialAppCompatMatch(TimeSpanFormat::FormatLiterals pattern);
    public: Boolean FullMatch(TimeSpanFormat::FormatLiterals pattern);
    public: Boolean FullDMatch(TimeSpanFormat::FormatLiterals pattern);
    public: Boolean FullHMMatch(TimeSpanFormat::FormatLiterals pattern);
    public: Boolean FullDHMMatch(TimeSpanFormat::FormatLiterals pattern);
    public: Boolean FullHMSMatch(TimeSpanFormat::FormatLiterals pattern);
    public: Boolean FullDHMSMatch(TimeSpanFormat::FormatLiterals pattern);
    public: Boolean FullHMSFMatch(TimeSpanFormat::FormatLiterals pattern);
    public: void Init(DateTimeFormatInfo dtfi);
    public: Boolean ProcessToken(TimeSpanToken& tok, TimeSpanResult& result);
    private: Boolean AddSep(ReadOnlySpan<Char> sep, TimeSpanResult& result);
    private: Boolean AddNum(TimeSpanToken num, TimeSpanResult& result);
    public: TTT _lastSeenTTT;
    public: Int32 _tokenCount;
    public: Int32 _sepCount;
    public: Int32 _numCount;
    private: TimeSpanFormat::FormatLiterals _posLoc;
    private: TimeSpanFormat::FormatLiterals _negLoc;
    private: Boolean _posLocInit;
    private: Boolean _negLocInit;
    private: String _fullPosPattern;
    private: String _fullNegPattern;
    public: TimeSpanToken _numbers0;
    public: TimeSpanToken _numbers1;
    public: TimeSpanToken _numbers2;
    public: TimeSpanToken _numbers3;
    public: TimeSpanToken _numbers4;
    public: ReadOnlySpan<Char> _literals0;
    public: ReadOnlySpan<Char> _literals1;
    public: ReadOnlySpan<Char> _literals2;
    public: ReadOnlySpan<Char> _literals3;
    public: ReadOnlySpan<Char> _literals4;
    public: ReadOnlySpan<Char> _literals5;
  };
  private: struct StringParser : public valueType<StringParser> {
    public: void NextChar();
    public: Char NextNonDigit();
    public: Boolean TryParse(ReadOnlySpan<Char> input, TimeSpanResult& result);
    public: Boolean ParseInt(Int32 max, Int32& i, TimeSpanResult& result);
    public: Boolean ParseTime(Int64& time, TimeSpanResult& result);
    public: void SkipBlanks();
    private: ReadOnlySpan<Char> _str;
    private: Char _ch;
    private: Int32 _pos;
    private: Int32 _len;
  };
  public: static Int64 Pow10(Int32 pow);
  private: static Boolean TryTimeToTicks(Boolean positive, TimeSpanToken days, TimeSpanToken hours, TimeSpanToken minutes, TimeSpanToken seconds, TimeSpanToken fraction, Int64& result);
  public: static TimeSpan Parse(ReadOnlySpan<Char> input, IFormatProvider formatProvider);
  public: static Boolean TryParse(ReadOnlySpan<Char> input, IFormatProvider formatProvider, TimeSpan& result);
  public: static TimeSpan ParseExact(ReadOnlySpan<Char> input, ReadOnlySpan<Char> format, IFormatProvider formatProvider, TimeSpanStyles styles);
  public: static Boolean TryParseExact(ReadOnlySpan<Char> input, ReadOnlySpan<Char> format, IFormatProvider formatProvider, TimeSpanStyles styles, TimeSpan& result);
  public: static TimeSpan ParseExactMultiple(ReadOnlySpan<Char> input, Array<String> formats, IFormatProvider formatProvider, TimeSpanStyles styles);
  public: static Boolean TryParseExactMultiple(ReadOnlySpan<Char> input, Array<String> formats, IFormatProvider formatProvider, TimeSpanStyles styles, TimeSpan& result);
  private: static Boolean TryParseTimeSpan(ReadOnlySpan<Char> input, TimeSpanStandardStyles style, IFormatProvider formatProvider, TimeSpanResult& result);
  private: static Boolean ProcessTerminalState(TimeSpanRawInfo& raw, TimeSpanStandardStyles style, TimeSpanResult& result);
  private: static Boolean ProcessTerminal_DHMSF(TimeSpanRawInfo& raw, TimeSpanStandardStyles style, TimeSpanResult& result);
  private: static Boolean ProcessTerminal_HMS_F_D(TimeSpanRawInfo& raw, TimeSpanStandardStyles style, TimeSpanResult& result);
  private: static Boolean ProcessTerminal_HM_S_D(TimeSpanRawInfo& raw, TimeSpanStandardStyles style, TimeSpanResult& result);
  private: static Boolean ProcessTerminal_HM(TimeSpanRawInfo& raw, TimeSpanStandardStyles style, TimeSpanResult& result);
  private: static Boolean ProcessTerminal_D(TimeSpanRawInfo& raw, TimeSpanStandardStyles style, TimeSpanResult& result);
  private: static Boolean TryParseExactTimeSpan(ReadOnlySpan<Char> input, ReadOnlySpan<Char> format, IFormatProvider formatProvider, TimeSpanStyles styles, TimeSpanResult& result);
  private: static Boolean TryParseByFormat(ReadOnlySpan<Char> input, ReadOnlySpan<Char> format, TimeSpanStyles styles, TimeSpanResult& result);
  private: static Boolean ParseExactDigits(TimeSpanTokenizer& tokenizer, Int32 minDigitLength, Int32& result);
  private: static Boolean ParseExactDigits(TimeSpanTokenizer& tokenizer, Int32 minDigitLength, Int32 maxDigitLength, Int32& zeroes, Int32& result);
  private: static Boolean ParseExactLiteral(TimeSpanTokenizer& tokenizer, StringBuilder enquotedString);
  private: static Boolean TryParseTimeSpanConstant(ReadOnlySpan<Char> input, TimeSpanResult& result);
  private: static Boolean TryParseExactMultipleTimeSpan(ReadOnlySpan<Char> input, Array<String> formats, IFormatProvider formatProvider, TimeSpanStyles styles, TimeSpanResult& result);
};
} // namespace TimeSpanParseNamespace
using TimeSpanParse = TimeSpanParseNamespace::TimeSpanParse;
} // namespace System::Private::CoreLib::System::Globalization
