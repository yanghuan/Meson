#include "EnumeratorToEnumVariantMarshaler-dep.h"

#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/Collections/IEnumerator.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/CustomMarshalers/ComDataHelpers-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/CustomMarshalers/EnumeratorToEnumVariantMarshaler-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/CustomMarshalers/EnumVariantViewOfEnumerator-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/Marshal-dep.h>

namespace System::Private::CoreLib::System::Runtime::InteropServices::CustomMarshalers::EnumeratorToEnumVariantMarshalerNamespace {
using namespace System::Collections;

void EnumeratorToEnumVariantMarshaler___::__c___::cctor() {
  <>9 = rt::newobj<__c>();
}

void EnumeratorToEnumVariantMarshaler___::__c___::ctor() {
}

EnumeratorViewOfEnumVariant EnumeratorToEnumVariantMarshaler___::__c___::_MarshalNativeToManaged_b__7_0(IEnumVARIANT var) {
  return rt::newobj<EnumeratorViewOfEnumVariant>(var);
}

ICustomMarshaler EnumeratorToEnumVariantMarshaler___::GetInstance(String cookie) {
  return s_enumeratorToEnumVariantMarshaler;
}

void EnumeratorToEnumVariantMarshaler___::ctor() {
}

void EnumeratorToEnumVariantMarshaler___::CleanUpManagedData(Object ManagedObj) {
}

void EnumeratorToEnumVariantMarshaler___::CleanUpNativeData(IntPtr pNativeData) {
  Marshal::Release(pNativeData);
}

Int32 EnumeratorToEnumVariantMarshaler___::GetNativeDataSize() {
  return -1;
}

IntPtr EnumeratorToEnumVariantMarshaler___::MarshalManagedToNative(Object ManagedObj) {
  if (ManagedObj == nullptr) {
    rt::throw_exception<ArgumentNullException>("ManagedObj");
  }
  EnumeratorViewOfEnumVariant enumeratorViewOfEnumVariant = rt::as<EnumeratorViewOfEnumVariant>(ManagedObj);
  if (enumeratorViewOfEnumVariant != nullptr) {
    return Marshal::GetComInterfaceForObject<Object, IEnumVARIANT>(enumeratorViewOfEnumVariant->GetUnderlyingObject());
  }
  EnumVariantViewOfEnumerator o = rt::newobj<EnumVariantViewOfEnumerator>((IEnumerator)ManagedObj);
  return Marshal::GetComInterfaceForObject<EnumVariantViewOfEnumerator, IEnumVARIANT>(o);
}

Object EnumeratorToEnumVariantMarshaler___::MarshalNativeToManaged(IntPtr pNativeData) {
  if (pNativeData == IntPtr::Zero) {
    rt::throw_exception<ArgumentNullException>("pNativeData");
  }
  Object objectForIUnknown = Marshal::GetObjectForIUnknown(pNativeData);
  if (!objectForIUnknown->GetType()->get_IsCOMObject()) {
    EnumVariantViewOfEnumerator enumVariantViewOfEnumerator = rt::as<EnumVariantViewOfEnumerator>(objectForIUnknown);
    if (enumVariantViewOfEnumerator != nullptr) {
      return enumVariantViewOfEnumerator->get_Enumerator();
    }
    return rt::as<IEnumerator>(objectForIUnknown);
  }
  Func<IEnumVARIANT, EnumeratorViewOfEnumVariant> as = __c::in::__9__7_0;
  return ComDataHelpers::GetOrCreateManagedViewFromComData(objectForIUnknown, as != nullptr ? as : (__c::in::__9__7_0 = &__c::in::__9->_MarshalNativeToManaged_b__7_0));
}

void EnumeratorToEnumVariantMarshaler___::cctor() {
  s_enumeratorToEnumVariantMarshaler = rt::newobj<EnumeratorToEnumVariantMarshaler>();
}

} // namespace System::Private::CoreLib::System::Runtime::InteropServices::CustomMarshalers::EnumeratorToEnumVariantMarshalerNamespace
