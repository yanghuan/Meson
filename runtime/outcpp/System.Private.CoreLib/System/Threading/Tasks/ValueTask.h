#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/Int16.h>

namespace System::Private::CoreLib::System {
FORWARD_(Action, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading::Tasks::Sources {
FORWARD_(IValueTaskSource, T1, T2)
} // namespace System::Private::CoreLib::System::Threading::Tasks::Sources
namespace System::Private::CoreLib::System::Threading::Tasks {
FORWARD_(Task, T1, T2)
namespace ValueTaskNamespace {
using namespace ::System::Private::CoreLib::System::Threading::Tasks::Sources;
template <class T1 = void, class T2 = void>
struct ValueTask {
};
template <>
struct ValueTask<> {
  private: CLASS(ValueTaskSourceAsTask) {
    private: static Action<Object> s_completionAction;
    private: IValueTaskSource<> _source;
    private: Int16 _token;
  };
  public: static Task<> get_CompletedTask();
  public: Boolean get_IsCompleted();
  public: Boolean get_IsCompletedSuccessfully();
  public: Boolean get_IsFaulted();
  public: Boolean get_IsCanceled();
  private: static Task<> s_canceledTask;
  public: Object _obj;
  public: Int16 _token;
  public: Boolean _continueOnCapturedContext;
};
template <class TResult>
struct ValueTask<TResult> {
  private: CLASS(ValueTaskSourceAsTask) {
    private: static Action<Object> s_completionAction;
    private: IValueTaskSource<TResult> _source;
    private: Int16 _token;
  };
  public: Boolean get_IsCompleted();
  public: Boolean get_IsCompletedSuccessfully();
  public: Boolean get_IsFaulted();
  public: Boolean get_IsCanceled();
  public: TResult get_Result();
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
