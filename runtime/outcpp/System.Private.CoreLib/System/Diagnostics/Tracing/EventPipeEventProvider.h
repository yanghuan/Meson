#pragma once

#include <System.Private.CoreLib/Interop.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/EventProvider.h>
#include <System.Private.CoreLib/System/IntPtr.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARDS(Byte)
FORWARDS(Guid)
FORWARDS(Int32)
FORWARDS(Int64)
FORWARD(String)
FORWARDS(UInt32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Diagnostics::Tracing {
FORWARDS(EventDescriptor)
FORWARD(EventSource)
FORWARD(IEventProvider)
namespace EventPipeEventProviderNamespace {
CLASS(EventPipeEventProvider) : public object {
  public: using interface = rt::TypeList<IEventProvider>;
  private: UInt32 EventRegisterOfIEventProvider(EventSource eventSource, Interop::Advapi32::EtwEnableCallback enableCallback, void* callbackContext, Int64& registrationHandle);
  private: UInt32 EventUnregisterOfIEventProvider(Int64 registrationHandle);
  private: EventProvider::in::WriteEventErrorCode EventWriteTransferOfIEventProvider(Int64 registrationHandle, EventDescriptor& eventDescriptor, IntPtr eventHandle, Guid* activityId, Guid* relatedActivityId, Int32 userDataCount, EventProvider::in::EventData* userData);
  private: Int32 EventActivityIdControlOfIEventProvider(Interop::Advapi32::ActivityControl ControlCode, Guid& ActivityId);
  private: IntPtr DefineEventHandleOfIEventProvider(UInt32 eventID, String eventName, Int64 keywords, UInt32 eventVersion, UInt32 level, Byte* pMetadata, UInt32 metadataLength);
  public: void ctor();
  private: IntPtr m_provHandle;
};
} // namespace EventPipeEventProviderNamespace
using EventPipeEventProvider = EventPipeEventProviderNamespace::EventPipeEventProvider;
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing
