#pragma once

#include <System.Private.CoreLib/System/Guid.h>
#include <System.Private.CoreLib/System/Int64.h>
#include <System.Private.CoreLib/System/IntPtr.h>
#include <System.Private.CoreLib/System/UInt32.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System::Diagnostics::Tracing {
namespace EventPipeEventInstanceDataNamespace {
struct EventPipeEventInstanceData : public valueType<EventPipeEventInstanceData> {
  public: IntPtr ProviderID;
  public: UInt32 EventID;
  public: UInt32 ThreadID;
  public: Int64 TimeStamp;
  public: Guid ActivityId;
  public: Guid ChildActivityId;
  public: IntPtr Payload;
  public: UInt32 PayloadLength;
};
} // namespace EventPipeEventInstanceDataNamespace
using EventPipeEventInstanceData = EventPipeEventInstanceDataNamespace::EventPipeEventInstanceData;
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing
