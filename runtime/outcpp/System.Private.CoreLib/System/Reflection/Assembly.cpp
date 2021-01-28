#include "Assembly-dep.h"

#include <System.Private.CoreLib/System/Activator-dep.h>
#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/BadImageFormatException-dep.h>
#include <System.Private.CoreLib/System/Collections/Generic/Dictionary-dep.h>
#include <System.Private.CoreLib/System/Collections/Generic/List-dep.h>
#include <System.Private.CoreLib/System/Int32-dep.h>
#include <System.Private.CoreLib/System/IO/FileNotFoundException-dep.h>
#include <System.Private.CoreLib/System/IO/Path-dep.h>
#include <System.Private.CoreLib/System/IO/PathInternal-dep.h>
#include <System.Private.CoreLib/System/NotImplemented-dep.h>
#include <System.Private.CoreLib/System/NotSupportedException-dep.h>
#include <System.Private.CoreLib/System/PlatformNotSupportedException-dep.h>
#include <System.Private.CoreLib/System/Reflection/Assembly-dep.h>
#include <System.Private.CoreLib/System/Reflection/AssemblyName-dep.h>
#include <System.Private.CoreLib/System/Reflection/BindingFlags.h>
#include <System.Private.CoreLib/System/Reflection/IntrospectionExtensions-dep.h>
#include <System.Private.CoreLib/System/Reflection/RuntimeAssembly-dep.h>
#include <System.Private.CoreLib/System/Runtime/Loader/AssemblyLoadContext-dep.h>
#include <System.Private.CoreLib/System/Runtime/Loader/IndividualAssemblyLoadContext-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/Threading/StackCrawlMark.h>
#include <System.Private.CoreLib/System/Type-dep.h>

namespace System::Private::CoreLib::System::Reflection::AssemblyNamespace {
using namespace System::Collections::Generic;
using namespace System::IO;
using namespace System::Runtime::Loader;
using namespace System::Threading;

IEnumerable<TypeInfo> Assembly___::get_DefinedTypes() {
  Array<Type> types = GetTypes();
  Array<TypeInfo> array = rt::newarr<Array<TypeInfo>>(types->get_Length());
  for (Int32 i = 0; i < types->get_Length(); i++) {
    TypeInfo typeInfo = IntrospectionExtensions::GetTypeInfo(types[i]);
    if (typeInfo == nullptr) {
      rt::throw_exception<NotSupportedException>(SR::Format(SR::get_NotSupported_NoTypeInfo(), types[i]->get_FullName()));
    }
    array[i] = typeInfo;
  }
  return array;
}

IEnumerable<Type> Assembly___::get_ExportedTypes() {
  return GetExportedTypes();
}

String Assembly___::get_CodeBase() {
  rt::throw_exception(NotImplemented::get_ByDesign());
}

MethodInfo Assembly___::get_EntryPoint() {
  rt::throw_exception(NotImplemented::get_ByDesign());
}

String Assembly___::get_FullName() {
  rt::throw_exception(NotImplemented::get_ByDesign());
}

String Assembly___::get_ImageRuntimeVersion() {
  rt::throw_exception(NotImplemented::get_ByDesign());
}

Boolean Assembly___::get_IsDynamic() {
  return false;
}

String Assembly___::get_Location() {
  rt::throw_exception(NotImplemented::get_ByDesign());
}

Boolean Assembly___::get_ReflectionOnly() {
  rt::throw_exception(NotImplemented::get_ByDesign());
}

Boolean Assembly___::get_IsCollectible() {
  return true;
}

Boolean Assembly___::get_IsFullyTrusted() {
  return true;
}

IEnumerable<CustomAttributeData> Assembly___::get_CustomAttributes() {
  return GetCustomAttributesData();
}

String Assembly___::get_EscapedCodeBase() {
  return AssemblyName::in::EscapeCodeBase(get_CodeBase());
}

Module Assembly___::get_ManifestModule() {
  rt::throw_exception(NotImplemented::get_ByDesign());
}

IEnumerable<Module> Assembly___::get_Modules() {
  return GetLoadedModules(true);
}

Boolean Assembly___::get_GlobalAssemblyCache() {
  rt::throw_exception(NotImplemented::get_ByDesign());
}

Int64 Assembly___::get_HostContext() {
  rt::throw_exception(NotImplemented::get_ByDesign());
}

SecurityRuleSet Assembly___::get_SecurityRuleSet() {
  return SecurityRuleSet::None;
}

Assembly Assembly___::Load(String assemblyString) {
  StackCrawlMark stackMark = StackCrawlMark::LookForMyCaller;
  return RuntimeAssembly::in::InternalLoad(assemblyString, stackMark, AssemblyLoadContext::in::get_CurrentContextualReflectionContext());
}

Assembly Assembly___::LoadWithPartialName(String partialName) {
  if (partialName == nullptr) {
    rt::throw_exception<ArgumentNullException>("partialName");
  }
  if (partialName->get_Length() == 0 || partialName[0] == u'\0') {
    rt::throw_exception<ArgumentException>(SR::get_Format_StringZeroLength(), "partialName");
  }
  try {
    StackCrawlMark stackMark = StackCrawlMark::LookForMyCaller;
    return RuntimeAssembly::in::InternalLoad(partialName, stackMark, AssemblyLoadContext::in::get_CurrentContextualReflectionContext());
  } catch (FileNotFoundException) {
    return nullptr;
  }
}

Assembly Assembly___::Load(AssemblyName assemblyRef) {
  if (assemblyRef == nullptr) {
    rt::throw_exception<ArgumentNullException>("assemblyRef");
  }
  StackCrawlMark stackMark = StackCrawlMark::LookForMyCaller;
  return RuntimeAssembly::in::InternalLoad(assemblyRef, stackMark, AssemblyLoadContext::in::get_CurrentContextualReflectionContext());
}

RuntimeAssembly Assembly___::GetExecutingAssembly(StackCrawlMark& stackMark) {
  RuntimeAssembly o = nullptr;
  GetExecutingAssemblyNative(StackCrawlMarkHandle(stackMark), ObjectHandleOnStack::Create(o));
  return o;
}

Assembly Assembly___::GetExecutingAssembly() {
  StackCrawlMark stackMark = StackCrawlMark::LookForMyCaller;
  return GetExecutingAssembly(stackMark);
}

Assembly Assembly___::GetCallingAssembly() {
  StackCrawlMark stackMark = StackCrawlMark::LookForMyCallersCaller;
  return GetExecutingAssembly(stackMark);
}

Assembly Assembly___::GetEntryAssemblyInternal() {
  RuntimeAssembly o = nullptr;
  GetEntryAssemblyNative(ObjectHandleOnStack::Create(o));
  return o;
}

Boolean Assembly___::IsRuntimeImplemented() {
  return rt::is<RuntimeAssembly>((Assembly)this);
}

void Assembly___::ctor() {
}

Array<Type> Assembly___::GetTypes() {
  Array<Module> modules = GetModules(false);
  if (modules->get_Length() == 1) {
    return modules[0]->GetTypes();
  }
  Int32 num = 0;
  Array<Type> array = rt::newarr<Array<Array<Type>>>(modules->get_Length());
  for (Int32 i = 0; i < array->get_Length(); i++) {
    array[i] = modules[i]->GetTypes();
    num += array[i]->get_Length();
  }
  Int32 num2 = 0;
  Array<Type> array2 = rt::newarr<Array<Type>>(num);
  for (Int32 j = 0; j < array->get_Length(); j++) {
    Int32 num3 = array[j]->get_Length();
    Array<>::in::Copy(array[j], 0, array2, num2, num3);
    num2 += num3;
  }
  return array2;
}

Array<Type> Assembly___::GetExportedTypes() {
  rt::throw_exception(NotImplemented::get_ByDesign());
}

Array<Type> Assembly___::GetForwardedTypes() {
  rt::throw_exception(NotImplemented::get_ByDesign());
}

ManifestResourceInfo Assembly___::GetManifestResourceInfo(String resourceName) {
  rt::throw_exception(NotImplemented::get_ByDesign());
}

Array<String> Assembly___::GetManifestResourceNames() {
  rt::throw_exception(NotImplemented::get_ByDesign());
}

Stream Assembly___::GetManifestResourceStream(String name) {
  rt::throw_exception(NotImplemented::get_ByDesign());
}

Stream Assembly___::GetManifestResourceStream(Type type, String name) {
  rt::throw_exception(NotImplemented::get_ByDesign());
}

AssemblyName Assembly___::GetName() {
  return GetName(false);
}

AssemblyName Assembly___::GetName(Boolean copiedName) {
  rt::throw_exception(NotImplemented::get_ByDesign());
}

Type Assembly___::GetType(String name) {
  return GetType(name, false, false);
}

Type Assembly___::GetType(String name, Boolean throwOnError) {
  return GetType(name, throwOnError, false);
}

Type Assembly___::GetType(String name, Boolean throwOnError, Boolean ignoreCase) {
  rt::throw_exception(NotImplemented::get_ByDesign());
}

Boolean Assembly___::IsDefined(Type attributeType, Boolean inherit) {
  rt::throw_exception(NotImplemented::get_ByDesign());
}

IList<CustomAttributeData> Assembly___::GetCustomAttributesData() {
  rt::throw_exception(NotImplemented::get_ByDesign());
}

Array<Object> Assembly___::GetCustomAttributes(Boolean inherit) {
  rt::throw_exception(NotImplemented::get_ByDesign());
}

Array<Object> Assembly___::GetCustomAttributes(Type attributeType, Boolean inherit) {
  rt::throw_exception(NotImplemented::get_ByDesign());
}

Object Assembly___::CreateInstance(String typeName) {
  return CreateInstance(typeName, false, BindingFlags::Instance | BindingFlags::Public, nullptr, nullptr, nullptr, nullptr);
}

Object Assembly___::CreateInstance(String typeName, Boolean ignoreCase) {
  return CreateInstance(typeName, ignoreCase, BindingFlags::Instance | BindingFlags::Public, nullptr, nullptr, nullptr, nullptr);
}

Object Assembly___::CreateInstance(String typeName, Boolean ignoreCase, BindingFlags bindingAttr, Binder binder, Array<Object> args, CultureInfo culture, Array<Object> activationAttributes) {
  Type type = GetType(typeName, false, ignoreCase);
  if (type == nullptr) {
    return nullptr;
  }
  return Activator::CreateInstance(type, bindingAttr, binder, args, culture, activationAttributes);
}

Module Assembly___::GetModule(String name) {
  rt::throw_exception(NotImplemented::get_ByDesign());
}

Array<Module> Assembly___::GetModules() {
  return GetModules(false);
}

Array<Module> Assembly___::GetModules(Boolean getResourceModules) {
  rt::throw_exception(NotImplemented::get_ByDesign());
}

Array<Module> Assembly___::GetLoadedModules() {
  return GetLoadedModules(false);
}

Array<Module> Assembly___::GetLoadedModules(Boolean getResourceModules) {
  rt::throw_exception(NotImplemented::get_ByDesign());
}

Array<AssemblyName> Assembly___::GetReferencedAssemblies() {
  rt::throw_exception(NotImplemented::get_ByDesign());
}

Assembly Assembly___::GetSatelliteAssembly(CultureInfo culture) {
  rt::throw_exception(NotImplemented::get_ByDesign());
}

Assembly Assembly___::GetSatelliteAssembly(CultureInfo culture, Version version) {
  rt::throw_exception(NotImplemented::get_ByDesign());
}

FileStream Assembly___::GetFile(String name) {
  rt::throw_exception(NotImplemented::get_ByDesign());
}

Array<FileStream> Assembly___::GetFiles() {
  return GetFiles(false);
}

Array<FileStream> Assembly___::GetFiles(Boolean getResourceModules) {
  rt::throw_exception(NotImplemented::get_ByDesign());
}

void Assembly___::GetObjectData(SerializationInfo info, StreamingContext context) {
  rt::throw_exception(NotImplemented::get_ByDesign());
}

String Assembly___::ToString() {
  String as = get_FullName();
  return as != nullptr ? as : Object::in::ToString();
}

Boolean Assembly___::Equals(Object o) {
  return Object::in::Equals(o);
}

Int32 Assembly___::GetHashCode() {
  return Object::in::GetHashCode();
}

Boolean Assembly___::op_Equality(Assembly left, Assembly right) {
  if ((Object)right == nullptr) {
    if ((Object)left != nullptr) {
      return false;
    }
    return true;
  }
  if ((Object)left == right) {
    return true;
  }
  if ((Object)left != nullptr) {
    return left->Equals(right);
  }
  return false;
}

Boolean Assembly___::op_Inequality(Assembly left, Assembly right) {
  return !(left == right);
}

String Assembly___::CreateQualifiedName(String assemblyName, String typeName) {
  return typeName + ", " + assemblyName;
}

Assembly Assembly___::GetAssembly(Type type) {
  if (type == nullptr) {
    rt::throw_exception<ArgumentNullException>("type");
  }
  Module module = type->get_Module();
  if (module == nullptr) {
    return nullptr;
  }
  return module->get_Assembly();
}

Assembly Assembly___::GetEntryAssembly() {
  if (s_forceNullEntryPoint) {
    return nullptr;
  }
  return GetEntryAssemblyInternal();
}

Assembly Assembly___::Load(Array<Byte> rawAssembly) {
  return Load(rawAssembly, nullptr);
}

Assembly Assembly___::Load(Array<Byte> rawAssembly, Array<Byte> rawSymbolStore) {
  if (rawAssembly == nullptr) {
    rt::throw_exception<ArgumentNullException>("rawAssembly");
  }
  if (rawAssembly->get_Length() == 0) {
    rt::throw_exception<BadImageFormatException>(SR::get_BadImageFormat_BadILFormat());
  }
  SerializationInfo::in::ThrowIfDeserializationInProgress("AllowAssembliesFromByteArrays", s_cachedSerializationSwitch);
  AssemblyLoadContext assemblyLoadContext = rt::newobj<IndividualAssemblyLoadContext>("Assembly.Load(byte[], ...)");
  return assemblyLoadContext->InternalLoad(rawAssembly, rawSymbolStore);
}

Assembly Assembly___::LoadFile(String path) {
  if (path == nullptr) {
    rt::throw_exception<ArgumentNullException>("path");
  }
  if (PathInternal::IsPartiallyQualified(path)) {
    rt::throw_exception<ArgumentException>(SR::Format(SR::get_Argument_AbsolutePathRequired(), path), "path");
  }
  String fullPath = Path::GetFullPath(path);
  {
    rt::lock(s_loadfile);
    Assembly value;
    if (s_loadfile->TryGetValue(fullPath, value)) {
      return value;
    }
    AssemblyLoadContext assemblyLoadContext = rt::newobj<IndividualAssemblyLoadContext>(String::in::Format("Assembly.LoadFile({0})", fullPath));
    value = assemblyLoadContext->LoadFromAssemblyPath(fullPath);
    s_loadfile->Add(fullPath, value);
    return value;
  }
}

Assembly Assembly___::LoadFromResolveHandler(Object sender, ResolveEventArgs args) {
  Assembly requestingAssembly = args->get_RequestingAssembly();
  if (requestingAssembly == nullptr) {
    return nullptr;
  }
  if (AssemblyLoadContext::in::get_Default() != AssemblyLoadContext::in::GetLoadContext(requestingAssembly)) {
    return nullptr;
  }
  String fullPath = Path::GetFullPath(requestingAssembly->get_Location());
  if (String::in::IsNullOrEmpty(fullPath)) {
    return nullptr;
  }
  {
    rt::lock(s_loadFromAssemblyList);
    if (!s_loadFromAssemblyList->Contains(fullPath)) {
      if (AssemblyLoadContext::in::IsTracingEnabled()) {
        AssemblyLoadContext::in::TraceAssemblyLoadFromResolveHandlerInvoked(args->get_Name(), false, fullPath, nullptr);
      }
      return nullptr;
    }
  }
  AssemblyName assemblyName = rt::newobj<AssemblyName>(args->get_Name());
  String text = Path::Combine(Path::GetDirectoryName(fullPath), assemblyName->get_Name() + ".dll");
  if (AssemblyLoadContext::in::IsTracingEnabled()) {
    AssemblyLoadContext::in::TraceAssemblyLoadFromResolveHandlerInvoked(args->get_Name(), true, fullPath, text);
  }
  try {
    return LoadFrom(text);
  } catch (FileNotFoundException) {
    return nullptr;
  }
}

Assembly Assembly___::LoadFrom(String assemblyFile) {
  if (assemblyFile == nullptr) {
    rt::throw_exception<ArgumentNullException>("assemblyFile");
  }
  String fullPath = Path::GetFullPath(assemblyFile);
  if (!s_loadFromHandlerSet) {
    {
      rt::lock(s_loadFromAssemblyList);
      if (!s_loadFromHandlerSet) {
      }
    }
  }
  {
    rt::lock(s_loadFromAssemblyList);
    if (!s_loadFromAssemblyList->Contains(fullPath)) {
      s_loadFromAssemblyList->Add(fullPath);
    }
  }
  return AssemblyLoadContext::in::get_Default()->LoadFromAssemblyPath(fullPath);
}

Assembly Assembly___::LoadFrom(String assemblyFile, Array<Byte> hashValue, AssemblyHashAlgorithm hashAlgorithm) {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_AssemblyLoadFromHash());
}

Assembly Assembly___::UnsafeLoadFrom(String assemblyFile) {
  return LoadFrom(assemblyFile);
}

Module Assembly___::LoadModule(String moduleName, Array<Byte> rawModule) {
  return LoadModule(moduleName, rawModule, nullptr);
}

Module Assembly___::LoadModule(String moduleName, Array<Byte> rawModule, Array<Byte> rawSymbolStore) {
  rt::throw_exception(NotImplemented::get_ByDesign());
}

Assembly Assembly___::ReflectionOnlyLoad(Array<Byte> rawAssembly) {
  rt::throw_exception<PlatformNotSupportedException>(SR::get_PlatformNotSupported_ReflectionOnly());
}

Assembly Assembly___::ReflectionOnlyLoad(String assemblyString) {
  rt::throw_exception<PlatformNotSupportedException>(SR::get_PlatformNotSupported_ReflectionOnly());
}

Assembly Assembly___::ReflectionOnlyLoadFrom(String assemblyFile) {
  rt::throw_exception<PlatformNotSupportedException>(SR::get_PlatformNotSupported_ReflectionOnly());
}

void Assembly___::cctor() {
  s_loadfile = rt::newobj<Dictionary<String, Assembly>>();
  s_loadFromAssemblyList = rt::newobj<List<String>>();
  s_forceNullEntryPoint = false;
}

} // namespace System::Private::CoreLib::System::Reflection::AssemblyNamespace
