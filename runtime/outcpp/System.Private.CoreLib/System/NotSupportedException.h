#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
namespace NotSupportedExceptionNamespace {
CLASS(NotSupportedException) {
};
} // namespace NotSupportedExceptionNamespace
using NotSupportedException = NotSupportedExceptionNamespace::NotSupportedException;
} // namespace System::Private::CoreLib::System
