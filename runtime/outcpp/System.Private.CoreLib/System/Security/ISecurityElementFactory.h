#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Security {
FORWARD(SecurityElement)
namespace ISecurityElementFactoryNamespace {
CLASS(ISecurityElementFactory) {
  public: SecurityElement CreateSecurityElement();
};
} // namespace ISecurityElementFactoryNamespace
using ISecurityElementFactory = ISecurityElementFactoryNamespace::ISecurityElementFactory;
} // namespace System::Private::CoreLib::System::Security
