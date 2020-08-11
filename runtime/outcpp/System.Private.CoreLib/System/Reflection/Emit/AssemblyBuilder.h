#pragma once

#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/Reflection/Assembly.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Byte)
FORWARDS(Int32)
FORWARDS(Int64)
FORWARD(Object)
FORWARD(String)
FORWARD(Type)
FORWARD(Version)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection {
FORWARD(AssemblyName)
FORWARD(ConstructorInfo)
FORWARD(CustomAttributeData)
FORWARD(ManifestResourceInfo)
FORWARD(MethodInfo)
FORWARD(Module)
FORWARD(RuntimeAssembly)
FORWARD(RuntimeModule)
} // namespace System::Private::CoreLib::System::Reflection
namespace System::Private::CoreLib::System::Threading {
enum class StackCrawlMark : int32_t;
} // namespace System::Private::CoreLib::System::Threading
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(IEnumerable, T)
FORWARD(IList, T)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System::Runtime::CompilerServices {
FORWARDS(ObjectHandleOnStack)
FORWARDS(StackCrawlMarkHandle)
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
namespace System::Private::CoreLib::System::IO {
FORWARD(FileStream)
FORWARD(Stream)
} // namespace System::Private::CoreLib::System::IO
namespace System::Private::CoreLib::System::Globalization {
FORWARD(CultureInfo)
} // namespace System::Private::CoreLib::System::Globalization
namespace System::Private::CoreLib::System::Reflection::Emit {
enum class AssemblyBuilderAccess : int32_t;
FORWARD(AssemblyBuilderData)
FORWARD(CustomAttributeBuilder)
FORWARD(InternalAssemblyBuilder)
FORWARD(InternalModuleBuilder)
FORWARD(ModuleBuilder)
namespace AssemblyBuilderNamespace {
using namespace Collections::Generic;
using namespace Globalization;
using namespace IO;
using namespace Runtime::CompilerServices;
using namespace Threading;
CLASS(AssemblyBuilder) : public Assembly::in {
  public: Object get_SyncRoot();
  public: InternalAssemblyBuilder get_InternalAssembly();
  public: String get_Location();
  public: String get_ImageRuntimeVersion();
  public: String get_CodeBase();
  public: MethodInfo get_EntryPoint();
  public: String get_FullName();
  public: Module get_ManifestModule();
  public: Boolean get_ReflectionOnly();
  public: Boolean get_GlobalAssemblyCache();
  public: Int64 get_HostContext();
  public: Boolean get_IsDynamic();
  public: Boolean get_IsCollectible();
  private: static RuntimeModule GetInMemoryAssemblyModule(RuntimeAssembly assembly);
  public: ModuleBuilder GetModuleBuilder(InternalModuleBuilder module);
  public: RuntimeAssembly GetNativeHandle();
  public: void ctor(AssemblyName name, AssemblyBuilderAccess access, StackCrawlMark& stackMark, IEnumerable<CustomAttributeBuilder> unsafeAssemblyAttributes);
  private: void InitManifestModule();
  public: static AssemblyBuilder DefineDynamicAssembly(AssemblyName name, AssemblyBuilderAccess access);
  public: static AssemblyBuilder DefineDynamicAssembly(AssemblyName name, AssemblyBuilderAccess access, IEnumerable<CustomAttributeBuilder> assemblyAttributes);
  private: static void CreateDynamicAssembly(ObjectHandleOnStack name, StackCrawlMarkHandle stackMark, Int32 access, ObjectHandleOnStack retAssembly);
  public: static AssemblyBuilder InternalDefineDynamicAssembly(AssemblyName name, AssemblyBuilderAccess access, StackCrawlMark& stackMark, IEnumerable<CustomAttributeBuilder> unsafeAssemblyAttributes);
  public: ModuleBuilder DefineDynamicModule(String name);
  public: ModuleBuilder DefineDynamicModule(String name, Boolean emitSymbolInfo);
  private: ModuleBuilder DefineDynamicModuleInternal(String name, Boolean emitSymbolInfo);
  private: ModuleBuilder DefineDynamicModuleInternalNoLock(String name, Boolean emitSymbolInfo);
  public: static void CheckContext(Array<Array<Type>> typess);
  public: static void CheckContext(Array<Type> types);
  public: Boolean Equals(Object obj);
  public: Int32 GetHashCode();
  public: Array<Object> GetCustomAttributes(Boolean inherit);
  public: Array<Object> GetCustomAttributes(Type attributeType, Boolean inherit);
  public: Boolean IsDefined(Type attributeType, Boolean inherit);
  public: IList<CustomAttributeData> GetCustomAttributesData();
  public: Array<String> GetManifestResourceNames();
  public: FileStream GetFile(String name);
  public: Array<FileStream> GetFiles(Boolean getResourceModules);
  public: Stream GetManifestResourceStream(Type type, String name);
  public: Stream GetManifestResourceStream(String name);
  public: ManifestResourceInfo GetManifestResourceInfo(String resourceName);
  public: Array<Type> GetExportedTypes();
  public: AssemblyName GetName(Boolean copiedName);
  public: Type GetType(String name, Boolean throwOnError, Boolean ignoreCase);
  public: Module GetModule(String name);
  public: Array<AssemblyName> GetReferencedAssemblies();
  public: Array<Module> GetModules(Boolean getResourceModules);
  public: Array<Module> GetLoadedModules(Boolean getResourceModules);
  public: Assembly GetSatelliteAssembly(CultureInfo culture);
  public: Assembly GetSatelliteAssembly(CultureInfo culture, Version version);
  public: ModuleBuilder GetDynamicModule(String name);
  private: ModuleBuilder GetDynamicModuleNoLock(String name);
  public: void SetCustomAttribute(ConstructorInfo con, Array<Byte> binaryAttribute);
  private: void SetCustomAttributeNoLock(ConstructorInfo con, Array<Byte> binaryAttribute);
  public: void SetCustomAttribute(CustomAttributeBuilder customBuilder);
  private: void SetCustomAttributeNoLock(CustomAttributeBuilder customBuilder);
  private: static void ctor_static();
  public: AssemblyBuilderData _assemblyData;
  private: InternalAssemblyBuilder _internalAssemblyBuilder;
  private: ModuleBuilder _manifestModuleBuilder;
  private: Boolean _isManifestModuleUsedAsDefinedModule;
  private: static Object s_assemblyBuilderLock;
};
} // namespace AssemblyBuilderNamespace
using AssemblyBuilder = AssemblyBuilderNamespace::AssemblyBuilder;
} // namespace System::Private::CoreLib::System::Reflection::Emit
