#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Runtime::InteropServices::WindowsRuntime {
namespace IClosableToIDisposableAdapterNamespace {
CLASS(IClosableToIDisposableAdapter) {
  private: void Dispose();
};
} // namespace IClosableToIDisposableAdapterNamespace
using IClosableToIDisposableAdapter = IClosableToIDisposableAdapterNamespace::IClosableToIDisposableAdapter;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices::WindowsRuntime
