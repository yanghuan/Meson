#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices {
namespace UnknownWrapperNamespace {
CLASS(UnknownWrapper) {
  public: Object get_WrappedObject() { return WrappedObject; }
  public: void Ctor(Object obj);
  private: Object WrappedObject;
};
} // namespace UnknownWrapperNamespace
using UnknownWrapper = UnknownWrapperNamespace::UnknownWrapper;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
