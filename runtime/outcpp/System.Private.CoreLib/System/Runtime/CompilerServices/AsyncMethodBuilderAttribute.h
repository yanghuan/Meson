#pragma once

#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System {
FORWARD(Type)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace AsyncMethodBuilderAttributeNamespace {
CLASS(AsyncMethodBuilderAttribute) : public Attribute::in {
  public: Type get_BuilderType() { return BuilderType; }
  public: void Ctor(Type builderType);
  private: Type BuilderType;
};
} // namespace AsyncMethodBuilderAttributeNamespace
using AsyncMethodBuilderAttribute = AsyncMethodBuilderAttributeNamespace::AsyncMethodBuilderAttribute;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
