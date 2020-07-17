#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Int32.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
FORWARDS(Byte)
FORWARDS(Char)
FORWARDS(Decimal)
FORWARDS(Double)
FORWARD(IFormatProvider)
FORWARDS(Int16)
FORWARDS(Int64)
FORWARDS(IntPtr)
FORWARD(Object)
FORWARDS(ParamsArray)
FORWARDS(ReadOnlyMemory, T)
FORWARDS(ReadOnlySpan, T)
FORWARDS(SByte)
FORWARDS(Single)
FORWARDS(Span, T)
FORWARD(String)
FORWARDS(UInt16)
FORWARDS(UInt32)
FORWARDS(UInt64)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System::Text {
namespace StringBuilderNamespace {
using namespace Runtime::Serialization;
CLASS(StringBuilder) {
  public: struct ChunkEnumerator {
    private: CLASS(ManyChunkInfo) {
      public: Boolean MoveNext(StringBuilder& current);
      public: void Ctor(StringBuilder stringBuilder, Int32 chunkCount);
      private: Array<StringBuilder> _chunks;
      private: Int32 _chunkPos;
    };
    public: ReadOnlyMemory<Char> get_Current();
    public: ChunkEnumerator GetEnumerator();
    public: Boolean MoveNext();
    public: void Ctor(StringBuilder stringBuilder);
    private: static Int32 ChunkCount(StringBuilder stringBuilder);
    public: void Ctor();
    private: StringBuilder _firstChunk;
    private: StringBuilder _currentChunk;
    private: ManyChunkInfo _manyChunks;
  };
  public: Int32 get_Capacity();
  public: void set_Capacity(Int32 value);
  public: Int32 get_MaxCapacity();
  public: Int32 get_Length();
  public: void set_Length(Int32 value);
  public: Char get_Chars(Int32 index);
  public: void set_Chars(Int32 index, Char value);
  private: Span<Char> get_RemainingCurrentChunk();
  private: Int32 GetReplaceBufferCapacity(Int32 requiredCapacity);
  public: void ReplaceBufferInternal(Char* newBuffer, Int32 newLength);
  public: void ReplaceBufferUtf8Internal(ReadOnlySpan<Byte> source);
  public: void ReplaceBufferAnsiInternal(SByte* newBuffer, Int32 newLength);
  public: void InternalCopy(IntPtr dest, Int32 len);
  private: StringBuilder FindChunkForByte(Int32 byteIndex);
  public: void Ctor();
  public: void Ctor(Int32 capacity);
  public: void Ctor(String value);
  public: void Ctor(String value, Int32 capacity);
  public: void Ctor(String value, Int32 startIndex, Int32 length, Int32 capacity);
  public: void Ctor(Int32 capacity, Int32 maxCapacity);
  private: void Ctor(SerializationInfo info, StreamingContext context);
  public: Int32 EnsureCapacity(Int32 capacity);
  public: String ToString();
  public: String ToString(Int32 startIndex, Int32 length);
  public: StringBuilder Clear();
  public: ChunkEnumerator GetChunks();
  public: StringBuilder Append(Char value, Int32 repeatCount);
  public: StringBuilder Append(Array<Char> value, Int32 startIndex, Int32 charCount);
  public: StringBuilder Append(String value);
  private: void AppendHelper(String value);
  public: StringBuilder Append(String value, Int32 startIndex, Int32 count);
  public: StringBuilder Append(StringBuilder value);
  public: StringBuilder Append(StringBuilder value, Int32 startIndex, Int32 count);
  private: StringBuilder AppendCore(StringBuilder value, Int32 startIndex, Int32 count);
  public: StringBuilder AppendLine();
  public: StringBuilder AppendLine(String value);
  public: void CopyTo(Int32 sourceIndex, Array<Char> destination, Int32 destinationIndex, Int32 count);
  public: void CopyTo(Int32 sourceIndex, Span<Char> destination, Int32 count);
  public: StringBuilder Insert(Int32 index, String value, Int32 count);
  public: StringBuilder Remove(Int32 startIndex, Int32 length);
  public: StringBuilder Append(Boolean value);
  public: StringBuilder Append(Char value);
  public: StringBuilder Append(SByte value);
  public: StringBuilder Append(Byte value);
  public: StringBuilder Append(Int16 value);
  public: StringBuilder Append(Int32 value);
  public: StringBuilder Append(Int64 value);
  public: StringBuilder Append(Single value);
  public: StringBuilder Append(Double value);
  public: StringBuilder Append(Decimal value);
  public: StringBuilder Append(UInt16 value);
  public: StringBuilder Append(UInt32 value);
  public: StringBuilder Append(UInt64 value);
  public: StringBuilder Append(Object value);
  public: StringBuilder Append(Array<Char> value);
  public: StringBuilder Append(ReadOnlySpan<Char> value);
  public: StringBuilder Append(ReadOnlyMemory<Char> value);
  public: StringBuilder AppendJoin(String separator, Array<Object> values);
  public: StringBuilder AppendJoin(String separator, Array<String> values);
  public: StringBuilder AppendJoin(Char separator, Array<Object> values);
  public: StringBuilder AppendJoin(Char separator, Array<String> values);
  public: StringBuilder Insert(Int32 index, String value);
  public: StringBuilder Insert(Int32 index, Boolean value);
  public: StringBuilder Insert(Int32 index, SByte value);
  public: StringBuilder Insert(Int32 index, Byte value);
  public: StringBuilder Insert(Int32 index, Int16 value);
  public: StringBuilder Insert(Int32 index, Char value);
  public: StringBuilder Insert(Int32 index, Array<Char> value);
  public: StringBuilder Insert(Int32 index, Array<Char> value, Int32 startIndex, Int32 charCount);
  public: StringBuilder Insert(Int32 index, Int32 value);
  public: StringBuilder Insert(Int32 index, Int64 value);
  public: StringBuilder Insert(Int32 index, Single value);
  public: StringBuilder Insert(Int32 index, Double value);
  public: StringBuilder Insert(Int32 index, Decimal value);
  public: StringBuilder Insert(Int32 index, UInt16 value);
  public: StringBuilder Insert(Int32 index, UInt32 value);
  public: StringBuilder Insert(Int32 index, UInt64 value);
  public: StringBuilder Insert(Int32 index, Object value);
  public: StringBuilder Insert(Int32 index, ReadOnlySpan<Char> value);
  public: StringBuilder AppendFormat(String format, Object arg0);
  public: StringBuilder AppendFormat(String format, Object arg0, Object arg1);
  public: StringBuilder AppendFormat(String format, Object arg0, Object arg1, Object arg2);
  public: StringBuilder AppendFormat(String format, Array<Object> args);
  public: StringBuilder AppendFormat(IFormatProvider provider, String format, Object arg0);
  public: StringBuilder AppendFormat(IFormatProvider provider, String format, Object arg0, Object arg1);
  public: StringBuilder AppendFormat(IFormatProvider provider, String format, Object arg0, Object arg1, Object arg2);
  public: StringBuilder AppendFormat(IFormatProvider provider, String format, Array<Object> args);
  private: static void FormatError();
  public: StringBuilder AppendFormatHelper(IFormatProvider provider, String format, ParamsArray args);
  public: StringBuilder Replace(String oldValue, String newValue);
  public: Boolean Equals(StringBuilder sb);
  public: Boolean Equals(ReadOnlySpan<Char> span);
  public: StringBuilder Replace(String oldValue, String newValue, Int32 startIndex, Int32 count);
  public: StringBuilder Replace(Char oldChar, Char newChar);
  public: StringBuilder Replace(Char oldChar, Char newChar, Int32 startIndex, Int32 count);
  public: StringBuilder Append(Char* value, Int32 valueCount);
  private: void Insert(Int32 index, Char* value, Int32 valueCount);
  private: void ReplaceAllInChunk(Array<Int32> replacements, Int32 replacementsCount, StringBuilder sourceChunk, Int32 removeCount, String value);
  private: Boolean StartsWith(StringBuilder chunk, Int32 indexInChunk, Int32 count, String value);
  private: void ReplaceInPlaceAtChunk(StringBuilder& chunk, Int32& indexInChunk, Char* value, Int32 count);
  private: static void ThreadSafeCopy(Char* sourcePtr, Array<Char> destination, Int32 destinationIndex, Int32 count);
  private: static void ThreadSafeCopy(Array<Char> source, Int32 sourceIndex, Span<Char> destination, Int32 destinationIndex, Int32 count);
  private: StringBuilder FindChunkForIndex(Int32 index);
  private: StringBuilder Next(StringBuilder chunk);
  private: void ExpandByABlock(Int32 minBlockCharCount);
  private: void Ctor(StringBuilder from);
  private: void MakeRoom(Int32 index, Int32 count, StringBuilder& chunk, Int32& indexInChunk, Boolean doNotMoveFollowingChars);
  private: void Ctor(Int32 size, Int32 maxCapacity, StringBuilder previousBlock);
  private: void Remove(Int32 startIndex, Int32 count, StringBuilder& chunk, Int32& indexInChunk);
  public: Array<Char> m_ChunkChars;
  public: StringBuilder m_ChunkPrevious;
  public: Int32 m_ChunkLength;
  public: Int32 m_ChunkOffset;
  public: Int32 m_MaxCapacity;
};
} // namespace StringBuilderNamespace
using StringBuilder = StringBuilderNamespace::StringBuilder;
} // namespace System::Private::CoreLib::System::Text
