#pragma once

#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace IsUnmanagedAttributeNamespace {
CLASS(IsUnmanagedAttribute) : public Attribute::in {
  public: void ctor();
};
} // namespace IsUnmanagedAttributeNamespace
using IsUnmanagedAttribute = IsUnmanagedAttributeNamespace::IsUnmanagedAttribute;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
