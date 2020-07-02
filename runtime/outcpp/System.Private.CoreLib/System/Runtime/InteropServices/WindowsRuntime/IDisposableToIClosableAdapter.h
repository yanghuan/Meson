#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Runtime::InteropServices::WindowsRuntime {
namespace IDisposableToIClosableAdapterNamespace {
CLASS(IDisposableToIClosableAdapter) {
  public: void Close();
};
} // namespace IDisposableToIClosableAdapterNamespace
using IDisposableToIClosableAdapter = IDisposableToIClosableAdapterNamespace::IDisposableToIClosableAdapter;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices::WindowsRuntime
