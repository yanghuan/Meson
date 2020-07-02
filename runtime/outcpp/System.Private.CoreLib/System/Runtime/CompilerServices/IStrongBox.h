#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace IStrongBoxNamespace {
CLASS(IStrongBox) {
  public: Object get_Value();
  public: void set_Value(Object value);
};
} // namespace IStrongBoxNamespace
using IStrongBox = IStrongBoxNamespace::IStrongBox;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
