#pragma once

#include <System.Private.CoreLib/System/String.h>

namespace System::Private::CoreLib::System::Resources {
FORWARD(ResourceManager)
} // namespace System::Private::CoreLib::System::Resources
namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::Uri::System {
namespace SRNamespace {
using namespace ::System::Private::CoreLib::System;
using namespace ::System::Private::CoreLib::System::Resources;
class SR {
  public: static ResourceManager get_ResourceManager();
  public: static String get_net_uri_BadAuthority();
  public: static String get_net_uri_BadAuthorityTerminator();
  public: static String get_net_uri_BadFormat();
  public: static String get_net_uri_NeedFreshParser();
  public: static String get_net_uri_AlreadyRegistered();
  public: static String get_net_uri_BadHostName();
  public: static String get_net_uri_BadPort();
  public: static String get_net_uri_BadScheme();
  public: static String get_net_uri_BadString();
  public: static String get_net_uri_BadUserPassword();
  public: static String get_net_uri_CannotCreateRelative();
  public: static String get_net_uri_SchemeLimit();
  public: static String get_net_uri_EmptyUri();
  public: static String get_net_uri_InvalidUriKind();
  public: static String get_net_uri_MustRootedPath();
  public: static String get_net_uri_NotAbsolute();
  public: static String get_net_uri_PortOutOfRange();
  public: static String get_net_uri_SizeLimit();
  public: static String get_net_uri_UserDrivenParsing();
  public: static String get_net_uri_NotJustSerialization();
  public: static String get_net_uri_BadUnicodeHostForIdn();
  public: static String get_Argument_ExtraNotValid();
  public: static String get_Argument_InvalidUriSubcomponent();
  public: static String get_InvalidNullArgument();
  public: static String get_net_uri_InitializeCalledAlreadyOrTooLate();
  private: static Boolean UsingResourceKeys();
  public: static String GetResourceString(String resourceKey, String defaultString = nullptr);
  public: static String Format(String resourceFormat, Object p1);
  public: static String Format(String resourceFormat, Object p1, Object p2);
  private: static ResourceManager s_resourceManager;
};
} // namespace SRNamespace
using SR = SRNamespace::SR;
} // namespace System::Private::Uri::System
