#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Security {
FORWARD(ISecurityEncodable)
FORWARD(SecurityElement)
namespace IPermissionNamespace {
CLASS(IPermission) : public object {
  public: using interface = rt::TypeList<ISecurityEncodable>;
  public: void FromXml(SecurityElement e);
  public: SecurityElement ToXml();
  public: IPermission Copy();
  public: void Demand();
  public: IPermission Intersect(IPermission target);
  public: Boolean IsSubsetOf(IPermission target);
  public: IPermission Union(IPermission target);
  public: static constexpr rt::TypeCode code = rt::TypeCode::Interface;
};
} // namespace IPermissionNamespace
using IPermission = IPermissionNamespace::IPermission;
} // namespace System::Private::CoreLib::System::Security
