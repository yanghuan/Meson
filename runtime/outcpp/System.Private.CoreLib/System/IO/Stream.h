#pragma once

#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/MarshalByRefObject.h>
#include <System.Private.CoreLib/System/Object.h>
#include <System.Private.CoreLib/System/Threading/Tasks/Task.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARD(AsyncCallback)
FORWARDS(Byte)
FORWARD(Exception)
FORWARD_(Func, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18)
FORWARD(IAsyncDisposable)
FORWARD(IAsyncResult)
FORWARD(IDisposable)
FORWARDS(Int64)
FORWARDS(Memory, T)
FORWARDS(ReadOnlyMemory, T)
FORWARDS(ReadOnlySpan, T)
FORWARDS(Span, T)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Buffers {
FORWARD(ReadOnlySpanAction, T, TArg)
} // namespace System::Private::CoreLib::System::Buffers
namespace System::Private::CoreLib::System::Threading {
FORWARDS(CancellationToken)
FORWARD_(ContextCallback, T1, T2)
FORWARD(ExecutionContext)
FORWARD(ManualResetEvent)
FORWARD(SemaphoreSlim)
FORWARD(WaitHandle)
} // namespace System::Private::CoreLib::System::Threading
namespace System::Private::CoreLib::System::Threading::Tasks {
FORWARD(ITaskCompletionAction)
FORWARDS_(ValueTask, T1, T2)
} // namespace System::Private::CoreLib::System::Threading::Tasks
namespace System::Private::CoreLib::System::Runtime::ExceptionServices {
FORWARD(ExceptionDispatchInfo)
} // namespace System::Private::CoreLib::System::Runtime::ExceptionServices
namespace System::Private::CoreLib::System::IO {
enum class SeekOrigin : int32_t;
namespace StreamNamespace {
using namespace System::Buffers;
using namespace System::Runtime::ExceptionServices;
using namespace System::Threading;
using namespace System::Threading::Tasks;
CLASS(Stream) : public MarshalByRefObject::in {
  public: using interface = rt::TypeList<IDisposable, IAsyncDisposable>;
  private: struct ReadWriteParameters : public valueType<ReadWriteParameters> {
    public: Array<Byte> Buffer;
    public: Int32 Offset;
    public: Int32 Count;
  };
  private: FRIENDN(WriteCallbackStream)
  private: CLASS(ReadWriteTask) : public Task<Int32>::in {
    public: using interface = rt::TypeList<ITaskCompletionAction>;
    private: Boolean get_InvokeMayRunArbitraryCodeOfITaskCompletionAction();
    public: void ClearBeginState();
    public: void ctor(Boolean isRead, Boolean apm, Func<Object, Int32> function, Object state, Stream stream, Array<Byte> buffer, Int32 offset, Int32 count, AsyncCallback callback);
    private: static void InvokeAsyncCallback(Object completedTask);
    public: Boolean _isRead;
    public: Boolean _apm;
    public: Boolean _endCalled;
    public: Stream _stream;
    public: Array<Byte> _buffer;
    public: Int32 _offset;
    public: Int32 _count;
    private: AsyncCallback _callback;
    private: ExecutionContext _context;
    private: static ContextCallback<> s_invokeAsyncCallback;
  };
  private: FRIENDN(NullStream)
  private: CLASS(SynchronousAsyncResult) : public Object::in {
    public: using interface = rt::TypeList<IAsyncResult>;
    public: Boolean get_IsCompleted();
    public: WaitHandle get_AsyncWaitHandle();
    public: Object get_AsyncState();
    public: Boolean get_CompletedSynchronously();
    public: void ctor(Int32 bytesRead, Object asyncStateObject);
    public: void ctor(Object asyncStateObject);
    public: void ctor(Exception ex, Object asyncStateObject, Boolean isWrite);
    public: void ThrowIfError();
    public: static Int32 EndRead(IAsyncResult asyncResult);
    public: static void EndWrite(IAsyncResult asyncResult);
    private: Object _stateObject;
    private: Boolean _isWrite;
    private: ManualResetEvent _waitHandle;
    private: ExceptionDispatchInfo _exceptionInfo;
    private: Boolean _endXxxCalled;
    private: Int32 _bytesRead;
  };
  private: FRIENDN(SyncStream)
  public: Boolean get_CanRead();
  public: Boolean get_CanSeek();
  public: Boolean get_CanTimeout();
  public: Boolean get_CanWrite();
  public: Int64 get_Length();
  public: Int64 get_Position();
  public: void set_Position(Int64 value);
  public: Int32 get_ReadTimeout();
  public: void set_ReadTimeout(Int32 value);
  public: Int32 get_WriteTimeout();
  public: void set_WriteTimeout(Int32 value);
  private: Boolean HasOverriddenBeginEndRead();
  private: Boolean HasOverriddenBeginEndWrite();
  public: SemaphoreSlim EnsureAsyncActiveSemaphoreInitialized();
  public: Task<> CopyToAsync(Stream destination);
  public: Task<> CopyToAsync(Stream destination, Int32 bufferSize);
  public: Task<> CopyToAsync(Stream destination, CancellationToken cancellationToken);
  public: Task<> CopyToAsync(Stream destination, Int32 bufferSize, CancellationToken cancellationToken);
  private: Task<> CopyToAsyncInternal(Stream destination, Int32 bufferSize, CancellationToken cancellationToken);
  public: void CopyTo(Stream destination);
  public: void CopyTo(Stream destination, Int32 bufferSize);
  private: Int32 GetCopyBufferSize();
  public: void CopyTo(ReadOnlySpanAction<Byte, Object> callback, Object state, Int32 bufferSize);
  public: Task<> CopyToAsync(Func<ReadOnlyMemory<Byte>, Object, CancellationToken, ValueTask<>> callback, Object state, Int32 bufferSize, CancellationToken cancellationToken);
  public: void Close();
  public: void Dispose();
  protected: void Dispose(Boolean disposing);
  public: ValueTask<> DisposeAsync();
  public: void Flush();
  public: Task<> FlushAsync();
  public: Task<> FlushAsync(CancellationToken cancellationToken);
  protected: WaitHandle CreateWaitHandle();
  public: IAsyncResult BeginRead(Array<Byte> buffer, Int32 offset, Int32 count, AsyncCallback callback, Object state);
  public: IAsyncResult BeginReadInternal(Array<Byte> buffer, Int32 offset, Int32 count, AsyncCallback callback, Object state, Boolean serializeAsynchronously, Boolean apm);
  public: Int32 EndRead(IAsyncResult asyncResult);
  public: Task<Int32> ReadAsync(Array<Byte> buffer, Int32 offset, Int32 count);
  public: Task<Int32> ReadAsync(Array<Byte> buffer, Int32 offset, Int32 count, CancellationToken cancellationToken);
  public: template <class T0 = CancellationToken>
  ValueTask<Int32> ReadAsync(Memory<Byte> buffer, T0 cancellationToken = rt::default__);
  private: Task<Int32> BeginEndReadAsync(Array<Byte> buffer, Int32 offset, Int32 count);
  public: IAsyncResult BeginWrite(Array<Byte> buffer, Int32 offset, Int32 count, AsyncCallback callback, Object state);
  public: IAsyncResult BeginWriteInternal(Array<Byte> buffer, Int32 offset, Int32 count, AsyncCallback callback, Object state, Boolean serializeAsynchronously, Boolean apm);
  private: void RunReadWriteTaskWhenReady(Task<> asyncWaiter, ReadWriteTask readWriteTask);
  private: void RunReadWriteTask(ReadWriteTask readWriteTask);
  private: void FinishTrackingAsyncOperation(ReadWriteTask task);
  public: void EndWrite(IAsyncResult asyncResult);
  public: Task<> WriteAsync(Array<Byte> buffer, Int32 offset, Int32 count);
  public: Task<> WriteAsync(Array<Byte> buffer, Int32 offset, Int32 count, CancellationToken cancellationToken);
  public: template <class T0 = CancellationToken>
  ValueTask<> WriteAsync(ReadOnlyMemory<Byte> buffer, T0 cancellationToken = rt::default__);
  private: Task<> FinishWriteAsync(Task<> writeTask, Array<Byte> localBuffer);
  private: Task<> BeginEndWriteAsync(Array<Byte> buffer, Int32 offset, Int32 count);
  public: Int64 Seek(Int64 offset, SeekOrigin origin);
  public: void SetLength(Int64 value);
  public: Int32 Read(Array<Byte> buffer, Int32 offset, Int32 count);
  public: Int32 Read(Span<Byte> buffer);
  public: Int32 ReadByte();
  public: void Write(Array<Byte> buffer, Int32 offset, Int32 count);
  public: void Write(ReadOnlySpan<Byte> buffer);
  public: void WriteByte(Byte value);
  public: static Stream Synchronized(Stream stream);
  protected: void ObjectInvariant();
  public: IAsyncResult BlockingBeginRead(Array<Byte> buffer, Int32 offset, Int32 count, AsyncCallback callback, Object state);
  public: static Int32 BlockingEndRead(IAsyncResult asyncResult);
  public: IAsyncResult BlockingBeginWrite(Array<Byte> buffer, Int32 offset, Int32 count, AsyncCallback callback, Object state);
  public: static void BlockingEndWrite(IAsyncResult asyncResult);
  protected: void ctor();
  private: static void cctor();
  public: static Stream Null;
  private: SemaphoreSlim _asyncActiveSemaphore;
};
CLASS(WriteCallbackStream) : public Stream::in {
  public: Boolean get_CanRead();
  public: Boolean get_CanSeek();
  public: Boolean get_CanWrite();
  public: Int64 get_Length();
  public: Int64 get_Position();
  public: void set_Position(Int64 value);
  public: void ctor(ReadOnlySpanAction<Byte, Object> action, Object state);
  public: void ctor(Func<ReadOnlyMemory<Byte>, Object, CancellationToken, ValueTask<>> func, Object state);
  public: void Write(Array<Byte> buffer, Int32 offset, Int32 count);
  public: void Write(ReadOnlySpan<Byte> span);
  public: Task<> WriteAsync(Array<Byte> buffer, Int32 offset, Int32 length, CancellationToken cancellationToken);
  public: ValueTask<> WriteAsync(ReadOnlyMemory<Byte> buffer, CancellationToken cancellationToken);
  public: void Flush();
  public: Task<> FlushAsync(CancellationToken token);
  public: Int32 Read(Array<Byte> buffer, Int32 offset, Int32 count);
  public: Int64 Seek(Int64 offset, SeekOrigin origin);
  public: void SetLength(Int64 value);
  private: ReadOnlySpanAction<Byte, Object> _action;
  private: Func<ReadOnlyMemory<Byte>, Object, CancellationToken, ValueTask<>> _func;
  private: Object _state;
};
CLASS(NullStream) : public Stream::in {
  public: Boolean get_CanRead();
  public: Boolean get_CanWrite();
  public: Boolean get_CanSeek();
  public: Int64 get_Length();
  public: Int64 get_Position();
  public: void set_Position(Int64 value);
  public: void ctor();
  public: void CopyTo(Stream destination, Int32 bufferSize);
  public: Task<> CopyToAsync(Stream destination, Int32 bufferSize, CancellationToken cancellationToken);
  public: void CopyTo(ReadOnlySpanAction<Byte, Object> callback, Object state, Int32 bufferSize);
  public: Task<> CopyToAsync(Func<ReadOnlyMemory<Byte>, Object, CancellationToken, ValueTask<>> callback, Object state, Int32 bufferSize, CancellationToken cancellationToken);
  protected: void Dispose(Boolean disposing);
  public: void Flush();
  public: Task<> FlushAsync(CancellationToken cancellationToken);
  public: IAsyncResult BeginRead(Array<Byte> buffer, Int32 offset, Int32 count, AsyncCallback callback, Object state);
  public: Int32 EndRead(IAsyncResult asyncResult);
  public: IAsyncResult BeginWrite(Array<Byte> buffer, Int32 offset, Int32 count, AsyncCallback callback, Object state);
  public: void EndWrite(IAsyncResult asyncResult);
  public: Int32 Read(Array<Byte> buffer, Int32 offset, Int32 count);
  public: Int32 Read(Span<Byte> buffer);
  public: Task<Int32> ReadAsync(Array<Byte> buffer, Int32 offset, Int32 count, CancellationToken cancellationToken);
  public: template <class T0 = CancellationToken>
  ValueTask<Int32> ReadAsync(Memory<Byte> buffer, T0 cancellationToken = rt::default__);
  public: Int32 ReadByte();
  public: void Write(Array<Byte> buffer, Int32 offset, Int32 count);
  public: void Write(ReadOnlySpan<Byte> buffer);
  public: Task<> WriteAsync(Array<Byte> buffer, Int32 offset, Int32 count, CancellationToken cancellationToken);
  public: template <class T0 = CancellationToken>
  ValueTask<> WriteAsync(ReadOnlyMemory<Byte> buffer, T0 cancellationToken = rt::default__);
  public: void WriteByte(Byte value);
  public: Int64 Seek(Int64 offset, SeekOrigin origin);
  public: void SetLength(Int64 length);
  private: static void cctor();
  private: static Task<Int32> s_zeroTask;
};
CLASS(SyncStream) : public Stream::in {
  public: using interface = rt::TypeList<IDisposable>;
  public: Boolean get_CanRead();
  public: Boolean get_CanWrite();
  public: Boolean get_CanSeek();
  public: Boolean get_CanTimeout();
  public: Int64 get_Length();
  public: Int64 get_Position();
  public: void set_Position(Int64 value);
  public: Int32 get_ReadTimeout();
  public: void set_ReadTimeout(Int32 value);
  public: Int32 get_WriteTimeout();
  public: void set_WriteTimeout(Int32 value);
  public: void ctor(Stream stream);
  public: void Close();
  protected: void Dispose(Boolean disposing);
  public: ValueTask<> DisposeAsync();
  public: void Flush();
  public: Int32 Read(Array<Byte> bytes, Int32 offset, Int32 count);
  public: Int32 Read(Span<Byte> buffer);
  public: Int32 ReadByte();
  public: IAsyncResult BeginRead(Array<Byte> buffer, Int32 offset, Int32 count, AsyncCallback callback, Object state);
  public: Int32 EndRead(IAsyncResult asyncResult);
  public: Int64 Seek(Int64 offset, SeekOrigin origin);
  public: void SetLength(Int64 length);
  public: void Write(Array<Byte> bytes, Int32 offset, Int32 count);
  public: void Write(ReadOnlySpan<Byte> buffer);
  public: void WriteByte(Byte b);
  public: IAsyncResult BeginWrite(Array<Byte> buffer, Int32 offset, Int32 count, AsyncCallback callback, Object state);
  public: void EndWrite(IAsyncResult asyncResult);
  private: Stream _stream;
};
} // namespace StreamNamespace
using Stream = StreamNamespace::Stream;
} // namespace System::Private::CoreLib::System::IO
