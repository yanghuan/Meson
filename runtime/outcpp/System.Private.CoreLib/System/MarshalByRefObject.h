#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
namespace MarshalByRefObjectNamespace {
CLASS(MarshalByRefObject) : public Object::in {
  protected: void Ctor();
  public: Object GetLifetimeService();
  public: Object InitializeLifetimeService();
  protected: MarshalByRefObject MemberwiseClone(Boolean cloneIdentity);
};
} // namespace MarshalByRefObjectNamespace
using MarshalByRefObject = MarshalByRefObjectNamespace::MarshalByRefObject;
} // namespace System::Private::CoreLib::System
