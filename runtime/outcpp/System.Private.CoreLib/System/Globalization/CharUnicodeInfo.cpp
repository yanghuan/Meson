#include "CharUnicodeInfo-dep.h"

#include <System.Private.CoreLib/Internal/Runtime/CompilerServices/Unsafe-dep.h>
#include <System.Private.CoreLib/System/BitConverter-dep.h>
#include <System.Private.CoreLib/System/Buffers/Binary/BinaryPrimitives-dep.h>
#include <System.Private.CoreLib/System/ExceptionArgument.h>
#include <System.Private.CoreLib/System/Int64-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/MemoryMarshal-dep.h>
#include <System.Private.CoreLib/System/SByte-dep.h>
#include <System.Private.CoreLib/System/Text/UnicodeUtility-dep.h>
#include <System.Private.CoreLib/System/ThrowHelper-dep.h>
#include <System.Private.CoreLib/System/UInt16-dep.h>
#include <System.Private.CoreLib/System/UInt32-dep.h>
#include <System.Private.CoreLib/System/UInt64-dep.h>
#include <System.Private.CoreLib/System/UIntPtr-dep.h>

namespace System::Private::CoreLib::System::Globalization::CharUnicodeInfoNamespace {
using namespace Internal::Runtime::CompilerServices;
using namespace System::Buffers::Binary;
using namespace System::Runtime::InteropServices;
using namespace System::Text;

ReadOnlySpan<Byte> CharUnicodeInfo::get_CategoryCasingLevel1Index() {
  return rt::newarr<Array<Byte>>(2176);
}

ReadOnlySpan<Byte> CharUnicodeInfo::get_CategoryCasingLevel2Index() {
  return rt::newarr<Array<Byte>>(6272);
}

ReadOnlySpan<Byte> CharUnicodeInfo::get_CategoryCasingLevel3Index() {
  return rt::newarr<Array<Byte>>(11184);
}

ReadOnlySpan<Byte> CharUnicodeInfo::get_CategoriesValues() {
  return rt::newarr<Array<Byte>>(56);
}

ReadOnlySpan<Byte> CharUnicodeInfo::get_NumericGraphemeLevel1Index() {
  return rt::newarr<Array<Byte>>(2176);
}

ReadOnlySpan<Byte> CharUnicodeInfo::get_NumericGraphemeLevel2Index() {
  return rt::newarr<Array<Byte>>(4928);
}

ReadOnlySpan<Byte> CharUnicodeInfo::get_NumericGraphemeLevel3Index() {
  return rt::newarr<Array<Byte>>(6096);
}

ReadOnlySpan<Byte> CharUnicodeInfo::get_DigitValues() {
  return rt::newarr<Array<Byte>>(177);
}

ReadOnlySpan<Byte> CharUnicodeInfo::get_NumericValues() {
  return rt::newarr<Array<Byte>>(1416);
}

ReadOnlySpan<Byte> CharUnicodeInfo::get_GraphemeSegmentationValues() {
  return rt::newarr<Array<Byte>>(177);
}

StrongBidiCategory CharUnicodeInfo::GetBidiCategory(String s, Int32 index) {
  if (s == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::s);
  }
  if ((UInt32)index >= (UInt32)s->get_Length()) {
    ThrowHelper::ThrowArgumentOutOfRangeException(ExceptionArgument::index);
  }
  return GetBidiCategoryNoBoundsChecks((UInt32)GetCodePointFromString(s, index));
}

StrongBidiCategory CharUnicodeInfo::GetBidiCategory(StringBuilder s, Int32 index) {
  Int32 num = s[index];
  if (index < s->get_Length() - 1) {
    Int32 num2 = num - 55296;
    if ((UInt32)num2 <= 1023u) {
      Int32 num3 = s[index + 1] - 56320;
      if ((UInt32)num3 <= 1023u) {
        num = (num2 << 10) + num3 + 65536;
      }
    }
  }
  return GetBidiCategoryNoBoundsChecks((UInt32)num);
}

StrongBidiCategory CharUnicodeInfo::GetBidiCategoryNoBoundsChecks(UInt32 codePoint) {
  UIntPtr categoryCasingTableOffsetNoBoundsChecks = GetCategoryCasingTableOffsetNoBoundsChecks(codePoint);
  return (StrongBidiCategory)(Unsafe::AddByteOffset(MemoryMarshal::GetReference(get_CategoriesValues()), (UIntPtr)categoryCasingTableOffsetNoBoundsChecks) & 96);
}

Int32 CharUnicodeInfo::GetDecimalDigitValue(Char ch) {
  return GetDecimalDigitValueInternalNoBoundsCheck(ch);
}

Int32 CharUnicodeInfo::GetDecimalDigitValue(String s, Int32 index) {
  if (s == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::s);
  }
  if ((UInt32)index >= (UInt32)s->get_Length()) {
    ThrowHelper::ThrowArgumentOutOfRangeException(ExceptionArgument::index);
  }
  return GetDecimalDigitValueInternalNoBoundsCheck((UInt32)GetCodePointFromString(s, index));
}

Int32 CharUnicodeInfo::GetDecimalDigitValueInternalNoBoundsCheck(UInt32 codePoint) {
  UIntPtr numericGraphemeTableOffsetNoBoundsChecks = GetNumericGraphemeTableOffsetNoBoundsChecks(codePoint);
  UInt32 num = Unsafe::AddByteOffset(MemoryMarshal::GetReference(get_DigitValues()), (UIntPtr)numericGraphemeTableOffsetNoBoundsChecks);
  return (Int32)((num >> 4) - 1);
}

Int32 CharUnicodeInfo::GetDigitValue(Char ch) {
  return GetDigitValueInternalNoBoundsCheck(ch);
}

Int32 CharUnicodeInfo::GetDigitValue(String s, Int32 index) {
  if (s == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::s);
  }
  if ((UInt32)index >= (UInt32)s->get_Length()) {
    ThrowHelper::ThrowArgumentOutOfRangeException(ExceptionArgument::index);
  }
  return GetDigitValueInternalNoBoundsCheck((UInt32)GetCodePointFromString(s, index));
}

Int32 CharUnicodeInfo::GetDigitValueInternalNoBoundsCheck(UInt32 codePoint) {
  UIntPtr numericGraphemeTableOffsetNoBoundsChecks = GetNumericGraphemeTableOffsetNoBoundsChecks(codePoint);
  Int32 num = Unsafe::AddByteOffset(MemoryMarshal::GetReference(get_DigitValues()), (UIntPtr)numericGraphemeTableOffsetNoBoundsChecks);
  return (num & 15) - 1;
}

GraphemeClusterBreakType CharUnicodeInfo::GetGraphemeClusterBreakType(Rune rune) {
  UIntPtr numericGraphemeTableOffsetNoBoundsChecks = GetNumericGraphemeTableOffsetNoBoundsChecks((UInt32)rune.get_Value());
  return (GraphemeClusterBreakType)Unsafe::AddByteOffset(MemoryMarshal::GetReference(get_GraphemeSegmentationValues()), (UIntPtr)numericGraphemeTableOffsetNoBoundsChecks);
}

Boolean CharUnicodeInfo::GetIsWhiteSpace(Char ch) {
  UIntPtr categoryCasingTableOffsetNoBoundsChecks = GetCategoryCasingTableOffsetNoBoundsChecks(ch);
  return (SByte)Unsafe::AddByteOffset(MemoryMarshal::GetReference(get_CategoriesValues()), (UIntPtr)categoryCasingTableOffsetNoBoundsChecks) < 0;
}

Double CharUnicodeInfo::GetNumericValue(Char ch) {
  return GetNumericValueNoBoundsCheck(ch);
}

Double CharUnicodeInfo::GetNumericValue(Int32 codePoint) {
  if (!UnicodeUtility::IsValidCodePoint((UInt32)codePoint)) {
    ThrowHelper::ThrowArgumentOutOfRangeException(ExceptionArgument::codePoint);
  }
  return GetNumericValueNoBoundsCheck((UInt32)codePoint);
}

Double CharUnicodeInfo::GetNumericValue(String s, Int32 index) {
  if (s == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::s);
  }
  if ((UInt32)index >= (UInt32)s->get_Length()) {
    ThrowHelper::ThrowArgumentOutOfRangeException(ExceptionArgument::index);
  }
  return GetNumericValueNoBoundsCheck((UInt32)GetCodePointFromString(s, index));
}

Double CharUnicodeInfo::GetNumericValueNoBoundsCheck(UInt32 codePoint) {
  UIntPtr numericGraphemeTableOffsetNoBoundsChecks = GetNumericGraphemeTableOffsetNoBoundsChecks(codePoint);
  Byte& source = Unsafe::AddByteOffset(MemoryMarshal::GetReference(get_NumericValues()), (UIntPtr)((UInt64)(Int64)(UInt64)numericGraphemeTableOffsetNoBoundsChecks * 8));
  if (BitConverter::IsLittleEndian) {
    return Unsafe::ReadUnaligned<Double>(source);
  }
  UInt64 value = Unsafe::ReadUnaligned<UInt64>(source);
  value = BinaryPrimitives::ReverseEndianness(value);
  return Unsafe::As<UInt64, Double>(value);
}

UnicodeCategory CharUnicodeInfo::GetUnicodeCategory(Char ch) {
  return GetUnicodeCategoryNoBoundsChecks(ch);
}

UnicodeCategory CharUnicodeInfo::GetUnicodeCategory(Int32 codePoint) {
  if (!UnicodeUtility::IsValidCodePoint((UInt32)codePoint)) {
    ThrowHelper::ThrowArgumentOutOfRangeException(ExceptionArgument::codePoint);
  }
  return GetUnicodeCategoryNoBoundsChecks((UInt32)codePoint);
}

UnicodeCategory CharUnicodeInfo::GetUnicodeCategory(String s, Int32 index) {
  if (s == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::s);
  }
  if ((UInt32)index >= (UInt32)s->get_Length()) {
    ThrowHelper::ThrowArgumentOutOfRangeException(ExceptionArgument::index);
  }
  return GetUnicodeCategoryInternal(s, index);
}

UnicodeCategory CharUnicodeInfo::GetUnicodeCategoryInternal(String value, Int32 index) {
  return GetUnicodeCategoryNoBoundsChecks((UInt32)GetCodePointFromString(value, index));
}

UnicodeCategory CharUnicodeInfo::GetUnicodeCategoryInternal(String str, Int32 index, Int32& charLength) {
  UInt32 codePointFromString = (UInt32)GetCodePointFromString(str, index);
  charLength = ((codePointFromString < 65536) ? 1 : 2);
  return GetUnicodeCategoryNoBoundsChecks(codePointFromString);
}

UnicodeCategory CharUnicodeInfo::GetUnicodeCategoryNoBoundsChecks(UInt32 codePoint) {
  UIntPtr categoryCasingTableOffsetNoBoundsChecks = GetCategoryCasingTableOffsetNoBoundsChecks(codePoint);
  return (UnicodeCategory)(Unsafe::AddByteOffset(MemoryMarshal::GetReference(get_CategoriesValues()), (UIntPtr)categoryCasingTableOffsetNoBoundsChecks) & 31);
}

Int32 CharUnicodeInfo::GetCodePointFromString(String s, Int32 index) {
  Int32 num = 0;
  if ((UInt32)index < (UInt32)s->get_Length()) {
    num = s[index];
    Int32 num2 = num - 55296;
    if ((UInt32)num2 <= 1023u) {
      index++;
      if ((UInt32)index < (UInt32)s->get_Length()) {
        Int32 num3 = s[index] - 56320;
        if ((UInt32)num3 <= 1023u) {
          num = (num2 << 10) + num3 + 65536;
        }
      }
    }
  }
  return num;
}

UIntPtr CharUnicodeInfo::GetCategoryCasingTableOffsetNoBoundsChecks(UInt32 codePoint) {
  UInt32 num = Unsafe::AddByteOffset(MemoryMarshal::GetReference(get_CategoryCasingLevel1Index()), (UIntPtr)codePoint >> 9);
  Byte& source = Unsafe::AddByteOffset(MemoryMarshal::GetReference(get_CategoryCasingLevel2Index()), (UIntPtr)(num << 6) + ((codePoint >> 3) & 62));
  num = ((!BitConverter::IsLittleEndian) ? BinaryPrimitives::ReverseEndianness(Unsafe::ReadUnaligned<UInt16>(source)) : Unsafe::ReadUnaligned<UInt16>(source));
  return Unsafe::AddByteOffset(MemoryMarshal::GetReference(get_CategoryCasingLevel3Index()), (UIntPtr)(num << 4) + (codePoint & 15));
}

UIntPtr CharUnicodeInfo::GetNumericGraphemeTableOffsetNoBoundsChecks(UInt32 codePoint) {
  UInt32 num = Unsafe::AddByteOffset(MemoryMarshal::GetReference(get_NumericGraphemeLevel1Index()), (UIntPtr)codePoint >> 9);
  Byte& source = Unsafe::AddByteOffset(MemoryMarshal::GetReference(get_NumericGraphemeLevel2Index()), (UIntPtr)(num << 6) + ((codePoint >> 3) & 62));
  num = ((!BitConverter::IsLittleEndian) ? BinaryPrimitives::ReverseEndianness(Unsafe::ReadUnaligned<UInt16>(source)) : Unsafe::ReadUnaligned<UInt16>(source));
  return Unsafe::AddByteOffset(MemoryMarshal::GetReference(get_NumericGraphemeLevel3Index()), (UIntPtr)(num << 4) + (codePoint & 15));
}

} // namespace System::Private::CoreLib::System::Globalization::CharUnicodeInfoNamespace
