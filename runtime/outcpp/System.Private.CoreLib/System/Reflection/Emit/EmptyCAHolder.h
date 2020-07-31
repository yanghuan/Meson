#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Reflection::Emit {
namespace EmptyCAHolderNamespace {
CLASS(EmptyCAHolder) : public Object::in {
  public: void Ctor();
};
} // namespace EmptyCAHolderNamespace
using EmptyCAHolder = EmptyCAHolderNamespace::EmptyCAHolder;
} // namespace System::Private::CoreLib::System::Reflection::Emit
