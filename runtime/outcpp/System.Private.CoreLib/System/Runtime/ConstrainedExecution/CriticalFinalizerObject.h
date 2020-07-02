#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Runtime::ConstrainedExecution {
namespace CriticalFinalizerObjectNamespace {
CLASS(CriticalFinalizerObject) {
  protected: void Finalize();
};
} // namespace CriticalFinalizerObjectNamespace
using CriticalFinalizerObject = CriticalFinalizerObjectNamespace::CriticalFinalizerObject;
} // namespace System::Private::CoreLib::System::Runtime::ConstrainedExecution
