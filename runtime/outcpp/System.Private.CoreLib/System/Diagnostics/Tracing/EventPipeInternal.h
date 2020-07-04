#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/Interop.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/EventProvider.h>
#include <System.Private.CoreLib/System/UInt32.h>
#include <System.Private.CoreLib/System/UInt64.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
FORWARDS(Char)
FORWARDS(Guid)
FORWARDS(Int32)
FORWARDS(Int64)
FORWARDS(IntPtr)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Diagnostics::Tracing {
FORWARDS(EventPipeProviderConfiguration)
enum class EventPipeSerializationFormat;
FORWARDS(EventPipeSessionInfo)
FORWARDS(EventPipeEventInstanceData)
namespace EventPipeInternalNamespace {
class EventPipeInternal {
  private: struct EventPipeProviderConfigurationNative {
    public: static void MarshalToNative(EventPipeProviderConfiguration managed, EventPipeProviderConfigurationNative& native);
    public: void Release();
    private: Char* m_pProviderName;
    private: UInt64 m_keywords;
    private: UInt32 m_loggingLevel;
    private: Char* m_pFilterData;
  };
  private: static UInt64 Enable(Char* outputFile, EventPipeSerializationFormat format, UInt32 circularBufferSizeInMB, EventPipeProviderConfigurationNative* providers, UInt32 numProviders);
  public: static UInt64 Enable(String outputFile, EventPipeSerializationFormat format, UInt32 circularBufferSizeInMB, Array<EventPipeProviderConfiguration> providers);
  public: static void Disable(UInt64 sessionID);
  public: static IntPtr CreateProvider(String providerName, Interop::Advapi32::EtwEnableCallback callbackFunc);
  public: static IntPtr DefineEvent(IntPtr provHandle, UInt32 eventID, Int64 keywords, UInt32 eventVersion, UInt32 level, void* pMetadata, UInt32 metadataLength);
  public: static IntPtr GetProvider(String providerName);
  public: static void DeleteProvider(IntPtr provHandle);
  public: static Int32 EventActivityIdControl(UInt32 controlCode, Guid& activityId);
  public: static void WriteEvent(IntPtr eventHandle, UInt32 eventID, void* pData, UInt32 length, Guid* activityId, Guid* relatedActivityId);
  public: static void WriteEventData(IntPtr eventHandle, UInt32 eventID, EventProvider::in::EventData* pEventData, UInt32 dataCount, Guid* activityId, Guid* relatedActivityId);
  public: static Boolean GetSessionInfo(UInt64 sessionID, EventPipeSessionInfo* pSessionInfo);
  public: static Boolean GetNextEvent(UInt64 sessionID, EventPipeEventInstanceData* pInstance);
  public: static IntPtr GetWaitHandle(UInt64 sessionID);
};
} // namespace EventPipeInternalNamespace
using EventPipeInternal = EventPipeInternalNamespace::EventPipeInternal;
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing
