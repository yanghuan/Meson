#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/Byte.h>
#include <System.Private.CoreLib/System/Int32.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Diagnostics::Tracing {
enum class EventOpcode;
enum class EventLevel;
enum class EventKeywords : int64_t;
enum class EventTask;
enum class EventChannel : uint8_t;
enum class EventTags;
enum class EventActivityOptions;
namespace EventAttributeNamespace {
CLASS(EventAttribute) {
  public: EventOpcode get_Opcode();
  public: void set_Opcode(EventOpcode value);
  public: Boolean get_IsOpcodeSet();
  private: Int32 EventId;
  private: EventLevel Level;
  private: EventKeywords Keywords;
  private: EventTask Task;
  private: EventChannel Channel;
  private: Byte Version;
  private: String Message;
  private: EventTags Tags;
  private: EventActivityOptions ActivityOptions;
  private: EventOpcode m_opcode;
  private: Boolean m_opcodeSet;
};
} // namespace EventAttributeNamespace
using EventAttribute = EventAttributeNamespace::EventAttribute;
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing
