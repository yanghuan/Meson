#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(Type)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace AsyncMethodBuilderAttributeNamespace {
CLASS(AsyncMethodBuilderAttribute) {
  private: Type BuilderType;
};
} // namespace AsyncMethodBuilderAttributeNamespace
using AsyncMethodBuilderAttribute = AsyncMethodBuilderAttributeNamespace::AsyncMethodBuilderAttribute;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
