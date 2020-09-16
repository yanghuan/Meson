#include "EnumerableToDispatchMarshaler-dep.h"

#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/Collections/IEnumerable.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/CustomMarshalers/ComDataHelpers-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/CustomMarshalers/EnumerableToDispatchMarshaler-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/Marshal-dep.h>

namespace System::Private::CoreLib::System::Runtime::InteropServices::CustomMarshalers::EnumerableToDispatchMarshalerNamespace {
using namespace System::Collections;

void EnumerableToDispatchMarshaler___::__c___::cctor() {
  __9 = rt::newobj<__c>();
}

void EnumerableToDispatchMarshaler___::__c___::ctor() {
}

EnumerableViewOfDispatch EnumerableToDispatchMarshaler___::__c___::_MarshalNativeToManaged_b__7_0(Object obj) {
  return rt::newobj<EnumerableViewOfDispatch>(obj);
}

ICustomMarshaler EnumerableToDispatchMarshaler___::GetInstance(String cookie) {
  return s_enumerableToDispatchMarshaler;
}

void EnumerableToDispatchMarshaler___::ctor() {
}

void EnumerableToDispatchMarshaler___::CleanUpManagedData(Object ManagedObj) {
}

void EnumerableToDispatchMarshaler___::CleanUpNativeData(IntPtr pNativeData) {
  Marshal::Release(pNativeData);
}

Int32 EnumerableToDispatchMarshaler___::GetNativeDataSize() {
  return -1;
}

IntPtr EnumerableToDispatchMarshaler___::MarshalManagedToNative(Object ManagedObj) {
  if (ManagedObj == nullptr) {
    rt::throw_exception<ArgumentNullException>("ManagedObj");
  }
  return Marshal::GetComInterfaceForObject<Object, IEnumerable>(ManagedObj);
}

Object EnumerableToDispatchMarshaler___::MarshalNativeToManaged(IntPtr pNativeData) {
  if (pNativeData == IntPtr::Zero) {
    rt::throw_exception<ArgumentNullException>("pNativeData");
  }
  Object objectForIUnknown = Marshal::GetObjectForIUnknown(pNativeData);
  Func<Object, EnumerableViewOfDispatch> as = __c::in::__9__7_0;
  return ComDataHelpers::GetOrCreateManagedViewFromComData(objectForIUnknown, as != nullptr ? as : (__c::in::__9__7_0 = {__c::in::__9, &__c::in::_MarshalNativeToManaged_b__7_0}));
}

void EnumerableToDispatchMarshaler___::cctor() {
  s_enumerableToDispatchMarshaler = rt::newobj<EnumerableToDispatchMarshaler>();
}

} // namespace System::Private::CoreLib::System::Runtime::InteropServices::CustomMarshalers::EnumerableToDispatchMarshalerNamespace
