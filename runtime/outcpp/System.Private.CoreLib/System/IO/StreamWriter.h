#pragma once

#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/IO/TextWriter.h>

namespace System::Private::CoreLib::System::Text {
FORWARD(Encoder)
FORWARD(Encoding)
} // namespace System::Private::CoreLib::System::Text
namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Byte)
FORWARDS(Char)
FORWARD(Object)
FORWARDS(ParamsArray)
FORWARDS(ReadOnlyMemory, T)
FORWARDS(ReadOnlySpan, T)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading::Tasks {
FORWARD_(Task, T1, T2)
FORWARDS_(ValueTask, T1, T2)
} // namespace System::Private::CoreLib::System::Threading::Tasks
namespace System::Private::CoreLib::System::Threading {
FORWARDS(CancellationToken)
} // namespace System::Private::CoreLib::System::Threading
namespace System::Private::CoreLib::System::IO {
FORWARD(Stream)
namespace StreamWriterNamespace {
using namespace Text;
using namespace Threading;
using namespace Threading::Tasks;
CLASS(StreamWriter) : public TextWriter::in {
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
  public: void ctor(Stream stream, Encoding encoding, Int32 bufferSize, Boolean leaveOpen);
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
  public: Task<> WriteAsync(ReadOnlyMemory<Char> buffer, CancellationToken cancellationToken);
  private: static Task<> WriteAsyncInternal(StreamWriter _this, ReadOnlyMemory<Char> source, Array<Char> charBuffer, Int32 charPos, Int32 charLen, Array<Char> coreNewLine, Boolean autoFlush, Boolean appendNewLine, CancellationToken cancellationToken);
  public: Task<> WriteLineAsync();
  public: Task<> WriteLineAsync(Char value);
  public: Task<> WriteLineAsync(String value);
  public: Task<> WriteLineAsync(Array<Char> buffer, Int32 index, Int32 count);
  public: Task<> WriteLineAsync(ReadOnlyMemory<Char> buffer, CancellationToken cancellationToken);
  public: Task<> FlushAsync();
  private: Task<> FlushAsyncInternal(Boolean flushStream, Boolean flushEncoder, Array<Char> sCharBuffer, Int32 sCharPos, CancellationToken cancellationToken);
  private: static Task<> FlushAsyncInternal(StreamWriter _this, Boolean flushStream, Boolean flushEncoder, Array<Char> charBuffer, Int32 charPos, Boolean haveWrittenPreamble, Encoding encoding, Encoder encoder, Array<Byte> byteBuffer, Stream stream, CancellationToken cancellationToken);
  private: void ThrowIfDisposed();
  private: static void ctor_static();
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
