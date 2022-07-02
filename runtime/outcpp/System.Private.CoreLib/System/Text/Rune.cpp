#include "Rune-dep.h"

#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ExceptionArgument.h>
#include <System.Private.CoreLib/System/FormattableString-dep.h>
#include <System.Private.CoreLib/System/Globalization/CharUnicodeInfo-dep.h>
#include <System.Private.CoreLib/System/Globalization/GlobalizationMode-dep.h>
#include <System.Private.CoreLib/System/Object-dep.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/FormattableStringFactory-dep.h>
#include <System.Private.CoreLib/System/SByte-dep.h>
#include <System.Private.CoreLib/System/Span-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/Text/Rune-dep.h>
#include <System.Private.CoreLib/System/Text/Unicode/Utf16Utility-dep.h>
#include <System.Private.CoreLib/System/Text/UnicodeUtility-dep.h>
#include <System.Private.CoreLib/System/ThrowHelper-dep.h>

namespace System::Private::CoreLib::System::Text::RuneNamespace {
using namespace System::Globalization;
using namespace System::Runtime::CompilerServices;
using namespace System::Text::Unicode;

ReadOnlySpan<Byte> Rune::get_AsciiCharInfo() {
  return rt::newarr<Array<Byte>>(128);
}

String Rune::get_DebuggerDisplay() {
  return FormattableString::in::Invariant(FormattableStringFactory::Create("U+{0:X4} '{1}'", rt::newarr<Array<Object>>(2, _value, IsValid(_value) ? ToString() : "�")));
}

Boolean Rune::get_IsAscii() {
  return UnicodeUtility::IsAsciiCodePoint(_value);
}

Boolean Rune::get_IsBmp() {
  return UnicodeUtility::IsBmpCodePoint(_value);
}

Int32 Rune::get_Plane() {
  return UnicodeUtility::GetPlane(_value);
}

Rune Rune::get_ReplacementChar() {
  return UnsafeCreate(65533u);
}

Int32 Rune::get_Utf16SequenceLength() {
  return UnicodeUtility::GetUtf16SequenceLength(_value);
}

Int32 Rune::get_Utf8SequenceLength() {
  return UnicodeUtility::GetUtf8SequenceLength(_value);
}

Int32 Rune::get_Value() {
  return (Int32)_value;
}

Rune::Rune(Char ch) {
  if (UnicodeUtility::IsSurrogateCodePoint(ch)) {
    ThrowHelper::ThrowArgumentOutOfRangeException(ExceptionArgument::ch);
  }
  _value = ch;
}

Rune::Rune(Char highSurrogate, Char lowSurrogate) {
}

Rune::Rune(Int32 value) {
}

Rune::Rune(UInt32 value) {
  if (!UnicodeUtility::IsValidUnicodeScalar(value)) {
    ThrowHelper::ThrowArgumentOutOfRangeException(ExceptionArgument::value);
  }
  _value = value;
}

Rune::Rune(UInt32 scalarValue, Boolean unused) {
  _value = scalarValue;
}

Boolean Rune::op_Equality(Rune left, Rune right) {
  return left._value == right._value;
}

Boolean Rune::op_Inequality(Rune left, Rune right) {
  return left._value != right._value;
}

Boolean Rune::op_LessThan(Rune left, Rune right) {
  return left._value < right._value;
}

Boolean Rune::op_LessThanOrEqual(Rune left, Rune right) {
  return left._value <= right._value;
}

Boolean Rune::op_GreaterThan(Rune left, Rune right) {
  return left._value > right._value;
}

Boolean Rune::op_GreaterThanOrEqual(Rune left, Rune right) {
  return left._value >= right._value;
}

Rune Rune::op_Explicit(Char ch) {
  return Rune(ch);
}

Rune Rune::op_Explicit(UInt32 value) {
  return Rune(value);
}

Rune Rune::op_Explicit(Int32 value) {
  return Rune(value);
}

Rune Rune::ChangeCaseCultureAware(Rune rune, TextInfo textInfo, Boolean toUpper) {
  Char as[2] = {};
  Span<Char> span = as;
  Char is[2] = {};
  Span<Char> destination = is;
  Int32 length = rune.EncodeToUtf16(span);
  span = span.Slice(0, length);
  destination = destination.Slice(0, length);
  if (toUpper) {
    textInfo->ChangeCaseToUpper(span, destination);
  } else {
    textInfo->ChangeCaseToLower(span, destination);
  }
  if (rune.get_IsBmp()) {
    return UnsafeCreate(destination[0]);
  }
  return UnsafeCreate(UnicodeUtility::GetScalarFromUtf16SurrogatePair(destination[0], destination[1]));
}

Int32 Rune::CompareTo(Rune other) {
  return get_Value() - other.get_Value();
}

OperationStatus Rune::DecodeFromUtf16(ReadOnlySpan<Char> source, Rune& result, Int32& charsConsumed) {
  if (!source.get_IsEmpty()) {
    Char c = source[0];
    if (TryCreate(c, result)) {
      charsConsumed = 1;
      return OperationStatus::Done;
    }
    if (1u < (UInt32)source.get_Length()) {
      Char lowSurrogate = source[1];
      if (TryCreate(c, lowSurrogate, result)) {
        charsConsumed = 2;
        return OperationStatus::Done;
      }
    } else if (Char::IsHighSurrogate(c)) {
      goto IL_004c;
    }

    charsConsumed = 1;
    result = get_ReplacementChar();
    return OperationStatus::InvalidData;
  }
  goto IL_004c;

IL_004c:
  charsConsumed = source.get_Length();
  result = get_ReplacementChar();
  return OperationStatus::NeedMoreData;
}

OperationStatus Rune::DecodeFromUtf8(ReadOnlySpan<Byte> source, Rune& result, Int32& bytesConsumed) {
  Int32 num = 0;
  UInt32 num2;
  if ((UInt32)num < (UInt32)source.get_Length()) {
    num2 = source[num];
    if (UnicodeUtility::IsAsciiCodePoint(num2)) {
      goto IL_0021;
    }
    if (UnicodeUtility::IsInRangeInclusive(num2, 194u, 244u)) {
      num2 = num2 - 194 << 6;
      num++;
      if ((UInt32)num >= (UInt32)source.get_Length()) {
        goto IL_0163;
      }
      Int32 num3 = (SByte)source[num];
      if (num3 < -64) {
        num2 += (UInt32)num3;
        num2 += 128;
        num2 += 128;
        if (num2 < 2048) {
          goto IL_0021;
        }
        if (UnicodeUtility::IsInRangeInclusive(num2, 2080u, 3343u) && !UnicodeUtility::IsInRangeInclusive(num2, 2912u, 2943u) && !UnicodeUtility::IsInRangeInclusive(num2, 3072u, 3087u)) {
          num++;
          if ((UInt32)num >= (UInt32)source.get_Length()) {
            goto IL_0163;
          }
          num3 = (SByte)source[num];
          if (num3 < -64) {
            num2 <<= 6;
            num2 += (UInt32)num3;
            num2 += 128;
            num2 -= 131072;
            if (num2 > 65535) {
              num++;
              if ((UInt32)num >= (UInt32)source.get_Length()) {
                goto IL_0163;
              }
              num3 = (SByte)source[num];
              if (num3 >= -64) {
                goto IL_0153;
              }
              num2 <<= 6;
              num2 += (UInt32)num3;
              num2 += 128;
              num2 -= 4194304;
            }
            goto IL_0021;
          }
        }
      }
    } else {
      num = 1;
    }
    goto IL_0153;
  }
  goto IL_0163;

IL_0021:
  bytesConsumed = num + 1;
  result = UnsafeCreate(num2);
  return OperationStatus::Done;

IL_0153:
  bytesConsumed = num;
  result = get_ReplacementChar();
  return OperationStatus::InvalidData;

IL_0163:
  bytesConsumed = num;
  result = get_ReplacementChar();
  return OperationStatus::NeedMoreData;
}

OperationStatus Rune::DecodeLastFromUtf16(ReadOnlySpan<Char> source, Rune& result, Int32& charsConsumed) {
  Int32 num = source.get_Length() - 1;
  if ((UInt32)num < (UInt32)source.get_Length()) {
    Char c = source[num];
    if (TryCreate(c, result)) {
      charsConsumed = 1;
      return OperationStatus::Done;
    }
    if (Char::IsLowSurrogate(c)) {
      num--;
      if ((UInt32)num < (UInt32)source.get_Length()) {
        Char highSurrogate = source[num];
        if (TryCreate(highSurrogate, c, result)) {
          charsConsumed = 2;
          return OperationStatus::Done;
        }
      }
      charsConsumed = 1;
      result = get_ReplacementChar();
      return OperationStatus::InvalidData;
    }
  }
  charsConsumed = (Int32)((UInt32)(-source.get_Length()) >> 31);
  result = get_ReplacementChar();
  return OperationStatus::NeedMoreData;
}

OperationStatus Rune::DecodeLastFromUtf8(ReadOnlySpan<Byte> source, Rune& value, Int32& bytesConsumed) {
  Int32 num = source.get_Length() - 1;
  if ((UInt32)num < (UInt32)source.get_Length()) {
    UInt32 num2 = source[num];
    if (UnicodeUtility::IsAsciiCodePoint(num2)) {
      bytesConsumed = 1;
      value = UnsafeCreate(num2);
      return OperationStatus::Done;
    }
    if (((Byte)num2 & 64u) != 0) {
      return DecodeFromUtf8(source.Slice(num), value, bytesConsumed);
    }
    Int32 num3 = 3;
    OperationStatus result2;
    Rune result;
    Int32 bytesConsumed2;
    while (true) {
      if (num3 > 0) {
        num--;
        if ((UInt32)num < (UInt32)source.get_Length()) {
          if ((SByte)source[num] < -64) {
            num3--;
            continue;
          }
          source = source.Slice(num);
          result2 = DecodeFromUtf8(source, result, bytesConsumed2);
          if (bytesConsumed2 == source.get_Length()) {
            break;
          }
        }
      }
      value = get_ReplacementChar();
      bytesConsumed = 1;
      return OperationStatus::InvalidData;
    }
    bytesConsumed = bytesConsumed2;
    value = result;
    return result2;
  }
  value = get_ReplacementChar();
  bytesConsumed = 0;
  return OperationStatus::NeedMoreData;
}

Int32 Rune::EncodeToUtf16(Span<Char> destination) {
  Int32 charsWritten;
  if (!TryEncodeToUtf16(destination, charsWritten)) {
    ThrowHelper::ThrowArgumentException_DestinationTooShort();
  }
  return charsWritten;
}

Int32 Rune::EncodeToUtf8(Span<Byte> destination) {
  Int32 bytesWritten;
  if (!TryEncodeToUtf8(destination, bytesWritten)) {
    ThrowHelper::ThrowArgumentException_DestinationTooShort();
  }
  return bytesWritten;
}

Boolean Rune::Equals(Object obj) {
  if (rt::is<Rune>(obj)) {
    Rune other = (Rune)obj;
    return Equals(other);
  }
  return false;
}

Boolean Rune::Equals(Rune other) {
  return *this == other;
}

Int32 Rune::GetHashCode() {
  return get_Value();
}

Rune Rune::GetRuneAt(String input, Int32 index) {
  Int32 num = ReadRuneFromString(input, index);
  if (num < 0) {
    ThrowHelper::ThrowArgumentException_CannotExtractScalar(ExceptionArgument::index);
  }
  return UnsafeCreate((UInt32)num);
}

Boolean Rune::IsValid(Int32 value) {
  return IsValid((UInt32)value);
}

Boolean Rune::IsValid(UInt32 value) {
  return UnicodeUtility::IsValidUnicodeScalar(value);
}

Int32 Rune::ReadFirstRuneFromUtf16Buffer(ReadOnlySpan<Char> input) {
  if (input.get_IsEmpty()) {
    return -1;
  }
  UInt32 num = input[0];
  if (UnicodeUtility::IsSurrogateCodePoint(num)) {
    if (!UnicodeUtility::IsHighSurrogateCodePoint(num)) {
      return -1;
    }
    if (1u >= (UInt32)input.get_Length()) {
      return -1;
    }
    UInt32 num2 = input[1];
    if (!UnicodeUtility::IsLowSurrogateCodePoint(num2)) {
      return -1;
    }
    num = UnicodeUtility::GetScalarFromUtf16SurrogatePair(num, num2);
  }
  return (Int32)num;
}

Int32 Rune::ReadRuneFromString(String input, Int32 index) {
  if (input == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::input);
  }
  if ((UInt32)index >= (UInt32)input->get_Length()) {
    ThrowHelper::ThrowArgumentOutOfRange_IndexException();
  }
  UInt32 num = input[index];
  if (UnicodeUtility::IsSurrogateCodePoint(num)) {
    if (!UnicodeUtility::IsHighSurrogateCodePoint(num)) {
      return -1;
    }
    index++;
    if ((UInt32)index >= (UInt32)input->get_Length()) {
      return -1;
    }
    UInt32 num2 = input[index];
    if (!UnicodeUtility::IsLowSurrogateCodePoint(num2)) {
      return -1;
    }
    num = UnicodeUtility::GetScalarFromUtf16SurrogatePair(num, num2);
  }
  return (Int32)num;
}

String Rune::ToString() {
  if (get_IsBmp()) {
    return String::in::CreateFromChar((Char)_value);
  }
  Char highSurrogateCodePoint;
  Char lowSurrogateCodePoint;
  UnicodeUtility::GetUtf16SurrogatesFromSupplementaryPlaneScalar(_value, highSurrogateCodePoint, lowSurrogateCodePoint);
  return String::in::CreateFromChar(highSurrogateCodePoint, lowSurrogateCodePoint);
}

Boolean Rune::TryCreate(Char ch, Rune& result) {
  if (!UnicodeUtility::IsSurrogateCodePoint(ch)) {
    result = UnsafeCreate(ch);
    return true;
  }
  result = rt::default__;
  return false;
}

Boolean Rune::TryCreate(Char highSurrogate, Char lowSurrogate, Rune& result) {
  UInt32 num = (UInt32)(highSurrogate - 55296);
  UInt32 num2 = (UInt32)(lowSurrogate - 56320);
  if ((num | num2) <= 1023) {
    result = UnsafeCreate((UInt32)((Int32)(num << 10) + (lowSurrogate - 56320) + 65536));
    return true;
  }
  result = rt::default__;
  return false;
}

Boolean Rune::TryCreate(Int32 value, Rune& result) {
  return TryCreate((UInt32)value, result);
}

Boolean Rune::TryCreate(UInt32 value, Rune& result) {
  if (UnicodeUtility::IsValidUnicodeScalar(value)) {
    result = UnsafeCreate(value);
    return true;
  }
  result = rt::default__;
  return false;
}

Boolean Rune::TryEncodeToUtf16(Span<Char> destination, Int32& charsWritten) {
  if (destination.get_Length() >= 1) {
    if (get_IsBmp()) {
      destination[0] = (Char)_value;
      charsWritten = 1;
      return true;
    }
    if (destination.get_Length() >= 2) {
      UnicodeUtility::GetUtf16SurrogatesFromSupplementaryPlaneScalar(_value, destination[0], destination[1]);
      charsWritten = 2;
      return true;
    }
  }
  charsWritten = 0;
  return false;
}

Boolean Rune::TryEncodeToUtf8(Span<Byte> destination, Int32& bytesWritten) {
  if (destination.get_Length() >= 1) {
    if (get_IsAscii()) {
      destination[0] = (Byte)_value;
      bytesWritten = 1;
      return true;
    }
    if (destination.get_Length() >= 2) {
      if (_value <= 2047) {
        destination[0] = (Byte)(_value + 12288 >> 6);
        destination[1] = (Byte)((_value & 63) + 128);
        bytesWritten = 2;
        return true;
      }
      if (destination.get_Length() >= 3) {
        if (_value <= 65535) {
          destination[0] = (Byte)(_value + 917504 >> 12);
          destination[1] = (Byte)(((_value & 4032) >> 6) + 128);
          destination[2] = (Byte)((_value & 63) + 128);
          bytesWritten = 3;
          return true;
        }
        if (destination.get_Length() >= 4) {
          destination[0] = (Byte)(_value + 62914560 >> 18);
          destination[1] = (Byte)(((_value & 258048) >> 12) + 128);
          destination[2] = (Byte)(((_value & 4032) >> 6) + 128);
          destination[3] = (Byte)((_value & 63) + 128);
          bytesWritten = 4;
          return true;
        }
      }
    }
  }
  bytesWritten = 0;
  return false;
}

Boolean Rune::TryGetRuneAt(String input, Int32 index, Rune& value) {
  Int32 num = ReadRuneFromString(input, index);
  if (num >= 0) {
    value = UnsafeCreate((UInt32)num);
    return true;
  }
  value = rt::default__;
  return false;
}

Rune Rune::UnsafeCreate(UInt32 scalarValue) {
  return Rune(scalarValue, false);
}

Double Rune::GetNumericValue(Rune value) {
  if (value.get_IsAscii()) {
    UInt32 num = value._value - 48;
    if (num > 9) {
      return -1;
    }
    return num;
  }
  return CharUnicodeInfo::GetNumericValue(value.get_Value());
}

UnicodeCategory Rune::GetUnicodeCategory(Rune value) {
  if (value.get_IsAscii()) {
    return (UnicodeCategory)(get_AsciiCharInfo()[value.get_Value()] & 31);
  }
  return GetUnicodeCategoryNonAscii(value);
}

UnicodeCategory Rune::GetUnicodeCategoryNonAscii(Rune value) {
  return CharUnicodeInfo::GetUnicodeCategory(value.get_Value());
}

Boolean Rune::IsCategoryLetter(UnicodeCategory category) {
  return UnicodeUtility::IsInRangeInclusive((UInt32)category, 0u, 4u);
}

Boolean Rune::IsCategoryLetterOrDecimalDigit(UnicodeCategory category) {
  if (!UnicodeUtility::IsInRangeInclusive((UInt32)category, 0u, 4u)) {
    return category == UnicodeCategory::DecimalDigitNumber;
  }
  return true;
}

Boolean Rune::IsCategoryNumber(UnicodeCategory category) {
  return UnicodeUtility::IsInRangeInclusive((UInt32)category, 8u, 10u);
}

Boolean Rune::IsCategoryPunctuation(UnicodeCategory category) {
  return UnicodeUtility::IsInRangeInclusive((UInt32)category, 18u, 24u);
}

Boolean Rune::IsCategorySeparator(UnicodeCategory category) {
  return UnicodeUtility::IsInRangeInclusive((UInt32)category, 11u, 13u);
}

Boolean Rune::IsCategorySymbol(UnicodeCategory category) {
  return UnicodeUtility::IsInRangeInclusive((UInt32)category, 25u, 28u);
}

Boolean Rune::IsControl(Rune value) {
  return ((value._value + 1) & 4294967167u) <= 32;
}

Boolean Rune::IsDigit(Rune value) {
  if (value.get_IsAscii()) {
    return UnicodeUtility::IsInRangeInclusive(value._value, 48u, 57u);
  }
  return GetUnicodeCategoryNonAscii(value) == UnicodeCategory::DecimalDigitNumber;
}

Boolean Rune::IsLetter(Rune value) {
  if (value.get_IsAscii()) {
    return ((value._value - 65) & 4294967263u) <= 25;
  }
  return IsCategoryLetter(GetUnicodeCategoryNonAscii(value));
}

Boolean Rune::IsLetterOrDigit(Rune value) {
  if (value.get_IsAscii()) {
    return (get_AsciiCharInfo()[value.get_Value()] & 64) != 0;
  }
  return IsCategoryLetterOrDecimalDigit(GetUnicodeCategoryNonAscii(value));
}

Boolean Rune::IsLower(Rune value) {
  if (value.get_IsAscii()) {
    return UnicodeUtility::IsInRangeInclusive(value._value, 97u, 122u);
  }
  return GetUnicodeCategoryNonAscii(value) == UnicodeCategory::LowercaseLetter;
}

Boolean Rune::IsNumber(Rune value) {
  if (value.get_IsAscii()) {
    return UnicodeUtility::IsInRangeInclusive(value._value, 48u, 57u);
  }
  return IsCategoryNumber(GetUnicodeCategoryNonAscii(value));
}

Boolean Rune::IsPunctuation(Rune value) {
  return IsCategoryPunctuation(GetUnicodeCategory(value));
}

Boolean Rune::IsSeparator(Rune value) {
  return IsCategorySeparator(GetUnicodeCategory(value));
}

Boolean Rune::IsSymbol(Rune value) {
  return IsCategorySymbol(GetUnicodeCategory(value));
}

Boolean Rune::IsUpper(Rune value) {
  if (value.get_IsAscii()) {
    return UnicodeUtility::IsInRangeInclusive(value._value, 65u, 90u);
  }
  return GetUnicodeCategoryNonAscii(value) == UnicodeCategory::UppercaseLetter;
}

Boolean Rune::IsWhiteSpace(Rune value) {
  if (value.get_IsAscii()) {
    return (get_AsciiCharInfo()[value.get_Value()] & 128) != 0;
  }
  if (value.get_IsBmp()) {
    return CharUnicodeInfo::GetIsWhiteSpace((Char)value._value);
  }
  return false;
}

Rune Rune::ToLower(Rune value, CultureInfo culture) {
  if (culture == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::culture);
  }
  if (GlobalizationMode::get_Invariant()) {
    return ToLowerInvariant(value);
  }
  return ChangeCaseCultureAware(value, culture->get_TextInfo(), false);
}

Rune Rune::ToLowerInvariant(Rune value) {
  if (value.get_IsAscii()) {
    return UnsafeCreate(Utf16Utility::ConvertAllAsciiCharsInUInt32ToLowercase(value._value));
  }
  if (GlobalizationMode::get_Invariant()) {
    return value;
  }
  return ChangeCaseCultureAware(value, TextInfo::in::Invariant, false);
}

Rune Rune::ToUpper(Rune value, CultureInfo culture) {
  if (culture == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::culture);
  }
  if (GlobalizationMode::get_Invariant()) {
    return ToUpperInvariant(value);
  }
  return ChangeCaseCultureAware(value, culture->get_TextInfo(), true);
}

Rune Rune::ToUpperInvariant(Rune value) {
  if (value.get_IsAscii()) {
    return UnsafeCreate(Utf16Utility::ConvertAllAsciiCharsInUInt32ToUppercase(value._value));
  }
  if (GlobalizationMode::get_Invariant()) {
    return value;
  }
  return ChangeCaseCultureAware(value, TextInfo::in::Invariant, true);
}

Int32 Rune::CompareToOfIComparable(Object obj) {
  if (obj == nullptr) {
    return 1;
  }
  if (rt::is<Rune>(obj)) {
    Rune other = (Rune)obj;
    return CompareTo(other);
  }
  rt::throw_exception<ArgumentException>(SR::get_Arg_MustBeRune());
}

} // namespace System::Private::CoreLib::System::Text::RuneNamespace
