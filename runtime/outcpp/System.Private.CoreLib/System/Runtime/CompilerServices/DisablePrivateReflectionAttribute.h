#pragma once

#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace DisablePrivateReflectionAttributeNamespace {
CLASS(DisablePrivateReflectionAttribute) : public Attribute::in {
  public: void ctor();
};
} // namespace DisablePrivateReflectionAttributeNamespace
using DisablePrivateReflectionAttribute = DisablePrivateReflectionAttributeNamespace::DisablePrivateReflectionAttribute;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
