#include "MemoryExtensions-dep.h"

#include <System.Private.CoreLib/Internal/Runtime/CompilerServices/Unsafe-dep.h>
#include <System.Private.CoreLib/System/ExceptionArgument.h>
#include <System.Private.CoreLib/System/Globalization/CompareInfo-dep.h>
#include <System.Private.CoreLib/System/Globalization/CultureInfo-dep.h>
#include <System.Private.CoreLib/System/Globalization/GlobalizationMode-dep.h>
#include <System.Private.CoreLib/System/Globalization/Ordinal-dep.h>
#include <System.Private.CoreLib/System/Globalization/TextInfo-dep.h>
#include <System.Private.CoreLib/System/Int64-dep.h>
#include <System.Private.CoreLib/System/InvalidOperationException-dep.h>
#include <System.Private.CoreLib/System/MemoryExtensions-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/MemoryMarshal-dep.h>
#include <System.Private.CoreLib/System/SpanHelpers-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/ThrowHelper-dep.h>
#include <System.Private.CoreLib/System/UInt32-dep.h>
#include <System.Private.CoreLib/System/UInt64-dep.h>
#include <System.Private.CoreLib/System/ValueTuple-dep.h>

namespace System::Private::CoreLib::System::MemoryExtensionsNamespace {
using namespace Internal::Runtime::CompilerServices;
using namespace System::Globalization;
using namespace System::Runtime::InteropServices;

ReadOnlySpan<Char> MemoryExtensions::AsSpan(String text) {
  if (text == nullptr) {
    return rt::default__;
  }
  return ReadOnlySpan<Char>(text->GetRawStringData(), text->get_Length());
}

ReadOnlySpan<Char> MemoryExtensions::AsSpan(String text, Int32 start) {
  if (text == nullptr) {
    if (start != 0) {
      ThrowHelper::ThrowArgumentOutOfRangeException(ExceptionArgument::start);
    }
    return rt::default__;
  }
  if ((UInt32)start > (UInt32)text->get_Length()) {
    ThrowHelper::ThrowArgumentOutOfRangeException(ExceptionArgument::start);
  }
  return ReadOnlySpan<Char>(Unsafe::Add(text->GetRawStringData(), start), text->get_Length() - start);
}

ReadOnlySpan<Char> MemoryExtensions::AsSpan(String text, Int32 start, Int32 length) {
  if (text == nullptr) {
    if (start != 0 || length != 0) {
      ThrowHelper::ThrowArgumentOutOfRangeException(ExceptionArgument::start);
    }
    return rt::default__;
  }
  if ((UInt64)((Int64)(UInt32)start + (Int64)(UInt32)length) > (UInt64)(UInt32)text->get_Length()) {
    ThrowHelper::ThrowArgumentOutOfRangeException(ExceptionArgument::start);
  }
  return ReadOnlySpan<Char>(Unsafe::Add(text->GetRawStringData(), start), length);
}

ReadOnlyMemory<Char> MemoryExtensions::AsMemory(String text) {
  if (text == nullptr) {
    return rt::default__;
  }
  return ReadOnlyMemory<Char>(text, 0, text->get_Length());
}

ReadOnlyMemory<Char> MemoryExtensions::AsMemory(String text, Int32 start) {
  if (text == nullptr) {
    if (start != 0) {
      ThrowHelper::ThrowArgumentOutOfRangeException(ExceptionArgument::start);
    }
    return rt::default__;
  }
  if ((UInt32)start > (UInt32)text->get_Length()) {
    ThrowHelper::ThrowArgumentOutOfRangeException(ExceptionArgument::start);
  }
  return ReadOnlyMemory<Char>(text, start, text->get_Length() - start);
}

ReadOnlyMemory<Char> MemoryExtensions::AsMemory(String text, Index startIndex) {
  if (text == nullptr) {
    if (!startIndex.Equals(Index::get_Start())) {
      ThrowHelper::ThrowArgumentNullException(ExceptionArgument::text);
    }
    return rt::default__;
  }
  Int32 offset = startIndex.GetOffset(text->get_Length());
  if ((UInt32)offset > (UInt32)text->get_Length()) {
    ThrowHelper::ThrowArgumentOutOfRangeException();
  }
  return ReadOnlyMemory<Char>(text, offset, text->get_Length() - offset);
}

ReadOnlyMemory<Char> MemoryExtensions::AsMemory(String text, Int32 start, Int32 length) {
  if (text == nullptr) {
    if (start != 0 || length != 0) {
      ThrowHelper::ThrowArgumentOutOfRangeException(ExceptionArgument::start);
    }
    return rt::default__;
  }
  if ((UInt64)((Int64)(UInt32)start + (Int64)(UInt32)length) > (UInt64)(UInt32)text->get_Length()) {
    ThrowHelper::ThrowArgumentOutOfRangeException(ExceptionArgument::start);
  }
  return ReadOnlyMemory<Char>(text, start, length);
}

ReadOnlyMemory<Char> MemoryExtensions::AsMemory(String text, Range range) {
  if (text == nullptr) {
    Index start = range.get_Start();
    Index end = range.get_End();
    if (!start.Equals(Index::get_Start()) || !end.Equals(Index::get_Start())) {
      ThrowHelper::ThrowArgumentNullException(ExceptionArgument::text);
    }
    return rt::default__;
  }
  ValueTuple<Int32, Int32> offsetAndLength = range.GetOffsetAndLength(text->get_Length());
  Int32 item = offsetAndLength.Item1;
  Int32 item2 = offsetAndLength.Item2;
  return ReadOnlyMemory<Char>(text, item, item2);
}

Boolean MemoryExtensions::IsWhiteSpace(ReadOnlySpan<Char> span) {
  for (Int32 i = 0; i < span.get_Length(); i++) {
    if (!Char::IsWhiteSpace(span[i])) {
      return false;
    }
  }
  return true;
}

Boolean MemoryExtensions::Contains(ReadOnlySpan<Char> span, ReadOnlySpan<Char> value, StringComparison comparisonType) {
  return MemoryExtensions::IndexOf(span, value, comparisonType) >= 0;
}

Boolean MemoryExtensions::Equals(ReadOnlySpan<Char> span, ReadOnlySpan<Char> other, StringComparison comparisonType) {
  String::in::CheckStringComparison(comparisonType);
  switch (comparisonType) {
    case StringComparison::CurrentCulture:
    case StringComparison::CurrentCultureIgnoreCase:
      return CultureInfo::in::get_CurrentCulture()->get_CompareInfo()->Compare(span, other, String::in::GetCaseCompareOfComparisonCulture(comparisonType)) == 0;
    case StringComparison::InvariantCulture:
    case StringComparison::InvariantCultureIgnoreCase:
      return CompareInfo::in::Invariant->Compare(span, other, String::in::GetCaseCompareOfComparisonCulture(comparisonType)) == 0;
    case StringComparison::Ordinal:
      return MemoryExtensions::EqualsOrdinal(span, other);
    default:
      return MemoryExtensions::EqualsOrdinalIgnoreCase(span, other);
  }
}

Boolean MemoryExtensions::EqualsOrdinal(ReadOnlySpan<Char> span, ReadOnlySpan<Char> value) {
  if (span.get_Length() != value.get_Length()) {
    return false;
  }
  if (value.get_Length() == 0) {
    return true;
  }
  return MemoryExtensions::SequenceEqual(span, value);
}

Boolean MemoryExtensions::EqualsOrdinalIgnoreCase(ReadOnlySpan<Char> span, ReadOnlySpan<Char> value) {
  if (span.get_Length() != value.get_Length()) {
    return false;
  }
  if (value.get_Length() == 0) {
    return true;
  }
  return Ordinal::EqualsIgnoreCase(MemoryMarshal::GetReference(span), MemoryMarshal::GetReference(value), span.get_Length());
}

Int32 MemoryExtensions::CompareTo(ReadOnlySpan<Char> span, ReadOnlySpan<Char> other, StringComparison comparisonType) {
  String::in::CheckStringComparison(comparisonType);
  switch (comparisonType) {
    case StringComparison::CurrentCulture:
    case StringComparison::CurrentCultureIgnoreCase:
      return CultureInfo::in::get_CurrentCulture()->get_CompareInfo()->Compare(span, other, String::in::GetCaseCompareOfComparisonCulture(comparisonType));
    case StringComparison::InvariantCulture:
    case StringComparison::InvariantCultureIgnoreCase:
      return CompareInfo::in::Invariant->Compare(span, other, String::in::GetCaseCompareOfComparisonCulture(comparisonType));
    case StringComparison::Ordinal:
      if (span.get_Length() == 0 || other.get_Length() == 0) {
        return span.get_Length() - other.get_Length();
      }
      return String::in::CompareOrdinal(span, other);
    default:
      return Ordinal::CompareStringIgnoreCase(MemoryMarshal::GetReference(span), span.get_Length(), MemoryMarshal::GetReference(other), other.get_Length());
  }
}

Int32 MemoryExtensions::IndexOf(ReadOnlySpan<Char> span, ReadOnlySpan<Char> value, StringComparison comparisonType) {
  String::in::CheckStringComparison(comparisonType);
  switch (comparisonType) {
    case StringComparison::Ordinal:
      return SpanHelpers::IndexOf(MemoryMarshal::GetReference(span), span.get_Length(), MemoryMarshal::GetReference(value), value.get_Length());
    case StringComparison::CurrentCulture:
    case StringComparison::CurrentCultureIgnoreCase:
      return CultureInfo::in::get_CurrentCulture()->get_CompareInfo()->IndexOf(span, value, String::in::GetCaseCompareOfComparisonCulture(comparisonType));
    case StringComparison::InvariantCulture:
    case StringComparison::InvariantCultureIgnoreCase:
      return CompareInfo::in::Invariant->IndexOf(span, value, String::in::GetCaseCompareOfComparisonCulture(comparisonType));
    default:
      return Ordinal::IndexOfOrdinalIgnoreCase(span, value);
  }
}

Int32 MemoryExtensions::LastIndexOf(ReadOnlySpan<Char> span, ReadOnlySpan<Char> value, StringComparison comparisonType) {
  String::in::CheckStringComparison(comparisonType);
  switch (comparisonType) {
    case StringComparison::Ordinal:
      return SpanHelpers::LastIndexOf(MemoryMarshal::GetReference(span), span.get_Length(), MemoryMarshal::GetReference(value), value.get_Length());
    case StringComparison::CurrentCulture:
    case StringComparison::CurrentCultureIgnoreCase:
      return CultureInfo::in::get_CurrentCulture()->get_CompareInfo()->LastIndexOf(span, value, String::in::GetCaseCompareOfComparisonCulture(comparisonType));
    case StringComparison::InvariantCulture:
    case StringComparison::InvariantCultureIgnoreCase:
      return CompareInfo::in::Invariant->LastIndexOf(span, value, String::in::GetCaseCompareOfComparisonCulture(comparisonType));
    default:
      return Ordinal::LastIndexOfOrdinalIgnoreCase(span, value);
  }
}

Int32 MemoryExtensions::ToLower(ReadOnlySpan<Char> source, Span<Char> destination, CultureInfo culture) {
  if (MemoryExtensions::Overlaps(source, destination)) {
    rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_SpanOverlappedOperation());
  }
  if (culture == nullptr) {
    culture = CultureInfo::in::set_CurrentCulture();
  }
  if (destination.get_Length() < source.get_Length()) {
    return -1;
  }
  if (GlobalizationMode::get_Invariant()) {
    TextInfo::in::ToLowerAsciiInvariant(source, destination);
  } else {
    culture->get_TextInfo()->ChangeCaseToLower(source, destination);
  }
  return source.get_Length();
}

Int32 MemoryExtensions::ToLowerInvariant(ReadOnlySpan<Char> source, Span<Char> destination) {
  if (MemoryExtensions::Overlaps(source, destination)) {
    rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_SpanOverlappedOperation());
  }
  if (destination.get_Length() < source.get_Length()) {
    return -1;
  }
  if (GlobalizationMode::get_Invariant()) {
    TextInfo::in::ToLowerAsciiInvariant(source, destination);
  } else {
    TextInfo::in::Invariant->ChangeCaseToLower(source, destination);
  }
  return source.get_Length();
}

Int32 MemoryExtensions::ToUpper(ReadOnlySpan<Char> source, Span<Char> destination, CultureInfo culture) {
  if (MemoryExtensions::Overlaps(source, destination)) {
    rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_SpanOverlappedOperation());
  }
  if (culture == nullptr) {
    culture = CultureInfo::in::set_CurrentCulture();
  }
  if (destination.get_Length() < source.get_Length()) {
    return -1;
  }
  if (GlobalizationMode::get_Invariant()) {
    TextInfo::in::ToUpperAsciiInvariant(source, destination);
  } else {
    culture->get_TextInfo()->ChangeCaseToUpper(source, destination);
  }
  return source.get_Length();
}

Int32 MemoryExtensions::ToUpperInvariant(ReadOnlySpan<Char> source, Span<Char> destination) {
  if (MemoryExtensions::Overlaps(source, destination)) {
    rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_SpanOverlappedOperation());
  }
  if (destination.get_Length() < source.get_Length()) {
    return -1;
  }
  if (GlobalizationMode::get_Invariant()) {
    TextInfo::in::ToUpperAsciiInvariant(source, destination);
  } else {
    TextInfo::in::Invariant->ChangeCaseToUpper(source, destination);
  }
  return source.get_Length();
}

Boolean MemoryExtensions::EndsWith(ReadOnlySpan<Char> span, ReadOnlySpan<Char> value, StringComparison comparisonType) {
  String::in::CheckStringComparison(comparisonType);
  switch (comparisonType) {
    case StringComparison::CurrentCulture:
    case StringComparison::CurrentCultureIgnoreCase:
      return CultureInfo::in::get_CurrentCulture()->get_CompareInfo()->IsSuffix(span, value, String::in::GetCaseCompareOfComparisonCulture(comparisonType));
    case StringComparison::InvariantCulture:
    case StringComparison::InvariantCultureIgnoreCase:
      return CompareInfo::in::Invariant->IsSuffix(span, value, String::in::GetCaseCompareOfComparisonCulture(comparisonType));
    case StringComparison::Ordinal:
      return MemoryExtensions::EndsWith(span, value);
    default:
      return MemoryExtensions::EndsWithOrdinalIgnoreCase(span, value);
  }
}

Boolean MemoryExtensions::EndsWithOrdinalIgnoreCase(ReadOnlySpan<Char> span, ReadOnlySpan<Char> value) {
  if (value.get_Length() <= span.get_Length()) {
    return Ordinal::EqualsIgnoreCase(Unsafe::Add(MemoryMarshal::GetReference(span), span.get_Length() - value.get_Length()), MemoryMarshal::GetReference(value), value.get_Length());
  }
  return false;
}

Boolean MemoryExtensions::StartsWith(ReadOnlySpan<Char> span, ReadOnlySpan<Char> value, StringComparison comparisonType) {
  String::in::CheckStringComparison(comparisonType);
  switch (comparisonType) {
    case StringComparison::CurrentCulture:
    case StringComparison::CurrentCultureIgnoreCase:
      return CultureInfo::in::get_CurrentCulture()->get_CompareInfo()->IsPrefix(span, value, String::in::GetCaseCompareOfComparisonCulture(comparisonType));
    case StringComparison::InvariantCulture:
    case StringComparison::InvariantCultureIgnoreCase:
      return CompareInfo::in::Invariant->IsPrefix(span, value, String::in::GetCaseCompareOfComparisonCulture(comparisonType));
    case StringComparison::Ordinal:
      return MemoryExtensions::StartsWith(span, value);
    default:
      return MemoryExtensions::StartsWithOrdinalIgnoreCase(span, value);
  }
}

Boolean MemoryExtensions::StartsWithOrdinalIgnoreCase(ReadOnlySpan<Char> span, ReadOnlySpan<Char> value) {
  if (value.get_Length() <= span.get_Length()) {
    return Ordinal::EqualsIgnoreCase(MemoryMarshal::GetReference(span), MemoryMarshal::GetReference(value), value.get_Length());
  }
  return false;
}

SpanRuneEnumerator MemoryExtensions::EnumerateRunes(ReadOnlySpan<Char> span) {
  return SpanRuneEnumerator(span);
}

SpanRuneEnumerator MemoryExtensions::EnumerateRunes(Span<Char> span) {
  return SpanRuneEnumerator(span);
}

Memory<Char> MemoryExtensions::Trim(Memory<Char> memory) {
  ReadOnlySpan<Char> span = memory.get_Span();
  Int32 start = ClampStart(span);
  Int32 length = ClampEnd(span, start);
  return memory.Slice(start, length);
}

Memory<Char> MemoryExtensions::TrimStart(Memory<Char> memory) {
  return memory.Slice(ClampStart(memory.get_Span()));
}

Memory<Char> MemoryExtensions::TrimEnd(Memory<Char> memory) {
  return memory.Slice(0, ClampEnd(memory.get_Span(), 0));
}

ReadOnlyMemory<Char> MemoryExtensions::Trim(ReadOnlyMemory<Char> memory) {
  ReadOnlySpan<Char> span = memory.get_Span();
  Int32 start = ClampStart(span);
  Int32 length = ClampEnd(span, start);
  return memory.Slice(start, length);
}

ReadOnlyMemory<Char> MemoryExtensions::TrimStart(ReadOnlyMemory<Char> memory) {
  return memory.Slice(ClampStart(memory.get_Span()));
}

ReadOnlyMemory<Char> MemoryExtensions::TrimEnd(ReadOnlyMemory<Char> memory) {
  return memory.Slice(0, ClampEnd(memory.get_Span(), 0));
}

ReadOnlySpan<Char> MemoryExtensions::Trim(ReadOnlySpan<Char> span) {
  Int32 i;
  for (i = 0; i < span.get_Length() && Char::IsWhiteSpace(span[i]); i++) {
  }
  Int32 num = span.get_Length() - 1;
  while (num > i && Char::IsWhiteSpace(span[num])) {
    num--;
  }
  return span.Slice(i, num - i + 1);
}

ReadOnlySpan<Char> MemoryExtensions::TrimStart(ReadOnlySpan<Char> span) {
  Int32 i;
  for (i = 0; i < span.get_Length() && Char::IsWhiteSpace(span[i]); i++) {
  }
  return span.Slice(i);
}

ReadOnlySpan<Char> MemoryExtensions::TrimEnd(ReadOnlySpan<Char> span) {
  Int32 num = span.get_Length() - 1;
  while (num >= 0 && Char::IsWhiteSpace(span[num])) {
    num--;
  }
  return span.Slice(0, num + 1);
}

ReadOnlySpan<Char> MemoryExtensions::Trim(ReadOnlySpan<Char> span, Char trimChar) {
  Int32 i;
  for (i = 0; i < span.get_Length() && span[i] == trimChar; i++) {
  }
  Int32 num = span.get_Length() - 1;
  while (num > i && span[num] == trimChar) {
    num--;
  }
  return span.Slice(i, num - i + 1);
}

ReadOnlySpan<Char> MemoryExtensions::TrimStart(ReadOnlySpan<Char> span, Char trimChar) {
  Int32 i;
  for (i = 0; i < span.get_Length() && span[i] == trimChar; i++) {
  }
  return span.Slice(i);
}

ReadOnlySpan<Char> MemoryExtensions::TrimEnd(ReadOnlySpan<Char> span, Char trimChar) {
  Int32 num = span.get_Length() - 1;
  while (num >= 0 && span[num] == trimChar) {
    num--;
  }
  return span.Slice(0, num + 1);
}

ReadOnlySpan<Char> MemoryExtensions::Trim(ReadOnlySpan<Char> span, ReadOnlySpan<Char> trimChars) {
  return MemoryExtensions::TrimEnd(MemoryExtensions::TrimStart(span, trimChars), trimChars);
}

ReadOnlySpan<Char> MemoryExtensions::TrimStart(ReadOnlySpan<Char> span, ReadOnlySpan<Char> trimChars) {
  if (trimChars.get_IsEmpty()) {
    return MemoryExtensions::TrimStart(span);
  }
  Int32 i;
  for (i = 0; i < span.get_Length(); i++) {
    Int32 num = 0;
    while (num < trimChars.get_Length()) {
      if (span[i] != trimChars[num]) {
        num++;
        continue;
      }
      goto IL_003c;
    }
    break;

  IL_003c:
  }
  return span.Slice(i);
}

ReadOnlySpan<Char> MemoryExtensions::TrimEnd(ReadOnlySpan<Char> span, ReadOnlySpan<Char> trimChars) {
  if (trimChars.get_IsEmpty()) {
    return MemoryExtensions::TrimEnd(span);
  }
  Int32 num;
  for (num = span.get_Length() - 1; num >= 0; num--) {
    Int32 num2 = 0;
    while (num2 < trimChars.get_Length()) {
      if (span[num] != trimChars[num2]) {
        num2++;
        continue;
      }
      goto IL_0044;
    }
    break;

  IL_0044:
  }
  return span.Slice(0, num + 1);
}

Span<Char> MemoryExtensions::Trim(Span<Char> span) {
  Int32 start = ClampStart(span);
  Int32 length = ClampEnd(span, start);
  return span.Slice(start, length);
}

Span<Char> MemoryExtensions::TrimStart(Span<Char> span) {
  return span.Slice(ClampStart(span));
}

Span<Char> MemoryExtensions::TrimEnd(Span<Char> span) {
  return span.Slice(0, ClampEnd(span, 0));
}

Int32 MemoryExtensions::ClampStart(ReadOnlySpan<Char> span) {
  Int32 i;
  for (i = 0; i < span.get_Length() && Char::IsWhiteSpace(span[i]); i++) {
  }
  return i;
}

Int32 MemoryExtensions::ClampEnd(ReadOnlySpan<Char> span, Int32 start) {
  Int32 num = span.get_Length() - 1;
  while (num >= start && Char::IsWhiteSpace(span[num])) {
    num--;
  }
  return num - start + 1;
}

} // namespace System::Private::CoreLib::System::MemoryExtensionsNamespace
