#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
FORWARDS(Boolean)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Globalization {
FORWARD(CultureInfo)
} // namespace System::Private::CoreLib::System::Globalization
namespace System::Private::CoreLib::Internal::Resources {
FORWARD(PRIExceptionInfo)
namespace WindowsRuntimeResourceManagerBaseNamespace {
using namespace ::System::Private::CoreLib::System;
using namespace ::System::Private::CoreLib::System::Globalization;
CLASS(WindowsRuntimeResourceManagerBase) {
  public: Boolean Initialize(String libpath, String reswFilename, PRIExceptionInfo& exceptionInfo);
  public: String GetString(String stringName, String startingCulture, String neutralResourcesCulture);
  public: Boolean SetGlobalResourceContextDefaultCulture(CultureInfo ci);
  public: static Boolean IsValidCulture(String cultureName);
};
} // namespace WindowsRuntimeResourceManagerBaseNamespace
using WindowsRuntimeResourceManagerBase = WindowsRuntimeResourceManagerBaseNamespace::WindowsRuntimeResourceManagerBase;
} // namespace System::Private::CoreLib::Internal::Resources
