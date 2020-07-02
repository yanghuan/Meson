#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Diagnostics::Tracing {
FORWARD(PropertyAnalysis)
enum class EventKeywords : int64_t;
enum class EventLevel;
enum class EventOpcode;
enum class EventTags;
namespace TypeAnalysisNamespace {
CLASS(TypeAnalysis) {
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
