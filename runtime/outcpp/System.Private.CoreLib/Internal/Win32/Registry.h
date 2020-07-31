#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::Internal::Win32 {
FORWARD(RegistryKey)
namespace RegistryNamespace {
using namespace ::System::Private::CoreLib::System;
class Registry : public Object::in {
  private: static void SCtor();
  public: static RegistryKey CurrentUser;
  public: static RegistryKey LocalMachine;
};
} // namespace RegistryNamespace
using Registry = RegistryNamespace::Registry;
} // namespace System::Private::CoreLib::Internal::Win32
