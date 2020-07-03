#include "SpanHelpers-dep.h"

namespace System::Private::CoreLib::System::SpanHelpersNamespace {
void SpanHelpers::ClearWithoutReferences(Byte& b, UInt64 byteLength) {
};
void SpanHelpers::ClearWithReferences(IntPtr& ip, UInt64 pointerSizeLength) {
};
Int32 SpanHelpers::IndexOf(Byte& searchSpace, Int32 searchSpaceLength, Byte& value, Int32 valueLength) {
  return Int32();
};
Int32 SpanHelpers::IndexOfAny(Byte& searchSpace, Int32 searchSpaceLength, Byte& value, Int32 valueLength) {
  return Int32();
};
Int32 SpanHelpers::LastIndexOfAny(Byte& searchSpace, Int32 searchSpaceLength, Byte& value, Int32 valueLength) {
  return Int32();
};
Boolean SpanHelpers::Contains(Byte& searchSpace, Byte value, Int32 length) {
  return Boolean();
};
Int32 SpanHelpers::IndexOf(Byte& searchSpace, Byte value, Int32 length) {
  return Int32();
};
Int32 SpanHelpers::LastIndexOf(Byte& searchSpace, Int32 searchSpaceLength, Byte& value, Int32 valueLength) {
  return Int32();
};
Int32 SpanHelpers::LastIndexOf(Byte& searchSpace, Byte value, Int32 length) {
  return Int32();
};
Int32 SpanHelpers::IndexOfAny(Byte& searchSpace, Byte value0, Byte value1, Int32 length) {
  return Int32();
};
Int32 SpanHelpers::IndexOfAny(Byte& searchSpace, Byte value0, Byte value1, Byte value2, Int32 length) {
  return Int32();
};
Int32 SpanHelpers::LastIndexOfAny(Byte& searchSpace, Byte value0, Byte value1, Int32 length) {
  return Int32();
};
Int32 SpanHelpers::LastIndexOfAny(Byte& searchSpace, Byte value0, Byte value1, Byte value2, Int32 length) {
  return Int32();
};
Boolean SpanHelpers::SequenceEqual(Byte& first, Byte& second, UInt64 length) {
  return Boolean();
};
Int32 SpanHelpers::LocateFirstFoundByte(Vector<Byte> match) {
  return Int32();
};
Int32 SpanHelpers::SequenceCompareTo(Byte& first, Int32 firstLength, Byte& second, Int32 secondLength) {
  return Int32();
};
Int32 SpanHelpers::LocateLastFoundByte(Vector<Byte> match) {
  return Int32();
};
Int32 SpanHelpers::LocateFirstFoundByte(UInt64 match) {
  return Int32();
};
Int32 SpanHelpers::LocateLastFoundByte(UInt64 match) {
  return Int32();
};
UIntPtr SpanHelpers::LoadUIntPtr(Byte& start, IntPtr offset) {
  return UIntPtr();
};
Vector<Byte> SpanHelpers::LoadVector(Byte& start, IntPtr offset) {
  return Vector<Byte>();
};
Vector128<Byte> SpanHelpers::LoadVector128(Byte& start, IntPtr offset) {
  return Vector128<Byte>();
};
Vector256<Byte> SpanHelpers::LoadVector256(Byte& start, IntPtr offset) {
  return Vector256<Byte>();
};
IntPtr SpanHelpers::GetByteVectorSpanLength(IntPtr offset, Int32 length) {
  return IntPtr();
};
IntPtr SpanHelpers::GetByteVector128SpanLength(IntPtr offset, Int32 length) {
  return IntPtr();
};
IntPtr SpanHelpers::GetByteVector256SpanLength(IntPtr offset, Int32 length) {
  return IntPtr();
};
IntPtr SpanHelpers::UnalignedCountVector(Byte& searchSpace) {
  return IntPtr();
};
IntPtr SpanHelpers::UnalignedCountVector128(Byte& searchSpace) {
  return IntPtr();
};
IntPtr SpanHelpers::UnalignedCountVectorFromEnd(Byte& searchSpace, Int32 length) {
  return IntPtr();
};
Int32 SpanHelpers::IndexOf(Char& searchSpace, Int32 searchSpaceLength, Char& value, Int32 valueLength) {
  return Int32();
};
Int32 SpanHelpers::SequenceCompareTo(Char& first, Int32 firstLength, Char& second, Int32 secondLength) {
  return Int32();
};
Boolean SpanHelpers::Contains(Char& searchSpace, Char value, Int32 length) {
  return Boolean();
};
Int32 SpanHelpers::IndexOf(Char& searchSpace, Char value, Int32 length) {
  return Int32();
};
Int32 SpanHelpers::IndexOfAny(Char& searchSpace, Char value0, Char value1, Int32 length) {
  return Int32();
};
Int32 SpanHelpers::IndexOfAny(Char& searchSpace, Char value0, Char value1, Char value2, Int32 length) {
  return Int32();
};
Int32 SpanHelpers::IndexOfAny(Char& searchSpace, Char value0, Char value1, Char value2, Char value3, Int32 length) {
  return Int32();
};
Int32 SpanHelpers::IndexOfAny(Char& searchSpace, Char value0, Char value1, Char value2, Char value3, Char value4, Int32 length) {
  return Int32();
};
Int32 SpanHelpers::LastIndexOf(Char& searchSpace, Char value, Int32 length) {
  return Int32();
};
Int32 SpanHelpers::LocateFirstFoundChar(Vector<UInt16> match) {
  return Int32();
};
Int32 SpanHelpers::LocateFirstFoundChar(UInt64 match) {
  return Int32();
};
Int32 SpanHelpers::LocateLastFoundChar(Vector<UInt16> match) {
  return Int32();
};
Int32 SpanHelpers::LocateLastFoundChar(UInt64 match) {
  return Int32();
};
Vector<UInt16> SpanHelpers::LoadVector(Char& start, Int64 offset) {
  return Vector<UInt16>();
};
Vector128<UInt16> SpanHelpers::LoadVector128(Char& start, Int64 offset) {
  return Vector128<UInt16>();
};
Vector256<UInt16> SpanHelpers::LoadVector256(Char& start, Int64 offset) {
  return Vector256<UInt16>();
};
Int64 SpanHelpers::GetCharVectorSpanLength(Int64 offset, Int64 length) {
  return Int64();
};
Int64 SpanHelpers::GetCharVector128SpanLength(Int64 offset, Int64 length) {
  return Int64();
};
Int64 SpanHelpers::GetCharVector256SpanLength(Int64 offset, Int64 length) {
  return Int64();
};
Int64 SpanHelpers::UnalignedCountVector(Char& searchSpace) {
  return Int64();
};
Int64 SpanHelpers::UnalignedCountVector128(Char& searchSpace) {
  return Int64();
};
} // namespace System::Private::CoreLib::System::SpanHelpersNamespace
