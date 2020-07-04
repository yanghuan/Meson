#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/IntPtr.h>

namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace QCallModuleNamespace {
struct QCallModule {
  private: void* _ptr;
  private: IntPtr _module;
};
} // namespace QCallModuleNamespace
using QCallModule = QCallModuleNamespace::QCallModule;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
