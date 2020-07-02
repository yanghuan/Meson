#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARD(String)
FORWARDS(Int32)
namespace LocalAppContextSwitchesNamespace {
class LocalAppContextSwitches {
  public: static Boolean get_EnforceJapaneseEraYearRanges();
  public: static Boolean get_FormatJapaneseFirstYearAsANumber();
  public: static Boolean get_EnforceLegacyJapaneseDateParsing();
  public: static Boolean get_PreserveEventListnerObjectIdentity();
  public: static Boolean get_SerializationGuard();
  public: static Boolean GetCachedSwitchValue(String switchName, Int32& cachedSwitchValue);
  private: static Boolean GetCachedSwitchValueInternal(String switchName, Int32& cachedSwitchValue);
  private: static Boolean GetSwitchDefaultValue(String switchName);
  private: static Int32 s_enforceJapaneseEraYearRanges;
  private: static Int32 s_formatJapaneseFirstYearAsANumber;
  private: static Int32 s_enforceLegacyJapaneseDateParsing;
  private: static Int32 s_preserveEventListnerObjectIdentity;
  private: static Int32 s_serializationGuard;
};
} // namespace LocalAppContextSwitchesNamespace
using LocalAppContextSwitches = LocalAppContextSwitchesNamespace::LocalAppContextSwitches;
} // namespace System::Private::CoreLib::System
