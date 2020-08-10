#pragma once

#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace ExtensionAttributeNamespace {
CLASS(ExtensionAttribute) : public Attribute::in {
  public: void ctor();
};
} // namespace ExtensionAttributeNamespace
using ExtensionAttribute = ExtensionAttributeNamespace::ExtensionAttribute;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
