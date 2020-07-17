#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
namespace ContextStaticAttributeNamespace {
CLASS(ContextStaticAttribute) {
  public: void Ctor();
};
} // namespace ContextStaticAttributeNamespace
using ContextStaticAttribute = ContextStaticAttributeNamespace::ContextStaticAttribute;
} // namespace System::Private::CoreLib::System
