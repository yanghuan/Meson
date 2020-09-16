#include "TypeAnalysis-dep.h"

#include <System.Private.CoreLib/System/Diagnostics/Tracing/EventFieldAttribute-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/EventIgnoreAttribute-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/EventLevel.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/EventOpcode.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/PropertyAnalysis-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/Statics-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/TraceLoggingTypeInfo-dep.h>
#include <System.Private.CoreLib/System/Int32-dep.h>
#include <System.Private.CoreLib/System/Reflection/MethodInfo-dep.h>
#include <System.Private.CoreLib/System/Reflection/PropertyInfo-dep.h>
#include <System.Private.CoreLib/System/String-dep.h>

namespace System::Private::CoreLib::System::Diagnostics::Tracing::TypeAnalysisNamespace {
using namespace System::Reflection;

void TypeAnalysis___::ctor(Type dataType, EventDataAttribute eventAttrib, List<Type> recursionCheck) {
  level = (EventLevel)(-1);
  opcode = (EventOpcode)(-1);
  Object::in::ctor();
  List<PropertyAnalysis> list = rt::newobj<List<PropertyAnalysis>>();
  Array<PropertyInfo> array = dataType->GetProperties();
  for (PropertyInfo&& propertyInfo : *array) {
    if (!Statics::HasCustomAttribute(propertyInfo, typeof<EventIgnoreAttribute>()) && propertyInfo->get_CanRead() && propertyInfo->GetIndexParameters()->get_Length() == 0) {
      MethodInfo getMethod = propertyInfo->GetGetMethod();
      if (!(getMethod == nullptr) && !getMethod->get_IsStatic() && getMethod->get_IsPublic()) {
        Type propertyType = propertyInfo->get_PropertyType();
        TraceLoggingTypeInfo instance = TraceLoggingTypeInfo::in::GetInstance(propertyType, recursionCheck);
        EventFieldAttribute customAttribute = Statics::GetCustomAttribute<EventFieldAttribute>(propertyInfo);
        String text = (customAttribute != nullptr && customAttribute->get_Name() != nullptr) ? customAttribute->get_Name() : (Statics::ShouldOverrideFieldName(propertyInfo->get_Name()) ? instance->get_Name() : propertyInfo->get_Name());
        list->Add(rt::newobj<PropertyAnalysis>(text, propertyInfo, instance, customAttribute));
      }
    }
  }
  properties = list->ToArray();
  Array<PropertyAnalysis> array2 = properties;
  for (PropertyAnalysis&& propertyAnalysis : *array2) {
    TraceLoggingTypeInfo typeInfo = propertyAnalysis->typeInfo;
    level = (EventLevel)Statics::Combine((Int32)typeInfo->get_Level(), (Int32)level);
    opcode = (EventOpcode)Statics::Combine((Int32)typeInfo->get_Opcode(), (Int32)opcode);
    keywords |= typeInfo->get_Keywords();
    tags |= typeInfo->get_Tags();
  }
  if (eventAttrib != nullptr) {
    level = (EventLevel)Statics::Combine((Int32)eventAttrib->get_Level(), (Int32)level);
    opcode = (EventOpcode)Statics::Combine((Int32)eventAttrib->get_Opcode(), (Int32)opcode);
    keywords |= eventAttrib->get_Keywords();
    tags |= eventAttrib->get_Tags();
    name = eventAttrib->set_Name();
  }
  if (name == nullptr) {
    name = dataType->get_Name();
  }
}

} // namespace System::Private::CoreLib::System::Diagnostics::Tracing::TypeAnalysisNamespace
