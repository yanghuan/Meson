#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Boolean.h>

namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace RuntimeCompatibilityAttributeNamespace {
CLASS(RuntimeCompatibilityAttribute) {
  private: Boolean WrapNonExceptionThrows;
};
} // namespace RuntimeCompatibilityAttributeNamespace
using RuntimeCompatibilityAttribute = RuntimeCompatibilityAttributeNamespace::RuntimeCompatibilityAttribute;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
