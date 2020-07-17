#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Int32.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARD(AsyncCallback)
FORWARDS(Boolean)
FORWARDS(Byte)
FORWARD(Exception)
FORWARD(IAsyncResult)
FORWARDS(Int64)
FORWARDS(Memory, T)
FORWARD(Object)
FORWARDS(ReadOnlyMemory, T)
FORWARDS(ReadOnlySpan, T)
FORWARDS(Span, T)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading {
FORWARDS(CancellationToken)
FORWARD(SemaphoreSlim)
} // namespace System::Private::CoreLib::System::Threading
namespace System::Private::CoreLib::System::Threading::Tasks {
FORWARD_(Task, T1, T2)
FORWARDS_(ValueTask, T1, T2)
} // namespace System::Private::CoreLib::System::Threading::Tasks
namespace System::Private::CoreLib::System::IO {
enum class SeekOrigin;
FORWARD(Stream)
namespace BufferedStreamNamespace {
using namespace Threading;
using namespace Threading::Tasks;
CLASS(BufferedStream) {
  public: Stream get_UnderlyingStream();
  public: Int32 get_BufferSize();
  public: Boolean get_CanRead();
  public: Boolean get_CanWrite();
  public: Boolean get_CanSeek();
  public: Int64 get_Length();
  public: Int64 get_Position();
  public: void set_Position(Int64 value);
  public: SemaphoreSlim LazyEnsureAsyncActiveSemaphoreInitialized();
  public: void Ctor(Stream stream);
  public: void Ctor(Stream stream, Int32 bufferSize);
  private: void EnsureNotClosed();
  private: void EnsureCanSeek();
  private: void EnsureCanRead();
  private: void EnsureCanWrite();
  private: void EnsureShadowBufferAllocated();
  private: void EnsureBufferAllocated();
  protected: void Dispose(Boolean disposing);
  public: ValueTask<> DisposeAsync();
  public: void Flush();
  public: Task<> FlushAsync(CancellationToken cancellationToken);
  private: Task<> FlushAsyncInternal(CancellationToken cancellationToken);
  private: void FlushRead();
  private: void ClearReadBufferBeforeWrite();
  private: void FlushWrite();
  private: ValueTask<> FlushWriteAsync(CancellationToken cancellationToken);
  private: Int32 ReadFromBuffer(Array<Byte> array, Int32 offset, Int32 count);
  private: Int32 ReadFromBuffer(Span<Byte> destination);
  private: Int32 ReadFromBuffer(Array<Byte> array, Int32 offset, Int32 count, Exception& error);
  public: Int32 Read(Array<Byte> array, Int32 offset, Int32 count);
  public: Int32 Read(Span<Byte> destination);
  private: Task<Int32> LastSyncCompletedReadTask(Int32 val);
  public: Task<Int32> ReadAsync(Array<Byte> buffer, Int32 offset, Int32 count, CancellationToken cancellationToken);
  public: ValueTask<Int32> ReadAsync(Memory<Byte> buffer, CancellationToken cancellationToken);
  private: ValueTask<Int32> ReadFromUnderlyingStreamAsync(Memory<Byte> buffer, CancellationToken cancellationToken, Int32 bytesAlreadySatisfied, Task<> semaphoreLockTask);
  public: IAsyncResult BeginRead(Array<Byte> buffer, Int32 offset, Int32 count, AsyncCallback callback, Object state);
  public: Int32 EndRead(IAsyncResult asyncResult);
  public: Int32 ReadByte();
  private: Int32 ReadByteSlow();
  private: void WriteToBuffer(Array<Byte> array, Int32& offset, Int32& count);
  private: Int32 WriteToBuffer(ReadOnlySpan<Byte> buffer);
  public: void Write(Array<Byte> array, Int32 offset, Int32 count);
  public: void Write(ReadOnlySpan<Byte> buffer);
  public: Task<> WriteAsync(Array<Byte> buffer, Int32 offset, Int32 count, CancellationToken cancellationToken);
  public: ValueTask<> WriteAsync(ReadOnlyMemory<Byte> buffer, CancellationToken cancellationToken);
  private: ValueTask<> WriteToUnderlyingStreamAsync(ReadOnlyMemory<Byte> buffer, CancellationToken cancellationToken, Task<> semaphoreLockTask);
  public: IAsyncResult BeginWrite(Array<Byte> buffer, Int32 offset, Int32 count, AsyncCallback callback, Object state);
  public: void EndWrite(IAsyncResult asyncResult);
  public: void WriteByte(Byte value);
  public: Int64 Seek(Int64 offset, SeekOrigin origin);
  public: void SetLength(Int64 value);
  public: void CopyTo(Stream destination, Int32 bufferSize);
  public: Task<> CopyToAsync(Stream destination, Int32 bufferSize, CancellationToken cancellationToken);
  private: Task<> CopyToAsyncCore(Stream destination, Int32 bufferSize, CancellationToken cancellationToken);
  private: Stream _stream;
  private: Array<Byte> _buffer;
  private: Int32 _bufferSize;
  private: Int32 _readPos;
  private: Int32 _readLen;
  private: Int32 _writePos;
  private: Task<Int32> _lastSyncCompletedReadTask;
  private: SemaphoreSlim _asyncActiveSemaphore;
};
} // namespace BufferedStreamNamespace
using BufferedStream = BufferedStreamNamespace::BufferedStream;
} // namespace System::Private::CoreLib::System::IO
