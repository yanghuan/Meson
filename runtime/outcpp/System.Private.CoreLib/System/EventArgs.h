#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
namespace EventArgsNamespace {
CLASS(EventArgs) : public Object::in {
  public: void Ctor();
  private: static void SCtor();
  public: static EventArgs Empty;
};
} // namespace EventArgsNamespace
using EventArgs = EventArgsNamespace::EventArgs;
} // namespace System::Private::CoreLib::System
