#include "ExpandoToDispatchExMarshaler-dep.h"

#include <System.Private.CoreLib/System/PlatformNotSupportedException-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/CustomMarshalers/ExpandoToDispatchExMarshaler-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>

namespace System::Private::CoreLib::System::Runtime::InteropServices::CustomMarshalers::ExpandoToDispatchExMarshalerNamespace {
ICustomMarshaler ExpandoToDispatchExMarshaler___::GetInstance(String cookie) {
  return s_ExpandoToDispatchExMarshaler;
}

void ExpandoToDispatchExMarshaler___::ctor() {
}

void ExpandoToDispatchExMarshaler___::CleanUpManagedData(Object ManagedObj) {
}

void ExpandoToDispatchExMarshaler___::CleanUpNativeData(IntPtr pNativeData) {
}

Int32 ExpandoToDispatchExMarshaler___::GetNativeDataSize() {
  return -1;
}

IntPtr ExpandoToDispatchExMarshaler___::MarshalManagedToNative(Object ManagedObj) {
  rt::throw_exception<PlatformNotSupportedException>(SR::get_PlatformNotSupported_IExpando());
}

Object ExpandoToDispatchExMarshaler___::MarshalNativeToManaged(IntPtr pNativeData) {
  rt::throw_exception<PlatformNotSupportedException>(SR::get_PlatformNotSupported_IExpando());
}

void ExpandoToDispatchExMarshaler___::cctor() {
  s_ExpandoToDispatchExMarshaler = rt::newobj<ExpandoToDispatchExMarshaler>();
}

} // namespace System::Private::CoreLib::System::Runtime::InteropServices::CustomMarshalers::ExpandoToDispatchExMarshalerNamespace
