#pragma once

#include <rt/GCObject.h>

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
enum class EventLevel;
enum class EventOpcode;
enum class EventTags;
FORWARD(EventDataAttribute)
FORWARD(PropertyAnalysis)
namespace TypeAnalysisNamespace {
using namespace Collections::Generic;
CLASS(TypeAnalysis) {
  public: void Ctor(Type dataType, EventDataAttribute eventAttrib, List<Type> recursionCheck);
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
