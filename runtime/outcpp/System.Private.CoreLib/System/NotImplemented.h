#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(Exception)
namespace NotImplementedNamespace {
class NotImplemented {
  public: static Exception get_ByDesign();
};
} // namespace NotImplementedNamespace
using NotImplemented = NotImplementedNamespace::NotImplemented;
} // namespace System::Private::CoreLib::System
