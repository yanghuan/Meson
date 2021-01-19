#include "UriBuilder-dep.h"

#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/Exception-dep.h>
#include <System.Private.CoreLib/System/Int32-dep.h>
#include <System.Private.CoreLib/System/OutOfMemoryException-dep.h>
#include <System.Private.Uri/System/SR-dep.h>
#include <System.Private.Uri/System/Uri-dep.h>
#include <System.Private.Uri/System/UriFormatException-dep.h>
#include <System.Private.Uri/System/UriKind.h>
#include <System.Private.Uri/System/UriParser-dep.h>
#include <System.Private.Uri/System/UriSyntaxFlags.h>

namespace System::Private::Uri::System::UriBuilderNamespace {
using namespace ::System::Private::CoreLib::System;

void UriBuilder___::set_Extra(String value) {
  if (value == nullptr) {
    value = String::in::Empty;
  }
  if (value->get_Length() > 0) {
    if (value[0] == '#') {
      get_Fragment(value->Substring(1));
      return;
    }
    if (value[0] != '?') {
      rt::throw_exception<ArgumentException>(SR::get_Argument_ExtraNotValid(), "value");
    }
    Int32 num = value->IndexOf('#');
    if (num == -1) {
      num = value->get_Length();
    } else {
      get_Fragment(value->Substring(num + 1));
    }
    get_Query(value->Substring(1, num - 1));
  } else {
    get_Fragment(String::in::Empty);
    get_Query(String::in::Empty);
  }
}

String UriBuilder___::get_Fragment() {
  return _fragment;
}

void UriBuilder___::set_Fragment(String value) {
  if (value == nullptr) {
    value = String::in::Empty;
  }
  if (value->get_Length() > 0 && value[0] != '#') {
    value = "#" + value;
  }
  _fragment = value;
  _changed = true;
}

String UriBuilder___::get_Host() {
  return _host;
}

void UriBuilder___::set_Host(String value) {
  if (value == nullptr) {
    value = String::in::Empty;
  }
  _host = value;
  if (_host->Contains(':') && _host[0] != '[') {
    _host = "[" + _host + "]";
  }
  _changed = true;
}

String UriBuilder___::get_Password() {
  return _password;
}

void UriBuilder___::set_Password(String value) {
  if (value == nullptr) {
    value = String::in::Empty;
  }
  _password = value;
  _changed = true;
}

String UriBuilder___::get_Path() {
  return _path;
}

void UriBuilder___::set_Path(String value) {
  _path = (String::in::IsNullOrEmpty(value) ? "/" : Uri::in::InternalEscapeString(value->Replace('\\', '/')));
  _changed = true;
}

Int32 UriBuilder___::get_Port() {
  return _port;
}

void UriBuilder___::set_Port(Int32 value) {
  if (value < -1 || value > 65535) {
    rt::throw_exception<ArgumentOutOfRangeException>("value");
  }
  _port = value;
  _changed = true;
}

String UriBuilder___::get_Query() {
  return _query;
}

void UriBuilder___::set_Query(String value) {
  if (value == nullptr) {
    value = String::in::Empty;
  }
  if (value->get_Length() > 0 && value[0] != '?') {
    value = "?" + value;
  }
  _query = value;
  _changed = true;
}

String UriBuilder___::get_Scheme() {
  return _scheme;
}

void UriBuilder___::set_Scheme(String value) {
  if (value == nullptr) {
    value = String::in::Empty;
  }
  Int32 num = value->IndexOf(':');
  if (num != -1) {
    value = value->Substring(0, num);
  }
  if (value->get_Length() != 0) {
    if (!Uri::in::CheckSchemeName(value)) {
      rt::throw_exception<ArgumentException>(SR::get_net_uri_BadScheme(), "value");
    }
    value = value->ToLowerInvariant();
  }
  _scheme = value;
  _changed = true;
}

Uri UriBuilder___::get_Uri() {
  if (_changed) {
    _uri = rt::newobj<Uri>(ToString());
    SetFieldsFromUri(_uri);
    _changed = false;
  }
  return _uri;
}

String UriBuilder___::get_UserName() {
  return _username;
}

void UriBuilder___::set_UserName(String value) {
  if (value == nullptr) {
    value = String::in::Empty;
  }
  _username = value;
  _changed = true;
}

void UriBuilder___::ctor() {
  _changed = true;
  _fragment = String::in::Empty;
  _host = "localhost";
  _password = String::in::Empty;
  _path = "/";
  _port = -1;
  _query = String::in::Empty;
  _scheme = "http";
  _schemeDelimiter = Uri::in::SchemeDelimiter;
  _username = String::in::Empty;
  Object::in::ctor();
}

void UriBuilder___::ctor(String uri) {
  _changed = true;
  _fragment = String::in::Empty;
  _host = "localhost";
  _password = String::in::Empty;
  _path = "/";
  _port = -1;
  _query = String::in::Empty;
  _scheme = "http";
  _schemeDelimiter = Uri::in::SchemeDelimiter;
  _username = String::in::Empty;
  Object::in::ctor();
  Uri uri2 = rt::newobj<Uri>(uri, UriKind::RelativeOrAbsolute);
  if (uri2->get_IsAbsoluteUri()) {
    Init(uri2);
    return;
  }
  uri = Uri::in::UriSchemeHttp + Uri::in::SchemeDelimiter + uri;
  Init(rt::newobj<Uri>(uri));
}

void UriBuilder___::ctor(Uri uri) {
  _changed = true;
  _fragment = String::in::Empty;
  _host = "localhost";
  _password = String::in::Empty;
  _path = "/";
  _port = -1;
  _query = String::in::Empty;
  _scheme = "http";
  _schemeDelimiter = Uri::in::SchemeDelimiter;
  _username = String::in::Empty;
  Object::in::ctor();
  if ((Object)uri == nullptr) {
    rt::throw_exception<ArgumentNullException>("uri");
  }
  Init(uri);
}

void UriBuilder___::Init(Uri uri) {
  _fragment = uri->get_Fragment();
  _query = uri->get_Query();
  _host = uri->get_Host();
  _path = uri->get_AbsolutePath();
  _port = uri->get_Port();
  _scheme = uri->get_Scheme();
  _schemeDelimiter = (uri->get_HasAuthority() ? Uri::in::SchemeDelimiter : ":");
  String userInfo = uri->get_UserInfo();
  if (!String::in::IsNullOrEmpty(userInfo)) {
    Int32 num = userInfo->IndexOf(':');
    if (num != -1) {
      _password = userInfo->Substring(num + 1);
      _username = userInfo->Substring(0, num);
    } else {
      _username = userInfo;
    }
  }
  SetFieldsFromUri(uri);
}

void UriBuilder___::ctor(String schemeName, String hostName) {
  _changed = true;
  _fragment = String::in::Empty;
  _host = "localhost";
  _password = String::in::Empty;
  _path = "/";
  _port = -1;
  _query = String::in::Empty;
  _scheme = "http";
  _schemeDelimiter = Uri::in::SchemeDelimiter;
  _username = String::in::Empty;
  Object::in::ctor();
  get_Scheme(schemeName);
  get_Host(hostName);
}

void UriBuilder___::ctor(String scheme, String host, Int32 portNumber) {
  get_Port(portNumber);
}

void UriBuilder___::ctor(String scheme, String host, Int32 port, String pathValue) {
  get_Path(pathValue);
}

void UriBuilder___::ctor(String scheme, String host, Int32 port, String path, String extraValue) {
  try {
    set_Extra(extraValue);
  } catch (Exception ex) {
    if (rt::is<OutOfMemoryException>(ex)) {
      throw;
    }
    rt::throw_exception<ArgumentException>(SR::get_Argument_ExtraNotValid(), "extraValue");
  }
}

Boolean UriBuilder___::Equals(Object rparam) {
  if (rparam == nullptr) {
    return false;
  }
  return get_Uri()->Equals(rparam->ToString());
}

Int32 UriBuilder___::GetHashCode() {
  return get_Uri()->GetHashCode();
}

void UriBuilder___::SetFieldsFromUri(Uri uri) {
  _fragment = uri->get_Fragment();
  _query = uri->get_Query();
  _host = uri->get_Host();
  _path = uri->get_AbsolutePath();
  _port = uri->get_Port();
  _scheme = uri->get_Scheme();
  _schemeDelimiter = (uri->get_HasAuthority() ? Uri::in::SchemeDelimiter : ":");
  String userInfo = uri->get_UserInfo();
  if (userInfo->get_Length() > 0) {
    Int32 num = userInfo->IndexOf(':');
    if (num != -1) {
      _password = userInfo->Substring(num + 1);
      _username = userInfo->Substring(0, num);
    } else {
      _username = userInfo;
    }
  }
}

String UriBuilder___::ToString() {
  if (_username->get_Length() == 0 && _password->get_Length() > 0) {
    rt::throw_exception<UriFormatException>(SR::get_net_uri_BadUserPassword());
  }
  if (_scheme->get_Length() != 0) {
    UriParser syntax = UriParser::in::GetSyntax(_scheme);
    if (syntax != nullptr) {
      _schemeDelimiter = ((syntax->InFact(UriSyntaxFlags::MustHaveAuthority) || (_host->get_Length() != 0 && syntax->NotAny(UriSyntaxFlags::MailToLikeUri) && syntax->InFact(UriSyntaxFlags::OptionalAuthority))) ? Uri::in::SchemeDelimiter : ":");
    } else {
      _schemeDelimiter = ((_host->get_Length() != 0) ? Uri::in::SchemeDelimiter : ":");
    }
  }
  String text = ((_scheme->get_Length() != 0) ? (_scheme + _schemeDelimiter) : String::in::Empty);
  return text + _username + ((_password->get_Length() > 0) ? (":" + _password) : String::in::Empty) + ((_username->get_Length() > 0) ? "@" : String::in::Empty) + _host + ((_port != -1 && _host->get_Length() > 0) ? (":" + _port) : String::in::Empty) + ((_host->get_Length() > 0 && _path->get_Length() != 0 && _path[0] != '/') ? "/" : String::in::Empty) + _path + _query + _fragment;
}

} // namespace System::Private::Uri::System::UriBuilderNamespace
