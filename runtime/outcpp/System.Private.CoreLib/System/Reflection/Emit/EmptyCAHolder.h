#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Reflection {
FORWARD(ICustomAttributeProvider)
} // namespace System::Private::CoreLib::System::Reflection
namespace System::Private::CoreLib::System::Reflection::Emit {
namespace EmptyCAHolderNamespace {
CLASS(EmptyCAHolder) : public Object::in {
  public: using interface = rt::TypeList<ICustomAttributeProvider>;
  public: void ctor();
};
} // namespace EmptyCAHolderNamespace
using EmptyCAHolder = EmptyCAHolderNamespace::EmptyCAHolder;
} // namespace System::Private::CoreLib::System::Reflection::Emit
