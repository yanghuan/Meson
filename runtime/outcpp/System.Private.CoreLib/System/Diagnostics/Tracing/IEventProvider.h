#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/Interop.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/EventProvider.h>

namespace System::Private::CoreLib::System {
FORWARDS(Byte)
FORWARDS(Guid)
FORWARDS(Int32)
FORWARDS(Int64)
FORWARDS(IntPtr)
FORWARD(String)
FORWARDS(UInt32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Diagnostics::Tracing {
FORWARD(EventSource)
FORWARDS(EventDescriptor)
namespace IEventProviderNamespace {
CLASS(IEventProvider) {
  public: UInt32 EventRegister(EventSource eventSource, Interop::Advapi32::in::EtwEnableCallback enableCallback, void* callbackContext, Int64& registrationHandle);
  public: UInt32 EventUnregister(Int64 registrationHandle);
  public: EventProvider::in::WriteEventErrorCode EventWriteTransfer(Int64 registrationHandle, EventDescriptor& eventDescriptor, IntPtr eventHandle, Guid* activityId, Guid* relatedActivityId, Int32 userDataCount, void/*EventProvider.EventData*/* userData);
  public: Int32 EventActivityIdControl(Interop::Advapi32::in::ActivityControl ControlCode, Guid& ActivityId);
  public: IntPtr DefineEventHandle(UInt32 eventID, String eventName, Int64 keywords, UInt32 eventVersion, UInt32 level, Byte* pMetadata, UInt32 metadataLength);
};
} // namespace IEventProviderNamespace
using IEventProvider = IEventProviderNamespace::IEventProvider;
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing
