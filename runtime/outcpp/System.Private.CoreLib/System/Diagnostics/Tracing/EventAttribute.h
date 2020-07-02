#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Boolean.h>

namespace System::Private::CoreLib::System::Diagnostics::Tracing {
enum class EventOpcode;
namespace EventAttributeNamespace {
CLASS(EventAttribute) {
  public: EventOpcode get_Opcode();
  public: void set_Opcode(EventOpcode value);
  public: Boolean get_IsOpcodeSet();
  private: EventOpcode m_opcode;
  private: Boolean m_opcodeSet;
};
} // namespace EventAttributeNamespace
using EventAttribute = EventAttributeNamespace::EventAttribute;
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing
