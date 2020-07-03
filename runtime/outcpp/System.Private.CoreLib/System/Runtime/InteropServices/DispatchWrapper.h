#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices {
namespace DispatchWrapperNamespace {
CLASS(DispatchWrapper) {
  private: Object WrappedObject;
};
} // namespace DispatchWrapperNamespace
using DispatchWrapper = DispatchWrapperNamespace::DispatchWrapper;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
