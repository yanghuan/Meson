#include "Char-dep.h"

#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/Char-dep.h>
#include <System.Private.CoreLib/System/Convert-dep.h>
#include <System.Private.CoreLib/System/FormatException-dep.h>
#include <System.Private.CoreLib/System/Globalization/CharUnicodeInfo-dep.h>
#include <System.Private.CoreLib/System/Globalization/TextInfo-dep.h>
#include <System.Private.CoreLib/System/InvalidCastException-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/Text/Rune-dep.h>
#include <System.Private.CoreLib/System/Text/UnicodeUtility-dep.h>
#include <System.Private.CoreLib/System/UInt32-dep.h>

namespace System::Private::CoreLib::System::CharNamespace {
using namespace System::Globalization;
using namespace System::Text;

ReadOnlySpan<Byte> Char::get_Latin1CharInfo() {
  return rt::newarr<Array<Byte>>(256);
}

Boolean Char::IsLatin1(Char ch) {
  return (UInt32)ch < (UInt32)get_Latin1CharInfo().get_Length();
}

Boolean Char::IsAscii(Char ch) {
  return (UInt32)ch <= 127u;
}

UnicodeCategory Char::GetLatin1UnicodeCategory(Char ch) {
  return (UnicodeCategory)(get_Latin1CharInfo()[ch] & 31);
}

Int32 Char::GetHashCode() {
  return (Int32)(*this | ((UInt32)*this << 16));
}

Boolean Char::Equals(Object obj) {
  if (!rt::is<Char>(obj)) {
    return false;
  }
  return *this == (Char)obj;
}

Boolean Char::Equals(Char obj) {
  return *this == obj;
}

Int32 Char::CompareTo(Object value) {
  if (value == nullptr) {
    return 1;
  }
  if (!rt::is<Char>(value)) {
    rt::throw_exception<ArgumentException>(SR::get_Arg_MustBeChar());
  }
  return *this - (Char)value;
}

Int32 Char::CompareTo(Char value) {
  return *this - value;
}

String Char::ToString() {
  return ToString(*this);
}

String Char::ToString(IFormatProvider provider) {
  return ToString(*this);
}

String Char::ToString(Char c) {
  return String::in::CreateFromChar(c);
}

Char Char::Parse(String s) {
  if (s == nullptr) {
    rt::throw_exception<ArgumentNullException>("s");
  }
  if (s->get_Length() != 1) {
    rt::throw_exception<FormatException>(SR::get_Format_NeedSingleChar());
  }
  return s[0];
}

Boolean Char::TryParse(String s, Char& result) {
  result = u'\0';
  if (s == nullptr) {
    return false;
  }
  if (s->get_Length() != 1) {
    return false;
  }
  result = s[0];
  return true;
}

Boolean Char::IsDigit(Char c) {
  if (IsLatin1(c)) {
    return IsInRange(c, u'0', u'9');
  }
  return CharUnicodeInfo::GetUnicodeCategory(c) == UnicodeCategory::DecimalDigitNumber;
}

Boolean Char::IsInRange(Char c, Char min, Char max) {
  return (UInt32)(c - min) <= (UInt32)(max - min);
}

Boolean Char::IsInRange(UnicodeCategory c, UnicodeCategory min, UnicodeCategory max) {
  return (UInt32)(c - min) <= (UInt32)(max - min);
}

Boolean Char::CheckLetter(UnicodeCategory uc) {
  return IsInRange(uc, UnicodeCategory::UppercaseLetter, UnicodeCategory::OtherLetter);
}

Boolean Char::IsLetter(Char c) {
  if (IsLatin1(c)) {
    return (get_Latin1CharInfo()[c] & 96) != 0;
  }
  return CheckLetter(CharUnicodeInfo::GetUnicodeCategory(c));
}

Boolean Char::IsWhiteSpaceLatin1(Char c) {
  return (get_Latin1CharInfo()[c] & 128) != 0;
}

Boolean Char::IsWhiteSpace(Char c) {
  if (IsLatin1(c)) {
    return IsWhiteSpaceLatin1(c);
  }
  return CharUnicodeInfo::GetIsWhiteSpace(c);
}

Boolean Char::IsUpper(Char c) {
  if (IsLatin1(c)) {
    return (get_Latin1CharInfo()[c] & 64) != 0;
  }
  return CharUnicodeInfo::GetUnicodeCategory(c) == UnicodeCategory::UppercaseLetter;
}

Boolean Char::IsLower(Char c) {
  if (IsLatin1(c)) {
    return (get_Latin1CharInfo()[c] & 32) != 0;
  }
  return CharUnicodeInfo::GetUnicodeCategory(c) == UnicodeCategory::LowercaseLetter;
}

Boolean Char::CheckPunctuation(UnicodeCategory uc) {
  return IsInRange(uc, UnicodeCategory::ConnectorPunctuation, UnicodeCategory::OtherPunctuation);
}

Boolean Char::IsPunctuation(Char c) {
  if (IsLatin1(c)) {
    return CheckPunctuation(GetLatin1UnicodeCategory(c));
  }
  return CheckPunctuation(CharUnicodeInfo::GetUnicodeCategory(c));
}

Boolean Char::CheckLetterOrDigit(UnicodeCategory uc) {
  if (!CheckLetter(uc)) {
    return uc == UnicodeCategory::DecimalDigitNumber;
  }
  return true;
}

Boolean Char::IsLetterOrDigit(Char c) {
  if (IsLatin1(c)) {
    return CheckLetterOrDigit(GetLatin1UnicodeCategory(c));
  }
  return CheckLetterOrDigit(CharUnicodeInfo::GetUnicodeCategory(c));
}

Char Char::ToUpper(Char c, CultureInfo culture) {
  if (culture == nullptr) {
    rt::throw_exception<ArgumentNullException>("culture");
  }
  return culture->get_TextInfo()->ToUpper(c);
}

Char Char::ToUpper(Char c) {
  return CultureInfo::in::get_CurrentCulture()->get_TextInfo()->ToUpper(c);
}

Char Char::ToUpperInvariant(Char c) {
  return TextInfo::in::ToUpperInvariant(c);
}

Char Char::ToLower(Char c, CultureInfo culture) {
  if (culture == nullptr) {
    rt::throw_exception<ArgumentNullException>("culture");
  }
  return culture->get_TextInfo()->ToLower(c);
}

Char Char::ToLower(Char c) {
  return CultureInfo::in::get_CurrentCulture()->get_TextInfo()->ToLower(c);
}

Char Char::ToLowerInvariant(Char c) {
  return TextInfo::in::ToLowerInvariant(c);
}

TypeCode Char::GetTypeCode() {
  return TypeCode::Char;
}

Boolean Char::ToBooleanOfIConvertible(IFormatProvider provider) {
  rt::throw_exception<InvalidCastException>(SR::Format(SR::get_InvalidCast_FromTo(), "Char", "Boolean"));
}

Char Char::ToCharOfIConvertible(IFormatProvider provider) {
  return *this;
}

SByte Char::ToSByteOfIConvertible(IFormatProvider provider) {
  return Convert::ToSByte(*this);
}

Byte Char::ToByteOfIConvertible(IFormatProvider provider) {
  return Convert::ToByte(*this);
}

Int16 Char::ToInt16OfIConvertible(IFormatProvider provider) {
  return Convert::ToInt16(*this);
}

UInt16 Char::ToUInt16OfIConvertible(IFormatProvider provider) {
  return Convert::ToUInt16(*this);
}

Int32 Char::ToInt32OfIConvertible(IFormatProvider provider) {
  return Convert::ToInt32(*this);
}

UInt32 Char::ToUInt32OfIConvertible(IFormatProvider provider) {
  return Convert::ToUInt32(*this);
}

Int64 Char::ToInt64OfIConvertible(IFormatProvider provider) {
  return Convert::ToInt64(*this);
}

UInt64 Char::ToUInt64OfIConvertible(IFormatProvider provider) {
  return Convert::ToUInt64(*this);
}

Single Char::ToSingleOfIConvertible(IFormatProvider provider) {
  rt::throw_exception<InvalidCastException>(SR::Format(SR::get_InvalidCast_FromTo(), "Char", "Single"));
}

Double Char::ToDoubleOfIConvertible(IFormatProvider provider) {
  rt::throw_exception<InvalidCastException>(SR::Format(SR::get_InvalidCast_FromTo(), "Char", "Double"));
}

Decimal Char::ToDecimalOfIConvertible(IFormatProvider provider) {
  rt::throw_exception<InvalidCastException>(SR::Format(SR::get_InvalidCast_FromTo(), "Char", "Decimal"));
}

DateTime Char::ToDateTimeOfIConvertible(IFormatProvider provider) {
  rt::throw_exception<InvalidCastException>(SR::Format(SR::get_InvalidCast_FromTo(), "Char", "DateTime"));
}

Object Char::ToTypeOfIConvertible(Type type, IFormatProvider provider) {
  return Convert::DefaultToType(*this, type, provider);
}

Boolean Char::IsControl(Char c) {
  return (UInt32)((c + 1) & -129) <= 32u;
}

Boolean Char::IsControl(String s, Int32 index) {
  if (s == nullptr) {
    rt::throw_exception<ArgumentNullException>("s");
  }
  if ((UInt32)index >= (UInt32)s->get_Length()) {
    rt::throw_exception<ArgumentOutOfRangeException>("index");
  }
  return IsControl(s[index]);
}

Boolean Char::IsDigit(String s, Int32 index) {
  if (s == nullptr) {
    rt::throw_exception<ArgumentNullException>("s");
  }
  if ((UInt32)index >= (UInt32)s->get_Length()) {
    rt::throw_exception<ArgumentOutOfRangeException>("index");
  }
  Char c = s[index];
  if (IsLatin1(c)) {
    return IsInRange(c, u'0', u'9');
  }
  return CharUnicodeInfo::GetUnicodeCategory(s, index) == UnicodeCategory::DecimalDigitNumber;
}

Boolean Char::IsLetter(String s, Int32 index) {
  if (s == nullptr) {
    rt::throw_exception<ArgumentNullException>("s");
  }
  if ((UInt32)index >= (UInt32)s->get_Length()) {
    rt::throw_exception<ArgumentOutOfRangeException>("index");
  }
  Char c = s[index];
  if (IsLatin1(c)) {
    return (get_Latin1CharInfo()[c] & 96) != 0;
  }
  return CheckLetter(CharUnicodeInfo::GetUnicodeCategory(s, index));
}

Boolean Char::IsLetterOrDigit(String s, Int32 index) {
  if (s == nullptr) {
    rt::throw_exception<ArgumentNullException>("s");
  }
  if ((UInt32)index >= (UInt32)s->get_Length()) {
    rt::throw_exception<ArgumentOutOfRangeException>("index");
  }
  Char ch = s[index];
  if (IsLatin1(ch)) {
    return CheckLetterOrDigit(GetLatin1UnicodeCategory(ch));
  }
  return CheckLetterOrDigit(CharUnicodeInfo::GetUnicodeCategory(s, index));
}

Boolean Char::IsLower(String s, Int32 index) {
  if (s == nullptr) {
    rt::throw_exception<ArgumentNullException>("s");
  }
  if ((UInt32)index >= (UInt32)s->get_Length()) {
    rt::throw_exception<ArgumentOutOfRangeException>("index");
  }
  Char c = s[index];
  if (IsLatin1(c)) {
    return (get_Latin1CharInfo()[c] & 32) != 0;
  }
  return CharUnicodeInfo::GetUnicodeCategory(s, index) == UnicodeCategory::LowercaseLetter;
}

Boolean Char::CheckNumber(UnicodeCategory uc) {
  return IsInRange(uc, UnicodeCategory::DecimalDigitNumber, UnicodeCategory::OtherNumber);
}

Boolean Char::IsNumber(Char c) {
  if (IsLatin1(c)) {
    if (IsAscii(c)) {
      return IsInRange(c, u'0', u'9');
    }
    return CheckNumber(GetLatin1UnicodeCategory(c));
  }
  return CheckNumber(CharUnicodeInfo::GetUnicodeCategory(c));
}

Boolean Char::IsNumber(String s, Int32 index) {
  if (s == nullptr) {
    rt::throw_exception<ArgumentNullException>("s");
  }
  if ((UInt32)index >= (UInt32)s->get_Length()) {
    rt::throw_exception<ArgumentOutOfRangeException>("index");
  }
  Char c = s[index];
  if (IsLatin1(c)) {
    if (IsAscii(c)) {
      return IsInRange(c, u'0', u'9');
    }
    return CheckNumber(GetLatin1UnicodeCategory(c));
  }
  return CheckNumber(CharUnicodeInfo::GetUnicodeCategory(s, index));
}

Boolean Char::IsPunctuation(String s, Int32 index) {
  if (s == nullptr) {
    rt::throw_exception<ArgumentNullException>("s");
  }
  if ((UInt32)index >= (UInt32)s->get_Length()) {
    rt::throw_exception<ArgumentOutOfRangeException>("index");
  }
  Char ch = s[index];
  if (IsLatin1(ch)) {
    return CheckPunctuation(GetLatin1UnicodeCategory(ch));
  }
  return CheckPunctuation(CharUnicodeInfo::GetUnicodeCategory(s, index));
}

Boolean Char::CheckSeparator(UnicodeCategory uc) {
  return IsInRange(uc, UnicodeCategory::SpaceSeparator, UnicodeCategory::ParagraphSeparator);
}

Boolean Char::IsSeparatorLatin1(Char c) {
  if (c != u' ') {
    return c == u'\x00a0';
  }
  return true;
}

Boolean Char::IsSeparator(Char c) {
  if (IsLatin1(c)) {
    return IsSeparatorLatin1(c);
  }
  return CheckSeparator(CharUnicodeInfo::GetUnicodeCategory(c));
}

Boolean Char::IsSeparator(String s, Int32 index) {
  if (s == nullptr) {
    rt::throw_exception<ArgumentNullException>("s");
  }
  if ((UInt32)index >= (UInt32)s->get_Length()) {
    rt::throw_exception<ArgumentOutOfRangeException>("index");
  }
  Char c = s[index];
  if (IsLatin1(c)) {
    return IsSeparatorLatin1(c);
  }
  return CheckSeparator(CharUnicodeInfo::GetUnicodeCategory(s, index));
}

Boolean Char::IsSurrogate(Char c) {
  return IsInRange(c, u'\xd800', u'\xdfff');
}

Boolean Char::IsSurrogate(String s, Int32 index) {
  if (s == nullptr) {
    rt::throw_exception<ArgumentNullException>("s");
  }
  if ((UInt32)index >= (UInt32)s->get_Length()) {
    rt::throw_exception<ArgumentOutOfRangeException>("index");
  }
  return IsSurrogate(s[index]);
}

Boolean Char::CheckSymbol(UnicodeCategory uc) {
  return IsInRange(uc, UnicodeCategory::MathSymbol, UnicodeCategory::OtherSymbol);
}

Boolean Char::IsSymbol(Char c) {
  if (IsLatin1(c)) {
    return CheckSymbol(GetLatin1UnicodeCategory(c));
  }
  return CheckSymbol(CharUnicodeInfo::GetUnicodeCategory(c));
}

Boolean Char::IsSymbol(String s, Int32 index) {
  if (s == nullptr) {
    rt::throw_exception<ArgumentNullException>("s");
  }
  if ((UInt32)index >= (UInt32)s->get_Length()) {
    rt::throw_exception<ArgumentOutOfRangeException>("index");
  }
  Char ch = s[index];
  if (IsLatin1(ch)) {
    return CheckSymbol(GetLatin1UnicodeCategory(ch));
  }
  return CheckSymbol(CharUnicodeInfo::GetUnicodeCategory(s, index));
}

Boolean Char::IsUpper(String s, Int32 index) {
  if (s == nullptr) {
    rt::throw_exception<ArgumentNullException>("s");
  }
  if ((UInt32)index >= (UInt32)s->get_Length()) {
    rt::throw_exception<ArgumentOutOfRangeException>("index");
  }
  Char c = s[index];
  if (IsLatin1(c)) {
    return (get_Latin1CharInfo()[c] & 64) != 0;
  }
  return CharUnicodeInfo::GetUnicodeCategory(s, index) == UnicodeCategory::UppercaseLetter;
}

Boolean Char::IsWhiteSpace(String s, Int32 index) {
  if (s == nullptr) {
    rt::throw_exception<ArgumentNullException>("s");
  }
  if ((UInt32)index >= (UInt32)s->get_Length()) {
    rt::throw_exception<ArgumentOutOfRangeException>("index");
  }
  return IsWhiteSpace(s[index]);
}

UnicodeCategory Char::GetUnicodeCategory(Char c) {
  if (IsLatin1(c)) {
    return GetLatin1UnicodeCategory(c);
  }
  return CharUnicodeInfo::GetUnicodeCategory((Int32)c);
}

UnicodeCategory Char::GetUnicodeCategory(String s, Int32 index) {
  if (s == nullptr) {
    rt::throw_exception<ArgumentNullException>("s");
  }
  if ((UInt32)index >= (UInt32)s->get_Length()) {
    rt::throw_exception<ArgumentOutOfRangeException>("index");
  }
  if (IsLatin1(s[index])) {
    return GetLatin1UnicodeCategory(s[index]);
  }
  return CharUnicodeInfo::GetUnicodeCategoryInternal(s, index);
}

Double Char::GetNumericValue(Char c) {
  return CharUnicodeInfo::GetNumericValue(c);
}

Double Char::GetNumericValue(String s, Int32 index) {
  if (s == nullptr) {
    rt::throw_exception<ArgumentNullException>("s");
  }
  if ((UInt32)index >= (UInt32)s->get_Length()) {
    rt::throw_exception<ArgumentOutOfRangeException>("index");
  }
  return CharUnicodeInfo::GetNumericValue(s, index);
}

Boolean Char::IsHighSurrogate(Char c) {
  return IsInRange(c, u'\xd800', u'\xdbff');
}

Boolean Char::IsHighSurrogate(String s, Int32 index) {
  if (s == nullptr) {
    rt::throw_exception<ArgumentNullException>("s");
  }
  if (index < 0 || index >= s->get_Length()) {
    rt::throw_exception<ArgumentOutOfRangeException>("index");
  }
  return IsHighSurrogate(s[index]);
}

Boolean Char::IsLowSurrogate(Char c) {
  return IsInRange(c, u'\xdc00', u'\xdfff');
}

Boolean Char::IsLowSurrogate(String s, Int32 index) {
  if (s == nullptr) {
    rt::throw_exception<ArgumentNullException>("s");
  }
  if (index < 0 || index >= s->get_Length()) {
    rt::throw_exception<ArgumentOutOfRangeException>("index");
  }
  return IsLowSurrogate(s[index]);
}

Boolean Char::IsSurrogatePair(String s, Int32 index) {
  if (s == nullptr) {
    rt::throw_exception<ArgumentNullException>("s");
  }
  if (index < 0 || index >= s->get_Length()) {
    rt::throw_exception<ArgumentOutOfRangeException>("index");
  }
  if (index + 1 < s->get_Length()) {
    return IsSurrogatePair(s[index], s[index + 1]);
  }
  return false;
}

Boolean Char::IsSurrogatePair(Char highSurrogate, Char lowSurrogate) {
  UInt32 num = (UInt32)(highSurrogate - 55296);
  UInt32 num2 = (UInt32)(lowSurrogate - 56320);
  return (num | num2) <= 1023;
}

String Char::ConvertFromUtf32(Int32 utf32) {
  if (!UnicodeUtility::IsValidUnicodeScalar((UInt32)utf32)) {
    rt::throw_exception<ArgumentOutOfRangeException>("utf32", SR::get_ArgumentOutOfRange_InvalidUTF32());
  }
  return Rune::UnsafeCreate((UInt32)utf32).ToString();
}

Int32 Char::ConvertToUtf32(Char highSurrogate, Char lowSurrogate) {
  UInt32 num = (UInt32)(highSurrogate - 55296);
  UInt32 num2 = (UInt32)(lowSurrogate - 56320);
  if ((num | num2) > 1023) {
    ConvertToUtf32_ThrowInvalidArgs(num);
  }
  return (Int32)(num << 10) + (lowSurrogate - 56320) + 65536;
}

void Char::ConvertToUtf32_ThrowInvalidArgs(UInt32 highSurrogateOffset) {
  if (highSurrogateOffset > 1023) {
    rt::throw_exception<ArgumentOutOfRangeException>("highSurrogate", SR::get_ArgumentOutOfRange_InvalidHighSurrogate());
  }
  rt::throw_exception<ArgumentOutOfRangeException>("lowSurrogate", SR::get_ArgumentOutOfRange_InvalidLowSurrogate());
}

Int32 Char::ConvertToUtf32(String s, Int32 index) {
  if (s == nullptr) {
    rt::throw_exception<ArgumentNullException>("s");
  }
  if (index < 0 || index >= s->get_Length()) {
    rt::throw_exception<ArgumentOutOfRangeException>("index", SR::get_ArgumentOutOfRange_Index());
  }
  Int32 num = s[index] - 55296;
  if (num >= 0 && num <= 2047) {
    if (num <= 1023) {
      if (index < s->get_Length() - 1) {
        Int32 num2 = s[index + 1] - 56320;
        if (num2 >= 0 && num2 <= 1023) {
          return num * 1024 + num2 + 65536;
        }
        rt::throw_exception<ArgumentException>(SR::Format(SR::get_Argument_InvalidHighSurrogate(), index), "s");
      }
      rt::throw_exception<ArgumentException>(SR::Format(SR::get_Argument_InvalidHighSurrogate(), index), "s");
    }
    rt::throw_exception<ArgumentException>(SR::Format(SR::get_Argument_InvalidLowSurrogate(), index), "s");
  }
  return s[index];
}

} // namespace System::Private::CoreLib::System::CharNamespace
