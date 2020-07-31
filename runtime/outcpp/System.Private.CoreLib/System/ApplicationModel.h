#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/Interop.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
namespace ApplicationModelNamespace {
class ApplicationModel {
  private: static Interop::BOOL IsAppXProcess();
  private: static void SCtor();
  public: static Boolean IsUap;
};
} // namespace ApplicationModelNamespace
using ApplicationModel = ApplicationModelNamespace::ApplicationModel;
} // namespace System::Private::CoreLib::System
