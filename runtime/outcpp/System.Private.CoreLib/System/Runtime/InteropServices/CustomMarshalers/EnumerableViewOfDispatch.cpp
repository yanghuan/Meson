#include "EnumerableViewOfDispatch-dep.h"

#include <System.Private.CoreLib/System/Guid-dep.h>
#include <System.Private.CoreLib/System/IntPtr-dep.h>
#include <System.Private.CoreLib/System/InvalidOperationException-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/ComTypes/DISPPARAMS-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/ComTypes/IEnumVARIANT.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/CustomMarshalers/EnumeratorToEnumVariantMarshaler-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/InvokeFlags.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/Marshal-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/Variant-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>

namespace System::Private::CoreLib::System::Runtime::InteropServices::CustomMarshalers::EnumerableViewOfDispatchNamespace {
using namespace System::Runtime::InteropServices::ComTypes;

IDispatch EnumerableViewOfDispatch___::get_Dispatch() {
  return (IDispatch)_dispatch;
}

void EnumerableViewOfDispatch___::ctor(Object dispatch) {
  _dispatch = dispatch;
}

IEnumerator EnumerableViewOfDispatch___::GetEnumerator() {
  Variant variant;
  void* value = &variant;
  DISPPARAMS pDispParams = DISPPARAMS();
  Guid riid = Guid::Empty;
  get_Dispatch()->Invoke(-4, riid, 1, InvokeFlags::DISPATCH_METHOD | InvokeFlags::DISPATCH_PROPERTYGET, pDispParams, IntPtr(value), IntPtr::Zero, IntPtr::Zero);
  IntPtr intPtr = IntPtr::Zero;
  try{
    Object obj = variant.ToObject();
    IEnumVARIANT enumVARIANT = rt::as<IEnumVARIANT>(obj);
    if (enumVARIANT == nullptr) {
      rt::throw_exception<InvalidOperationException>(SR::get_InvalidOp_InvalidNewEnumVariant());
    }
    intPtr = Marshal::GetIUnknownForObject(enumVARIANT);
    return (IEnumerator)EnumeratorToEnumVariantMarshaler::in::GetInstance(nullptr)->MarshalNativeToManaged(intPtr);
  } catch (...) {
  } finally: {
    variant.Clear();
    if (intPtr != IntPtr::Zero) {
      Marshal::Release(intPtr);
    }
  }
}

Object EnumerableViewOfDispatch___::GetUnderlyingObject() {
  return _dispatch;
}

} // namespace System::Private::CoreLib::System::Runtime::InteropServices::CustomMarshalers::EnumerableViewOfDispatchNamespace
