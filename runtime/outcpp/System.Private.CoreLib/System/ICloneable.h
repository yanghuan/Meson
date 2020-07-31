#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
namespace ICloneableNamespace {
CLASS(ICloneable) : public Object::in {
  public: Object Clone();
};
} // namespace ICloneableNamespace
using ICloneable = ICloneableNamespace::ICloneable;
} // namespace System::Private::CoreLib::System
