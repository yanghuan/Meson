#include "ValueType-dep.h"

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
}

String ValueType___::ToString() {
  return GetType()->ToString();
}

void ValueType___::ctor() {
}

} // namespace System::Private::CoreLib::System::ValueTypeNamespace
