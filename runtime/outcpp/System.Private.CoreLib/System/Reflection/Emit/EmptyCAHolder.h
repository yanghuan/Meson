#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Reflection {
FORWARD(ICustomAttributeProvider)
} // namespace System::Private::CoreLib::System::Reflection
namespace System::Private::CoreLib::System {
FORWARD_(Array)
FORWARDS(Boolean)
FORWARD(Type)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection::Emit {
namespace EmptyCAHolderNamespace {
CLASS(EmptyCAHolder) : public object {
  public: using interface = rt::TypeList<ICustomAttributeProvider>;
  public: void ctor();
  private: Array<Object> GetCustomAttributesOfICustomAttributeProvider(Type attributeType, Boolean inherit);
  private: Array<Object> GetCustomAttributesOfICustomAttributeProvider(Boolean inherit);
  private: Boolean IsDefinedOfICustomAttributeProvider(Type attributeType, Boolean inherit);
};
} // namespace EmptyCAHolderNamespace
using EmptyCAHolder = EmptyCAHolderNamespace::EmptyCAHolder;
} // namespace System::Private::CoreLib::System::Reflection::Emit
