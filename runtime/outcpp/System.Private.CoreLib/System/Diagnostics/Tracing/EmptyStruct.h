#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Diagnostics::Tracing {
namespace EmptyStructNamespace {
struct EmptyStruct {
  public: void Ctor();
};
} // namespace EmptyStructNamespace
using EmptyStruct = EmptyStructNamespace::EmptyStruct;
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing
