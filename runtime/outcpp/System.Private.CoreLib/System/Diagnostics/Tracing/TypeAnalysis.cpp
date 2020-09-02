#include "TypeAnalysis-dep.h"

#include <System.Private.CoreLib/System/Collections/Generic/IEnumerable.h>
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
using namespace System::Collections::Generic;
using namespace System::Reflection;

void TypeAnalysis___::ctor(Type dataType, EventDataAttribute eventAttrib, List<Type> recursionCheck) {
  level = (EventLevel)(-1);
  opcode = (EventOpcode)(-1);
  Object::in::ctor();
  IEnumerable<PropertyInfo> enumerable = Statics::GetProperties(dataType);
  List<PropertyAnalysis> list = rt::newobj<List<PropertyAnalysis>>();
  for (PropertyInfo&& item : rt::each(enumerable)) {
    if (!Statics::HasCustomAttribute(item, typeof<EventIgnoreAttribute>()) && item->get_CanRead() && item->GetIndexParameters()->get_Length() == 0) {
      MethodInfo getMethod = Statics::GetGetMethod(item);
      if (!(getMethod == nullptr) && !getMethod->get_IsStatic() && getMethod->get_IsPublic()) {
        Type propertyType = item->get_PropertyType();
        TraceLoggingTypeInfo instance = TraceLoggingTypeInfo::in::GetInstance(propertyType, recursionCheck);
        EventFieldAttribute customAttribute = Statics::GetCustomAttribute<EventFieldAttribute>(item);
        String text = (customAttribute != nullptr && customAttribute->get_Name() != nullptr) ? customAttribute->get_Name() : (Statics::ShouldOverrideFieldName(item->get_Name()) ? instance->get_Name() : item->get_Name());
        list->Add(rt::newobj<PropertyAnalysis>(text, item, instance, customAttribute));
      }
    }
  }
  properties = list->ToArray();
  Array<PropertyAnalysis> array = properties;
  for (PropertyAnalysis&& propertyAnalysis : rt::each(array)) {
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
