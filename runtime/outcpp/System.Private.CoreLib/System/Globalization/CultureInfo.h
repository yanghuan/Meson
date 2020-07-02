#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Boolean.h>

namespace System::Private::CoreLib::System {
FORWARDS(Int32)
FORWARD(String)
FORWARD_(Array, T1, T2)
FORWARD(Object)
FORWARD(Type)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading {
FORWARDS(AsyncLocalValueChangedArgs, T)
FORWARD(AsyncLocal, T)
} // namespace System::Private::CoreLib::System::Threading
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(Dictionary, TKey, TValue)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::Internal::Resources {
FORWARD(WindowsRuntimeResourceManagerBase)
} // namespace System::Private::CoreLib::Internal::Resources
namespace System::Private::CoreLib::System::Globalization {
FORWARD(CompareInfo)
FORWARD(TextInfo)
enum class CultureTypes;
FORWARD(NumberFormatInfo)
FORWARD(DateTimeFormatInfo)
FORWARD(Calendar)
enum class CalendarId : uint16_t;
FORWARD(CultureData)
namespace CultureInfoNamespace {
using namespace ::System::Private::CoreLib::Internal::Resources;
using namespace ::System::Private::CoreLib::System::Collections::Generic;
using namespace ::System::Private::CoreLib::System::Threading;
CLASS(CultureInfo) {
  public: static CultureInfo get_CurrentCulture();
  public: static void set_CurrentCulture(CultureInfo value);
  public: static CultureInfo get_CurrentUICulture();
  public: static void set_CurrentUICulture(CultureInfo value);
  public: static CultureInfo get_UserDefaultUICulture();
  public: static CultureInfo get_InstalledUICulture();
  public: static CultureInfo get_DefaultThreadCurrentCulture();
  public: static void set_DefaultThreadCurrentCulture(CultureInfo value);
  public: static CultureInfo get_DefaultThreadCurrentUICulture();
  public: static void set_DefaultThreadCurrentUICulture(CultureInfo value);
  public: static CultureInfo get_InvariantCulture();
  public: CultureInfo get_Parent();
  public: Int32 get_LCID();
  public: Int32 get_KeyboardLayoutId();
  public: String get_Name();
  public: String get_SortName();
  public: String get_IetfLanguageTag();
  public: String get_DisplayName();
  public: String get_NativeName();
  public: String get_EnglishName();
  public: String get_TwoLetterISOLanguageName();
  public: String get_ThreeLetterISOLanguageName();
  public: String get_ThreeLetterWindowsLanguageName();
  public: CompareInfo get_CompareInfo();
  public: TextInfo get_TextInfo();
  public: Boolean get_IsNeutralCulture();
  public: CultureTypes get_CultureTypes();
  public: NumberFormatInfo get_NumberFormat();
  public: void set_NumberFormat(NumberFormatInfo value);
  public: DateTimeFormatInfo get_DateTimeFormat();
  public: void set_DateTimeFormat(DateTimeFormatInfo value);
  public: Calendar get_Calendar();
  public: Array<Calendar> get_OptionalCalendars();
  public: Boolean get_UseUserOverride();
  public: Boolean get_IsReadOnly();
  public: Boolean get_HasInvariantCultureName();
  private: static void AsyncLocalSetCurrentCulture(AsyncLocalValueChangedArgs<CultureInfo> args);
  private: static void AsyncLocalSetCurrentUICulture(AsyncLocalValueChangedArgs<CultureInfo> args);
  private: static CultureInfo InitializeUserDefaultCulture();
  private: static CultureInfo InitializeUserDefaultUICulture();
  private: static CultureInfo CreateCultureInfoNoThrow(String name, Boolean useUserOverride);
  private: static CultureInfo GetCultureByName(String name);
  public: static CultureInfo CreateSpecificCulture(String name);
  public: static Boolean VerifyCultureName(String cultureName, Boolean throwException);
  public: static Boolean VerifyCultureName(CultureInfo culture, Boolean throwException);
  public: static Array<CultureInfo> GetCultures(CultureTypes types);
  public: Boolean Equals(Object value);
  public: Int32 GetHashCode();
  public: String ToString();
  public: Object GetFormat(Type formatType);
  public: void ClearCachedData();
  public: static Calendar GetCalendarInstance(CalendarId calType);
  public: static Calendar GetCalendarInstanceRare(CalendarId calType);
  public: CultureInfo GetConsoleFallbackUICulture();
  public: Object Clone();
  public: static CultureInfo ReadOnly(CultureInfo ci);
  private: void VerifyWritable();
  public: static CultureInfo GetCultureInfoHelper(Int32 lcid, String name, String altName);
  public: static CultureInfo GetCultureInfo(Int32 culture);
  public: static CultureInfo GetCultureInfo(String name);
  public: static CultureInfo GetCultureInfo(String name, String altName);
  public: static CultureInfo GetCultureInfoByIetfLanguageTag(String name);
  public: static CultureInfo GetUserDefaultCulture();
  private: static CultureInfo GetUserDefaultUICulture();
  public: static CultureInfo GetCultureInfoForUserPreferredLanguageInAppX();
  public: static Boolean SetCultureInfoForUserPreferredLanguageInAppX(CultureInfo ci);
  private: Boolean _isReadOnly;
  private: CompareInfo _compareInfo;
  private: TextInfo _textInfo;
  public: NumberFormatInfo _numInfo;
  public: DateTimeFormatInfo _dateTimeInfo;
  private: Calendar _calendar;
  public: CultureData _cultureData;
  public: Boolean _isInherited;
  private: CultureInfo _consoleFallbackCulture;
  public: String _name;
  private: String _nonSortName;
  private: String _sortName;
  private: static CultureInfo s_userDefaultCulture;
  private: static CultureInfo s_userDefaultUICulture;
  private: static CultureInfo s_InvariantCultureInfo;
  private: static CultureInfo s_DefaultThreadCurrentUICulture;
  private: static CultureInfo s_DefaultThreadCurrentCulture;
  private: static CultureInfo s_currentThreadCulture;
  private: static CultureInfo s_currentThreadUICulture;
  private: static AsyncLocal<CultureInfo> s_asyncLocalCurrentCulture;
  private: static AsyncLocal<CultureInfo> s_asyncLocalCurrentUICulture;
  private: static Object _lock;
  private: static Dictionary<String, CultureInfo> s_NameCachedCultures;
  private: static Dictionary<Int32, CultureInfo> s_LcidCachedCultures;
  private: CultureInfo _parent;
  public: static Int32 LOCALE_NEUTRAL;
  private: static Int32 LOCALE_USER_DEFAULT;
  private: static Int32 LOCALE_SYSTEM_DEFAULT;
  public: static Int32 LOCALE_CUSTOM_UNSPECIFIED;
  public: static Int32 LOCALE_CUSTOM_DEFAULT;
  public: static Int32 LOCALE_INVARIANT;
  private: static WindowsRuntimeResourceManagerBase s_WindowsRuntimeResourceManager;
  private: static Boolean ts_IsDoingAppXCultureInfoLookup;
};
} // namespace CultureInfoNamespace
using CultureInfo = CultureInfoNamespace::CultureInfo;
} // namespace System::Private::CoreLib::System::Globalization
