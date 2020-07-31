#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace IsUnmanagedAttributeNamespace {
CLASS(IsUnmanagedAttribute) : public Attribute::in {
  public: void Ctor();
};
} // namespace IsUnmanagedAttributeNamespace
using IsUnmanagedAttribute = IsUnmanagedAttributeNamespace::IsUnmanagedAttribute;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
