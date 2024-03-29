#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Diagnostics::Tracing {
FORWARD(TraceLoggingEventTypes)
namespace SimpleEventTypesNamespace {
template <class T>
class SimpleEventTypes {
  public: static TraceLoggingEventTypes get_Instance();
  private: static TraceLoggingEventTypes InitInstance();
  private: static TraceLoggingEventTypes instance;
};
} // namespace SimpleEventTypesNamespace
template <class T>
using SimpleEventTypes = SimpleEventTypesNamespace::SimpleEventTypes<T>;
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing
