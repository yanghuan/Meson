#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
namespace DllNotFoundExceptionNamespace {
CLASS(DllNotFoundException) {
};
} // namespace DllNotFoundExceptionNamespace
using DllNotFoundException = DllNotFoundExceptionNamespace::DllNotFoundException;
} // namespace System::Private::CoreLib::System
