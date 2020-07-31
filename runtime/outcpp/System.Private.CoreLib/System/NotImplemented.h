#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARD(Exception)
namespace NotImplementedNamespace {
class NotImplemented : public Object::in {
  public: static Exception get_ByDesign();
};
} // namespace NotImplementedNamespace
using NotImplemented = NotImplementedNamespace::NotImplemented;
} // namespace System::Private::CoreLib::System
