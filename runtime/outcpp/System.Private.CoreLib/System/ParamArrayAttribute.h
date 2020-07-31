#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System {
namespace ParamArrayAttributeNamespace {
CLASS(ParamArrayAttribute) : public Attribute::in {
  public: void Ctor();
};
} // namespace ParamArrayAttributeNamespace
using ParamArrayAttribute = ParamArrayAttributeNamespace::ParamArrayAttribute;
} // namespace System::Private::CoreLib::System
