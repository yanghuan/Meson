#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/Interop.h>
#include <System.Private.CoreLib/System/IntPtr.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
FORWARDS(Byte)
FORWARD(Exception)
FORWARDS(Int32)
FORWARDS(Int64)
FORWARD(Object)
FORWARD(String)
FORWARD(Type)
FORWARDS(UInt32)
FORWARD(Version)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(IEnumerable, T)
FORWARD(IList, T)
FORWARD(List, T)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System::Runtime::CompilerServices {
FORWARDS(ObjectHandleOnStack)
FORWARDS(QCallAssembly)
FORWARDS(StringHandleOnStack)
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
namespace System::Private::CoreLib::System::IO {
FORWARD(FileStream)
FORWARD(Stream)
} // namespace System::Private::CoreLib::System::IO
namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System::Threading {
enum class StackCrawlMark;
} // namespace System::Private::CoreLib::System::Threading
namespace System::Private::CoreLib::System::Runtime::Loader {
FORWARD(AssemblyLoadContext)
} // namespace System::Private::CoreLib::System::Runtime::Loader
namespace System::Private::CoreLib::System::Globalization {
FORWARD(CultureInfo)
} // namespace System::Private::CoreLib::System::Globalization
namespace System::Private::CoreLib::System::Configuration::Assemblies {
enum class AssemblyHashAlgorithm;
} // namespace System::Private::CoreLib::System::Configuration::Assemblies
namespace System::Private::CoreLib::System::Reflection {
FORWARD(MethodInfo)
FORWARD(TypeInfo)
FORWARD(Module)
FORWARD(AssemblyName)
FORWARD(CustomAttributeData)
FORWARD(ManifestResourceInfo)
enum class AssemblyNameFlags;
FORWARD(RuntimeModule)
FORWARD(Assembly)
FORWARDS(MetadataToken)
FORWARD(ModuleResolveEventHandler)
namespace RuntimeAssemblyNamespace {
using namespace ::System::Private::CoreLib::System::Collections::Generic;
using namespace ::System::Private::CoreLib::System::Configuration::Assemblies;
using namespace ::System::Private::CoreLib::System::Globalization;
using namespace ::System::Private::CoreLib::System::IO;
using namespace ::System::Private::CoreLib::System::Runtime::CompilerServices;
using namespace ::System::Private::CoreLib::System::Runtime::Loader;
using namespace ::System::Private::CoreLib::System::Runtime::Serialization;
using namespace ::System::Private::CoreLib::System::Threading;
using ::System::Private::CoreLib::System::Collections::Generic::IList;
CLASS(RuntimeAssembly) {
  private: CLASS(ManifestResourceStream) {
    private: RuntimeAssembly _manifestAssembly;
  };
  public: Object get_SyncRoot();
  public: String get_CodeBase();
  public: String get_FullName();
  public: MethodInfo get_EntryPoint();
  public: IEnumerable<TypeInfo> get_DefinedTypes();
  public: Boolean get_IsCollectible();
  public: Module get_ManifestModule();
  public: Boolean get_ReflectionOnly();
  public: String get_Location();
  public: String get_ImageRuntimeVersion();
  public: Boolean get_GlobalAssemblyCache();
  public: Int64 get_HostContext();
  public: Boolean get_IsDynamic();
  public: IntPtr GetUnderlyingNativeHandle();
  private: static void GetCodeBase(QCallAssembly assembly, Boolean copiedName, StringHandleOnStack retString);
  public: String GetCodeBase(Boolean copiedName);
  public: RuntimeAssembly GetNativeHandle();
  public: AssemblyName GetName(Boolean copiedName);
  private: static void GetFullName(QCallAssembly assembly, StringHandleOnStack retString);
  private: static void GetEntryPoint(QCallAssembly assembly, ObjectHandleOnStack retMethod);
  private: static void GetType(QCallAssembly assembly, String name, Boolean throwOnError, Boolean ignoreCase, ObjectHandleOnStack type, ObjectHandleOnStack keepAlive, ObjectHandleOnStack assemblyLoadContext);
  public: Type GetType(String name, Boolean throwOnError, Boolean ignoreCase);
  private: static void GetExportedTypes(QCallAssembly assembly, ObjectHandleOnStack retTypes);
  public: Array<Type> GetExportedTypes();
  public: static Interop::BOOL GetIsCollectible(QCallAssembly assembly);
  private: static Byte* GetResource(QCallAssembly assembly, String resourceName, UInt32& length);
  public: Stream GetManifestResourceStream(Type type, String name);
  public: Stream GetManifestResourceStream(String name);
  public: void GetObjectData(SerializationInfo info, StreamingContext context);
  public: Array<Object> GetCustomAttributes(Boolean inherit);
  public: Array<Object> GetCustomAttributes(Type attributeType, Boolean inherit);
  public: Boolean IsDefined(Type attributeType, Boolean inherit);
  public: IList<CustomAttributeData> GetCustomAttributesData();
  public: static RuntimeAssembly InternalLoad(String assemblyString, StackCrawlMark& stackMark, AssemblyLoadContext assemblyLoadContext);
  public: static RuntimeAssembly InternalLoadAssemblyName(AssemblyName assemblyRef, StackCrawlMark& stackMark, AssemblyLoadContext assemblyLoadContext);
  private: static RuntimeAssembly nLoad(AssemblyName fileName, String codeBase, RuntimeAssembly assemblyContext, StackCrawlMark& stackMark, Boolean throwOnFileNotFound, AssemblyLoadContext assemblyLoadContext);
  private: static void GetModule(QCallAssembly assembly, String name, ObjectHandleOnStack retModule);
  public: Module GetModule(String name);
  public: FileStream GetFile(String name);
  public: Array<FileStream> GetFiles(Boolean getResourceModules);
  private: static Array<String> GetManifestResourceNames(RuntimeAssembly assembly);
  public: Array<String> GetManifestResourceNames();
  private: static Array<AssemblyName> GetReferencedAssemblies(RuntimeAssembly assembly);
  public: Array<AssemblyName> GetReferencedAssemblies();
  private: static Int32 GetManifestResourceInfo(QCallAssembly assembly, String resourceName, ObjectHandleOnStack assemblyRef, StringHandleOnStack retFileName);
  public: ManifestResourceInfo GetManifestResourceInfo(String resourceName);
  private: static void GetLocation(QCallAssembly assembly, StringHandleOnStack retString);
  private: static void GetImageRuntimeVersion(QCallAssembly assembly, StringHandleOnStack retString);
  private: static String VerifyCodeBase(String codebase);
  private: static void GetVersion(QCallAssembly assembly, Int32& majVer, Int32& minVer, Int32& buildNum, Int32& revNum);
  public: Version GetVersion();
  private: static void GetLocale(QCallAssembly assembly, StringHandleOnStack retString);
  public: CultureInfo GetLocale();
  private: static Boolean FCallIsDynamic(RuntimeAssembly assembly);
  private: static void GetSimpleName(QCallAssembly assembly, StringHandleOnStack retSimpleName);
  public: String GetSimpleName();
  private: static AssemblyHashAlgorithm GetHashAlgorithm(QCallAssembly assembly);
  private: AssemblyHashAlgorithm GetHashAlgorithm();
  private: static AssemblyNameFlags GetFlags(QCallAssembly assembly);
  private: AssemblyNameFlags GetFlags();
  private: static void GetPublicKey(QCallAssembly assembly, ObjectHandleOnStack retPublicKey);
  public: Array<Byte> GetPublicKey();
  private: RuntimeModule OnModuleResolveEvent(String moduleName);
  public: Assembly GetSatelliteAssembly(CultureInfo culture);
  public: Assembly GetSatelliteAssembly(CultureInfo culture, Version version);
  public: Assembly InternalGetSatelliteAssembly(CultureInfo culture, Version version, Boolean throwOnFileNotFound);
  private: static void GetModules(QCallAssembly assembly, Boolean loadIfNotFound, Boolean getResourceModules, ObjectHandleOnStack retModuleHandles);
  private: Array<RuntimeModule> GetModulesInternal(Boolean loadIfNotFound, Boolean getResourceModules);
  public: Array<Module> GetModules(Boolean getResourceModules);
  public: Array<Module> GetLoadedModules(Boolean getResourceModules);
  public: static RuntimeModule GetManifestModule(RuntimeAssembly assembly);
  public: static Int32 GetToken(RuntimeAssembly assembly);
  public: Array<Type> GetForwardedTypes();
  private: static void AddPublicNestedTypes(Type type, List<Type> types, List<Exception> exceptions);
  private: static void GetForwardedType(QCallAssembly assembly, MetadataToken mdtExternalType, ObjectHandleOnStack type);
  private: ModuleResolveEventHandler _ModuleResolve;
  private: String m_fullname;
  private: Object m_syncRoot;
  private: IntPtr m_assembly;
  private: static String s_localFilePrefix;
};
} // namespace RuntimeAssemblyNamespace
using RuntimeAssembly = RuntimeAssemblyNamespace::RuntimeAssembly;
} // namespace System::Private::CoreLib::System::Reflection