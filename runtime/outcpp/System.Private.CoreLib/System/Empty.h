#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
namespace EmptyNamespace {
CLASS(Empty) {
  public: String ToString();
  public: static Empty Value;
};
} // namespace EmptyNamespace
using Empty = EmptyNamespace::Empty;
} // namespace System::Private::CoreLib::System
