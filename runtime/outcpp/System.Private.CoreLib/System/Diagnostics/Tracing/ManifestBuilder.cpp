#include "ManifestBuilder-dep.h"

#include <System.Private.CoreLib/Microsoft/Reflection/ReflectionExtensions-dep.h>
#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/Byte-dep.h>
#include <System.Private.CoreLib/System/Char-dep.h>
#include <System.Private.CoreLib/System/Collections/Generic/Dictionary-dep.h>
#include <System.Private.CoreLib/System/Collections/Generic/KeyValuePair-dep.h>
#include <System.Private.CoreLib/System/Collections/Generic/List-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/EventChannel.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/EventKeywords.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/ManifestBuilder-dep.h>
#include <System.Private.CoreLib/System/Enum-dep.h>
#include <System.Private.CoreLib/System/Globalization/CultureInfo-dep.h>
#include <System.Private.CoreLib/System/Int32-dep.h>
#include <System.Private.CoreLib/System/Int64-dep.h>
#include <System.Private.CoreLib/System/IntPtr-dep.h>
#include <System.Private.CoreLib/System/Reflection/BindingFlags.h>
#include <System.Private.CoreLib/System/Reflection/FieldInfo-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/StringComparison.h>
#include <System.Private.CoreLib/System/Text/Encoding-dep.h>
#include <System.Private.CoreLib/System/Text/StringBuilder-dep.h>
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
  Object::in::ctor();
  this->providerName = providerName;
  this->flags = flags;
  this->resources = resources;
  sb = rt::newobj<StringBuilder>();
  events = rt::newobj<StringBuilder>();
  templates = rt::newobj<StringBuilder>();
  opcodeTab = rt::newobj<Dictionary<Int32, String>>();
  stringTab = rt::newobj<Dictionary<String, String>>();
  errors = rt::newobj<List<String>>();
  perEventByteArrayArgIndices = rt::newobj<Dictionary<String, List<Int32>>>();
  sb->AppendLine("<instrumentationManifest xmlns="http://schemas.microsoft.com/win/2004/08/events">");
  sb->AppendLine(" <instrumentation xmlns:xs="http://www.w3.org/2001/XMLSchema" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:win="http://manifests.microsoft.com/win/2004/08/windows/events">");
  sb->AppendLine("  <events xmlns="http://schemas.microsoft.com/win/2004/08/events">");
  sb->Append("<provider name="")->Append(providerName)->Append("" guid="{")->Append(providerGuid.ToString())->Append(125);
  if (dllName != nullptr) {
    sb->Append("" resourceFileName="")->Append(dllName)->Append("" messageFileName="")->Append(dllName);
  }
  String value = providerName->Replace("-", "")->Replace(46, 95);
  sb->Append("" symbol="")->Append(value);
  sb->AppendLine("">");
}

void ManifestBuilder___::AddOpcode(String name, Int32 value) {
  if ((flags & EventManifestOptions::Strict) != 0) {
    if (value <= 10 || value >= 239) {
      ManifestError(SR::Format(SR::get_EventSource_IllegalOpcodeValue(), name, value));
    }
    String value2;
    if (opcodeTab->TryGetValue(value, value2) && !name->Equals(value2, StringComparison::Ordinal)) {
      ManifestError(SR::Format(SR::get_EventSource_OpcodeCollision(), name, value2, value));
    }
  }
  opcodeTab[value] = name;
}

void ManifestBuilder___::AddTask(String name, Int32 value) {
  if ((flags & EventManifestOptions::Strict) != 0) {
    if (value <= 0 || value >= 65535) {
      ManifestError(SR::Format(SR::get_EventSource_IllegalTaskValue(), name, value));
    }
    String value2;
    if (taskTab != nullptr && taskTab->TryGetValue(value, value2) && !name->Equals(value2, StringComparison::Ordinal)) {
      ManifestError(SR::Format(SR::get_EventSource_TaskCollision(), name, value2, value));
    }
  }
  if (taskTab == nullptr) {
    taskTab = rt::newobj<Dictionary<Int32, String>>();
  }
  taskTab[value] = name;
}

void ManifestBuilder___::AddKeyword(String name, UInt64 value) {
  if ((value & (value - 1)) != 0) {
    ManifestError(SR::Format(SR::get_EventSource_KeywordNeedPowerOfTwo(), "0x" + value.ToString("x", CultureInfo::in::get_CurrentCulture()), name), true);
  }
  if ((flags & EventManifestOptions::Strict) != 0) {
    if (value >= 17592186044416 && !name->StartsWith("Session", StringComparison::Ordinal)) {
      ManifestError(SR::Format(SR::get_EventSource_IllegalKeywordsValue(), name, "0x" + value.ToString("x", CultureInfo::in::get_CurrentCulture())));
    }
    String value2;
    if (keywordTab != nullptr && keywordTab->TryGetValue(value, value2) && !name->Equals(value2, StringComparison::Ordinal)) {
      ManifestError(SR::Format(SR::get_EventSource_KeywordCollision(), name, value2, "0x" + value.ToString("x", CultureInfo::in::get_CurrentCulture())));
    }
  }
  if (keywordTab == nullptr) {
    keywordTab = rt::newobj<Dictionary<UInt64, String>>();
  }
  keywordTab[value] = name;
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
  eventChannelAttribute->set_EventChannelType(EventChannelToChannelType(channel));
  if (eventChannelAttribute->get_EventChannelType() <= EventChannelType::Operational) {
    eventChannelAttribute->set_Enabled(true);
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
  if (type == typeof<Array<Byte>>()) {
    if (byteArrArgIndices == nullptr) {
      byteArrArgIndices = rt::newobj<List<Int32>>(4);
    }
    byteArrArgIndices->Add(numParams);
    numParams++;
    templates->Append("   <data name="")->Append(name)->AppendLine("Size" inType="win:UInt32"/>");
  }
  numParams++;
  templates->Append("   <data name="")->Append(name)->Append("" inType="")->Append(GetTypeName(type))->Append(""");
  if ((type->get_IsArray() || type->get_IsPointer()) && type->GetElementType() == typeof<Byte>()) {
    templates->Append(" length="")->Append(name)->Append("Size"");
  }
  if (ReflectionExtensions::IsEnum(type) && Enum::in::GetUnderlyingType(type) != typeof<UInt64>() && Enum::in::GetUnderlyingType(type) != typeof<Int64>()) {
    templates->Append(" map="")->Append(type->get_Name())->Append(""");
    if (mapsTab == nullptr) {
      mapsTab = rt::newobj<Dictionary<String, Type>>();
    }
    if (!mapsTab->ContainsKey(type->get_Name())) {
      mapsTab->Add(type->get_Name(), type);
    }
  }
  templates->AppendLine("/>");
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
  String value;
  if (stringTab->TryGetValue("event_" + eventName, value)) {
    value = TranslateToManifestConvention(value, eventName);
    stringTab["event_" + eventName] = value;
  }
  eventName = nullptr;
  numParams = 0;
  byteArrArgIndices = nullptr;
}

UInt64 ManifestBuilder___::GetChannelKeyword(EventChannel channel, UInt64 channelKeyword) {
  channelKeyword &= 17293822569102704640;
  if (channelTab == nullptr) {
    channelTab = rt::newobj<Dictionary<Int32, ChannelInfo>>(4);
  }
  if (channelTab->get_Count() == 8) {
    ManifestError(SR::get_EventSource_MaxChannelExceeded());
  }
  ChannelInfo value;
  if (!channelTab->TryGetValue((Int32)channel, value)) {
    if (channelKeyword != 0) {
      channelKeyword = nextChannelKeywordBit;
      nextChannelKeywordBit >>= 1;
    }
  } else {
    channelKeyword = value->Keywords;
  }
  return channelKeyword;
}

Array<Byte> ManifestBuilder___::CreateManifest() {
  String s = CreateManifestString();
  return Encoding::in::get_UTF8()->GetBytes(s);
}

void ManifestBuilder___::ManifestError(String msg, Boolean runtimeCritical) {
  if ((flags & EventManifestOptions::Strict) != 0) {
    errors->Add(msg);
  } else if (runtimeCritical) {
    rt::throw_exception<ArgumentException>(msg);
  }

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
    String value2;
    if (stringTab->TryGetValue(text, value2) && !value2->Equals(value)) {
      ManifestError(SR::Format(SR::get_EventSource_DuplicateStringKey(), text), true);
    } else {
      stringTab[text] = value;
    }
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
  ChannelInfo value;
  if (channelTab == nullptr || !channelTab->TryGetValue((Int32)channel, value)) {
    if ((Int32)channel < 16) {
      ManifestError(SR::Format(SR::get_EventSource_UndefinedChannel(), channel, eventName));
    }
    if (channelTab == nullptr) {
      channelTab = rt::newobj<Dictionary<Int32, ChannelInfo>>(4);
    }
    String text = channel->ToString();
    if (19 < (Int32)channel) {
      text = "Channel" + text;
    }
    AddChannel(text, (Int32)channel, GetDefaultChannelAttribute(channel));
    if (!channelTab->TryGetValue((Int32)channel, value)) {
      ManifestError(SR::Format(SR::get_EventSource_UndefinedChannel(), channel, eventName));
    }
  }
  if (resources != nullptr && eventMessage == nullptr) {
    eventMessage = resources->GetString("event_" + eventName, CultureInfo::in::get_InvariantCulture());
  }
  if (value->Attribs->get_EventChannelType() == EventChannelType::Admin && eventMessage == nullptr) {
    ManifestError(SR::Format(SR::get_EventSource_EventWithAdminChannelMustHaveMessage(), eventName, value->Name));
  }
  return value->Name;
}

String ManifestBuilder___::GetTaskName(EventTask task, String eventName) {
  if (task == EventTask::None) {
    return "";
  }
  if (taskTab == nullptr) {
    taskTab = rt::newobj<Dictionary<Int32, String>>();
  }
  String value;
  if (!taskTab->TryGetValue((Int32)task, value)) {
    return taskTab[(Int32)task] = eventName;
  }
  return value;
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
        String value;
        if (opcodeTab == nullptr || !opcodeTab->TryGetValue((Int32)opcode, value)) {
          ManifestError(SR::Format(SR::get_EventSource_UndefinedOpcode(), opcode, eventName), true);
          return nullptr;
        }
        return value;
      }}
}

String ManifestBuilder___::GetKeywords(UInt64 keywords, String eventName) {
  keywords &= 1152921504606846975;
  String text = "";
  for (UInt64 num = 1; num != 0; num <<= 1) {
    if ((keywords & num) != 0) {
      String value = nullptr;
      if ((keywordTab == nullptr || !keywordTab->TryGetValue(num, value)) && num >= 281474976710656) {
        value = String::in::Empty;
      }
      if (value == nullptr) {
        ManifestError(SR::Format(SR::get_EventSource_UndefinedKeyword(), "0x" + num.ToString("x", CultureInfo::in::get_CurrentCulture()), eventName), true);
        value = String::in::Empty;
      }
      if (text->get_Length() != 0 && value->get_Length() != 0) {
        text += " ";
      }
      text += value;
    }
  }
  return text;
}

String ManifestBuilder___::GetTypeName(Type type) {
  if (ReflectionExtensions::IsEnum(type)) {
    Array<FieldInfo> fields = type->GetFields(BindingFlags::Instance | BindingFlags::Public | BindingFlags::NonPublic);
    String typeName = GetTypeName(fields[0]->get_FieldType());
    return typeName->Replace("win:Int", "win:UInt");
  }
  switch (ReflectionExtensions::GetTypeCode(type)) {
    case TypeCode::Boolean:
      return "win:Boolean";
    case TypeCode::Byte:
      return "win:UInt8";
    case TypeCode::Char:
    case TypeCode::UInt16:
      return "win:UInt16";
    case TypeCode::UInt32:
      return "win:UInt32";
    case TypeCode::UInt64:
      return "win:UInt64";
    case TypeCode::SByte:
      return "win:Int8";
    case TypeCode::Int16:
      return "win:Int16";
    case TypeCode::Int32:
      return "win:Int32";
    case TypeCode::Int64:
      return "win:Int64";
    case TypeCode::String:
      return "win:UnicodeString";
    case TypeCode::Single:
      return "win:Float";
    case TypeCode::Double:
      return "win:Double";
    case TypeCode::DateTime:
      return "win:FILETIME";
    default:
      if (type == typeof<Guid>()) {
        return "win:GUID";
      }
      if (type == typeof<IntPtr>()) {
        return "win:Pointer";
      }
      if ((type->get_IsArray() || type->get_IsPointer()) && type->GetElementType() == typeof<Byte>()) {
        return "win:Binary";
      }
      ManifestError(SR::Format(SR::get_EventSource_UnsupportedEventTypeInManifest(), type->get_Name()), true);
      return String::in::Empty;
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
  List<Int32> value;
  if (perEventByteArrayArgIndices->TryGetValue(evtName, value)) {
  }
  return idx + 1;
}

void ManifestBuilder___::cctor() {
  s_escapes = rt::newarr<Array<String>>(8);
}

} // namespace System::Private::CoreLib::System::Diagnostics::Tracing::ManifestBuilderNamespace
