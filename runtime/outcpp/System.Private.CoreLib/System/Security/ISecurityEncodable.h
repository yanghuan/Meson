#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Security {
FORWARD(SecurityElement)
namespace ISecurityEncodableNamespace {
CLASS(ISecurityEncodable) : public object {
  public: void FromXml(SecurityElement e);
  public: SecurityElement ToXml();
  public: static constexpr rt::TypeCode code = rt::TypeCode::Interface;
};
} // namespace ISecurityEncodableNamespace
using ISecurityEncodable = ISecurityEncodableNamespace::ISecurityEncodable;
} // namespace System::Private::CoreLib::System::Security
