#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/Int32.h>

namespace System::Private::CoreLib::System {
FORWARD(Object)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::Uri::System {
FORWARD(Uri)
namespace UriBuilderNamespace {
using namespace ::System::Private::CoreLib::System;
CLASS(UriBuilder) {
  private: void Init(Uri uri);
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
