#include "InternalAssemblyBuilder-dep.h"

#include <System.Private.CoreLib/System/NotSupportedException-dep.h>
#include <System.Private.CoreLib/System/Reflection/Assembly-dep.h>
#include <System.Private.CoreLib/System/Reflection/Emit/InternalAssemblyBuilder-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>

namespace System::Private::CoreLib::System::Reflection::Emit::InternalAssemblyBuilderNamespace {
String InternalAssemblyBuilder___::get_Location() {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_DynamicAssembly());
}

String InternalAssemblyBuilder___::get_CodeBase() {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_DynamicAssembly());
}

String InternalAssemblyBuilder___::get_ImageRuntimeVersion() {
  return Assembly::in::GetExecutingAssembly()->get_ImageRuntimeVersion();
}

void InternalAssemblyBuilder___::ctor() {
}

Boolean InternalAssemblyBuilder___::Equals(Object obj) {
  if (obj == nullptr) {
    return false;
  }
  if (rt::is<InternalAssemblyBuilder>(obj)) {
    return (InternalAssemblyBuilder)this == obj;
  }
  return obj->Equals((InternalAssemblyBuilder)this);
}

Int32 InternalAssemblyBuilder___::GetHashCode() {
  return Assembly::GetHashCode();
}

Array<String> InternalAssemblyBuilder___::GetManifestResourceNames() {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_DynamicAssembly());
}

FileStream InternalAssemblyBuilder___::GetFile(String name) {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_DynamicAssembly());
}

Array<FileStream> InternalAssemblyBuilder___::GetFiles(Boolean getResourceModules) {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_DynamicAssembly());
}

Stream InternalAssemblyBuilder___::GetManifestResourceStream(Type type, String name) {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_DynamicAssembly());
}

Stream InternalAssemblyBuilder___::GetManifestResourceStream(String name) {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_DynamicAssembly());
}

ManifestResourceInfo InternalAssemblyBuilder___::GetManifestResourceInfo(String resourceName) {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_DynamicAssembly());
}

Array<Type> InternalAssemblyBuilder___::GetExportedTypes() {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_DynamicAssembly());
}

} // namespace System::Private::CoreLib::System::Reflection::Emit::InternalAssemblyBuilderNamespace
