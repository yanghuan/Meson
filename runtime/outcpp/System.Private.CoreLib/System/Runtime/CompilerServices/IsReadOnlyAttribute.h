#pragma once

#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace IsReadOnlyAttributeNamespace {
CLASS(IsReadOnlyAttribute) : public Attribute::in {
  public: void Ctor();
};
} // namespace IsReadOnlyAttributeNamespace
using IsReadOnlyAttribute = IsReadOnlyAttributeNamespace::IsReadOnlyAttribute;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
