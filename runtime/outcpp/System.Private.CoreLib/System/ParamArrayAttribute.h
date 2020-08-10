#pragma once

#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System {
namespace ParamArrayAttributeNamespace {
CLASS(ParamArrayAttribute) : public Attribute::in {
  public: void ctor();
};
} // namespace ParamArrayAttributeNamespace
using ParamArrayAttribute = ParamArrayAttributeNamespace::ParamArrayAttribute;
} // namespace System::Private::CoreLib::System
