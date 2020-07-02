#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(Object)
FORWARDS(Boolean)
namespace MarshalByRefObjectNamespace {
CLASS(MarshalByRefObject) {
  public: Object GetLifetimeService();
  public: Object InitializeLifetimeService();
  protected: MarshalByRefObject MemberwiseClone(Boolean cloneIdentity);
};
} // namespace MarshalByRefObjectNamespace
using MarshalByRefObject = MarshalByRefObjectNamespace::MarshalByRefObject;
} // namespace System::Private::CoreLib::System
