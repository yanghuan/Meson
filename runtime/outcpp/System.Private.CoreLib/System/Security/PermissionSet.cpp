#include "PermissionSet-dep.h"

#include <System.Private.CoreLib/System/PlatformNotSupportedException-dep.h>
#include <System.Private.CoreLib/System/Security/PermissionSet-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>

namespace System::Private::CoreLib::System::Security::PermissionSetNamespace {
Int32 PermissionSet___::get_Count() {
  return 0;
}

Boolean PermissionSet___::get_IsReadOnly() {
  return false;
}

Boolean PermissionSet___::get_IsSynchronized() {
  return false;
}

Object PermissionSet___::get_SyncRoot() {
  return (PermissionSet)this;
}

void PermissionSet___::ctor(PermissionState state) {
}

void PermissionSet___::ctor(PermissionSet permSet) {
}

IPermission PermissionSet___::AddPermission(IPermission perm) {
  return AddPermissionImpl(perm);
}

IPermission PermissionSet___::AddPermissionImpl(IPermission perm) {
  return nullptr;
}

void PermissionSet___::Assert() {
}

Boolean PermissionSet___::ContainsNonCodeAccessPermissions() {
  return false;
}

Array<Byte> PermissionSet___::ConvertPermissionSet(String inFormat, Array<Byte> inData, String outFormat) {
  rt::throw_exception<PlatformNotSupportedException>(SR::get_PlatformNotSupported_CAS());
}

PermissionSet PermissionSet___::Copy() {
  return rt::newobj<PermissionSet>((PermissionSet)this);
}

void PermissionSet___::CopyTo(Array<> array, Int32 index) {
}

void PermissionSet___::Demand() {
}

void PermissionSet___::Deny() {
  rt::throw_exception<PlatformNotSupportedException>(SR::get_PlatformNotSupported_CAS());
}

Boolean PermissionSet___::Equals(Object o) {
  return Object::in::Equals(o);
}

void PermissionSet___::FromXml(SecurityElement et) {
}

IEnumerator PermissionSet___::GetEnumerator() {
  return GetEnumeratorImpl();
}

IEnumerator PermissionSet___::GetEnumeratorImpl() {
  return Array<>::in::Empty<Object>()->GetEnumerator();
}

Int32 PermissionSet___::GetHashCode() {
  return Object::in::GetHashCode();
}

IPermission PermissionSet___::GetPermission(Type permClass) {
  return GetPermissionImpl(permClass);
}

IPermission PermissionSet___::GetPermissionImpl(Type permClass) {
  return nullptr;
}

PermissionSet PermissionSet___::Intersect(PermissionSet other) {
  return nullptr;
}

Boolean PermissionSet___::IsEmpty() {
  return false;
}

Boolean PermissionSet___::IsSubsetOf(PermissionSet target) {
  return false;
}

Boolean PermissionSet___::IsUnrestricted() {
  return false;
}

void PermissionSet___::PermitOnly() {
  rt::throw_exception<PlatformNotSupportedException>(SR::get_PlatformNotSupported_CAS());
}

IPermission PermissionSet___::RemovePermission(Type permClass) {
  return RemovePermissionImpl(permClass);
}

IPermission PermissionSet___::RemovePermissionImpl(Type permClass) {
  return nullptr;
}

void PermissionSet___::RevertAssert() {
}

IPermission PermissionSet___::SetPermission(IPermission perm) {
  return SetPermissionImpl(perm);
}

IPermission PermissionSet___::SetPermissionImpl(IPermission perm) {
  return nullptr;
}

void PermissionSet___::OnDeserializationOfIDeserializationCallback(Object sender) {
}

String PermissionSet___::ToString() {
  return Object::in::ToString();
}

SecurityElement PermissionSet___::ToXml() {
  return nullptr;
}

PermissionSet PermissionSet___::Union(PermissionSet other) {
  return nullptr;
}

} // namespace System::Private::CoreLib::System::Security::PermissionSetNamespace
