#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Int32)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices::WindowsRuntime {
namespace IRestrictedErrorInfoNamespace {
CLASS(IRestrictedErrorInfo) {
  public: void GetErrorDetails(String& description, Int32& error, String& restrictedDescription, String& capabilitySid);
  public: void GetReference(String& reference);
};
} // namespace IRestrictedErrorInfoNamespace
using IRestrictedErrorInfo = IRestrictedErrorInfoNamespace::IRestrictedErrorInfo;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices::WindowsRuntime