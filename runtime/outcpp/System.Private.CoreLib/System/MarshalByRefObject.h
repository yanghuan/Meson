#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
namespace MarshalByRefObjectNamespace {
CLASS(MarshalByRefObject) : public object {
  protected: void ctor();
  public: Object GetLifetimeService();
  public: Object InitializeLifetimeService();
  protected: MarshalByRefObject MemberwiseClone(Boolean cloneIdentity);
};
} // namespace MarshalByRefObjectNamespace
using MarshalByRefObject = MarshalByRefObjectNamespace::MarshalByRefObject;
} // namespace System::Private::CoreLib::System
