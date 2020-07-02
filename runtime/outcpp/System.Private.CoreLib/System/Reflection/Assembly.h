#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(IEnumerable, T)
FORWARD(IList, T)
FORWARD(Dictionary, TKey, TValue)
FORWARD(List, T)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System {
FORWARD(Type)
FORWARD(String)
FORWARDS(Boolean)
FORWARDS(Int64)
FORWARDS(UInt32)
FORWARD_(Array, T1, T2)
FORWARD(Object)
FORWARD(Version)
FORWARDS(Int32)
FORWARDS(Byte)
FORWARD(ResolveEventArgs)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Security {
enum class SecurityRuleSet : uint8_t;
} // namespace System::Private::CoreLib::System::Security
namespace System::Private::CoreLib::System::Threading {
enum class StackCrawlMark;
} // namespace System::Private::CoreLib::System::Threading
namespace System::Private::CoreLib::System::Runtime::Loader {
FORWARD(AssemblyLoadContext)
} // namespace System::Private::CoreLib::System::Runtime::Loader
namespace System::Private::CoreLib::System::Runtime::CompilerServices {
FORWARDS(StackCrawlMarkHandle)
FORWARDS(ObjectHandleOnStack)
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
namespace System::Private::CoreLib::System::IO {
FORWARD(Stream)
FORWARD(FileStream)
} // namespace System::Private::CoreLib::System::IO
namespace System::Private::CoreLib::System::Globalization {
FORWARD(CultureInfo)
} // namespace System::Private::CoreLib::System::Globalization
namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System::Configuration::Assemblies {
enum class AssemblyHashAlgorithm;
} // namespace System::Private::CoreLib::System::Configuration::Assemblies
namespace System::Private::CoreLib::System::Reflection {
FORWARD(TypeInfo)
FORWARD(MethodInfo)
FORWARD(CustomAttributeData)
FORWARD(Module)
FORWARD(AssemblyName)
FORWARD(RuntimeAssembly)
FORWARD(ManifestResourceInfo)
enum class BindingFlags;
FORWARD(Binder)
namespace AssemblyNamespace {
using namespace ::System::Private::CoreLib::System::Collections::Generic;
using namespace ::System::Private::CoreLib::System::Configuration::Assemblies;
using namespace ::System::Private::CoreLib::System::Globalization;
using namespace ::System::Private::CoreLib::System::IO;
using namespace ::System::Private::CoreLib::System::Runtime::CompilerServices;
using namespace ::System::Private::CoreLib::System::Runtime::Loader;
using namespace ::System::Private::CoreLib::System::Runtime::Serialization;
using namespace ::System::Private::CoreLib::System::Security;
using namespace ::System::Private::CoreLib::System::Threading;
using System::Collections::Generic::IList;
CLASS(Assembly) {
  public: IEnumerable<TypeInfo> get_DefinedTypes();
  public: IEnumerable<Type> get_ExportedTypes();
  public: String get_CodeBase();
  public: MethodInfo get_EntryPoint();
  public: String get_FullName();
  public: String get_ImageRuntimeVersion();
  public: Boolean get_IsDynamic();
  public: String get_Location();
  public: Boolean get_ReflectionOnly();
  public: Boolean get_IsCollectible();
  public: Boolean get_IsFullyTrusted();
  public: IEnumerable<CustomAttributeData> get_CustomAttributes();
  public: String get_EscapedCodeBase();
  public: Module get_ManifestModule();
  public: IEnumerable<Module> get_Modules();
  public: Boolean get_GlobalAssemblyCache();
  public: Int64 get_HostContext();
  public: SecurityRuleSet get_SecurityRuleSet();
  public: static Assembly Load(String assemblyString);
  public: static Assembly LoadWithPartialName(String partialName);
  public: static Assembly Load(AssemblyName assemblyRef);
  public: static Assembly Load(AssemblyName assemblyRef, StackCrawlMark& stackMark, AssemblyLoadContext assemblyLoadContext);
  private: static void GetExecutingAssemblyNative(StackCrawlMarkHandle stackMark, ObjectHandleOnStack retAssembly);
  public: static RuntimeAssembly GetExecutingAssembly(StackCrawlMark& stackMark);
  public: static Assembly GetExecutingAssembly();
  public: static Assembly GetCallingAssembly();
  private: static void GetEntryAssemblyNative(ObjectHandleOnStack retAssembly);
  public: static Assembly GetEntryAssembly();
  public: Boolean IsRuntimeImplemented();
  public: static UInt32 GetAssemblyCount();
  public: Array<Type> GetTypes();
  public: Array<Type> GetExportedTypes();
  public: Array<Type> GetForwardedTypes();
  public: ManifestResourceInfo GetManifestResourceInfo(String resourceName);
  public: Array<String> GetManifestResourceNames();
  public: Stream GetManifestResourceStream(String name);
  public: Stream GetManifestResourceStream(Type type, String name);
  public: AssemblyName GetName();
  public: AssemblyName GetName(Boolean copiedName);
  public: Type GetType(String name);
  public: Type GetType(String name, Boolean throwOnError);
  public: Type GetType(String name, Boolean throwOnError, Boolean ignoreCase);
  public: Boolean IsDefined(Type attributeType, Boolean inherit);
  public: IList<CustomAttributeData> GetCustomAttributesData();
  public: Array<Object> GetCustomAttributes(Boolean inherit);
  public: Array<Object> GetCustomAttributes(Type attributeType, Boolean inherit);
  public: Object CreateInstance(String typeName);
  public: Object CreateInstance(String typeName, Boolean ignoreCase);
  public: Object CreateInstance(String typeName, Boolean ignoreCase, BindingFlags bindingAttr, Binder binder, Array<Object> args, CultureInfo culture, Array<Object> activationAttributes);
  public: Module GetModule(String name);
  public: Array<Module> GetModules();
  public: Array<Module> GetModules(Boolean getResourceModules);
  public: Array<Module> GetLoadedModules();
  public: Array<Module> GetLoadedModules(Boolean getResourceModules);
  public: Array<AssemblyName> GetReferencedAssemblies();
  public: Assembly GetSatelliteAssembly(CultureInfo culture);
  public: Assembly GetSatelliteAssembly(CultureInfo culture, Version version);
  public: FileStream GetFile(String name);
  public: Array<FileStream> GetFiles();
  public: Array<FileStream> GetFiles(Boolean getResourceModules);
  public: void GetObjectData(SerializationInfo info, StreamingContext context);
  public: String ToString();
  public: Boolean Equals(Object o);
  public: Int32 GetHashCode();
  public: static String CreateQualifiedName(String assemblyName, String typeName);
  public: static Assembly GetAssembly(Type type);
  public: static Assembly Load(Array<Byte> rawAssembly);
  public: static Assembly Load(Array<Byte> rawAssembly, Array<Byte> rawSymbolStore);
  public: static Assembly LoadFile(String path);
  private: static Assembly LoadFromResolveHandler(Object sender, ResolveEventArgs args);
  public: static Assembly LoadFrom(String assemblyFile);
  public: static Assembly LoadFrom(String assemblyFile, Array<Byte> hashValue, AssemblyHashAlgorithm hashAlgorithm);
  public: static Assembly UnsafeLoadFrom(String assemblyFile);
  public: Module LoadModule(String moduleName, Array<Byte> rawModule);
  public: Module LoadModule(String moduleName, Array<Byte> rawModule, Array<Byte> rawSymbolStore);
  public: static Assembly ReflectionOnlyLoad(Array<Byte> rawAssembly);
  public: static Assembly ReflectionOnlyLoad(String assemblyString);
  public: static Assembly ReflectionOnlyLoadFrom(String assemblyFile);
  private: static Boolean s_forceNullEntryPoint;
  private: static Dictionary<String, Assembly> s_loadfile;
  private: static List<String> s_loadFromAssemblyList;
  private: static Boolean s_loadFromHandlerSet;
  private: static Int32 s_cachedSerializationSwitch;
};
} // namespace AssemblyNamespace
using Assembly = AssemblyNamespace::Assembly;
} // namespace System::Private::CoreLib::System::Reflection
