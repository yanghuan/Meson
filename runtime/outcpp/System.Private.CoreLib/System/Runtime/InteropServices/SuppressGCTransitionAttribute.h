#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System::Runtime::InteropServices {
namespace SuppressGCTransitionAttributeNamespace {
CLASS(SuppressGCTransitionAttribute) : public Attribute::in {
  public: void Ctor();
};
} // namespace SuppressGCTransitionAttributeNamespace
using SuppressGCTransitionAttribute = SuppressGCTransitionAttributeNamespace::SuppressGCTransitionAttribute;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
