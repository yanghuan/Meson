#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace DisablePrivateReflectionAttributeNamespace {
CLASS(DisablePrivateReflectionAttribute) {
  public: void Ctor();
};
} // namespace DisablePrivateReflectionAttributeNamespace
using DisablePrivateReflectionAttribute = DisablePrivateReflectionAttributeNamespace::DisablePrivateReflectionAttribute;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
