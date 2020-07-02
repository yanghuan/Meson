#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
namespace OutOfMemoryExceptionNamespace {
CLASS(OutOfMemoryException) {
};
} // namespace OutOfMemoryExceptionNamespace
using OutOfMemoryException = OutOfMemoryExceptionNamespace::OutOfMemoryException;
} // namespace System::Private::CoreLib::System
