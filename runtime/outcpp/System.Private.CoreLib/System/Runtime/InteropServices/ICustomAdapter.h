#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices {
namespace ICustomAdapterNamespace {
CLASS(ICustomAdapter) {
  public: Object GetUnderlyingObject();
};
} // namespace ICustomAdapterNamespace
using ICustomAdapter = ICustomAdapterNamespace::ICustomAdapter;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
