#pragma once

#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/Byte.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/EventDescriptor.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/EventProvider.h>
#include <System.Private.CoreLib/System/Guid.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Int64.h>
#include <System.Private.CoreLib/System/IntPtr.h>
#include <System.Private.CoreLib/System/Object.h>
#include <System.Private.CoreLib/System/UInt64.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARD(Attribute)
FORWARDS(Char)
FORWARDS(DateTime)
FORWARD_(EventHandler, T1, T2)
FORWARD(Exception)
FORWARDS(ReadOnlySpan, T)
FORWARD(String)
FORWARD(Type)
FORWARDS(UInt32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(Dictionary, TKey, TValue)
FORWARD(IDictionary, TKey, TValue)
FORWARD(IEnumerable, T)
FORWARD(List, T)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System::Reflection {
FORWARD(FieldInfo)
FORWARD(MemberInfo)
FORWARD(MethodInfo)
FORWARD(ParameterInfo)
} // namespace System::Private::CoreLib::System::Reflection
namespace System::Private::CoreLib::System::Runtime::InteropServices {
FORWARDS(GCHandle)
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
namespace System::Private::CoreLib::System::Diagnostics::Tracing {
enum class ControllerCommand;
enum class EventActivityOptions;
enum class EventChannel : uint8_t;
enum class EventCommand;
enum class EventKeywords : int64_t;
enum class EventLevel;
enum class EventManifestOptions;
enum class EventOpcode;
enum class EventProviderType;
enum class EventSourceSettings;
enum class EventTags;
FORWARD(ActivityTracker)
FORWARD(EventAttribute)
FORWARD(EventCommandEventArgs)
FORWARD(EventDispatcher)
FORWARD(EventListener)
FORWARD(EventPayload)
FORWARDS(EventSourceOptions)
FORWARD(EventWrittenEventArgs)
FORWARD(ManifestBuilder)
FORWARD(NameInfo)
FORWARD(TraceLoggingEventHandleTable)
FORWARD(TraceLoggingEventTypes)
namespace EventSourceNamespace {
using namespace Collections::Generic;
using namespace Reflection;
using namespace Runtime::InteropServices;
CLASS(EventSource) : public Object::in {
  public: struct EventData : public valueType<EventData> {
    public: IntPtr get_DataPointer();
    public: void set_DataPointer(IntPtr value);
    public: Int32 get_Size();
    public: void set_Size(Int32 value);
    public: void set_Reserved(Int32 value);
    public: void SetMetadata(Byte* pointer, Int32 size, Int32 reserved);
    public: UInt64 m_Ptr;
    public: Int32 m_Size;
    public: Int32 m_Reserved;
  };
  private: struct Sha1ForNonSecretPurposes : public valueType<Sha1ForNonSecretPurposes> {
    public: void Start();
    public: void Append(Byte input);
    public: void Append(ReadOnlySpan<Byte> input);
    public: void Finish(Array<Byte> output);
    private: void Drain();
    private: Int64 length;
    private: Array<UInt32> w;
    private: Int32 pos;
  };
  private: CLASS(OverideEventProvider) : public EventProvider::in {
    public: void Ctor(EventSource eventSource, EventProviderType providerType);
    protected: void OnControllerCommand(ControllerCommand command, IDictionary<String, String> arguments, Int32 perEventSourceSessionId, Int32 etwSessionId);
    private: EventSource m_eventSource;
    private: EventProviderType m_eventProviderType;
  };
  public: struct EventMetadata : public valueType<EventMetadata> {
    public: EventDescriptor Descriptor;
    public: IntPtr EventHandle;
    public: EventTags Tags;
    public: Boolean EnabledForAnyListener;
    public: Boolean EnabledForETW;
    public: Boolean EnabledForEventPipe;
    public: Boolean HasRelatedActivityID;
    public: Byte TriggersActivityTracking;
    public: String Name;
    public: String Message;
    public: Array<ParameterInfo> Parameters;
    public: TraceLoggingEventTypes TraceLoggingEventTypes;
    public: EventActivityOptions ActivityOptions;
  };
  public: String get_Name();
  public: Guid get_Guid();
  public: EventSourceSettings get_Settings();
  public: Exception get_ConstructionException();
  public: static Guid get_CurrentThreadActivityId();
  private: Boolean get_IsDisposed();
  private: Boolean get_ThrowOnEventWriteErrors();
  private: Boolean get_SelfDescribingEvents();
  public: Boolean IsEnabled();
  public: Boolean IsEnabled(EventLevel level, EventKeywords keywords);
  public: Boolean IsEnabled(EventLevel level, EventKeywords keywords, EventChannel channel);
  public: static Guid GetGuid(Type eventSourceType);
  public: static String GetName(Type eventSourceType);
  public: static String GenerateManifest(Type eventSourceType, String assemblyPathToIncludeInManifest);
  public: static String GenerateManifest(Type eventSourceType, String assemblyPathToIncludeInManifest, EventManifestOptions flags);
  public: static IEnumerable<EventSource> GetSources();
  public: static void SendCommand(EventSource eventSource, EventCommand command, IDictionary<String, String> commandArguments);
  public: String GetTrait(String key);
  public: String ToString();
  public: static void SetCurrentThreadActivityId(Guid activityId);
  public: static void SetCurrentThreadActivityId(Guid activityId, Guid& oldActivityThatWillContinue);
  protected: void Ctor();
  protected: void Ctor(Boolean throwOnEventWriteErrors);
  protected: void Ctor(EventSourceSettings settings);
  protected: void Ctor(EventSourceSettings settings, Array<String> traits);
  private: void DefineEventPipeEvents();
  public: void GetMetadata(Guid& eventSourceGuid, String& eventSourceName, Array<EventMetadata>& eventData, Array<Byte>& manifestBytes);
  protected: void OnEventCommand(EventCommandEventArgs command);
  protected: void WriteEvent(Int32 eventId);
  protected: void WriteEvent(Int32 eventId, Int32 arg1);
  protected: void WriteEvent(Int32 eventId, Int32 arg1, Int32 arg2);
  protected: void WriteEvent(Int32 eventId, Int32 arg1, Int32 arg2, Int32 arg3);
  protected: void WriteEvent(Int32 eventId, Int64 arg1);
  protected: void WriteEvent(Int32 eventId, Int64 arg1, Int64 arg2);
  protected: void WriteEvent(Int32 eventId, Int64 arg1, Int64 arg2, Int64 arg3);
  protected: void WriteEvent(Int32 eventId, String arg1);
  protected: void WriteEvent(Int32 eventId, String arg1, String arg2);
  protected: void WriteEvent(Int32 eventId, String arg1, String arg2, String arg3);
  protected: void WriteEvent(Int32 eventId, String arg1, Int32 arg2);
  protected: void WriteEvent(Int32 eventId, String arg1, Int32 arg2, Int32 arg3);
  protected: void WriteEvent(Int32 eventId, String arg1, Int64 arg2);
  protected: void WriteEvent(Int32 eventId, Int64 arg1, String arg2);
  protected: void WriteEvent(Int32 eventId, Int32 arg1, String arg2);
  protected: void WriteEvent(Int32 eventId, Array<Byte> arg1);
  protected: void WriteEvent(Int32 eventId, Int64 arg1, Array<Byte> arg2);
  protected: void WriteEventCore(Int32 eventId, Int32 eventDataCount, EventData* data);
  protected: void WriteEventWithRelatedActivityIdCore(Int32 eventId, Guid* relatedActivityId, Int32 eventDataCount, EventData* data);
  protected: void WriteEvent(Int32 eventId, Array<Object> args);
  protected: void WriteEventWithRelatedActivityId(Int32 eventId, Guid relatedActivityId, Array<Object> args);
  public: void Dispose();
  protected: void Dispose(Boolean disposing);
  protected: void Finalize();
  private: void WriteEventRaw(String eventName, EventDescriptor& eventDescriptor, IntPtr eventHandle, Guid* activityID, Guid* relatedActivityID, Int32 dataCount, IntPtr data);
  public: void Ctor(Guid eventSourceGuid, String eventSourceName);
  public: void Ctor(Guid eventSourceGuid, String eventSourceName, EventSourceSettings settings, Array<String> traits);
  private: void Initialize(Guid eventSourceGuid, String eventSourceName, Array<String> traits);
  private: static String GetName(Type eventSourceType, EventManifestOptions flags);
  private: static Guid GenerateGuidFromName(String name);
  private: Object DecodeObject(Int32 eventId, Int32 parameterId, EventData*& data);
  private: EventDispatcher GetDispatcher(EventListener listener);
  private: void WriteEventVarargs(Int32 eventId, Guid* childActivityID, Array<Object> args);
  private: Array<Object> SerializeEventArgs(Int32 eventId, Array<Object> args);
  private: void LogEventArgsMismatches(Int32 eventId, Array<Object> args);
  private: void WriteToAllListeners(Int32 eventId, Guid* activityID, Guid* childActivityID, Int32 eventDataCount, EventData* data);
  public: void WriteToAllListeners(Int32 eventId, UInt32* osThreadId, DateTime* timeStamp, Guid* activityID, Guid* childActivityID, Array<Object> args);
  private: void DispatchToAllListeners(Int32 eventId, EventWrittenEventArgs eventCallbackArgs);
  private: void WriteEventString(String msgString);
  private: void WriteStringToAllListeners(String eventName, String msg);
  private: Boolean IsEnabledByDefault(Int32 eventNum, Boolean enable, EventLevel currentLevel, EventKeywords currentMatchAnyKeyword);
  private: Boolean IsEnabledCommon(Boolean enabled, EventLevel currentLevel, EventKeywords currentMatchAnyKeyword, EventLevel eventLevel, EventKeywords eventKeywords, EventChannel eventChannel);
  private: void ThrowEventSourceException(String eventName, Exception innerEx);
  private: void ValidateEventOpcodeForTransfer(EventMetadata& eventData, String eventName);
  public: static EventOpcode GetOpcodeWithDefault(EventOpcode opcode, String eventName);
  private: static Int32 GetParameterCount(EventMetadata eventData);
  private: static Type GetDataType(EventMetadata eventData, Int32 parameterId);
  public: void SendCommand(EventListener listener, EventProviderType eventProviderType, Int32 perEventSourceSessionId, Int32 etwSessionId, EventCommand command, Boolean enable, EventLevel level, EventKeywords matchAnyKeyword, IDictionary<String, String> commandArguments);
  public: void DoCommand(EventCommandEventArgs commandArgs);
  public: Boolean EnableEventForDispatcher(EventDispatcher dispatcher, EventProviderType eventProviderType, Int32 eventId, Boolean value);
  private: Boolean AnyEventEnabled();
  private: void EnsureDescriptorsInitialized();
  private: void SendManifest(Array<Byte> rawManifest);
  public: static Attribute GetCustomAttributeHelper(MemberInfo member, Type attributeType, EventManifestOptions flags);
  private: static Boolean AttributeTypeNamesMatch(Type attributeType, Type reflectedAttributeType);
  private: static Type GetEventSourceBaseType(Type eventSourceType, Boolean allowEventSourceOverride, Boolean reflectionOnly);
  private: static Array<Byte> CreateManifestAndDescriptors(Type eventSourceType, String eventSourceDllName, EventSource source, EventManifestOptions flags);
  private: static Boolean RemoveFirstArgIfRelatedActivityId(Array<ParameterInfo>& args);
  private: static void AddProviderEnumKind(ManifestBuilder manifest, FieldInfo staticField, String providerEnumKind);
  private: static void AddEventDescriptor(Array<EventMetadata>& eventData, String eventName, EventAttribute eventAttribute, Array<ParameterInfo> eventParameters, Boolean hasRelatedActivityID);
  private: static void TrimEventDescriptors(Array<EventMetadata>& eventData);
  public: void AddListener(EventListener listener);
  private: static void DebugCheckEvent(Dictionary<String, String>& eventsByName, Array<EventMetadata> eventData, MethodInfo method, EventAttribute eventAttribute, ManifestBuilder manifest, EventManifestOptions options);
  private: static Int32 GetHelperCallFirstArg(MethodInfo method);
  public: void ReportOutOfBandMessage(String msg);
  private: EventSourceSettings ValidateSettings(EventSourceSettings settings);
  public: void Ctor(String eventSourceName);
  public: void Ctor(String eventSourceName, EventSourceSettings config);
  public: void Ctor(String eventSourceName, EventSourceSettings config, Array<String> traits);
  public: void Write(String eventName);
  public: void Write(String eventName, EventSourceOptions options);
  public: template <class T>
  void Write(String eventName, T data);
  public: template <class T>
  void Write(String eventName, EventSourceOptions options, T data);
  public: template <class T>
  void Write(String eventName, EventSourceOptions& options, T& data);
  public: template <class T>
  void Write(String eventName, EventSourceOptions& options, Guid& activityId, Guid& relatedActivityId, T& data);
  private: void WriteMultiMerge(String eventName, EventSourceOptions& options, TraceLoggingEventTypes eventTypes, Guid* activityID, Guid* childActivityID, Array<Object> values);
  private: void WriteMultiMergeInner(String eventName, EventSourceOptions& options, TraceLoggingEventTypes eventTypes, Guid* activityID, Guid* childActivityID, Array<Object> values);
  public: void WriteMultiMerge(String eventName, EventSourceOptions& options, TraceLoggingEventTypes eventTypes, Guid* activityID, Guid* childActivityID, EventData* data);
  private: void WriteImpl(String eventName, EventSourceOptions& options, Object data, Guid* pActivityId, Guid* pRelatedActivityId, TraceLoggingEventTypes eventTypes);
  private: void WriteToAllListeners(String eventName, EventDescriptor& eventDescriptor, EventTags tags, Guid* pActivityId, Guid* pChildActivityId, EventPayload payload);
  private: static void WriteCleanup(GCHandle* pPins, Int32 cPins);
  private: void InitializeProviderMetadata();
  private: static Int32 AddValueToMetaData(List<Byte> metaData, String value);
  private: static Int32 HexDigit(Char c);
  private: NameInfo UpdateDescriptor(String name, TraceLoggingEventTypes eventInfo, EventSourceOptions& options, EventDescriptor& descriptor);
  private: String m_name;
  public: Int32 m_id;
  private: Guid m_guid;
  public: Array<EventMetadata> m_eventData;
  private: Array<Byte> m_rawManifest;
  private: EventHandler<EventCommandEventArgs> m_eventCommandExecuted;
  private: EventSourceSettings m_config;
  private: Boolean m_eventSourceDisposed;
  private: Boolean m_eventSourceEnabled;
  public: EventLevel m_level;
  public: EventKeywords m_matchAnyKeyword;
  public: EventDispatcher m_Dispatchers;
  private: OverideEventProvider m_etwProvider;
  private: Object m_createEventLock;
  private: IntPtr m_writeEventStringEventHandle;
  private: OverideEventProvider m_eventPipeProvider;
  private: Boolean m_completelyInited;
  private: Exception m_constructionException;
  private: Byte m_outOfBandMessageCount;
  private: EventCommandEventArgs m_deferredCommands;
  private: Array<String> m_traits;
  public: static UInt32 s_currentPid;
  private: static Byte m_EventSourceExceptionRecurenceCount;
  private: static Boolean m_EventSourceInDecodeObject;
  public: Array<UInt64> m_channelData;
  private: ActivityTracker m_activityTracker;
  private: Array<Byte> providerMetadata;
  private: TraceLoggingEventHandleTable m_eventHandleTable;
};
} // namespace EventSourceNamespace
using EventSource = EventSourceNamespace::EventSource;
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing
