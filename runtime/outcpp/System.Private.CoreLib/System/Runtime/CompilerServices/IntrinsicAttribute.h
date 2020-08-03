#pragma once

#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace IntrinsicAttributeNamespace {
CLASS(IntrinsicAttribute) : public Attribute::in {
  public: void Ctor();
};
} // namespace IntrinsicAttributeNamespace
using IntrinsicAttribute = IntrinsicAttributeNamespace::IntrinsicAttribute;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
