#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Security {
FORWARD(SecurityElement)
namespace ISecurityEncodableNamespace {
CLASS(ISecurityEncodable) {
  public: void FromXml(SecurityElement e);
  public: SecurityElement ToXml();
};
} // namespace ISecurityEncodableNamespace
using ISecurityEncodable = ISecurityEncodableNamespace::ISecurityEncodable;
} // namespace System::Private::CoreLib::System::Security
