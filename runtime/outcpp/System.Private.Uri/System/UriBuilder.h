#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::Uri::System {
FORWARD(Uri)
namespace UriBuilderNamespace {
using namespace ::System::Private::CoreLib::System;
CLASS(UriBuilder) : public Object::in {
  private: void set_Extra(String value);
  public: String get_Fragment();
  public: void set_Fragment(String value);
  public: String get_Host();
  public: void set_Host(String value);
  public: String get_Password();
  public: void set_Password(String value);
  public: String get_Path();
  public: void set_Path(String value);
  public: Int32 get_Port();
  public: void set_Port(Int32 value);
  public: String get_Query();
  public: void set_Query(String value);
  public: String get_Scheme();
  public: void set_Scheme(String value);
  public: Uri get_Uri();
  public: String get_UserName();
  public: void set_UserName(String value);
  public: void Ctor();
  public: void Ctor(String uri);
  public: void Ctor(Uri uri);
  private: void Init(Uri uri);
  public: void Ctor(String schemeName, String hostName);
  public: void Ctor(String scheme, String host, Int32 portNumber);
  public: void Ctor(String scheme, String host, Int32 port, String pathValue);
  public: void Ctor(String scheme, String host, Int32 port, String path, String extraValue);
  public: Boolean Equals(Object rparam);
  public: Int32 GetHashCode();
  private: void SetFieldsFromUri(Uri uri);
  public: String ToString();
  private: Boolean _changed;
  private: String _fragment;
  private: String _host;
  private: String _password;
  private: String _path;
  private: Int32 _port;
  private: String _query;
  private: String _scheme;
  private: String _schemeDelimiter;
  private: Uri _uri;
  private: String _username;
};
} // namespace UriBuilderNamespace
using UriBuilder = UriBuilderNamespace::UriBuilder;
} // namespace System::Private::Uri::System
