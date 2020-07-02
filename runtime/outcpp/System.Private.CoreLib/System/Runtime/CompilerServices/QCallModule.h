#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/IntPtr.h>

namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace QCallModuleNamespace {
struct QCallModule {
  private: IntPtr m_ptr;
  private: IntPtr m_module;
};
} // namespace QCallModuleNamespace
using QCallModule = QCallModuleNamespace::QCallModule;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
