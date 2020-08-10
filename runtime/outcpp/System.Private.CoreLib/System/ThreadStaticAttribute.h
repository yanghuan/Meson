#pragma once

#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System {
namespace ThreadStaticAttributeNamespace {
CLASS(ThreadStaticAttribute) : public Attribute::in {
  public: void ctor();
};
} // namespace ThreadStaticAttributeNamespace
using ThreadStaticAttribute = ThreadStaticAttributeNamespace::ThreadStaticAttribute;
} // namespace System::Private::CoreLib::System
