#pragma once

#include <System.Private.CoreLib/System/Byte.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Int64.h>
#include <System.Private.CoreLib/System/UInt16.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Diagnostics::Tracing {
namespace EventDescriptorNamespace {
struct EventDescriptor : public valueType<EventDescriptor> {
  public: Int32 get_EventId();
  public: Byte get_Version();
  public: Byte get_Channel();
  public: Byte get_Level();
  public: Byte get_Opcode();
  public: Int32 get_Task();
  public: Int64 get_Keywords();
  public: explicit EventDescriptor(Int32 traceloggingId, Byte level, Byte opcode, Int64 keywords);
  public: explicit EventDescriptor(Int32 id, Byte version, Byte channel, Byte level, Byte opcode, Int32 task, Int64 keywords);
  public: Boolean Equals(Object obj);
  public: Int32 GetHashCode();
  public: Boolean Equals(EventDescriptor other);
  public: explicit EventDescriptor() {}
  private: Int32 m_traceloggingId;
  private: UInt16 m_id;
  private: Byte m_version;
  private: Byte m_channel;
  private: Byte m_level;
  private: Byte m_opcode;
  private: UInt16 m_task;
  private: Int64 m_keywords;
};
} // namespace EventDescriptorNamespace
using EventDescriptor = EventDescriptorNamespace::EventDescriptor;
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing
