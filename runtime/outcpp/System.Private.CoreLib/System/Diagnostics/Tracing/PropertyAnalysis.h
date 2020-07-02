#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD_(Func, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection {
FORWARD(PropertyInfo)
} // namespace System::Private::CoreLib::System::Reflection
namespace System::Private::CoreLib::System::Diagnostics::Tracing {
FORWARDS(PropertyValue)
FORWARD(TraceLoggingTypeInfo)
FORWARD(EventFieldAttribute)
namespace PropertyAnalysisNamespace {
using namespace ::System::Private::CoreLib::System::Reflection;
CLASS(PropertyAnalysis) {
  public: String name;
  public: PropertyInfo propertyInfo;
  public: Func<PropertyValue, PropertyValue> getter;
  public: TraceLoggingTypeInfo typeInfo;
  public: EventFieldAttribute fieldAttribute;
};
} // namespace PropertyAnalysisNamespace
using PropertyAnalysis = PropertyAnalysisNamespace::PropertyAnalysis;
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing
