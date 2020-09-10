#include "CLRConfig-dep.h"

#include <System.Private.CoreLib/Interop-dep.h>
#include <System.Private.CoreLib/System/Char-dep.h>
#include <System.Private.CoreLib/System/Span-dep.h>

namespace System::Private::CoreLib::System::CLRConfigNamespace {
Boolean CLRConfig::GetBoolValue(String switchName, Boolean& exist) {
  return GetConfigBoolValue(switchName, exist);
}

Boolean CLRConfig::GetBoolValueWithFallbacks(String switchName, String environmentName, Boolean defaultValue) {
  Boolean exist;
  Boolean boolValue = GetBoolValue(switchName, exist);
  if (exist) {
    return boolValue;
  }
  Char as[32] = {};
  Span<Char> buffer = as;
  switch (Interop::Kernel32::GetEnvironmentVariable(environmentName, buffer).get()) {
    case 1:
      if (buffer[0] == '0') {
        return false;
      }
      if (buffer[0] == '1') {
        return true;
      }
      break;
    case 4:
      if (Boolean::IsTrueStringIgnoreCase(buffer.Slice(0, 4))) {
        return true;
      }
      break;
    case 5:
      if (Boolean::IsFalseStringIgnoreCase(buffer.Slice(0, 5))) {
        return false;
      }
      break;
  }
  return defaultValue;
}

} // namespace System::Private::CoreLib::System::CLRConfigNamespace
