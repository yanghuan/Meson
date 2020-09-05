#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::Microsoft::Win32::SafeHandles {
FORWARD(SafeFileHandle)
} // namespace System::Private::CoreLib::Microsoft::Win32::SafeHandles
namespace System::Private::CoreLib::Internal {
namespace ConsoleNamespace {
using namespace Microsoft::Win32::SafeHandles;
using namespace System;
class Console {
  public: static void Write(String s);
  public: static void WriteLine(String s);
  public: static void WriteLine();
  public: static void cctor();
  private: static SafeFileHandle _outputHandle;
};
} // namespace ConsoleNamespace
using Console = ConsoleNamespace::Console;
} // namespace System::Private::CoreLib::Internal
