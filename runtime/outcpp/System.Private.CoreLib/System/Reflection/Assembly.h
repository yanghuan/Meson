#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(Dictionary, TKey, TValue)
FORWARD(IEnumerable, T)
FORWARD(IList, T)
FORWARD(List, T)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
FORWARDS(Byte)
FORWARDS(Int32)
FORWARDS(Int64)
FORWARD(ResolveEventArgs)
FORWARD(String)
FORWARD(Type)
FORWARDS(UInt32)
FORWARD(Version)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Security {
enum class SecurityRuleSet : uint8_t;
} // namespace System::Private::CoreLib::System::Security
namespace System::Private::CoreLib::System::Runtime::CompilerServices {
FORWARDS(ObjectHandleOnStack)
FORWARDS(StackCrawlMarkHandle)
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
namespace System::Private::CoreLib::System::Threading {
enum class StackCrawlMark;
} // namespace System::Private::CoreLib::System::Threading
namespace System::Private::CoreLib::System::IO {
FORWARD(FileStream)
FORWARD(Stream)
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
enum class BindingFlags;
FORWARD(AssemblyName)
FORWARD(Binder)
FORWARD(CustomAttributeData)
FORWARD(ManifestResourceInfo)
FORWARD(MethodInfo)
FORWARD(Module)
FORWARD(RuntimeAssembly)
FORWARD(TypeInfo)
namespace AssemblyNamespace {
using namespace Collections::Generic;
using namespace Configuration::Assemblies;
using namespace Globalization;
using namespace IO;
using namespace Runtime::CompilerServices;
using namespace Runtime::Serialization;
using namespace Security;
using namespace Threading;
using Collections::Generic::IList;
CLASS(Assembly) : public Object::in {
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
  private: static void GetExecutingAssemblyNative(StackCrawlMarkHandle stackMark, ObjectHandleOnStack retAssembly);
  public: static RuntimeAssembly GetExecutingAssembly(StackCrawlMark& stackMark);
  public: static Assembly GetExecutingAssembly();
  public: static Assembly GetCallingAssembly();
  private: static void GetEntryAssemblyNative(ObjectHandleOnStack retAssembly);
  private: static Assembly GetEntryAssemblyInternal();
  public: Boolean IsRuntimeImplemented();
  public: static UInt32 GetAssemblyCount();
  protected: void Ctor();
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
  public: static Boolean op_Equality(Assembly left, Assembly right);
  public: static Boolean op_Inequality(Assembly left, Assembly right);
  public: static String CreateQualifiedName(String assemblyName, String typeName);
  public: static Assembly GetAssembly(Type type);
  public: static Assembly GetEntryAssembly();
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
  private: static void SCtor();
  private: static Dictionary<String, Assembly> s_loadfile;
  private: static List<String> s_loadFromAssemblyList;
  private: static Boolean s_loadFromHandlerSet;
  private: static Int32 s_cachedSerializationSwitch;
  private: static Boolean s_forceNullEntryPoint;
};
} // namespace AssemblyNamespace
using Assembly = AssemblyNamespace::Assembly;
} // namespace System::Private::CoreLib::System::Reflection
