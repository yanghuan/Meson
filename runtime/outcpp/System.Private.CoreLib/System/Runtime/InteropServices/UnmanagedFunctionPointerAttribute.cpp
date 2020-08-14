#include "UnmanagedFunctionPointerAttribute-dep.h"

namespace System::Private::CoreLib::System::Runtime::InteropServices::UnmanagedFunctionPointerAttributeNamespace {
void UnmanagedFunctionPointerAttribute___::ctor() {
  CallingConvention = CallingConvention::Winapi;
}

void UnmanagedFunctionPointerAttribute___::ctor(InteropServices::CallingConvention callingConvention) {
  CallingConvention = callingConvention;
}

} // namespace System::Private::CoreLib::System::Runtime::InteropServices::UnmanagedFunctionPointerAttributeNamespace
