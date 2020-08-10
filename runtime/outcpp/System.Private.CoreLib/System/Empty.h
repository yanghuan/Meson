#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
namespace EmptyNamespace {
CLASS(Empty) : public Object::in {
  private: void ctor();
  public: String ToString();
  private: static void ctor_static();
  public: static Empty Value;
};
} // namespace EmptyNamespace
using Empty = EmptyNamespace::Empty;
} // namespace System::Private::CoreLib::System
