#include "RuntimeAssembly-dep.h"

#include <System.Private.CoreLib/Interop-dep.h>
#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/Collections/Generic/List-dep.h>
#include <System.Private.CoreLib/System/Configuration/Assemblies/AssemblyVersionCompatibility.h>
#include <System.Private.CoreLib/System/Exception-dep.h>
#include <System.Private.CoreLib/System/GC-dep.h>
#include <System.Private.CoreLib/System/Int32-dep.h>
#include <System.Private.CoreLib/System/IO/FileMode.h>
#include <System.Private.CoreLib/System/IO/FileShare.h>
#include <System.Private.CoreLib/System/IRuntimeMethodInfo.h>
#include <System.Private.CoreLib/System/NotSupportedException-dep.h>
#include <System.Private.CoreLib/System/PlatformNotSupportedException-dep.h>
#include <System.Private.CoreLib/System/Reflection/BindingFlags.h>
#include <System.Private.CoreLib/System/Reflection/CustomAttribute-dep.h>
#include <System.Private.CoreLib/System/Reflection/MetadataTokenType.h>
#include <System.Private.CoreLib/System/Reflection/ResourceLocation.h>
#include <System.Private.CoreLib/System/Reflection/RuntimeAssembly-dep.h>
#include <System.Private.CoreLib/System/Reflection/RuntimeModule-dep.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/ObjectHandleOnStack-dep.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/QCallAssembly-dep.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/StackCrawlMarkHandle-dep.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/StringHandleOnStack-dep.h>
#include <System.Private.CoreLib/System/Runtime/Loader/AssemblyLoadContext-dep.h>
#include <System.Private.CoreLib/System/RuntimeType-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/Threading/Interlocked-dep.h>

namespace System::Private::CoreLib::System::Reflection::RuntimeAssemblyNamespace {
using namespace System::Collections::Generic;
using namespace System::Configuration::Assemblies;
using namespace System::IO;
using namespace System::Runtime::CompilerServices;
using namespace System::Runtime::Loader;
using namespace System::Threading;

void RuntimeAssembly___::ManifestResourceStream___::ctor(RuntimeAssembly manifestAssembly, Byte* pointer, Int64 length, Int64 capacity, FileAccess access) {
  _manifestAssembly = manifestAssembly;
}

Object RuntimeAssembly___::get_SyncRoot() {
  if (m_syncRoot == nullptr) {
    Interlocked::CompareExchange<Object>(m_syncRoot, rt::newobj<Object>(), (Object)nullptr);
  }
  return m_syncRoot;
}

String RuntimeAssembly___::get_CodeBase() {
  return GetCodeBase(false);
}

String RuntimeAssembly___::get_FullName() {
  if (m_fullname == nullptr) {
    String s = nullptr;
    RuntimeAssembly assembly = (RuntimeAssembly)this;
    GetFullName(QCallAssembly(assembly), StringHandleOnStack(s));
    Interlocked::CompareExchange(m_fullname, s, nullptr);
  }
  return m_fullname;
}

MethodInfo RuntimeAssembly___::get_EntryPoint() {
  IRuntimeMethodInfo o = nullptr;
  RuntimeAssembly assembly = (RuntimeAssembly)this;
  GetEntryPoint(QCallAssembly(assembly), ObjectHandleOnStack::Create(o));
  if (o == nullptr) {
    return nullptr;
  }
  return (MethodInfo)RuntimeType::in::GetMethodBase(o);
}

IEnumerable<TypeInfo> RuntimeAssembly___::get_DefinedTypes() {
  Array<RuntimeModule> modulesInternal = GetModulesInternal(true, false);
  if (modulesInternal->get_Length() == 1) {
    return modulesInternal[0]->GetDefinedTypes();
  }
  List<RuntimeType> list = rt::newobj<List<RuntimeType>>();
  for (Int32 i = 0; i < modulesInternal->get_Length(); i++) {
    list->AddRange(modulesInternal[i]->GetDefinedTypes());
  }
  return list->ToArray();
}

Boolean RuntimeAssembly___::get_IsCollectible() {
  RuntimeAssembly assembly = (RuntimeAssembly)this;
  return GetIsCollectible(QCallAssembly(assembly)) != Interop::BOOL::FALSE;
}

Module RuntimeAssembly___::get_ManifestModule() {
  return GetManifestModule(GetNativeHandle());
}

Boolean RuntimeAssembly___::get_ReflectionOnly() {
  return false;
}

String RuntimeAssembly___::get_Location() {
  String s = nullptr;
  RuntimeAssembly assembly = (RuntimeAssembly)this;
  GetLocation(QCallAssembly(assembly), StringHandleOnStack(s));
  return s;
}

String RuntimeAssembly___::get_ImageRuntimeVersion() {
  String s = nullptr;
  RuntimeAssembly assembly = (RuntimeAssembly)this;
  GetImageRuntimeVersion(QCallAssembly(assembly), StringHandleOnStack(s));
  return s;
}

Boolean RuntimeAssembly___::get_GlobalAssemblyCache() {
  return false;
}

Int64 RuntimeAssembly___::get_HostContext() {
  return 0;
}

Boolean RuntimeAssembly___::get_IsDynamic() {
  return FCallIsDynamic(GetNativeHandle());
}

void RuntimeAssembly___::ctor() {
  rt::throw_exception<NotSupportedException>();
}

IntPtr RuntimeAssembly___::GetUnderlyingNativeHandle() {
  return m_assembly;
}

String RuntimeAssembly___::GetCodeBase(Boolean copiedName) {
  String s = nullptr;
  RuntimeAssembly assembly = (RuntimeAssembly)this;
  GetCodeBase(QCallAssembly(assembly), copiedName, StringHandleOnStack(s));
  return s;
}

RuntimeAssembly RuntimeAssembly___::GetNativeHandle() {
  return (RuntimeAssembly)this;
}

AssemblyName RuntimeAssembly___::GetName(Boolean copiedName) {
  String codeBase = GetCodeBase(copiedName);
}

Type RuntimeAssembly___::GetType(String name, Boolean throwOnError, Boolean ignoreCase) {
  if (name == nullptr) {
    rt::throw_exception<ArgumentNullException>("name");
  }
  RuntimeType o = nullptr;
  Object o2 = nullptr;
  AssemblyLoadContext o3 = AssemblyLoadContext::in::get_CurrentContextualReflectionContext();
  RuntimeAssembly assembly = (RuntimeAssembly)this;
  GetType(QCallAssembly(assembly), name, throwOnError, ignoreCase, ObjectHandleOnStack::Create(o), ObjectHandleOnStack::Create(o2), ObjectHandleOnStack::Create(o3));
  GC::KeepAlive(o2);
  return o;
}

Array<Type> RuntimeAssembly___::GetExportedTypes() {
  Array<Type> o = nullptr;
  RuntimeAssembly assembly = (RuntimeAssembly)this;
  GetExportedTypes(QCallAssembly(assembly), ObjectHandleOnStack::Create(o));
  return o;
}

Stream RuntimeAssembly___::GetManifestResourceStream(Type type, String name) {
  if (type == nullptr && name == nullptr) {
    rt::throw_exception<ArgumentNullException>("type");
  }
}

Stream RuntimeAssembly___::GetManifestResourceStream(String name) {
  RuntimeAssembly assembly = (RuntimeAssembly)this;
  UInt32 length;
  Byte* resource = GetResource(QCallAssembly(assembly), name, length);
  if (resource != nullptr) {
    return rt::newobj<ManifestResourceStream>((RuntimeAssembly)this, resource, length, length, FileAccess::Read);
  }
  return nullptr;
}

void RuntimeAssembly___::GetObjectData(SerializationInfo info, StreamingContext context) {
  rt::throw_exception<PlatformNotSupportedException>();
}

Array<Object> RuntimeAssembly___::GetCustomAttributes(Boolean inherit) {
}

Array<Object> RuntimeAssembly___::GetCustomAttributes(Type attributeType, Boolean inherit) {
  if (attributeType == nullptr) {
    rt::throw_exception<ArgumentNullException>("attributeType");
  }
  RuntimeType runtimeType = rt::as<RuntimeType>(attributeType->get_UnderlyingSystemType());
  if (runtimeType == nullptr) {
    rt::throw_exception<ArgumentException>(SR::get_Arg_MustBeType(), "attributeType");
  }
  return CustomAttribute::GetCustomAttributes((RuntimeAssembly)this, runtimeType);
}

Boolean RuntimeAssembly___::IsDefined(Type attributeType, Boolean inherit) {
  if (attributeType == nullptr) {
    rt::throw_exception<ArgumentNullException>("attributeType");
  }
  RuntimeType runtimeType = rt::as<RuntimeType>(attributeType->get_UnderlyingSystemType());
  if (runtimeType == nullptr) {
    rt::throw_exception<ArgumentException>(SR::get_Arg_MustBeType(), "attributeType");
  }
  return CustomAttribute::IsDefined((RuntimeAssembly)this, runtimeType);
}

IList<CustomAttributeData> RuntimeAssembly___::GetCustomAttributesData() {
  return CustomAttributeData::in::GetCustomAttributesInternal((RuntimeAssembly)this);
}

RuntimeAssembly RuntimeAssembly___::InternalLoad(String assemblyName, StackCrawlMark& stackMark, AssemblyLoadContext assemblyLoadContext) {
  return InternalLoad(rt::newobj<AssemblyName>(assemblyName), stackMark, assemblyLoadContext);
}

RuntimeAssembly RuntimeAssembly___::InternalLoad(AssemblyName assemblyName, StackCrawlMark& stackMark, AssemblyLoadContext assemblyLoadContext) {
  return InternalLoad(assemblyName, nullptr, stackMark, true, assemblyLoadContext);
}

RuntimeAssembly RuntimeAssembly___::InternalLoad(AssemblyName assemblyName, RuntimeAssembly requestingAssembly, StackCrawlMark& stackMark, Boolean throwOnFileNotFound, AssemblyLoadContext assemblyLoadContext) {
  RuntimeAssembly o = nullptr;
  InternalLoad(ObjectHandleOnStack::Create(assemblyName), ObjectHandleOnStack::Create(requestingAssembly), StackCrawlMarkHandle(stackMark), throwOnFileNotFound, ObjectHandleOnStack::Create(assemblyLoadContext), ObjectHandleOnStack::Create(o));
  return o;
}

Module RuntimeAssembly___::GetModule(String name) {
  Module o = nullptr;
  RuntimeAssembly assembly = (RuntimeAssembly)this;
  GetModule(QCallAssembly(assembly), name, ObjectHandleOnStack::Create(o));
  return o;
}

FileStream RuntimeAssembly___::GetFile(String name) {
  RuntimeModule runtimeModule = (RuntimeModule)GetModule(name);
  if (runtimeModule == nullptr) {
    return nullptr;
  }
  return rt::newobj<FileStream>(runtimeModule->GetFullyQualifiedName(), FileMode::Open, FileAccess::Read, FileShare::Read, 4096, false);
}

Array<FileStream> RuntimeAssembly___::GetFiles(Boolean getResourceModules) {
  Array<Module> modules = GetModules(getResourceModules);
  Array<FileStream> array = rt::newarr<Array<FileStream>>(modules->get_Length());
  for (Int32 i = 0; i < array->get_Length(); i++) {
    array[i] = rt::newobj<FileStream>(((RuntimeModule)modules[i])->GetFullyQualifiedName(), FileMode::Open, FileAccess::Read, FileShare::Read, 4096, false);
  }
  return array;
}

Array<String> RuntimeAssembly___::GetManifestResourceNames() {
  return GetManifestResourceNames(GetNativeHandle());
}

Array<AssemblyName> RuntimeAssembly___::GetReferencedAssemblies() {
  return GetReferencedAssemblies(GetNativeHandle());
}

ManifestResourceInfo RuntimeAssembly___::GetManifestResourceInfo(String resourceName) {
  RuntimeAssembly o = nullptr;
  String s = nullptr;
  RuntimeAssembly assembly = (RuntimeAssembly)this;
  Int32 manifestResourceInfo = GetManifestResourceInfo(QCallAssembly(assembly), resourceName, ObjectHandleOnStack::Create(o), StringHandleOnStack(s));
  if (manifestResourceInfo == -1) {
    return nullptr;
  }
  return rt::newobj<ManifestResourceInfo>(o, s, (ResourceLocation)manifestResourceInfo);
}

Version RuntimeAssembly___::GetVersion() {
  RuntimeAssembly assembly = (RuntimeAssembly)this;
}

CultureInfo RuntimeAssembly___::GetLocale() {
  String s = nullptr;
  RuntimeAssembly assembly = (RuntimeAssembly)this;
  GetLocale(QCallAssembly(assembly), StringHandleOnStack(s));
  if (s == nullptr) {
    return CultureInfo::in::get_InvariantCulture();
  }
  return CultureInfo::in::GetCultureInfo(s);
}

String RuntimeAssembly___::GetSimpleName() {
  RuntimeAssembly assembly = (RuntimeAssembly)this;
  String s = nullptr;
  GetSimpleName(QCallAssembly(assembly), StringHandleOnStack(s));
  return s;
}

AssemblyHashAlgorithm RuntimeAssembly___::GetHashAlgorithm() {
  RuntimeAssembly assembly = (RuntimeAssembly)this;
  return GetHashAlgorithm(QCallAssembly(assembly));
}

AssemblyNameFlags RuntimeAssembly___::GetFlags() {
  RuntimeAssembly assembly = (RuntimeAssembly)this;
  return GetFlags(QCallAssembly(assembly));
}

Array<Byte> RuntimeAssembly___::GetPublicKey() {
  Array<Byte> o = nullptr;
  RuntimeAssembly assembly = (RuntimeAssembly)this;
  GetPublicKey(QCallAssembly(assembly), ObjectHandleOnStack::Create(o));
  return o;
}

Assembly RuntimeAssembly___::GetSatelliteAssembly(CultureInfo culture) {
  return GetSatelliteAssembly(culture, nullptr);
}

Assembly RuntimeAssembly___::GetSatelliteAssembly(CultureInfo culture, Version version) {
  if (culture == nullptr) {
    rt::throw_exception<ArgumentNullException>("culture");
  }
  return InternalGetSatelliteAssembly(culture, version, true);
}

Assembly RuntimeAssembly___::InternalGetSatelliteAssembly(CultureInfo culture, Version version, Boolean throwOnFileNotFound) {
  AssemblyName assemblyName = rt::newobj<AssemblyName>();
  assemblyName->SetPublicKey(GetPublicKey());
}

Array<RuntimeModule> RuntimeAssembly___::GetModulesInternal(Boolean loadIfNotFound, Boolean getResourceModules) {
  Array<RuntimeModule> o = nullptr;
  RuntimeAssembly assembly = (RuntimeAssembly)this;
  GetModules(QCallAssembly(assembly), loadIfNotFound, getResourceModules, ObjectHandleOnStack::Create(o));
  return o;
}

Array<Module> RuntimeAssembly___::GetModules(Boolean getResourceModules) {
  return GetModulesInternal(true, getResourceModules);
}

Array<Module> RuntimeAssembly___::GetLoadedModules(Boolean getResourceModules) {
  return GetModulesInternal(false, getResourceModules);
}

Array<Type> RuntimeAssembly___::GetForwardedTypes() {
  List<Type> list = rt::newobj<List<Type>>();
  List<Exception> list2 = rt::newobj<List<Exception>>();
}

void RuntimeAssembly___::AddPublicNestedTypes(Type type, List<Type> types, List<Exception> exceptions) {
  Array<Type> nestedTypes;
  try{
    nestedTypes = type->GetNestedTypes(BindingFlags::Public);
  } catch (Exception item) {
  }
  Array<Type> array = nestedTypes;
}

} // namespace System::Private::CoreLib::System::Reflection::RuntimeAssemblyNamespace
