#pragma once

#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System::Diagnostics::Tracing {
namespace EmptyStructNamespace {
struct EmptyStruct : public valueType<EmptyStruct> {
};
} // namespace EmptyStructNamespace
using EmptyStruct = EmptyStructNamespace::EmptyStruct;
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing
