#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace IsConstNamespace {
class IsConst : public Object::in {
};
} // namespace IsConstNamespace
using IsConst = IsConstNamespace::IsConst;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
