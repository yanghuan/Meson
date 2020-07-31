#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System::Runtime::InteropServices {
namespace InAttributeNamespace {
CLASS(InAttribute) : public Attribute::in {
  public: void Ctor();
};
} // namespace InAttributeNamespace
using InAttribute = InAttributeNamespace::InAttribute;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
