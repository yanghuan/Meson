#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices {
namespace UnknownWrapperNamespace {
CLASS(UnknownWrapper) {
  private: Object WrappedObject;
};
} // namespace UnknownWrapperNamespace
using UnknownWrapper = UnknownWrapperNamespace::UnknownWrapper;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
