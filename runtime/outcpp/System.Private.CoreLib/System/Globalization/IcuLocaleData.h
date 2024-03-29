#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array)
FORWARDS(Int32)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Globalization {
enum class IcuLocaleDataParts : int32_t;
namespace IcuLocaleDataNamespace {
class IcuLocaleData {
  public: static Int32 GetLocaleDataNumericPart(String cultureName, IcuLocaleDataParts part);
  public: static String GetThreeLetterWindowsLanguageName(String cultureName);
  public: static String GetLocaleDataMappedCulture(String cultureName, IcuLocaleDataParts part);
  public: static String GetConsoleUICulture(String cultureName);
  private: static Int32 SearchCultureName(String name);
  private: static Int32 CompareOrdinal(String s1, String s2, Int32 index, Int32 length);
  public: static void cctor();
  private: static Array<Int32> s_localeNamesIndices;
  private: static Array<Int32> s_nameIndexToNumericData;
  private: static Array<Int32> s_lcids;
  private: static Array<Int32> s_lcidToCultureNameIndices;
};
} // namespace IcuLocaleDataNamespace
using IcuLocaleData = IcuLocaleDataNamespace::IcuLocaleData;
} // namespace System::Private::CoreLib::System::Globalization
