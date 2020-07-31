#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(Byte)
FORWARDS(Double)
FORWARDS(Int16)
FORWARDS(Int32)
FORWARDS(Int64)
FORWARDS(ReadOnlySpan, T)
FORWARDS(SByte)
FORWARDS(Single)
FORWARDS(Span, T)
FORWARDS(UInt16)
FORWARDS(UInt32)
FORWARDS(UInt64)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Buffers::Binary {
namespace BinaryPrimitivesNamespace {
class BinaryPrimitives : public Object::in {
  public: static SByte ReverseEndianness(SByte value);
  public: static Int16 ReverseEndianness(Int16 value);
  public: static Int32 ReverseEndianness(Int32 value);
  public: static Int64 ReverseEndianness(Int64 value);
  public: static Byte ReverseEndianness(Byte value);
  public: static UInt16 ReverseEndianness(UInt16 value);
  public: static UInt32 ReverseEndianness(UInt32 value);
  public: static UInt64 ReverseEndianness(UInt64 value);
  public: static Double ReadDoubleBigEndian(ReadOnlySpan<Byte> source);
  public: static Int16 ReadInt16BigEndian(ReadOnlySpan<Byte> source);
  public: static Int32 ReadInt32BigEndian(ReadOnlySpan<Byte> source);
  public: static Int64 ReadInt64BigEndian(ReadOnlySpan<Byte> source);
  public: static Single ReadSingleBigEndian(ReadOnlySpan<Byte> source);
  public: static UInt16 ReadUInt16BigEndian(ReadOnlySpan<Byte> source);
  public: static UInt32 ReadUInt32BigEndian(ReadOnlySpan<Byte> source);
  public: static UInt64 ReadUInt64BigEndian(ReadOnlySpan<Byte> source);
  public: static Boolean TryReadDoubleBigEndian(ReadOnlySpan<Byte> source, Double& value);
  public: static Boolean TryReadInt16BigEndian(ReadOnlySpan<Byte> source, Int16& value);
  public: static Boolean TryReadInt32BigEndian(ReadOnlySpan<Byte> source, Int32& value);
  public: static Boolean TryReadInt64BigEndian(ReadOnlySpan<Byte> source, Int64& value);
  public: static Boolean TryReadSingleBigEndian(ReadOnlySpan<Byte> source, Single& value);
  public: static Boolean TryReadUInt16BigEndian(ReadOnlySpan<Byte> source, UInt16& value);
  public: static Boolean TryReadUInt32BigEndian(ReadOnlySpan<Byte> source, UInt32& value);
  public: static Boolean TryReadUInt64BigEndian(ReadOnlySpan<Byte> source, UInt64& value);
  public: static Double ReadDoubleLittleEndian(ReadOnlySpan<Byte> source);
  public: static Int16 ReadInt16LittleEndian(ReadOnlySpan<Byte> source);
  public: static Int32 ReadInt32LittleEndian(ReadOnlySpan<Byte> source);
  public: static Int64 ReadInt64LittleEndian(ReadOnlySpan<Byte> source);
  public: static Single ReadSingleLittleEndian(ReadOnlySpan<Byte> source);
  public: static UInt16 ReadUInt16LittleEndian(ReadOnlySpan<Byte> source);
  public: static UInt32 ReadUInt32LittleEndian(ReadOnlySpan<Byte> source);
  public: static UInt64 ReadUInt64LittleEndian(ReadOnlySpan<Byte> source);
  public: static Boolean TryReadDoubleLittleEndian(ReadOnlySpan<Byte> source, Double& value);
  public: static Boolean TryReadInt16LittleEndian(ReadOnlySpan<Byte> source, Int16& value);
  public: static Boolean TryReadInt32LittleEndian(ReadOnlySpan<Byte> source, Int32& value);
  public: static Boolean TryReadInt64LittleEndian(ReadOnlySpan<Byte> source, Int64& value);
  public: static Boolean TryReadSingleLittleEndian(ReadOnlySpan<Byte> source, Single& value);
  public: static Boolean TryReadUInt16LittleEndian(ReadOnlySpan<Byte> source, UInt16& value);
  public: static Boolean TryReadUInt32LittleEndian(ReadOnlySpan<Byte> source, UInt32& value);
  public: static Boolean TryReadUInt64LittleEndian(ReadOnlySpan<Byte> source, UInt64& value);
  public: static void WriteDoubleBigEndian(Span<Byte> destination, Double value);
  public: static void WriteInt16BigEndian(Span<Byte> destination, Int16 value);
  public: static void WriteInt32BigEndian(Span<Byte> destination, Int32 value);
  public: static void WriteInt64BigEndian(Span<Byte> destination, Int64 value);
  public: static void WriteSingleBigEndian(Span<Byte> destination, Single value);
  public: static void WriteUInt16BigEndian(Span<Byte> destination, UInt16 value);
  public: static void WriteUInt32BigEndian(Span<Byte> destination, UInt32 value);
  public: static void WriteUInt64BigEndian(Span<Byte> destination, UInt64 value);
  public: static Boolean TryWriteDoubleBigEndian(Span<Byte> destination, Double value);
  public: static Boolean TryWriteInt16BigEndian(Span<Byte> destination, Int16 value);
  public: static Boolean TryWriteInt32BigEndian(Span<Byte> destination, Int32 value);
  public: static Boolean TryWriteInt64BigEndian(Span<Byte> destination, Int64 value);
  public: static Boolean TryWriteSingleBigEndian(Span<Byte> destination, Single value);
  public: static Boolean TryWriteUInt16BigEndian(Span<Byte> destination, UInt16 value);
  public: static Boolean TryWriteUInt32BigEndian(Span<Byte> destination, UInt32 value);
  public: static Boolean TryWriteUInt64BigEndian(Span<Byte> destination, UInt64 value);
  public: static void WriteDoubleLittleEndian(Span<Byte> destination, Double value);
  public: static void WriteInt16LittleEndian(Span<Byte> destination, Int16 value);
  public: static void WriteInt32LittleEndian(Span<Byte> destination, Int32 value);
  public: static void WriteInt64LittleEndian(Span<Byte> destination, Int64 value);
  public: static void WriteSingleLittleEndian(Span<Byte> destination, Single value);
  public: static void WriteUInt16LittleEndian(Span<Byte> destination, UInt16 value);
  public: static void WriteUInt32LittleEndian(Span<Byte> destination, UInt32 value);
  public: static void WriteUInt64LittleEndian(Span<Byte> destination, UInt64 value);
  public: static Boolean TryWriteDoubleLittleEndian(Span<Byte> destination, Double value);
  public: static Boolean TryWriteInt16LittleEndian(Span<Byte> destination, Int16 value);
  public: static Boolean TryWriteInt32LittleEndian(Span<Byte> destination, Int32 value);
  public: static Boolean TryWriteInt64LittleEndian(Span<Byte> destination, Int64 value);
  public: static Boolean TryWriteSingleLittleEndian(Span<Byte> destination, Single value);
  public: static Boolean TryWriteUInt16LittleEndian(Span<Byte> destination, UInt16 value);
  public: static Boolean TryWriteUInt32LittleEndian(Span<Byte> destination, UInt32 value);
  public: static Boolean TryWriteUInt64LittleEndian(Span<Byte> destination, UInt64 value);
};
} // namespace BinaryPrimitivesNamespace
using BinaryPrimitives = BinaryPrimitivesNamespace::BinaryPrimitives;
} // namespace System::Private::CoreLib::System::Buffers::Binary
