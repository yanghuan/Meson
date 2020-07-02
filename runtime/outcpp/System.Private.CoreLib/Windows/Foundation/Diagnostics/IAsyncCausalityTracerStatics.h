#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD_(EventHandler, T1, T2)
FORWARDS(Guid)
FORWARD(String)
FORWARDS(UInt64)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices::WindowsRuntime {
FORWARDS(EventRegistrationToken)
} // namespace System::Private::CoreLib::System::Runtime::InteropServices::WindowsRuntime
namespace System::Private::CoreLib::Windows::Foundation::Diagnostics {
enum class CausalityTraceLevel;
enum class CausalitySource;
enum class AsyncCausalityStatus;
enum class CausalityRelation;
enum class CausalitySynchronousWork;
FORWARD(TracingStatusChangedEventArgs)
namespace IAsyncCausalityTracerStaticsNamespace {
using namespace ::System::Private::CoreLib::System;
using namespace ::System::Private::CoreLib::System::Runtime::InteropServices::WindowsRuntime;
CLASS(IAsyncCausalityTracerStatics) {
  public: void TraceOperationCreation(CausalityTraceLevel traceLevel, CausalitySource source, Guid platformId, UInt64 operationId, String operationName, UInt64 relatedContext);
  public: void TraceOperationCompletion(CausalityTraceLevel traceLevel, CausalitySource source, Guid platformId, UInt64 operationId, AsyncCausalityStatus status);
  public: void TraceOperationRelation(CausalityTraceLevel traceLevel, CausalitySource source, Guid platformId, UInt64 operationId, CausalityRelation relation);
  public: void TraceSynchronousWorkStart(CausalityTraceLevel traceLevel, CausalitySource source, Guid platformId, UInt64 operationId, CausalitySynchronousWork work);
  public: void TraceSynchronousWorkCompletion(CausalityTraceLevel traceLevel, CausalitySource source, CausalitySynchronousWork work);
  public: EventRegistrationToken add_TracingStatusChanged(EventHandler<TracingStatusChangedEventArgs> eventHandler);
};
} // namespace IAsyncCausalityTracerStaticsNamespace
using IAsyncCausalityTracerStatics = IAsyncCausalityTracerStaticsNamespace::IAsyncCausalityTracerStatics;
} // namespace System::Private::CoreLib::Windows::Foundation::Diagnostics
