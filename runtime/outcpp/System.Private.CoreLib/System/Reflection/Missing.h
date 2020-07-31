#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Reflection {
namespace MissingNamespace {
CLASS(Missing) : public Object::in {
  private: void Ctor();
  private: static void SCtor();
  public: static Missing Value;
};
} // namespace MissingNamespace
using Missing = MissingNamespace::Missing;
} // namespace System::Private::CoreLib::System::Reflection
