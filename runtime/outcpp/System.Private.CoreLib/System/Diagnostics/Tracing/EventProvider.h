#pragma once

#include <System.Private.CoreLib/Interop.h>
#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/Byte.h>
#include <System.Private.CoreLib/System/Guid.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Int64.h>
#include <System.Private.CoreLib/System/MulticastDelegate.h>
#include <System.Private.CoreLib/System/Object.h>
#include <System.Private.CoreLib/System/UInt32.h>
#include <System.Private.CoreLib/System/UInt64.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array)
FORWARD(AsyncCallback)
FORWARD(IAsyncResult)
FORWARD(IDisposable)
FORWARDS(IntPtr)
FORWARD(String)
FORWARD_(Tuple)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(IDictionary, TKey, TValue)
FORWARD(List, T)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System::Diagnostics::Tracing {
enum class ControllerCommand : int32_t;
enum class EventKeywords : int64_t;
enum class EventLevel : int32_t;
enum class EventProviderType : int32_t;
FORWARDS(EventDescriptor)
FORWARD(EventSource)
FORWARD(IEventProvider)
namespace EventProviderNamespace {
using namespace System::Collections::Generic;
CLASS(EventProvider) : public object {
  public: using interface = rt::TypeList<IDisposable>;
  public: enum class WriteEventErrorCode : int32_t {
    NoError = 0,
    NoFreeBuffers = 1,
    EventTooBig = 2,
    NullInput = 3,
    TooManyArgs = 4,
    Other = 5,
  };
  public: struct SessionInfo : public valueType<SessionInfo> {
    public: explicit SessionInfo(Int32 sessionIdBit_, Int32 etwSessionId_);
    public: explicit SessionInfo() {}
    public: Int32 sessionIdBit;
    public: Int32 etwSessionId;
  };
  private: CLASS(SessionInfoCallback) : public MulticastDelegate::in {
    public: void ctor(Object object, IntPtr method);
    public: void Invoke(Int32 etwSessionId, Int64 matchAllKeywords, List<SessionInfo>& sessionList);
    public: IAsyncResult BeginInvoke(Int32 etwSessionId, Int64 matchAllKeywords, List<SessionInfo>& sessionList, AsyncCallback callback, Object object);
    public: void EndInvoke(List<SessionInfo>& sessionList, IAsyncResult result);
    public: static constexpr rt::TypeCode code = rt::TypeCode::Delegate;
  };
  public: struct EventData : public valueType<EventData> {
    public: UInt64 Ptr;
    public: UInt32 Size;
    public: UInt32 Reserved;
  };
  private: CLASS(__c) : public object {
    public: static void cctor();
    public: void ctor();
    public: void _GetSessions_b__37_0(Int32 etwSessionId, Int64 matchAllKeywords, List<SessionInfo>& sessionList);
    public: static __c __9;
    public: static SessionInfoCallback __9__37_0;
  };
  protected: EventLevel get_Level();
  protected: EventKeywords get_MatchAnyKeyword();
  public: void ctor(EventProviderType providerType);
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
