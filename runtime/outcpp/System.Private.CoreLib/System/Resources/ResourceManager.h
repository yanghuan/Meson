#pragma once

#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARDS(Int32)
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
namespace System::Private::CoreLib::System::Resources {
enum class UltimateResourceFallbackLocation : int32_t;
FORWARD(IResourceGroveler)
FORWARD(ResourceSet)
namespace ResourceManagerNamespace {
using namespace Collections::Generic;
using namespace Globalization;
using namespace IO;
using namespace Reflection;
CLASS(ResourceManager) : public Object::in {
  public: CLASS(CultureNameResourceSetPair) : public Object::in {
    public: void ctor();
    public: String lastCultureName;
    public: ResourceSet lastResourceSet;
  };
  public: CLASS(ResourceManagerMediator) : public Object::in {
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
    public: void ctor(ResourceManager rm);
    public: String GetResourceFileName(CultureInfo culture);
    public: static Version ObtainSatelliteContractVersion(Assembly a);
    private: ResourceManager _rm;
  };
  public: String get_BaseName();
  public: Boolean get_IgnoreCase();
  public: void set_IgnoreCase(Boolean value);
  public: Type get_ResourceSetType();
  protected: UltimateResourceFallbackLocation get_FallbackLocation();
  protected: void set_FallbackLocation(UltimateResourceFallbackLocation value);
  protected: void ctor();
  private: void ctor(String baseName, String resourceDir, Type userResourceSet);
  public: void ctor(String baseName, Assembly assembly);
  public: void ctor(String baseName, Assembly assembly, Type usingResourceSet);
  public: void ctor(Type resourceSource);
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
  private: static void ctor_static();
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
};
} // namespace ResourceManagerNamespace
using ResourceManager = ResourceManagerNamespace::ResourceManager;
} // namespace System::Private::CoreLib::System::Resources
