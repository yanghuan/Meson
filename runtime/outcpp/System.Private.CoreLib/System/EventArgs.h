#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
namespace EventArgsNamespace {
CLASS(EventArgs) : public object {
  public: void ctor();
  private: static void cctor();
  public: static EventArgs Empty;
};
} // namespace EventArgsNamespace
using EventArgs = EventArgsNamespace::EventArgs;
} // namespace System::Private::CoreLib::System
