#pragma once

#include <System.Private.CoreLib/System/ArraySegment.h>
#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/Byte.h>
#include <System.Private.CoreLib/System/Char.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/IO/Stream.h>
#include <System.Private.CoreLib/System/Memory.h>
#include <System.Private.CoreLib/System/ReadOnlyMemory.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/AsyncValueTaskMethodBuilder.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/ConfiguredValueTaskAwaitable.h>
#include <System.Private.CoreLib/System/Threading/CancellationToken.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System::Runtime::CompilerServices {
FORWARD(IAsyncStateMachine)
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
namespace System::Private::CoreLib::System {
FORWARD_(Array)
FORWARD(AsyncCallback)
FORWARD(IAsyncResult)
FORWARDS(Int64)
FORWARD(Object)
FORWARDS(ReadOnlySpan, T)
FORWARDS(Span, T)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading::Tasks {
FORWARD_(Task)
FORWARDS_(ValueTask)
} // namespace System::Private::CoreLib::System::Threading::Tasks
namespace System::Private::CoreLib::System::IO {
enum class SeekOrigin : int32_t;
} // namespace System::Private::CoreLib::System::IO
namespace System::Private::CoreLib::System::Text {
FORWARD(Decoder)
FORWARD(Encoder)
FORWARD(Encoding)
namespace TranscodingStreamNamespace {
using namespace System::IO;
using namespace System::Runtime::CompilerServices;
using namespace System::Threading;
using namespace System::Threading::Tasks;
CLASS(TranscodingStream) : public Stream::in {
  private: struct __DisposeAsync_g__DisposeAsyncCore30_0_d : public valueType<__DisposeAsync_g__DisposeAsyncCore30_0_d> {
    public: using interface = rt::TypeList<IAsyncStateMachine>;
    private: void MoveNext();
    private: void SetStateMachine(IAsyncStateMachine stateMachine);
    public: Int32 __1__state;
    public: AsyncValueTaskMethodBuilder<> __t__builder;
    public: TranscodingStream __4__this;
    public: ArraySegment<Byte> pendingData;
    private: Stream _innerStream_5__2;
    private: ConfiguredValueTaskAwaitable<>::ConfiguredValueTaskAwaiter __u__1;
  };
  private: struct __ReadAsync_g__ReadAsyncCore41_0_d : public valueType<__ReadAsync_g__ReadAsyncCore41_0_d> {
    public: using interface = rt::TypeList<IAsyncStateMachine>;
    private: void MoveNext();
    private: void SetStateMachine(IAsyncStateMachine stateMachine);
    public: Int32 __1__state;
    public: AsyncValueTaskMethodBuilder<Int32> __t__builder;
    public: TranscodingStream __4__this;
    public: CancellationToken cancellationToken;
    public: Memory<Byte> buffer;
    private: Array<Byte> _rentedBytes_5__2;
    private: Array<Char> _rentedChars_5__3;
    private: ConfiguredValueTaskAwaitable<Int32>::ConfiguredValueTaskAwaiter __u__1;
  };
  private: struct __WriteAsync_g__WriteAsyncCore50_0_d : public valueType<__WriteAsync_g__WriteAsyncCore50_0_d> {
    public: using interface = rt::TypeList<IAsyncStateMachine>;
    private: void MoveNext();
    private: void SetStateMachine(IAsyncStateMachine stateMachine);
    public: Int32 __1__state;
    public: AsyncValueTaskMethodBuilder<> __t__builder;
    public: ReadOnlyMemory<Byte> remainingOuterEncodedBytes;
    public: TranscodingStream __4__this;
    public: CancellationToken cancellationToken;
    private: Array<Char> _scratchChars_5__2;
    private: Array<Byte> _scratchBytes_5__3;
    private: Boolean _decoderFinished_5__4;
    private: Boolean _encoderFinished_5__5;
    private: ArraySegment<Char> _decodedChars_5__6;
    private: ConfiguredValueTaskAwaitable<>::ConfiguredValueTaskAwaiter __u__1;
  };
  public: Boolean get_CanRead();
  public: Boolean get_CanSeek();
  public: Boolean get_CanWrite();
  public: Int64 get_Length();
  public: Int64 get_Position();
  public: void set_Position(Int64 value);
  public: void ctor(Stream innerStream, Encoding innerEncoding, Encoding thisEncoding, Boolean leaveOpen);
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
  private: ValueTask<> _DisposeAsync_g__DisposeAsyncCore30_0(ArraySegment<Byte> pendingData);
  private: void _EnsurePreReadConditions_g__InitializeReadDataStructures33_0();
  private: void _EnsurePreWriteConditions_g__InitializeReadDataStructures34_0();
  private: ValueTask<Int32> _ReadAsync_g__ReadAsyncCore41_0(Memory<Byte> buffer, CancellationToken cancellationToken);
  private: ValueTask<> _WriteAsync_g__WriteAsyncCore50_0(ReadOnlyMemory<Byte> remainingOuterEncodedBytes, CancellationToken cancellationToken);
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
