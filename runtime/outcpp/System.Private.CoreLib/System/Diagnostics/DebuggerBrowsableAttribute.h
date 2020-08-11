#pragma once

#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System::Diagnostics {
enum class DebuggerBrowsableState : int32_t;
namespace DebuggerBrowsableAttributeNamespace {
CLASS(DebuggerBrowsableAttribute) : public Attribute::in {
  public: DebuggerBrowsableState get_State() { return State; }
  public: void ctor(DebuggerBrowsableState state);
  private: DebuggerBrowsableState State;
};
} // namespace DebuggerBrowsableAttributeNamespace
using DebuggerBrowsableAttribute = DebuggerBrowsableAttributeNamespace::DebuggerBrowsableAttribute;
} // namespace System::Private::CoreLib::System::Diagnostics
