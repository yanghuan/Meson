#include "TypeNameParser-dep.h"

namespace System::Private::CoreLib::System::TypeNameParserNamespace {
Type TypeNameParser___::GetType(String typeName, Func<AssemblyName, Assembly> assemblyResolver, Func<Assembly, String, Boolean, Type> typeResolver, Boolean throwOnError, Boolean ignoreCase, StackCrawlMark& stackMark) {
  return nullptr;
}

void TypeNameParser___::ctor(SafeTypeNameParserHandle handle) {
}

void TypeNameParser___::Dispose() {
}

Type TypeNameParser___::ConstructType(Func<AssemblyName, Assembly> assemblyResolver, Func<Assembly, String, Boolean, Type> typeResolver, Boolean throwOnError, Boolean ignoreCase, StackCrawlMark& stackMark) {
  return nullptr;
}

Assembly TypeNameParser___::ResolveAssembly(String asmName, Func<AssemblyName, Assembly> assemblyResolver, Boolean throwOnError, StackCrawlMark& stackMark) {
  return nullptr;
}

Type TypeNameParser___::ResolveType(Assembly assembly, Array<String> names, Func<Assembly, String, Boolean, Type> typeResolver, Boolean throwOnError, Boolean ignoreCase, StackCrawlMark& stackMark) {
  return nullptr;
}

String TypeNameParser___::EscapeTypeName(String name) {
  return nullptr;
}

SafeTypeNameParserHandle TypeNameParser___::CreateTypeNameParser(String typeName, Boolean throwOnError) {
  return nullptr;
}

Array<String> TypeNameParser___::GetNames() {
  return Array<String>();
}

Array<SafeTypeNameParserHandle> TypeNameParser___::GetTypeArguments() {
  return Array<SafeTypeNameParserHandle>();
}

Array<Int32> TypeNameParser___::GetModifiers() {
  return Array<Int32>();
}

String TypeNameParser___::GetAssemblyName() {
  return nullptr;
}

void TypeNameParser___::ctor_static() {
}

} // namespace System::Private::CoreLib::System::TypeNameParserNamespace
