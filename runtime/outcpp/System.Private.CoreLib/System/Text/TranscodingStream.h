#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/Int32.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(ArraySegment, T)
FORWARD(AsyncCallback)
FORWARDS(Byte)
FORWARD(IAsyncResult)
FORWARDS(Int64)
FORWARDS(Memory, T)
FORWARD(Object)
FORWARDS(ReadOnlyMemory, T)
FORWARDS(ReadOnlySpan, T)
FORWARDS(Span, T)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading::Tasks {
FORWARD_(Task, T1, T2)
FORWARDS_(ValueTask, T1, T2)
} // namespace System::Private::CoreLib::System::Threading::Tasks
namespace System::Private::CoreLib::System::Threading {
FORWARDS(CancellationToken)
} // namespace System::Private::CoreLib::System::Threading
namespace System::Private::CoreLib::System::IO {
enum class SeekOrigin;
FORWARD(Stream)
} // namespace System::Private::CoreLib::System::IO
namespace System::Private::CoreLib::System::Text {
FORWARD(Decoder)
FORWARD(Encoder)
FORWARD(Encoding)
namespace TranscodingStreamNamespace {
using namespace IO;
using namespace Threading;
using namespace Threading::Tasks;
CLASS(TranscodingStream) {
  public: Boolean get_CanRead();
  public: Boolean get_CanSeek();
  public: Boolean get_CanWrite();
  public: Int64 get_Length();
  public: Int64 get_Position();
  public: void set_Position(Int64 value);
  public: IAsyncResult BeginRead(Array<Byte> buffer, Int32 offset, Int32 count, AsyncCallback callback, Object state);
  public: IAsyncResult BeginWrite(Array<Byte> buffer, Int32 offset, Int32 count, AsyncCallback callback, Object state);
  protected: void Dispose(Boolean disposing);
  public: ValueTask<> DisposeAsync();
  public: Int32 EndRead(IAsyncResult asyncResult);
  public: void EndWrite(IAsyncResult asyncResult);
  private: void EnsurePreReadConditions();
  private: void EnsurePreWriteConditions();
  private: ArraySegment<Byte> FinalFlushWriteBuffers();
  public: void Flush();
  public: Task<> FlushAsync(CancellationToken cancellationToken);
  public: Int32 Read(Array<Byte> buffer, Int32 offset, Int32 count);
  public: Int32 Read(Span<Byte> buffer);
  public: Task<Int32> ReadAsync(Array<Byte> buffer, Int32 offset, Int32 count, CancellationToken cancellationToken);
  public: ValueTask<Int32> ReadAsync(Memory<Byte> buffer, CancellationToken cancellationToken);
  public: Int32 ReadByte();
  public: Int64 Seek(Int64 offset, SeekOrigin origin);
  public: void SetLength(Int64 value);
  private: void ThrowIfDisposed();
  private: void ThrowObjectDisposedException();
  public: void Write(Array<Byte> buffer, Int32 offset, Int32 count);
  public: void Write(ReadOnlySpan<Byte> buffer);
  public: Task<> WriteAsync(Array<Byte> buffer, Int32 offset, Int32 count, CancellationToken cancellationToken);
  public: ValueTask<> WriteAsync(ReadOnlyMemory<Byte> buffer, CancellationToken cancellationToken);
  public: void WriteByte(Byte value);
  private: Encoding _innerEncoding;
  private: Encoding _thisEncoding;
  private: Stream _innerStream;
  private: Boolean _leaveOpen;
  private: Encoder _innerEncoder;
  private: Decoder _thisDecoder;
  private: Encoder _thisEncoder;
  private: Decoder _innerDecoder;
  private: Int32 _readCharBufferMaxSize;
  private: Array<Byte> _readBuffer;
  private: Int32 _readBufferOffset;
  private: Int32 _readBufferCount;
};
} // namespace TranscodingStreamNamespace
using TranscodingStream = TranscodingStreamNamespace::TranscodingStream;
} // namespace System::Private::CoreLib::System::Text
