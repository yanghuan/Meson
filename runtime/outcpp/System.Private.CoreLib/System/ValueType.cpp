#include "ValueType-dep.h"

#include <System.Private.CoreLib/System/Int32-dep.h>
#include <System.Private.CoreLib/System/Reflection/BindingFlags.h>
#include <System.Private.CoreLib/System/Reflection/FieldInfo-dep.h>
#include <System.Private.CoreLib/System/Type-dep.h>
#include <System.Private.CoreLib/System/ValueType-dep.h>

namespace System::Private::CoreLib::System::ValueTypeNamespace {
using namespace System::Reflection;

Boolean ValueType___::Equals(Object obj) {
  if (obj == nullptr) {
    return false;
  }
  Type type = GetType();
  Type type2 = obj->GetType();
  if (type2 != type) {
    return false;
  }
  if (CanCompareBits((ValueType)this)) {
    return FastEqualsCheck((ValueType)this, obj);
  }
  Array<FieldInfo> fields = type->GetFields(BindingFlags::Instance | BindingFlags::Public | BindingFlags::NonPublic);
  for (Int32 i = 0; i < fields->get_Length(); i++) {
    Object value = fields[i]->GetValue((ValueType)this);
    Object value2 = fields[i]->GetValue(obj);
    if (value == nullptr) {
      if (value2 != nullptr) {
        return false;
      }
    } else if (!value->Equals(value2)) {
      return false;
    }

  }
  return true;
}

String ValueType___::ToString() {
  return GetType()->ToString();
}

void ValueType___::ctor() {
}

} // namespace System::Private::CoreLib::System::ValueTypeNamespace
