#include "BinaryReader-dep.h"

#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/BitConverter-dep.h>
#include <System.Private.CoreLib/System/Buffer-dep.h>
#include <System.Private.CoreLib/System/Buffers/Binary/BinaryPrimitives-dep.h>
#include <System.Private.CoreLib/System/Byte-dep.h>
#include <System.Private.CoreLib/System/Char-dep.h>
#include <System.Private.CoreLib/System/FormatException-dep.h>
#include <System.Private.CoreLib/System/Int32-dep.h>
#include <System.Private.CoreLib/System/Int64-dep.h>
#include <System.Private.CoreLib/System/IO/Error-dep.h>
#include <System.Private.CoreLib/System/IO/IOException-dep.h>
#include <System.Private.CoreLib/System/IO/MemoryStream-dep.h>
#include <System.Private.CoreLib/System/IO/SeekOrigin.h>
#include <System.Private.CoreLib/System/Math-dep.h>
#include <System.Private.CoreLib/System/ReadOnlySpan-dep.h>
#include <System.Private.CoreLib/System/Span-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/Text/DecoderNLS-dep.h>
#include <System.Private.CoreLib/System/Text/StringBuilder-dep.h>
#include <System.Private.CoreLib/System/Text/StringBuilderCache-dep.h>
#include <System.Private.CoreLib/System/Text/UnicodeEncoding-dep.h>
#include <System.Private.CoreLib/System/Type-dep.h>

namespace System::Private::CoreLib::System::IO::BinaryReaderNamespace {
using namespace System::Buffers::Binary;
using namespace System::Text;

Stream BinaryReader___::get_BaseStream() {
  return _stream;
}

void BinaryReader___::ctor(Stream input) {
}

void BinaryReader___::ctor(Stream input, Encoding encoding) {
}

void BinaryReader___::ctor(Stream input, Encoding encoding, Boolean leaveOpen) {
  if (input == nullptr) {
    rt::throw_exception<ArgumentNullException>("input");
  }
  if (encoding == nullptr) {
    rt::throw_exception<ArgumentNullException>("encoding");
  }
  if (!input->get_CanRead()) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_StreamNotReadable());
  }
  _stream = input;
  _decoder = encoding->GetDecoder();
  _maxCharsSize = encoding->GetMaxCharCount(128);
  Int32 num = encoding->GetMaxByteCount(1);
  if (num < 16) {
    num = 16;
  }
  _buffer = rt::newarr<Array<Byte>>(num);
  _2BytesPerChar = rt::is<UnicodeEncoding>(encoding);
  _isMemoryStream = (_stream->GetType() == typeof<MemoryStream>());
  _leaveOpen = leaveOpen;
}

void BinaryReader___::Dispose(Boolean disposing) {
  if (!_disposed) {
    if (disposing && !_leaveOpen) {
      _stream->Close();
    }
    _disposed = true;
  }
}

void BinaryReader___::Dispose() {
  Dispose(true);
}

void BinaryReader___::Close() {
  Dispose(true);
}

void BinaryReader___::ThrowIfDisposed() {
  if (_disposed) {
    rt::throw_exception(Error::GetFileNotOpen());
  }
}

Int32 BinaryReader___::PeekChar() {
  ThrowIfDisposed();
  if (!_stream->get_CanSeek()) {
    return -1;
  }
  Int64 position = _stream->get_Position();
  Int32 result = Read();
  _stream->set_Position(position);
  return result;
}

Int32 BinaryReader___::Read() {
  ThrowIfDisposed();
  Int32 num = 0;
  Int64 num2 = 0;
  if (_stream->get_CanSeek()) {
    num2 = _stream->set_Position();
  }
  if (_charBytes == nullptr) {
    _charBytes = rt::newarr<Array<Byte>>(128);
  }
  Char as[1] = {};
  Span<Char> chars = as;
  while (num == 0) {
    Int32 num3 = (!_2BytesPerChar) ? 1 : 2;
    Int32 num4 = _stream->ReadByte();
    _charBytes[0] = (Byte)num4;
    if (num4 == -1) {
      num3 = 0;
    }
    if (num3 == 2) {
      num4 = _stream->ReadByte();
      _charBytes[1] = (Byte)num4;
      if (num4 == -1) {
        num3 = 1;
      }
    }
    if (num3 == 0) {
      return -1;
    }
    try {
      num = _decoder->GetChars(ReadOnlySpan<Byte>(_charBytes, 0, num3), chars, false);
    } catch (...) {
      if (_stream->get_CanSeek()) {
        _stream->Seek(num2 - _stream->get_Position(), SeekOrigin::Current);
      }
      throw;
    }
  }
  return chars[0];
}

Byte BinaryReader___::ReadByte() {
  return InternalReadByte();
}

Byte BinaryReader___::InternalReadByte() {
  ThrowIfDisposed();
  Int32 num = _stream->ReadByte();
  if (num == -1) {
    rt::throw_exception(Error::GetEndOfFile());
  }
  return (Byte)num;
}

SByte BinaryReader___::ReadSByte() {
  return (SByte)InternalReadByte();
}

Boolean BinaryReader___::ReadBoolean() {
  return InternalReadByte() != 0;
}

Char BinaryReader___::ReadChar() {
  Int32 num = Read();
  if (num == -1) {
    rt::throw_exception(Error::GetEndOfFile());
  }
  return (Char)num;
}

Int16 BinaryReader___::ReadInt16() {
  return BinaryPrimitives::ReadInt16LittleEndian(InternalRead(2));
}

UInt16 BinaryReader___::ReadUInt16() {
  return BinaryPrimitives::ReadUInt16LittleEndian(InternalRead(2));
}

Int32 BinaryReader___::ReadInt32() {
  return BinaryPrimitives::ReadInt32LittleEndian(InternalRead(4));
}

UInt32 BinaryReader___::ReadUInt32() {
  return BinaryPrimitives::ReadUInt32LittleEndian(InternalRead(4));
}

Int64 BinaryReader___::ReadInt64() {
  return BinaryPrimitives::ReadInt64LittleEndian(InternalRead(8));
}

UInt64 BinaryReader___::ReadUInt64() {
  return BinaryPrimitives::ReadUInt64LittleEndian(InternalRead(8));
}

Single BinaryReader___::ReadSingle() {
  return BitConverter::Int32BitsToSingle(BinaryPrimitives::ReadInt32LittleEndian(InternalRead(4)));
}

Double BinaryReader___::ReadDouble() {
  return BitConverter::Int64BitsToDouble(BinaryPrimitives::ReadInt64LittleEndian(InternalRead(8)));
}

Decimal BinaryReader___::ReadDecimal() {
  ReadOnlySpan<Byte> span = InternalRead(16);
  try {
    return Decimal::ToDecimal(span);
  } catch (ArgumentException innerException) {
    rt::throw_exception<IOException>(SR::get_Arg_DecBitCtor(), innerException);
  }
}

String BinaryReader___::ReadString() {
  ThrowIfDisposed();
  Int32 num = 0;
  Int32 num2 = Read7BitEncodedInt();
  if (num2 < 0) {
    rt::throw_exception<IOException>(SR::Format(SR::get_IO_InvalidStringLen_Len(), num2));
  }
  if (num2 == 0) {
    return String::in::Empty;
  }
  if (_charBytes == nullptr) {
    _charBytes = rt::newarr<Array<Byte>>(128);
  }
  if (_charBuffer == nullptr) {
    _charBuffer = rt::newarr<Array<Char>>(_maxCharsSize);
  }
  StringBuilder stringBuilder = nullptr;
  do {
    Int32 count = (num2 - num > 128) ? 128 : (num2 - num);
    Int32 num3 = _stream->Read(_charBytes, 0, count);
    if (num3 == 0) {
      rt::throw_exception(Error::GetEndOfFile());
    }
    Int32 chars = _decoder->GetChars(_charBytes, 0, num3, _charBuffer, 0);
    if (num == 0 && num3 == num2) {
      return rt::newstr<String>(_charBuffer, 0, chars);
    }
    if (stringBuilder == nullptr) {
      stringBuilder = StringBuilderCache::Acquire(Math::Min(num2, 360));
    }
    stringBuilder->Append(_charBuffer, 0, chars);
    num += num3;
  } while (num < num2)
  return StringBuilderCache::GetStringAndRelease(stringBuilder);
}

Int32 BinaryReader___::Read(Array<Char> buffer, Int32 index, Int32 count) {
  if (buffer == nullptr) {
    rt::throw_exception<ArgumentNullException>("buffer", SR::get_ArgumentNull_Buffer());
  }
  if (index < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("index", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  if (count < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("count", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  if (buffer->get_Length() - index < count) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_InvalidOffLen());
  }
  ThrowIfDisposed();
  return InternalReadChars(Span<Char>(buffer, index, count));
}

Int32 BinaryReader___::Read(Span<Char> buffer) {
  ThrowIfDisposed();
  return InternalReadChars(buffer);
}

Int32 BinaryReader___::InternalReadChars(Span<Char> buffer) {
  Int32 num = 0;
  while (!buffer.get_IsEmpty()) {
    Int32 num2 = buffer.get_Length();
    if (_2BytesPerChar) {
      num2 <<= 1;
    }
    if (num2 > 1) {
      DecoderNLS decoderNLS = rt::as<DecoderNLS>(_decoder);
      if (decoderNLS == nullptr || decoderNLS->get_HasState()) {
        num2--;
        if (_2BytesPerChar && num2 > 2) {
          num2 -= 2;
        }
      }
    }
    ReadOnlySpan<Byte> bytes;
    if (_isMemoryStream) {
      MemoryStream memoryStream = (MemoryStream)_stream;
      Int32 start = memoryStream->InternalGetPosition();
      num2 = memoryStream->InternalEmulateRead(num2);
      bytes = ReadOnlySpan<Byte>(memoryStream->InternalGetBuffer(), start, num2);
    } else {
      if (_charBytes == nullptr) {
        _charBytes = rt::newarr<Array<Byte>>(128);
      }
      if (num2 > 128) {
        num2 = 128;
      }
      num2 = _stream->Read(_charBytes, 0, num2);
      bytes = ReadOnlySpan<Byte>(_charBytes, 0, num2);
    }
    if (bytes.get_IsEmpty()) {
      break;
    }
    Int32 chars = _decoder->GetChars(bytes, buffer, false);
    buffer = buffer.Slice(chars);
    num += chars;
  }
  return num;
}

Array<Char> BinaryReader___::ReadChars(Int32 count) {
  if (count < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("count", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  ThrowIfDisposed();
  if (count == 0) {
    return Array<>::in::Empty<Char>();
  }
  Array<Char> array = rt::newarr<Array<Char>>(count);
  Int32 num = InternalReadChars(Span<Char>(array));
  if (num != count) {
    Array<Char> array2 = rt::newarr<Array<Char>>(num);
    Buffer::BlockCopy(array, 0, array2, 0, 2 * num);
    array = array2;
  }
  return array;
}

Int32 BinaryReader___::Read(Array<Byte> buffer, Int32 index, Int32 count) {
  if (buffer == nullptr) {
    rt::throw_exception<ArgumentNullException>("buffer", SR::get_ArgumentNull_Buffer());
  }
  if (index < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("index", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  if (count < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("count", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  if (buffer->get_Length() - index < count) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_InvalidOffLen());
  }
  ThrowIfDisposed();
  return _stream->Read(buffer, index, count);
}

Int32 BinaryReader___::Read(Span<Byte> buffer) {
  ThrowIfDisposed();
  return _stream->Read(buffer);
}

Array<Byte> BinaryReader___::ReadBytes(Int32 count) {
  if (count < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("count", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  ThrowIfDisposed();
  if (count == 0) {
    return Array<>::in::Empty<Byte>();
  }
  Array<Byte> array = rt::newarr<Array<Byte>>(count);
  Int32 num = 0;
  do {
    Int32 num2 = _stream->Read(array, num, count);
    if (num2 == 0) {
      break;
    }
    num += num2;
    count -= num2;
  } while (count > 0)
  if (num != array->get_Length()) {
    Array<Byte> array2 = rt::newarr<Array<Byte>>(num);
    Buffer::BlockCopy(array, 0, array2, 0, num);
    array = array2;
  }
  return array;
}

ReadOnlySpan<Byte> BinaryReader___::InternalRead(Int32 numBytes) {
  if (_isMemoryStream) {
    return ((MemoryStream)_stream)->InternalReadSpan(numBytes);
  }
  ThrowIfDisposed();
  Int32 num = 0;
  do {
    Int32 num2 = _stream->Read(_buffer, num, numBytes - num);
    if (num2 == 0) {
      rt::throw_exception(Error::GetEndOfFile());
    }
    num += num2;
  } while (num < numBytes)
  return _buffer;
}

void BinaryReader___::FillBuffer(Int32 numBytes) {
  if (numBytes < 0 || numBytes > _buffer->get_Length()) {
    rt::throw_exception<ArgumentOutOfRangeException>("numBytes", SR::get_ArgumentOutOfRange_BinaryReaderFillBuffer());
  }
  Int32 num = 0;
  Int32 num2 = 0;
  ThrowIfDisposed();
  if (numBytes == 1) {
    num2 = _stream->ReadByte();
    if (num2 == -1) {
      rt::throw_exception(Error::GetEndOfFile());
    }
    _buffer[0] = (Byte)num2;
    return;
  }
  do {
    num2 = _stream->Read(_buffer, num, numBytes - num);
    if (num2 == 0) {
      rt::throw_exception(Error::GetEndOfFile());
    }
    num += num2;
  } while (num < numBytes)
}

Int32 BinaryReader___::Read7BitEncodedInt() {
  UInt32 num = 0u;
  Byte b;
  for (Int32 i = 0; i < 28; i += 7) {
    b = ReadByte();
    num |= (UInt32)((b & 127) << i);
    if ((UInt32)b <= 127u) {
      return (Int32)num;
    }
  }
  b = ReadByte();
  if ((UInt32)b > 15u) {
    rt::throw_exception<FormatException>(SR::get_Format_Bad7BitInt());
  }
  return (Int32)num | (b << 28);
}

Int64 BinaryReader___::Read7BitEncodedInt64() {
  UInt64 num = 0;
  Byte b;
  for (Int32 i = 0; i < 63; i += 7) {
    b = ReadByte();
    num |= (UInt64)(((Int64)b & 127) << i);
    if ((UInt32)b <= 127u) {
      return (Int64)num;
    }
  }
  b = ReadByte();
  if ((UInt32)b > 1u) {
    rt::throw_exception<FormatException>(SR::get_Format_Bad7BitInt());
  }
  return (Int64)(num | ((UInt64)b << 63));
}

} // namespace System::Private::CoreLib::System::IO::BinaryReaderNamespace
