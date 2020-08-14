#include "MarshalAsAttribute-dep.h"

namespace System::Private::CoreLib::System::Runtime::InteropServices::MarshalAsAttributeNamespace {
void MarshalAsAttribute___::ctor(UnmanagedType unmanagedType) {
  Value = unmanagedType;
}

void MarshalAsAttribute___::ctor(Int16 unmanagedType) {
  Value = (UnmanagedType)unmanagedType;
}

} // namespace System::Private::CoreLib::System::Runtime::InteropServices::MarshalAsAttributeNamespace
