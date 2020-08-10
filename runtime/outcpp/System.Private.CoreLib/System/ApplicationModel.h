#pragma once

#include <System.Private.CoreLib/Interop.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
namespace ApplicationModelNamespace {
class ApplicationModel {
  private: static Interop::BOOL IsAppXProcess();
  private: static void ctor_static();
  public: static Boolean IsUap;
};
} // namespace ApplicationModelNamespace
using ApplicationModel = ApplicationModelNamespace::ApplicationModel;
} // namespace System::Private::CoreLib::System
