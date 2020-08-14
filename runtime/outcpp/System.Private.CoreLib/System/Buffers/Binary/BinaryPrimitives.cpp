#include "BinaryPrimitives-dep.h"

#include <System.Private.CoreLib/System/BitConverter-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/MemoryMarshal-dep.h>
#include <System.Private.CoreLib/System/UInt16-dep.h>
#include <System.Private.CoreLib/System/UInt32-dep.h>
#include <System.Private.CoreLib/System/UInt64-dep.h>

namespace System::Private::CoreLib::System::Buffers::Binary::BinaryPrimitivesNamespace {
using namespace System::Runtime::InteropServices;

SByte BinaryPrimitives::ReverseEndianness(SByte value) {
  return value;
}

Int16 BinaryPrimitives::ReverseEndianness(Int16 value) {
  return (Int16)ReverseEndianness((UInt16)value);
}

Int32 BinaryPrimitives::ReverseEndianness(Int32 value) {
  return (Int32)ReverseEndianness((UInt32)value);
}

Int64 BinaryPrimitives::ReverseEndianness(Int64 value) {
  return (Int64)ReverseEndianness((UInt64)value);
}

Byte BinaryPrimitives::ReverseEndianness(Byte value) {
  return value;
}

UInt16 BinaryPrimitives::ReverseEndianness(UInt16 value) {
  return (UInt16)((value >> 8) + (value << 8));
}

UInt32 BinaryPrimitives::ReverseEndianness(UInt32 value) {
}

UInt64 BinaryPrimitives::ReverseEndianness(UInt64 value) {
  return ((UInt64)ReverseEndianness((UInt32)value) << 32) + ReverseEndianness((UInt32)(value >> 32));
}

Double BinaryPrimitives::ReadDoubleBigEndian(ReadOnlySpan<Byte> source) {
  if (!BitConverter::IsLittleEndian) {
    return MemoryMarshal::Read<Double>(source);
  }
  return BitConverter::Int64BitsToDouble(ReverseEndianness(MemoryMarshal::Read<Int64>(source)));
}

Int16 BinaryPrimitives::ReadInt16BigEndian(ReadOnlySpan<Byte> source) {
  Int16 num = MemoryMarshal::Read<Int16>(source);
  if (BitConverter::IsLittleEndian) {
    num = ReverseEndianness(num);
  }
  return num;
}

Int32 BinaryPrimitives::ReadInt32BigEndian(ReadOnlySpan<Byte> source) {
  Int32 num = MemoryMarshal::Read<Int32>(source);
  if (BitConverter::IsLittleEndian) {
    num = ReverseEndianness(num);
  }
  return num;
}

Int64 BinaryPrimitives::ReadInt64BigEndian(ReadOnlySpan<Byte> source) {
  Int64 num = MemoryMarshal::Read<Int64>(source);
  if (BitConverter::IsLittleEndian) {
    num = ReverseEndianness(num);
  }
  return num;
}

Single BinaryPrimitives::ReadSingleBigEndian(ReadOnlySpan<Byte> source) {
  if (!BitConverter::IsLittleEndian) {
    return MemoryMarshal::Read<Single>(source);
  }
  return BitConverter::Int32BitsToSingle(ReverseEndianness(MemoryMarshal::Read<Int32>(source)));
}

UInt16 BinaryPrimitives::ReadUInt16BigEndian(ReadOnlySpan<Byte> source) {
  UInt16 num = MemoryMarshal::Read<UInt16>(source);
  if (BitConverter::IsLittleEndian) {
    num = ReverseEndianness(num);
  }
  return num;
}

UInt32 BinaryPrimitives::ReadUInt32BigEndian(ReadOnlySpan<Byte> source) {
  UInt32 num = MemoryMarshal::Read<UInt32>(source);
  if (BitConverter::IsLittleEndian) {
    num = ReverseEndianness(num);
  }
  return num;
}

UInt64 BinaryPrimitives::ReadUInt64BigEndian(ReadOnlySpan<Byte> source) {
  UInt64 num = MemoryMarshal::Read<UInt64>(source);
  if (BitConverter::IsLittleEndian) {
    num = ReverseEndianness(num);
  }
  return num;
}

Boolean BinaryPrimitives::TryReadDoubleBigEndian(ReadOnlySpan<Byte> source, Double& value) {
  if (BitConverter::IsLittleEndian) {
    Int64 value2;
    Boolean result = MemoryMarshal::TryRead(source, value2);
    value = BitConverter::Int64BitsToDouble(ReverseEndianness(value2));
    return result;
  }
  return MemoryMarshal::TryRead(source, value);
}

Boolean BinaryPrimitives::TryReadInt16BigEndian(ReadOnlySpan<Byte> source, Int16& value) {
  if (BitConverter::IsLittleEndian) {
    Int16 value2;
    Boolean result = MemoryMarshal::TryRead(source, value2);
    value = ReverseEndianness(value2);
    return result;
  }
  return MemoryMarshal::TryRead(source, value);
}

Boolean BinaryPrimitives::TryReadInt32BigEndian(ReadOnlySpan<Byte> source, Int32& value) {
  if (BitConverter::IsLittleEndian) {
    Int32 value2;
    Boolean result = MemoryMarshal::TryRead(source, value2);
    value = ReverseEndianness(value2);
    return result;
  }
  return MemoryMarshal::TryRead(source, value);
}

Boolean BinaryPrimitives::TryReadInt64BigEndian(ReadOnlySpan<Byte> source, Int64& value) {
  if (BitConverter::IsLittleEndian) {
    Int64 value2;
    Boolean result = MemoryMarshal::TryRead(source, value2);
    value = ReverseEndianness(value2);
    return result;
  }
  return MemoryMarshal::TryRead(source, value);
}

Boolean BinaryPrimitives::TryReadSingleBigEndian(ReadOnlySpan<Byte> source, Single& value) {
  if (BitConverter::IsLittleEndian) {
    Int32 value2;
    Boolean result = MemoryMarshal::TryRead(source, value2);
    value = BitConverter::Int32BitsToSingle(ReverseEndianness(value2));
    return result;
  }
  return MemoryMarshal::TryRead(source, value);
}

Boolean BinaryPrimitives::TryReadUInt16BigEndian(ReadOnlySpan<Byte> source, UInt16& value) {
  if (BitConverter::IsLittleEndian) {
    UInt16 value2;
    Boolean result = MemoryMarshal::TryRead(source, value2);
    value = ReverseEndianness(value2);
    return result;
  }
  return MemoryMarshal::TryRead(source, value);
}

Boolean BinaryPrimitives::TryReadUInt32BigEndian(ReadOnlySpan<Byte> source, UInt32& value) {
  if (BitConverter::IsLittleEndian) {
    UInt32 value2;
    Boolean result = MemoryMarshal::TryRead(source, value2);
    value = ReverseEndianness(value2);
    return result;
  }
  return MemoryMarshal::TryRead(source, value);
}

Boolean BinaryPrimitives::TryReadUInt64BigEndian(ReadOnlySpan<Byte> source, UInt64& value) {
  if (BitConverter::IsLittleEndian) {
    UInt64 value2;
    Boolean result = MemoryMarshal::TryRead(source, value2);
    value = ReverseEndianness(value2);
    return result;
  }
  return MemoryMarshal::TryRead(source, value);
}

Double BinaryPrimitives::ReadDoubleLittleEndian(ReadOnlySpan<Byte> source) {
  if (BitConverter::IsLittleEndian) {
    return MemoryMarshal::Read<Double>(source);
  }
  return BitConverter::Int64BitsToDouble(ReverseEndianness(MemoryMarshal::Read<Int64>(source)));
}

Int16 BinaryPrimitives::ReadInt16LittleEndian(ReadOnlySpan<Byte> source) {
  Int16 num = MemoryMarshal::Read<Int16>(source);
  if (!BitConverter::IsLittleEndian) {
    num = ReverseEndianness(num);
  }
  return num;
}

Int32 BinaryPrimitives::ReadInt32LittleEndian(ReadOnlySpan<Byte> source) {
  Int32 num = MemoryMarshal::Read<Int32>(source);
  if (!BitConverter::IsLittleEndian) {
    num = ReverseEndianness(num);
  }
  return num;
}

Int64 BinaryPrimitives::ReadInt64LittleEndian(ReadOnlySpan<Byte> source) {
  Int64 num = MemoryMarshal::Read<Int64>(source);
  if (!BitConverter::IsLittleEndian) {
    num = ReverseEndianness(num);
  }
  return num;
}

Single BinaryPrimitives::ReadSingleLittleEndian(ReadOnlySpan<Byte> source) {
  if (BitConverter::IsLittleEndian) {
    return MemoryMarshal::Read<Single>(source);
  }
  return BitConverter::Int32BitsToSingle(ReverseEndianness(MemoryMarshal::Read<Int32>(source)));
}

UInt16 BinaryPrimitives::ReadUInt16LittleEndian(ReadOnlySpan<Byte> source) {
  UInt16 num = MemoryMarshal::Read<UInt16>(source);
  if (!BitConverter::IsLittleEndian) {
    num = ReverseEndianness(num);
  }
  return num;
}

UInt32 BinaryPrimitives::ReadUInt32LittleEndian(ReadOnlySpan<Byte> source) {
  UInt32 num = MemoryMarshal::Read<UInt32>(source);
  if (!BitConverter::IsLittleEndian) {
    num = ReverseEndianness(num);
  }
  return num;
}

UInt64 BinaryPrimitives::ReadUInt64LittleEndian(ReadOnlySpan<Byte> source) {
  UInt64 num = MemoryMarshal::Read<UInt64>(source);
  if (!BitConverter::IsLittleEndian) {
    num = ReverseEndianness(num);
  }
  return num;
}

Boolean BinaryPrimitives::TryReadDoubleLittleEndian(ReadOnlySpan<Byte> source, Double& value) {
  if (!BitConverter::IsLittleEndian) {
    Int64 value2;
    Boolean result = MemoryMarshal::TryRead(source, value2);
    value = BitConverter::Int64BitsToDouble(ReverseEndianness(value2));
    return result;
  }
  return MemoryMarshal::TryRead(source, value);
}

Boolean BinaryPrimitives::TryReadInt16LittleEndian(ReadOnlySpan<Byte> source, Int16& value) {
  if (BitConverter::IsLittleEndian) {
    return MemoryMarshal::TryRead(source, value);
  }
  Int16 value2;
  Boolean result = MemoryMarshal::TryRead(source, value2);
  value = ReverseEndianness(value2);
  return result;
}

Boolean BinaryPrimitives::TryReadInt32LittleEndian(ReadOnlySpan<Byte> source, Int32& value) {
  if (BitConverter::IsLittleEndian) {
    return MemoryMarshal::TryRead(source, value);
  }
  Int32 value2;
  Boolean result = MemoryMarshal::TryRead(source, value2);
  value = ReverseEndianness(value2);
  return result;
}

Boolean BinaryPrimitives::TryReadInt64LittleEndian(ReadOnlySpan<Byte> source, Int64& value) {
  if (BitConverter::IsLittleEndian) {
    return MemoryMarshal::TryRead(source, value);
  }
  Int64 value2;
  Boolean result = MemoryMarshal::TryRead(source, value2);
  value = ReverseEndianness(value2);
  return result;
}

Boolean BinaryPrimitives::TryReadSingleLittleEndian(ReadOnlySpan<Byte> source, Single& value) {
  if (!BitConverter::IsLittleEndian) {
    Int32 value2;
    Boolean result = MemoryMarshal::TryRead(source, value2);
    value = BitConverter::Int32BitsToSingle(ReverseEndianness(value2));
    return result;
  }
  return MemoryMarshal::TryRead(source, value);
}

Boolean BinaryPrimitives::TryReadUInt16LittleEndian(ReadOnlySpan<Byte> source, UInt16& value) {
  if (BitConverter::IsLittleEndian) {
    return MemoryMarshal::TryRead(source, value);
  }
  UInt16 value2;
  Boolean result = MemoryMarshal::TryRead(source, value2);
  value = ReverseEndianness(value2);
  return result;
}

Boolean BinaryPrimitives::TryReadUInt32LittleEndian(ReadOnlySpan<Byte> source, UInt32& value) {
  if (BitConverter::IsLittleEndian) {
    return MemoryMarshal::TryRead(source, value);
  }
  UInt32 value2;
  Boolean result = MemoryMarshal::TryRead(source, value2);
  value = ReverseEndianness(value2);
  return result;
}

Boolean BinaryPrimitives::TryReadUInt64LittleEndian(ReadOnlySpan<Byte> source, UInt64& value) {
  if (BitConverter::IsLittleEndian) {
    return MemoryMarshal::TryRead(source, value);
  }
  UInt64 value2;
  Boolean result = MemoryMarshal::TryRead(source, value2);
  value = ReverseEndianness(value2);
  return result;
}

void BinaryPrimitives::WriteDoubleBigEndian(Span<Byte> destination, Double value) {
  if (BitConverter::IsLittleEndian) {
    Int64 value2 = ReverseEndianness(BitConverter::DoubleToInt64Bits(value));
    MemoryMarshal::Write(destination, value2);
  } else {
    MemoryMarshal::Write(destination, value);
  }
}

void BinaryPrimitives::WriteInt16BigEndian(Span<Byte> destination, Int16 value) {
  if (BitConverter::IsLittleEndian) {
    value = ReverseEndianness(value);
  }
  MemoryMarshal::Write(destination, value);
}

void BinaryPrimitives::WriteInt32BigEndian(Span<Byte> destination, Int32 value) {
  if (BitConverter::IsLittleEndian) {
    value = ReverseEndianness(value);
  }
  MemoryMarshal::Write(destination, value);
}

void BinaryPrimitives::WriteInt64BigEndian(Span<Byte> destination, Int64 value) {
  if (BitConverter::IsLittleEndian) {
    value = ReverseEndianness(value);
  }
  MemoryMarshal::Write(destination, value);
}

void BinaryPrimitives::WriteSingleBigEndian(Span<Byte> destination, Single value) {
  if (BitConverter::IsLittleEndian) {
    Int32 value2 = ReverseEndianness(BitConverter::SingleToInt32Bits(value));
    MemoryMarshal::Write(destination, value2);
  } else {
    MemoryMarshal::Write(destination, value);
  }
}

void BinaryPrimitives::WriteUInt16BigEndian(Span<Byte> destination, UInt16 value) {
  if (BitConverter::IsLittleEndian) {
    value = ReverseEndianness(value);
  }
  MemoryMarshal::Write(destination, value);
}

void BinaryPrimitives::WriteUInt32BigEndian(Span<Byte> destination, UInt32 value) {
  if (BitConverter::IsLittleEndian) {
    value = ReverseEndianness(value);
  }
  MemoryMarshal::Write(destination, value);
}

void BinaryPrimitives::WriteUInt64BigEndian(Span<Byte> destination, UInt64 value) {
  if (BitConverter::IsLittleEndian) {
    value = ReverseEndianness(value);
  }
  MemoryMarshal::Write(destination, value);
}

Boolean BinaryPrimitives::TryWriteDoubleBigEndian(Span<Byte> destination, Double value) {
  if (BitConverter::IsLittleEndian) {
    Int64 value2 = ReverseEndianness(BitConverter::DoubleToInt64Bits(value));
    return MemoryMarshal::TryWrite(destination, value2);
  }
  return MemoryMarshal::TryWrite(destination, value);
}

Boolean BinaryPrimitives::TryWriteInt16BigEndian(Span<Byte> destination, Int16 value) {
  if (BitConverter::IsLittleEndian) {
    value = ReverseEndianness(value);
  }
  return MemoryMarshal::TryWrite(destination, value);
}

Boolean BinaryPrimitives::TryWriteInt32BigEndian(Span<Byte> destination, Int32 value) {
  if (BitConverter::IsLittleEndian) {
    value = ReverseEndianness(value);
  }
  return MemoryMarshal::TryWrite(destination, value);
}

Boolean BinaryPrimitives::TryWriteInt64BigEndian(Span<Byte> destination, Int64 value) {
  if (BitConverter::IsLittleEndian) {
    value = ReverseEndianness(value);
  }
  return MemoryMarshal::TryWrite(destination, value);
}

Boolean BinaryPrimitives::TryWriteSingleBigEndian(Span<Byte> destination, Single value) {
  if (BitConverter::IsLittleEndian) {
    Int32 value2 = ReverseEndianness(BitConverter::SingleToInt32Bits(value));
    return MemoryMarshal::TryWrite(destination, value2);
  }
  return MemoryMarshal::TryWrite(destination, value);
}

Boolean BinaryPrimitives::TryWriteUInt16BigEndian(Span<Byte> destination, UInt16 value) {
  if (BitConverter::IsLittleEndian) {
    value = ReverseEndianness(value);
  }
  return MemoryMarshal::TryWrite(destination, value);
}

Boolean BinaryPrimitives::TryWriteUInt32BigEndian(Span<Byte> destination, UInt32 value) {
  if (BitConverter::IsLittleEndian) {
    value = ReverseEndianness(value);
  }
  return MemoryMarshal::TryWrite(destination, value);
}

Boolean BinaryPrimitives::TryWriteUInt64BigEndian(Span<Byte> destination, UInt64 value) {
  if (BitConverter::IsLittleEndian) {
    value = ReverseEndianness(value);
  }
  return MemoryMarshal::TryWrite(destination, value);
}

void BinaryPrimitives::WriteDoubleLittleEndian(Span<Byte> destination, Double value) {
  if (!BitConverter::IsLittleEndian) {
    Int64 value2 = ReverseEndianness(BitConverter::DoubleToInt64Bits(value));
    MemoryMarshal::Write(destination, value2);
  } else {
    MemoryMarshal::Write(destination, value);
  }
}

void BinaryPrimitives::WriteInt16LittleEndian(Span<Byte> destination, Int16 value) {
  if (!BitConverter::IsLittleEndian) {
    value = ReverseEndianness(value);
  }
  MemoryMarshal::Write(destination, value);
}

void BinaryPrimitives::WriteInt32LittleEndian(Span<Byte> destination, Int32 value) {
  if (!BitConverter::IsLittleEndian) {
    value = ReverseEndianness(value);
  }
  MemoryMarshal::Write(destination, value);
}

void BinaryPrimitives::WriteInt64LittleEndian(Span<Byte> destination, Int64 value) {
  if (!BitConverter::IsLittleEndian) {
    value = ReverseEndianness(value);
  }
  MemoryMarshal::Write(destination, value);
}

void BinaryPrimitives::WriteSingleLittleEndian(Span<Byte> destination, Single value) {
  if (!BitConverter::IsLittleEndian) {
    Int32 value2 = ReverseEndianness(BitConverter::SingleToInt32Bits(value));
    MemoryMarshal::Write(destination, value2);
  } else {
    MemoryMarshal::Write(destination, value);
  }
}

void BinaryPrimitives::WriteUInt16LittleEndian(Span<Byte> destination, UInt16 value) {
  if (!BitConverter::IsLittleEndian) {
    value = ReverseEndianness(value);
  }
  MemoryMarshal::Write(destination, value);
}

void BinaryPrimitives::WriteUInt32LittleEndian(Span<Byte> destination, UInt32 value) {
  if (!BitConverter::IsLittleEndian) {
    value = ReverseEndianness(value);
  }
  MemoryMarshal::Write(destination, value);
}

void BinaryPrimitives::WriteUInt64LittleEndian(Span<Byte> destination, UInt64 value) {
  if (!BitConverter::IsLittleEndian) {
    value = ReverseEndianness(value);
  }
  MemoryMarshal::Write(destination, value);
}

Boolean BinaryPrimitives::TryWriteDoubleLittleEndian(Span<Byte> destination, Double value) {
  if (!BitConverter::IsLittleEndian) {
    Int64 value2 = ReverseEndianness(BitConverter::DoubleToInt64Bits(value));
    return MemoryMarshal::TryWrite(destination, value2);
  }
  return MemoryMarshal::TryWrite(destination, value);
}

Boolean BinaryPrimitives::TryWriteInt16LittleEndian(Span<Byte> destination, Int16 value) {
  if (!BitConverter::IsLittleEndian) {
    value = ReverseEndianness(value);
  }
  return MemoryMarshal::TryWrite(destination, value);
}

Boolean BinaryPrimitives::TryWriteInt32LittleEndian(Span<Byte> destination, Int32 value) {
  if (!BitConverter::IsLittleEndian) {
    value = ReverseEndianness(value);
  }
  return MemoryMarshal::TryWrite(destination, value);
}

Boolean BinaryPrimitives::TryWriteInt64LittleEndian(Span<Byte> destination, Int64 value) {
  if (!BitConverter::IsLittleEndian) {
    value = ReverseEndianness(value);
  }
  return MemoryMarshal::TryWrite(destination, value);
}

Boolean BinaryPrimitives::TryWriteSingleLittleEndian(Span<Byte> destination, Single value) {
  if (!BitConverter::IsLittleEndian) {
    Int32 value2 = ReverseEndianness(BitConverter::SingleToInt32Bits(value));
    return MemoryMarshal::TryWrite(destination, value2);
  }
  return MemoryMarshal::TryWrite(destination, value);
}

Boolean BinaryPrimitives::TryWriteUInt16LittleEndian(Span<Byte> destination, UInt16 value) {
  if (!BitConverter::IsLittleEndian) {
    value = ReverseEndianness(value);
  }
  return MemoryMarshal::TryWrite(destination, value);
}

Boolean BinaryPrimitives::TryWriteUInt32LittleEndian(Span<Byte> destination, UInt32 value) {
  if (!BitConverter::IsLittleEndian) {
    value = ReverseEndianness(value);
  }
  return MemoryMarshal::TryWrite(destination, value);
}

Boolean BinaryPrimitives::TryWriteUInt64LittleEndian(Span<Byte> destination, UInt64 value) {
  if (!BitConverter::IsLittleEndian) {
    value = ReverseEndianness(value);
  }
  return MemoryMarshal::TryWrite(destination, value);
}

} // namespace System::Private::CoreLib::System::Buffers::Binary::BinaryPrimitivesNamespace
