#pragma once

#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array)
FORWARDS(Boolean)
FORWARDS(Char)
FORWARD(IFormatProvider)
FORWARDS(ReadOnlySpan, T)
FORWARDS(Span, T)
FORWARD(String)
FORWARDS(TimeSpan)
FORWARDS(UInt32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Text {
FORWARD(StringBuilder)
} // namespace System::Private::CoreLib::System::Text
namespace System::Private::CoreLib::System::Globalization {
FORWARD(DateTimeFormatInfo)
namespace TimeSpanFormatNamespace {
using namespace System::Text;
class TimeSpanFormat {
  private: enum class StandardFormat : int32_t {
    C = 0,
    G = 1,
    g = 2,
  };
  public: struct FormatLiterals : public valueType<FormatLiterals> {
    public: String get_Start();
    public: String get_DayHourSep();
    public: String get_HourMinuteSep();
    public: String get_MinuteSecondSep();
    public: String get_SecondFractionSep();
    public: String get_End();
    public: static FormatLiterals InitInvariant(Boolean isNegative);
    public: void Init(ReadOnlySpan<Char> format, Boolean useInvariantFieldLengths);
    public: String AppCompatLiteral;
    public: Int32 dd;
    public: Int32 hh;
    public: Int32 mm;
    public: Int32 ss;
    public: Int32 ff;
    private: Array<String> _literals;
  };
  public: static String Format(TimeSpan value, String format, IFormatProvider formatProvider);
  public: static Boolean TryFormat(TimeSpan value, Span<Char> destination, Int32& charsWritten, ReadOnlySpan<Char> format, IFormatProvider formatProvider);
  public: static String FormatC(TimeSpan value);
  private: static String FormatG(TimeSpan value, DateTimeFormatInfo dtfi, StandardFormat format);
  private: static Boolean TryFormatStandard(TimeSpan value, StandardFormat format, String decimalSeparator, Span<Char> destination, Int32& charsWritten);
  private: static void WriteTwoDigits(UInt32 value, Span<Char> buffer);
  private: static void WriteDigits(UInt32 value, Span<Char> buffer);
  private: static StringBuilder FormatCustomized(TimeSpan value, ReadOnlySpan<Char> format, DateTimeFormatInfo dtfi, StringBuilder result = nullptr);
  public: static void cctor();
  public: static FormatLiterals PositiveInvariantFormatLiterals;
  public: static FormatLiterals NegativeInvariantFormatLiterals;
};
} // namespace TimeSpanFormatNamespace
using TimeSpanFormat = TimeSpanFormatNamespace::TimeSpanFormat;
} // namespace System::Private::CoreLib::System::Globalization
