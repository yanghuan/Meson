#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System::Security {
namespace SuppressUnmanagedCodeSecurityAttributeNamespace {
CLASS(SuppressUnmanagedCodeSecurityAttribute) : public Attribute::in {
  public: void Ctor();
};
} // namespace SuppressUnmanagedCodeSecurityAttributeNamespace
using SuppressUnmanagedCodeSecurityAttribute = SuppressUnmanagedCodeSecurityAttributeNamespace::SuppressUnmanagedCodeSecurityAttribute;
} // namespace System::Private::CoreLib::System::Security
