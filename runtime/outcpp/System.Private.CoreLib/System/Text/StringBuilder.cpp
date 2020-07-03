#include "StringBuilder-dep.h"

#include <System.Private.CoreLib/System/Text/StringBuilder-dep.h>

namespace System::Private::CoreLib::System::Text::StringBuilderNamespace {
Boolean StringBuilder___::ChunkEnumerator::ManyChunkInfo___::MoveNext(StringBuilder& current) {
  return Boolean();
};
ReadOnlyMemory<Char> StringBuilder___::ChunkEnumerator::get_Current() {
  return ReadOnlyMemory<Char>();
};
StringBuilder::in::ChunkEnumerator StringBuilder___::ChunkEnumerator::GetEnumerator() {
  return StringBuilder::in::ChunkEnumerator();
};
Boolean StringBuilder___::ChunkEnumerator::MoveNext() {
  return Boolean();
};
Int32 StringBuilder___::ChunkEnumerator::ChunkCount(StringBuilder stringBuilder) {
  return Int32();
};
Int32 StringBuilder___::get_Capacity() {
  return Int32();
};
void StringBuilder___::set_Capacity(Int32 value) {
};
Int32 StringBuilder___::get_MaxCapacity() {
  return Int32();
};
Int32 StringBuilder___::get_Length() {
  return Int32();
};
void StringBuilder___::set_Length(Int32 value) {
};
Char StringBuilder___::get_Chars(Int32 index) {
  return Char();
};
void StringBuilder___::set_Chars(Int32 index, Char value) {
};
Span<Char> StringBuilder___::get_RemainingCurrentChunk() {
  return Span<Char>();
};
Int32 StringBuilder___::GetReplaceBufferCapacity(Int32 requiredCapacity) {
  return Int32();
};
void StringBuilder___::ReplaceBufferInternal(Char* newBuffer, Int32 newLength) {
};
void StringBuilder___::ReplaceBufferUtf8Internal(ReadOnlySpan<Byte> source) {
};
void StringBuilder___::ReplaceBufferAnsiInternal(SByte* newBuffer, Int32 newLength) {
};
void StringBuilder___::InternalCopy(IntPtr dest, Int32 len) {
};
Int32 StringBuilder___::EnsureCapacity(Int32 capacity) {
  return Int32();
};
String StringBuilder___::ToString() {
  return nullptr;
};
String StringBuilder___::ToString(Int32 startIndex, Int32 length) {
  return nullptr;
};
StringBuilder StringBuilder___::Clear() {
  return nullptr;
};
StringBuilder::in::ChunkEnumerator StringBuilder___::GetChunks() {
  return StringBuilder::in::ChunkEnumerator();
};
StringBuilder StringBuilder___::Append(Char value, Int32 repeatCount) {
  return nullptr;
};
StringBuilder StringBuilder___::Append(Array<Char> value, Int32 startIndex, Int32 charCount) {
  return nullptr;
};
StringBuilder StringBuilder___::Append(String value) {
  return nullptr;
};
void StringBuilder___::AppendHelper(String value) {
};
StringBuilder StringBuilder___::Append(String value, Int32 startIndex, Int32 count) {
  return nullptr;
};
StringBuilder StringBuilder___::Append(StringBuilder value) {
  return nullptr;
};
StringBuilder StringBuilder___::Append(StringBuilder value, Int32 startIndex, Int32 count) {
  return nullptr;
};
StringBuilder StringBuilder___::AppendCore(StringBuilder value, Int32 startIndex, Int32 count) {
  return nullptr;
};
StringBuilder StringBuilder___::AppendLine() {
  return nullptr;
};
StringBuilder StringBuilder___::AppendLine(String value) {
  return nullptr;
};
void StringBuilder___::CopyTo(Int32 sourceIndex, Array<Char> destination, Int32 destinationIndex, Int32 count) {
};
void StringBuilder___::CopyTo(Int32 sourceIndex, Span<Char> destination, Int32 count) {
};
StringBuilder StringBuilder___::Insert(Int32 index, String value, Int32 count) {
  return nullptr;
};
StringBuilder StringBuilder___::Remove(Int32 startIndex, Int32 length) {
  return nullptr;
};
StringBuilder StringBuilder___::Append(Boolean value) {
  return nullptr;
};
StringBuilder StringBuilder___::Append(Char value) {
  return nullptr;
};
StringBuilder StringBuilder___::Append(SByte value) {
  return nullptr;
};
StringBuilder StringBuilder___::Append(Byte value) {
  return nullptr;
};
StringBuilder StringBuilder___::Append(Int16 value) {
  return nullptr;
};
StringBuilder StringBuilder___::Append(Int32 value) {
  return nullptr;
};
StringBuilder StringBuilder___::Append(Int64 value) {
  return nullptr;
};
StringBuilder StringBuilder___::Append(Single value) {
  return nullptr;
};
StringBuilder StringBuilder___::Append(Double value) {
  return nullptr;
};
StringBuilder StringBuilder___::Append(Decimal value) {
  return nullptr;
};
StringBuilder StringBuilder___::Append(UInt16 value) {
  return nullptr;
};
StringBuilder StringBuilder___::Append(UInt32 value) {
  return nullptr;
};
StringBuilder StringBuilder___::Append(UInt64 value) {
  return nullptr;
};
StringBuilder StringBuilder___::Append(Object value) {
  return nullptr;
};
StringBuilder StringBuilder___::Append(Array<Char> value) {
  return nullptr;
};
StringBuilder StringBuilder___::Append(ReadOnlySpan<Char> value) {
  return nullptr;
};
StringBuilder StringBuilder___::Append(ReadOnlyMemory<Char> value) {
  return nullptr;
};
StringBuilder StringBuilder___::AppendJoin(String separator, Array<Object> values) {
  return nullptr;
};
StringBuilder StringBuilder___::AppendJoin(String separator, Array<String> values) {
  return nullptr;
};
StringBuilder StringBuilder___::AppendJoin(Char separator, Array<Object> values) {
  return nullptr;
};
StringBuilder StringBuilder___::AppendJoin(Char separator, Array<String> values) {
  return nullptr;
};
StringBuilder StringBuilder___::Insert(Int32 index, String value) {
  return nullptr;
};
StringBuilder StringBuilder___::Insert(Int32 index, Boolean value) {
  return nullptr;
};
StringBuilder StringBuilder___::Insert(Int32 index, SByte value) {
  return nullptr;
};
StringBuilder StringBuilder___::Insert(Int32 index, Byte value) {
  return nullptr;
};
StringBuilder StringBuilder___::Insert(Int32 index, Int16 value) {
  return nullptr;
};
StringBuilder StringBuilder___::Insert(Int32 index, Char value) {
  return nullptr;
};
StringBuilder StringBuilder___::Insert(Int32 index, Array<Char> value) {
  return nullptr;
};
StringBuilder StringBuilder___::Insert(Int32 index, Array<Char> value, Int32 startIndex, Int32 charCount) {
  return nullptr;
};
StringBuilder StringBuilder___::Insert(Int32 index, Int32 value) {
  return nullptr;
};
StringBuilder StringBuilder___::Insert(Int32 index, Int64 value) {
  return nullptr;
};
StringBuilder StringBuilder___::Insert(Int32 index, Single value) {
  return nullptr;
};
StringBuilder StringBuilder___::Insert(Int32 index, Double value) {
  return nullptr;
};
StringBuilder StringBuilder___::Insert(Int32 index, Decimal value) {
  return nullptr;
};
StringBuilder StringBuilder___::Insert(Int32 index, UInt16 value) {
  return nullptr;
};
StringBuilder StringBuilder___::Insert(Int32 index, UInt32 value) {
  return nullptr;
};
StringBuilder StringBuilder___::Insert(Int32 index, UInt64 value) {
  return nullptr;
};
StringBuilder StringBuilder___::Insert(Int32 index, Object value) {
  return nullptr;
};
StringBuilder StringBuilder___::Insert(Int32 index, ReadOnlySpan<Char> value) {
  return nullptr;
};
StringBuilder StringBuilder___::AppendFormat(String format, Object arg0) {
  return nullptr;
};
StringBuilder StringBuilder___::AppendFormat(String format, Object arg0, Object arg1) {
  return nullptr;
};
StringBuilder StringBuilder___::AppendFormat(String format, Object arg0, Object arg1, Object arg2) {
  return nullptr;
};
StringBuilder StringBuilder___::AppendFormat(String format, Array<Object> args) {
  return nullptr;
};
StringBuilder StringBuilder___::AppendFormat(IFormatProvider provider, String format, Object arg0) {
  return nullptr;
};
StringBuilder StringBuilder___::AppendFormat(IFormatProvider provider, String format, Object arg0, Object arg1) {
  return nullptr;
};
StringBuilder StringBuilder___::AppendFormat(IFormatProvider provider, String format, Object arg0, Object arg1, Object arg2) {
  return nullptr;
};
StringBuilder StringBuilder___::AppendFormat(IFormatProvider provider, String format, Array<Object> args) {
  return nullptr;
};
void StringBuilder___::FormatError() {
};
StringBuilder StringBuilder___::AppendFormatHelper(IFormatProvider provider, String format, ParamsArray args) {
  return nullptr;
};
StringBuilder StringBuilder___::Replace(String oldValue, String newValue) {
  return nullptr;
};
Boolean StringBuilder___::Equals(StringBuilder sb) {
  return Boolean();
};
Boolean StringBuilder___::Equals(ReadOnlySpan<Char> span) {
  return Boolean();
};
StringBuilder StringBuilder___::Replace(String oldValue, String newValue, Int32 startIndex, Int32 count) {
  return nullptr;
};
StringBuilder StringBuilder___::Replace(Char oldChar, Char newChar) {
  return nullptr;
};
StringBuilder StringBuilder___::Replace(Char oldChar, Char newChar, Int32 startIndex, Int32 count) {
  return nullptr;
};
StringBuilder StringBuilder___::Append(Char* value, Int32 valueCount) {
  return nullptr;
};
void StringBuilder___::Insert(Int32 index, Char* value, Int32 valueCount) {
};
void StringBuilder___::ReplaceAllInChunk(Array<Int32> replacements, Int32 replacementsCount, StringBuilder sourceChunk, Int32 removeCount, String value) {
};
Boolean StringBuilder___::StartsWith(StringBuilder chunk, Int32 indexInChunk, Int32 count, String value) {
  return Boolean();
};
void StringBuilder___::ReplaceInPlaceAtChunk(StringBuilder& chunk, Int32& indexInChunk, Char* value, Int32 count) {
};
void StringBuilder___::ThreadSafeCopy(Char* sourcePtr, Array<Char> destination, Int32 destinationIndex, Int32 count) {
};
void StringBuilder___::ThreadSafeCopy(Array<Char> source, Int32 sourceIndex, Span<Char> destination, Int32 destinationIndex, Int32 count) {
};
StringBuilder StringBuilder___::FindChunkForIndex(Int32 index) {
  return nullptr;
};
StringBuilder StringBuilder___::FindChunkForByte(Int32 byteIndex) {
  return nullptr;
};
StringBuilder StringBuilder___::Next(StringBuilder chunk) {
  return nullptr;
};
void StringBuilder___::ExpandByABlock(Int32 minBlockCharCount) {
};
void StringBuilder___::MakeRoom(Int32 index, Int32 count, StringBuilder& chunk, Int32& indexInChunk, Boolean doNotMoveFollowingChars) {
};
void StringBuilder___::Remove(Int32 startIndex, Int32 count, StringBuilder& chunk, Int32& indexInChunk) {
};
} // namespace System::Private::CoreLib::System::Text::StringBuilderNamespace
