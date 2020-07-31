#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Runtime::ConstrainedExecution {
namespace CriticalFinalizerObjectNamespace {
CLASS(CriticalFinalizerObject) : public Object::in {
  protected: void Ctor();
  protected: void Finalize();
};
} // namespace CriticalFinalizerObjectNamespace
using CriticalFinalizerObject = CriticalFinalizerObjectNamespace::CriticalFinalizerObject;
} // namespace System::Private::CoreLib::System::Runtime::ConstrainedExecution
