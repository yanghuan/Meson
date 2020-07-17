#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
namespace ContextBoundObjectNamespace {
CLASS(ContextBoundObject) {
  protected: void Ctor();
};
} // namespace ContextBoundObjectNamespace
using ContextBoundObject = ContextBoundObjectNamespace::ContextBoundObject;
} // namespace System::Private::CoreLib::System
