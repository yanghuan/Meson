#include "EnumVariantViewOfEnumerator-dep.h"

#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/Exception-dep.h>
#include <System.Private.CoreLib/System/ICloneable.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/COMException-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/CustomMarshalers/EnumVariantViewOfEnumerator-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/Marshal-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>

namespace System::Private::CoreLib::System::Runtime::InteropServices::CustomMarshalers::EnumVariantViewOfEnumeratorNamespace {
void EnumVariantViewOfEnumerator___::ctor(IEnumerator enumerator) {
  if (enumerator == nullptr) {
    rt::throw_exception<ArgumentNullException>("enumerator");
  }
  Enumerator = enumerator;
}

IEnumVARIANT EnumVariantViewOfEnumerator___::Clone() {
  ICloneable cloneable = rt::as<ICloneable>(Enumerator);
  if (cloneable != nullptr) {
    return rt::newobj<EnumVariantViewOfEnumerator>((IEnumerator)cloneable->Clone());
  }
  rt::throw_exception<COMException>(SR::get_Arg_EnumNotCloneable(), -2147467259);
}

Int32 EnumVariantViewOfEnumerator___::Next(Int32 celt, Array<Object> rgVar, IntPtr pceltFetched) {
  Int32 num = 0;
  try {
    if (celt > 0 && rgVar == nullptr) {
      return -2147024809;
    }
    while (num < celt && Enumerator->MoveNext()) {
      rgVar[num++] = Enumerator->get_Current();
    }
    if (pceltFetched != IntPtr::Zero) {
      Marshal::WriteInt32(pceltFetched, num);
    }
  } catch (Exception ex) {
    return ex->get_HResult();
  }
  if (num != celt) {
    return 1;
  }
  return 0;
}

Int32 EnumVariantViewOfEnumerator___::Reset() {
  try {
    Enumerator->Reset();
  } catch (Exception ex) {
    return ex->get_HResult();
  }
  return 0;
}

Int32 EnumVariantViewOfEnumerator___::Skip(Int32 celt) {
  try {
    while (celt > 0 && Enumerator->MoveNext()) {
      celt--;
    }
  } catch (Exception ex) {
    return ex->get_HResult();
  }
  if (celt != 0) {
    return 1;
  }
  return 0;
}

Object EnumVariantViewOfEnumerator___::GetUnderlyingObject() {
  return Enumerator;
}

} // namespace System::Private::CoreLib::System::Runtime::InteropServices::CustomMarshalers::EnumVariantViewOfEnumeratorNamespace
