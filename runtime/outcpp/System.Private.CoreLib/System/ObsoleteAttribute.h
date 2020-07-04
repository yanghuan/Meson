#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Boolean.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
namespace ObsoleteAttributeNamespace {
CLASS(ObsoleteAttribute) {
  public: String get_Message() { return Message; }
  public: Boolean get_IsError() { return IsError; }
  public: String get_DiagnosticId() { return DiagnosticId; }
  public: void set_DiagnosticId(String value) { DiagnosticId = value; }
  public: String get_UrlFormat() { return UrlFormat; }
  public: void set_UrlFormat(String value) { UrlFormat = value; }
  private: String Message;
  private: Boolean IsError;
  private: String DiagnosticId;
  private: String UrlFormat;
};
} // namespace ObsoleteAttributeNamespace
using ObsoleteAttribute = ObsoleteAttributeNamespace::ObsoleteAttribute;
} // namespace System::Private::CoreLib::System
