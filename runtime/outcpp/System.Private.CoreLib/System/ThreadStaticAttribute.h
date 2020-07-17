#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
namespace ThreadStaticAttributeNamespace {
CLASS(ThreadStaticAttribute) {
  public: void Ctor();
};
} // namespace ThreadStaticAttributeNamespace
using ThreadStaticAttribute = ThreadStaticAttributeNamespace::ThreadStaticAttribute;
} // namespace System::Private::CoreLib::System
