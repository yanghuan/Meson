#include "OAVariantLib-dep.h"

#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>

namespace System::Private::CoreLib::Microsoft::Win32::OAVariantLibNamespace {
using namespace System;

Variant OAVariantLib::ChangeType(Variant source, Type targetClass, Int16 options, CultureInfo culture) {
  if (targetClass == nullptr) {
    rt::throw_exception<ArgumentNullException>("targetClass");
  }
  if (culture == nullptr) {
    rt::throw_exception<ArgumentNullException>("culture");
  }
  Variant result = rt::default__;
  ChangeTypeEx(result, source, culture->get_LCID(), targetClass->get_TypeHandle().get_Value(), GetCVTypeFromClass(targetClass), options);
  return result;
}

Int32 OAVariantLib::GetCVTypeFromClass(Type ctype) {
  Int32 num = -1;
  for (Int32 i = 0; i < ClassTypes->get_Length(); i++) {
    if (ctype->Equals(ClassTypes[i])) {
      num = i;
      break;
    }
  }
  if (num == -1) {
    num = 18;
  }
  return num;
}

void OAVariantLib::cctor() {
  ClassTypes = rt::newarr<Array<Type>>(23);
}

} // namespace System::Private::CoreLib::Microsoft::Win32::OAVariantLibNamespace
