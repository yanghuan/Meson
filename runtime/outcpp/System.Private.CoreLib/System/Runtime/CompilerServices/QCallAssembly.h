#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/IntPtr.h>

namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace QCallAssemblyNamespace {
struct QCallAssembly {
  private: IntPtr m_ptr;
  private: IntPtr m_assembly;
};
} // namespace QCallAssemblyNamespace
using QCallAssembly = QCallAssemblyNamespace::QCallAssembly;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
