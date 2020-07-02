#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Int32.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
FORWARDS(Boolean)
FORWARDS(ReadOnlySpan, T)
FORWARDS(Char)
FORWARD_(Array, T1, T2)
FORWARDS(TimeSpan)
FORWARD(IFormatProvider)
FORWARDS(Span, T)
FORWARDS(UInt32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Text {
FORWARD(StringBuilder)
} // namespace System::Private::CoreLib::System::Text
namespace System::Private::CoreLib::System::Globalization {
FORWARD(DateTimeFormatInfo)
namespace TimeSpanFormatNamespace {
using namespace ::System::Private::CoreLib::System::Text;
class TimeSpanFormat {
  private: enum class StandardFormat {
    C = 0,
    G = 1,
    g = 2,
  };
  public: struct FormatLiterals {
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
  private: static StringBuilder FormatCustomized(TimeSpan value, ReadOnlySpan<Char> format, DateTimeFormatInfo dtfi, StringBuilder result);
  public: static FormatLiterals PositiveInvariantFormatLiterals;
  public: static FormatLiterals NegativeInvariantFormatLiterals;
};
} // namespace TimeSpanFormatNamespace
using TimeSpanFormat = TimeSpanFormatNamespace::TimeSpanFormat;
} // namespace System::Private::CoreLib::System::Globalization
