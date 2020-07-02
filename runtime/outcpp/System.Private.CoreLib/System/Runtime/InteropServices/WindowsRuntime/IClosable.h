#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Runtime::InteropServices::WindowsRuntime {
namespace IClosableNamespace {
CLASS(IClosable) {
  public: void Close();
};
} // namespace IClosableNamespace
using IClosable = IClosableNamespace::IClosable;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices::WindowsRuntime
