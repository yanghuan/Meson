#pragma once

#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/MarshalByRefObject.h>
#include <System.Private.CoreLib/System/Object.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/AsyncTaskMethodBuilder.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/ConfiguredTaskAwaitable.h>
#include <System.Private.CoreLib/System/Text/StringBuilder.h>
#include <System.Private.CoreLib/System/Threading/CancellationToken.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System {
FORWARD_(Action)
FORWARD_(Array)
FORWARDS(Boolean)
FORWARDS(Char)
FORWARDS(Decimal)
FORWARDS(Double)
FORWARD(IAsyncDisposable)
FORWARD(IDisposable)
FORWARD(IFormatProvider)
FORWARDS(Int64)
FORWARDS(ReadOnlyMemory, T)
FORWARDS(ReadOnlySpan, T)
FORWARDS(Single)
FORWARD(String)
FORWARDS(UInt32)
FORWARDS(UInt64)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Text {
FORWARD(Encoding)
} // namespace System::Private::CoreLib::System::Text
namespace System::Private::CoreLib::System::Threading::Tasks {
FORWARD_(Task)
FORWARDS_(ValueTask)
} // namespace System::Private::CoreLib::System::Threading::Tasks
namespace System::Private::CoreLib::System::Runtime::CompilerServices {
FORWARD(IAsyncStateMachine)
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
namespace System::Private::CoreLib::System::IO {
namespace TextWriterNamespace {
using namespace System::Runtime::CompilerServices;
using namespace System::Text;
using namespace System::Threading;
using namespace System::Threading::Tasks;
CLASS(TextWriter) : public MarshalByRefObject::in {
  public: using interface = rt::TypeList<IDisposable, IAsyncDisposable>;
  private: FRIENDN(NullTextWriter)
  public: FRIENDN(SyncTextWriter)
  private: CLASS(__c) : public object {
    public: static void cctor();
    public: void ctor();
    public: void _WriteAsync_b__58_0(Object state);
    public: void _WriteAsync_b__59_0(Object state);
    public: void _WriteAsync_b__62_0(Object state);
    public: void _WriteAsync_b__63_0(Object state);
    public: void _WriteLineAsync_b__64_0(Object state);
    public: void _WriteLineAsync_b__65_0(Object state);
    public: void _WriteLineAsync_b__68_0(Object state);
    public: void _WriteLineAsync_b__69_0(Object state);
    public: void _FlushAsync_b__71_0(Object state);
    public: static __c __9;
    public: static Action<Object> __9__58_0;
    public: static Action<Object> __9__59_0;
    public: static Action<Object> __9__62_0;
    public: static Action<Object> __9__63_0;
    public: static Action<Object> __9__64_0;
    public: static Action<Object> __9__65_0;
    public: static Action<Object> __9__68_0;
    public: static Action<Object> __9__69_0;
    public: static Action<Object> __9__71_0;
  };
  private: struct __WriteAsync_g__WriteAsyncCore60_0_d : public valueType<__WriteAsync_g__WriteAsyncCore60_0_d> {
    public: using interface = rt::TypeList<IAsyncStateMachine>;
    private: void MoveNext();
    private: void SetStateMachine(IAsyncStateMachine stateMachine);
    public: Int32 __1__state;
    public: AsyncTaskMethodBuilder<> __t__builder;
    public: StringBuilder sb;
    public: TextWriter __4__this;
    public: CancellationToken ct;
    private: StringBuilder::in::ChunkEnumerator __7__wrap1;
    private: ConfiguredTaskAwaitable<>::ConfiguredTaskAwaiter __u__1;
  };
  private: struct __WriteLineAsync_g__WriteLineAsyncCore66_0_d : public valueType<__WriteLineAsync_g__WriteLineAsyncCore66_0_d> {
    public: using interface = rt::TypeList<IAsyncStateMachine>;
    private: void MoveNext();
    private: void SetStateMachine(IAsyncStateMachine stateMachine);
    public: Int32 __1__state;
    public: AsyncTaskMethodBuilder<> __t__builder;
    public: StringBuilder sb;
    public: TextWriter __4__this;
    public: CancellationToken ct;
    private: StringBuilder::in::ChunkEnumerator __7__wrap1;
    private: ConfiguredTaskAwaitable<>::ConfiguredTaskAwaiter __u__1;
  };
  public: IFormatProvider get_FormatProvider();
  public: Encoding get_Encoding();
  public: String get_NewLine();
  public: void set_NewLine(String value);
  public: void ctor();
  public: void ctor(IFormatProvider formatProvider);
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
  public: template <class T0 = CancellationToken>
  Task<> WriteAsync(StringBuilder value, T0 cancellationToken = rt::default__);
  public: Task<> WriteAsync(Array<Char> buffer);
  public: Task<> WriteAsync(Array<Char> buffer, Int32 index, Int32 count);
  public: template <class T0 = CancellationToken>
  Task<> WriteAsync(ReadOnlyMemory<Char> buffer, T0 cancellationToken = rt::default__);
  public: Task<> WriteLineAsync(Char value);
  public: Task<> WriteLineAsync(String value);
  public: template <class T0 = CancellationToken>
  Task<> WriteLineAsync(StringBuilder value, T0 cancellationToken = rt::default__);
  public: Task<> WriteLineAsync(Array<Char> buffer);
  public: Task<> WriteLineAsync(Array<Char> buffer, Int32 index, Int32 count);
  public: template <class T0 = CancellationToken>
  Task<> WriteLineAsync(ReadOnlyMemory<Char> buffer, T0 cancellationToken = rt::default__);
  public: Task<> WriteLineAsync();
  public: Task<> FlushAsync();
  public: static TextWriter Synchronized(TextWriter writer);
  public: static void cctor();
  private: Task<> _WriteAsync_g__WriteAsyncCore60_0(StringBuilder sb, CancellationToken ct);
  private: Task<> _WriteLineAsync_g__WriteLineAsyncCore66_0(StringBuilder sb, CancellationToken ct);
  public: static TextWriter Null;
  private: static Array<Char> s_coreNewLine;
  protected: Array<Char> CoreNewLine;
  private: String CoreNewLineStr;
  private: IFormatProvider _internalFormatProvider;
};
CLASS(NullTextWriter) : public TextWriter::in {
  public: Encoding get_Encoding();
  public: void ctor();
  public: void Write(Array<Char> buffer, Int32 index, Int32 count);
  public: void Write(String value);
  public: void WriteLine();
  public: void WriteLine(String value);
  public: void WriteLine(Object value);
  public: void Write(Char value);
};
CLASS(SyncTextWriter) : public TextWriter::in {
  public: using interface = rt::TypeList<IDisposable>;
  public: Encoding get_Encoding();
  public: IFormatProvider get_FormatProvider();
  public: String get_NewLine();
  public: void set_NewLine(String value);
  public: void ctor(TextWriter t);
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
  public: template <class T0 = CancellationToken>
  Task<> WriteAsync(StringBuilder value, T0 cancellationToken = rt::default__);
  public: Task<> WriteAsync(Array<Char> buffer, Int32 index, Int32 count);
  public: template <class T0 = CancellationToken>
  Task<> WriteAsync(ReadOnlyMemory<Char> buffer, T0 cancellationToken = rt::default__);
  public: template <class T0 = CancellationToken>
  Task<> WriteLineAsync(ReadOnlyMemory<Char> buffer, T0 cancellationToken = rt::default__);
  public: Task<> WriteLineAsync(Char value);
  public: Task<> WriteLineAsync();
  public: Task<> WriteLineAsync(String value);
  public: template <class T0 = CancellationToken>
  Task<> WriteLineAsync(StringBuilder value, T0 cancellationToken = rt::default__);
  public: Task<> WriteLineAsync(Array<Char> buffer, Int32 index, Int32 count);
  public: Task<> FlushAsync();
  private: TextWriter _out;
};
} // namespace TextWriterNamespace
using TextWriter = TextWriterNamespace::TextWriter;
} // namespace System::Private::CoreLib::System::IO
