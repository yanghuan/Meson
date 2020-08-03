#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Security {
namespace IStackWalkNamespace {
CLASS(IStackWalk) : public Object::in {
  public: void Assert();
  public: void Demand();
  public: void Deny();
  public: void PermitOnly();
};
} // namespace IStackWalkNamespace
using IStackWalk = IStackWalkNamespace::IStackWalk;
} // namespace System::Private::CoreLib::System::Security
