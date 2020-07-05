#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARD(Object)
namespace MarshalByRefObjectNamespace {
CLASS(MarshalByRefObject) {
  public: Object GetLifetimeService();
  public: Object InitializeLifetimeService();
  protected: MarshalByRefObject MemberwiseClone(Boolean cloneIdentity);
};
} // namespace MarshalByRefObjectNamespace
using MarshalByRefObject = MarshalByRefObjectNamespace::MarshalByRefObject;
} // namespace System::Private::CoreLib::System
