#include "BinaryWriter-dep.h"

#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/Buffers/ArrayPool-dep.h>
#include <System.Private.CoreLib/System/Buffers/Binary/BinaryPrimitives-dep.h>
#include <System.Private.CoreLib/System/Byte-dep.h>
#include <System.Private.CoreLib/System/Exception-dep.h>
#include <System.Private.CoreLib/System/IO/BinaryWriter-dep.h>
#include <System.Private.CoreLib/System/IO/EncodingCache-dep.h>
#include <System.Private.CoreLib/System/ReadOnlySpan-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/Text/UTF8Encoding-dep.h>
#include <System.Private.CoreLib/System/Type-dep.h>
#include <System.Private.CoreLib/System/UIntPtr-dep.h>

namespace System::Private::CoreLib::System::IO::BinaryWriterNamespace {
using namespace System::Buffers;
using namespace System::Buffers::Binary;
using namespace System::Text;

Stream BinaryWriter___::get_BaseStream() {
  Flush();
  return OutStream;
}

void BinaryWriter___::ctor() {
  OutStream = Stream::in::Null;
  _buffer = rt::newarr<Array<Byte>>(16);
  _encoding = EncodingCache::UTF8NoBOM;
  _encoder = _encoding->GetEncoder();
}

void BinaryWriter___::ctor(Stream output) {
}

void BinaryWriter___::ctor(Stream output, Encoding encoding) {
}

void BinaryWriter___::ctor(Stream output, Encoding encoding, Boolean leaveOpen) {
  if (output == nullptr) {
    rt::throw_exception<ArgumentNullException>("output");
  }
  if (encoding == nullptr) {
    rt::throw_exception<ArgumentNullException>("encoding");
  }
  if (!output->get_CanWrite()) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_StreamNotWritable());
  }
  OutStream = output;
  _buffer = rt::newarr<Array<Byte>>(16);
  _encoding = encoding;
  _encoder = _encoding->GetEncoder();
  _leaveOpen = leaveOpen;
}

void BinaryWriter___::Close() {
  Dispose(true);
}

void BinaryWriter___::Dispose(Boolean disposing) {
  if (disposing) {
    if (_leaveOpen) {
      OutStream->Flush();
    } else {
      OutStream->Close();
    }
  }
}

void BinaryWriter___::Dispose() {
  Dispose(true);
}

ValueTask<> BinaryWriter___::DisposeAsync() {
  try {
    if (GetType() == typeof<BinaryWriter>()) {
      if (_leaveOpen) {
        return ValueTask<>(OutStream->FlushAsync());
      }
      OutStream->Close();
    } else {
      Dispose();
    }
    return rt::default__;
  } catch (Exception exception) {
    return ValueTask<>::FromException(exception);
  }
}

void BinaryWriter___::Flush() {
  OutStream->Flush();
}

Int64 BinaryWriter___::Seek(Int32 offset, SeekOrigin origin) {
  return OutStream->Seek(offset, origin);
}

void BinaryWriter___::Write(Boolean value) {
  OutStream->WriteByte((Byte)(value ? 1u : 0u));
}

void BinaryWriter___::Write(Byte value) {
  OutStream->WriteByte(value);
}

void BinaryWriter___::Write(SByte value) {
  OutStream->WriteByte((Byte)value);
}

void BinaryWriter___::Write(Array<Byte> buffer) {
  if (buffer == nullptr) {
    rt::throw_exception<ArgumentNullException>("buffer");
  }
  OutStream->Write(buffer, 0, buffer->get_Length());
}

void BinaryWriter___::Write(Array<Byte> buffer, Int32 index, Int32 count) {
  OutStream->Write(buffer, index, count);
}

void BinaryWriter___::Write(Char ch) {
  if (Char::IsSurrogate(ch)) {
    rt::throw_exception<ArgumentException>(SR::get_Arg_SurrogatesNotAllowedAsSingleChar());
  }
  Int32 num = 0;
  {
    Byte* bytes = rt::fixed(&_buffer[0]);
    num = _encoder->GetBytes(&ch, 1, bytes, _buffer->get_Length(), true);
  }
  OutStream->Write(_buffer, 0, num);
}

void BinaryWriter___::Write(Array<Char> chars) {
  if (chars == nullptr) {
    rt::throw_exception<ArgumentNullException>("chars");
  }
  Array<Byte> bytes = _encoding->GetBytes(chars, 0, chars->get_Length());
  OutStream->Write(bytes, 0, bytes->get_Length());
}

void BinaryWriter___::Write(Array<Char> chars, Int32 index, Int32 count) {
  Array<Byte> bytes = _encoding->GetBytes(chars, index, count);
  OutStream->Write(bytes, 0, bytes->get_Length());
}

void BinaryWriter___::Write(Double value) {
  BinaryPrimitives::WriteDoubleLittleEndian(_buffer, value);
  OutStream->Write(_buffer, 0, 8);
}

void BinaryWriter___::Write(Decimal value) {
  Decimal::GetBytes(value, _buffer);
  OutStream->Write(_buffer, 0, 16);
}

void BinaryWriter___::Write(Int16 value) {
  _buffer[0] = (Byte)value;
  _buffer[1] = (Byte)(value >> 8);
  OutStream->Write(_buffer, 0, 2);
}

void BinaryWriter___::Write(UInt16 value) {
  _buffer[0] = (Byte)value;
  _buffer[1] = (Byte)(value >> 8);
  OutStream->Write(_buffer, 0, 2);
}

void BinaryWriter___::Write(Int32 value) {
  _buffer[0] = (Byte)value;
  _buffer[1] = (Byte)(value >> 8);
  _buffer[2] = (Byte)(value >> 16);
  _buffer[3] = (Byte)(value >> 24);
  OutStream->Write(_buffer, 0, 4);
}

void BinaryWriter___::Write(UInt32 value) {
  _buffer[0] = (Byte)value;
  _buffer[1] = (Byte)(value >> 8);
  _buffer[2] = (Byte)(value >> 16);
  _buffer[3] = (Byte)(value >> 24);
  OutStream->Write(_buffer, 0, 4);
}

void BinaryWriter___::Write(Int64 value) {
  BinaryPrimitives::WriteInt64LittleEndian(_buffer, value);
  OutStream->Write(_buffer, 0, 8);
}

void BinaryWriter___::Write(UInt64 value) {
  BinaryPrimitives::WriteUInt64LittleEndian(_buffer, value);
  OutStream->Write(_buffer, 0, 8);
}

void BinaryWriter___::Write(Single value) {
  UInt32 num = *(UInt32*)(&value);
  _buffer[0] = (Byte)num;
  _buffer[1] = (Byte)(num >> 8);
  _buffer[2] = (Byte)(num >> 16);
  _buffer[3] = (Byte)(num >> 24);
  OutStream->Write(_buffer, 0, 4);
}

void BinaryWriter___::Write(String value) {
  if (value == nullptr) {
    rt::throw_exception<ArgumentNullException>("value");
  }
  Int32 byteCount = _encoding->GetByteCount(value);
  Write7BitEncodedInt(byteCount);
  if (_largeByteBuffer == nullptr) {
    _largeByteBuffer = rt::newarr<Array<Byte>>(256);
    _maxChars = _largeByteBuffer->get_Length() / _encoding->GetMaxByteCount(1);
  }
  if (byteCount <= _largeByteBuffer->get_Length()) {
    _encoding->GetBytes(value, _largeByteBuffer);
    OutStream->Write(_largeByteBuffer, 0, byteCount);
    return;
  }
  Int32 num = value->get_Length();
  Int32 num2 = 0;
  ReadOnlySpan<Char> readOnlySpan = value;
  if (_encoding->GetType() == typeof<UTF8Encoding>()) {
    while (num > 0) {
      Int32 charsUsed;
      Int32 bytesUsed;
      Boolean completed;
      _encoder->Convert(readOnlySpan.Slice(num2), _largeByteBuffer, num <= _maxChars, charsUsed, bytesUsed, completed);
      OutStream->Write(_largeByteBuffer, 0, bytesUsed);
      num2 += charsUsed;
      num -= charsUsed;
    }
  } else {
    WriteWhenEncodingIsNotUtf8(value, byteCount);
  }
}

void BinaryWriter___::WriteWhenEncodingIsNotUtf8(String value, Int32 len) {
  Int32 num = value->get_Length();
  Int32 num2 = 0;
  while (num > 0) {
    Int32 num3 = ((num > _maxChars) ? _maxChars : num);
    if (num2 < 0 || num3 < 0 || num2 > value->get_Length() - num3) {
      rt::throw_exception<ArgumentOutOfRangeException>("value");
    }
    Int32 bytes2;
    {
      Char* ptr = rt::fixed(value);
      Char* ptr2 = ptr;
      {
        Byte* bytes = rt::fixed(&_largeByteBuffer[0]);
        bytes2 = _encoder->GetBytes((Char*)(UInt64)ptr2 + (UInt64)(UIntPtr)(void*)(Int64)num2 * 2, num3, bytes, _largeByteBuffer->get_Length(), num3 == num);
      }
    }
    OutStream->Write(_largeByteBuffer, 0, bytes2);
    num2 += num3;
    num -= num3;
  }
}

void BinaryWriter___::Write(ReadOnlySpan<Byte> buffer) {
  if (GetType() == typeof<BinaryWriter>()) {
    OutStream->Write(buffer);
    return;
  }
  Array<Byte> array = ArrayPool<Byte>::in::get_Shared()->Rent(buffer.get_Length());
  try {
    buffer.CopyTo(array);
    Write(array, 0, buffer.get_Length());
  } catch (...) {
  } finally: {
    ArrayPool<Byte>::in::get_Shared()->Return(array);
  }
}

void BinaryWriter___::Write(ReadOnlySpan<Char> chars) {
  Array<Byte> array = ArrayPool<Byte>::in::get_Shared()->Rent(_encoding->GetMaxByteCount(chars.get_Length()));
  try {
    Int32 bytes = _encoding->GetBytes(chars, array);
    Write(array, 0, bytes);
  } catch (...) {
  } finally: {
    ArrayPool<Byte>::in::get_Shared()->Return(array);
  }
}

void BinaryWriter___::Write7BitEncodedInt(Int32 value) {
  UInt32 num;
  for (num = (UInt32)value; num > 127; num >>= 7) {
    Write((Byte)(num | 4294967168u));
  }
  Write((Byte)num);
}

void BinaryWriter___::Write7BitEncodedInt64(Int64 value) {
  UInt64 num;
  for (num = (UInt64)value; num > 127; num >>= 7) {
    Write((Byte)((UInt32)(Int32)num | 4294967168u));
  }
  Write((Byte)num);
}

void BinaryWriter___::cctor() {
  Null = rt::newobj<BinaryWriter>();
}

} // namespace System::Private::CoreLib::System::IO::BinaryWriterNamespace
