#include "AttributeUsageAttribute-dep.h"

#include <System.Private.CoreLib/System/AttributeUsageAttribute-dep.h>

namespace System::Private::CoreLib::System::AttributeUsageAttributeNamespace {
AttributeTargets AttributeUsageAttribute___::get_ValidOn() {
  return _attributeTarget;
}

Boolean AttributeUsageAttribute___::get_AllowMultiple() {
  return _allowMultiple;
}

void AttributeUsageAttribute___::set_AllowMultiple(Boolean value) {
  _allowMultiple = value;
}

Boolean AttributeUsageAttribute___::get_Inherited() {
  return _inherited;
}

void AttributeUsageAttribute___::set_Inherited(Boolean value) {
  _inherited = value;
}

void AttributeUsageAttribute___::ctor(AttributeTargets validOn) {
  _attributeTarget = validOn;
  _inherited = true;
}

void AttributeUsageAttribute___::ctor(AttributeTargets validOn, Boolean allowMultiple, Boolean inherited) {
  _attributeTarget = validOn;
  _allowMultiple = allowMultiple;
  _inherited = inherited;
}

void AttributeUsageAttribute___::ctor_static() {
  Default = rt::newobj<AttributeUsageAttribute>(AttributeTargets::All);
}

} // namespace System::Private::CoreLib::System::AttributeUsageAttributeNamespace
