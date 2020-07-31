#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/MarshalByRefObject.h>

namespace System::Private::CoreLib::System {
namespace ContextBoundObjectNamespace {
CLASS(ContextBoundObject) : public MarshalByRefObject::in {
  protected: void Ctor();
};
} // namespace ContextBoundObjectNamespace
using ContextBoundObject = ContextBoundObjectNamespace::ContextBoundObject;
} // namespace System::Private::CoreLib::System
