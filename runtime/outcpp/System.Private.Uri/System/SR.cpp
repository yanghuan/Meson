#include "SR-dep.h"

#include <System.Private.CoreLib/System/Resources/MissingManifestResourceException-dep.h>

namespace System::Private::Uri::System::SRNamespace {
using namespace ::System::Private::CoreLib::System::Resources;

ResourceManager SR::get_ResourceManager() {
}

String SR::get_net_uri_BadAuthority() {
  return GetResourceString("net_uri_BadAuthority");
}

String SR::get_net_uri_BadAuthorityTerminator() {
  return GetResourceString("net_uri_BadAuthorityTerminator");
}

String SR::get_net_uri_BadFormat() {
  return GetResourceString("net_uri_BadFormat");
}

String SR::get_net_uri_NeedFreshParser() {
  return GetResourceString("net_uri_NeedFreshParser");
}

String SR::get_net_uri_AlreadyRegistered() {
  return GetResourceString("net_uri_AlreadyRegistered");
}

String SR::get_net_uri_BadHostName() {
  return GetResourceString("net_uri_BadHostName");
}

String SR::get_net_uri_BadPort() {
  return GetResourceString("net_uri_BadPort");
}

String SR::get_net_uri_BadScheme() {
  return GetResourceString("net_uri_BadScheme");
}

String SR::get_net_uri_BadString() {
  return GetResourceString("net_uri_BadString");
}

String SR::get_net_uri_BadUserPassword() {
  return GetResourceString("net_uri_BadUserPassword");
}

String SR::get_net_uri_CannotCreateRelative() {
  return GetResourceString("net_uri_CannotCreateRelative");
}

String SR::get_net_uri_SchemeLimit() {
  return GetResourceString("net_uri_SchemeLimit");
}

String SR::get_net_uri_EmptyUri() {
  return GetResourceString("net_uri_EmptyUri");
}

String SR::get_net_uri_InvalidUriKind() {
  return GetResourceString("net_uri_InvalidUriKind");
}

String SR::get_net_uri_MustRootedPath() {
  return GetResourceString("net_uri_MustRootedPath");
}

String SR::get_net_uri_NotAbsolute() {
  return GetResourceString("net_uri_NotAbsolute");
}

String SR::get_net_uri_PortOutOfRange() {
  return GetResourceString("net_uri_PortOutOfRange");
}

String SR::get_net_uri_SizeLimit() {
  return GetResourceString("net_uri_SizeLimit");
}

String SR::get_net_uri_UserDrivenParsing() {
  return GetResourceString("net_uri_UserDrivenParsing");
}

String SR::get_net_uri_NotJustSerialization() {
  return GetResourceString("net_uri_NotJustSerialization");
}

String SR::get_net_uri_BadUnicodeHostForIdn() {
  return GetResourceString("net_uri_BadUnicodeHostForIdn");
}

String SR::get_Argument_ExtraNotValid() {
  return GetResourceString("Argument_ExtraNotValid");
}

String SR::get_Argument_InvalidUriSubcomponent() {
  return GetResourceString("Argument_InvalidUriSubcomponent");
}

String SR::get_InvalidNullArgument() {
  return GetResourceString("InvalidNullArgument");
}

String SR::get_net_uri_InitializeCalledAlreadyOrTooLate() {
  return GetResourceString("net_uri_InitializeCalledAlreadyOrTooLate");
}

Boolean SR::UsingResourceKeys() {
  return false;
}

String SR::GetResourceString(String resourceKey, String defaultString) {
  if (UsingResourceKeys()) {
  }
  String text = nullptr;
  try{
    text = get_ResourceManager()->GetString(resourceKey);
  } catch (MissingManifestResourceException) {
  }
  if (defaultString != nullptr && resourceKey->Equals(text)) {
    return defaultString;
  }
  return text;
}

String SR::Format(String resourceFormat, Object p1) {
  if (UsingResourceKeys()) {
  }
  return String::in::Format(resourceFormat, p1);
}

String SR::Format(String resourceFormat, Object p1, Object p2) {
  if (UsingResourceKeys()) {
  }
  return String::in::Format(resourceFormat, p1, p2);
}

} // namespace System::Private::Uri::System::SRNamespace
