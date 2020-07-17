#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
namespace ParamArrayAttributeNamespace {
CLASS(ParamArrayAttribute) {
  public: void Ctor();
};
} // namespace ParamArrayAttributeNamespace
using ParamArrayAttribute = ParamArrayAttributeNamespace::ParamArrayAttribute;
} // namespace System::Private::CoreLib::System
