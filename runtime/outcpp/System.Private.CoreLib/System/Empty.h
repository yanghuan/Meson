#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
namespace EmptyNamespace {
CLASS(Empty) {
  private: void Ctor();
  public: String ToString();
  private: static void SCtor();
  public: static Empty Value;
};
} // namespace EmptyNamespace
using Empty = EmptyNamespace::Empty;
} // namespace System::Private::CoreLib::System
