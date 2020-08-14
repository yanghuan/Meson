#include "MethodImplAttribute-dep.h"

namespace System::Private::CoreLib::System::Runtime::CompilerServices::MethodImplAttributeNamespace {
void MethodImplAttribute___::ctor(MethodImplOptions methodImplOptions) {
  Value = methodImplOptions;
}

void MethodImplAttribute___::ctor(Int16 value) {
  Value = (MethodImplOptions)value;
}

void MethodImplAttribute___::ctor() {
}

} // namespace System::Private::CoreLib::System::Runtime::CompilerServices::MethodImplAttributeNamespace
