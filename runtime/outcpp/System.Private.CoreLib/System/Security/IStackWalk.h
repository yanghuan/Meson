#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Security {
namespace IStackWalkNamespace {
CLASS(IStackWalk) : public object {
  public: void Assert();
  public: void Demand();
  public: void Deny();
  public: void PermitOnly();
  public: static constexpr rt::TypeCode code = rt::TypeCode::Interface;
};
} // namespace IStackWalkNamespace
using IStackWalk = IStackWalkNamespace::IStackWalk;
} // namespace System::Private::CoreLib::System::Security
