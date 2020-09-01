#include "OleAutBinder-dep.h"

#include <System.Private.CoreLib/Microsoft/Win32/OAVariantLib-dep.h>
#include <System.Private.CoreLib/System/Enum-dep.h>
#include <System.Private.CoreLib/System/NotSupportedException-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/COMException-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/Variant-dep.h>

namespace System::Private::CoreLib::System::OleAutBinderNamespace {
using namespace Microsoft::Win32;
using namespace System::Runtime::InteropServices;

Object OleAutBinder___::ChangeType(Object value, Type type, CultureInfo cultureInfo) {
  Variant source = Variant(value);
  if (cultureInfo == nullptr) {
    cultureInfo = CultureInfo::in::set_CurrentCulture();
  }
  if (type->get_IsByRef()) {
    type = type->GetElementType();
  }
  if (!type->get_IsPrimitive() && type->IsInstanceOfType(value)) {
    return value;
  }
  Type type2 = value->GetType();
  if (type->get_IsEnum() && type2->get_IsPrimitive()) {
    return Enum::in::Parse(type, value->ToString());
  }
  try {
    return OAVariantLib::ChangeType(source, type, 16, cultureInfo).ToObject();
  } catch (NotSupportedException) {
    rt::throw_exception<COMException>(SR::get_Interop_COM_TypeMismatch(), -2147352571);
  }
}

void OleAutBinder___::ctor() {
}

} // namespace System::Private::CoreLib::System::OleAutBinderNamespace
