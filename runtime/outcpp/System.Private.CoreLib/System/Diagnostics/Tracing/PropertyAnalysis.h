#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARD_(Func)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection {
FORWARD(PropertyInfo)
} // namespace System::Private::CoreLib::System::Reflection
namespace System::Private::CoreLib::System::Diagnostics::Tracing {
FORWARD(EventFieldAttribute)
FORWARDS(PropertyValue)
FORWARD(TraceLoggingTypeInfo)
namespace PropertyAnalysisNamespace {
using namespace System::Reflection;
CLASS(PropertyAnalysis) : public object {
  public: void ctor(String name, PropertyInfo propertyInfo, TraceLoggingTypeInfo typeInfo, EventFieldAttribute fieldAttribute);
  public: String name;
  public: PropertyInfo propertyInfo;
  public: Func<PropertyValue, PropertyValue> getter;
  public: TraceLoggingTypeInfo typeInfo;
  public: EventFieldAttribute fieldAttribute;
};
} // namespace PropertyAnalysisNamespace
using PropertyAnalysis = PropertyAnalysisNamespace::PropertyAnalysis;
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing
