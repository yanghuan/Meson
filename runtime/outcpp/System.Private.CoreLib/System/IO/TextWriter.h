#pragma once

#include <System.Private.CoreLib/System/MarshalByRefObject.h>

namespace System::Private::CoreLib::System::Text {
FORWARD(Encoding)
FORWARD(StringBuilder)
} // namespace System::Private::CoreLib::System::Text
namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
FORWARDS(Char)
FORWARDS(Decimal)
FORWARDS(Double)
FORWARD(IFormatProvider)
FORWARDS(Int32)
FORWARDS(Int64)
FORWARD(Object)
FORWARDS(ReadOnlyMemory, T)
FORWARDS(ReadOnlySpan, T)
FORWARDS(Single)
FORWARD(String)
FORWARDS(UInt32)
FORWARDS(UInt64)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading::Tasks {
FORWARD_(Task, T1, T2)
FORWARDS_(ValueTask, T1, T2)
} // namespace System::Private::CoreLib::System::Threading::Tasks
namespace System::Private::CoreLib::System::Threading {
FORWARDS(CancellationToken)
} // namespace System::Private::CoreLib::System::Threading
namespace System::Private::CoreLib::System::IO {
namespace TextWriterNamespace {
using namespace Text;
using namespace Threading;
using namespace Threading::Tasks;
CLASS(TextWriter) : public MarshalByRefObject::in {
  private: FRIENDN(NullTextWriter)
  public: FRIENDN(SyncTextWriter)
  public: IFormatProvider get_FormatProvider();
  public: Encoding get_Encoding();
  public: String get_NewLine();
  public: void set_NewLine(String value);
  protected: void Ctor();
  protected: void Ctor(IFormatProvider formatProvider);
  public: void Close();
  protected: void Dispose(Boolean disposing);
  public: void Dispose();
  public: ValueTask<> DisposeAsync();
  public: void Flush();
  public: void Write(Char value);
  public: void Write(Array<Char> buffer);
  public: void Write(Array<Char> buffer, Int32 index, Int32 count);
  public: void Write(ReadOnlySpan<Char> buffer);
  public: void Write(Boolean value);
  public: void Write(Int32 value);
  public: void Write(UInt32 value);
  public: void Write(Int64 value);
  public: void Write(UInt64 value);
  public: void Write(Single value);
  public: void Write(Double value);
  public: void Write(Decimal value);
  public: void Write(String value);
  public: void Write(Object value);
  public: void Write(StringBuilder value);
  public: void Write(String format, Object arg0);
  public: void Write(String format, Object arg0, Object arg1);
  public: void Write(String format, Object arg0, Object arg1, Object arg2);
  public: void Write(String format, Array<Object> arg);
  public: void WriteLine();
  public: void WriteLine(Char value);
  public: void WriteLine(Array<Char> buffer);
  public: void WriteLine(Array<Char> buffer, Int32 index, Int32 count);
  public: void WriteLine(ReadOnlySpan<Char> buffer);
  public: void WriteLine(Boolean value);
  public: void WriteLine(Int32 value);
  public: void WriteLine(UInt32 value);
  public: void WriteLine(Int64 value);
  public: void WriteLine(UInt64 value);
  public: void WriteLine(Single value);
  public: void WriteLine(Double value);
  public: void WriteLine(Decimal value);
  public: void WriteLine(String value);
  public: void WriteLine(StringBuilder value);
  public: void WriteLine(Object value);
  public: void WriteLine(String format, Object arg0);
  public: void WriteLine(String format, Object arg0, Object arg1);
  public: void WriteLine(String format, Object arg0, Object arg1, Object arg2);
  public: void WriteLine(String format, Array<Object> arg);
  public: Task<> WriteAsync(Char value);
  public: Task<> WriteAsync(String value);
  public: Task<> WriteAsync(StringBuilder value, CancellationToken cancellationToken);
  public: Task<> WriteAsync(Array<Char> buffer);
  public: Task<> WriteAsync(Array<Char> buffer, Int32 index, Int32 count);
  public: Task<> WriteAsync(ReadOnlyMemory<Char> buffer, CancellationToken cancellationToken);
  public: Task<> WriteLineAsync(Char value);
  public: Task<> WriteLineAsync(String value);
  public: Task<> WriteLineAsync(StringBuilder value, CancellationToken cancellationToken);
  public: Task<> WriteLineAsync(Array<Char> buffer);
  public: Task<> WriteLineAsync(Array<Char> buffer, Int32 index, Int32 count);
  public: Task<> WriteLineAsync(ReadOnlyMemory<Char> buffer, CancellationToken cancellationToken);
  public: Task<> WriteLineAsync();
  public: Task<> FlushAsync();
  public: static TextWriter Synchronized(TextWriter writer);
  private: static void SCtor();
  public: static TextWriter Null;
  private: static Array<Char> s_coreNewLine;
  protected: Array<Char> CoreNewLine;
  private: String CoreNewLineStr;
  private: IFormatProvider _internalFormatProvider;
};
CLASS(NullTextWriter) : public TextWriter::in {
  public: Encoding get_Encoding();
  public: void Ctor();
  public: void Write(Array<Char> buffer, Int32 index, Int32 count);
  public: void Write(String value);
  public: void WriteLine();
  public: void WriteLine(String value);
  public: void WriteLine(Object value);
  public: void Write(Char value);
};
CLASS(SyncTextWriter) : public TextWriter::in {
  public: Encoding get_Encoding();
  public: IFormatProvider get_FormatProvider();
  public: String get_NewLine();
  public: void set_NewLine(String value);
  public: void Ctor(TextWriter t);
  public: void Close();
  protected: void Dispose(Boolean disposing);
  public: void Flush();
  public: void Write(Char value);
  public: void Write(Array<Char> buffer);
  public: void Write(Array<Char> buffer, Int32 index, Int32 count);
  public: void Write(ReadOnlySpan<Char> buffer);
  public: void Write(Boolean value);
  public: void Write(Int32 value);
  public: void Write(UInt32 value);
  public: void Write(Int64 value);
  public: void Write(UInt64 value);
  public: void Write(Single value);
  public: void Write(Double value);
  public: void Write(Decimal value);
  public: void Write(String value);
  public: void Write(StringBuilder value);
  public: void Write(Object value);
  public: void Write(String format, Object arg0);
  public: void Write(String format, Object arg0, Object arg1);
  public: void Write(String format, Object arg0, Object arg1, Object arg2);
  public: void Write(String format, Array<Object> arg);
  public: void WriteLine();
  public: void WriteLine(Char value);
  public: void WriteLine(Decimal value);
  public: void WriteLine(Array<Char> buffer);
  public: void WriteLine(Array<Char> buffer, Int32 index, Int32 count);
  public: void WriteLine(ReadOnlySpan<Char> buffer);
  public: void WriteLine(Boolean value);
  public: void WriteLine(Int32 value);
  public: void WriteLine(UInt32 value);
  public: void WriteLine(Int64 value);
  public: void WriteLine(UInt64 value);
  public: void WriteLine(Single value);
  public: void WriteLine(Double value);
  public: void WriteLine(String value);
  public: void WriteLine(StringBuilder value);
  public: void WriteLine(Object value);
  public: void WriteLine(String format, Object arg0);
  public: void WriteLine(String format, Object arg0, Object arg1);
  public: void WriteLine(String format, Object arg0, Object arg1, Object arg2);
  public: void WriteLine(String format, Array<Object> arg);
  public: ValueTask<> DisposeAsync();
  public: Task<> WriteAsync(Char value);
  public: Task<> WriteAsync(String value);
  public: Task<> WriteAsync(StringBuilder value, CancellationToken cancellationToken);
  public: Task<> WriteAsync(Array<Char> buffer, Int32 index, Int32 count);
  public: Task<> WriteAsync(ReadOnlyMemory<Char> buffer, CancellationToken cancellationToken);
  public: Task<> WriteLineAsync(ReadOnlyMemory<Char> buffer, CancellationToken cancellationToken);
  public: Task<> WriteLineAsync(Char value);
  public: Task<> WriteLineAsync();
  public: Task<> WriteLineAsync(String value);
  public: Task<> WriteLineAsync(StringBuilder value, CancellationToken cancellationToken);
  public: Task<> WriteLineAsync(Array<Char> buffer, Int32 index, Int32 count);
  public: Task<> FlushAsync();
  private: TextWriter _out;
};
} // namespace TextWriterNamespace
using TextWriter = TextWriterNamespace::TextWriter;
} // namespace System::Private::CoreLib::System::IO
