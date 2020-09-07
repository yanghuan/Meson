#pragma once

#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/Char.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/IO/TextWriter.h>
#include <System.Private.CoreLib/System/ReadOnlyMemory.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/AsyncTaskMethodBuilder.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/AsyncValueTaskMethodBuilder.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/ConfiguredTaskAwaitable.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/ConfiguredValueTaskAwaitable.h>
#include <System.Private.CoreLib/System/Threading/CancellationToken.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System::Runtime::CompilerServices {
FORWARD(IAsyncStateMachine)
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Byte)
FORWARD(Object)
FORWARDS(ParamsArray)
FORWARDS(ReadOnlySpan, T)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Text {
FORWARD(Encoder)
FORWARD(Encoding)
} // namespace System::Private::CoreLib::System::Text
namespace System::Private::CoreLib::System::Threading::Tasks {
FORWARD_(Task, T1, T2)
FORWARDS_(ValueTask, T1, T2)
} // namespace System::Private::CoreLib::System::Threading::Tasks
namespace System::Private::CoreLib::System::IO {
FORWARD(Stream)
namespace StreamWriterNamespace {
using namespace System::Runtime::CompilerServices;
using namespace System::Text;
using namespace System::Threading;
using namespace System::Threading::Tasks;
CLASS(StreamWriter) : public TextWriter::in {
  private: struct _DisposeAsyncCore_d__33 : public valueType<_DisposeAsyncCore_d__33> {
    public: using interface = rt::TypeList<IAsyncStateMachine>;
    private: void MoveNext();
    private: void SetStateMachine(IAsyncStateMachine stateMachine);
    public: Int32 __1__state;
    public: AsyncValueTaskMethodBuilder<> __t__builder;
    public: StreamWriter __4__this;
    private: ConfiguredTaskAwaitable<>::ConfiguredTaskAwaiter __u__1;
  };
  private: struct _WriteAsyncInternal_d__61 : public valueType<_WriteAsyncInternal_d__61> {
    public: using interface = rt::TypeList<IAsyncStateMachine>;
    private: void MoveNext();
    private: void SetStateMachine(IAsyncStateMachine stateMachine);
    public: Int32 __1__state;
    public: AsyncTaskMethodBuilder<> __t__builder;
    public: Int32 charPos;
    public: Int32 charLen;
    public: StreamWriter _this;
    public: Array<Char> charBuffer;
    public: Char value;
    public: Boolean appendNewLine;
    public: Array<Char> coreNewLine;
    public: Boolean autoFlush;
    private: ConfiguredTaskAwaitable<>::ConfiguredTaskAwaiter __u__1;
    private: Int32 _i_5__2;
  };
  private: struct _WriteAsyncInternal_d__63 : public valueType<_WriteAsyncInternal_d__63> {
    public: using interface = rt::TypeList<IAsyncStateMachine>;
    private: void MoveNext();
    private: void SetStateMachine(IAsyncStateMachine stateMachine);
    public: Int32 __1__state;
    public: AsyncTaskMethodBuilder<> __t__builder;
    public: String value;
    public: Int32 charPos;
    public: Int32 charLen;
    public: StreamWriter _this;
    public: Array<Char> charBuffer;
    public: Boolean appendNewLine;
    public: Array<Char> coreNewLine;
    public: Boolean autoFlush;
    private: Int32 _count_5__2;
    private: Int32 _index_5__3;
    private: ConfiguredTaskAwaitable<>::ConfiguredTaskAwaiter __u__1;
    private: Int32 _i_5__4;
  };
  private: struct _WriteAsyncInternal_d__66 : public valueType<_WriteAsyncInternal_d__66> {
    public: using interface = rt::TypeList<IAsyncStateMachine>;
    private: void MoveNext();
    private: void SetStateMachine(IAsyncStateMachine stateMachine);
    public: Int32 __1__state;
    public: AsyncTaskMethodBuilder<> __t__builder;
    public: Int32 charPos;
    public: Int32 charLen;
    public: StreamWriter _this;
    public: Array<Char> charBuffer;
    public: CancellationToken cancellationToken;
    public: ReadOnlyMemory<Char> source;
    public: Boolean appendNewLine;
    public: Array<Char> coreNewLine;
    public: Boolean autoFlush;
    private: Int32 _copied_5__2;
    private: ConfiguredTaskAwaitable<>::ConfiguredTaskAwaiter __u__1;
    private: Int32 _i_5__3;
  };
  private: struct _FlushAsyncInternal_d__74 : public valueType<_FlushAsyncInternal_d__74> {
    public: using interface = rt::TypeList<IAsyncStateMachine>;
    private: void MoveNext();
    private: void SetStateMachine(IAsyncStateMachine stateMachine);
    public: Int32 __1__state;
    public: AsyncTaskMethodBuilder<> __t__builder;
    public: Boolean haveWrittenPreamble;
    public: StreamWriter _this;
    public: Encoding encoding;
    public: Stream stream;
    public: CancellationToken cancellationToken;
    public: Encoder encoder;
    public: Array<Char> charBuffer;
    public: Int32 charPos;
    public: Array<Byte> byteBuffer;
    public: Boolean flushEncoder;
    public: Boolean flushStream;
    private: ConfiguredValueTaskAwaitable<>::ConfiguredValueTaskAwaiter __u__1;
    private: ConfiguredTaskAwaitable<>::ConfiguredTaskAwaiter __u__2;
  };
  private: static Encoding get_UTF8NoBOM();
  public: Boolean get_AutoFlush();
  public: void set_AutoFlush(Boolean value);
  public: Stream get_BaseStream();
  public: Encoding get_Encoding();
  private: void CheckAsyncTaskInProgress();
  private: static void ThrowAsyncIOInProgress();
  public: void ctor(Stream stream);
  public: void ctor(Stream stream, Encoding encoding);
  public: void ctor(Stream stream, Encoding encoding, Int32 bufferSize);
  public: void ctor(Stream stream, Encoding encoding = nullptr, Int32 bufferSize = -1, Boolean leaveOpen = false);
  public: void ctor(String path);
  public: void ctor(String path, Boolean append);
  public: void ctor(String path, Boolean append, Encoding encoding);
  public: void ctor(String path, Boolean append, Encoding encoding, Int32 bufferSize);
  private: static Stream ValidateArgsAndOpenPath(String path, Boolean append, Encoding encoding, Int32 bufferSize);
  public: void Close();
  protected: void Dispose(Boolean disposing);
  private: void CloseStreamFromDispose(Boolean disposing);
  public: ValueTask<> DisposeAsync();
  private: ValueTask<> DisposeAsyncCore();
  public: void Flush();
  private: void Flush(Boolean flushStream, Boolean flushEncoder);
  public: void Write(Char value);
  public: void Write(Array<Char> buffer);
  public: void Write(Array<Char> buffer, Int32 index, Int32 count);
  public: void Write(ReadOnlySpan<Char> buffer);
  private: void WriteSpan(ReadOnlySpan<Char> buffer, Boolean appendNewLine);
  public: void Write(String value);
  public: void WriteLine(String value);
  public: void WriteLine(ReadOnlySpan<Char> value);
  private: void WriteFormatHelper(String format, ParamsArray args, Boolean appendNewLine);
  public: void Write(String format, Object arg0);
  public: void Write(String format, Object arg0, Object arg1);
  public: void Write(String format, Object arg0, Object arg1, Object arg2);
  public: void Write(String format, Array<Object> arg);
  public: void WriteLine(String format, Object arg0);
  public: void WriteLine(String format, Object arg0, Object arg1);
  public: void WriteLine(String format, Object arg0, Object arg1, Object arg2);
  public: void WriteLine(String format, Array<Object> arg);
  public: Task<> WriteAsync(Char value);
  private: static Task<> WriteAsyncInternal(StreamWriter _this, Char value, Array<Char> charBuffer, Int32 charPos, Int32 charLen, Array<Char> coreNewLine, Boolean autoFlush, Boolean appendNewLine);
  public: Task<> WriteAsync(String value);
  private: static Task<> WriteAsyncInternal(StreamWriter _this, String value, Array<Char> charBuffer, Int32 charPos, Int32 charLen, Array<Char> coreNewLine, Boolean autoFlush, Boolean appendNewLine);
  public: Task<> WriteAsync(Array<Char> buffer, Int32 index, Int32 count);
  public: template <class T0 = CancellationToken>
  Task<> WriteAsync(ReadOnlyMemory<Char> buffer, T0 cancellationToken = rt::default__);
  private: static Task<> WriteAsyncInternal(StreamWriter _this, ReadOnlyMemory<Char> source, Array<Char> charBuffer, Int32 charPos, Int32 charLen, Array<Char> coreNewLine, Boolean autoFlush, Boolean appendNewLine, CancellationToken cancellationToken);
  public: Task<> WriteLineAsync();
  public: Task<> WriteLineAsync(Char value);
  public: Task<> WriteLineAsync(String value);
  public: Task<> WriteLineAsync(Array<Char> buffer, Int32 index, Int32 count);
  public: template <class T0 = CancellationToken>
  Task<> WriteLineAsync(ReadOnlyMemory<Char> buffer, T0 cancellationToken = rt::default__);
  public: Task<> FlushAsync();
  private: template <class T0 = CancellationToken>
  Task<> FlushAsyncInternal(Boolean flushStream, Boolean flushEncoder, Array<Char> sCharBuffer, Int32 sCharPos, T0 cancellationToken = rt::default__);
  private: static Task<> FlushAsyncInternal(StreamWriter _this, Boolean flushStream, Boolean flushEncoder, Array<Char> charBuffer, Int32 charPos, Boolean haveWrittenPreamble, Encoding encoding, Encoder encoder, Array<Byte> byteBuffer, Stream stream, CancellationToken cancellationToken);
  private: void ThrowIfDisposed();
  public: static void cctor();
  private: void _ThrowIfDisposed_g__ThrowObjectDisposedException75_0();
  public: static StreamWriter Null;
  private: Stream _stream;
  private: Encoding _encoding;
  private: Encoder _encoder;
  private: Array<Byte> _byteBuffer;
  private: Array<Char> _charBuffer;
  private: Int32 _charPos;
  private: Int32 _charLen;
  private: Boolean _autoFlush;
  private: Boolean _haveWrittenPreamble;
  private: Boolean _closable;
  private: Boolean _disposed;
  private: Task<> _asyncWriteTask;
};
} // namespace StreamWriterNamespace
using StreamWriter = StreamWriterNamespace::StreamWriter;
} // namespace System::Private::CoreLib::System::IO
