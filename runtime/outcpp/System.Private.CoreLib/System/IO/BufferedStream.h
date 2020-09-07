#pragma once

#include <System.Private.CoreLib/System/Byte.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/IO/Stream.h>
#include <System.Private.CoreLib/System/Memory.h>
#include <System.Private.CoreLib/System/Object.h>
#include <System.Private.CoreLib/System/ReadOnlyMemory.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/AsyncTaskMethodBuilder.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/AsyncValueTaskMethodBuilder.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/ConfiguredTaskAwaitable.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/ConfiguredValueTaskAwaitable.h>
#include <System.Private.CoreLib/System/Threading/CancellationToken.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System::Threading {
FORWARD(SemaphoreSlim)
} // namespace System::Private::CoreLib::System::Threading
namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARD(AsyncCallback)
FORWARDS(Boolean)
FORWARD(Exception)
FORWARD_(Func, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18)
FORWARD(IAsyncResult)
FORWARDS(Int64)
FORWARDS(ReadOnlySpan, T)
FORWARDS(Span, T)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::CompilerServices {
FORWARD(IAsyncStateMachine)
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
namespace System::Private::CoreLib::System::Threading::Tasks {
FORWARD_(Task, T1, T2)
FORWARDS_(ValueTask, T1, T2)
} // namespace System::Private::CoreLib::System::Threading::Tasks
namespace System::Private::CoreLib::System::IO {
enum class SeekOrigin : int32_t;
namespace BufferedStreamNamespace {
using namespace System::Runtime::CompilerServices;
using namespace System::Threading;
using namespace System::Threading::Tasks;
CLASS(BufferedStream) : public Stream::in {
  private: CLASS(__c) : public object {
    public: static void cctor();
    public: void ctor();
    public: SemaphoreSlim _LazyEnsureAsyncActiveSemaphoreInitialized_b__10_0();
    public: static __c __9;
    public: static Func<SemaphoreSlim> __9__10_0;
  };
  private: struct _DisposeAsync_d__35 : public valueType<_DisposeAsync_d__35> {
    public: using interface = rt::TypeList<IAsyncStateMachine>;
    private: void MoveNext();
    private: void SetStateMachine(IAsyncStateMachine stateMachine);
    public: Int32 __1__state;
    public: AsyncValueTaskMethodBuilder<> __t__builder;
    public: BufferedStream __4__this;
    private: Object __7__wrap1;
    private: Int32 __7__wrap2;
    private: ConfiguredTaskAwaitable<>::ConfiguredTaskAwaiter __u__1;
    private: ConfiguredValueTaskAwaitable<>::ConfiguredValueTaskAwaiter __u__2;
  };
  private: struct _FlushAsyncInternal_d__38 : public valueType<_FlushAsyncInternal_d__38> {
    public: using interface = rt::TypeList<IAsyncStateMachine>;
    private: void MoveNext();
    private: void SetStateMachine(IAsyncStateMachine stateMachine);
    public: Int32 __1__state;
    public: AsyncTaskMethodBuilder<> __t__builder;
    public: BufferedStream __4__this;
    public: CancellationToken cancellationToken;
    private: SemaphoreSlim _sem_5__2;
    private: ConfiguredTaskAwaitable<>::ConfiguredTaskAwaiter __u__1;
    private: ConfiguredValueTaskAwaitable<>::ConfiguredValueTaskAwaiter __u__2;
  };
  private: struct _FlushWriteAsync_d__42 : public valueType<_FlushWriteAsync_d__42> {
    public: using interface = rt::TypeList<IAsyncStateMachine>;
    private: void MoveNext();
    private: void SetStateMachine(IAsyncStateMachine stateMachine);
    public: Int32 __1__state;
    public: AsyncValueTaskMethodBuilder<> __t__builder;
    public: BufferedStream __4__this;
    public: CancellationToken cancellationToken;
    private: ConfiguredValueTaskAwaitable<>::ConfiguredValueTaskAwaiter __u__1;
    private: ConfiguredTaskAwaitable<>::ConfiguredTaskAwaiter __u__2;
  };
  private: struct _ReadFromUnderlyingStreamAsync_d__51 : public valueType<_ReadFromUnderlyingStreamAsync_d__51> {
    public: using interface = rt::TypeList<IAsyncStateMachine>;
    private: void MoveNext();
    private: void SetStateMachine(IAsyncStateMachine stateMachine);
    public: Int32 __1__state;
    public: AsyncValueTaskMethodBuilder<Int32> __t__builder;
    public: Task<> semaphoreLockTask;
    public: BufferedStream __4__this;
    public: Memory<Byte> buffer;
    public: Int32 bytesAlreadySatisfied;
    public: CancellationToken cancellationToken;
    private: ConfiguredTaskAwaitable<>::ConfiguredTaskAwaiter __u__1;
    private: ConfiguredValueTaskAwaitable<>::ConfiguredValueTaskAwaiter __u__2;
    private: Int32 __7__wrap1;
    private: ConfiguredValueTaskAwaitable<Int32>::ConfiguredValueTaskAwaiter __u__3;
  };
  private: struct _WriteToUnderlyingStreamAsync_d__62 : public valueType<_WriteToUnderlyingStreamAsync_d__62> {
    public: using interface = rt::TypeList<IAsyncStateMachine>;
    private: void MoveNext();
    private: void SetStateMachine(IAsyncStateMachine stateMachine);
    public: Int32 __1__state;
    public: AsyncValueTaskMethodBuilder<> __t__builder;
    public: Task<> semaphoreLockTask;
    public: BufferedStream __4__this;
    public: ReadOnlyMemory<Byte> buffer;
    public: CancellationToken cancellationToken;
    private: ConfiguredTaskAwaitable<>::ConfiguredTaskAwaiter __u__1;
    private: ConfiguredValueTaskAwaitable<>::ConfiguredValueTaskAwaiter __u__2;
  };
  private: struct _CopyToAsyncCore_d__70 : public valueType<_CopyToAsyncCore_d__70> {
    public: using interface = rt::TypeList<IAsyncStateMachine>;
    private: void MoveNext();
    private: void SetStateMachine(IAsyncStateMachine stateMachine);
    public: Int32 __1__state;
    public: AsyncTaskMethodBuilder<> __t__builder;
    public: BufferedStream __4__this;
    public: CancellationToken cancellationToken;
    public: Stream destination;
    public: Int32 bufferSize;
    private: ConfiguredTaskAwaitable<>::ConfiguredTaskAwaiter __u__1;
    private: ConfiguredValueTaskAwaitable<>::ConfiguredValueTaskAwaiter __u__2;
  };
  public: Stream get_UnderlyingStream();
  public: Int32 get_BufferSize();
  public: Boolean get_CanRead();
  public: Boolean get_CanWrite();
  public: Boolean get_CanSeek();
  public: Int64 get_Length();
  public: Int64 get_Position();
  public: void set_Position(Int64 value);
  public: SemaphoreSlim LazyEnsureAsyncActiveSemaphoreInitialized();
  public: void ctor(Stream stream);
  public: void ctor(Stream stream, Int32 bufferSize);
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
  public: template <class T0 = CancellationToken>
  ValueTask<Int32> ReadAsync(Memory<Byte> buffer, T0 cancellationToken = rt::default__);
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
  public: template <class T0 = CancellationToken>
  ValueTask<> WriteAsync(ReadOnlyMemory<Byte> buffer, T0 cancellationToken = rt::default__);
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
