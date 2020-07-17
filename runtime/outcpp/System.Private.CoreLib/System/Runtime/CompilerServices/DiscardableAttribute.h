#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace DiscardableAttributeNamespace {
CLASS(DiscardableAttribute) {
  public: void Ctor();
};
} // namespace DiscardableAttributeNamespace
using DiscardableAttribute = DiscardableAttributeNamespace::DiscardableAttribute;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
