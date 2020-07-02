#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(Object)
namespace ICloneableNamespace {
CLASS(ICloneable) {
  public: Object Clone();
};
} // namespace ICloneableNamespace
using ICloneable = ICloneableNamespace::ICloneable;
} // namespace System::Private::CoreLib::System
