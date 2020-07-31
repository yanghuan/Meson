#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System::Diagnostics {
namespace StackTraceHiddenAttributeNamespace {
CLASS(StackTraceHiddenAttribute) : public Attribute::in {
  public: void Ctor();
};
} // namespace StackTraceHiddenAttributeNamespace
using StackTraceHiddenAttribute = StackTraceHiddenAttributeNamespace::StackTraceHiddenAttribute;
} // namespace System::Private::CoreLib::System::Diagnostics
