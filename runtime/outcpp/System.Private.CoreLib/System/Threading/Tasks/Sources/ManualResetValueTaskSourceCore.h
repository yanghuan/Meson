#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/Int16.h>

namespace System::Private::CoreLib::System {
FORWARD_(Action, T1, T2, T3, T4, T5, T6, T7, T8, T9)
FORWARD(Exception)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading {
FORWARD(ExecutionContext)
} // namespace System::Private::CoreLib::System::Threading
namespace System::Private::CoreLib::System::Runtime::ExceptionServices {
FORWARD(ExceptionDispatchInfo)
} // namespace System::Private::CoreLib::System::Runtime::ExceptionServices
namespace System::Private::CoreLib::System::Threading::Tasks::Sources {
enum class ValueTaskSourceStatus;
enum class ValueTaskSourceOnCompletedFlags;
namespace ManualResetValueTaskSourceCoreNamespace {
using namespace ::System::Private::CoreLib::System::Runtime::ExceptionServices;
template <class TResult>
struct ManualResetValueTaskSourceCore {
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
};
} // namespace ManualResetValueTaskSourceCoreNamespace
template <class TResult>
using ManualResetValueTaskSourceCore = ManualResetValueTaskSourceCoreNamespace::ManualResetValueTaskSourceCore<TResult>;
} // namespace System::Private::CoreLib::System::Threading::Tasks::Sources