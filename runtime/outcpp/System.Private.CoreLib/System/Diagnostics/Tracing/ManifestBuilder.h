#pragma once

#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Object.h>
#include <System.Private.CoreLib/System/UInt64.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array)
FORWARDS(Byte)
FORWARD(Comparison, T)
FORWARDS(Guid)
FORWARD(String)
FORWARD(Type)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(Dictionary, TKey, TValue)
FORWARD(IList, T)
FORWARDS_(KeyValuePair)
FORWARD(List, T)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System::Resources {
FORWARD(ResourceManager)
} // namespace System::Private::CoreLib::System::Resources
namespace System::Private::CoreLib::System::Text {
FORWARD(StringBuilder)
} // namespace System::Private::CoreLib::System::Text
namespace System::Private::CoreLib::System::Globalization {
FORWARD(CultureInfo)
} // namespace System::Private::CoreLib::System::Globalization
namespace System::Private::CoreLib::System::Diagnostics::Tracing {
enum class EventChannel : uint8_t;
enum class EventChannelType : int32_t;
enum class EventLevel : int32_t;
enum class EventManifestOptions : int32_t;
enum class EventOpcode : int32_t;
enum class EventTask : int32_t;
FORWARD(EventAttribute)
FORWARD(EventChannelAttribute)
namespace ManifestBuilderNamespace {
using namespace System::Collections::Generic;
using namespace System::Globalization;
using namespace System::Resources;
using namespace System::Text;
CLASS(ManifestBuilder) : public object {
  private: CLASS(ChannelInfo) : public object {
    public: void ctor();
    public: String Name;
    public: UInt64 Keywords;
    public: EventChannelAttribute Attribs;
  };
  private: CLASS(__c) : public object {
    public: static void cctor();
    public: void ctor();
    public: Int32 _CreateManifestString_b__16_0(KeyValuePair<Int32, ChannelInfo> p1, KeyValuePair<Int32, ChannelInfo> p2);
    public: static __c __9;
    public: static Comparison<KeyValuePair<Int32, ChannelInfo>> __9__16_0;
  };
  public: IList<String> get_Errors();
  public: void ctor(String providerName, Guid providerGuid, String dllName, ResourceManager resources, EventManifestOptions flags);
  public: void AddOpcode(String name, Int32 value);
  public: void AddTask(String name, Int32 value);
  public: void AddKeyword(String name, UInt64 value);
  public: void AddChannel(String name, Int32 value, EventChannelAttribute channelAttribute);
  private: static EventChannelType EventChannelToChannelType(EventChannel channel);
  private: static EventChannelAttribute GetDefaultChannelAttribute(EventChannel channel);
  public: Array<UInt64> GetChannelData();
  public: void StartEvent(String eventName, EventAttribute eventAttribute);
  public: void AddEventParameter(Type type, String name);
  public: void EndEvent();
  public: UInt64 GetChannelKeyword(EventChannel channel, UInt64 channelKeyword = 0);
  public: Array<Byte> CreateManifest();
  public: void ManifestError(String msg, Boolean runtimeCritical = false);
  private: String CreateManifestString();
  private: void WriteNameAndMessageAttribs(StringBuilder stringBuilder, String elementName, String name);
  private: void WriteMessageAttrib(StringBuilder stringBuilder, String elementName, String name, String value);
  public: String GetLocalizedMessage(String key, CultureInfo ci, Boolean etwFormat);
  private: static List<CultureInfo> GetSupportedCultures();
  private: static String GetLevelName(EventLevel level);
  private: String GetChannelName(EventChannel channel, String eventName, String eventMessage);
  private: String GetTaskName(EventTask task, String eventName);
  private: String GetOpcodeName(EventOpcode opcode, String eventName);
  private: String GetKeywords(UInt64 keywords, String eventName);
  private: String GetTypeName(Type type);
  private: static void UpdateStringBuilder(StringBuilder& stringBuilder, String eventMessage, Int32 startIndex, Int32 count);
  private: String TranslateToManifestConvention(String eventMessage, String evtName);
  private: Int32 TranslateIndexToManifestConvention(Int32 idx, String evtName);
  public: static void cctor();
  private: static Array<String> s_escapes;
  private: Dictionary<Int32, String> opcodeTab;
  private: Dictionary<Int32, String> taskTab;
  private: Dictionary<Int32, ChannelInfo> channelTab;
  private: Dictionary<UInt64, String> keywordTab;
  private: Dictionary<String, Type> mapsTab;
  private: Dictionary<String, String> stringTab;
  private: UInt64 nextChannelKeywordBit;
  private: StringBuilder sb;
  private: StringBuilder events;
  private: StringBuilder templates;
  private: String providerName;
  private: ResourceManager resources;
  private: EventManifestOptions flags;
  private: IList<String> errors;
  private: Dictionary<String, List<Int32>> perEventByteArrayArgIndices;
  private: String eventName;
  private: Int32 numParams;
  private: List<Int32> byteArrArgIndices;
};
} // namespace ManifestBuilderNamespace
using ManifestBuilder = ManifestBuilderNamespace::ManifestBuilder;
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing
