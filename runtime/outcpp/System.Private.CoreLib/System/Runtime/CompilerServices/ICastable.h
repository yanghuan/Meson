#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARD(Exception)
FORWARDS(RuntimeTypeHandle)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace ICastableNamespace {
CLASS(ICastable) {
  public: Boolean IsInstanceOfInterface(RuntimeTypeHandle interfaceType, Exception& castError);
  public: RuntimeTypeHandle GetImplType(RuntimeTypeHandle interfaceType);
};
} // namespace ICastableNamespace
using ICastable = ICastableNamespace::ICastable;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
