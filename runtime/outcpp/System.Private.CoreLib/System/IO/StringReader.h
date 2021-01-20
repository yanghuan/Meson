#pragma once

#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/IO/TextReader.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array)
FORWARDS(Boolean)
FORWARDS(Char)
FORWARDS(Memory, T)
FORWARDS(Span, T)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading::Tasks {
FORWARD_(Task)
FORWARDS_(ValueTask)
} // namespace System::Private::CoreLib::System::Threading::Tasks
namespace System::Private::CoreLib::System::Threading {
FORWARDS(CancellationToken)
} // namespace System::Private::CoreLib::System::Threading
namespace System::Private::CoreLib::System::IO {
namespace StringReaderNamespace {
using namespace System::Threading;
using namespace System::Threading::Tasks;
CLASS(StringReader) : public TextReader::in {
  public: void ctor(String s);
  public: void Close();
  protected: void Dispose(Boolean disposing);
  public: Int32 Peek();
  public: Int32 Read();
  public: Int32 Read(Array<Char> buffer, Int32 index, Int32 count);
  public: Int32 Read(Span<Char> buffer);
  public: Int32 ReadBlock(Span<Char> buffer);
  public: String ReadToEnd();
  public: String ReadLine();
  public: Task<String> ReadLineAsync();
  public: Task<String> ReadToEndAsync();
  public: Task<Int32> ReadBlockAsync(Array<Char> buffer, Int32 index, Int32 count);
  public: template <class T0 = CancellationToken>
  ValueTask<Int32> ReadBlockAsync(Memory<Char> buffer, T0 cancellationToken = rt::default__);
  public: Task<Int32> ReadAsync(Array<Char> buffer, Int32 index, Int32 count);
  public: template <class T0 = CancellationToken>
  ValueTask<Int32> ReadAsync(Memory<Char> buffer, T0 cancellationToken = rt::default__);
  private: String _s;
  private: Int32 _pos;
  private: Int32 _length;
};
} // namespace StringReaderNamespace
using StringReader = StringReaderNamespace::StringReader;
} // namespace System::Private::CoreLib::System::IO
