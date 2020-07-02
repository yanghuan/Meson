#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
FORWARDS(Char)
FORWARDS(Int32)
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
namespace TextReaderNamespace {
using namespace ::System::Private::CoreLib::System::Threading;
using namespace ::System::Private::CoreLib::System::Threading::Tasks;
CLASS(TextReader) {
  private: CLASS(NullTextReader) {
    public: Int32 Read(Array<Char> buffer, Int32 index, Int32 count);
    public: String ReadLine();
  };
  public: CLASS(SyncTextReader) {
    public: void Close();
    protected: void Dispose(Boolean disposing);
    public: Int32 Peek();
    public: Int32 Read();
    public: Int32 Read(Array<Char> buffer, Int32 index, Int32 count);
    public: Int32 ReadBlock(Array<Char> buffer, Int32 index, Int32 count);
    public: String ReadLine();
    public: String ReadToEnd();
    public: Task<String> ReadLineAsync();
    public: Task<String> ReadToEndAsync();
    public: Task<Int32> ReadBlockAsync(Array<Char> buffer, Int32 index, Int32 count);
    public: Task<Int32> ReadAsync(Array<Char> buffer, Int32 index, Int32 count);
    public: TextReader _in;
  };
  public: void Close();
  public: void Dispose();
  protected: void Dispose(Boolean disposing);
  public: Int32 Peek();
  public: Int32 Read();
  public: Int32 Read(Array<Char> buffer, Int32 index, Int32 count);
  public: Int32 Read(Span<Char> buffer);
  public: String ReadToEnd();
  public: Int32 ReadBlock(Array<Char> buffer, Int32 index, Int32 count);
  public: Int32 ReadBlock(Span<Char> buffer);
  public: String ReadLine();
  public: Task<String> ReadLineAsync();
  public: Task<String> ReadToEndAsync();
  public: Task<Int32> ReadAsync(Array<Char> buffer, Int32 index, Int32 count);
  public: ValueTask<Int32> ReadAsync(Memory<Char> buffer, CancellationToken cancellationToken);
  public: ValueTask<Int32> ReadAsyncInternal(Memory<Char> buffer, CancellationToken cancellationToken);
  public: Task<Int32> ReadBlockAsync(Array<Char> buffer, Int32 index, Int32 count);
  public: ValueTask<Int32> ReadBlockAsync(Memory<Char> buffer, CancellationToken cancellationToken);
  public: ValueTask<Int32> ReadBlockAsyncInternal(Memory<Char> buffer, CancellationToken cancellationToken);
  public: static TextReader Synchronized(TextReader reader);
  public: static TextReader Null;
};
} // namespace TextReaderNamespace
using TextReader = TextReaderNamespace::TextReader;
} // namespace System::Private::CoreLib::System::IO