#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARD(Exception)
FORWARD(RuntimeType)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::CompilerServices {
FORWARD(ICastable)
namespace ICastableHelpersNamespace {
CLASS(ICastableHelpers) {
  public: static Boolean IsInstanceOfInterface(ICastable castable, RuntimeType type, Exception& castError);
  public: static RuntimeType GetImplType(ICastable castable, RuntimeType interfaceType);
};
} // namespace ICastableHelpersNamespace
using ICastableHelpers = ICastableHelpersNamespace::ICastableHelpers;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
