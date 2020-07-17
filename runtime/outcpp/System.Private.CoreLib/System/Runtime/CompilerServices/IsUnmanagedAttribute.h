#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace IsUnmanagedAttributeNamespace {
CLASS(IsUnmanagedAttribute) {
  public: void Ctor();
};
} // namespace IsUnmanagedAttributeNamespace
using IsUnmanagedAttribute = IsUnmanagedAttributeNamespace::IsUnmanagedAttribute;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
