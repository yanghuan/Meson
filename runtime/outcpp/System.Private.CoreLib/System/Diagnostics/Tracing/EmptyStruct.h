#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Diagnostics::Tracing {
namespace EmptyStructNamespace {
struct EmptyStruct {
};
} // namespace EmptyStructNamespace
using EmptyStruct = EmptyStructNamespace::EmptyStruct;
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing
