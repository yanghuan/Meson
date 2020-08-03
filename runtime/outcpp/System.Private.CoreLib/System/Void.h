#pragma once

#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System {
namespace VoidNamespace {
CLASS(Void) : public ValueType::in {
};
} // namespace VoidNamespace
using Void = VoidNamespace::Void;
} // namespace System::Private::CoreLib::System
