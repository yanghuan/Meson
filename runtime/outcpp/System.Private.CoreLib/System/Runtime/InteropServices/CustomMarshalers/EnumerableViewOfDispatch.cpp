#include "EnumerableViewOfDispatch-dep.h"

#include <System.Private.CoreLib/System/Guid-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/ComTypes/DISPPARAMS-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/InvokeFlags.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/Variant-dep.h>

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
}

Object EnumerableViewOfDispatch___::GetUnderlyingObject() {
  return _dispatch;
}

} // namespace System::Private::CoreLib::System::Runtime::InteropServices::CustomMarshalers::EnumerableViewOfDispatchNamespace
