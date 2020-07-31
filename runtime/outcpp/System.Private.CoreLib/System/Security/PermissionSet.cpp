#include "PermissionSet-dep.h"

#include <System.Private.CoreLib/System/Security/PermissionSet-dep.h>

namespace System::Private::CoreLib::System::Security::PermissionSetNamespace {
Int32 PermissionSet___::get_Count() {
  return Int32();
}

Boolean PermissionSet___::get_IsReadOnly() {
  return Boolean();
}

Boolean PermissionSet___::get_IsSynchronized() {
  return Boolean();
}

Object PermissionSet___::get_SyncRoot() {
  return nullptr;
}

void PermissionSet___::Ctor(PermissionState state) {
}

void PermissionSet___::Ctor(PermissionSet permSet) {
}

IPermission PermissionSet___::AddPermission(IPermission perm) {
  return nullptr;
}

IPermission PermissionSet___::AddPermissionImpl(IPermission perm) {
  return nullptr;
}

void PermissionSet___::Assert() {
}

Boolean PermissionSet___::ContainsNonCodeAccessPermissions() {
  return Boolean();
}

Array<Byte> PermissionSet___::ConvertPermissionSet(String inFormat, Array<Byte> inData, String outFormat) {
  return Array<Byte>();
}

PermissionSet PermissionSet___::Copy() {
  return nullptr;
}

void PermissionSet___::CopyTo(Array<> array, Int32 index) {
}

void PermissionSet___::Demand() {
}

void PermissionSet___::Deny() {
}

Boolean PermissionSet___::Equals(Object o) {
  return Boolean();
}

void PermissionSet___::FromXml(SecurityElement et) {
}

IEnumerator PermissionSet___::GetEnumerator() {
  return nullptr;
}

IEnumerator PermissionSet___::GetEnumeratorImpl() {
  return nullptr;
}

Int32 PermissionSet___::GetHashCode() {
  return Int32();
}

IPermission PermissionSet___::GetPermission(Type permClass) {
  return nullptr;
}

IPermission PermissionSet___::GetPermissionImpl(Type permClass) {
  return nullptr;
}

PermissionSet PermissionSet___::Intersect(PermissionSet other) {
  return nullptr;
}

Boolean PermissionSet___::IsEmpty() {
  return Boolean();
}

Boolean PermissionSet___::IsSubsetOf(PermissionSet target) {
  return Boolean();
}

Boolean PermissionSet___::IsUnrestricted() {
  return Boolean();
}

void PermissionSet___::PermitOnly() {
}

IPermission PermissionSet___::RemovePermission(Type permClass) {
  return nullptr;
}

IPermission PermissionSet___::RemovePermissionImpl(Type permClass) {
  return nullptr;
}

void PermissionSet___::RevertAssert() {
}

IPermission PermissionSet___::SetPermission(IPermission perm) {
  return nullptr;
}

IPermission PermissionSet___::SetPermissionImpl(IPermission perm) {
  return nullptr;
}

String PermissionSet___::ToString() {
  return nullptr;
}

SecurityElement PermissionSet___::ToXml() {
  return nullptr;
}

PermissionSet PermissionSet___::Union(PermissionSet other) {
  return nullptr;
}

} // namespace System::Private::CoreLib::System::Security::PermissionSetNamespace
