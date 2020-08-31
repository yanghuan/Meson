#pragma once

#include <System.Private.CoreLib/System/Runtime/Versioning/OSPlatformAttribute.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::Versioning {
namespace ObsoletedInOSPlatformAttributeNamespace {
CLASS(ObsoletedInOSPlatformAttribute) : public OSPlatformAttribute::in {
  public: String get_Message() { return Message; }
  public: String get_Url() { return Url; }
  public: void set_Url(String value) { Url = value; }
  public: void ctor(String platformName);
  public: void ctor(String platformName, String message);
  private: String Message;
  private: String Url;
};
} // namespace ObsoletedInOSPlatformAttributeNamespace
using ObsoletedInOSPlatformAttribute = ObsoletedInOSPlatformAttributeNamespace::ObsoletedInOSPlatformAttribute;
} // namespace System::Private::CoreLib::System::Runtime::Versioning
