#pragma once

#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System::Diagnostics {
namespace DebuggerNonUserCodeAttributeNamespace {
CLASS(DebuggerNonUserCodeAttribute) : public Attribute::in {
  public: void ctor();
};
} // namespace DebuggerNonUserCodeAttributeNamespace
using DebuggerNonUserCodeAttribute = DebuggerNonUserCodeAttributeNamespace::DebuggerNonUserCodeAttribute;
} // namespace System::Private::CoreLib::System::Diagnostics
