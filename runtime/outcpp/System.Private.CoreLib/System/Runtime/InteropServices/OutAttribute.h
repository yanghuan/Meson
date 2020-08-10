#pragma once

#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System::Runtime::InteropServices {
namespace OutAttributeNamespace {
CLASS(OutAttribute) : public Attribute::in {
  public: void ctor();
};
} // namespace OutAttributeNamespace
using OutAttribute = OutAttributeNamespace::OutAttribute;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
