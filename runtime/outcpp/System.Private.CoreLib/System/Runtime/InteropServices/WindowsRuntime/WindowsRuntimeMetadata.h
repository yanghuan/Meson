#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
FORWARD_(Array, T1, T2)
FORWARD_(EventHandler, T1, T2)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices::WindowsRuntime {
FORWARD(DesignerNamespaceResolveEventArgs)
namespace WindowsRuntimeMetadataNamespace {
class WindowsRuntimeMetadata {
  public: static Array<String> OnDesignerNamespaceResolve(String namespaceName);
  private: static EventHandler<DesignerNamespaceResolveEventArgs> DesignerNamespaceResolve;
};
} // namespace WindowsRuntimeMetadataNamespace
using WindowsRuntimeMetadata = WindowsRuntimeMetadataNamespace::WindowsRuntimeMetadata;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices::WindowsRuntime
