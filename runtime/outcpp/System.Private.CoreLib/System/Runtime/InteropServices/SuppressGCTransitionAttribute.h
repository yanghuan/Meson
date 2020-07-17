#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Runtime::InteropServices {
namespace SuppressGCTransitionAttributeNamespace {
CLASS(SuppressGCTransitionAttribute) {
  public: void Ctor();
};
} // namespace SuppressGCTransitionAttributeNamespace
using SuppressGCTransitionAttribute = SuppressGCTransitionAttributeNamespace::SuppressGCTransitionAttribute;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
