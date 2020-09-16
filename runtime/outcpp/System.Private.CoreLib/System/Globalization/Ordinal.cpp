#include "Ordinal-dep.h"

#include <System.Private.CoreLib/Internal/Runtime/CompilerServices/Unsafe-dep.h>
#include <System.Private.CoreLib/System/Byte-dep.h>
#include <System.Private.CoreLib/System/ExceptionArgument.h>
#include <System.Private.CoreLib/System/ExceptionResource.h>
#include <System.Private.CoreLib/System/Globalization/CompareInfo-dep.h>
#include <System.Private.CoreLib/System/Globalization/GlobalizationMode-dep.h>
#include <System.Private.CoreLib/System/Globalization/OrdinalCasing-dep.h>
#include <System.Private.CoreLib/System/Globalization/TextInfo-dep.h>
#include <System.Private.CoreLib/System/IntPtr-dep.h>
#include <System.Private.CoreLib/System/InvalidOperationException-dep.h>
#include <System.Private.CoreLib/System/Math-dep.h>
#include <System.Private.CoreLib/System/MemoryExtensions-dep.h>
#include <System.Private.CoreLib/System/ReadOnlySpan-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/Text/Unicode/Utf16Utility-dep.h>
#include <System.Private.CoreLib/System/ThrowHelper-dep.h>
#include <System.Private.CoreLib/System/UInt32-dep.h>
#include <System.Private.CoreLib/System/UInt64-dep.h>

namespace System::Private::CoreLib::System::Globalization::OrdinalNamespace {
using namespace Internal::Runtime::CompilerServices;
using namespace System::Text::Unicode;

Int32 Ordinal::CompareStringIgnoreCase(Char& strA, Int32 lengthA, Char& strB, Int32 lengthB) {
  Int32 num = Math::Min(lengthA, lengthB);
  Int32 num2 = num;
  Char& reference = strA;
  Char& reference2 = strB;
  Char c = GlobalizationMode::get_Invariant() ? 'ÿ' : '';
  while (num != 0 && reference <= c && reference2 <= c) {
    if (reference == reference2 || ((reference | 32) == (reference2 | 32) && (UInt32)((reference | 32) - 97) <= 25u)) {
      num--;
      reference = Unsafe::Add(reference, 1);
      reference2 = Unsafe::Add(reference2, 1);
      continue;
    }
    Int32 num3 = reference;
    Int32 num4 = reference2;
    if ((UInt32)(reference - 97) <= 25u) {
      num3 -= 32;
    }
    if ((UInt32)(reference2 - 97) <= 25u) {
      num4 -= 32;
    }
    return num3 - num4;
  }
  if (num == 0 || GlobalizationMode::get_Invariant()) {
    return lengthA - lengthB;
  }
  num2 -= num;
  return CompareStringIgnoreCaseNonAscii(reference, lengthA - num2, reference2, lengthB - num2);
}

Int32 Ordinal::CompareStringIgnoreCaseNonAscii(Char& strA, Int32 lengthA, Char& strB, Int32 lengthB) {
  if (GlobalizationMode::get_Invariant()) {
    return CompareIgnoreCaseInvariantMode(strA, lengthA, strB, lengthB);
  }
  if (GlobalizationMode::get_UseNls()) {
    return CompareInfo::in::NlsCompareStringOrdinalIgnoreCase(strA, lengthA, strB, lengthB);
  }
  return OrdinalCasing::CompareStringIgnoreCase(strA, lengthA, strB, lengthB);
}

Boolean Ordinal::EqualsIgnoreCase(Char& charA, Char& charB, Int32 length) {
  IntPtr zero = IntPtr::Zero;
  while (true) {
    if ((UInt32)length >= 4u) {
      UInt64 num = Unsafe::ReadUnaligned<UInt64>(Unsafe::As<Char, Byte>(Unsafe::AddByteOffset(charA, zero)));
      UInt64 num2 = Unsafe::ReadUnaligned<UInt64>(Unsafe::As<Char, Byte>(Unsafe::AddByteOffset(charB, zero)));
      UInt64 num3 = num | num2;
      if (!Utf16Utility::AllCharsInUInt32AreAscii((UInt32)((Int32)num3 | (Int32)(num3 >> 32)))) {
        break;
      }
      if (!Utf16Utility::UInt64OrdinalIgnoreCaseAscii(num, num2)) {
        return false;
      }
      zero += 8;
      length -= 4;
      continue;
    }
    if ((UInt32)length >= 2u) {
      UInt32 num4 = Unsafe::ReadUnaligned<UInt32>(Unsafe::As<Char, Byte>(Unsafe::AddByteOffset(charA, zero)));
      UInt32 num5 = Unsafe::ReadUnaligned<UInt32>(Unsafe::As<Char, Byte>(Unsafe::AddByteOffset(charB, zero)));
      if (!Utf16Utility::AllCharsInUInt32AreAscii(num4 | num5)) {
        break;
      }
      if (!Utf16Utility::UInt32OrdinalIgnoreCaseAscii(num4, num5)) {
        return false;
      }
      zero += 4;
      length -= 2;
    }
    if (length != 0) {
      UInt32 num6 = Unsafe::AddByteOffset(charA, zero);
      UInt32 num7 = Unsafe::AddByteOffset(charB, zero);
      if ((num6 | num7) > 127) {
        break;
      }
      if (num6 == num7) {
        return true;
      }
      num6 |= 32;
      if (num6 - 97 > 25) {
        return false;
      }
      if (num6 != (num7 | 32)) {
        return false;
      }
      return true;
    }
    return true;
  }
  return CompareStringIgnoreCase(Unsafe::AddByteOffset(charA, zero), length, Unsafe::AddByteOffset(charB, zero), length) == 0;
}

Int32 Ordinal::CompareIgnoreCaseInvariantMode(Char& strA, Int32 lengthA, Char& strB, Int32 lengthB) {
  Int32 num = Math::Min(lengthA, lengthB);
  Char& reference = strA;
  Char& reference2 = strB;
  while (num != 0) {
    if (reference == reference2) {
      num--;
      reference = Unsafe::Add(reference, 1);
      reference2 = Unsafe::Add(reference2, 1);
      continue;
    }
    Char c = OrdinalCasing::ToUpperInvariantMode(reference);
    Char c2 = OrdinalCasing::ToUpperInvariantMode(reference2);
    if (c == c2) {
      num--;
      reference = Unsafe::Add(reference, 1);
      reference2 = Unsafe::Add(reference2, 1);
      continue;
    }
    return c - c2;
  }
  return lengthA - lengthB;
}

Int32 Ordinal::IndexOf(String source, String value, Int32 startIndex, Int32 count, Boolean ignoreCase) {
  if (source == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::source);
  }
  if (value == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::value);
  }
  ReadOnlySpan<Char> slice;
  if (!source->TryGetSpan(startIndex, count, slice)) {
    if ((UInt32)startIndex > (UInt32)source->get_Length()) {
      ThrowHelper::ThrowArgumentOutOfRangeException(ExceptionArgument::startIndex, ExceptionResource::ArgumentOutOfRange_Index);
    } else {
      ThrowHelper::ThrowArgumentOutOfRangeException(ExceptionArgument::count, ExceptionResource::ArgumentOutOfRange_Count);
    }
  }
  Int32 num = ignoreCase ? IndexOfOrdinalIgnoreCase(slice, value) : MemoryExtensions::IndexOf(slice, value);
  if (num < 0) {
    return num;
  }
  return num + startIndex;
}

Int32 Ordinal::IndexOfOrdinalIgnoreCase(ReadOnlySpan<Char> source, ReadOnlySpan<Char> value) {
  if (value.get_Length() == 0) {
    return 0;
  }
  if (value.get_Length() > source.get_Length()) {
    return -1;
  }
  if (GlobalizationMode::get_Invariant()) {
    return CompareInfo::in::InvariantIndexOf(source, value, true);
  }
  if (GlobalizationMode::get_UseNls()) {
    return CompareInfo::in::NlsIndexOfOrdinalCore(source, value, true, true);
  }
  return OrdinalCasing::IndexOf(source, value);
}

Int32 Ordinal::LastIndexOfOrdinalIgnoreCase(ReadOnlySpan<Char> source, ReadOnlySpan<Char> value) {
  if (value.get_Length() == 0) {
    return source.get_Length();
  }
  if (value.get_Length() > source.get_Length()) {
    return -1;
  }
  if (GlobalizationMode::get_Invariant()) {
    return CompareInfo::in::InvariantIndexOf(source, value, true, false);
  }
  if (GlobalizationMode::get_UseNls()) {
    return CompareInfo::in::NlsIndexOfOrdinalCore(source, value, true, false);
  }
  return OrdinalCasing::LastIndexOf(source, value);
}

Int32 Ordinal::ToUpperOrdinal(ReadOnlySpan<Char> source, Span<Char> destination) {
  if (MemoryExtensions::Overlaps(source, destination)) {
    rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_SpanOverlappedOperation());
  }
  if (destination.get_Length() < source.get_Length()) {
    return -1;
  }
  if (GlobalizationMode::get_Invariant()) {
    OrdinalCasing::ToUpperInvariantMode(source, destination);
    return source.get_Length();
  }
  if (GlobalizationMode::get_UseNls()) {
    TextInfo::in::Invariant->ChangeCaseToUpper(source, destination);
    return source.get_Length();
  }
  OrdinalCasing::ToUpperOrdinal(source, destination);
  return source.get_Length();
}

} // namespace System::Private::CoreLib::System::Globalization::OrdinalNamespace
