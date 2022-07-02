#include "StringBuilder-dep.h"

#include <System.Private.CoreLib/Interop-dep.h>
#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/Buffer-dep.h>
#include <System.Private.CoreLib/System/Environment-dep.h>
#include <System.Private.CoreLib/System/FormatException-dep.h>
#include <System.Private.CoreLib/System/GC-dep.h>
#include <System.Private.CoreLib/System/ICustomFormatter.h>
#include <System.Private.CoreLib/System/IFormattable.h>
#include <System.Private.CoreLib/System/IndexOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/Int32-dep.h>
#include <System.Private.CoreLib/System/Int64-dep.h>
#include <System.Private.CoreLib/System/ISpanFormattable.h>
#include <System.Private.CoreLib/System/Math-dep.h>
#include <System.Private.CoreLib/System/MemoryExtensions-dep.h>
#include <System.Private.CoreLib/System/OutOfMemoryException-dep.h>
#include <System.Private.CoreLib/System/ParamsArray-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/MemoryMarshal-dep.h>
#include <System.Private.CoreLib/System/Runtime/Serialization/SerializationException-dep.h>
#include <System.Private.CoreLib/System/Runtime/Serialization/SerializationInfoEnumerator-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/Text/Encoding-dep.h>
#include <System.Private.CoreLib/System/Text/StringBuilder-dep.h>
#include <System.Private.CoreLib/System/ThrowHelper-dep.h>
#include <System.Private.CoreLib/System/UInt32-dep.h>

namespace System::Private::CoreLib::System::Text::StringBuilderNamespace {
using namespace System::Runtime::InteropServices;
using namespace System::Runtime::Serialization;

Boolean StringBuilder___::ChunkEnumerator::ManyChunkInfo___::MoveNext(StringBuilder& current) {
  Int32 num = ++_chunkPos;
  if (_chunks->get_Length() <= num) {
    return false;
  }
  current = _chunks[num];
  return true;
}

void StringBuilder___::ChunkEnumerator::ManyChunkInfo___::ctor(StringBuilder stringBuilder, Int32 chunkCount) {
  _chunks = rt::newarr<Array<StringBuilder>>(chunkCount);
  while (0 <= --chunkCount) {
    _chunks[chunkCount] = stringBuilder;
    stringBuilder = stringBuilder->m_ChunkPrevious;
  }
  _chunkPos = -1;
}

ReadOnlyMemory<Char> StringBuilder___::ChunkEnumerator::get_Current() {
  if (_currentChunk == nullptr) {
    ThrowHelper::ThrowInvalidOperationException_InvalidOperation_EnumOpCantHappen();
  }
  return ReadOnlyMemory<Char>(_currentChunk->m_ChunkChars, 0, _currentChunk->m_ChunkLength);
}

StringBuilder::in::ChunkEnumerator StringBuilder___::ChunkEnumerator::GetEnumerator() {
  return *this;
}

Boolean StringBuilder___::ChunkEnumerator::MoveNext() {
  if (_currentChunk == _firstChunk) {
    return false;
  }
  if (_manyChunks != nullptr) {
    return _manyChunks->MoveNext(_currentChunk);
  }
  StringBuilder stringBuilder = _firstChunk;
  while (stringBuilder->m_ChunkPrevious != _currentChunk) {
    stringBuilder = stringBuilder->m_ChunkPrevious;
  }
  _currentChunk = stringBuilder;
  return true;
}

StringBuilder___::ChunkEnumerator::ChunkEnumerator(StringBuilder stringBuilder) {
  _firstChunk = stringBuilder;
  _currentChunk = nullptr;
  _manyChunks = nullptr;
  Int32 num = ChunkCount(stringBuilder);
  if (8 < num) {
    _manyChunks = rt::newobj<ManyChunkInfo>(stringBuilder, num);
  }
}

Int32 StringBuilder___::ChunkEnumerator::ChunkCount(StringBuilder stringBuilder) {
  Int32 num = 0;
  while (stringBuilder != nullptr) {
    num++;
    stringBuilder = stringBuilder->m_ChunkPrevious;
  }
  return num;
}

Int32 StringBuilder___::get_Capacity() {
  return m_ChunkChars->get_Length() + m_ChunkOffset;
}

void StringBuilder___::set_Capacity(Int32 value) {
  if (value < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("value", SR::get_ArgumentOutOfRange_NegativeCapacity());
  }
  if (value > get_MaxCapacity()) {
    rt::throw_exception<ArgumentOutOfRangeException>("value", SR::get_ArgumentOutOfRange_Capacity());
  }
  if (value < get_Length()) {
    rt::throw_exception<ArgumentOutOfRangeException>("value", SR::get_ArgumentOutOfRange_SmallCapacity());
  }
  if (get_Capacity() != value) {
    Int32 length = value - m_ChunkOffset;
    Array<Char> array = GC::AllocateUninitializedArray<Char>(length);
    Array<>::in::Copy(m_ChunkChars, array, m_ChunkLength);
    m_ChunkChars = array;
  }
}

Int32 StringBuilder___::get_MaxCapacity() {
  return m_MaxCapacity;
}

Int32 StringBuilder___::get_Length() {
  return m_ChunkOffset + m_ChunkLength;
}

void StringBuilder___::set_Length(Int32 value) {
  if (value < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("value", SR::get_ArgumentOutOfRange_NegativeLength());
  }
  if (value > get_MaxCapacity()) {
    rt::throw_exception<ArgumentOutOfRangeException>("value", SR::get_ArgumentOutOfRange_SmallCapacity());
  }
  if (value == 0 && m_ChunkPrevious == nullptr) {
    m_ChunkLength = 0;
    m_ChunkOffset = 0;
    return;
  }
  Int32 num = value - get_Length();
  if (num > 0) {
    Append(u'\0', num);
    return;
  }
  StringBuilder stringBuilder = FindChunkForIndex(value);
  if (stringBuilder != (StringBuilder)this) {
    Int32 num2 = Math::Min(get_Capacity(), Math::Max(get_Length() * 6 / 5, m_ChunkChars->get_Length()));
    Int32 num3 = num2 - stringBuilder->m_ChunkOffset;
    if (num3 > stringBuilder->m_ChunkChars->get_Length()) {
      Array<Char> array = GC::AllocateUninitializedArray<Char>(num3);
      Array<>::in::Copy(stringBuilder->m_ChunkChars, array, stringBuilder->m_ChunkLength);
      m_ChunkChars = array;
    } else {
      m_ChunkChars = stringBuilder->m_ChunkChars;
    }
    m_ChunkPrevious = stringBuilder->m_ChunkPrevious;
    m_ChunkOffset = stringBuilder->m_ChunkOffset;
  }
  m_ChunkLength = value - stringBuilder->m_ChunkOffset;
}

Char StringBuilder___::get_Chars(Int32 index) {
  StringBuilder stringBuilder = (StringBuilder)this;
  do {
    Int32 num = index - stringBuilder->m_ChunkOffset;
    if (num >= 0) {
      if (num >= stringBuilder->m_ChunkLength) {
        rt::throw_exception<IndexOutOfRangeException>();
      }
      return stringBuilder->m_ChunkChars[num];
    }
    stringBuilder = stringBuilder->m_ChunkPrevious;
  } while (stringBuilder != nullptr);
  rt::throw_exception<IndexOutOfRangeException>();
}

void StringBuilder___::set_Chars(Int32 index, Char value) {
  StringBuilder stringBuilder = (StringBuilder)this;
  do {
    Int32 num = index - stringBuilder->m_ChunkOffset;
    if (num >= 0) {
      if (num >= stringBuilder->m_ChunkLength) {
        rt::throw_exception<ArgumentOutOfRangeException>("index", SR::get_ArgumentOutOfRange_Index());
      }
      stringBuilder->m_ChunkChars[num] = value;
      return;
    }
    stringBuilder = stringBuilder->m_ChunkPrevious;
  } while (stringBuilder != nullptr);
  rt::throw_exception<ArgumentOutOfRangeException>("index", SR::get_ArgumentOutOfRange_Index());
}

Span<Char> StringBuilder___::get_RemainingCurrentChunk() {
  return Span<Char>(m_ChunkChars, m_ChunkLength, m_ChunkChars->get_Length() - m_ChunkLength);
}

Int32 StringBuilder___::GetReplaceBufferCapacity(Int32 requiredCapacity) {
  Int32 num = get_Capacity();
  if (num < requiredCapacity) {
    num = (requiredCapacity + 1) & -2;
  }
  return num;
}

void StringBuilder___::ReplaceBufferInternal(Char* newBuffer, Int32 newLength) {
  if (newLength > m_MaxCapacity) {
    rt::throw_exception<ArgumentOutOfRangeException>("capacity", SR::get_ArgumentOutOfRange_Capacity());
  }
  if (newLength > m_ChunkChars->get_Length()) {
    m_ChunkChars = rt::newarr<Array<Char>>(GetReplaceBufferCapacity(newLength));
  }
  Span<Char>(newBuffer, newLength).CopyTo(m_ChunkChars);
  m_ChunkLength = newLength;
  m_ChunkPrevious = nullptr;
  m_ChunkOffset = 0;
}

void StringBuilder___::ReplaceBufferUtf8Internal(ReadOnlySpan<Byte> source) {
  if (source.get_Length() > m_MaxCapacity) {
    rt::throw_exception<ArgumentOutOfRangeException>("capacity", SR::get_ArgumentOutOfRange_Capacity());
  }
  Int32 charCount = Encoding::in::get_UTF8()->GetCharCount(source);
  if (charCount > m_ChunkChars->get_Length()) {
    m_ChunkChars = rt::newarr<Array<Char>>(GetReplaceBufferCapacity(charCount));
  }
  m_ChunkLength = Encoding::in::get_UTF8()->GetChars(source, m_ChunkChars);
  m_ChunkPrevious = nullptr;
  m_ChunkOffset = 0;
}

void StringBuilder___::ReplaceBufferAnsiInternal(SByte* newBuffer, Int32 newLength) {
  if (newLength > m_MaxCapacity) {
    rt::throw_exception<ArgumentOutOfRangeException>("capacity", SR::get_ArgumentOutOfRange_Capacity());
  }
  if (newLength > m_ChunkChars->get_Length()) {
    m_ChunkChars = rt::newarr<Array<Char>>(GetReplaceBufferCapacity(newLength));
  }
  Int32 chunkLength;
  {
    Char* lpWideCharStr = rt::fixed(m_ChunkChars);
    chunkLength = Interop::Kernel32::MultiByteToWideChar(0u, 1u, (Byte*)newBuffer, newLength, lpWideCharStr, newLength);
  }
  m_ChunkOffset = 0;
  m_ChunkLength = chunkLength;
  m_ChunkPrevious = nullptr;
}

void StringBuilder___::InternalCopy(IntPtr dest, Int32 len) {
  if (len == 0) {
    return;
  }
  Boolean flag = true;
  Byte* ptr = (Byte*)dest.ToPointer();
  StringBuilder stringBuilder = FindChunkForByte(len);
  do {
    Int32 num = stringBuilder->m_ChunkOffset * 2;
    Int32 len2 = stringBuilder->m_ChunkLength * 2;
    {
      Char* ptr2 = rt::fixed(&stringBuilder->m_ChunkChars[0]);
      Byte* src = (Byte*)ptr2;
      if (flag) {
        flag = false;
        Buffer::Memcpy(ptr + num, src, len - num);
      } else {
        Buffer::Memcpy(ptr + num, src, len2);
      }
    }
    stringBuilder = stringBuilder->m_ChunkPrevious;
  } while (stringBuilder != nullptr);
}

StringBuilder StringBuilder___::FindChunkForByte(Int32 byteIndex) {
  StringBuilder stringBuilder = (StringBuilder)this;
  while (stringBuilder->m_ChunkOffset * 2 > byteIndex) {
    stringBuilder = stringBuilder->m_ChunkPrevious;
  }
  return stringBuilder;
}

void StringBuilder___::ctor() {
  m_MaxCapacity = Int32::MaxValue();
  m_ChunkChars = rt::newarr<Array<Char>>(16);
}

void StringBuilder___::ctor(Int32 capacity) {
}

void StringBuilder___::ctor(String value) {
}

void StringBuilder___::ctor(String value, Int32 capacity) {
}

void StringBuilder___::ctor(String value, Int32 startIndex, Int32 length, Int32 capacity) {
  if (capacity < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("capacity", SR::Format(SR::get_ArgumentOutOfRange_MustBePositive(), "capacity"));
  }
  if (length < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("length", SR::Format(SR::get_ArgumentOutOfRange_MustBeNonNegNum(), "length"));
  }
  if (startIndex < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("startIndex", SR::get_ArgumentOutOfRange_StartIndex());
  }
  if (value == nullptr) {
    value = String::in::Empty;
  }
  if (startIndex > value->get_Length() - length) {
    rt::throw_exception<ArgumentOutOfRangeException>("length", SR::get_ArgumentOutOfRange_IndexLength());
  }
  m_MaxCapacity = Int32::MaxValue();
  if (capacity == 0) {
    capacity = 16;
  }
  capacity = Math::Max(capacity, length);
  m_ChunkChars = GC::AllocateUninitializedArray<Char>(capacity);
  m_ChunkLength = length;
  {
    Char* ptr = rt::fixed(value);
    Char* ptr2 = ptr;
    ThreadSafeCopy(ptr2 + startIndex, m_ChunkChars, 0, length);
  }
}

void StringBuilder___::ctor(Int32 capacity, Int32 maxCapacity) {
  if (capacity > maxCapacity) {
    rt::throw_exception<ArgumentOutOfRangeException>("capacity", SR::get_ArgumentOutOfRange_Capacity());
  }
  if (maxCapacity < 1) {
    rt::throw_exception<ArgumentOutOfRangeException>("maxCapacity", SR::get_ArgumentOutOfRange_SmallMaxCapacity());
  }
  if (capacity < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("capacity", SR::Format(SR::get_ArgumentOutOfRange_MustBePositive(), "capacity"));
  }
  if (capacity == 0) {
    capacity = Math::Min(16, maxCapacity);
  }
  m_MaxCapacity = maxCapacity;
  m_ChunkChars = GC::AllocateUninitializedArray<Char>(capacity);
}

void StringBuilder___::ctor(SerializationInfo info, StreamingContext context) {
  if (info == nullptr) {
    rt::throw_exception<ArgumentNullException>("info");
  }
  Int32 num = 0;
  String text = nullptr;
  Int32 num2 = Int32::MaxValue();
  Boolean flag = false;
  SerializationInfoEnumerator enumerator = info->GetEnumerator();
  while (enumerator->MoveNext()) {
    String name = enumerator->get_Name();
    if (!(name == "m_MaxCapacity")) {
      if (!(name == "m_StringValue")) {
        if (name == "Capacity") {
          num = info->GetInt32("Capacity");
          flag = true;
        }
      } else {
        text = info->GetString("m_StringValue");
      }
    } else {
      num2 = info->GetInt32("m_MaxCapacity");
    }
  }
  if (text == nullptr) {
    text = String::in::Empty;
  }
  if (num2 < 1 || text->get_Length() > num2) {
    rt::throw_exception<SerializationException>(SR::get_Serialization_StringBuilderMaxCapacity());
  }
  if (!flag) {
    num = Math::Min(Math::Max(16, text->get_Length()), num2);
  }
  if (num < 0 || num < text->get_Length() || num > num2) {
    rt::throw_exception<SerializationException>(SR::get_Serialization_StringBuilderCapacity());
  }
  m_MaxCapacity = num2;
  m_ChunkChars = GC::AllocateUninitializedArray<Char>(num);
  text->CopyTo(0, m_ChunkChars, 0, text->get_Length());
  m_ChunkLength = text->get_Length();
}

void StringBuilder___::GetObjectDataOfISerializable(SerializationInfo info, StreamingContext context) {
  if (info == nullptr) {
    rt::throw_exception<ArgumentNullException>("info");
  }
  info->AddValue("m_MaxCapacity", m_MaxCapacity);
  info->AddValue("Capacity", get_Capacity());
  info->AddValue("m_StringValue", ToString());
  info->AddValue("m_currentThread", (Int32)0);
}

Int32 StringBuilder___::EnsureCapacity(Int32 capacity) {
  if (capacity < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("capacity", SR::get_ArgumentOutOfRange_NegativeCapacity());
  }
  if (get_Capacity() < capacity) {
    set_Capacity(capacity);
  }
  return get_Capacity();
}

String StringBuilder___::ToString() {
  if (get_Length() == 0) {
    return String::in::Empty;
  }
  String text = String::in::FastAllocateString(get_Length());
  StringBuilder stringBuilder = (StringBuilder)this;
  {
    Char* ptr = rt::fixed(text);
    Char* ptr2 = ptr;
    do {
      if (stringBuilder->m_ChunkLength > 0) {
        Array<Char> chunkChars = stringBuilder->m_ChunkChars;
        Int32 chunkOffset = stringBuilder->m_ChunkOffset;
        Int32 chunkLength = stringBuilder->m_ChunkLength;
        if ((UInt32)(chunkLength + chunkOffset) > (UInt32)text->get_Length() || (UInt32)chunkLength > (UInt32)chunkChars->get_Length()) {
          rt::throw_exception<ArgumentOutOfRangeException>("chunkLength", SR::get_ArgumentOutOfRange_Index());
        }
        {
          Char* smem = rt::fixed(&chunkChars[0]);
          String::in::wstrcpy(ptr2 + chunkOffset, smem, chunkLength);
        }
      }
      stringBuilder = stringBuilder->m_ChunkPrevious;
    } while (stringBuilder != nullptr);
    return text;
  }
}

String StringBuilder___::ToString(Int32 startIndex, Int32 length) {
  Int32 length2 = get_Length();
  if (startIndex < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("startIndex", SR::get_ArgumentOutOfRange_StartIndex());
  }
  if (startIndex > length2) {
    rt::throw_exception<ArgumentOutOfRangeException>("startIndex", SR::get_ArgumentOutOfRange_StartIndexLargerThanLength());
  }
  if (length < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("length", SR::get_ArgumentOutOfRange_NegativeLength());
  }
  if (startIndex > length2 - length) {
    rt::throw_exception<ArgumentOutOfRangeException>("length", SR::get_ArgumentOutOfRange_IndexLength());
  }
  String text = String::in::FastAllocateString(length);
  {
    Char* ptr = rt::fixed(text);
    Char* pointer = ptr;
    CopyTo(startIndex, Span<Char>(pointer, length), length);
    return text;
  }
}

StringBuilder StringBuilder___::Clear() {
  set_Length(0);
  return (StringBuilder)this;
}

StringBuilder::in::ChunkEnumerator StringBuilder___::GetChunks() {
  return ChunkEnumerator((StringBuilder)this);
}

StringBuilder StringBuilder___::Append(Char value, Int32 repeatCount) {
  if (repeatCount < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("repeatCount", SR::get_ArgumentOutOfRange_NegativeCount());
  }
  if (repeatCount == 0) {
    return (StringBuilder)this;
  }
  Int32 num = get_Length() + repeatCount;
  if (num > m_MaxCapacity || num < repeatCount) {
    rt::throw_exception<ArgumentOutOfRangeException>("repeatCount", SR::get_ArgumentOutOfRange_LengthGreaterThanCapacity());
  }
  Int32 num2 = m_ChunkLength;
  while (repeatCount > 0) {
    if (num2 < m_ChunkChars->get_Length()) {
      m_ChunkChars[num2++] = value;
      repeatCount--;
    } else {
      m_ChunkLength = num2;
      ExpandByABlock(repeatCount);
      num2 = 0;
    }
  }
  m_ChunkLength = num2;
  return (StringBuilder)this;
}

StringBuilder StringBuilder___::Append(Array<Char> value, Int32 startIndex, Int32 charCount) {
  if (startIndex < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("startIndex", SR::get_ArgumentOutOfRange_GenericPositive());
  }
  if (charCount < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("charCount", SR::get_ArgumentOutOfRange_GenericPositive());
  }
  if (value == nullptr) {
    if (startIndex == 0 && charCount == 0) {
      return (StringBuilder)this;
    }
    rt::throw_exception<ArgumentNullException>("value");
  }
  if (charCount > value->get_Length() - startIndex) {
    rt::throw_exception<ArgumentOutOfRangeException>("charCount", SR::get_ArgumentOutOfRange_Index());
  }
  if (charCount == 0) {
    return (StringBuilder)this;
  }
  {
    Char* value2 = rt::fixed(&value[startIndex]);
    Append(value2, charCount);
    return (StringBuilder)this;
  }
}

StringBuilder StringBuilder___::Append(String value) {
  if (value != nullptr) {
    Array<Char> chunkChars = m_ChunkChars;
    Int32 chunkLength = m_ChunkLength;
    Int32 length = value->get_Length();
    if ((UInt32)(chunkLength + length) < (UInt32)chunkChars->get_Length()) {
      if (length <= 2) {
        if (length > 0) {
          chunkChars[chunkLength] = value[0];
        }
        if (length > 1) {
          chunkChars[chunkLength + 1] = value[1];
        }
      } else {
        {
          Char* ptr = rt::fixed(value);
          Char* smem = ptr;
          {
            Char* dmem = rt::fixed(&chunkChars[chunkLength]);
            String::in::wstrcpy(dmem, smem, length);
          }
        }
      }
      m_ChunkLength = chunkLength + length;
    } else {
      AppendHelper(value);
    }
  }
  return (StringBuilder)this;
}

void StringBuilder___::AppendHelper(String value) {
  {
    Char* ptr = rt::fixed(value);
    Char* value2 = ptr;
    Append(value2, value->get_Length());
  }
}

StringBuilder StringBuilder___::Append(String value, Int32 startIndex, Int32 count) {
  if (startIndex < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("startIndex", SR::get_ArgumentOutOfRange_Index());
  }
  if (count < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("count", SR::get_ArgumentOutOfRange_GenericPositive());
  }
  if (value == nullptr) {
    if (startIndex == 0 && count == 0) {
      return (StringBuilder)this;
    }
    rt::throw_exception<ArgumentNullException>("value");
  }
  if (count == 0) {
    return (StringBuilder)this;
  }
  if (startIndex > value->get_Length() - count) {
    rt::throw_exception<ArgumentOutOfRangeException>("startIndex", SR::get_ArgumentOutOfRange_Index());
  }
  {
    Char* ptr = rt::fixed(value);
    Char* ptr2 = ptr;
    Append(ptr2 + startIndex, count);
    return (StringBuilder)this;
  }
}

StringBuilder StringBuilder___::Append(StringBuilder value) {
  if (value != nullptr && value->get_Length() != 0) {
    return AppendCore(value, 0, value->get_Length());
  }
  return (StringBuilder)this;
}

StringBuilder StringBuilder___::Append(StringBuilder value, Int32 startIndex, Int32 count) {
  if (startIndex < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("startIndex", SR::get_ArgumentOutOfRange_Index());
  }
  if (count < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("count", SR::get_ArgumentOutOfRange_GenericPositive());
  }
  if (value == nullptr) {
    if (startIndex == 0 && count == 0) {
      return (StringBuilder)this;
    }
    rt::throw_exception<ArgumentNullException>("value");
  }
  if (count == 0) {
    return (StringBuilder)this;
  }
  if (count > value->get_Length() - startIndex) {
    rt::throw_exception<ArgumentOutOfRangeException>("startIndex", SR::get_ArgumentOutOfRange_Index());
  }
  return AppendCore(value, startIndex, count);
}

StringBuilder StringBuilder___::AppendCore(StringBuilder value, Int32 startIndex, Int32 count) {
  if (value == (StringBuilder)this) {
    return Append(value->ToString(startIndex, count));
  }
  Int32 num = get_Length() + count;
  if ((UInt32)num > (UInt32)m_MaxCapacity) {
    rt::throw_exception<ArgumentOutOfRangeException>("Capacity", SR::get_ArgumentOutOfRange_Capacity());
  }
  while (count > 0) {
    Int32 num2 = Math::Min(m_ChunkChars->get_Length() - m_ChunkLength, count);
    if (num2 == 0) {
      ExpandByABlock(count);
      num2 = Math::Min(m_ChunkChars->get_Length() - m_ChunkLength, count);
    }
    value->CopyTo(startIndex, Span<Char>(m_ChunkChars, m_ChunkLength, num2), num2);
    m_ChunkLength += num2;
    startIndex += num2;
    count -= num2;
  }
  return (StringBuilder)this;
}

StringBuilder StringBuilder___::AppendLine() {
  return Append(Environment::get_NewLine());
}

StringBuilder StringBuilder___::AppendLine(String value) {
  Append(value);
  return Append(Environment::get_NewLine());
}

void StringBuilder___::CopyTo(Int32 sourceIndex, Array<Char> destination, Int32 destinationIndex, Int32 count) {
  if (destination == nullptr) {
    rt::throw_exception<ArgumentNullException>("destination");
  }
  if (destinationIndex < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("destinationIndex", SR::Format(SR::get_ArgumentOutOfRange_MustBeNonNegNum(), "destinationIndex"));
  }
  if (destinationIndex > destination->get_Length() - count) {
    rt::throw_exception<ArgumentException>(SR::get_ArgumentOutOfRange_OffsetOut());
  }
  CopyTo(sourceIndex, Span<Char>(destination).Slice(destinationIndex), count);
}

void StringBuilder___::CopyTo(Int32 sourceIndex, Span<Char> destination, Int32 count) {
  if (count < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("count", SR::get_Arg_NegativeArgCount());
  }
  if ((UInt32)sourceIndex > (UInt32)get_Length()) {
    rt::throw_exception<ArgumentOutOfRangeException>("sourceIndex", SR::get_ArgumentOutOfRange_Index());
  }
  if (sourceIndex > get_Length() - count) {
    rt::throw_exception<ArgumentException>(SR::get_Arg_LongerThanSrcString());
  }
  StringBuilder stringBuilder = (StringBuilder)this;
  Int32 num = sourceIndex + count;
  Int32 num2 = count;
  while (count > 0) {
    Int32 num3 = num - stringBuilder->m_ChunkOffset;
    if (num3 >= 0) {
      num3 = Math::Min(num3, stringBuilder->m_ChunkLength);
      Int32 num4 = count;
      Int32 num5 = num3 - count;
      if (num5 < 0) {
        num4 += num5;
        num5 = 0;
      }
      num2 -= num4;
      count -= num4;
      ThreadSafeCopy(stringBuilder->m_ChunkChars, num5, destination, num2, num4);
    }
    stringBuilder = stringBuilder->m_ChunkPrevious;
  }
}

StringBuilder StringBuilder___::Insert(Int32 index, String value, Int32 count) {
  if (count < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("count", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  Int32 length = get_Length();
  if ((UInt32)index > (UInt32)length) {
    rt::throw_exception<ArgumentOutOfRangeException>("index", SR::get_ArgumentOutOfRange_Index());
  }
  if (String::in::IsNullOrEmpty(value) || count == 0) {
    return (StringBuilder)this;
  }
  Int64 num = (Int64)value->get_Length() * (Int64)count;
  if (num > get_MaxCapacity() - get_Length()) {
    rt::throw_exception<OutOfMemoryException>();
  }
  StringBuilder chunk;
  Int32 indexInChunk;
  MakeRoom(index, (Int32)num, chunk, indexInChunk, false);
  {
    Char* ptr = rt::fixed(value);
    Char* value2 = ptr;
    while (count > 0) {
      ReplaceInPlaceAtChunk(chunk, indexInChunk, value2, value->get_Length());
      count--;
    }
    return (StringBuilder)this;
  }
}

StringBuilder StringBuilder___::Remove(Int32 startIndex, Int32 length) {
  if (length < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("length", SR::get_ArgumentOutOfRange_NegativeLength());
  }
  if (startIndex < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("startIndex", SR::get_ArgumentOutOfRange_StartIndex());
  }
  if (length > get_Length() - startIndex) {
    rt::throw_exception<ArgumentOutOfRangeException>("length", SR::get_ArgumentOutOfRange_Index());
  }
  if (get_Length() == length && startIndex == 0) {
    set_Length(0);
    return (StringBuilder)this;
  }
  if (length > 0) {
    StringBuilder chunk;
    Int32 indexInChunk;
    Remove(startIndex, length, chunk, indexInChunk);
  }
  return (StringBuilder)this;
}

StringBuilder StringBuilder___::Append(Boolean value) {
  return Append(value.ToString());
}

StringBuilder StringBuilder___::Append(Char value) {
  Int32 chunkLength = m_ChunkLength;
  Array<Char> chunkChars = m_ChunkChars;
  if ((UInt32)chunkChars->get_Length() > (UInt32)chunkLength) {
    chunkChars[chunkLength] = value;
    m_ChunkLength++;
  } else {
    Append(value, 1);
  }
  return (StringBuilder)this;
}

StringBuilder StringBuilder___::Append(SByte value) {
  return AppendSpanFormattable(value);
}

StringBuilder StringBuilder___::Append(Byte value) {
  return AppendSpanFormattable(value);
}

StringBuilder StringBuilder___::Append(Int16 value) {
  return AppendSpanFormattable(value);
}

StringBuilder StringBuilder___::Append(Int32 value) {
  return AppendSpanFormattable(value);
}

StringBuilder StringBuilder___::Append(Int64 value) {
  return AppendSpanFormattable(value);
}

StringBuilder StringBuilder___::Append(Single value) {
  return AppendSpanFormattable(value);
}

StringBuilder StringBuilder___::Append(Double value) {
  return AppendSpanFormattable(value);
}

StringBuilder StringBuilder___::Append(Decimal value) {
  return AppendSpanFormattable(value);
}

StringBuilder StringBuilder___::Append(UInt16 value) {
  return AppendSpanFormattable(value);
}

StringBuilder StringBuilder___::Append(UInt32 value) {
  return AppendSpanFormattable(value);
}

StringBuilder StringBuilder___::Append(UInt64 value) {
  return AppendSpanFormattable(value);
}

StringBuilder StringBuilder___::Append(Object value) {
  if (value != nullptr) {
    return Append(value->ToString());
  }
  return (StringBuilder)this;
}

StringBuilder StringBuilder___::Append(Array<Char> value) {
  if (value != nullptr && value->get_Length() != 0) {
    {
      Char* value2 = rt::fixed(&value[0]);
      Append(value2, value->get_Length());
    }
  }
  return (StringBuilder)this;
}

StringBuilder StringBuilder___::Append(ReadOnlySpan<Char> value) {
  if (value.get_Length() > 0) {
    {
      Char* value2 = rt::fixed(&MemoryMarshal::GetReference(value));
      Append(value2, value.get_Length());
    }
  }
  return (StringBuilder)this;
}

StringBuilder StringBuilder___::Append(ReadOnlyMemory<Char> value) {
  return Append(value.get_Span());
}

StringBuilder StringBuilder___::AppendJoin(String separator, Array<Object> values) {
  if (separator == nullptr) {
    separator = String::in::Empty;
  }
  {
    Char* ptr = rt::fixed(separator);
    Char* separator2 = ptr;
    return AppendJoinCore(separator2, separator->get_Length(), values);
  }
}

StringBuilder StringBuilder___::AppendJoin(String separator, Array<String> values) {
  if (separator == nullptr) {
    separator = String::in::Empty;
  }
  {
    Char* ptr = rt::fixed(separator);
    Char* separator2 = ptr;
    return AppendJoinCore(separator2, separator->get_Length(), values);
  }
}

StringBuilder StringBuilder___::AppendJoin(Char separator, Array<Object> values) {
  return AppendJoinCore(&separator, 1, values);
}

StringBuilder StringBuilder___::AppendJoin(Char separator, Array<String> values) {
  return AppendJoinCore(&separator, 1, values);
}

StringBuilder StringBuilder___::Insert(Int32 index, String value) {
  if ((UInt32)index > (UInt32)get_Length()) {
    rt::throw_exception<ArgumentOutOfRangeException>("index", SR::get_ArgumentOutOfRange_Index());
  }
  if (value != nullptr) {
    {
      Char* ptr = rt::fixed(value);
      Char* value2 = ptr;
      Insert(index, value2, value->get_Length());
    }
  }
  return (StringBuilder)this;
}

StringBuilder StringBuilder___::Insert(Int32 index, Boolean value) {
  return Insert(index, value.ToString(), 1);
}

StringBuilder StringBuilder___::Insert(Int32 index, SByte value) {
  return Insert(index, value.ToString(), 1);
}

StringBuilder StringBuilder___::Insert(Int32 index, Byte value) {
  return Insert(index, value.ToString(), 1);
}

StringBuilder StringBuilder___::Insert(Int32 index, Int16 value) {
  return Insert(index, value.ToString(), 1);
}

StringBuilder StringBuilder___::Insert(Int32 index, Char value) {
  Insert(index, &value, 1);
  return (StringBuilder)this;
}

StringBuilder StringBuilder___::Insert(Int32 index, Array<Char> value) {
  if ((UInt32)index > (UInt32)get_Length()) {
    rt::throw_exception<ArgumentOutOfRangeException>("index", SR::get_ArgumentOutOfRange_Index());
  }
  if (value != nullptr) {
    Insert(index, value, 0, value->get_Length());
  }
  return (StringBuilder)this;
}

StringBuilder StringBuilder___::Insert(Int32 index, Array<Char> value, Int32 startIndex, Int32 charCount) {
  Int32 length = get_Length();
  if ((UInt32)index > (UInt32)length) {
    rt::throw_exception<ArgumentOutOfRangeException>("index", SR::get_ArgumentOutOfRange_Index());
  }
  if (value == nullptr) {
    if (startIndex == 0 && charCount == 0) {
      return (StringBuilder)this;
    }
    rt::throw_exception<ArgumentNullException>("value", SR::get_ArgumentNull_String());
  }
  if (startIndex < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("startIndex", SR::get_ArgumentOutOfRange_StartIndex());
  }
  if (charCount < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("charCount", SR::get_ArgumentOutOfRange_GenericPositive());
  }
  if (startIndex > value->get_Length() - charCount) {
    rt::throw_exception<ArgumentOutOfRangeException>("startIndex", SR::get_ArgumentOutOfRange_Index());
  }
  if (charCount > 0) {
    {
      Char* value2 = rt::fixed(&value[startIndex]);
      Insert(index, value2, charCount);
    }
  }
  return (StringBuilder)this;
}

StringBuilder StringBuilder___::Insert(Int32 index, Int32 value) {
  return Insert(index, value.ToString(), 1);
}

StringBuilder StringBuilder___::Insert(Int32 index, Int64 value) {
  return Insert(index, value.ToString(), 1);
}

StringBuilder StringBuilder___::Insert(Int32 index, Single value) {
  return Insert(index, value.ToString(), 1);
}

StringBuilder StringBuilder___::Insert(Int32 index, Double value) {
  return Insert(index, value.ToString(), 1);
}

StringBuilder StringBuilder___::Insert(Int32 index, Decimal value) {
  return Insert(index, value.ToString(), 1);
}

StringBuilder StringBuilder___::Insert(Int32 index, UInt16 value) {
  return Insert(index, value.ToString(), 1);
}

StringBuilder StringBuilder___::Insert(Int32 index, UInt32 value) {
  return Insert(index, value.ToString(), 1);
}

StringBuilder StringBuilder___::Insert(Int32 index, UInt64 value) {
  return Insert(index, value.ToString(), 1);
}

StringBuilder StringBuilder___::Insert(Int32 index, Object value) {
  if (value != nullptr) {
    return Insert(index, value->ToString(), 1);
  }
  return (StringBuilder)this;
}

StringBuilder StringBuilder___::Insert(Int32 index, ReadOnlySpan<Char> value) {
  if ((UInt32)index > (UInt32)get_Length()) {
    rt::throw_exception<ArgumentOutOfRangeException>("index", SR::get_ArgumentOutOfRange_Index());
  }
  if (value.get_Length() > 0) {
    {
      Char* value2 = rt::fixed(&MemoryMarshal::GetReference(value));
      Insert(index, value2, value.get_Length());
    }
  }
  return (StringBuilder)this;
}

StringBuilder StringBuilder___::AppendFormat(String format, Object arg0) {
  return AppendFormatHelper(nullptr, format, ParamsArray(arg0));
}

StringBuilder StringBuilder___::AppendFormat(String format, Object arg0, Object arg1) {
  return AppendFormatHelper(nullptr, format, ParamsArray(arg0, arg1));
}

StringBuilder StringBuilder___::AppendFormat(String format, Object arg0, Object arg1, Object arg2) {
  return AppendFormatHelper(nullptr, format, ParamsArray(arg0, arg1, arg2));
}

StringBuilder StringBuilder___::AppendFormat(String format, Array<Object> args) {
  if (args == nullptr) {
    String paramName = ((format == nullptr) ? "format" : "args");
    rt::throw_exception<ArgumentNullException>(paramName);
  }
  return AppendFormatHelper(nullptr, format, ParamsArray(args));
}

StringBuilder StringBuilder___::AppendFormat(IFormatProvider provider, String format, Object arg0) {
  return AppendFormatHelper(provider, format, ParamsArray(arg0));
}

StringBuilder StringBuilder___::AppendFormat(IFormatProvider provider, String format, Object arg0, Object arg1) {
  return AppendFormatHelper(provider, format, ParamsArray(arg0, arg1));
}

StringBuilder StringBuilder___::AppendFormat(IFormatProvider provider, String format, Object arg0, Object arg1, Object arg2) {
  return AppendFormatHelper(provider, format, ParamsArray(arg0, arg1, arg2));
}

StringBuilder StringBuilder___::AppendFormat(IFormatProvider provider, String format, Array<Object> args) {
  if (args == nullptr) {
    String paramName = ((format == nullptr) ? "format" : "args");
    rt::throw_exception<ArgumentNullException>(paramName);
  }
  return AppendFormatHelper(provider, format, ParamsArray(args));
}

void StringBuilder___::FormatError() {
  rt::throw_exception<FormatException>(SR::get_Format_InvalidString());
}

StringBuilder StringBuilder___::AppendFormatHelper(IFormatProvider provider, String format, ParamsArray args) {
  if (format == nullptr) {
    rt::throw_exception<ArgumentNullException>("format");
  }
  Int32 num = 0;
  Int32 length = format->get_Length();
  Char c = u'\0';
  ICustomFormatter customFormatter = nullptr;
  if (provider != nullptr) {
    customFormatter = (ICustomFormatter)provider->GetFormat(typeof<ICustomFormatter>());
  }
  while (true) {
    if (num < length) {
      c = format[num];
      num++;
      if (c == u'}') {
        if (num < length && format[num] == u'}') {
          num++;
        } else {
          FormatError();
        }
      } else if (c == u'{') {
        if (num >= length || format[num] != u'{') {
          num--;
          goto IL_008f;
        }
        num++;
      }

      Append(c);
      continue;
    }
    goto IL_008f;

  IL_008f:
    if (num == length) {
      break;
    }
    num++;
    if (num == length || (c = format[num]) < u'0' || c > u'9') {
      FormatError();
    }
    Int32 num2 = 0;
    do {
      num2 = num2 * 10 + c - 48;
      num++;
      if (num == length) {
        FormatError();
      }
      c = format[num];
    } while (c >= u'0' && c <= u'9' && num2 < 1000000);
    if (num2 >= args.get_Length()) {
      rt::throw_exception<FormatException>(SR::get_Format_IndexOutOfRange());
    }
    for (; num < length; num++) {
      if ((c = format[num]) != u' ') {
        break;
      }
    }
    Boolean flag = false;
    Int32 num3 = 0;
    if (c == u',') {
      for (num++; num < length && format[num] == u' '; num++) {
      }
      if (num == length) {
        FormatError();
      }
      c = format[num];
      if (c == u'-') {
        flag = true;
        num++;
        if (num == length) {
          FormatError();
        }
        c = format[num];
      }
      if (c < u'0' || c > u'9') {
        FormatError();
      }
      do {
        num3 = num3 * 10 + c - 48;
        num++;
        if (num == length) {
          FormatError();
        }
        c = format[num];
      } while (c >= u'0' && c <= u'9' && num3 < 1000000);
    }
    for (; num < length; num++) {
      if ((c = format[num]) != u' ') {
        break;
      }
    }
    Object obj = args[num2];
    ReadOnlySpan<Char> readOnlySpan;
    switch (c.get()) {
      case u':':
        {
          num++;
          Int32 num4 = num;
          while (true) {
            if (num == length) {
              FormatError();
            }
            c = format[num];
            switch (c.get()) {
              case u'{':
                FormatError();
                goto IL_0205;
              default:
                goto IL_0205;
              case u'}':
                break;
            }
            break;

          IL_0205:
            num++;
          }
          if (num > num4) {
            readOnlySpan = MemoryExtensions::AsSpan(format, num4, num - num4);
          }
          break;
        }default:
        FormatError();
        break;
      case u'}':
        break;
    }
    num++;
    String text = nullptr;
    String text2 = nullptr;
    if (customFormatter != nullptr) {
      if (readOnlySpan.get_Length() != 0) {
        text2 = rt::newstr<String>(readOnlySpan);
      }
      text = customFormatter->Format(text2, obj, provider);
    }
    if (text == nullptr) {
      ISpanFormattable spanFormattable = rt::as<ISpanFormattable>(obj);
      Int32 charsWritten;
      if (spanFormattable != nullptr && (flag || num3 == 0) && spanFormattable->TryFormat(get_RemainingCurrentChunk(), charsWritten, readOnlySpan, provider)) {
        m_ChunkLength += charsWritten;
        Int32 num5 = num3 - charsWritten;
        if (flag && num5 > 0) {
          Append(u' ', num5);
        }
        continue;
      }
      IFormattable formattable = rt::as<IFormattable>(obj);
      if (formattable != nullptr) {
        if (readOnlySpan.get_Length() != 0 && text2 == nullptr) {
          text2 = rt::newstr<String>(readOnlySpan);
        }
        text = formattable->ToString(text2, provider);
      } else if (obj != nullptr) {
        text = obj->ToString();
      }

    }
    if (text == nullptr) {
      text = String::in::Empty;
    }
    Int32 num6 = num3 - text->get_Length();
    if (!flag && num6 > 0) {
      Append(u' ', num6);
    }
    Append(text);
    if (flag && num6 > 0) {
      Append(u' ', num6);
    }
  }
  return (StringBuilder)this;
}

StringBuilder StringBuilder___::Replace(String oldValue, String newValue) {
  return Replace(oldValue, newValue, 0, get_Length());
}

Boolean StringBuilder___::Equals(StringBuilder sb) {
  if (sb == nullptr) {
    return false;
  }
  if (get_Length() != sb->get_Length()) {
    return false;
  }
  if (sb == (StringBuilder)this) {
    return true;
  }
  StringBuilder stringBuilder = (StringBuilder)this;
  Int32 num = stringBuilder->m_ChunkLength;
  StringBuilder stringBuilder2 = sb;
  Int32 num2 = stringBuilder2->m_ChunkLength;
  do {
    num--;
    num2--;
    while (num < 0) {
      stringBuilder = stringBuilder->m_ChunkPrevious;
      if (stringBuilder == nullptr) {
        break;
      }
      num = stringBuilder->m_ChunkLength + num;
    }
    while (num2 < 0) {
      stringBuilder2 = stringBuilder2->m_ChunkPrevious;
      if (stringBuilder2 == nullptr) {
        break;
      }
      num2 = stringBuilder2->m_ChunkLength + num2;
    }
    if (num < 0) {
      return num2 < 0;
    }
    if (num2 < 0) {
      return false;
    }
  } while (stringBuilder->m_ChunkChars[num] == stringBuilder2->m_ChunkChars[num2]);
  return false;
}

Boolean StringBuilder___::Equals(ReadOnlySpan<Char> span) {
  if (span.get_Length() != get_Length()) {
    return false;
  }
  StringBuilder stringBuilder = (StringBuilder)this;
  Int32 num = 0;
  do {
    Int32 chunkLength = stringBuilder->m_ChunkLength;
    num += chunkLength;
    ReadOnlySpan<Char> span2 = ReadOnlySpan<Char>(stringBuilder->m_ChunkChars, 0, chunkLength);
    if (!MemoryExtensions::EqualsOrdinal(span2, span.Slice(span.get_Length() - num, chunkLength))) {
      return false;
    }
    stringBuilder = stringBuilder->m_ChunkPrevious;
  } while (stringBuilder != nullptr);
  return true;
}

StringBuilder StringBuilder___::Replace(String oldValue, String newValue, Int32 startIndex, Int32 count) {
  Int32 length = get_Length();
  if ((UInt32)startIndex > (UInt32)length) {
    rt::throw_exception<ArgumentOutOfRangeException>("startIndex", SR::get_ArgumentOutOfRange_Index());
  }
  if (count < 0 || startIndex > length - count) {
    rt::throw_exception<ArgumentOutOfRangeException>("count", SR::get_ArgumentOutOfRange_Index());
  }
  if (oldValue == nullptr) {
    rt::throw_exception<ArgumentNullException>("oldValue");
  }
  if (oldValue->get_Length() == 0) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_EmptyName(), "oldValue");
  }
  if (newValue == nullptr) {
    newValue = String::in::Empty;
  }
  Array<Int32> array = nullptr;
  Int32 num = 0;
  StringBuilder stringBuilder = FindChunkForIndex(startIndex);
  Int32 num2 = startIndex - stringBuilder->m_ChunkOffset;
  while (count > 0) {
    if (StartsWith(stringBuilder, num2, count, oldValue)) {
      if (array == nullptr) {
        array = rt::newarr<Array<Int32>>(5);
      } else if (num >= array->get_Length()) {
        Array<>::in::Resize(array, array->get_Length() * 3 / 2 + 4);
      }

      array[num++] = num2;
      num2 += oldValue->get_Length();
      count -= oldValue->get_Length();
    } else {
      num2++;
      count--;
    }
    if (num2 >= stringBuilder->m_ChunkLength || count == 0) {
      Int32 num3 = num2 + stringBuilder->m_ChunkOffset;
      ReplaceAllInChunk(array, num, stringBuilder, oldValue->get_Length(), newValue);
      num3 += (newValue->get_Length() - oldValue->get_Length()) * num;
      num = 0;
      stringBuilder = FindChunkForIndex(num3);
      num2 = num3 - stringBuilder->m_ChunkOffset;
    }
  }
  return (StringBuilder)this;
}

StringBuilder StringBuilder___::Replace(Char oldChar, Char newChar) {
  return Replace(oldChar, newChar, 0, get_Length());
}

StringBuilder StringBuilder___::Replace(Char oldChar, Char newChar, Int32 startIndex, Int32 count) {
  Int32 length = get_Length();
  if ((UInt32)startIndex > (UInt32)length) {
    rt::throw_exception<ArgumentOutOfRangeException>("startIndex", SR::get_ArgumentOutOfRange_Index());
  }
  if (count < 0 || startIndex > length - count) {
    rt::throw_exception<ArgumentOutOfRangeException>("count", SR::get_ArgumentOutOfRange_Index());
  }
  Int32 num = startIndex + count;
  StringBuilder stringBuilder = (StringBuilder)this;
  while (true) {
    Int32 num2 = num - stringBuilder->m_ChunkOffset;
    Int32 num3 = startIndex - stringBuilder->m_ChunkOffset;
    if (num2 >= 0) {
      Int32 i = Math::Max(num3, 0);
      for (Int32 num4 = Math::Min(stringBuilder->m_ChunkLength, num2); i < num4; i++) {
        if (stringBuilder->m_ChunkChars[i] == oldChar) {
          stringBuilder->m_ChunkChars[i] = newChar;
        }
      }
    }
    if (num3 >= 0) {
      break;
    }
    stringBuilder = stringBuilder->m_ChunkPrevious;
  }
  return (StringBuilder)this;
}

StringBuilder StringBuilder___::Append(Char* value, Int32 valueCount) {
  if (valueCount < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("valueCount", SR::get_ArgumentOutOfRange_NegativeCount());
  }
  Int32 num = get_Length() + valueCount;
  if (num > m_MaxCapacity || num < valueCount) {
    rt::throw_exception<ArgumentOutOfRangeException>("valueCount", SR::get_ArgumentOutOfRange_LengthGreaterThanCapacity());
  }
  Int32 num2 = valueCount + m_ChunkLength;
  if (num2 <= m_ChunkChars->get_Length()) {
    ThreadSafeCopy(value, m_ChunkChars, m_ChunkLength, valueCount);
    m_ChunkLength = num2;
  } else {
    Int32 num3 = m_ChunkChars->get_Length() - m_ChunkLength;
    if (num3 > 0) {
      ThreadSafeCopy(value, m_ChunkChars, m_ChunkLength, num3);
      m_ChunkLength = m_ChunkChars->get_Length();
    }
    Int32 num4 = valueCount - num3;
    ExpandByABlock(num4);
    ThreadSafeCopy(value + num3, m_ChunkChars, 0, num4);
    m_ChunkLength = num4;
  }
  return (StringBuilder)this;
}

void StringBuilder___::Insert(Int32 index, Char* value, Int32 valueCount) {
  if ((UInt32)index > (UInt32)get_Length()) {
    rt::throw_exception<ArgumentOutOfRangeException>("index", SR::get_ArgumentOutOfRange_Index());
  }
  if (valueCount > 0) {
    StringBuilder chunk;
    Int32 indexInChunk;
    MakeRoom(index, valueCount, chunk, indexInChunk, false);
    ReplaceInPlaceAtChunk(chunk, indexInChunk, value, valueCount);
  }
}

void StringBuilder___::ReplaceAllInChunk(Array<Int32> replacements, Int32 replacementsCount, StringBuilder sourceChunk, Int32 removeCount, String value) {
  if (replacementsCount <= 0) {
    return;
  }
  {
    Char* ptr = rt::fixed(value);
    Char* value2 = ptr;
    Int64 num = (Int64)(value->get_Length() - removeCount) * (Int64)replacementsCount;
    Int32 num2 = (Int32)num;
    if (num2 != num) {
      rt::throw_exception<OutOfMemoryException>();
    }
    StringBuilder chunk = sourceChunk;
    Int32 indexInChunk = replacements[0];
    if (num2 > 0) {
      MakeRoom(chunk->m_ChunkOffset + indexInChunk, num2, chunk, indexInChunk, true);
    }
    Int32 num3 = 0;
    while (true) {
      ReplaceInPlaceAtChunk(chunk, indexInChunk, value2, value->get_Length());
      Int32 num4 = replacements[num3] + removeCount;
      num3++;
      if (num3 >= replacementsCount) {
        break;
      }
      Int32 num5 = replacements[num3];
      if (num2 != 0) {
        {
          Char* value3 = rt::fixed(&sourceChunk->m_ChunkChars[num4]);
          ReplaceInPlaceAtChunk(chunk, indexInChunk, value3, num5 - num4);
        }
      } else {
        indexInChunk += num5 - num4;
      }
    }
    if (num2 < 0) {
      Remove(chunk->m_ChunkOffset + indexInChunk, -num2, chunk, indexInChunk);
    }
  }
}

Boolean StringBuilder___::StartsWith(StringBuilder chunk, Int32 indexInChunk, Int32 count, String value) {
  for (Int32 i = 0; i < value->get_Length(); i++) {
    if (count == 0) {
      return false;
    }
    if (indexInChunk >= chunk->m_ChunkLength) {
      chunk = Next(chunk);
      if (chunk == nullptr) {
        return false;
      }
      indexInChunk = 0;
    }
    if (value[i] != chunk->m_ChunkChars[indexInChunk]) {
      return false;
    }
    indexInChunk++;
    count--;
  }
  return true;
}

void StringBuilder___::ReplaceInPlaceAtChunk(StringBuilder& chunk, Int32& indexInChunk, Char* value, Int32 count) {
  if (count == 0) {
    return;
  }
  while (true) {
    Int32 val = chunk->m_ChunkLength - indexInChunk;
    Int32 num = Math::Min(val, count);
    ThreadSafeCopy(value, chunk->m_ChunkChars, indexInChunk, num);
    indexInChunk += num;
    if (indexInChunk >= chunk->m_ChunkLength) {
      chunk = Next(chunk);
      indexInChunk = 0;
    }
    count -= num;
    if (count != 0) {
      value += num;
      continue;
    }
    break;
  }
}

void StringBuilder___::ThreadSafeCopy(Char* sourcePtr, Array<Char> destination, Int32 destinationIndex, Int32 count) {
  if (count > 0) {
    if ((UInt32)destinationIndex > (UInt32)destination->get_Length() || destinationIndex + count > destination->get_Length()) {
      rt::throw_exception<ArgumentOutOfRangeException>("destinationIndex", SR::get_ArgumentOutOfRange_Index());
    }
    {
      Char* dmem = rt::fixed(&destination[destinationIndex]);
      String::in::wstrcpy(dmem, sourcePtr, count);
    }
  }
}

void StringBuilder___::ThreadSafeCopy(Array<Char> source, Int32 sourceIndex, Span<Char> destination, Int32 destinationIndex, Int32 count) {
  if (count <= 0) {
    return;
  }
  if ((UInt32)sourceIndex > (UInt32)source->get_Length() || count > source->get_Length() - sourceIndex) {
    rt::throw_exception<ArgumentOutOfRangeException>("sourceIndex", SR::get_ArgumentOutOfRange_Index());
  }
  if ((UInt32)destinationIndex > (UInt32)destination.get_Length() || count > destination.get_Length() - destinationIndex) {
    rt::throw_exception<ArgumentOutOfRangeException>("destinationIndex", SR::get_ArgumentOutOfRange_Index());
  }
  {
    Char* smem = rt::fixed(&source[sourceIndex]);
    {
      Char* ptr = rt::fixed(&MemoryMarshal::GetReference(destination));
      String::in::wstrcpy(ptr + destinationIndex, smem, count);
    }
  }
}

StringBuilder StringBuilder___::FindChunkForIndex(Int32 index) {
  StringBuilder stringBuilder = (StringBuilder)this;
  while (stringBuilder->m_ChunkOffset > index) {
    stringBuilder = stringBuilder->m_ChunkPrevious;
  }
  return stringBuilder;
}

StringBuilder StringBuilder___::Next(StringBuilder chunk) {
  if (chunk != (StringBuilder)this) {
    return FindChunkForIndex(chunk->m_ChunkOffset + chunk->m_ChunkLength);
  }
  return nullptr;
}

void StringBuilder___::ExpandByABlock(Int32 minBlockCharCount) {
  if (minBlockCharCount + get_Length() > m_MaxCapacity || minBlockCharCount + get_Length() < minBlockCharCount) {
    rt::throw_exception<ArgumentOutOfRangeException>("requiredLength", SR::get_ArgumentOutOfRange_SmallCapacity());
  }
  Int32 num = Math::Max(minBlockCharCount, Math::Min(get_Length(), 8000));
  if (m_ChunkOffset + m_ChunkLength + num < num) {
    rt::throw_exception<OutOfMemoryException>();
  }
  Array<Char> chunkChars = GC::AllocateUninitializedArray<Char>(num);
  m_ChunkPrevious = rt::newobj<StringBuilder>((StringBuilder)this);
  m_ChunkOffset += m_ChunkLength;
  m_ChunkLength = 0;
  m_ChunkChars = chunkChars;
}

void StringBuilder___::ctor(StringBuilder from) {
  m_ChunkLength = from->m_ChunkLength;
  m_ChunkOffset = from->m_ChunkOffset;
  m_ChunkChars = from->m_ChunkChars;
  m_ChunkPrevious = from->m_ChunkPrevious;
  m_MaxCapacity = from->m_MaxCapacity;
}

void StringBuilder___::MakeRoom(Int32 index, Int32 count, StringBuilder& chunk, Int32& indexInChunk, Boolean doNotMoveFollowingChars) {
  if (count + get_Length() > m_MaxCapacity || count + get_Length() < count) {
    rt::throw_exception<ArgumentOutOfRangeException>("requiredLength", SR::get_ArgumentOutOfRange_SmallCapacity());
  }
  chunk = (StringBuilder)this;
  while (chunk->m_ChunkOffset > index) {
    chunk->m_ChunkOffset += count;
    chunk = chunk->m_ChunkPrevious;
  }
  indexInChunk = index - chunk->m_ChunkOffset;
  if (!doNotMoveFollowingChars && chunk->m_ChunkLength <= 32 && chunk->m_ChunkChars->get_Length() - chunk->m_ChunkLength >= count) {
    Int32 num = chunk->m_ChunkLength;
    while (num > indexInChunk) {
      num--;
      chunk->m_ChunkChars[num + count] = chunk->m_ChunkChars[num];
    }
    chunk->m_ChunkLength += count;
    return;
  }
  StringBuilder stringBuilder = rt::newobj<StringBuilder>(Math::Max(count, 16), chunk->m_MaxCapacity, chunk->m_ChunkPrevious);
  stringBuilder->m_ChunkLength = count;
  Int32 num2 = Math::Min(count, indexInChunk);
  if (num2 > 0) {
    {
      Char* ptr = rt::fixed(&chunk->m_ChunkChars[0]);
      ThreadSafeCopy(ptr, stringBuilder->m_ChunkChars, 0, num2);
      Int32 num3 = indexInChunk - num2;
      if (num3 >= 0) {
        ThreadSafeCopy(ptr + num2, chunk->m_ChunkChars, 0, num3);
        indexInChunk = num3;
      }
    }
  }
  chunk->m_ChunkPrevious = stringBuilder;
  chunk->m_ChunkOffset += count;
  if (num2 < count) {
    chunk = stringBuilder;
    indexInChunk = num2;
  }
}

void StringBuilder___::ctor(Int32 size, Int32 maxCapacity, StringBuilder previousBlock) {
  m_ChunkChars = GC::AllocateUninitializedArray<Char>(size);
  m_MaxCapacity = maxCapacity;
  m_ChunkPrevious = previousBlock;
  if (previousBlock != nullptr) {
    m_ChunkOffset = previousBlock->m_ChunkOffset + previousBlock->m_ChunkLength;
  }
}

void StringBuilder___::Remove(Int32 startIndex, Int32 count, StringBuilder& chunk, Int32& indexInChunk) {
  Int32 num = startIndex + count;
  chunk = (StringBuilder)this;
  StringBuilder stringBuilder = nullptr;
  Int32 num2 = 0;
  while (true) {
    if (num - chunk->m_ChunkOffset >= 0) {
      if (stringBuilder == nullptr) {
        stringBuilder = chunk;
        num2 = num - stringBuilder->m_ChunkOffset;
      }
      if (startIndex - chunk->m_ChunkOffset >= 0) {
        break;
      }
    } else {
      chunk->m_ChunkOffset -= count;
    }
    chunk = chunk->m_ChunkPrevious;
  }
  indexInChunk = startIndex - chunk->m_ChunkOffset;
  Int32 num3 = indexInChunk;
  Int32 count2 = stringBuilder->m_ChunkLength - num2;
  if (stringBuilder != chunk) {
    num3 = 0;
    chunk->m_ChunkLength = indexInChunk;
    stringBuilder->m_ChunkPrevious = chunk;
    stringBuilder->m_ChunkOffset = chunk->m_ChunkOffset + chunk->m_ChunkLength;
    if (indexInChunk == 0) {
      stringBuilder->m_ChunkPrevious = chunk->m_ChunkPrevious;
      chunk = stringBuilder;
    }
  }
  stringBuilder->m_ChunkLength -= num2 - num3;
  if (num3 != num2) {
    ThreadSafeCopy(stringBuilder->m_ChunkChars, num2, stringBuilder->m_ChunkChars, num3, count2);
  }
}

} // namespace System::Private::CoreLib::System::Text::StringBuilderNamespace
