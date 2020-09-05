#pragma once

#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/Int16.h>
#include <System.Private.CoreLib/System/Threading/Tasks/Task.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System {
FORWARD_(Action, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17)
FORWARD(Exception)
FORWARD(IEquatable, T)
FORWARDS(Int32)
FORWARD(Object)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading::Tasks::Sources {
FORWARD_(IValueTaskSource, T1, T2)
} // namespace System::Private::CoreLib::System::Threading::Tasks::Sources
namespace System::Private::CoreLib::System::Threading {
FORWARDS(CancellationToken)
} // namespace System::Private::CoreLib::System::Threading
namespace System::Private::CoreLib::System::Runtime::CompilerServices {
FORWARDS_(ConfiguredValueTaskAwaitable, T1, T2)
FORWARDS_(ValueTaskAwaiter, T1, T2)
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
namespace System::Private::CoreLib::System::Threading::Tasks {
namespace ValueTaskNamespace {
using namespace System::Runtime::CompilerServices;
using namespace System::Threading::Tasks::Sources;
template <class T1 = void, class T2 = void>
struct ValueTask {
};
template <>
struct ValueTask<> : public valueType<ValueTask<>> {
  public: using interface = rt::TypeList<IEquatable<ValueTask<>>>;
  private: CLASS(ValueTaskSourceAsTask) : public Task<>::in {
    public: void ctor(IValueTaskSource<> source, Int16 token);
    public: static void cctor();
    private: static Action<Object> s_completionAction;
    private: IValueTaskSource<> _source;
    private: Int16 _token;
  };
  public: static ValueTask<> get_CompletedTask();
  public: Boolean get_IsCompleted();
  public: Boolean get_IsCompletedSuccessfully();
  public: Boolean get_IsFaulted();
  public: Boolean get_IsCanceled();
  public: explicit ValueTask(Task<> task);
  public: explicit ValueTask(IValueTaskSource<> source, Int16 token);
  private: explicit ValueTask(Object obj, Int16 token, Boolean continueOnCapturedContext);
  public: template <class TResult>
  static ValueTask<TResult> FromResult(TResult result);
  public: static ValueTask<> FromCanceled(CancellationToken cancellationToken);
  public: template <class TResult>
  static ValueTask<TResult> FromCanceled(CancellationToken cancellationToken);
  public: static ValueTask<> FromException(Exception exception);
  public: template <class TResult>
  static ValueTask<TResult> FromException(Exception exception);
  public: Int32 GetHashCode();
  public: Boolean Equals(Object obj);
  public: Boolean Equals(ValueTask<> other);
  public: static Boolean op_Equality(ValueTask<> left, ValueTask<> right);
  public: static Boolean op_Inequality(ValueTask<> left, ValueTask<> right);
  public: Task<> AsTask();
  public: ValueTask<> Preserve();
  private: Task<> GetTaskForValueTaskSource(IValueTaskSource<> t);
  public: void ThrowIfCompletedUnsuccessfully();
  public: ValueTaskAwaiter<> GetAwaiter();
  public: ConfiguredValueTaskAwaitable<> ConfigureAwait(Boolean continueOnCapturedContext);
  public: static void cctor();
  public: explicit ValueTask() {}
  private: static Task<> s_canceledTask;
  public: Object _obj;
  public: Int16 _token;
  public: Boolean _continueOnCapturedContext;
};
template <class TResult>
struct ValueTask<TResult> : public valueType<ValueTask<TResult>> {
  public: using interface = rt::TypeList<IEquatable<ValueTask<TResult>>>;
  private: CLASS(ValueTaskSourceAsTask) : public Task<TResult>::in {
    public: void ctor(IValueTaskSource<TResult> source, Int16 token);
    public: static void cctor();
    private: static Action<Object> s_completionAction;
    private: IValueTaskSource<TResult> _source;
    private: Int16 _token;
  };
  public: Boolean get_IsCompleted();
  public: Boolean get_IsCompletedSuccessfully();
  public: Boolean get_IsFaulted();
  public: Boolean get_IsCanceled();
  public: TResult get_Result();
  public: explicit ValueTask(TResult result);
  public: explicit ValueTask(Task<TResult> task);
  public: explicit ValueTask(IValueTaskSource<TResult> source, Int16 token);
  private: explicit ValueTask(Object obj, TResult result, Int16 token, Boolean continueOnCapturedContext);
  public: Int32 GetHashCode();
  public: Boolean Equals(Object obj);
  public: Boolean Equals(ValueTask<TResult> other);
  public: static Boolean op_Equality(ValueTask<TResult> left, ValueTask<TResult> right);
  public: static Boolean op_Inequality(ValueTask<TResult> left, ValueTask<TResult> right);
  public: Task<TResult> AsTask();
  public: ValueTask<TResult> Preserve();
  private: Task<TResult> GetTaskForValueTaskSource(IValueTaskSource<TResult> t);
  public: ValueTaskAwaiter<TResult> GetAwaiter();
  public: ConfiguredValueTaskAwaitable<TResult> ConfigureAwait(Boolean continueOnCapturedContext);
  public: String ToString();
  public: explicit ValueTask() {}
  private: static Task<TResult> s_canceledTask;
  public: Object _obj;
  public: TResult _result;
  public: Int16 _token;
  public: Boolean _continueOnCapturedContext;
};
} // namespace ValueTaskNamespace
template <class T1 = void, class T2 = void>
using ValueTask = ValueTaskNamespace::ValueTask<T1, T2>;
} // namespace System::Private::CoreLib::System::Threading::Tasks
