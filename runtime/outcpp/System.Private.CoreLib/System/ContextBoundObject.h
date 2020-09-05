#pragma once

#include <System.Private.CoreLib/System/MarshalByRefObject.h>

namespace System::Private::CoreLib::System {
namespace ContextBoundObjectNamespace {
CLASS(ContextBoundObject) : public MarshalByRefObject::in {
  public: void ctor();
};
} // namespace ContextBoundObjectNamespace
using ContextBoundObject = ContextBoundObjectNamespace::ContextBoundObject;
} // namespace System::Private::CoreLib::System
