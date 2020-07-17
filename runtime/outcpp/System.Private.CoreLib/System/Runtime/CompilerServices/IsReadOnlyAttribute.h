#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace IsReadOnlyAttributeNamespace {
CLASS(IsReadOnlyAttribute) {
  public: void Ctor();
};
} // namespace IsReadOnlyAttributeNamespace
using IsReadOnlyAttribute = IsReadOnlyAttributeNamespace::IsReadOnlyAttribute;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
