#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Runtime::CompilerServices {
FORWARD(IStrongBox)
namespace StrongBoxNamespace {
CLASS(StrongBox, T) : public object {
  public: using interface = rt::TypeList<IStrongBox>;
  private: Object get_ValueOfIStrongBox();
  private: void set_ValueOfIStrongBox(Object value);
  public: void ctor();
  public: void ctor(T value);
  public: T Value;
};
} // namespace StrongBoxNamespace
template <class T>
using StrongBox = StrongBoxNamespace::StrongBox<T>;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
