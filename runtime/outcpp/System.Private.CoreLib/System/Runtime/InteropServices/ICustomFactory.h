#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(Type)
FORWARD(MarshalByRefObject)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices {
namespace ICustomFactoryNamespace {
CLASS(ICustomFactory) {
  public: MarshalByRefObject CreateInstance(Type serverType);
};
} // namespace ICustomFactoryNamespace
using ICustomFactory = ICustomFactoryNamespace::ICustomFactory;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
