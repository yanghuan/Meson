#pragma once

namespace System::Private::CoreLib::System::Runtime::InteropServices::WindowsRuntime {
enum class InterfaceForwardingSupport {
  None = 0,
  IBindableVector = 1,
  IVector = 2,
  IBindableVectorView = 4,
  IVectorView = 8,
  IBindableIterableOrIIterable = 16,
};
} // namespace System::Private::CoreLib::System::Runtime::InteropServices::WindowsRuntime
