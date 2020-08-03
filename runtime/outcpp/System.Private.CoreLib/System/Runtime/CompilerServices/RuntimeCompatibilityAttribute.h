#pragma once

#include <System.Private.CoreLib/System/Attribute.h>
#include <System.Private.CoreLib/System/Boolean.h>

namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace RuntimeCompatibilityAttributeNamespace {
CLASS(RuntimeCompatibilityAttribute) : public Attribute::in {
  public: Boolean get_WrapNonExceptionThrows() { return WrapNonExceptionThrows; }
  public: void set_WrapNonExceptionThrows(Boolean value) { WrapNonExceptionThrows = value; }
  public: void Ctor();
  private: Boolean WrapNonExceptionThrows;
};
} // namespace RuntimeCompatibilityAttributeNamespace
using RuntimeCompatibilityAttribute = RuntimeCompatibilityAttributeNamespace::RuntimeCompatibilityAttribute;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
