#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/Interop.h>
#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/Byte.h>
#include <System.Private.CoreLib/System/Guid.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Int64.h>
#include <System.Private.CoreLib/System/UInt32.h>
#include <System.Private.CoreLib/System/UInt64.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARD(AsyncCallback)
FORWARD(IAsyncResult)
FORWARDS(IntPtr)
FORWARD(Object)
FORWARD(String)
FORWARD_(Tuple, T1, T2, T3, T4, T5, T6, T7, T8, T9)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(IDictionary, TKey, TValue)
FORWARD(List, T)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System::Diagnostics::Tracing {
enum class ControllerCommand;
enum class EventKeywords : int64_t;
enum class EventLevel;
enum class EventProviderType;
FORWARDS(EventDescriptor)
FORWARD(EventSource)
FORWARD(IEventProvider)
namespace EventProviderNamespace {
using namespace Collections::Generic;
CLASS(EventProvider) {
  public: enum class WriteEventErrorCode {
    NoError = 0,
    NoFreeBuffers = 1,
    EventTooBig = 2,
    NullInput = 3,
    TooManyArgs = 4,
    Other = 5,
  };
  public: struct SessionInfo {
    public: explicit SessionInfo(Int32 sessionIdBit_, Int32 etwSessionId_);
    public: explicit SessionInfo() {}
    public: Int32 sessionIdBit;
    public: Int32 etwSessionId;
  };
  private: CLASS(SessionInfoCallback) {
    public: void Ctor(Object object, IntPtr method);
    public: void Invoke(Int32 etwSessionId, Int64 matchAllKeywords, List<SessionInfo>& sessionList);
    public: IAsyncResult BeginInvoke(Int32 etwSessionId, Int64 matchAllKeywords, List<SessionInfo>& sessionList, AsyncCallback callback, Object object);
    public: void EndInvoke(List<SessionInfo>& sessionList, IAsyncResult result);
  };
  public: struct EventData {
    public: UInt64 Ptr;
    public: UInt32 Size;
    public: UInt32 Reserved;
  };
  protected: EventLevel get_Level();
  protected: EventKeywords get_MatchAnyKeyword();
  public: void Ctor(EventProviderType providerType);
  public: void Register(EventSource eventSource);
  public: void Dispose();
  protected: void Dispose(Boolean disposing);
  protected: void Finalize();
  private: void EtwEnableCallBack(Guid& sourceId, Int32 controlCode, Byte setLevel, Int64 anyKeyword, Int64 allKeyword, Interop::Advapi32::EVENT_FILTER_DESCRIPTOR* filterData, void* callbackContext);
  protected: void OnControllerCommand(ControllerCommand command, IDictionary<String, String> arguments, Int32 sessionId, Int32 etwSessionId);
  private: static Int32 FindNull(Array<Byte> buffer, Int32 idx);
  private: List<Tuple<SessionInfo, Boolean>> GetSessions();
  private: static void GetSessionInfoCallback(Int32 etwSessionId, Int64 matchAllKeywords, List<SessionInfo>& sessionList);
  private: void GetSessionInfo(SessionInfoCallback action, List<SessionInfo>& sessionList);
  private: static Int32 IndexOfSessionInList(List<SessionInfo> sessions, Int32 etwSessionId);
  private: Boolean GetDataFromController(Int32 etwSessionId, Interop::Advapi32::EVENT_FILTER_DESCRIPTOR* filterData, ControllerCommand& command, Array<Byte>& data, Int32& dataStart);
  public: Boolean IsEnabled();
  public: Boolean IsEnabled(Byte level, Int64 keywords);
  public: static WriteEventErrorCode GetLastWriteEventError();
  private: static void SetLastError(WriteEventErrorCode error);
  private: static Object EncodeObject(Object& data, EventData*& dataDescriptor, Byte*& dataBuffer, UInt32& totalEventSize);
  public: Boolean WriteEvent(EventDescriptor& eventDescriptor, IntPtr eventHandle, Guid* activityID, Guid* childActivityID, Array<Object> eventPayload);
  public: Boolean WriteEvent(EventDescriptor& eventDescriptor, IntPtr eventHandle, Guid* activityID, Guid* childActivityID, Int32 dataCount, IntPtr data);
  public: Boolean WriteEventRaw(EventDescriptor& eventDescriptor, IntPtr eventHandle, Guid* activityID, Guid* relatedActivityID, Int32 dataCount, IntPtr data);
  private: UInt32 EventRegister(EventSource eventSource, Interop::Advapi32::EtwEnableCallback enableCallback);
  private: void EventUnregister(Int64 registrationHandle);
  public: Int32 SetInformation(Interop::Advapi32::EVENT_INFO_CLASS eventInfoClass, IntPtr data, UInt32 dataSize);
  public: IEventProvider m_eventProvider;
  private: Interop::Advapi32::EtwEnableCallback m_etwCallback;
  private: Int64 m_regHandle;
  private: Byte m_level;
  private: Int64 m_anyKeywordMask;
  private: Int64 m_allKeywordMask;
  private: List<SessionInfo> m_liveSessions;
  private: Boolean m_enabled;
  private: String m_providerName;
  private: Guid m_providerId;
  public: Boolean m_disposed;
  private: static WriteEventErrorCode s_returnCode;
  private: static Boolean m_setInformationMissing;
};
} // namespace EventProviderNamespace
using EventProvider = EventProviderNamespace::EventProvider;
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing
