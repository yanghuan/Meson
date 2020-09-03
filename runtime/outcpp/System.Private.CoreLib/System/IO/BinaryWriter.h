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
FORWARD(IAsyncDisposable)
FORWARD(IDisposable)
FORWARDS(Int16)
FORWARDS(Int64)
FORWARDS(ReadOnlySpan, T)
FORWARDS(SByte)
FORWARDS(Single)
FORWARD(String)
FORWARDS(UInt16)
FORWARDS(UInt32)
FORWARDS(UInt64)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Text {
FORWARD(Encoder)
FORWARD(Encoding)
} // namespace System::Private::CoreLib::System::Text
namespace System::Private::CoreLib::System::Threading::Tasks {
FORWARDS_(ValueTask, T1, T2)
} // namespace System::Private::CoreLib::System::Threading::Tasks
namespace System::Private::CoreLib::System::IO {
enum class SeekOrigin : int32_t;
FORWARD(Stream)
namespace BinaryWriterNamespace {
using namespace System::Text;
using namespace System::Threading::Tasks;
CLASS(BinaryWriter) : public object {
  public: using interface = rt::TypeList<IDisposable, IAsyncDisposable>;
  public: Stream get_BaseStream();
  protected: void ctor();
  public: void ctor(Stream output);
  public: void ctor(Stream output, Encoding encoding);
  public: void ctor(Stream output, Encoding encoding, Boolean leaveOpen);
  public: void Close();
  protected: void Dispose(Boolean disposing);
  public: void Dispose();
  public: ValueTask<> DisposeAsync();
  public: void Flush();
  public: Int64 Seek(Int32 offset, SeekOrigin origin);
  public: void Write(Boolean value);
  public: void Write(Byte value);
  public: void Write(SByte value);
  public: void Write(Array<Byte> buffer);
  public: void Write(Array<Byte> buffer, Int32 index, Int32 count);
  public: void Write(Char ch);
  public: void Write(Array<Char> chars);
  public: void Write(Array<Char> chars, Int32 index, Int32 count);
  public: void Write(Double value);
  public: void Write(Decimal value);
  public: void Write(Int16 value);
  public: void Write(UInt16 value);
  public: void Write(Int32 value);
  public: void Write(UInt32 value);
  public: void Write(Int64 value);
  public: void Write(UInt64 value);
  public: void Write(Single value);
  public: void Write(String value);
  private: void WriteWhenEncodingIsNotUtf8(String value, Int32 len);
  public: void Write(ReadOnlySpan<Byte> buffer);
  public: void Write(ReadOnlySpan<Char> chars);
  public: void Write7BitEncodedInt(Int32 value);
  public: void Write7BitEncodedInt64(Int64 value);
  private: static void cctor();
  public: static BinaryWriter Null;
  protected: Stream OutStream;
  private: Array<Byte> _buffer;
  private: Encoding _encoding;
  private: Encoder _encoder;
  private: Boolean _leaveOpen;
  private: Array<Byte> _largeByteBuffer;
  private: Int32 _maxChars;
};
} // namespace BinaryWriterNamespace
using BinaryWriter = BinaryWriterNamespace::BinaryWriter;
} // namespace System::Private::CoreLib::System::IO
