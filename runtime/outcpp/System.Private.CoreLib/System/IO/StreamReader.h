#pragma once

#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/Char.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/IO/TextReader.h>
#include <System.Private.CoreLib/System/Memory.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/AsyncTaskMethodBuilder.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/AsyncValueTaskMethodBuilder.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/ConfiguredValueTaskAwaitable.h>
#include <System.Private.CoreLib/System/Threading/CancellationToken.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System::Text {
FORWARD(Decoder)
FORWARD(Encoding)
FORWARD(StringBuilder)
} // namespace System::Private::CoreLib::System::Text
namespace System::Private::CoreLib::System {
FORWARD_(Array)
FORWARDS(Byte)
FORWARDS(Span, T)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::CompilerServices {
FORWARD(IAsyncStateMachine)
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
namespace System::Private::CoreLib::System::Threading::Tasks {
FORWARD_(Task)
FORWARDS_(ValueTask)
} // namespace System::Private::CoreLib::System::Threading::Tasks
namespace System::Private::CoreLib::System::IO {
FORWARD(Stream)
namespace StreamReaderNamespace {
using namespace System::Runtime::CompilerServices;
using namespace System::Text;
using namespace System::Threading;
using namespace System::Threading::Tasks;
CLASS(StreamReader) : public TextReader::in {
  private: FRIENDN(NullStreamReader)
  private: struct _ReadLineAsyncInternal_d__59 : public valueType<_ReadLineAsyncInternal_d__59> {
    public: using interface = rt::TypeList<IAsyncStateMachine>;
    private: void MoveNext();
    private: void SetStateMachine(IAsyncStateMachine stateMachine);
    public: Int32 __1__state;
    public: AsyncTaskMethodBuilder<String> __t__builder;
    public: StreamReader __4__this;
    private: StringBuilder _sb_5__2;
    private: ConfiguredValueTaskAwaitable<Int32>::ConfiguredValueTaskAwaiter __u__1;
    private: String _s_5__3;
  };
  private: struct _ReadToEndAsyncInternal_d__61 : public valueType<_ReadToEndAsyncInternal_d__61> {
    public: using interface = rt::TypeList<IAsyncStateMachine>;
    private: void MoveNext();
    private: void SetStateMachine(IAsyncStateMachine stateMachine);
    public: Int32 __1__state;
    public: AsyncTaskMethodBuilder<String> __t__builder;
    public: StreamReader __4__this;
    private: StringBuilder _sb_5__2;
    private: ConfiguredValueTaskAwaitable<Int32>::ConfiguredValueTaskAwaiter __u__1;
  };
  private: struct _ReadAsyncInternal_d__64 : public valueType<_ReadAsyncInternal_d__64> {
    public: using interface = rt::TypeList<IAsyncStateMachine>;
    private: void MoveNext();
    private: void SetStateMachine(IAsyncStateMachine stateMachine);
    public: Int32 __1__state;
    public: AsyncValueTaskMethodBuilder<Int32> __t__builder;
    public: StreamReader __4__this;
    public: CancellationToken cancellationToken;
    public: Memory<Char> buffer;
    private: Int32 _charsRead_5__2;
    private: Boolean _readToUserBuffer_5__3;
    private: Array<Byte> _tmpByteBuffer_5__4;
    private: Stream _tmpStream_5__5;
    private: Int32 _count_5__6;
    private: ConfiguredValueTaskAwaitable<Int32>::ConfiguredValueTaskAwaiter __u__1;
    private: Int32 _n_5__7;
  };
  private: struct _ReadBufferAsync_d__67 : public valueType<_ReadBufferAsync_d__67> {
    public: using interface = rt::TypeList<IAsyncStateMachine>;
    private: void MoveNext();
    private: void SetStateMachine(IAsyncStateMachine stateMachine);
    public: Int32 __1__state;
    public: AsyncValueTaskMethodBuilder<Int32> __t__builder;
    public: StreamReader __4__this;
    public: CancellationToken cancellationToken;
    private: Array<Byte> _tmpByteBuffer_5__2;
    private: Stream _tmpStream_5__3;
    private: ConfiguredValueTaskAwaitable<Int32>::ConfiguredValueTaskAwaiter __u__1;
  };
  public: Encoding get_CurrentEncoding();
  public: Stream get_BaseStream();
  public: Boolean get_EndOfStream();
  private: void CheckAsyncTaskInProgress();
  private: static void ThrowAsyncIOInProgress();
  public: void ctor();
  public: void ctor(Stream stream);
  public: void ctor(Stream stream, Boolean detectEncodingFromByteOrderMarks);
  public: void ctor(Stream stream, Encoding encoding);
  public: void ctor(Stream stream, Encoding encoding, Boolean detectEncodingFromByteOrderMarks);
  public: void ctor(Stream stream, Encoding encoding, Boolean detectEncodingFromByteOrderMarks, Int32 bufferSize);
  public: void ctor(Stream stream, Encoding encoding = nullptr, Boolean detectEncodingFromByteOrderMarks = true, Int32 bufferSize = -1, Boolean leaveOpen = false);
  public: void ctor(String path);
  public: void ctor(String path, Boolean detectEncodingFromByteOrderMarks);
  public: void ctor(String path, Encoding encoding);
  public: void ctor(String path, Encoding encoding, Boolean detectEncodingFromByteOrderMarks);
  public: void ctor(String path, Encoding encoding, Boolean detectEncodingFromByteOrderMarks, Int32 bufferSize);
  private: static Stream ValidateArgsAndOpenPath(String path, Encoding encoding, Int32 bufferSize);
  public: void Close();
  protected: void Dispose(Boolean disposing);
  public: void DiscardBufferedData();
  public: Int32 Peek();
  public: Int32 Read();
  public: Int32 Read(Array<Char> buffer, Int32 index, Int32 count);
  public: Int32 Read(Span<Char> buffer);
  private: Int32 ReadSpan(Span<Char> buffer);
  public: String ReadToEnd();
  public: Int32 ReadBlock(Array<Char> buffer, Int32 index, Int32 count);
  public: Int32 ReadBlock(Span<Char> buffer);
  private: void CompressBuffer(Int32 n);
  private: void DetectEncoding();
  private: Boolean IsPreamble();
  public: Int32 ReadBuffer();
  private: Int32 ReadBuffer(Span<Char> userBuffer, Boolean& readToUserBuffer);
  public: String ReadLine();
  public: Task<String> ReadLineAsync();
  private: Task<String> ReadLineAsyncInternal();
  public: Task<String> ReadToEndAsync();
  private: Task<String> ReadToEndAsyncInternal();
  public: Task<Int32> ReadAsync(Array<Char> buffer, Int32 index, Int32 count);
  public: template <class T0 = CancellationToken>
  ValueTask<Int32> ReadAsync(Memory<Char> buffer, T0 cancellationToken = rt::default__);
  public: ValueTask<Int32> ReadAsyncInternal(Memory<Char> buffer, CancellationToken cancellationToken);
  public: Task<Int32> ReadBlockAsync(Array<Char> buffer, Int32 index, Int32 count);
  public: template <class T0 = CancellationToken>
  ValueTask<Int32> ReadBlockAsync(Memory<Char> buffer, T0 cancellationToken = rt::default__);
  private: ValueTask<Int32> ReadBufferAsync(CancellationToken cancellationToken);
  private: void ThrowIfDisposed();
  public: static void cctor();
  private: void _ThrowIfDisposed_g__ThrowObjectDisposedException68_0();
  public: static StreamReader Null;
  private: Stream _stream;
  private: Encoding _encoding;
  private: Decoder _decoder;
  private: Array<Byte> _byteBuffer;
  private: Array<Char> _charBuffer;
  private: Int32 _charPos;
  private: Int32 _charLen;
  private: Int32 _byteLen;
  private: Int32 _bytePos;
  private: Int32 _maxCharsPerBuffer;
  private: Boolean _disposed;
  private: Boolean _detectEncoding;
  private: Boolean _checkPreamble;
  private: Boolean _isBlocked;
  private: Boolean _closable;
  private: Task<> _asyncReadTask;
};
CLASS(NullStreamReader) : public StreamReader::in {
  public: Encoding get_CurrentEncoding();
  protected: void Dispose(Boolean disposing);
  public: Int32 Peek();
  public: Int32 Read();
  public: Int32 Read(Array<Char> buffer, Int32 index, Int32 count);
  public: String ReadLine();
  public: String ReadToEnd();
  public: Int32 ReadBuffer();
  public: void ctor();
};
} // namespace StreamReaderNamespace
using StreamReader = StreamReaderNamespace::StreamReader;
} // namespace System::Private::CoreLib::System::IO
