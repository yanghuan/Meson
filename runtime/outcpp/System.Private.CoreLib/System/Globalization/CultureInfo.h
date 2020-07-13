#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Boolean.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Int32)
FORWARD(Object)
FORWARD(String)
FORWARD(Type)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(Dictionary, TKey, TValue)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System::Threading {
FORWARD(AsyncLocal, T)
FORWARDS(AsyncLocalValueChangedArgs, T)
} // namespace System::Private::CoreLib::System::Threading
namespace System::Private::CoreLib::System::Globalization {
enum class CalendarId : uint16_t;
enum class CultureTypes;
FORWARD(Calendar)
FORWARD(CompareInfo)
FORWARD(CultureData)
FORWARD(DateTimeFormatInfo)
FORWARD(NumberFormatInfo)
FORWARD(TextInfo)
namespace CultureInfoNamespace {
using namespace Collections::Generic;
using namespace Threading;
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
  private: static Dictionary<String, CultureInfo> get_CachedCulturesByName();
  private: static Dictionary<Int32, CultureInfo> get_CachedCulturesByLcid();
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
  public: static CultureInfo GetCultureInfo(Int32 culture);
  public: static CultureInfo GetCultureInfo(String name);
  public: static CultureInfo GetCultureInfo(String name, String altName);
  public: static CultureInfo GetCultureInfo(String name, Boolean predefinedOnly);
  public: static CultureInfo GetCultureInfoByIetfLanguageTag(String name);
  private: static CultureInfo IcuGetPredefinedCultureInfo(String name);
  private: static CultureInfo NlsGetPredefinedCultureInfo(String name);
  public: static CultureInfo GetUserDefaultCulture();
  private: static CultureInfo GetUserDefaultUICulture();
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
  private: static Dictionary<String, CultureInfo> s_cachedCulturesByName;
  private: static Dictionary<Int32, CultureInfo> s_cachedCulturesByLcid;
  private: CultureInfo _parent;
  public: static constexpr Int32 LOCALE_NEUTRAL = 0;
  private: static constexpr Int32 LOCALE_USER_DEFAULT = 1024;
  private: static constexpr Int32 LOCALE_SYSTEM_DEFAULT = 2048;
  public: static constexpr Int32 LOCALE_CUSTOM_UNSPECIFIED = 4096;
  public: static constexpr Int32 LOCALE_CUSTOM_DEFAULT = 3072;
  public: static constexpr Int32 LOCALE_INVARIANT = 127;
};
} // namespace CultureInfoNamespace
using CultureInfo = CultureInfoNamespace::CultureInfo;
} // namespace System::Private::CoreLib::System::Globalization
