#include "AssemblyBuilder-dep.h"

#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/Collections/Generic/List-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/DebuggableAttribute-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/SymbolStore/ISymbolWriter.h>
#include <System.Private.CoreLib/System/Int32-dep.h>
#include <System.Private.CoreLib/System/IntPtr-dep.h>
#include <System.Private.CoreLib/System/InvalidOperationException-dep.h>
#include <System.Private.CoreLib/System/Reflection/Emit/AssemblyBuilder-dep.h>
#include <System.Private.CoreLib/System/Reflection/Emit/AssemblyBuilderData-dep.h>
#include <System.Private.CoreLib/System/Reflection/Emit/SymWrapperCore-dep.h>
#include <System.Private.CoreLib/System/Reflection/Emit/TypeBuilder-dep.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/ObjectHandleOnStack-dep.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/StackCrawlMarkHandle-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>

namespace System::Private::CoreLib::System::Reflection::Emit::AssemblyBuilderNamespace {
using namespace System::Collections::Generic;
using namespace System::Diagnostics;
using namespace System::Diagnostics::SymbolStore;
using namespace System::Runtime::CompilerServices;

Object AssemblyBuilder___::get_SyncRoot() {
  return get_InternalAssembly()->get_SyncRoot();
}

InternalAssemblyBuilder AssemblyBuilder___::get_InternalAssembly() {
  return _internalAssemblyBuilder;
}

String AssemblyBuilder___::get_Location() {
  return get_InternalAssembly()->get_Location();
}

String AssemblyBuilder___::get_ImageRuntimeVersion() {
  return get_InternalAssembly()->get_ImageRuntimeVersion();
}

String AssemblyBuilder___::get_CodeBase() {
  return get_InternalAssembly()->get_CodeBase();
}

MethodInfo AssemblyBuilder___::get_EntryPoint() {
  return _assemblyData->_entryPointMethod;
}

String AssemblyBuilder___::get_FullName() {
  return get_InternalAssembly()->get_FullName();
}

Module AssemblyBuilder___::get_ManifestModule() {
  return _manifestModuleBuilder->get_InternalModule();
}

Boolean AssemblyBuilder___::get_ReflectionOnly() {
  return get_InternalAssembly()->get_ReflectionOnly();
}

Boolean AssemblyBuilder___::get_GlobalAssemblyCache() {
  return get_InternalAssembly()->get_GlobalAssemblyCache();
}

Int64 AssemblyBuilder___::get_HostContext() {
  return get_InternalAssembly()->get_HostContext();
}

Boolean AssemblyBuilder___::get_IsDynamic() {
  return true;
}

Boolean AssemblyBuilder___::get_IsCollectible() {
  return get_InternalAssembly()->get_IsCollectible();
}

ModuleBuilder AssemblyBuilder___::GetModuleBuilder(InternalModuleBuilder module) {
  {
    rt::lock(get_SyncRoot());
    if (_manifestModuleBuilder->get_InternalModule() == module) {
      return _manifestModuleBuilder;
    }
    rt::throw_exception<ArgumentException>(nullptr, "module");
  }
}

RuntimeAssembly AssemblyBuilder___::GetNativeHandle() {
  return get_InternalAssembly()->GetNativeHandle();
}

void AssemblyBuilder___::ctor(AssemblyName name, AssemblyBuilderAccess access, StackCrawlMark& stackMark, IEnumerable<CustomAttributeBuilder> unsafeAssemblyAttributes) {
  if (name == nullptr) {
    rt::throw_exception<ArgumentNullException>("name");
  }
  if (access != AssemblyBuilderAccess::Run && access != AssemblyBuilderAccess::RunAndCollect) {
    rt::throw_exception<ArgumentException>(SR::Format(SR::get_Arg_EnumIllegalVal(), (Int32)access), "access");
  }
  name = (AssemblyName)name->Clone();
  List<CustomAttributeBuilder> list = nullptr;
  if (unsafeAssemblyAttributes != nullptr) {
    list = rt::newobj<List<CustomAttributeBuilder>>(unsafeAssemblyAttributes);
  }
  Assembly o = nullptr;
  CreateDynamicAssembly(ObjectHandleOnStack::Create(name), StackCrawlMarkHandle(stackMark), (Int32)access, ObjectHandleOnStack::Create(o));
  _internalAssemblyBuilder = (InternalAssemblyBuilder)o;
  _assemblyData = rt::newobj<AssemblyBuilderData>(_internalAssemblyBuilder, access);
  InitManifestModule();
  if (list == nullptr) {
    return;
  }
  for (CustomAttributeBuilder&& item : *list) {
    SetCustomAttribute(item);
  }
}

void AssemblyBuilder___::InitManifestModule() {
  InternalModuleBuilder internalModuleBuilder = (InternalModuleBuilder)GetInMemoryAssemblyModule(GetNativeHandle());
  _manifestModuleBuilder = rt::newobj<ModuleBuilder>((AssemblyBuilder)this, internalModuleBuilder);
  _manifestModuleBuilder->Init("RefEmit_InMemoryManifestModule");
  _isManifestModuleUsedAsDefinedModule = false;
}

AssemblyBuilder AssemblyBuilder___::DefineDynamicAssembly(AssemblyName name, AssemblyBuilderAccess access) {
  StackCrawlMark stackMark = StackCrawlMark::LookForMyCaller;
  return InternalDefineDynamicAssembly(name, access, stackMark, nullptr);
}

AssemblyBuilder AssemblyBuilder___::DefineDynamicAssembly(AssemblyName name, AssemblyBuilderAccess access, IEnumerable<CustomAttributeBuilder> assemblyAttributes) {
  StackCrawlMark stackMark = StackCrawlMark::LookForMyCaller;
  return InternalDefineDynamicAssembly(name, access, stackMark, assemblyAttributes);
}

AssemblyBuilder AssemblyBuilder___::InternalDefineDynamicAssembly(AssemblyName name, AssemblyBuilderAccess access, StackCrawlMark& stackMark, IEnumerable<CustomAttributeBuilder> unsafeAssemblyAttributes) {
  {
    rt::lock(s_assemblyBuilderLock);
    return rt::newobj<AssemblyBuilder>(name, access, stackMark, unsafeAssemblyAttributes);
  }
}

ModuleBuilder AssemblyBuilder___::DefineDynamicModule(String name) {
  return DefineDynamicModuleInternal(name, false);
}

ModuleBuilder AssemblyBuilder___::DefineDynamicModule(String name, Boolean emitSymbolInfo) {
  return DefineDynamicModuleInternal(name, emitSymbolInfo);
}

ModuleBuilder AssemblyBuilder___::DefineDynamicModuleInternal(String name, Boolean emitSymbolInfo) {
  {
    rt::lock(get_SyncRoot());
    return DefineDynamicModuleInternalNoLock(name, emitSymbolInfo);
  }
}

ModuleBuilder AssemblyBuilder___::DefineDynamicModuleInternalNoLock(String name, Boolean emitSymbolInfo) {
  if (name == nullptr) {
    rt::throw_exception<ArgumentNullException>("name");
  }
  if (name->get_Length() == 0) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_EmptyName(), "name");
  }
  if (name[0] == '\0') {
    rt::throw_exception<ArgumentException>(SR::get_Argument_InvalidName(), "name");
  }
  if (_isManifestModuleUsedAsDefinedModule) {
    rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_NoMultiModuleAssembly());
  }
  ModuleBuilder manifestModuleBuilder = _manifestModuleBuilder;
  ISymbolWriter symbolWriter = nullptr;
  if (emitSymbolInfo) {
    symbolWriter = SymWrapperCore::in::SymWriter::in::CreateSymWriter();
    IntPtr ppUnderlyingWriter = ModuleBuilder::in::nCreateISymWriterForDynamicModule(manifestModuleBuilder->get_InternalModule(), "Unused");
    ((SymWrapperCore::in::SymWriter)symbolWriter)->InternalSetUnderlyingWriter(ppUnderlyingWriter);
  }
  manifestModuleBuilder->SetSymWriter(symbolWriter);
  _assemblyData->_moduleBuilderList->Add(manifestModuleBuilder);
  if (manifestModuleBuilder == _manifestModuleBuilder) {
    _isManifestModuleUsedAsDefinedModule = true;
  }
  return manifestModuleBuilder;
}

void AssemblyBuilder___::CheckContext(Array<Array<Type>> typess) {
  if (typess == nullptr) {
    return;
  }
  for (Array<Type>&& array : *typess) {
    if (array != nullptr) {
      CheckContext(array);
    }
  }
}

void AssemblyBuilder___::CheckContext(Array<Type> types) {
  if (types == nullptr) {
    return;
  }
  for (Type&& type : *types) {
    if (!(type == nullptr)) {
      if (type->get_Module() == nullptr || type->get_Module()->get_Assembly() == nullptr) {
        rt::throw_exception<ArgumentException>(SR::get_Argument_TypeNotValid());
      }
      Boolean flag = type->get_Module()->get_Assembly() == typeof<Object>()->get_Module()->get_Assembly();
    }
  }
}

Boolean AssemblyBuilder___::Equals(Object obj) {
  return get_InternalAssembly()->Equals(obj);
}

Int32 AssemblyBuilder___::GetHashCode() {
  return get_InternalAssembly()->GetHashCode();
}

Array<Object> AssemblyBuilder___::GetCustomAttributes(Boolean inherit) {
  return get_InternalAssembly()->GetCustomAttributes(inherit);
}

Array<Object> AssemblyBuilder___::GetCustomAttributes(Type attributeType, Boolean inherit) {
  return get_InternalAssembly()->GetCustomAttributes(attributeType, inherit);
}

Boolean AssemblyBuilder___::IsDefined(Type attributeType, Boolean inherit) {
  return get_InternalAssembly()->IsDefined(attributeType, inherit);
}

IList<CustomAttributeData> AssemblyBuilder___::GetCustomAttributesData() {
  return get_InternalAssembly()->GetCustomAttributesData();
}

Array<String> AssemblyBuilder___::GetManifestResourceNames() {
  return get_InternalAssembly()->GetManifestResourceNames();
}

FileStream AssemblyBuilder___::GetFile(String name) {
  return get_InternalAssembly()->GetFile(name);
}

Array<FileStream> AssemblyBuilder___::GetFiles(Boolean getResourceModules) {
  return get_InternalAssembly()->GetFiles(getResourceModules);
}

Stream AssemblyBuilder___::GetManifestResourceStream(Type type, String name) {
  return get_InternalAssembly()->GetManifestResourceStream(type, name);
}

Stream AssemblyBuilder___::GetManifestResourceStream(String name) {
  return get_InternalAssembly()->GetManifestResourceStream(name);
}

ManifestResourceInfo AssemblyBuilder___::GetManifestResourceInfo(String resourceName) {
  return get_InternalAssembly()->GetManifestResourceInfo(resourceName);
}

Array<Type> AssemblyBuilder___::GetExportedTypes() {
  return get_InternalAssembly()->GetExportedTypes();
}

AssemblyName AssemblyBuilder___::GetName(Boolean copiedName) {
  return get_InternalAssembly()->GetName(copiedName);
}

Type AssemblyBuilder___::GetType(String name, Boolean throwOnError, Boolean ignoreCase) {
  return get_InternalAssembly()->GetType(name, throwOnError, ignoreCase);
}

Module AssemblyBuilder___::GetModule(String name) {
  return get_InternalAssembly()->GetModule(name);
}

Array<AssemblyName> AssemblyBuilder___::GetReferencedAssemblies() {
  return get_InternalAssembly()->GetReferencedAssemblies();
}

Array<Module> AssemblyBuilder___::GetModules(Boolean getResourceModules) {
  return get_InternalAssembly()->GetModules(getResourceModules);
}

Array<Module> AssemblyBuilder___::GetLoadedModules(Boolean getResourceModules) {
  return get_InternalAssembly()->GetLoadedModules(getResourceModules);
}

Assembly AssemblyBuilder___::GetSatelliteAssembly(CultureInfo culture) {
  return get_InternalAssembly()->GetSatelliteAssembly(culture, nullptr);
}

Assembly AssemblyBuilder___::GetSatelliteAssembly(CultureInfo culture, Version version) {
  return get_InternalAssembly()->GetSatelliteAssembly(culture, version);
}

ModuleBuilder AssemblyBuilder___::GetDynamicModule(String name) {
  {
    rt::lock(get_SyncRoot());
    return GetDynamicModuleNoLock(name);
  }
}

ModuleBuilder AssemblyBuilder___::GetDynamicModuleNoLock(String name) {
  if (name == nullptr) {
    rt::throw_exception<ArgumentNullException>("name");
  }
  if (name->get_Length() == 0) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_EmptyName(), "name");
  }
  for (Int32 i = 0; i < _assemblyData->_moduleBuilderList->get_Count(); i++) {
    ModuleBuilder moduleBuilder = _assemblyData->_moduleBuilderList[i];
    if (moduleBuilder->_moduleData->_moduleName->Equals(name)) {
      return moduleBuilder;
    }
  }
  return nullptr;
}

void AssemblyBuilder___::SetCustomAttribute(ConstructorInfo con, Array<Byte> binaryAttribute) {
  if (con == nullptr) {
    rt::throw_exception<ArgumentNullException>("con");
  }
  if (binaryAttribute == nullptr) {
    rt::throw_exception<ArgumentNullException>("binaryAttribute");
  }
  {
    rt::lock(get_SyncRoot());
    SetCustomAttributeNoLock(con, binaryAttribute);
  }
}

void AssemblyBuilder___::SetCustomAttributeNoLock(ConstructorInfo con, Array<Byte> binaryAttribute) {
  TypeBuilder::in::DefineCustomAttribute(_manifestModuleBuilder, 536870913, _manifestModuleBuilder->GetConstructorToken(con).get_Token(), binaryAttribute, false, typeof<DebuggableAttribute>() == con->get_DeclaringType());
}

void AssemblyBuilder___::SetCustomAttribute(CustomAttributeBuilder customBuilder) {
  if (customBuilder == nullptr) {
    rt::throw_exception<ArgumentNullException>("customBuilder");
  }
  {
    rt::lock(get_SyncRoot());
    SetCustomAttributeNoLock(customBuilder);
  }
}

void AssemblyBuilder___::SetCustomAttributeNoLock(CustomAttributeBuilder customBuilder) {
  customBuilder->CreateCustomAttribute(_manifestModuleBuilder, 536870913);
}

void AssemblyBuilder___::cctor() {
  s_assemblyBuilderLock = rt::newobj<Object>();
}

} // namespace System::Private::CoreLib::System::Reflection::Emit::AssemblyBuilderNamespace
