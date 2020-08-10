#pragma once

#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace DiscardableAttributeNamespace {
CLASS(DiscardableAttribute) : public Attribute::in {
  public: void ctor();
};
} // namespace DiscardableAttributeNamespace
using DiscardableAttribute = DiscardableAttributeNamespace::DiscardableAttribute;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
