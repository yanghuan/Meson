#pragma once

#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Byte)
FORWARDS(Char)
FORWARDS(Decimal)
FORWARDS(Double)
FORWARD(IDisposable)
FORWARDS(Int16)
FORWARDS(Int64)
FORWARDS(ReadOnlySpan, T)
FORWARDS(SByte)
FORWARDS(Single)
FORWARDS(Span, T)
FORWARD(String)
FORWARDS(UInt16)
FORWARDS(UInt32)
FORWARDS(UInt64)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Text {
FORWARD(Decoder)
FORWARD(Encoding)
} // namespace System::Private::CoreLib::System::Text
namespace System::Private::CoreLib::System::IO {
FORWARD(Stream)
namespace BinaryReaderNamespace {
using namespace Text;
CLASS(BinaryReader) : public Object::in {
  public: using interface = rt::TypeList<IDisposable>;
  public: Stream get_BaseStream();
  public: void ctor(Stream input);
  public: void ctor(Stream input, Encoding encoding);
  public: void ctor(Stream input, Encoding encoding, Boolean leaveOpen);
  protected: void Dispose(Boolean disposing);
  public: void Dispose();
  public: void Close();
  private: void ThrowIfDisposed();
  public: Int32 PeekChar();
  public: Int32 Read();
  public: Byte ReadByte();
  private: Byte InternalReadByte();
  public: SByte ReadSByte();
  public: Boolean ReadBoolean();
  public: Char ReadChar();
  public: Int16 ReadInt16();
  public: UInt16 ReadUInt16();
  public: Int32 ReadInt32();
  public: UInt32 ReadUInt32();
  public: Int64 ReadInt64();
  public: UInt64 ReadUInt64();
  public: Single ReadSingle();
  public: Double ReadDouble();
  public: Decimal ReadDecimal();
  public: String ReadString();
  public: Int32 Read(Array<Char> buffer, Int32 index, Int32 count);
  public: Int32 Read(Span<Char> buffer);
  private: Int32 InternalReadChars(Span<Char> buffer);
  public: Array<Char> ReadChars(Int32 count);
  public: Int32 Read(Array<Byte> buffer, Int32 index, Int32 count);
  public: Int32 Read(Span<Byte> buffer);
  public: Array<Byte> ReadBytes(Int32 count);
  private: ReadOnlySpan<Byte> InternalRead(Int32 numBytes);
  protected: void FillBuffer(Int32 numBytes);
  public: Int32 Read7BitEncodedInt();
  public: Int64 Read7BitEncodedInt64();
  private: Stream _stream;
  private: Array<Byte> _buffer;
  private: Decoder _decoder;
  private: Array<Byte> _charBytes;
  private: Array<Char> _charBuffer;
  private: Int32 _maxCharsSize;
  private: Boolean _2BytesPerChar;
  private: Boolean _isMemoryStream;
  private: Boolean _leaveOpen;
  private: Boolean _disposed;
};
} // namespace BinaryReaderNamespace
using BinaryReader = BinaryReaderNamespace::BinaryReader;
} // namespace System::Private::CoreLib::System::IO
