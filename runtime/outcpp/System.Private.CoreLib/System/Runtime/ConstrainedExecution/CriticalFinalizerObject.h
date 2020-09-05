#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Runtime::ConstrainedExecution {
namespace CriticalFinalizerObjectNamespace {
CLASS(CriticalFinalizerObject) : public object {
  public: void ctor();
  protected: void Finalize();
};
} // namespace CriticalFinalizerObjectNamespace
using CriticalFinalizerObject = CriticalFinalizerObjectNamespace::CriticalFinalizerObject;
} // namespace System::Private::CoreLib::System::Runtime::ConstrainedExecution
