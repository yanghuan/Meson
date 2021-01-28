#include "UnmanagedMemoryAccessor-dep.h"

#include <System.Private.CoreLib/Internal/Runtime/CompilerServices/Unsafe-dep.h>
#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/BitConverter-dep.h>
#include <System.Private.CoreLib/System/Byte-dep.h>
#include <System.Private.CoreLib/System/GC-dep.h>
#include <System.Private.CoreLib/System/InvalidOperationException-dep.h>
#include <System.Private.CoreLib/System/IO/FileAccess.h>
#include <System.Private.CoreLib/System/IO/UnmanagedMemoryAccessor-dep.h>
#include <System.Private.CoreLib/System/NotSupportedException-dep.h>
#include <System.Private.CoreLib/System/ObjectDisposedException-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/UInt32-dep.h>
#include <System.Private.CoreLib/System/UInt64-dep.h>
#include <System.Private.CoreLib/System/UIntPtr-dep.h>

namespace System::Private::CoreLib::System::IO::UnmanagedMemoryAccessorNamespace {
using namespace Internal::Runtime::CompilerServices;

Int64 UnmanagedMemoryAccessor___::get_Capacity() {
  return _capacity;
}

Boolean UnmanagedMemoryAccessor___::get_CanRead() {
  if (_isOpen) {
    return _canRead;
  }
  return false;
}

Boolean UnmanagedMemoryAccessor___::get_CanWrite() {
  if (_isOpen) {
    return _canWrite;
  }
  return false;
}

Boolean UnmanagedMemoryAccessor___::get_IsOpen() {
  return _isOpen;
}

void UnmanagedMemoryAccessor___::ctor() {
  _isOpen = false;
}

void UnmanagedMemoryAccessor___::ctor(SafeBuffer buffer, Int64 offset, Int64 capacity) {
  Initialize(buffer, offset, capacity, FileAccess::Read);
}

void UnmanagedMemoryAccessor___::ctor(SafeBuffer buffer, Int64 offset, Int64 capacity, FileAccess access) {
  Initialize(buffer, offset, capacity, access);
}

void UnmanagedMemoryAccessor___::Initialize(SafeBuffer buffer, Int64 offset, Int64 capacity, FileAccess access) {
  if (buffer == nullptr) {
    rt::throw_exception<ArgumentNullException>("buffer");
  }
  if (offset < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("offset", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  if (capacity < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("capacity", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  if (buffer->get_ByteLength() < (UInt64)(offset + capacity)) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_OffsetAndCapacityOutOfBounds());
  }
  if (access < FileAccess::Read || access > FileAccess::ReadWrite) {
    rt::throw_exception<ArgumentOutOfRangeException>("access");
  }
  if (_isOpen) {
    rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_CalledTwice());
  }
  Byte* pointer = nullptr;
  try {
    buffer->AcquirePointer(pointer);
    if ((UInt64)(UIntPtr)(void*)((Int64)pointer + offset + capacity) < (UInt64)pointer) {
      rt::throw_exception<ArgumentException>(SR::get_Argument_UnmanagedMemAccessorWrapAround());
    }
  } catch (...) {
  } finally: {
    if (pointer != nullptr) {
      buffer->ReleasePointer();
    }
  }
  _offset = offset;
  _buffer = buffer;
  _capacity = capacity;
  _access = access;
  _isOpen = true;
  _canRead = (_access & FileAccess::Read) != 0;
  _canWrite = (_access & FileAccess::Write) != 0;
}

void UnmanagedMemoryAccessor___::Dispose(Boolean disposing) {
  _isOpen = false;
}

void UnmanagedMemoryAccessor___::Dispose() {
  Dispose(true);
  GC::SuppressFinalize((UnmanagedMemoryAccessor)this);
}

Boolean UnmanagedMemoryAccessor___::ReadBoolean(Int64 position) {
  return ReadByte(position) != 0;
}

Byte UnmanagedMemoryAccessor___::ReadByte(Int64 position) {
  EnsureSafeToRead(position, 1);
  Byte* pointer = nullptr;
  try {
    _buffer->AcquirePointer(pointer);
    return (pointer + _offset)[position];
  } catch (...) {
  } finally: {
    if (pointer != nullptr) {
      _buffer->ReleasePointer();
    }
  }
}

Char UnmanagedMemoryAccessor___::ReadChar(Int64 position) {
  return (Char)ReadInt16(position);
}

Int16 UnmanagedMemoryAccessor___::ReadInt16(Int64 position) {
  EnsureSafeToRead(position, 2);
  Byte* pointer = nullptr;
  try {
    _buffer->AcquirePointer(pointer);
    return Unsafe::ReadUnaligned<Int16>(pointer + _offset + position);
  } catch (...) {
  } finally: {
    if (pointer != nullptr) {
      _buffer->ReleasePointer();
    }
  }
}

Int32 UnmanagedMemoryAccessor___::ReadInt32(Int64 position) {
  EnsureSafeToRead(position, 4);
  Byte* pointer = nullptr;
  try {
    _buffer->AcquirePointer(pointer);
    return Unsafe::ReadUnaligned<Int32>(pointer + _offset + position);
  } catch (...) {
  } finally: {
    if (pointer != nullptr) {
      _buffer->ReleasePointer();
    }
  }
}

Int64 UnmanagedMemoryAccessor___::ReadInt64(Int64 position) {
  EnsureSafeToRead(position, 8);
  Byte* pointer = nullptr;
  try {
    _buffer->AcquirePointer(pointer);
    return Unsafe::ReadUnaligned<Int64>(pointer + _offset + position);
  } catch (...) {
  } finally: {
    if (pointer != nullptr) {
      _buffer->ReleasePointer();
    }
  }
}

Decimal UnmanagedMemoryAccessor___::ReadDecimal(Int64 position) {
  EnsureSafeToRead(position, 16);
  Byte* pointer = nullptr;
  Int32 lo;
  Int32 mid;
  Int32 hi;
  Int32 num;
  try {
    _buffer->AcquirePointer(pointer);
    pointer += _offset + position;
    lo = Unsafe::ReadUnaligned<Int32>(pointer);
    mid = Unsafe::ReadUnaligned<Int32>(pointer + 4);
    hi = Unsafe::ReadUnaligned<Int32>(pointer + 8);
    num = Unsafe::ReadUnaligned<Int32>(pointer + 12);
  } catch (...) {
  } finally: {
    if (pointer != nullptr) {
      _buffer->ReleasePointer();
    }
  }
  if (((UInt32)num & 2130771967u) != 0 || (num & 16711680) > 1835008) {
    rt::throw_exception<ArgumentException>(SR::get_Arg_BadDecimal());
  }
  Boolean isNegative = (num & Int32::MinValue()) != 0;
  Byte scale = (Byte)(num >> 16);
  return Decimal(lo, mid, hi, isNegative, scale);
}

Single UnmanagedMemoryAccessor___::ReadSingle(Int64 position) {
  return BitConverter::Int32BitsToSingle(ReadInt32(position));
}

Double UnmanagedMemoryAccessor___::ReadDouble(Int64 position) {
  return BitConverter::Int64BitsToDouble(ReadInt64(position));
}

SByte UnmanagedMemoryAccessor___::ReadSByte(Int64 position) {
  return (SByte)ReadByte(position);
}

UInt16 UnmanagedMemoryAccessor___::ReadUInt16(Int64 position) {
  return (UInt16)ReadInt16(position);
}

UInt32 UnmanagedMemoryAccessor___::ReadUInt32(Int64 position) {
  return (UInt32)ReadInt32(position);
}

UInt64 UnmanagedMemoryAccessor___::ReadUInt64(Int64 position) {
  return (UInt64)ReadInt64(position);
}

void UnmanagedMemoryAccessor___::Write(Int64 position, Boolean value) {
  Write(position, (Byte)(value ? 1u : 0u));
}

void UnmanagedMemoryAccessor___::Write(Int64 position, Byte value) {
  EnsureSafeToWrite(position, 1);
  Byte* pointer = nullptr;
  try {
    _buffer->AcquirePointer(pointer);
    (pointer + _offset)[position] = value;
  } catch (...) {
  } finally: {
    if (pointer != nullptr) {
      _buffer->ReleasePointer();
    }
  }
}

void UnmanagedMemoryAccessor___::Write(Int64 position, Char value) {
  Write(position, (Int16)value);
}

void UnmanagedMemoryAccessor___::Write(Int64 position, Int16 value) {
  EnsureSafeToWrite(position, 2);
  Byte* pointer = nullptr;
  try {
    _buffer->AcquirePointer(pointer);
    Unsafe::WriteUnaligned(pointer + _offset + position, value);
  } catch (...) {
  } finally: {
    if (pointer != nullptr) {
      _buffer->ReleasePointer();
    }
  }
}

void UnmanagedMemoryAccessor___::Write(Int64 position, Int32 value) {
  EnsureSafeToWrite(position, 4);
  Byte* pointer = nullptr;
  try {
    _buffer->AcquirePointer(pointer);
    Unsafe::WriteUnaligned(pointer + _offset + position, value);
  } catch (...) {
  } finally: {
    if (pointer != nullptr) {
      _buffer->ReleasePointer();
    }
  }
}

void UnmanagedMemoryAccessor___::Write(Int64 position, Int64 value) {
  EnsureSafeToWrite(position, 8);
  Byte* pointer = nullptr;
  try {
    _buffer->AcquirePointer(pointer);
    Unsafe::WriteUnaligned(pointer + _offset + position, value);
  } catch (...) {
  } finally: {
    if (pointer != nullptr) {
      _buffer->ReleasePointer();
    }
  }
}

void UnmanagedMemoryAccessor___::Write(Int64 position, Decimal value) {
  EnsureSafeToWrite(position, 16);
  Int32* ptr = (Int32*)(&value);
  Int32 value2 = *ptr;
  Int32 value3 = ptr[1];
  Int32 value4 = ptr[2];
  Int32 value5 = ptr[3];
  Byte* pointer = nullptr;
  try {
    _buffer->AcquirePointer(pointer);
    pointer += _offset + position;
    Unsafe::WriteUnaligned(pointer, value4);
    Unsafe::WriteUnaligned(pointer + 4, value5);
    Unsafe::WriteUnaligned(pointer + 8, value3);
    Unsafe::WriteUnaligned(pointer + 12, value2);
  } catch (...) {
  } finally: {
    if (pointer != nullptr) {
      _buffer->ReleasePointer();
    }
  }
}

void UnmanagedMemoryAccessor___::Write(Int64 position, Single value) {
  Write(position, BitConverter::SingleToInt32Bits(value));
}

void UnmanagedMemoryAccessor___::Write(Int64 position, Double value) {
  Write(position, BitConverter::DoubleToInt64Bits(value));
}

void UnmanagedMemoryAccessor___::Write(Int64 position, SByte value) {
  Write(position, (Byte)value);
}

void UnmanagedMemoryAccessor___::Write(Int64 position, UInt16 value) {
  Write(position, (Int16)value);
}

void UnmanagedMemoryAccessor___::Write(Int64 position, UInt32 value) {
  Write(position, (Int32)value);
}

void UnmanagedMemoryAccessor___::Write(Int64 position, UInt64 value) {
  Write(position, (Int64)value);
}

void UnmanagedMemoryAccessor___::EnsureSafeToRead(Int64 position, Int32 sizeOfType) {
  if (!_isOpen) {
    rt::throw_exception<ObjectDisposedException>("UnmanagedMemoryAccessor", SR::get_ObjectDisposed_ViewAccessorClosed());
  }
  if (!_canRead) {
    rt::throw_exception<NotSupportedException>(SR::get_NotSupported_Reading());
  }
  if (position < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("position", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  if (position > _capacity - sizeOfType) {
    if (position >= _capacity) {
      rt::throw_exception<ArgumentOutOfRangeException>("position", SR::get_ArgumentOutOfRange_PositionLessThanCapacityRequired());
    }
    rt::throw_exception<ArgumentException>(SR::get_Argument_NotEnoughBytesToRead(), "position");
  }
}

void UnmanagedMemoryAccessor___::EnsureSafeToWrite(Int64 position, Int32 sizeOfType) {
  if (!_isOpen) {
    rt::throw_exception<ObjectDisposedException>("UnmanagedMemoryAccessor", SR::get_ObjectDisposed_ViewAccessorClosed());
  }
  if (!_canWrite) {
    rt::throw_exception<NotSupportedException>(SR::get_NotSupported_Writing());
  }
  if (position < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("position", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  if (position > _capacity - sizeOfType) {
    if (position >= _capacity) {
      rt::throw_exception<ArgumentOutOfRangeException>("position", SR::get_ArgumentOutOfRange_PositionLessThanCapacityRequired());
    }
    rt::throw_exception<ArgumentException>(SR::get_Argument_NotEnoughBytesToWrite(), "position");
  }
}

} // namespace System::Private::CoreLib::System::IO::UnmanagedMemoryAccessorNamespace
