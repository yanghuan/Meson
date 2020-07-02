#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Security {
namespace IPermissionNamespace {
CLASS(IPermission) {
  public: IPermission Copy();
  public: void Demand();
  public: IPermission Intersect(IPermission target);
  public: Boolean IsSubsetOf(IPermission target);
  public: IPermission Union(IPermission target);
};
} // namespace IPermissionNamespace
using IPermission = IPermissionNamespace::IPermission;
} // namespace System::Private::CoreLib::System::Security
