#include "TypeAnalysis-dep.h"

#include <System.Private.CoreLib/System/Diagnostics/Tracing/EventLevel.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/EventOpcode.h>

namespace System::Private::CoreLib::System::Diagnostics::Tracing::TypeAnalysisNamespace {
void TypeAnalysis___::ctor(Type dataType, EventDataAttribute eventAttrib, List<Type> recursionCheck) {
  level = (EventLevel)(-1);
  opcode = (EventOpcode)(-1);
}

} // namespace System::Private::CoreLib::System::Diagnostics::Tracing::TypeAnalysisNamespace
