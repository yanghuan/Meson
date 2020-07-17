#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Security {
namespace SuppressUnmanagedCodeSecurityAttributeNamespace {
CLASS(SuppressUnmanagedCodeSecurityAttribute) {
  public: void Ctor();
};
} // namespace SuppressUnmanagedCodeSecurityAttributeNamespace
using SuppressUnmanagedCodeSecurityAttribute = SuppressUnmanagedCodeSecurityAttributeNamespace::SuppressUnmanagedCodeSecurityAttribute;
} // namespace System::Private::CoreLib::System::Security
