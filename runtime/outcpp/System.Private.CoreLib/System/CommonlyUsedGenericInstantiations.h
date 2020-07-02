#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Threading::Tasks {
FORWARD_(Task, T1, T2)
} // namespace System::Private::CoreLib::System::Threading::Tasks
namespace System::Private::CoreLib::System {
namespace CommonlyUsedGenericInstantiationsNamespace {
using namespace ::System::Private::CoreLib::System::Threading::Tasks;
class CommonlyUsedGenericInstantiations {
  private: static Task<> AsyncHelper3();
  private: static void CommonlyUsedWinRTRedirectedInterfaceStubs();
};
} // namespace CommonlyUsedGenericInstantiationsNamespace
using CommonlyUsedGenericInstantiations = CommonlyUsedGenericInstantiationsNamespace::CommonlyUsedGenericInstantiations;
} // namespace System::Private::CoreLib::System
