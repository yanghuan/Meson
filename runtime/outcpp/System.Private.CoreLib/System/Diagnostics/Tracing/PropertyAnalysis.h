#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARD_(Func, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18)
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
CLASS(PropertyAnalysis) : public Object::in {
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
