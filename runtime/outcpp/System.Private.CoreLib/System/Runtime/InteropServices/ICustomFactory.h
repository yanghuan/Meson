#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARD(MarshalByRefObject)
FORWARD(Type)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices {
namespace ICustomFactoryNamespace {
CLASS(ICustomFactory) : public Object::in {
  public: MarshalByRefObject CreateInstance(Type serverType);
};
} // namespace ICustomFactoryNamespace
using ICustomFactory = ICustomFactoryNamespace::ICustomFactory;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
