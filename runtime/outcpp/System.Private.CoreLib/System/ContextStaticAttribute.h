#pragma once

#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System {
namespace ContextStaticAttributeNamespace {
CLASS(ContextStaticAttribute) : public Attribute::in {
  public: void ctor();
};
} // namespace ContextStaticAttributeNamespace
using ContextStaticAttribute = ContextStaticAttributeNamespace::ContextStaticAttribute;
} // namespace System::Private::CoreLib::System
