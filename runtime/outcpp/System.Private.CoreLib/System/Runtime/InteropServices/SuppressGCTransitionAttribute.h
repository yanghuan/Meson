#pragma once

#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System::Runtime::InteropServices {
namespace SuppressGCTransitionAttributeNamespace {
CLASS(SuppressGCTransitionAttribute) : public Attribute::in {
  public: void ctor();
};
} // namespace SuppressGCTransitionAttributeNamespace
using SuppressGCTransitionAttribute = SuppressGCTransitionAttributeNamespace::SuppressGCTransitionAttribute;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
