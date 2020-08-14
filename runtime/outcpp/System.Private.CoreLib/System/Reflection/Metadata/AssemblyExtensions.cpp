#include "AssemblyExtensions-dep.h"

#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/Reflection/RuntimeAssembly-dep.h>

namespace System::Private::CoreLib::System::Reflection::Metadata::AssemblyExtensionsNamespace {
Boolean AssemblyExtensions::TryGetRawMetadata(Assembly assembly, Byte*& blob, Int32& length) {
  if (assembly == nullptr) {
    rt::throw_exception<ArgumentNullException>("assembly");
  }
  blob = nullptr;
  length = 0;
  RuntimeAssembly runtimeAssembly = rt::as<RuntimeAssembly>(assembly);
  if (runtimeAssembly == nullptr) {
    return false;
  }
  RuntimeAssembly assembly2 = runtimeAssembly;
  return InternalTryGetRawMetadata(QCallAssembly(assembly2), blob, length);
}

} // namespace System::Private::CoreLib::System::Reflection::Metadata::AssemblyExtensionsNamespace
