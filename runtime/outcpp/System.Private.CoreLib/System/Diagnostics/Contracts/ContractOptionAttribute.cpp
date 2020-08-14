#include "ContractOptionAttribute-dep.h"

namespace System::Private::CoreLib::System::Diagnostics::Contracts::ContractOptionAttributeNamespace {
String ContractOptionAttribute___::get_Category() {
  return _category;
}

String ContractOptionAttribute___::get_Setting() {
  return _setting;
}

Boolean ContractOptionAttribute___::get_Enabled() {
  return _enabled;
}

String ContractOptionAttribute___::get_Value() {
  return _value;
}

void ContractOptionAttribute___::ctor(String category, String setting, Boolean enabled) {
  _category = category;
  _setting = setting;
  _enabled = enabled;
}

void ContractOptionAttribute___::ctor(String category, String setting, String value) {
  _category = category;
  _setting = setting;
  _value = value;
}

} // namespace System::Private::CoreLib::System::Diagnostics::Contracts::ContractOptionAttributeNamespace
