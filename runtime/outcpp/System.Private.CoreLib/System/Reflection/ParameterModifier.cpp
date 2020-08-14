#include "ParameterModifier-dep.h"

#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>

namespace System::Private::CoreLib::System::Reflection::ParameterModifierNamespace {
Boolean ParameterModifier::get_Item(Int32 index) {
  return _byRef[index];
}

void ParameterModifier::set_Item(Int32 index, Boolean value) {
  _byRef[index] = value;
}

Array<Boolean> ParameterModifier::get_IsByRefArray() {
  return _byRef;
}

ParameterModifier::ParameterModifier(Int32 parameterCount) {
  if (parameterCount <= 0) {
    rt::throw_exception<ArgumentException>(SR::get_Arg_ParmArraySize());
  }
  _byRef = rt::newarr<Array<Boolean>>(parameterCount);
}

} // namespace System::Private::CoreLib::System::Reflection::ParameterModifierNamespace
