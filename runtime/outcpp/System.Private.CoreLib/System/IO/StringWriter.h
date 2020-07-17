#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Boolean.h>

namespace System::Private::CoreLib::System::Text {
FORWARD(Encoding)
FORWARD(StringBuilder)
FORWARD(UnicodeEncoding)
} // namespace System::Private::CoreLib::System::Text
namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Char)
FORWARD(IFormatProvider)
FORWARDS(Int32)
FORWARDS(ReadOnlyMemory, T)
FORWARDS(ReadOnlySpan, T)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading::Tasks {
FORWARD_(Task, T1, T2)
} // namespace System::Private::CoreLib::System::Threading::Tasks
namespace System::Private::CoreLib::System::Threading {
FORWARDS(CancellationToken)
} // namespace System::Private::CoreLib::System::Threading
namespace System::Private::CoreLib::System::IO {
namespace StringWriterNamespace {
using namespace Text;
using namespace Threading;
using namespace Threading::Tasks;
CLASS(StringWriter) {
  public: Encoding get_Encoding();
  public: void Ctor();
  public: void Ctor(IFormatProvider formatProvider);
  public: void Ctor(StringBuilder sb);
  public: void Ctor(StringBuilder sb, IFormatProvider formatProvider);
  public: void Close();
  protected: void Dispose(Boolean disposing);
  public: StringBuilder GetStringBuilder();
  public: void Write(Char value);
  public: void Write(Array<Char> buffer, Int32 index, Int32 count);
  public: void Write(ReadOnlySpan<Char> buffer);
  public: void Write(String value);
  public: void Write(StringBuilder value);
  public: void WriteLine(ReadOnlySpan<Char> buffer);
  public: void WriteLine(StringBuilder value);
  public: Task<> WriteAsync(Char value);
  public: Task<> WriteAsync(String value);
  public: Task<> WriteAsync(Array<Char> buffer, Int32 index, Int32 count);
  public: Task<> WriteAsync(ReadOnlyMemory<Char> buffer, CancellationToken cancellationToken);
  public: Task<> WriteAsync(StringBuilder value, CancellationToken cancellationToken);
  public: Task<> WriteLineAsync(Char value);
  public: Task<> WriteLineAsync(String value);
  public: Task<> WriteLineAsync(StringBuilder value, CancellationToken cancellationToken);
  public: Task<> WriteLineAsync(Array<Char> buffer, Int32 index, Int32 count);
  public: Task<> WriteLineAsync(ReadOnlyMemory<Char> buffer, CancellationToken cancellationToken);
  public: Task<> FlushAsync();
  public: String ToString();
  private: static UnicodeEncoding s_encoding;
  private: StringBuilder _sb;
  private: Boolean _isOpen;
};
} // namespace StringWriterNamespace
using StringWriter = StringWriterNamespace::StringWriter;
} // namespace System::Private::CoreLib::System::IO
