#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Int32.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
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
namespace StringReaderNamespace {
using namespace ::System::Private::CoreLib::System::Threading;
using namespace ::System::Private::CoreLib::System::Threading::Tasks;
CLASS(StringReader) {
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
  public: ValueTask<Int32> ReadBlockAsync(Memory<Char> buffer, CancellationToken cancellationToken);
  public: Task<Int32> ReadAsync(Array<Char> buffer, Int32 index, Int32 count);
  public: ValueTask<Int32> ReadAsync(Memory<Char> buffer, CancellationToken cancellationToken);
  private: String _s;
  private: Int32 _pos;
  private: Int32 _length;
};
} // namespace StringReaderNamespace
using StringReader = StringReaderNamespace::StringReader;
} // namespace System::Private::CoreLib::System::IO
