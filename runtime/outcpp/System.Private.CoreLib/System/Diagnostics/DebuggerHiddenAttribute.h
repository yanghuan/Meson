#pragma once

#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System::Diagnostics {
namespace DebuggerHiddenAttributeNamespace {
CLASS(DebuggerHiddenAttribute) : public Attribute::in {
  public: void Ctor();
};
} // namespace DebuggerHiddenAttributeNamespace
using DebuggerHiddenAttribute = DebuggerHiddenAttributeNamespace::DebuggerHiddenAttribute;
} // namespace System::Private::CoreLib::System::Diagnostics
