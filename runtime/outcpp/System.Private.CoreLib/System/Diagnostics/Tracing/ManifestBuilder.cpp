#include "ManifestBuilder-dep.h"

#include <System.Private.CoreLib/Microsoft/Reflection/ReflectionExtensions-dep.h>
#include <System.Private.CoreLib/System/Char-dep.h>
#include <System.Private.CoreLib/System/Collections/Generic/Dictionary-dep.h>
#include <System.Private.CoreLib/System/Collections/Generic/KeyValuePair-dep.h>
#include <System.Private.CoreLib/System/Collections/Generic/List-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/EventChannel.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/EventKeywords.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/ManifestBuilder-dep.h>
#include <System.Private.CoreLib/System/Globalization/CultureInfo-dep.h>
#include <System.Private.CoreLib/System/Reflection/BindingFlags.h>
#include <System.Private.CoreLib/System/Reflection/FieldInfo-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/StringComparison.h>
#include <System.Private.CoreLib/System/Text/Encoding-dep.h>
#include <System.Private.CoreLib/System/TypeCode.h>

namespace System::Private::CoreLib::System::Diagnostics::Tracing::ManifestBuilderNamespace {
using namespace Microsoft::Reflection;
using namespace System::Collections::Generic;
using namespace System::Globalization;
using namespace System::Reflection;
using namespace System::Text;

void ManifestBuilder___::ChannelInfo___::ctor() {
}

IList<String> ManifestBuilder___::get_Errors() {
  return errors;
}

void ManifestBuilder___::ctor(String providerName, Guid providerGuid, String dllName, ResourceManager resources, EventManifestOptions flags) {
  nextChannelKeywordBit = 9223372036854775808;
}

void ManifestBuilder___::AddOpcode(String name, Int32 value) {
}

void ManifestBuilder___::AddTask(String name, Int32 value) {
}

void ManifestBuilder___::AddKeyword(String name, UInt64 value) {
}

void ManifestBuilder___::AddChannel(String name, Int32 value, EventChannelAttribute channelAttribute) {
  EventChannel eventChannel = (EventChannel)value;
  if (value < 16 || value > 255) {
    ManifestError(SR::Format(SR::get_EventSource_EventChannelOutOfRange(), name, value));
  } else if ((Int32)eventChannel >= 16 && (Int32)eventChannel <= 19 && channelAttribute != nullptr && EventChannelToChannelType(eventChannel) != channelAttribute->get_EventChannelType()) {
    ManifestError(SR::Format(SR::get_EventSource_ChannelTypeDoesNotMatchEventChannelValue(), name, ((EventChannel)value)->ToString()));
  }

  UInt64 channelKeyword = GetChannelKeyword(eventChannel, 0);
  if (channelTab == nullptr) {
    channelTab = rt::newobj<Dictionary<Int32, ChannelInfo>>(4);
  }
  channelTab[value] = rt::newobj<ChannelInfo>();
}

EventChannelType ManifestBuilder___::EventChannelToChannelType(EventChannel channel) {
  return (EventChannelType)(channel - 16 + 1);
}

EventChannelAttribute ManifestBuilder___::GetDefaultChannelAttribute(EventChannel channel) {
  EventChannelAttribute eventChannelAttribute = rt::newobj<EventChannelAttribute>();
  eventChannelAttribute->set_EventChannelType = EventChannelToChannelType(channel);
  if (eventChannelAttribute->get_EventChannelType() <= EventChannelType::Operational) {
    eventChannelAttribute->set_Enabled = true;
  }
  return eventChannelAttribute;
}

Array<UInt64> ManifestBuilder___::GetChannelData() {
  if (channelTab == nullptr) {
    return Array<>::in::Empty<UInt64>();
  }
  Int32 num = -1;
}

void ManifestBuilder___::StartEvent(String eventName, EventAttribute eventAttribute) {
  this->eventName = eventName;
  numParams = 0;
  byteArrArgIndices = nullptr;
  events->Append("  <event")->Append(" value="")->Append(eventAttribute->get_EventId())->Append(""")->Append(" version="")->Append(eventAttribute->get_Version())->Append(""")->Append(" level="")->Append(GetLevelName(eventAttribute->get_Level()))->Append(""")->Append(" symbol="")->Append(eventName)->Append(""");
  WriteMessageAttrib(events, "event", eventName, eventAttribute->get_Message());
  if (eventAttribute->get_Keywords() != EventKeywords::None) {
    events->Append(" keywords="")->Append(GetKeywords((UInt64)eventAttribute->get_Keywords(), eventName))->Append(""");
  }
  if (eventAttribute->get_Opcode() != 0) {
    events->Append(" opcode="")->Append(GetOpcodeName(eventAttribute->get_Opcode(), eventName))->Append(""");
  }
  if (eventAttribute->get_Task() != 0) {
    events->Append(" task="")->Append(GetTaskName(eventAttribute->get_Task(), eventName))->Append(""");
  }
  if (eventAttribute->get_Channel() != 0) {
    events->Append(" channel="")->Append(GetChannelName(eventAttribute->get_Channel(), eventName, eventAttribute->get_Message()))->Append(""");
  }
}

void ManifestBuilder___::AddEventParameter(Type type, String name) {
  if (numParams == 0) {
    templates->Append("  <template tid="")->Append(eventName)->AppendLine("Args">");
  }
}

void ManifestBuilder___::EndEvent() {
  if (numParams > 0) {
    templates->AppendLine("  </template>");
    events->Append(" template="")->Append(eventName)->Append("Args"");
  }
  events->AppendLine("/>");
  if (byteArrArgIndices != nullptr) {
    perEventByteArrayArgIndices[eventName] = byteArrArgIndices;
  }
}

UInt64 ManifestBuilder___::GetChannelKeyword(EventChannel channel, UInt64 channelKeyword) {
  channelKeyword &= 17293822569102704640;
  if (channelTab == nullptr) {
    channelTab = rt::newobj<Dictionary<Int32, ChannelInfo>>(4);
  }
  if (channelTab->get_Count() == 8) {
    ManifestError(SR::get_EventSource_MaxChannelExceeded());
  }
}

Array<Byte> ManifestBuilder___::CreateManifest() {
  String s = CreateManifestString();
  return Encoding::in::get_UTF8()->GetBytes(s);
}

void ManifestBuilder___::ManifestError(String msg, Boolean runtimeCritical) {
}

String ManifestBuilder___::CreateManifestString() {
  if (channelTab != nullptr) {
    sb->AppendLine(" <channels>");
    List<KeyValuePair<Int32, ChannelInfo>> list = rt::newobj<List<KeyValuePair<Int32, ChannelInfo>>>();
  }
  if (taskTab != nullptr) {
    sb->AppendLine(" <tasks>");
    List<Int32> list2 = rt::newobj<List<Int32>>(taskTab->get_Keys());
    list2->Sort();
  }
  if (mapsTab != nullptr) {
    sb->AppendLine(" <maps>");
  }
  sb->AppendLine(" <opcodes>");
  List<Int32> list3 = rt::newobj<List<Int32>>(opcodeTab->get_Keys());
  list3->Sort();
}

void ManifestBuilder___::WriteNameAndMessageAttribs(StringBuilder stringBuilder, String elementName, String name) {
  stringBuilder->Append(" name="")->Append(name)->Append(""");
  WriteMessageAttrib(sb, elementName, name, name);
}

void ManifestBuilder___::WriteMessageAttrib(StringBuilder stringBuilder, String elementName, String name, String value) {
  String text = elementName + "_" + name;
  if (resources != nullptr) {
    String string = resources->GetString(text, CultureInfo::in::get_InvariantCulture());
    if (string != nullptr) {
      value = string;
    }
  }
  if (value != nullptr) {
    stringBuilder->Append(" message="$(string.")->Append(text)->Append(")"");
  }
}

String ManifestBuilder___::GetLocalizedMessage(String key, CultureInfo ci, Boolean etwFormat) {
  String value = nullptr;
  if (resources != nullptr) {
    String string = resources->GetString(key, ci);
    if (string != nullptr) {
      value = string;
      if (etwFormat && key->StartsWith("event_", StringComparison::Ordinal)) {
        String evtName = key->Substring("event_"->get_Length());
        value = TranslateToManifestConvention(value, evtName);
      }
    }
  }
  if (etwFormat && value == nullptr) {
    stringTab->TryGetValue(key, value);
  }
  return value;
}

List<CultureInfo> ManifestBuilder___::GetSupportedCultures() {
  List<CultureInfo> list = rt::newobj<List<CultureInfo>>();
  if (!list->Contains(CultureInfo::in::get_CurrentUICulture())) {
    list->Insert(0, CultureInfo::in::get_CurrentUICulture());
  }
  return list;
}

String ManifestBuilder___::GetLevelName(EventLevel level) {
  return ((level >= (EventLevel)16) ? "" : "win:") + level;
}

String ManifestBuilder___::GetChannelName(EventChannel channel, String eventName, String eventMessage) {
}

String ManifestBuilder___::GetTaskName(EventTask task, String eventName) {
  if (task == EventTask::None) {
    return "";
  }
  if (taskTab == nullptr) {
    taskTab = rt::newobj<Dictionary<Int32, String>>();
  }
}

String ManifestBuilder___::GetOpcodeName(EventOpcode opcode, String eventName) {
  switch (opcode) {
    case EventOpcode::Info:
      return "win:Info";
    case EventOpcode::Start:
      return "win:Start";
    case EventOpcode::Stop:
      return "win:Stop";
    case EventOpcode::DataCollectionStart:
      return "win:DC_Start";
    case EventOpcode::DataCollectionStop:
      return "win:DC_Stop";
    case EventOpcode::Extension:
      return "win:Extension";
    case EventOpcode::Reply:
      return "win:Reply";
    case EventOpcode::Resume:
      return "win:Resume";
    case EventOpcode::Suspend:
      return "win:Suspend";
    case EventOpcode::Send:
      return "win:Send";
    case EventOpcode::Receive:
      return "win:Receive";
    default:
      {
      }}
}

String ManifestBuilder___::GetKeywords(UInt64 keywords, String eventName) {
  keywords &= 1152921504606846975;
  String text = "";
  for (UInt64 num = 1; num != 0; num <<= 1) {
  }
  return text;
}

String ManifestBuilder___::GetTypeName(Type type) {
  if (ReflectionExtensions::IsEnum(type)) {
  }
}

void ManifestBuilder___::UpdateStringBuilder(StringBuilder& stringBuilder, String eventMessage, Int32 startIndex, Int32 count) {
  if (stringBuilder == nullptr) {
    stringBuilder = rt::newobj<StringBuilder>();
  }
  stringBuilder->Append(eventMessage, startIndex, count);
}

String ManifestBuilder___::TranslateToManifestConvention(String eventMessage, String evtName) {
  StringBuilder stringBuilder = nullptr;
  Int32 num = 0;
  Int32 i = 0;
  while (i < eventMessage->get_Length()) {
    Int32 num4;
    if (eventMessage[i] == 37) {
      UpdateStringBuilder(stringBuilder, eventMessage, num, i - num);
      stringBuilder->Append("%%");
      i++;
      num = i;
    } else if (i < eventMessage->get_Length() - 1 && ((eventMessage[i] == 123 && eventMessage[i + 1] == 123) || (eventMessage[i] == 125 && eventMessage[i + 1] == 125))) {
      UpdateStringBuilder(stringBuilder, eventMessage, num, i - num);
      stringBuilder->Append(eventMessage[i]);
      i++;
      i++;
      num = i;
    } else if (eventMessage[i] == 123) {
      Int32 num2 = i;
      i++;
      Int32 num3 = 0;
      for (; i < eventMessage->get_Length() && Char::IsDigit(eventMessage[i]); i++) {
        num3 = num3 * 10 + eventMessage[i] - 48;
      }
      if (i < eventMessage->get_Length() && eventMessage[i] == 125) {
        i++;
        UpdateStringBuilder(stringBuilder, eventMessage, num, num2 - num);
        Int32 value = TranslateIndexToManifestConvention(num3, evtName);
        stringBuilder->Append(37)->Append(value);
        if (i < eventMessage->get_Length() && eventMessage[i] == 33) {
          i++;
          stringBuilder->Append("%!");
        }
        num = i;
      } else {
        ManifestError(SR::Format(SR::get_EventSource_UnsupportedMessageProperty(), evtName, eventMessage));
      }
    } else if ((num4 = "&<>'"
	"->IndexOf(eventMessage[i])) >= 0) {
      UpdateStringBuilder(stringBuilder, eventMessage, num, i - num);
      i++;
      stringBuilder->Append(s_escapes[num4]);
      num = i;
    } else {
      i++;
    }



  }
  if (stringBuilder == nullptr) {
    return eventMessage;
  }
  UpdateStringBuilder(stringBuilder, eventMessage, num, i - num);
  return stringBuilder->ToString();
}

Int32 ManifestBuilder___::TranslateIndexToManifestConvention(Int32 idx, String evtName) {
}

void ManifestBuilder___::cctor() {
  s_escapes = rt::newarr<Array<String>>(8);
}

} // namespace System::Private::CoreLib::System::Diagnostics::Tracing::ManifestBuilderNamespace
