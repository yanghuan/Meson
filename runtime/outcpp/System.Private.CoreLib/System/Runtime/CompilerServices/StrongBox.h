#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace StrongBoxNamespace {
CLASS(StrongBox, T) {
  private: Object get_ValueOfIStrongBox();
  private: void set_ValueOfIStrongBox(Object value);
  public: void Ctor();
  public: void Ctor(T value);
  public: T Value;
};
} // namespace StrongBoxNamespace
template <class T>
using StrongBox = StrongBoxNamespace::StrongBox<T>;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
