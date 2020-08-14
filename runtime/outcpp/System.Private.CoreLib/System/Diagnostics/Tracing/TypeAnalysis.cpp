#include "TypeAnalysis-dep.h"

#include <System.Private.CoreLib/System/Collections/Generic/IEnumerable.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/EventLevel.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/EventOpcode.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/PropertyAnalysis-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/Statics-dep.h>
#include <System.Private.CoreLib/System/Reflection/PropertyInfo-dep.h>

namespace System::Private::CoreLib::System::Diagnostics::Tracing::TypeAnalysisNamespace {
using namespace System::Collections::Generic;
using namespace System::Reflection;

void TypeAnalysis___::ctor(Type dataType, EventDataAttribute eventAttrib, List<Type> recursionCheck) {
  level = (EventLevel)(-1);
  opcode = (EventOpcode)(-1);
  Object::ctor();
  IEnumerable<PropertyInfo> enumerable = Statics::GetProperties(dataType);
  List<PropertyAnalysis> list = rt::newobj<List<PropertyAnalysis>>();
}

} // namespace System::Private::CoreLib::System::Diagnostics::Tracing::TypeAnalysisNamespace
