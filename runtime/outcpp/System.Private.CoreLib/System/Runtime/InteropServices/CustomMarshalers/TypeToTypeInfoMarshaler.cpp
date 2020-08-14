#include "TypeToTypeInfoMarshaler-dep.h"

#include <System.Private.CoreLib/System/PlatformNotSupportedException-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/CustomMarshalers/TypeToTypeInfoMarshaler-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>

namespace System::Private::CoreLib::System::Runtime::InteropServices::CustomMarshalers::TypeToTypeInfoMarshalerNamespace {
ICustomMarshaler TypeToTypeInfoMarshaler___::GetInstance(String cookie) {
  return s_typeToTypeInfoMarshaler;
}

void TypeToTypeInfoMarshaler___::ctor() {
}

void TypeToTypeInfoMarshaler___::CleanUpManagedData(Object ManagedObj) {
}

void TypeToTypeInfoMarshaler___::CleanUpNativeData(IntPtr pNativeData) {
}

Int32 TypeToTypeInfoMarshaler___::GetNativeDataSize() {
  return -1;
}

IntPtr TypeToTypeInfoMarshaler___::MarshalManagedToNative(Object ManagedObj) {
  rt::throw_exception<PlatformNotSupportedException>(SR::get_PlatformNotSupported_ITypeInfo());
}

Object TypeToTypeInfoMarshaler___::MarshalNativeToManaged(IntPtr pNativeData) {
  rt::throw_exception<PlatformNotSupportedException>(SR::get_PlatformNotSupported_ITypeInfo());
}

void TypeToTypeInfoMarshaler___::cctor() {
  s_typeToTypeInfoMarshaler = rt::newobj<TypeToTypeInfoMarshaler>();
}

} // namespace System::Private::CoreLib::System::Runtime::InteropServices::CustomMarshalers::TypeToTypeInfoMarshalerNamespace
