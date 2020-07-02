#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Security {
namespace IStackWalkNamespace {
CLASS(IStackWalk) {
  public: void Assert();
  public: void Demand();
  public: void Deny();
  public: void PermitOnly();
};
} // namespace IStackWalkNamespace
using IStackWalk = IStackWalkNamespace::IStackWalk;
} // namespace System::Private::CoreLib::System::Security
