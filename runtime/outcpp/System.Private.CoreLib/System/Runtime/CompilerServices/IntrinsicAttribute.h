#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace IntrinsicAttributeNamespace {
CLASS(IntrinsicAttribute) {
  public: void Ctor();
};
} // namespace IntrinsicAttributeNamespace
using IntrinsicAttribute = IntrinsicAttributeNamespace::IntrinsicAttribute;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
