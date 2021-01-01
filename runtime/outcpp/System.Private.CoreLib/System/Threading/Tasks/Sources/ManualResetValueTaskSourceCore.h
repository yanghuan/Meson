#pragma once

#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/Int16.h>
#include <System.Private.CoreLib/System/Object.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System::Threading {
FORWARD_(ContextCallback, T1, T2)
FORWARD(ExecutionContext)
FORWARD(SendOrPostCallback)
} // namespace System::Private::CoreLib::System::Threading
namespace System::Private::CoreLib::System {
FORWARD_(Action, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17)
FORWARD(Exception)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::ExceptionServices {
FORWARD(ExceptionDispatchInfo)
} // namespace System::Private::CoreLib::System::Runtime::ExceptionServices
namespace System::Private::CoreLib::System::Threading::Tasks::Sources {
enum class ValueTaskSourceOnCompletedFlags : int32_t;
enum class ValueTaskSourceStatus : int32_t;
namespace ManualResetValueTaskSourceCoreNamespace {
using namespace System::Runtime::ExceptionServices;
template <class TResult>
struct ManualResetValueTaskSourceCore : public valueType<ManualResetValueTaskSourceCore<TResult>> {
  private: CLASS(__c) : public object {
    public: static void cctor();
    public: void ctor();
    public: void _OnCompleted_b__19_0(Object s);
    public: void _SignalCompletion_b__21_0(ManualResetValueTaskSourceCore<TResult>& s);
    public: void _InvokeContinuation_b__22_0(Object s);
    public: static __c __9;
    public: static SendOrPostCallback __9__19_0;
    public: static ContextCallback<ManualResetValueTaskSourceCore<TResult>> __9__21_0;
    public: static SendOrPostCallback __9__22_0;
  };
  public: Boolean get_RunContinuationsAsynchronously() { return RunContinuationsAsynchronously; }
  public: void set_RunContinuationsAsynchronously(Boolean value) { RunContinuationsAsynchronously = value; }
  public: Int16 get_Version();
  public: void Reset();
  public: void SetResult(TResult result);
  public: void SetException(Exception error);
  public: ValueTaskSourceStatus GetStatus(Int16 token);
  public: TResult GetResult(Int16 token);
  public: void OnCompleted(Action<Object> continuation, Object state, Int16 token, ValueTaskSourceOnCompletedFlags flags);
  private: void ValidateToken(Int16 token);
  private: void SignalCompletion();
  private: void InvokeContinuation();
  private: Action<Object> _continuation;
  private: Object _continuationState;
  private: ExecutionContext _executionContext;
  private: Object _capturedContext;
  private: Boolean _completed;
  private: TResult _result;
  private: ExceptionDispatchInfo _error;
  private: Int16 _version;
  private: Boolean RunContinuationsAsynchronously;
};
} // namespace ManualResetValueTaskSourceCoreNamespace
template <class TResult>
using ManualResetValueTaskSourceCore = ManualResetValueTaskSourceCoreNamespace::ManualResetValueTaskSourceCore<TResult>;
} // namespace System::Private::CoreLib::System::Threading::Tasks::Sources
