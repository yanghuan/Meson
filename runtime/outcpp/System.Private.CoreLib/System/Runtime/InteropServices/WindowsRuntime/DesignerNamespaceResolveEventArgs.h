#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Collections::ObjectModel {
FORWARD(Collection, T)
} // namespace System::Private::CoreLib::System::Collections::ObjectModel
namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices::WindowsRuntime {
namespace DesignerNamespaceResolveEventArgsNamespace {
using namespace ::System::Private::CoreLib::System::Collections::ObjectModel;
CLASS(DesignerNamespaceResolveEventArgs) {
  public: Collection<String> get_ResolvedAssemblyFiles();
  private: String _NamespaceName;
  private: Collection<String> _ResolvedAssemblyFiles;
};
} // namespace DesignerNamespaceResolveEventArgsNamespace
using DesignerNamespaceResolveEventArgs = DesignerNamespaceResolveEventArgsNamespace::DesignerNamespaceResolveEventArgs;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices::WindowsRuntime
