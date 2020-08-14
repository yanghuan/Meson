#include "CompareInfo-dep.h"

#include <System.Private.CoreLib/Internal/Runtime/CompilerServices/Unsafe-dep.h>
#include <System.Private.CoreLib/Interop-dep.h>
#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/Buffers/ArrayPool-dep.h>
#include <System.Private.CoreLib/System/Buffers/Binary/BinaryPrimitives-dep.h>
#include <System.Private.CoreLib/System/Byte-dep.h>
#include <System.Private.CoreLib/System/Collections/Generic/Dictionary-dep.h>
#include <System.Private.CoreLib/System/Environment-dep.h>
#include <System.Private.CoreLib/System/ExceptionArgument.h>
#include <System.Private.CoreLib/System/ExceptionResource.h>
#include <System.Private.CoreLib/System/Globalization/CompareInfo-dep.h>
#include <System.Private.CoreLib/System/Globalization/CompareOptions.h>
#include <System.Private.CoreLib/System/Globalization/CultureData-dep.h>
#include <System.Private.CoreLib/System/Globalization/CultureInfo-dep.h>
#include <System.Private.CoreLib/System/Globalization/GlobalizationMode-dep.h>
#include <System.Private.CoreLib/System/Guid-dep.h>
#include <System.Private.CoreLib/System/Marvin-dep.h>
#include <System.Private.CoreLib/System/Math-dep.h>
#include <System.Private.CoreLib/System/MemoryExtensions-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/MemoryMarshal-dep.h>
#include <System.Private.CoreLib/System/Span-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/ThrowHelper-dep.h>
#include <System.Private.CoreLib/System/UInt32-dep.h>
#include <System.Private.CoreLib/System/UInt64-dep.h>

namespace System::Private::CoreLib::System::Globalization::CompareInfoNamespace {
using namespace Internal::Runtime::CompilerServices;
using namespace System::Buffers;
using namespace System::Buffers::Binary;
using namespace System::Collections::Generic;
using namespace System::Runtime::InteropServices;

IntPtr CompareInfo___::SortHandleCache::GetCachedSortHandle(String sortName) {
}

void CompareInfo___::SortHandleCache::cctor() {
  s_sortNameToSortHandleCache = rt::newobj<Dictionary<String, IntPtr>>();
}

String CompareInfo___::get_Name() {
  if (m_name == "zh-CHT" || m_name == "zh-CHS") {
    return m_name;
  }
  return _sortName;
}

SortVersion CompareInfo___::get_Version() {
  if (m_SortVersion == nullptr) {
    if (GlobalizationMode::get_Invariant()) {
      m_SortVersion = rt::newobj<SortVersion>(0, 127, Guid(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 127));
    } else {
      m_SortVersion = (GlobalizationMode::get_UseNls() ? NlsGetSortVersion() : IcuGetSortVersion());
    }
  }
  return m_SortVersion;
}

Int32 CompareInfo___::get_LCID() {
  return CultureInfo::in::GetCultureInfo(get_Name())->get_LCID();
}

ReadOnlySpan<Boolean> CompareInfo___::get_HighCharTable() {
  return rt::newarr<Array<Boolean>>(128);
}

void CompareInfo___::ctor(CultureInfo culture) {
  m_name = culture->_name;
  InitSort(culture);
}

CompareInfo CompareInfo___::GetCompareInfo(Int32 culture, Assembly assembly) {
  if (assembly == nullptr) {
    rt::throw_exception<ArgumentNullException>("assembly");
  }
}

CompareInfo CompareInfo___::GetCompareInfo(String name, Assembly assembly) {
  if (name == nullptr) {
    rt::throw_exception<ArgumentNullException>("name");
  }
  if (assembly == nullptr) {
    rt::throw_exception<ArgumentNullException>("assembly");
  }
}

CompareInfo CompareInfo___::GetCompareInfo(Int32 culture) {
  if (CultureData::in::IsCustomCultureId(culture)) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_CustomCultureCannotBePassedByNumber(), "culture");
  }
  return CultureInfo::in::GetCultureInfo(culture)->get_CompareInfo();
}

CompareInfo CompareInfo___::GetCompareInfo(String name) {
  if (name == nullptr) {
    rt::throw_exception<ArgumentNullException>("name");
  }
  return CultureInfo::in::GetCultureInfo(name)->get_CompareInfo();
}

Boolean CompareInfo___::IsSortable(Char ch) {
  return IsSortable(MemoryMarshal::CreateReadOnlySpan(ch, 1));
}

Boolean CompareInfo___::IsSortable(String text) {
  if (text == nullptr) {
    rt::throw_exception<ArgumentNullException>("text");
  }
  return IsSortable(MemoryExtensions::AsSpan(text));
}

Boolean CompareInfo___::IsSortable(ReadOnlySpan<Char> text) {
  if (text.get_Length() == 0) {
    return false;
  }
  if (GlobalizationMode::get_Invariant()) {
    return true;
  }
  if (!GlobalizationMode::get_UseNls()) {
    return IcuIsSortable(text);
  }
  return NlsIsSortable(text);
}

Boolean CompareInfo___::IsSortable(Rune value) {
  Char default[2] = {};
  Span<Char> destination = default;
}

void CompareInfo___::InitSort(CultureInfo culture) {
  _sortName = culture->get_SortName();
  if (GlobalizationMode::get_UseNls()) {
    NlsInitSortHandle();
  } else {
    IcuInitSortHandle();
  }
}

void CompareInfo___::OnDeserializing(StreamingContext ctx) {
  m_name = nullptr;
}

void CompareInfo___::OnDeserialized(StreamingContext ctx) {
  OnDeserialized();
}

void CompareInfo___::OnDeserialized() {
  if (m_name == nullptr) {
    m_name = CultureInfo::in::GetCultureInfo(culture)->_name;
  } else {
    InitSort(CultureInfo::in::GetCultureInfo(m_name));
  }
}

void CompareInfo___::OnSerializing(StreamingContext ctx) {
  culture = CultureInfo::in::GetCultureInfo(get_Name())->get_LCID();
}

Int32 CompareInfo___::Compare(String string1, String string2) {
  return Compare(string1, string2, CompareOptions::None);
}

Int32 CompareInfo___::Compare(String string1, String string2, CompareOptions options) {
  Int32 result;
  if (string1 == nullptr) {
    result = ((string2 != nullptr) ? (-1) : 0);
  } else {
    if (string2 != nullptr) {
      return Compare(MemoryExtensions::AsSpan(string1), MemoryExtensions::AsSpan(string2), options);
    }
    result = 1;
  }
  CheckCompareOptionsForCompare(options);
  return result;
}

Int32 CompareInfo___::CompareOptionIgnoreCase(ReadOnlySpan<Char> string1, ReadOnlySpan<Char> string2) {
  if (!GlobalizationMode::get_Invariant()) {
    return CompareStringCore(string1, string2, CompareOptions::IgnoreCase);
  }
  return CompareOrdinalIgnoreCase(string1, string2);
}

Int32 CompareInfo___::Compare(String string1, Int32 offset1, Int32 length1, String string2, Int32 offset2, Int32 length2) {
  return Compare(string1, offset1, length1, string2, offset2, length2, CompareOptions::None);
}

Int32 CompareInfo___::Compare(String string1, Int32 offset1, String string2, Int32 offset2, CompareOptions options) {
  return Compare(string1, offset1, (string1 != nullptr) ? (string1->get_Length() - offset1) : 0, string2, offset2, (string2 != nullptr) ? (string2->get_Length() - offset2) : 0, options);
}

Int32 CompareInfo___::Compare(String string1, Int32 offset1, String string2, Int32 offset2) {
  return Compare(string1, offset1, string2, offset2, CompareOptions::None);
}

Int32 CompareInfo___::Compare(String string1, Int32 offset1, Int32 length1, String string2, Int32 offset2, Int32 length2, CompareOptions options) {
  ReadOnlySpan<Char> slice = ReadOnlySpan<T>();
  ReadOnlySpan<Char> slice2 = ReadOnlySpan<T>();
  if (string1 == nullptr) {
    if (offset1 == 0 && length1 == 0) {
    }
  } else if (string1->TryGetSpan(offset1, length1, slice)) {
  }

}

Int32 CompareInfo___::Compare(ReadOnlySpan<Char> string1, ReadOnlySpan<Char> string2, CompareOptions options) {
  if (string1 == string2) {
    CheckCompareOptionsForCompare(options);
    return 0;
  }
}

void CompareInfo___::CheckCompareOptionsForCompare(CompareOptions options) {
}

void CompareInfo___::ThrowCompareOptionsCheckFailed(CompareOptions options) {
}

Int32 CompareInfo___::CompareStringCore(ReadOnlySpan<Char> string1, ReadOnlySpan<Char> string2, CompareOptions options) {
  if (!GlobalizationMode::get_UseNls()) {
    return IcuCompareString(string1, string2, options);
  }
  return NlsCompareString(string1, string2, options);
}

Int32 CompareInfo___::CompareOrdinalIgnoreCase(String strA, Int32 indexA, Int32 lengthA, String strB, Int32 indexB, Int32 lengthB) {
  return CompareOrdinalIgnoreCase(Unsafe::Add(strA->GetRawStringData(), indexA), lengthA, Unsafe::Add(strB->GetRawStringData(), indexB), lengthB);
}

Int32 CompareInfo___::CompareOrdinalIgnoreCase(ReadOnlySpan<Char> strA, ReadOnlySpan<Char> strB) {
  return CompareOrdinalIgnoreCase(MemoryMarshal::GetReference(strA), strA.get_Length(), MemoryMarshal::GetReference(strB), strB.get_Length());
}

Int32 CompareInfo___::CompareOrdinalIgnoreCase(String strA, String strB) {
  return CompareOrdinalIgnoreCase(strA->GetRawStringData(), strA->get_Length(), strB->GetRawStringData(), strB->get_Length());
}

Int32 CompareInfo___::CompareOrdinalIgnoreCase(Char& strA, Int32 lengthA, Char& strB, Int32 lengthB) {
  Int32 num = Math::Min(lengthA, lengthB);
  Int32 num2 = num;
  Char& reference = strA;
  Char& reference2 = strB;
  Char c = GlobalizationMode::get_Invariant() ? 65535 : 127;
  while (num != 0 && reference <= c && reference2 <= c) {
  }
  if (num == 0) {
    return lengthA - lengthB;
  }
  num2 -= num;
  return CompareStringOrdinalIgnoreCaseCore(reference, lengthA - num2, reference2, lengthB - num2);
}

Boolean CompareInfo___::EqualsOrdinalIgnoreCase(Char& charA, Char& charB, Int32 length) {
  IntPtr zero = IntPtr::Zero;
  while (true) {
    if ((UInt32)length >= 4u) {
      UInt64 num = Unsafe::ReadUnaligned<UInt64>(Unsafe::As<Char, Byte>(Unsafe::AddByteOffset(charA, zero)));
      UInt64 num2 = Unsafe::ReadUnaligned<UInt64>(Unsafe::As<Char, Byte>(Unsafe::AddByteOffset(charB, zero)));
    }
    if ((UInt32)length >= 2u) {
      UInt32 num4 = Unsafe::ReadUnaligned<UInt32>(Unsafe::As<Char, Byte>(Unsafe::AddByteOffset(charA, zero)));
      UInt32 num5 = Unsafe::ReadUnaligned<UInt32>(Unsafe::As<Char, Byte>(Unsafe::AddByteOffset(charB, zero)));
    }
    if (length != 0) {
      UInt32 num6 = Unsafe::AddByteOffset(charA, zero);
      UInt32 num7 = Unsafe::AddByteOffset(charB, zero);
    }
    return true;
  }
  return EqualsOrdinalIgnoreCaseNonAscii(Unsafe::AddByteOffset(charA, zero), Unsafe::AddByteOffset(charB, zero), length);
}

Boolean CompareInfo___::EqualsOrdinalIgnoreCaseNonAscii(Char& charA, Char& charB, Int32 length) {
  if (!GlobalizationMode::get_Invariant()) {
    return CompareStringOrdinalIgnoreCaseCore(charA, length, charB, length) == 0;
  }
  IntPtr zero = IntPtr::Zero;
  while (length != 0) {
    UInt32 num = Unsafe::AddByteOffset(charA, zero);
    UInt32 num2 = Unsafe::AddByteOffset(charB, zero);
  }
  return true;
}

Int32 CompareInfo___::CompareStringOrdinalIgnoreCaseCore(Char& string1, Int32 count1, Char& string2, Int32 count2) {
  if (!GlobalizationMode::get_UseNls()) {
    return IcuCompareStringOrdinalIgnoreCase(string1, count1, string2, count2);
  }
  return NlsCompareStringOrdinalIgnoreCase(string1, count1, string2, count2);
}

Boolean CompareInfo___::IsPrefix(String source, String prefix, CompareOptions options) {
  if (source == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::source);
  }
  if (prefix == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::prefix);
  }
  return IsPrefix(MemoryExtensions::AsSpan(source), MemoryExtensions::AsSpan(prefix), options);
}

Boolean CompareInfo___::IsPrefix(ReadOnlySpan<Char> source, ReadOnlySpan<Char> prefix, CompareOptions options) {
  if (prefix.get_IsEmpty()) {
    return true;
  }
}

Boolean CompareInfo___::StartsWithCore(ReadOnlySpan<Char> source, ReadOnlySpan<Char> prefix, CompareOptions options) {
  if (!GlobalizationMode::get_UseNls()) {
    return IcuStartsWith(source, prefix, options);
  }
  return NlsStartsWith(source, prefix, options);
}

Boolean CompareInfo___::IsPrefix(String source, String prefix) {
  return IsPrefix(source, prefix, CompareOptions::None);
}

Boolean CompareInfo___::IsSuffix(String source, String suffix, CompareOptions options) {
  if (source == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::source);
  }
  if (suffix == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::suffix);
  }
  return IsSuffix(MemoryExtensions::AsSpan(source), MemoryExtensions::AsSpan(suffix), options);
}

Boolean CompareInfo___::IsSuffix(ReadOnlySpan<Char> source, ReadOnlySpan<Char> suffix, CompareOptions options) {
  if (suffix.get_IsEmpty()) {
    return true;
  }
}

Boolean CompareInfo___::IsSuffix(String source, String suffix) {
  return IsSuffix(source, suffix, CompareOptions::None);
}

Boolean CompareInfo___::EndsWithCore(ReadOnlySpan<Char> source, ReadOnlySpan<Char> suffix, CompareOptions options) {
  if (!GlobalizationMode::get_UseNls()) {
    return IcuEndsWith(source, suffix, options);
  }
  return NlsEndsWith(source, suffix, options);
}

Int32 CompareInfo___::IndexOf(String source, Char value) {
  return IndexOf(source, value, CompareOptions::None);
}

Int32 CompareInfo___::IndexOf(String source, String value) {
  return IndexOf(source, value, CompareOptions::None);
}

Int32 CompareInfo___::IndexOf(String source, Char value, CompareOptions options) {
  if (source == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::source);
  }
  return IndexOf(source, MemoryMarshal::CreateReadOnlySpan(value, 1), options);
}

Int32 CompareInfo___::IndexOf(String source, String value, CompareOptions options) {
  if (source == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::source);
  }
  if (value == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::value);
  }
  return IndexOf(MemoryExtensions::AsSpan(source), MemoryExtensions::AsSpan(value), options);
}

Int32 CompareInfo___::IndexOf(String source, Char value, Int32 startIndex) {
  return IndexOf(source, value, startIndex, CompareOptions::None);
}

Int32 CompareInfo___::IndexOf(String source, String value, Int32 startIndex) {
  return IndexOf(source, value, startIndex, CompareOptions::None);
}

Int32 CompareInfo___::IndexOf(String source, Char value, Int32 startIndex, CompareOptions options) {
  if (source == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::source);
  }
  return IndexOf(source, value, startIndex, source->get_Length() - startIndex, options);
}

Int32 CompareInfo___::IndexOf(String source, String value, Int32 startIndex, CompareOptions options) {
  if (source == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::source);
  }
  return IndexOf(source, value, startIndex, source->get_Length() - startIndex, options);
}

Int32 CompareInfo___::IndexOf(String source, Char value, Int32 startIndex, Int32 count) {
  return IndexOf(source, value, startIndex, count, CompareOptions::None);
}

Int32 CompareInfo___::IndexOf(String source, String value, Int32 startIndex, Int32 count) {
  return IndexOf(source, value, startIndex, count, CompareOptions::None);
}

Int32 CompareInfo___::IndexOf(String source, Char value, Int32 startIndex, Int32 count, CompareOptions options) {
  if (source == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::source);
  }
}

Int32 CompareInfo___::IndexOf(String source, String value, Int32 startIndex, Int32 count, CompareOptions options) {
  if (source == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::source);
  }
  if (value == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::value);
  }
}

Int32 CompareInfo___::IndexOf(ReadOnlySpan<Char> source, ReadOnlySpan<Char> value, CompareOptions options) {
}

Int32 CompareInfo___::IndexOf(ReadOnlySpan<Char> source, Rune value, CompareOptions options) {
  Char default[2] = {};
  Span<Char> destination = default;
}

Int32 CompareInfo___::IndexOfOrdinalCore(ReadOnlySpan<Char> source, ReadOnlySpan<Char> value, Boolean ignoreCase, Boolean fromBeginning) {
  if (!GlobalizationMode::get_UseNls()) {
    return IcuIndexOfOrdinalCore(source, value, ignoreCase, fromBeginning);
  }
  return NlsIndexOfOrdinalCore(source, value, ignoreCase, fromBeginning);
}

Int32 CompareInfo___::IndexOfOrdinalIgnoreCase(ReadOnlySpan<Char> source, ReadOnlySpan<Char> value, Boolean fromBeginning) {
  if (value.get_IsEmpty()) {
    if (!fromBeginning) {
      return source.get_Length();
    }
    return 0;
  }
  if (value.get_Length() > source.get_Length()) {
    return -1;
  }
  if (GlobalizationMode::get_Invariant()) {
    return InvariantIndexOf(source, value, true, fromBeginning);
  }
  return IndexOfOrdinalCore(source, value, true, fromBeginning);
}

Int32 CompareInfo___::IndexOf(ReadOnlySpan<Char> source, ReadOnlySpan<Char> value, Int32* matchLengthPtr, CompareOptions options, Boolean fromBeginning) {
  *matchLengthPtr = 0;
}

Int32 CompareInfo___::IndexOfCore(ReadOnlySpan<Char> source, ReadOnlySpan<Char> target, CompareOptions options, Int32* matchLengthPtr, Boolean fromBeginning) {
  if (!GlobalizationMode::get_UseNls()) {
    return IcuIndexOfCore(source, target, options, matchLengthPtr, fromBeginning);
  }
  return NlsIndexOfCore(source, target, options, matchLengthPtr, fromBeginning);
}

Int32 CompareInfo___::LastIndexOf(String source, Char value) {
  return LastIndexOf(source, value, CompareOptions::None);
}

Int32 CompareInfo___::LastIndexOf(String source, String value) {
  return LastIndexOf(source, value, CompareOptions::None);
}

Int32 CompareInfo___::LastIndexOf(String source, Char value, CompareOptions options) {
  if (source == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::source);
  }
  return LastIndexOf(source, MemoryMarshal::CreateReadOnlySpan(value, 1), options);
}

Int32 CompareInfo___::LastIndexOf(String source, String value, CompareOptions options) {
  if (source == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::source);
  }
  if (value == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::value);
  }
  return LastIndexOf(MemoryExtensions::AsSpan(source), MemoryExtensions::AsSpan(value), options);
}

Int32 CompareInfo___::LastIndexOf(String source, Char value, Int32 startIndex) {
  return LastIndexOf(source, value, startIndex, startIndex + 1, CompareOptions::None);
}

Int32 CompareInfo___::LastIndexOf(String source, String value, Int32 startIndex) {
  return LastIndexOf(source, value, startIndex, startIndex + 1, CompareOptions::None);
}

Int32 CompareInfo___::LastIndexOf(String source, Char value, Int32 startIndex, CompareOptions options) {
  return LastIndexOf(source, value, startIndex, startIndex + 1, options);
}

Int32 CompareInfo___::LastIndexOf(String source, String value, Int32 startIndex, CompareOptions options) {
  return LastIndexOf(source, value, startIndex, startIndex + 1, options);
}

Int32 CompareInfo___::LastIndexOf(String source, Char value, Int32 startIndex, Int32 count) {
  return LastIndexOf(source, value, startIndex, count, CompareOptions::None);
}

Int32 CompareInfo___::LastIndexOf(String source, String value, Int32 startIndex, Int32 count) {
  return LastIndexOf(source, value, startIndex, count, CompareOptions::None);
}

Int32 CompareInfo___::LastIndexOf(String source, Char value, Int32 startIndex, Int32 count, CompareOptions options) {
  if (source == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::source);
  }
  while ((UInt32)startIndex >= (UInt32)source->get_Length()) {
    if (startIndex == -1 && source->get_Length() == 0) {
      count = 0;
      break;
    }
    if (startIndex == source->get_Length()) {
      startIndex--;
      if (count > 0) {
        count--;
      }
    }
    ThrowHelper::ThrowArgumentOutOfRangeException(ExceptionArgument::startIndex, ExceptionResource::ArgumentOutOfRange_Index);
    break;
  }
  startIndex = startIndex - count + 1;
}

Int32 CompareInfo___::LastIndexOf(String source, String value, Int32 startIndex, Int32 count, CompareOptions options) {
  if (source == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::source);
  }
  if (value == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::value);
  }
  while ((UInt32)startIndex >= (UInt32)source->get_Length()) {
    if (startIndex == -1 && source->get_Length() == 0) {
      count = 0;
      break;
    }
    if (startIndex == source->get_Length()) {
      startIndex--;
      if (count > 0) {
        count--;
      }
    }
    ThrowHelper::ThrowArgumentOutOfRangeException(ExceptionArgument::startIndex, ExceptionResource::ArgumentOutOfRange_Index);
    break;
  }
  startIndex = startIndex - count + 1;
}

Int32 CompareInfo___::LastIndexOf(ReadOnlySpan<Char> source, ReadOnlySpan<Char> value, CompareOptions options) {
}

Int32 CompareInfo___::LastIndexOf(ReadOnlySpan<Char> source, Rune value, CompareOptions options) {
  Char default[2] = {};
  Span<Char> destination = default;
}

SortKey CompareInfo___::GetSortKey(String source, CompareOptions options) {
  if (GlobalizationMode::get_Invariant()) {
    return InvariantCreateSortKey(source, options);
  }
  return CreateSortKeyCore(source, options);
}

SortKey CompareInfo___::GetSortKey(String source) {
  if (GlobalizationMode::get_Invariant()) {
    return InvariantCreateSortKey(source, CompareOptions::None);
  }
  return CreateSortKeyCore(source, CompareOptions::None);
}

SortKey CompareInfo___::CreateSortKeyCore(String source, CompareOptions options) {
  if (!GlobalizationMode::get_UseNls()) {
    return IcuCreateSortKey(source, options);
  }
  return NlsCreateSortKey(source, options);
}

Int32 CompareInfo___::GetSortKey(ReadOnlySpan<Char> source, Span<Byte> destination, CompareOptions options) {
}

Int32 CompareInfo___::GetSortKeyCore(ReadOnlySpan<Char> source, Span<Byte> destination, CompareOptions options) {
  if (!GlobalizationMode::get_UseNls()) {
    return IcuGetSortKey(source, destination, options);
  }
  return NlsGetSortKey(source, destination, options);
}

Int32 CompareInfo___::GetSortKeyLength(ReadOnlySpan<Char> source, CompareOptions options) {
}

Int32 CompareInfo___::GetSortKeyLengthCore(ReadOnlySpan<Char> source, CompareOptions options) {
  if (!GlobalizationMode::get_UseNls()) {
    return IcuGetSortKeyLength(source, options);
  }
  return NlsGetSortKeyLength(source, options);
}

Boolean CompareInfo___::Equals(Object value) {
  CompareInfo compareInfo = rt::as<CompareInfo>(value);
  if (compareInfo != nullptr) {
    return get_Name() == compareInfo->get_Name();
  }
  return false;
}

Int32 CompareInfo___::GetHashCode() {
  return get_Name()->GetHashCode();
}

Int32 CompareInfo___::GetHashCode(String source, CompareOptions options) {
  if (source == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::source);
  }
  return GetHashCode(MemoryExtensions::AsSpan(source), options);
}

Int32 CompareInfo___::GetHashCode(ReadOnlySpan<Char> source, CompareOptions options) {
}

Int32 CompareInfo___::GetHashCodeOfStringCore(ReadOnlySpan<Char> source, CompareOptions options) {
  if (!GlobalizationMode::get_UseNls()) {
    return IcuGetHashCodeOfString(source, options);
  }
  return NlsGetHashCodeOfString(source, options);
}

String CompareInfo___::ToString() {
  return "CompareInfo - " + get_Name();
}

void CompareInfo___::IcuInitSortHandle() {
  if (GlobalizationMode::get_Invariant()) {
    _isAsciiEqualityOrdinal = true;
    return;
  }
  _isAsciiEqualityOrdinal = (_sortName->get_Length() == 0 || (_sortName->get_Length() >= 2 && _sortName[0] == 101 && _sortName[1] == 110 && (_sortName->get_Length() == 2 || _sortName[2] == 45)));
  _sortHandle = SortHandleCache::GetCachedSortHandle(_sortName);
}

Int32 CompareInfo___::IcuIndexOfOrdinalCore(ReadOnlySpan<Char> source, ReadOnlySpan<Char> value, Boolean ignoreCase, Boolean fromBeginning) {
  if (source.get_Length() < value.get_Length()) {
    return -1;
  }
  if (ignoreCase) {
    {
      Char* pSource = &MemoryMarshal::GetReference(source);
      {
        Char* target = &MemoryMarshal::GetReference(value);
        return Interop::Globalization::IndexOfOrdinalIgnoreCase(target, value.get_Length(), pSource, source.get_Length(), !fromBeginning);
      }
    }
  }
  Int32 num;
  Int32 num2;
  Int32 num3;
  if (fromBeginning) {
    num = 0;
    num2 = source.get_Length() - value.get_Length() + 1;
    num3 = 1;
  } else {
    num = source.get_Length() - value.get_Length();
    num2 = -1;
    num3 = -1;
  }
  for (Int32 i = num; i != num2; i += num3) {
    Int32 num4 = 0;
    Int32 num5 = i;
    while (num4 < value.get_Length() && source[num5] == value[num4]) {
      num4++;
      num5++;
    }
    if (num4 == value.get_Length()) {
      return i;
    }
  }
  return -1;
}

Int32 CompareInfo___::IcuCompareStringOrdinalIgnoreCase(Char& string1, Int32 count1, Char& string2, Int32 count2) {
  {
    Char* lpStr = &string1;
    {
      Char* lpStr2 = &string2;
      return Interop::Globalization::CompareStringOrdinalIgnoreCase(lpStr, count1, lpStr2, count2);
    }
  }
}

Int32 CompareInfo___::IcuCompareString(ReadOnlySpan<Char> string1, ReadOnlySpan<Char> string2, CompareOptions options) {
  {
    Char* lpStr = &MemoryMarshal::GetReference(string1);
    {
      Char* lpStr2 = &MemoryMarshal::GetReference(string2);
      return Interop::Globalization::CompareString(_sortHandle, lpStr, string1.get_Length(), lpStr2, string2.get_Length(), options);
    }
  }
}

Int32 CompareInfo___::IcuIndexOfCore(ReadOnlySpan<Char> source, ReadOnlySpan<Char> target, CompareOptions options, Int32* matchLengthPtr, Boolean fromBeginning) {
  if (_isAsciiEqualityOrdinal && CanUseAsciiOrdinalForOptions(options)) {
  }
  {
    Char* pSource = &MemoryMarshal::GetReference(source);
    {
      Char* target2 = &MemoryMarshal::GetReference(target);
      if (fromBeginning) {
        return Interop::Globalization::IndexOf(_sortHandle, target2, target.get_Length(), pSource, source.get_Length(), options, matchLengthPtr);
      }
      return Interop::Globalization::LastIndexOf(_sortHandle, target2, target.get_Length(), pSource, source.get_Length(), options, matchLengthPtr);
    }
  }
}

Int32 CompareInfo___::IndexOfOrdinalIgnoreCaseHelper(ReadOnlySpan<Char> source, ReadOnlySpan<Char> target, CompareOptions options, Int32* matchLengthPtr, Boolean fromBeginning) {
  {
    Char* ptr = &MemoryMarshal::GetReference(source);
    {
      Char* ptr3 = &MemoryMarshal::GetReference(target);
      Char* ptr2 = ptr;
      Char* ptr4 = ptr3;
      Int32 num = 0;
      while (true) {
        if (num < target.get_Length()) {
          Char c = ptr4[num];
          if (c >= 128 || get_HighCharTable()[c]) {
            break;
          }
          num++;
        }
        if (target.get_Length() > source.get_Length()) {
          Int32 num2 = 0;
          while (true) {
            if (num2 < source.get_Length()) {
              Char c2 = ptr2[num2];
              if (c2 >= 128 || get_HighCharTable()[c2]) {
                break;
              }
              num2++;
            }
            return -1;
          }
          break;
        }
        Int32 num3;
        Int32 num4;
        Int32 num5;
        if (fromBeginning) {
          num3 = 0;
          num4 = source.get_Length() - target.get_Length() + 1;
          num5 = 1;
        } else {
          num3 = source.get_Length() - target.get_Length();
          num4 = -1;
          num5 = -1;
        }
        Int32 num6 = num3;
        while (true) {
          Int32 num8;
          if (num6 != num4) {
            Int32 num7 = 0;
            num8 = num6;
            while (true) {
              if (num7 < target.get_Length()) {
                Char c3 = ptr2[num8];
                Char c4 = ptr4[num7];
                if (c3 >= 128 || get_HighCharTable()[c3]) {
                  break;
                }
                if (c3 == c4) {
                }
                if ((UInt32)(c3 - 97) <= 25u) {
                  c3 = (Char)(c3 - 32);
                }
                if ((UInt32)(c4 - 97) <= 25u) {
                  c4 = (Char)(c4 - 32);
                }
                if (c3 == c4) {
                }
              }
              if (num8 < source.get_Length() && ptr2[num8] >= 128) {
                break;
              }
              if (matchLengthPtr != nullptr) {
                *matchLengthPtr = target.get_Length();
              }
              return num6;
            }
            break;
          }
          return -1;
        }
        break;
      }
      if (fromBeginning) {
        return Interop::Globalization::IndexOf(_sortHandle, ptr4, target.get_Length(), ptr2, source.get_Length(), options, matchLengthPtr);
      }
      return Interop::Globalization::LastIndexOf(_sortHandle, ptr4, target.get_Length(), ptr2, source.get_Length(), options, matchLengthPtr);
    }
  }
}

Int32 CompareInfo___::IndexOfOrdinalHelper(ReadOnlySpan<Char> source, ReadOnlySpan<Char> target, CompareOptions options, Int32* matchLengthPtr, Boolean fromBeginning) {
  {
    Char* ptr = &MemoryMarshal::GetReference(source);
    {
      Char* ptr3 = &MemoryMarshal::GetReference(target);
      Char* ptr2 = ptr;
      Char* ptr4 = ptr3;
      Int32 num = 0;
      while (true) {
        if (num < target.get_Length()) {
          Char c = ptr4[num];
          if (c >= 128 || get_HighCharTable()[c]) {
            break;
          }
          num++;
        }
        if (target.get_Length() > source.get_Length()) {
          Int32 num2 = 0;
          while (true) {
            if (num2 < source.get_Length()) {
              Char c2 = ptr2[num2];
              if (c2 >= 128 || get_HighCharTable()[c2]) {
                break;
              }
              num2++;
            }
            return -1;
          }
          break;
        }
        Int32 num3;
        Int32 num4;
        Int32 num5;
        if (fromBeginning) {
          num3 = 0;
          num4 = source.get_Length() - target.get_Length() + 1;
          num5 = 1;
        } else {
          num3 = source.get_Length() - target.get_Length();
          num4 = -1;
          num5 = -1;
        }
        Int32 num6 = num3;
        while (true) {
          Int32 num8;
          if (num6 != num4) {
            Int32 num7 = 0;
            num8 = num6;
            while (true) {
              if (num7 < target.get_Length()) {
                Char c3 = ptr2[num8];
                Char c4 = ptr4[num7];
                if (c3 >= 128 || get_HighCharTable()[c3]) {
                  break;
                }
                if (c3 == c4) {
                  num7++;
                  num8++;
                }
              }
              if (num8 < source.get_Length() && ptr2[num8] >= 128) {
                break;
              }
              if (matchLengthPtr != nullptr) {
                *matchLengthPtr = target.get_Length();
              }
              return num6;
            }
            break;
          }
          return -1;
        }
        break;
      }
      if (fromBeginning) {
        return Interop::Globalization::IndexOf(_sortHandle, ptr4, target.get_Length(), ptr2, source.get_Length(), options, matchLengthPtr);
      }
      return Interop::Globalization::LastIndexOf(_sortHandle, ptr4, target.get_Length(), ptr2, source.get_Length(), options, matchLengthPtr);
    }
  }
}

Boolean CompareInfo___::IcuStartsWith(ReadOnlySpan<Char> source, ReadOnlySpan<Char> prefix, CompareOptions options) {
  if (_isAsciiEqualityOrdinal && CanUseAsciiOrdinalForOptions(options)) {
  }
  {
    Char* source2 = &MemoryMarshal::GetReference(source);
    {
      Char* target = &MemoryMarshal::GetReference(prefix);
      return Interop::Globalization::StartsWith(_sortHandle, target, prefix.get_Length(), source2, source.get_Length(), options);
    }
  }
}

Boolean CompareInfo___::StartsWithOrdinalIgnoreCaseHelper(ReadOnlySpan<Char> source, ReadOnlySpan<Char> prefix, CompareOptions options) {
  Int32 num = Math::Min(source.get_Length(), prefix.get_Length());
  {
    Char* ptr = &MemoryMarshal::GetReference(source);
    {
      Char* ptr3 = &MemoryMarshal::GetReference(prefix);
      Char* ptr2 = ptr;
      Char* ptr4 = ptr3;
      while (true) {
        if (num != 0) {
          Int32 num2 = *ptr2;
          Int32 num3 = *ptr4;
          if (num2 >= 128 || num3 >= 128 || get_HighCharTable()[num2] || get_HighCharTable()[num3]) {
            break;
          }
          if (num2 == num3) {
            ptr2++;
            ptr4++;
            num--;
          }
          if ((UInt32)(num2 - 97) <= 25u) {
            num2 -= 32;
          }
          if ((UInt32)(num3 - 97) <= 25u) {
            num3 -= 32;
          }
          if (num2 == num3) {
            ptr2++;
            ptr4++;
            num--;
          }
          if ((ptr2 < ptr + source.get_Length() - 1 && ptr2[1] >= 128) || (ptr4 < ptr3 + prefix.get_Length() - 1 && ptr4[1] >= 128)) {
            break;
          }
          return false;
        }
        if (source.get_Length() < prefix.get_Length()) {
          if (*ptr4 >= 128) {
            break;
          }
          return false;
        }
        if (source.get_Length() > prefix.get_Length() && *ptr2 >= 128) {
          break;
        }
        return true;
      }
      return Interop::Globalization::StartsWith(_sortHandle, ptr3, prefix.get_Length(), ptr, source.get_Length(), options);
    }
  }
}

Boolean CompareInfo___::StartsWithOrdinalHelper(ReadOnlySpan<Char> source, ReadOnlySpan<Char> prefix, CompareOptions options) {
  Int32 num = Math::Min(source.get_Length(), prefix.get_Length());
  {
    Char* ptr = &MemoryMarshal::GetReference(source);
    {
      Char* ptr3 = &MemoryMarshal::GetReference(prefix);
      Char* ptr2 = ptr;
      Char* ptr4 = ptr3;
      while (true) {
        if (num != 0) {
          Int32 num2 = *ptr2;
          Int32 num3 = *ptr4;
          if (num2 >= 128 || num3 >= 128 || get_HighCharTable()[num2] || get_HighCharTable()[num3]) {
            break;
          }
          if (num2 == num3) {
            ptr2++;
            ptr4++;
            num--;
          }
          if ((ptr2 < ptr + source.get_Length() - 1 && ptr2[1] >= 128) || (ptr4 < ptr3 + prefix.get_Length() - 1 && ptr4[1] >= 128)) {
            break;
          }
          return false;
        }
        if (source.get_Length() < prefix.get_Length()) {
          if (*ptr4 >= 128) {
            break;
          }
          return false;
        }
        if (source.get_Length() > prefix.get_Length() && *ptr2 >= 128) {
          break;
        }
        return true;
      }
      return Interop::Globalization::StartsWith(_sortHandle, ptr3, prefix.get_Length(), ptr, source.get_Length(), options);
    }
  }
}

Boolean CompareInfo___::IcuEndsWith(ReadOnlySpan<Char> source, ReadOnlySpan<Char> suffix, CompareOptions options) {
  if (_isAsciiEqualityOrdinal && CanUseAsciiOrdinalForOptions(options)) {
  }
  {
    Char* source2 = &MemoryMarshal::GetReference(source);
    {
      Char* target = &MemoryMarshal::GetReference(suffix);
      return Interop::Globalization::EndsWith(_sortHandle, target, suffix.get_Length(), source2, source.get_Length(), options);
    }
  }
}

Boolean CompareInfo___::EndsWithOrdinalIgnoreCaseHelper(ReadOnlySpan<Char> source, ReadOnlySpan<Char> suffix, CompareOptions options) {
  Int32 num = Math::Min(source.get_Length(), suffix.get_Length());
  {
    Char* ptr = &MemoryMarshal::GetReference(source);
    {
      Char* ptr3 = &MemoryMarshal::GetReference(suffix);
      Char* ptr2 = ptr + source.get_Length() - 1;
      Char* ptr4 = ptr3 + suffix.get_Length() - 1;
      while (true) {
        if (num != 0) {
          Int32 num2 = *ptr2;
          Int32 num3 = *ptr4;
          if (num2 >= 128 || num3 >= 128 || get_HighCharTable()[num2] || get_HighCharTable()[num3]) {
            break;
          }
          if (num2 == num3) {
            ptr2--;
            ptr4--;
            num--;
          }
          if ((UInt32)(num2 - 97) <= 25u) {
            num2 -= 32;
          }
          if ((UInt32)(num3 - 97) <= 25u) {
            num3 -= 32;
          }
          if (num2 == num3) {
            ptr2--;
            ptr4--;
            num--;
          }
          if ((ptr2 > ptr && *(ptr2 - 1) >= 128) || (ptr4 > ptr3 && *(ptr4 - 1) >= 128)) {
            break;
          }
          return false;
        }
        if (source.get_Length() < suffix.get_Length()) {
          if (*ptr4 >= 128) {
            break;
          }
          return false;
        }
        if (source.get_Length() > suffix.get_Length() && *ptr2 >= 128) {
          break;
        }
        return true;
      }
      return Interop::Globalization::EndsWith(_sortHandle, ptr3, suffix.get_Length(), ptr, source.get_Length(), options);
    }
  }
}

Boolean CompareInfo___::EndsWithOrdinalHelper(ReadOnlySpan<Char> source, ReadOnlySpan<Char> suffix, CompareOptions options) {
  Int32 num = Math::Min(source.get_Length(), suffix.get_Length());
  {
    Char* ptr = &MemoryMarshal::GetReference(source);
    {
      Char* ptr3 = &MemoryMarshal::GetReference(suffix);
      Char* ptr2 = ptr + source.get_Length() - 1;
      Char* ptr4 = ptr3 + suffix.get_Length() - 1;
      while (true) {
        if (num != 0) {
          Int32 num2 = *ptr2;
          Int32 num3 = *ptr4;
          if (num2 >= 128 || num3 >= 128 || get_HighCharTable()[num2] || get_HighCharTable()[num3]) {
            break;
          }
          if (num2 == num3) {
            ptr2--;
            ptr4--;
            num--;
          }
          if ((ptr2 > ptr && *(ptr2 - 1) >= 128) || (ptr4 > ptr3 && *(ptr4 - 1) >= 128)) {
            break;
          }
          return false;
        }
        if (source.get_Length() < suffix.get_Length()) {
          if (*ptr4 >= 128) {
            break;
          }
          return false;
        }
        if (source.get_Length() > suffix.get_Length() && *ptr2 >= 128) {
          break;
        }
        return true;
      }
      return Interop::Globalization::EndsWith(_sortHandle, ptr3, suffix.get_Length(), ptr, source.get_Length(), options);
    }
  }
}

SortKey CompareInfo___::IcuCreateSortKey(String source, CompareOptions options) {
  if (source == nullptr) {
    rt::throw_exception<ArgumentNullException>("source");
  }
}

Int32 CompareInfo___::IcuGetSortKey(ReadOnlySpan<Char> source, Span<Byte> destination, CompareOptions options) {
  Int32 sortKey2;
  {
    Char* str = &MemoryMarshal::GetReference(source);
    {
      Byte* sortKey = &MemoryMarshal::GetReference(destination);
      sortKey2 = Interop::Globalization::GetSortKey(_sortHandle, str, source.get_Length(), sortKey, destination.get_Length(), options);
    }
  }
  if ((UInt32)sortKey2 > (UInt32)destination.get_Length()) {
    if (sortKey2 <= destination.get_Length()) {
      rt::throw_exception<ArgumentException>(SR::get_Arg_ExternalException());
    }
    ThrowHelper::ThrowArgumentException_DestinationTooShort();
  }
  return sortKey2;
}

Int32 CompareInfo___::IcuGetSortKeyLength(ReadOnlySpan<Char> source, CompareOptions options) {
  {
    Char* str = &MemoryMarshal::GetReference(source);
    return Interop::Globalization::GetSortKey(_sortHandle, str, source.get_Length(), nullptr, 0, options);
  }
}

Boolean CompareInfo___::IcuIsSortable(ReadOnlySpan<Char> text) {
}

Int32 CompareInfo___::IcuGetHashCodeOfString(ReadOnlySpan<Char> source, CompareOptions options) {
  Int32 num = (source.get_Length() <= 262144) ? (4 * source.get_Length()) : 0;
  Array<Byte> array = nullptr;
  Span<Byte> span2;
  if (num <= 1024) {
    Byte default[1024] = {};
    Span<Byte> span = Span<Byte>(default, 1024);
    span2 = span;
  } else {
    span2 = (array = ArrayPool<Byte>::in::get_Shared()->Rent(num));
  }
  Span<Byte> span3 = span2;
  {
    Char* str = &MemoryMarshal::GetNonNullPinnableReference(source);
    {
      Byte* sortKey = &MemoryMarshal::GetReference(span3);
      num = Interop::Globalization::GetSortKey(_sortHandle, str, source.get_Length(), sortKey, span3.get_Length(), options);
    }
    if (num > span3.get_Length()) {
      if (array != nullptr) {
        ArrayPool<Byte>::in::get_Shared()->Return(array);
      }
      span3 = (array = ArrayPool<Byte>::in::get_Shared()->Rent(num));
      {
        Byte* sortKey2 = &MemoryMarshal::GetReference(span3);
        num = Interop::Globalization::GetSortKey(_sortHandle, str, source.get_Length(), sortKey2, span3.get_Length(), options);
      }
    }
  }
  if (num == 0 || num > span3.get_Length()) {
    rt::throw_exception<ArgumentException>(SR::get_Arg_ExternalException());
  }
  Int32 result = Marvin::ComputeHash32(span3.Slice(0, num), Marvin::get_DefaultSeed());
  if (array != nullptr) {
    ArrayPool<Byte>::in::get_Shared()->Return(array);
  }
  return result;
}

Boolean CompareInfo___::CanUseAsciiOrdinalForOptions(CompareOptions options) {
}

SortVersion CompareInfo___::IcuGetSortVersion() {
  Int32 sortVersion = Interop::Globalization::GetSortVersion(_sortHandle);
}

Int32 CompareInfo___::InvariantIndexOf(ReadOnlySpan<Char> source, ReadOnlySpan<Char> value, Boolean ignoreCase, Boolean fromBeginning) {
  {
    Char* source2 = &MemoryMarshal::GetReference(source);
    {
      Char* value2 = &MemoryMarshal::GetReference(value);
      return InvariantFindString(source2, source.get_Length(), value2, value.get_Length(), ignoreCase, fromBeginning);
    }
  }
}

Int32 CompareInfo___::InvariantFindString(Char* source, Int32 sourceCount, Char* value, Int32 valueCount, Boolean ignoreCase, Boolean fromBeginning) {
  Int32 num = 0;
  Int32 num2 = 0;
  if (valueCount == 0) {
    if (!fromBeginning) {
      return sourceCount;
    }
    return 0;
  }
  if (sourceCount < valueCount) {
    return -1;
  }
  if (fromBeginning) {
    Int32 num3 = sourceCount - valueCount;
    if (ignoreCase) {
      Char c = InvariantCaseFold(*value);
      for (num = 0; num <= num3; num++) {
        Char c2 = InvariantCaseFold(source[num]);
        if (c2 != c) {
        }
        for (num2 = 1; num2 < valueCount; num2++) {
          c2 = InvariantCaseFold(source[num + num2]);
          Char c3 = InvariantCaseFold(value[num2]);
          if (c2 != c3) {
            break;
          }
        }
        if (num2 == valueCount) {
          return num;
        }
      }
    } else {
      Char c4 = *value;
      for (num = 0; num <= num3; num++) {
        Char c2 = source[num];
        if (c2 != c4) {
        }
        for (num2 = 1; num2 < valueCount; num2++) {
          c2 = source[num + num2];
          Char c3 = value[num2];
          if (c2 != c3) {
            break;
          }
        }
        if (num2 == valueCount) {
          return num;
        }
      }
    }
  } else {
    Int32 num3 = sourceCount - valueCount;
    if (ignoreCase) {
      Char c5 = InvariantCaseFold(*value);
      for (num = num3; num >= 0; num--) {
        Char c2 = InvariantCaseFold(source[num]);
        if (c2 == c5) {
          for (num2 = 1; num2 < valueCount; num2++) {
            c2 = InvariantCaseFold(source[num + num2]);
            Char c3 = InvariantCaseFold(value[num2]);
            if (c2 != c3) {
              break;
            }
          }
          if (num2 == valueCount) {
            return num;
          }
        }
      }
    } else {
      Char c6 = *value;
      for (num = num3; num >= 0; num--) {
        Char c2 = source[num];
        if (c2 == c6) {
          for (num2 = 1; num2 < valueCount; num2++) {
            c2 = source[num + num2];
            Char c3 = value[num2];
            if (c2 != c3) {
              break;
            }
          }
          if (num2 == valueCount) {
            return num;
          }
        }
      }
    }
  }
  return -1;
}

Char CompareInfo___::InvariantCaseFold(Char c) {
  if ((UInt32)(c - 97) > 25u) {
    return c;
  }
  return (Char)(c - 32);
}

SortKey CompareInfo___::InvariantCreateSortKey(String source, CompareOptions options) {
  if (source == nullptr) {
    rt::throw_exception<ArgumentNullException>("source");
  }
}

void CompareInfo___::InvariantCreateSortKeyOrdinal(ReadOnlySpan<Char> source, Span<Byte> sortKey) {
  for (Int32 i = 0; i < source.get_Length(); i++) {
    BinaryPrimitives::WriteUInt16BigEndian(sortKey, source[i]);
    sortKey = sortKey.Slice(2);
  }
}

void CompareInfo___::InvariantCreateSortKeyOrdinalIgnoreCase(ReadOnlySpan<Char> source, Span<Byte> sortKey) {
  for (Int32 i = 0; i < source.get_Length(); i++) {
    BinaryPrimitives::WriteUInt16BigEndian(sortKey, InvariantCaseFold(source[i]));
    sortKey = sortKey.Slice(2);
  }
}

Int32 CompareInfo___::InvariantGetSortKey(ReadOnlySpan<Char> source, Span<Byte> destination, CompareOptions options) {
  if ((UInt32)destination.get_Length() < (UInt32)(source.get_Length() * 2)) {
    ThrowHelper::ThrowArgumentException_DestinationTooShort();
  }
}

Int32 CompareInfo___::InvariantGetSortKeyLength(ReadOnlySpan<Char> source, CompareOptions options) {
  Int32 num = source.get_Length() * 2;
  if (num < 0) {
    rt::throw_exception<ArgumentException>(SR::get_ArgumentOutOfRange_GetByteCountOverflow(), "source");
  }
  return num;
}

void CompareInfo___::NlsInitSortHandle() {
  _sortHandle = NlsGetSortHandle(_sortName);
}

IntPtr CompareInfo___::NlsGetSortHandle(String cultureName) {
  if (GlobalizationMode::get_Invariant()) {
    return IntPtr::Zero;
  }
  IntPtr intPtr;
  Int32 num = Interop::Kernel32::LCMapStringEx(cultureName, 536870912u, nullptr, 0, &intPtr, IntPtr::get_Size(), nullptr, nullptr, IntPtr::Zero);
  if (num > 0) {
    Int32 num2 = 0;
    Char c = 97;
    num = Interop::Kernel32::LCMapStringEx(nullptr, 262144u, &c, 1, &num2, 4, nullptr, nullptr, intPtr);
    if (num > 1) {
      return intPtr;
    }
  }
  return IntPtr::Zero;
}

Int32 CompareInfo___::FindStringOrdinal(UInt32 dwFindStringOrdinalFlags, ReadOnlySpan<Char> source, ReadOnlySpan<Char> value, Boolean bIgnoreCase) {
  {
    Char* lpStringSource = &MemoryMarshal::GetReference(source);
    {
      Char* lpStringValue = &MemoryMarshal::GetReference(value);
      return Interop::Kernel32::FindStringOrdinal(dwFindStringOrdinalFlags, lpStringSource, source.get_Length(), lpStringValue, value.get_Length(), bIgnoreCase ? Interop::BOOL::TRUE : Interop::BOOL::FALSE);
    }
  }
}

Int32 CompareInfo___::NlsIndexOfOrdinalCore(ReadOnlySpan<Char> source, ReadOnlySpan<Char> value, Boolean ignoreCase, Boolean fromBeginning) {
  UInt32 dwFindStringOrdinalFlags = fromBeginning ? 4194304u : 8388608u;
  return FindStringOrdinal(dwFindStringOrdinalFlags, source, value, ignoreCase);
}

Int32 CompareInfo___::NlsGetHashCodeOfString(ReadOnlySpan<Char> source, CompareOptions options) {
  if (!Environment::get_IsWindows8OrAbove()) {
    source = source.ToString();
  }
  Int32 num = source.get_Length();
  if (num == 0) {
    source = String::in::Empty;
    num = -1;
  }
}

Int32 CompareInfo___::NlsCompareStringOrdinalIgnoreCase(Char& string1, Int32 count1, Char& string2, Int32 count2) {
  {
    Char* lpString = &string1;
    {
      Char* lpString2 = &string2;
      Int32 num = Interop::Kernel32::CompareStringOrdinal(lpString, count1, lpString2, count2, true);
      if (num == 0) {
        rt::throw_exception<ArgumentException>(SR::get_Arg_ExternalException());
      }
      return num - 2;
    }
  }
}

Int32 CompareInfo___::NlsCompareString(ReadOnlySpan<Char> string1, ReadOnlySpan<Char> string2, CompareOptions options) {
  String text = (_sortHandle != IntPtr::Zero) ? nullptr : _sortName;
  if (string1.get_IsEmpty()) {
    string1 = String::in::Empty;
  }
  if (string2.get_IsEmpty()) {
    string2 = String::in::Empty;
  }
  {
    Char* ptr = text;
    Char* lpLocaleName = ptr;
    {
      Char* lpString = &MemoryMarshal::GetReference(string1);
      {
        Char* lpString2 = &MemoryMarshal::GetReference(string2);
        Int32 num = Interop::Kernel32::CompareStringEx(lpLocaleName, (UInt32)GetNativeCompareFlags(options), lpString, string1.get_Length(), lpString2, string2.get_Length(), nullptr, nullptr, _sortHandle);
        if (num == 0) {
          rt::throw_exception<ArgumentException>(SR::get_Arg_ExternalException());
        }
        return num - 2;
      }
    }
  }
}

Int32 CompareInfo___::FindString(UInt32 dwFindNLSStringFlags, ReadOnlySpan<Char> lpStringSource, ReadOnlySpan<Char> lpStringValue, Int32* pcchFound) {
  String text = (_sortHandle != IntPtr::Zero) ? nullptr : _sortName;
  Int32 num = lpStringSource.get_Length();
  if (num == 0) {
    lpStringSource = String::in::Empty;
    num = -1;
  }
  {
    Char* ptr = text;
    Char* lpLocaleName = ptr;
    {
      Char* lpStringSource2 = &MemoryMarshal::GetReference(lpStringSource);
      {
        Char* lpStringValue2 = &MemoryMarshal::GetReference(lpStringValue);
        return Interop::Kernel32::FindNLSStringEx(lpLocaleName, dwFindNLSStringFlags, lpStringSource2, num, lpStringValue2, lpStringValue.get_Length(), pcchFound, nullptr, nullptr, _sortHandle);
      }
    }
  }
}

Int32 CompareInfo___::NlsIndexOfCore(ReadOnlySpan<Char> source, ReadOnlySpan<Char> target, CompareOptions options, Int32* matchLengthPtr, Boolean fromBeginning) {
  UInt32 num = fromBeginning ? 4194304u : 8388608u;
}

Boolean CompareInfo___::NlsStartsWith(ReadOnlySpan<Char> source, ReadOnlySpan<Char> prefix, CompareOptions options) {
}

Boolean CompareInfo___::NlsEndsWith(ReadOnlySpan<Char> source, ReadOnlySpan<Char> suffix, CompareOptions options) {
}

SortKey CompareInfo___::NlsCreateSortKey(String source, CompareOptions options) {
  if (source == nullptr) {
    rt::throw_exception<ArgumentNullException>("source");
  }
}

Int32 CompareInfo___::NlsGetSortKey(ReadOnlySpan<Char> source, Span<Byte> destination, CompareOptions options) {
  if (destination.get_IsEmpty()) {
    ThrowHelper::ThrowArgumentException_DestinationTooShort();
  }
  if (!Environment::get_IsWindows8OrAbove()) {
    source = source.ToString();
  }
}

Int32 CompareInfo___::NlsGetSortKeyLength(ReadOnlySpan<Char> source, CompareOptions options) {
}

Boolean CompareInfo___::NlsIsSortable(ReadOnlySpan<Char> text) {
  {
    Char* lpString = &MemoryMarshal::GetReference(text);
    return Interop::Kernel32::IsNLSDefinedString(1, 0u, IntPtr::Zero, lpString, text.get_Length());
  }
}

Int32 CompareInfo___::GetNativeCompareFlags(CompareOptions options) {
  Int32 num = 134217728;
}

SortVersion CompareInfo___::NlsGetSortVersion() {
  Interop::Kernel32::NlsVersionInfoEx nlsVersionInfoEx = Interop::Kernel32::NlsVersionInfoEx();
  nlsVersionInfoEx.dwNLSVersionInfoSize = sizeof(Interop::Kernel32::NlsVersionInfoEx);
  Interop::Kernel32::GetNLSVersionEx(1, _sortName, &nlsVersionInfoEx);
  return rt::newobj<SortVersion>(nlsVersionInfoEx.dwNLSVersion, (nlsVersionInfoEx.dwEffectiveId == 0) ? get_LCID() : nlsVersionInfoEx.dwEffectiveId, nlsVersionInfoEx.guidCustomVersion);
}

void CompareInfo___::cctor() {
  Invariant = CultureInfo::in::get_InvariantCulture()->get_CompareInfo();
}

} // namespace System::Private::CoreLib::System::Globalization::CompareInfoNamespace
