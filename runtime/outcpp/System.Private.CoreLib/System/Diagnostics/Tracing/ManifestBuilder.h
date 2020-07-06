#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/UInt64.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
FORWARDS(Byte)
FORWARD(String)
FORWARD(Type)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(Dictionary, TKey, TValue)
FORWARD(IList, T)
FORWARD(List, T)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System::Text {
FORWARD(StringBuilder)
} // namespace System::Private::CoreLib::System::Text
namespace System::Private::CoreLib::System::Globalization {
FORWARD(CultureInfo)
} // namespace System::Private::CoreLib::System::Globalization
namespace System::Private::CoreLib::System::Resources {
FORWARD(ResourceManager)
} // namespace System::Private::CoreLib::System::Resources
namespace System::Private::CoreLib::System::Diagnostics::Tracing {
enum class EventChannel : uint8_t;
enum class EventChannelType;
enum class EventLevel;
enum class EventManifestOptions;
enum class EventOpcode;
enum class EventTask;
FORWARD(EventAttribute)
FORWARD(EventChannelAttribute)
namespace ManifestBuilderNamespace {
using namespace Collections::Generic;
using namespace Globalization;
using namespace Resources;
using namespace Text;
using Collections::Generic::IList;
CLASS(ManifestBuilder) {
  private: CLASS(ChannelInfo) {
    public: String Name;
    public: UInt64 Keywords;
    public: EventChannelAttribute Attribs;
  };
  public: IList<String> get_Errors();
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
  public: UInt64 GetChannelKeyword(EventChannel channel, UInt64 channelKeyword);
  public: Array<Byte> CreateManifest();
  public: void ManifestError(String msg, Boolean runtimeCritical);
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
