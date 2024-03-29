#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::Internal::Win32 {
FORWARD(RegistryKey)
namespace RegistryNamespace {
class Registry {
  public: static void cctor();
  public: static RegistryKey CurrentUser;
  public: static RegistryKey LocalMachine;
};
} // namespace RegistryNamespace
using Registry = RegistryNamespace::Registry;
} // namespace System::Private::CoreLib::Internal::Win32
