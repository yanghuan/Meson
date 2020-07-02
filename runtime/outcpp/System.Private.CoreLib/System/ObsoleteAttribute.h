#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Boolean.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
namespace ObsoleteAttributeNamespace {
CLASS(ObsoleteAttribute) {
  public: String get_Message();
  public: Boolean get_IsError();
  private: String _message;
  private: Boolean _error;
};
} // namespace ObsoleteAttributeNamespace
using ObsoleteAttribute = ObsoleteAttributeNamespace::ObsoleteAttribute;
} // namespace System::Private::CoreLib::System
