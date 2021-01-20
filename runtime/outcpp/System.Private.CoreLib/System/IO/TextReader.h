#pragma once

#include <System.Private.CoreLib/System/Char.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/MarshalByRefObject.h>
#include <System.Private.CoreLib/System/Memory.h>
#include <System.Private.CoreLib/System/Object.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/AsyncTaskMethodBuilder.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/AsyncValueTaskMethodBuilder.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/ConfiguredValueTaskAwaitable.h>
#include <System.Private.CoreLib/System/Threading/CancellationToken.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array)
FORWARDS(Boolean)
FORWARD_(Func)
FORWARD(IDisposable)
FORWARDS(Span, T)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading::Tasks {
FORWARD_(Task)
FORWARDS_(ValueTask)
} // namespace System::Private::CoreLib::System::Threading::Tasks
namespace System::Private::CoreLib::System::Runtime::CompilerServices {
FORWARD(IAsyncStateMachine)
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
namespace System::Private::CoreLib::System::Text {
FORWARD(StringBuilder)
} // namespace System::Private::CoreLib::System::Text
namespace System::Private::CoreLib::System::IO {
namespace TextReaderNamespace {
using namespace System::Runtime::CompilerServices;
using namespace System::Text;
using namespace System::Threading;
using namespace System::Threading::Tasks;
CLASS(TextReader) : public MarshalByRefObject::in {
  public: using interface = rt::TypeList<IDisposable>;
  private: FRIENDN(NullTextReader)
  public: FRIENDN(SyncTextReader)
  private: CLASS(__c) : public object {
    public: static void cctor();
    public: void ctor();
    public: String _ReadLineAsync_b__13_0(Object state);
    public: Int32 _ReadAsync_b__16_0(Object state);
    public: Int32 _ReadAsyncInternal_b__17_0(Object state);
    public: Int32 _ReadBlockAsync_b__19_0(Object state);
    public: static __c __9;
    public: static Func<Object, String> __9__13_0;
    public: static Func<Object, Int32> __9__16_0;
    public: static Func<Object, Int32> __9__17_0;
    public: static Func<Object, Int32> __9__19_0;
  };
  private: struct _ReadToEndAsync_d__14 : public valueType<_ReadToEndAsync_d__14> {
    public: using interface = rt::TypeList<IAsyncStateMachine>;
    private: void MoveNext();
    private: void SetStateMachine(IAsyncStateMachine stateMachine);
    public: Int32 __1__state;
    public: AsyncTaskMethodBuilder<String> __t__builder;
    public: TextReader __4__this;
    private: StringBuilder _sb_5__2;
    private: Array<Char> _chars_5__3;
    private: ConfiguredValueTaskAwaitable<Int32>::ConfiguredValueTaskAwaiter __u__1;
  };
  private: struct _ReadBlockAsyncInternal_d__20 : public valueType<_ReadBlockAsyncInternal_d__20> {
    public: using interface = rt::TypeList<IAsyncStateMachine>;
    private: void MoveNext();
    private: void SetStateMachine(IAsyncStateMachine stateMachine);
    public: Int32 __1__state;
    public: AsyncValueTaskMethodBuilder<Int32> __t__builder;
    public: TextReader __4__this;
    public: Memory<Char> buffer;
    public: CancellationToken cancellationToken;
    private: Int32 _n_5__2;
    private: ConfiguredValueTaskAwaitable<Int32>::ConfiguredValueTaskAwaiter __u__1;
  };
  public: void ctor();
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
  public: template <class T0 = CancellationToken>
  ValueTask<Int32> ReadAsync(Memory<Char> buffer, T0 cancellationToken = rt::default__);
  public: ValueTask<Int32> ReadAsyncInternal(Memory<Char> buffer, CancellationToken cancellationToken);
  public: Task<Int32> ReadBlockAsync(Array<Char> buffer, Int32 index, Int32 count);
  public: template <class T0 = CancellationToken>
  ValueTask<Int32> ReadBlockAsync(Memory<Char> buffer, T0 cancellationToken = rt::default__);
  public: ValueTask<Int32> ReadBlockAsyncInternal(Memory<Char> buffer, CancellationToken cancellationToken);
  public: static TextReader Synchronized(TextReader reader);
  public: static void cctor();
  public: static TextReader Null;
};
CLASS(NullTextReader) : public TextReader::in {
  public: void ctor();
  public: Int32 Read(Array<Char> buffer, Int32 index, Int32 count);
  public: String ReadLine();
};
CLASS(SyncTextReader) : public TextReader::in {
  public: void ctor(TextReader t);
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
} // namespace TextReaderNamespace
using TextReader = TextReaderNamespace::TextReader;
} // namespace System::Private::CoreLib::System::IO
