#pragma once

#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARD_(Action, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17)
FORWARD_(Array, T1, T2)
FORWARD(IDisposable)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(ISerializable)
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System::Threading {
FORWARDS(AsyncFlowControl)
FORWARD(ContextCallback)
FORWARD(IAsyncLocal)
FORWARD(IAsyncLocalValueMap)
FORWARD(Thread)
namespace ExecutionContextNamespace {
using namespace System::Runtime::Serialization;
CLASS(ExecutionContext) : public object {
  public: using interface = rt::TypeList<IDisposable, ISerializable>;
  public: Boolean get_HasChangeNotifications();
  public: Boolean get_IsDefault();
  private: void ctor(Boolean isDefault);
  private: void ctor(IAsyncLocalValueMap localValues, Array<IAsyncLocal> localChangeNotifications, Boolean isFlowSuppressed);
  public: void GetObjectData(SerializationInfo info, StreamingContext context);
  public: static ExecutionContext Capture();
  private: ExecutionContext ShallowClone(Boolean isFlowSuppressed);
  public: static AsyncFlowControl SuppressFlow();
  public: static void RestoreFlow();
  public: static Boolean IsFlowSuppressed();
  public: static void Run(ExecutionContext executionContext, ContextCallback callback, Object state);
  public: static void RunInternal(ExecutionContext executionContext, ContextCallback callback, Object state);
  public: static void Restore(ExecutionContext executionContext);
  public: static void RunFromThreadPoolDispatchLoop(Thread threadPoolThread, ExecutionContext executionContext, ContextCallback callback, Object state);
  public: template <class TState>
  static void RunForThreadPoolUnsafe(ExecutionContext executionContext, Action<TState> callback, TState& state);
  public: static void RestoreChangedContextToThread(Thread currentThread, ExecutionContext contextToRestore, ExecutionContext currentContext);
  public: static void ResetThreadPoolThread(Thread currentThread);
  public: static void OnValuesChanged(ExecutionContext previousExecutionCtx, ExecutionContext nextExecutionCtx);
  private: static void ThrowNullContext();
  public: static Object GetLocalValue(IAsyncLocal local);
  public: static void SetLocalValue(IAsyncLocal local, Object newValue, Boolean needChangeNotifications);
  public: ExecutionContext CreateCopy();
  public: void Dispose();
  private: static void cctor();
  public: static ExecutionContext Default;
  public: static ExecutionContext DefaultFlowSuppressed;
  private: IAsyncLocalValueMap m_localValues;
  private: Array<IAsyncLocal> m_localChangeNotifications;
  private: Boolean m_isFlowSuppressed;
  private: Boolean m_isDefault;
};
} // namespace ExecutionContextNamespace
using ExecutionContext = ExecutionContextNamespace::ExecutionContext;
} // namespace System::Private::CoreLib::System::Threading
