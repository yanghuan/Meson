#pragma once

#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System::Runtime::InteropServices {
namespace OptionalAttributeNamespace {
CLASS(OptionalAttribute) : public Attribute::in {
  public: void Ctor();
};
} // namespace OptionalAttributeNamespace
using OptionalAttribute = OptionalAttributeNamespace::OptionalAttribute;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
