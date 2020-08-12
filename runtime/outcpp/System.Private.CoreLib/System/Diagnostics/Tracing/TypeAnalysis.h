#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARD(String)
FORWARD(Type)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(List, T)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System::Diagnostics::Tracing {
enum class EventKeywords : int64_t;
enum class EventLevel : int32_t;
enum class EventOpcode : int32_t;
enum class EventTags : int32_t;
FORWARD(EventDataAttribute)
FORWARD(PropertyAnalysis)
namespace TypeAnalysisNamespace {
using namespace System::Collections::Generic;
CLASS(TypeAnalysis) : public Object::in {
  public: void ctor(Type dataType, EventDataAttribute eventAttrib, List<Type> recursionCheck);
  public: Array<PropertyAnalysis> properties;
  public: String name;
  public: EventKeywords keywords;
  public: EventLevel level;
  public: EventOpcode opcode;
  public: EventTags tags;
};
} // namespace TypeAnalysisNamespace
using TypeAnalysis = TypeAnalysisNamespace::TypeAnalysis;
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing
