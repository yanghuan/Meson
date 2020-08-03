#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Security {
FORWARD(SecurityElement)
namespace ISecurityEncodableNamespace {
CLASS(ISecurityEncodable) : public Object::in {
  public: void FromXml(SecurityElement e);
  public: SecurityElement ToXml();
};
} // namespace ISecurityEncodableNamespace
using ISecurityEncodable = ISecurityEncodableNamespace::ISecurityEncodable;
} // namespace System::Private::CoreLib::System::Security
