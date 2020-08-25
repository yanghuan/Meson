#include "PropertyAnalysis-dep.h"

#include <System.Private.CoreLib/System/Diagnostics/Tracing/PropertyAnalysis-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/PropertyValue-dep.h>

namespace System::Private::CoreLib::System::Diagnostics::Tracing::PropertyAnalysisNamespace {
void PropertyAnalysis___::ctor(String name, PropertyInfo propertyInfo, TraceLoggingTypeInfo typeInfo, EventFieldAttribute fieldAttribute) {
  this->name = name;
  this->propertyInfo = propertyInfo;
  getter = &PropertyValue::GetPropertyGetter(propertyInfo);
  this->typeInfo = typeInfo;
  this->fieldAttribute = fieldAttribute;
}

} // namespace System::Private::CoreLib::System::Diagnostics::Tracing::PropertyAnalysisNamespace
