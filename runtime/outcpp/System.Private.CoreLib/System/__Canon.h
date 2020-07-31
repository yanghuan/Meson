#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
namespace __CanonNamespace {
CLASS(__Canon) : public Object::in {
};
} // namespace __CanonNamespace
using __Canon = __CanonNamespace::__Canon;
} // namespace System::Private::CoreLib::System
