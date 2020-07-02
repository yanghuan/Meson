#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARD(Object)
FORWARD(String)
FORWARD(Exception)
FORWARDS(UInt32)
FORWARDS(UInt64)
FORWARDS(Guid)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::Windows::Foundation::Diagnostics {
FORWARD(TracingStatusChangedEventArgs)
FORWARD(IAsyncCausalityTracerStatics)
} // namespace System::Private::CoreLib::Windows::Foundation::Diagnostics
namespace System::Private::CoreLib::System::Threading::Tasks {
FORWARD_(Task, T1, T2)
enum class AsyncCausalityStatus;
enum class CausalityRelation;
enum class CausalitySynchronousWork;
namespace AsyncCausalityTracerNamespace {
using namespace ::System::Private::CoreLib::Windows::Foundation::Diagnostics;
class AsyncCausalityTracer {
  private: enum class Loggers : uint8_t {
    CausalityTracer = 1,
    ETW = 2,
  };
  public: static Boolean get_LoggingOn();
  public: static void EnableToETW(Boolean enabled);
  private: static void TracingStatusChangedHandler(Object sender, TracingStatusChangedEventArgs args);
  public: static void TraceOperationCreation(Task<> task, String operationName);
  public: static void TraceOperationCompletion(Task<> task, AsyncCausalityStatus status);
  public: static void TraceOperationRelation(Task<> task, CausalityRelation relation);
  public: static void TraceSynchronousWorkStart(Task<> task, CausalitySynchronousWork work);
  public: static void TraceSynchronousWorkCompletion(CausalitySynchronousWork work);
  private: static void LogAndDisable(Exception ex);
  private: static UInt64 GetOperationId(UInt32 taskId);
  private: static Guid s_PlatformId;
  private: static IAsyncCausalityTracerStatics s_TracerFactory;
  private: static Loggers f_LoggingOn;
};
} // namespace AsyncCausalityTracerNamespace
using AsyncCausalityTracer = AsyncCausalityTracerNamespace::AsyncCausalityTracer;
} // namespace System::Private::CoreLib::System::Threading::Tasks
