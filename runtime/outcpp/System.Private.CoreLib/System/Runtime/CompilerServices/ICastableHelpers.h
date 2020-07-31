#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARD(Exception)
FORWARD(RuntimeType)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::CompilerServices {
FORWARD(ICastable)
namespace ICastableHelpersNamespace {
class ICastableHelpers : public Object::in {
  public: static Boolean IsInstanceOfInterface(ICastable castable, RuntimeType type, Exception& castError);
  public: static RuntimeType GetImplType(ICastable castable, RuntimeType interfaceType);
};
} // namespace ICastableHelpersNamespace
using ICastableHelpers = ICastableHelpersNamespace::ICastableHelpers;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
