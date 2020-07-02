#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Boolean.h>

namespace System::Private::CoreLib::System {
FORWARDS(Int32)
FORWARD(Object)
FORWARD(String)
FORWARD(Type)
FORWARD(Version)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Globalization {
FORWARD(CultureInfo)
} // namespace System::Private::CoreLib::System::Globalization
namespace System::Private::CoreLib::System::Reflection {
FORWARD(Assembly)
} // namespace System::Private::CoreLib::System::Reflection
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(Dictionary, TKey, TValue)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System::IO {
FORWARD(UnmanagedMemoryStream)
} // namespace System::Private::CoreLib::System::IO
namespace System::Private::CoreLib::Internal::Resources {
FORWARD(PRIExceptionInfo)
FORWARD(WindowsRuntimeResourceManagerBase)
} // namespace System::Private::CoreLib::Internal::Resources
namespace System::Private::CoreLib::System::Resources {
FORWARD(ResourceSet)
enum class UltimateResourceFallbackLocation;
FORWARD(IResourceGroveler)
namespace ResourceManagerNamespace {
using namespace ::System::Private::CoreLib::Internal::Resources;
using namespace ::System::Private::CoreLib::System::Collections::Generic;
using namespace ::System::Private::CoreLib::System::Globalization;
using namespace ::System::Private::CoreLib::System::IO;
using namespace ::System::Private::CoreLib::System::Reflection;
CLASS(ResourceManager) {
  public: CLASS(CultureNameResourceSetPair) {
    public: String lastCultureName;
    public: ResourceSet lastResourceSet;
  };
  public: CLASS(ResourceManagerMediator) {
    public: String get_ModuleDir();
    public: Type get_LocationInfo();
    public: Type get_UserResourceSet();
    public: String get_BaseNameField();
    public: CultureInfo get_NeutralResourcesCulture();
    public: Boolean get_LookedForSatelliteContractVersion();
    public: void set_LookedForSatelliteContractVersion(Boolean value);
    public: Version get_SatelliteContractVersion();
    public: void set_SatelliteContractVersion(Version value);
    public: UltimateResourceFallbackLocation get_FallbackLoc();
    public: Assembly get_MainAssembly();
    public: String get_BaseName();
    public: String GetResourceFileName(CultureInfo culture);
    public: Version ObtainSatelliteContractVersion(Assembly a);
    private: ResourceManager _rm;
  };
  public: String get_BaseName();
  public: Boolean get_IgnoreCase();
  public: void set_IgnoreCase(Boolean value);
  public: Type get_ResourceSetType();
  protected: UltimateResourceFallbackLocation get_FallbackLocation();
  protected: void set_FallbackLocation(UltimateResourceFallbackLocation value);
  private: void CommonAssemblyInit();
  public: void ReleaseAllResources();
  public: static ResourceManager CreateFileBasedResourceManager(String baseName, String resourceDir, Type usingResourceSet);
  protected: String GetResourceFileName(CultureInfo culture);
  public: ResourceSet GetFirstResourceSet(CultureInfo culture);
  public: ResourceSet GetResourceSet(CultureInfo culture, Boolean createIfNotExists, Boolean tryParents);
  protected: ResourceSet InternalGetResourceSet(CultureInfo culture, Boolean createIfNotExists, Boolean tryParents);
  private: static void AddResourceSet(Dictionary<String, ResourceSet> localResourceSets, String cultureName, ResourceSet& rs);
  protected: static Version GetSatelliteContractVersion(Assembly a);
  protected: static CultureInfo GetNeutralResourcesLanguage(Assembly a);
  public: static Boolean IsDefaultType(String asmTypeName, String typeName);
  public: String GetString(String name);
  public: String GetString(String name, CultureInfo culture);
  public: Object GetObject(String name);
  public: Object GetObject(String name, CultureInfo culture);
  private: Object GetObject(String name, CultureInfo culture, Boolean wrapUnmanagedMemStream);
  public: UnmanagedMemoryStream GetStream(String name);
  public: UnmanagedMemoryStream GetStream(String name, CultureInfo culture);
  private: String GetStringFromPRI(String stringName, CultureInfo culture, String neutralResourcesCulture);
  public: static WindowsRuntimeResourceManagerBase GetWinRTResourceManager();
  private: static Boolean ShouldUseUapResourceManagement(Assembly resourcesAssembly);
  private: void SetUapConfiguration();
  protected: String BaseNameField;
  protected: Assembly MainAssembly;
  private: Dictionary<String, ResourceSet> _resourceSets;
  private: String _moduleDir;
  private: Type _locationInfo;
  private: Type _userResourceSet;
  private: CultureInfo _neutralResourcesCulture;
  private: CultureNameResourceSetPair _lastUsedResourceCache;
  private: Boolean _ignoreCase;
  private: Boolean _useManifest;
  private: UltimateResourceFallbackLocation _fallbackLoc;
  private: Version _satelliteContractVersion;
  private: Boolean _lookedForSatelliteContractVersion;
  private: IResourceGroveler _resourceGroveler;
  public: static Int32 MagicNumber;
  public: static Int32 HeaderVersionNumber;
  private: static Type s_minResourceSet;
  private: WindowsRuntimeResourceManagerBase _WinRTResourceManager;
  private: PRIExceptionInfo _PRIExceptionInfo;
  private: Boolean _PRIInitialized;
  private: Boolean _useUapResourceManagement;
};
} // namespace ResourceManagerNamespace
using ResourceManager = ResourceManagerNamespace::ResourceManager;
} // namespace System::Private::CoreLib::System::Resources
