#pragma once

#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/IO/TextReader.h>

namespace System::Private::CoreLib::System::Text {
FORWARD(Decoder)
FORWARD(Encoding)
} // namespace System::Private::CoreLib::System::Text
namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Byte)
FORWARDS(Char)
FORWARDS(Memory, T)
FORWARDS(Span, T)
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
namespace StreamReaderNamespace {
using namespace System::Text;
using namespace System::Threading;
using namespace System::Threading::Tasks;
CLASS(StreamReader) : public TextReader::in {
  private: FRIENDN(NullStreamReader)
  public: Encoding get_CurrentEncoding();
  public: Stream get_BaseStream();
  public: Boolean get_EndOfStream();
  private: void CheckAsyncTaskInProgress();
  private: static void ThrowAsyncIOInProgress();
  private: void ctor();
  public: void ctor(Stream stream);
  public: void ctor(Stream stream, Boolean detectEncodingFromByteOrderMarks);
  public: void ctor(Stream stream, Encoding encoding);
  public: void ctor(Stream stream, Encoding encoding, Boolean detectEncodingFromByteOrderMarks);
  public: void ctor(Stream stream, Encoding encoding, Boolean detectEncodingFromByteOrderMarks, Int32 bufferSize);
  public: void ctor(Stream stream, Encoding encoding, Boolean detectEncodingFromByteOrderMarks, Int32 bufferSize, Boolean leaveOpen);
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
  public: ValueTask<Int32> ReadAsync(Memory<Char> buffer, CancellationToken cancellationToken);
  public: ValueTask<Int32> ReadAsyncInternal(Memory<Char> buffer, CancellationToken cancellationToken);
  public: Task<Int32> ReadBlockAsync(Array<Char> buffer, Int32 index, Int32 count);
  public: ValueTask<Int32> ReadBlockAsync(Memory<Char> buffer, CancellationToken cancellationToken);
  private: ValueTask<Int32> ReadBufferAsync(CancellationToken cancellationToken);
  private: void ThrowIfDisposed();
  private: static void ctor_static();
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
