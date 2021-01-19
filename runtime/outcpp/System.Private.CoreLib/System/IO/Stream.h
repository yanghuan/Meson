#pragma once

#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/Byte.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/MarshalByRefObject.h>
#include <System.Private.CoreLib/System/Memory.h>
#include <System.Private.CoreLib/System/Object.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/AsyncTaskMethodBuilder.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/AsyncValueTaskMethodBuilder.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/ConfiguredTaskAwaitable.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/ConfiguredValueTaskAwaitable.h>
#include <System.Private.CoreLib/System/Threading/CancellationToken.h>
#include <System.Private.CoreLib/System/Threading/Tasks/Task.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System {
FORWARD_(Action, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17)
FORWARD_(Array, T1, T2)
FORWARD(AsyncCallback)
FORWARD(Exception)
FORWARD_(Func, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18)
FORWARD(IAsyncDisposable)
FORWARD(IAsyncResult)
FORWARD(IDisposable)
FORWARDS(Int64)
FORWARDS(ReadOnlyMemory, T)
FORWARDS(ReadOnlySpan, T)
FORWARDS(Span, T)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading::Tasks {
FORWARD(ITaskCompletionAction)
FORWARDS_(ValueTask, T1, T2)
FORWARDS(VoidTaskResult)
} // namespace System::Private::CoreLib::System::Threading::Tasks
namespace System::Private::CoreLib::System::Threading {
FORWARD(ContextCallback)
FORWARD(ExecutionContext)
FORWARD(ManualResetEvent)
FORWARD(SemaphoreSlim)
FORWARD(WaitHandle)
} // namespace System::Private::CoreLib::System::Threading
namespace System::Private::CoreLib::System::Runtime::ExceptionServices {
FORWARD(ExceptionDispatchInfo)
} // namespace System::Private::CoreLib::System::Runtime::ExceptionServices
namespace System::Private::CoreLib::System::Runtime::CompilerServices {
FORWARD(IAsyncStateMachine)
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
namespace System::Private::CoreLib::System::IO {
enum class SeekOrigin : int32_t;
namespace StreamNamespace {
using namespace System::Runtime::CompilerServices;
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
  private: CLASS(ReadWriteTask) : public Task<Int32>::in {
    public: using interface = rt::TypeList<ITaskCompletionAction>;
    private: Boolean get_InvokeMayRunArbitraryCodeOfITaskCompletionAction();
    public: void ClearBeginState();
    public: void ctor(Boolean isRead, Boolean apm, Func<Object, Int32> function, Object state, Stream stream, Array<Byte> buffer, Int32 offset, Int32 count, AsyncCallback callback);
    private: static void InvokeAsyncCallback(Object completedTask);
    private: void InvokeOfITaskCompletionAction(Task<> completingTask);
    public: Boolean _isRead;
    public: Boolean _apm;
    public: Boolean _endCalled;
    public: Stream _stream;
    public: Array<Byte> _buffer;
    public: Int32 _offset;
    public: Int32 _count;
    private: AsyncCallback _callback;
    private: ExecutionContext _context;
    private: static ContextCallback s_invokeAsyncCallback;
  };
  private: FRIENDN(NullStream)
  private: CLASS(SynchronousAsyncResult) : public object {
    public: using interface = rt::TypeList<IAsyncResult>;
    private: CLASS(__c) : public object {
      public: static void cctor();
      public: void ctor();
      public: ManualResetEvent _get_AsyncWaitHandle_b__12_0();
      public: static __c __9;
      public: static Func<ManualResetEvent> __9__12_0;
    };
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
  private: CLASS(__c) : public object {
    public: static void cctor();
    public: void ctor();
    public: SemaphoreSlim _EnsureAsyncActiveSemaphoreInitialized_b__5_0();
    public: void _FlushAsync_b__39_0(Object state);
    public: Int32 _BeginReadInternal_b__42_0(Object _p0_);
    public: IAsyncResult _BeginEndReadAsync_b__47_0(Stream stream, ReadWriteParameters args, AsyncCallback callback, Object state);
    public: Int32 _BeginEndReadAsync_b__47_1(Stream stream, IAsyncResult asyncResult);
    public: Int32 _BeginWriteInternal_b__50_0(Object _p0_);
    public: void _RunReadWriteTaskWhenReady_b__51_0(Task<> t, Object state);
    public: IAsyncResult _BeginEndWriteAsync_b__60_0(Stream stream, ReadWriteParameters args, AsyncCallback callback, Object state);
    public: VoidTaskResult _BeginEndWriteAsync_b__60_1(Stream stream, IAsyncResult asyncResult);
    public: static __c __9;
    public: static Func<SemaphoreSlim> __9__5_0;
    public: static Action<Object> __9__39_0;
    public: static Func<Object, Int32> __9__42_0;
    public: static Func<Stream, ReadWriteParameters, AsyncCallback, Object, IAsyncResult> __9__47_0;
    public: static Func<Stream, IAsyncResult, Int32> __9__47_1;
    public: static Func<Object, Int32> __9__50_0;
    public: static Action<Task<>, Object> __9__51_0;
    public: static Func<Stream, ReadWriteParameters, AsyncCallback, Object, IAsyncResult> __9__60_0;
    public: static Func<Stream, IAsyncResult, VoidTaskResult> __9__60_1;
  };
  private: struct _CopyToAsyncInternal_d__29 : public valueType<_CopyToAsyncInternal_d__29> {
    public: using interface = rt::TypeList<IAsyncStateMachine>;
    private: void MoveNext();
    private: void SetStateMachine(IAsyncStateMachine stateMachine);
    public: Int32 __1__state;
    public: AsyncTaskMethodBuilder<> __t__builder;
    public: Int32 bufferSize;
    public: Stream __4__this;
    public: CancellationToken cancellationToken;
    public: Stream destination;
    private: Array<Byte> _buffer_5__2;
    private: ConfiguredValueTaskAwaitable<Int32>::ConfiguredValueTaskAwaiter __u__1;
    private: ConfiguredValueTaskAwaitable<>::ConfiguredValueTaskAwaiter __u__2;
  };
  private: struct _FinishWriteAsync_d__59 : public valueType<_FinishWriteAsync_d__59> {
    public: using interface = rt::TypeList<IAsyncStateMachine>;
    private: void MoveNext();
    private: void SetStateMachine(IAsyncStateMachine stateMachine);
    public: Int32 __1__state;
    public: AsyncTaskMethodBuilder<> __t__builder;
    public: Task<> writeTask;
    public: Array<Byte> localBuffer;
    private: ConfiguredTaskAwaitable<>::ConfiguredTaskAwaiter __u__1;
  };
  private: struct __ReadAsync_g__FinishReadAsync46_0_d : public valueType<__ReadAsync_g__FinishReadAsync46_0_d> {
    public: using interface = rt::TypeList<IAsyncStateMachine>;
    private: void MoveNext();
    private: void SetStateMachine(IAsyncStateMachine stateMachine);
    public: Int32 __1__state;
    public: AsyncValueTaskMethodBuilder<Int32> __t__builder;
    public: Task<Int32> readTask;
    public: Array<Byte> localBuffer;
    public: Memory<Byte> localDestination;
    private: ConfiguredTaskAwaitable<Int32>::ConfiguredTaskAwaiter __u__1;
  };
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
  public: void ctor();
  public: static void cctor();
  public: static ValueTask<Int32> _ReadAsync_g__FinishReadAsync46_0(Task<Int32> readTask, Array<Byte> localBuffer, Memory<Byte> localDestination);
  public: static Stream Null;
  private: SemaphoreSlim _asyncActiveSemaphore;
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
  public: static void cctor();
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
