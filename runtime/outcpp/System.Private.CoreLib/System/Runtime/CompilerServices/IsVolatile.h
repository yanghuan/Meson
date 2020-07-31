#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace IsVolatileNamespace {
class IsVolatile : public Object::in {
};
} // namespace IsVolatileNamespace
using IsVolatile = IsVolatileNamespace::IsVolatile;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
