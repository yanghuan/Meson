#include "TraceLoggingTypeInfo-dep.h"

#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/Collections/Generic/Dictionary-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/Statics-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/TraceLoggingTypeInfo-dep.h>
#include <System.Private.CoreLib/System/Int32-dep.h>

namespace System::Private::CoreLib::System::Diagnostics::Tracing::TraceLoggingTypeInfoNamespace {
using namespace System::Collections::Generic;

String TraceLoggingTypeInfo___::get_Name() {
  return name;
}

EventLevel TraceLoggingTypeInfo___::get_Level() {
  return level;
}

EventOpcode TraceLoggingTypeInfo___::get_Opcode() {
  return opcode;
}

EventKeywords TraceLoggingTypeInfo___::get_Keywords() {
  return keywords;
}

EventTags TraceLoggingTypeInfo___::get_Tags() {
  return tags;
}

Type TraceLoggingTypeInfo___::get_DataType() {
  return dataType;
}

Func<Object, PropertyValue> TraceLoggingTypeInfo___::get_PropertyValueFactory() {
  return propertyValueFactory;
}

void TraceLoggingTypeInfo___::ctor(Type dataType) {
  level = (EventLevel)(-1);
  opcode = (EventOpcode)(-1);
  Object::in::ctor();
  if (dataType == nullptr) {
    rt::throw_exception<ArgumentNullException>("dataType");
  }
  name = dataType->get_Name();
  this->dataType = dataType;
  propertyValueFactory = PropertyValue::GetFactory(dataType);
}

void TraceLoggingTypeInfo___::ctor(Type dataType, String name, EventLevel level, EventOpcode opcode, EventKeywords keywords, EventTags tags) {
  this->level = (EventLevel)(-1);
  this->opcode = (EventOpcode)(-1);
  Object::in::ctor();
  if (dataType == nullptr) {
    rt::throw_exception<ArgumentNullException>("dataType");
  }
  if (name == nullptr) {
    rt::throw_exception<ArgumentNullException>("name");
  }
  Statics::CheckName(name);
  this->name = name;
  this->keywords = keywords;
  this->level = level;
  this->opcode = opcode;
  this->tags = tags;
  this->dataType = dataType;
  propertyValueFactory = PropertyValue::GetFactory(dataType);
}

Object TraceLoggingTypeInfo___::GetData(Object value) {
  return value;
}

TraceLoggingTypeInfo TraceLoggingTypeInfo___::GetInstance(Type type, List<Type> recursionCheck) {
  auto& default = threadCache;
  Dictionary<Type, TraceLoggingTypeInfo> dictionary = default != nullptr ? default : (threadCache = rt::newobj<Dictionary<Type, TraceLoggingTypeInfo>>());
  TraceLoggingTypeInfo value;
  if (!dictionary->TryGetValue(type, value)) {
    if (recursionCheck == nullptr) {
      recursionCheck = rt::newobj<List<Type>>();
    }
    Int32 count = recursionCheck->get_Count();
    value = (dictionary[type] = Statics::CreateDefaultTypeInfo(type, recursionCheck));
    recursionCheck->RemoveRange(count, recursionCheck->get_Count() - count);
  }
  return value;
}

} // namespace System::Private::CoreLib::System::Diagnostics::Tracing::TraceLoggingTypeInfoNamespace
