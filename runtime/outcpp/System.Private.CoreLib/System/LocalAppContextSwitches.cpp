#include "LocalAppContextSwitches-dep.h"

namespace System::Private::CoreLib::System::LocalAppContextSwitchesNamespace {
Boolean LocalAppContextSwitches::get_EnforceJapaneseEraYearRanges() {
  return GetCachedSwitchValue("Switch.System.Globalization.EnforceJapaneseEraYearRanges", s_enforceJapaneseEraYearRanges);
}

Boolean LocalAppContextSwitches::get_FormatJapaneseFirstYearAsANumber() {
  return GetCachedSwitchValue("Switch.System.Globalization.FormatJapaneseFirstYearAsANumber", s_formatJapaneseFirstYearAsANumber);
}

Boolean LocalAppContextSwitches::get_EnforceLegacyJapaneseDateParsing() {
  return GetCachedSwitchValue("Switch.System.Globalization.EnforceLegacyJapaneseDateParsing", s_enforceLegacyJapaneseDateParsing);
}

Boolean LocalAppContextSwitches::get_PreserveEventListnerObjectIdentity() {
  return GetCachedSwitchValue("Switch.System.Diagnostics.EventSource.PreserveEventListnerObjectIdentity", s_preserveEventListnerObjectIdentity);
}

Boolean LocalAppContextSwitches::get_SerializationGuard() {
  return GetCachedSwitchValue("Switch.System.Runtime.Serialization.SerializationGuard", s_serializationGuard);
}

Boolean LocalAppContextSwitches::GetCachedSwitchValue(String switchName, Int32& cachedSwitchValue) {
  if (cachedSwitchValue < 0) {
    return false;
  }
  if (cachedSwitchValue > 0) {
    return true;
  }
  return GetCachedSwitchValueInternal(switchName, cachedSwitchValue);
}

Boolean LocalAppContextSwitches::GetCachedSwitchValueInternal(String switchName, Int32& cachedSwitchValue) {
}

Boolean LocalAppContextSwitches::GetSwitchDefaultValue(String switchName) {
  if (switchName == "Switch.System.Runtime.Serialization.SerializationGuard") {
    return true;
  }
  return false;
}

} // namespace System::Private::CoreLib::System::LocalAppContextSwitchesNamespace
