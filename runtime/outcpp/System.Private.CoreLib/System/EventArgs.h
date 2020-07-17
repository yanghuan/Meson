#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
namespace EventArgsNamespace {
CLASS(EventArgs) {
  public: void Ctor();
  private: static void SCtor();
  public: static EventArgs Empty;
};
} // namespace EventArgsNamespace
using EventArgs = EventArgsNamespace::EventArgs;
} // namespace System::Private::CoreLib::System
