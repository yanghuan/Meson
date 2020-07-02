#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Boolean.h>

namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading {
FORWARDS(AsyncFlowControl)
FORWARD_(ContextCallback, T1, T2)
FORWARD(Thread)
FORWARD(IAsyncLocal)
FORWARD(IAsyncLocalValueMap)
namespace ExecutionContextNamespace {
using namespace ::System::Private::CoreLib::System::Runtime::Serialization;
CLASS(ExecutionContext) {
  public: Boolean get_HasChangeNotifications();
  public: Boolean get_IsDefault();
  public: void GetObjectData(SerializationInfo info, StreamingContext context);
  public: static ExecutionContext Capture();
  private: ExecutionContext ShallowClone(Boolean isFlowSuppressed);
  public: static AsyncFlowControl SuppressFlow();
  public: static void RestoreFlow();
  public: static Boolean IsFlowSuppressed();
  public: static void Run(ExecutionContext executionContext, ContextCallback<> callback, Object state);
  public: static void RunInternal(ExecutionContext executionContext, ContextCallback<> callback, Object state);
  public: static void RunFromThreadPoolDispatchLoop(Thread threadPoolThread, ExecutionContext executionContext, ContextCallback<> callback, Object state);
  public: static void RestoreChangedContextToThread(Thread currentThread, ExecutionContext contextToRestore, ExecutionContext currentContext);
  public: static void ResetThreadPoolThread(Thread currentThread);
  public: static void OnValuesChanged(ExecutionContext previousExecutionCtx, ExecutionContext nextExecutionCtx);
  private: static void ThrowNullContext();
  public: static Object GetLocalValue(IAsyncLocal local);
  public: static void SetLocalValue(IAsyncLocal local, Object newValue, Boolean needChangeNotifications);
  public: ExecutionContext CreateCopy();
  public: void Dispose();
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
