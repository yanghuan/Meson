#include "EventProvider-dep.h"

#include <System.Private.CoreLib/Internal/Win32/Registry-dep.h>
#include <System.Private.CoreLib/Internal/Win32/RegistryKey-dep.h>
#include <System.Private.CoreLib/Interop-dep.h>
#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/Char-dep.h>
#include <System.Private.CoreLib/System/Collections/Generic/Dictionary-dep.h>
#include <System.Private.CoreLib/System/Collections/Generic/IDictionary.h>
#include <System.Private.CoreLib/System/Convert-dep.h>
#include <System.Private.CoreLib/System/DateTime-dep.h>
#include <System.Private.CoreLib/System/Decimal-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/ControllerCommand.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/EtwEventProvider-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/EventListener-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/EventPipeEventProvider-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/EventProvider-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/IEventProvider.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/NoOpEventProvider-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/SessionMask-dep.h>
#include <System.Private.CoreLib/System/Double-dep.h>
#include <System.Private.CoreLib/System/Enum-dep.h>
#include <System.Private.CoreLib/System/GC-dep.h>
#include <System.Private.CoreLib/System/Globalization/CultureInfo-dep.h>
#include <System.Private.CoreLib/System/Int16-dep.h>
#include <System.Private.CoreLib/System/Numerics/BitOperations-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/GCHandle-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/GCHandleType.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/Marshal-dep.h>
#include <System.Private.CoreLib/System/SByte-dep.h>
#include <System.Private.CoreLib/System/Single-dep.h>
#include <System.Private.CoreLib/System/String-dep.h>
#include <System.Private.CoreLib/System/Text/Encoding-dep.h>
#include <System.Private.CoreLib/System/Tuple-dep.h>
#include <System.Private.CoreLib/System/Type-dep.h>
#include <System.Private.CoreLib/System/TypeLoadException-dep.h>
#include <System.Private.CoreLib/System/UInt16-dep.h>

namespace System::Private::CoreLib::System::Diagnostics::Tracing::EventProviderNamespace {
using namespace Internal::Win32;
using namespace System::Collections::Generic;
using namespace System::Globalization;
using namespace System::Numerics;
using namespace System::Runtime::InteropServices;
using namespace System::Text;

EventProvider___::SessionInfo::SessionInfo(Int32 sessionIdBit_, Int32 etwSessionId_) {
  sessionIdBit = sessionIdBit_;
  etwSessionId = etwSessionId_;
}

EventLevel EventProvider___::get_Level() {
  return (EventLevel)m_level;
}

EventKeywords EventProvider___::get_MatchAnyKeyword() {
  return (EventKeywords)m_anyKeywordMask;
}

void EventProvider___::ctor(EventProviderType providerType) {
  IEventProvider eventProvider;
  switch (providerType) {
    case EventProviderType::ETW:
      eventProvider = rt::newobj<EtwEventProvider>();
      break;
    case EventProviderType::EventPipe:
      eventProvider = rt::newobj<EventPipeEventProvider>();
      break;
    default:
      eventProvider = rt::newobj<NoOpEventProvider>();
      break;
  }
  m_eventProvider = eventProvider;
}

void EventProvider___::Register(EventSource eventSource) {
  m_etwCallback = &EtwEnableCallBack;
  UInt32 num = EventRegister(eventSource, m_etwCallback);
  if (num != 0) {
    rt::throw_exception<ArgumentException>(Interop::Kernel32::GetMessage((Int32)num));
  }
}

void EventProvider___::Dispose() {
  Dispose(true);
  GC::SuppressFinalize((EventProvider)this);
}

void EventProvider___::Dispose(Boolean disposing) {
  if (m_disposed) {
    return;
  }
  m_enabled = false;
  Int64 num = 0;
  {
    rt::lock(EventListener::in::get_EventListenersLock());
    if (m_disposed) {
      return;
    }
    num = m_regHandle;
    m_regHandle = 0;
    m_disposed = true;
  }
  if (num != 0) {
    EventUnregister(num);
  }
}

void EventProvider___::Finalize() {
  Dispose(false);
}

void EventProvider___::EtwEnableCallBack(Guid& sourceId, Int32 controlCode, Byte setLevel, Int64 anyKeyword, Int64 allKeyword, Interop::Advapi32::EVENT_FILTER_DESCRIPTOR* filterData, void* callbackContext) {
  try {
    ControllerCommand command = ControllerCommand::Update;
    IDictionary<String, String> dictionary = nullptr;
    Boolean flag = false;
    switch (controlCode.get()) {
      default:
        return;
      case 1:
        {
          m_enabled = true;
          m_level = setLevel;
          m_anyKeywordMask = anyKeyword;
          m_allKeywordMask = allKeyword;
          List<Tuple<SessionInfo, Boolean>> sessions = GetSessions();
          if (sessions->get_Count() == 0) {
            sessions->Add(rt::newobj<Tuple<SessionInfo, Boolean>>(SessionInfo(0, 0), true));
          }
          for (Tuple<SessionInfo, Boolean>& item2 : sessions) {
            Int32 sessionIdBit = item2->get_Item1().sessionIdBit;
            Int32 etwSessionId = item2->get_Item1().etwSessionId;
            Boolean item = item2->get_Item2();
            flag = true;
            dictionary = nullptr;
            if (sessions->get_Count() > 1) {
              filterData = nullptr;
            }
            Array<Byte> data;
            Int32 dataStart;
            if (item && GetDataFromController(etwSessionId, filterData, command, data, dataStart)) {
              dictionary = rt::newobj<Dictionary<String, String>>(4);
              if (data != nullptr) {
                while (dataStart < data->get_Length()) {
                  Int32 num = FindNull(data, dataStart);
                  Int32 num2 = num + 1;
                  Int32 num3 = FindNull(data, num2);
                  if (num3 < data->get_Length()) {
                    String string = Encoding::in::get_UTF8()->GetString(data, dataStart, num - dataStart);
                    String text = dictionary[string] = Encoding::in::get_UTF8()->GetString(data, num2, num3 - num2);
                  }
                  dataStart = num3 + 1;
                }
              }
            }
            OnControllerCommand(command, dictionary, item ? sessionIdBit : (-sessionIdBit), etwSessionId);
          }
          break;
        }case 0:
        m_enabled = false;
        m_level = 0;
        m_anyKeywordMask = 0;
        m_allKeywordMask = 0;
        m_liveSessions = nullptr;
        break;
      case 2:
        command = ControllerCommand::SendManifest;
        break;
    }
    if (!flag) {
      OnControllerCommand(command, dictionary, 0, 0);
    }
  } catch (...) {
  }
}

void EventProvider___::OnControllerCommand(ControllerCommand command, IDictionary<String, String> arguments, Int32 sessionId, Int32 etwSessionId) {
}

Int32 EventProvider___::FindNull(Array<Byte> buffer, Int32 idx) {
  while (idx < buffer->get_Length() && buffer[idx] != 0) {
    idx++;
  }
  return idx;
}

List<Tuple<EventProvider::in::SessionInfo, Boolean>> EventProvider___::GetSessions() {
  List<SessionInfo> sessionList2 = nullptr;
}

void EventProvider___::GetSessionInfoCallback(Int32 etwSessionId, Int64 matchAllKeywords, List<SessionInfo>& sessionList) {
  UInt32 value = (UInt32)SessionMask::FromEventKeywords((UInt64)matchAllKeywords);
  Int32 num = BitOperations::PopCount(value);
  if (num <= 1) {
    if (sessionList == nullptr) {
      sessionList = rt::newobj<List<SessionInfo>>(8);
    }
    num = ((num != 1) ? BitOperations::PopCount((UInt32)SessionMask::get_All()) : BitOperations::TrailingZeroCount(value));
    sessionList->Add(SessionInfo(num + 1, etwSessionId));
  }
}

void EventProvider___::GetSessionInfo(SessionInfoCallback action, List<SessionInfo>& sessionList) {
  Int32 ReturnLength = 256;
  Byte as[(Int32)(UInt32)ReturnLength] = {};
  Byte* ptr = as;
  Byte* ptr2 = ptr;
  try {
    while (true) {
      Int32 num = 0;
      try {
        {
          Guid* inBuffer = &m_providerId;
          num = Interop::Advapi32::EnumerateTraceGuidsEx(Interop::Advapi32::TRACE_QUERY_INFO_CLASS::TraceGuidQueryInfo, inBuffer, sizeof(Guid), ptr2, ReturnLength, ReturnLength);
        }
      } catch (...) {
      } finally: {
      }
      switch (num.get()) {
        default:
          return;
        case 122:
          if (ptr2 != ptr) {
            Byte* value = ptr2;
            ptr2 = nullptr;
            Marshal::FreeHGlobal((IntPtr)(void*)value);
          }
          break;
        case 0:
          {
            Interop::Advapi32::TRACE_GUID_INFO* ptr3 = (Interop::Advapi32::TRACE_GUID_INFO*)ptr2;
            Interop::Advapi32::TRACE_PROVIDER_INSTANCE_INFO* ptr4 = (Interop::Advapi32::TRACE_PROVIDER_INSTANCE_INFO*)(ptr3 + 1);
            Int32 currentProcessId = (Int32)Interop::Kernel32::GetCurrentProcessId();
            for (Int32 i = 0; i < ptr3->InstanceCount; i++) {
              if (ptr4->Pid == currentProcessId) {
                Interop::Advapi32::TRACE_ENABLE_INFO* ptr5 = (Interop::Advapi32::TRACE_ENABLE_INFO*)(ptr4 + 1);
                for (Int32 j = 0; j < ptr4->EnableCount; j++) {
                  action(*(ptr5 + j).LoggerId, *(ptr5 + j).MatchAllKeyword, sessionList);
                }
              }
              if (ptr4->NextOffset == 0) {
                break;
              }
              Byte* ptr6 = (Byte*)ptr4;
              ptr4 = (Interop::Advapi32::TRACE_PROVIDER_INSTANCE_INFO*)(ptr6 + ptr4->NextOffset);
            }
            return;
          }}
      ptr2 = (Byte*)(void*)Marshal::AllocHGlobal(ReturnLength);
    }
  } catch (...) {
  } finally: {
    if (ptr2 != nullptr && ptr2 != ptr) {
      Marshal::FreeHGlobal((IntPtr)(void*)ptr2);
    }
  }
}

Int32 EventProvider___::IndexOfSessionInList(List<SessionInfo> sessions, Int32 etwSessionId) {
  if (sessions == nullptr) {
    return -1;
  }
  for (Int32 i = 0; i < sessions->get_Count(); i++) {
    if (sessions[i].etwSessionId == etwSessionId) {
      return i;
    }
  }
  return -1;
}

Boolean EventProvider___::GetDataFromController(Int32 etwSessionId, Interop::Advapi32::EVENT_FILTER_DESCRIPTOR* filterData, ControllerCommand& command, Array<Byte>& data, Int32& dataStart) {
  data = nullptr;
  dataStart = 0;
  if (filterData == nullptr) {
    Guid providerId = m_providerId;
    String str = "\Microsoft\Windows\CurrentVersion\Winevt\Publishers\{" + providerId.ToString() + "}";
    Int32 size = IntPtr::get_Size();
    str = "Software\Wow6432Node" + str;
    String name = "ControllerData_Session_" + etwSessionId.ToString(CultureInfo::in::get_InvariantCulture());
    {
      RegistryKey registryKey = Registry::LocalMachine->OpenSubKey(str);
      rt::Using(registryKey);
      data = (rt::as<Array<Byte>>(((registryKey != nullptr) ? registryKey->GetValue(name, nullptr) : nullptr)));
      if (data != nullptr) {
        command = ControllerCommand::Update;
        return true;
      }
    }
    command = ControllerCommand::Update;
    return false;
  }
  if (filterData->Ptr != 0 && 0 < filterData->Size && filterData->Size <= 102400) {
    data = rt::newarr<Array<Byte>>(filterData->Size);
    Marshal::Copy((IntPtr)(void*)filterData->Ptr, data, 0, data->get_Length());
  }
  command = (ControllerCommand)filterData->Type;
  return true;
}

Boolean EventProvider___::IsEnabled() {
  return m_enabled;
}

Boolean EventProvider___::IsEnabled(Byte level, Int64 keywords) {
  if (!m_enabled) {
    return false;
  }
  if ((level <= m_level || m_level == 0) && (keywords == 0 || ((keywords & m_anyKeywordMask) != 0 && (keywords & m_allKeywordMask) == m_allKeywordMask))) {
    return true;
  }
  return false;
}

EventProvider::in::WriteEventErrorCode EventProvider___::GetLastWriteEventError() {
  return s_returnCode;
}

void EventProvider___::SetLastError(WriteEventErrorCode error) {
  s_returnCode = error;
}

Object EventProvider___::EncodeObject(Object& data, EventData*& dataDescriptor, Byte*& dataBuffer, UInt32& totalEventSize) {
  String text;
  Array<Byte> array;
  while (true) {
    dataDescriptor->Reserved = 0u;
    text = (rt::as<String>(data));
    array = nullptr;
    if (text != nullptr) {
      dataDescriptor->Size = (UInt32)((text->get_Length() + 1) * 2);
      break;
    }
    if ((array = (rt::as<Array<Byte>>(data))) != nullptr) {
      *(Int32*)dataBuffer = array->get_Length();
      dataDescriptor->Ptr = (UInt64)dataBuffer;
      dataDescriptor->Size = 4u;
      totalEventSize += dataDescriptor->Size;
      dataDescriptor++;
      dataBuffer += 16;
      dataDescriptor->Size = (UInt32)array->get_Length();
      break;
    }
    if (rt::is<IntPtr>(data)) {
      dataDescriptor->Size = (UInt32)sizeof(IntPtr);
      IntPtr* ptr = (IntPtr*)dataBuffer;
      *ptr = (IntPtr)data;
      dataDescriptor->Ptr = (UInt64)ptr;
      break;
    }
    if (rt::is<Int32>(data)) {
      dataDescriptor->Size = 4u;
      Int32* ptr2 = (Int32*)dataBuffer;
      *ptr2 = (Int32)data;
      dataDescriptor->Ptr = (UInt64)ptr2;
      break;
    }
    if (rt::is<Int64>(data)) {
      dataDescriptor->Size = 8u;
      Int64* ptr3 = (Int64*)dataBuffer;
      *ptr3 = (Int64)data;
      dataDescriptor->Ptr = (UInt64)ptr3;
      break;
    }
    if (rt::is<UInt32>(data)) {
      dataDescriptor->Size = 4u;
      UInt32* ptr4 = (UInt32*)dataBuffer;
      *ptr4 = (UInt32)data;
      dataDescriptor->Ptr = (UInt64)ptr4;
      break;
    }
    if (rt::is<UInt64>(data)) {
      dataDescriptor->Size = 8u;
      UInt64* ptr5 = (UInt64*)dataBuffer;
      *ptr5 = (UInt64)data;
      dataDescriptor->Ptr = (UInt64)ptr5;
      break;
    }
    if (rt::is<Char>(data)) {
      dataDescriptor->Size = 2u;
      Char* ptr6 = (Char*)dataBuffer;
      *ptr6 = (Char)data;
      dataDescriptor->Ptr = (UInt64)ptr6;
      break;
    }
    if (rt::is<Byte>(data)) {
      dataDescriptor->Size = 1u;
      Byte* ptr7 = dataBuffer;
      *ptr7 = (Byte)data;
      dataDescriptor->Ptr = (UInt64)ptr7;
      break;
    }
    if (rt::is<Int16>(data)) {
      dataDescriptor->Size = 2u;
      Int16* ptr8 = (Int16*)dataBuffer;
      *ptr8 = (Int16)data;
      dataDescriptor->Ptr = (UInt64)ptr8;
      break;
    }
    if (rt::is<SByte>(data)) {
      dataDescriptor->Size = 1u;
      SByte* ptr9 = (SByte*)dataBuffer;
      *ptr9 = (SByte)data;
      dataDescriptor->Ptr = (UInt64)ptr9;
      break;
    }
    if (rt::is<UInt16>(data)) {
      dataDescriptor->Size = 2u;
      UInt16* ptr10 = (UInt16*)dataBuffer;
      *ptr10 = (UInt16)data;
      dataDescriptor->Ptr = (UInt64)ptr10;
      break;
    }
    if (rt::is<Single>(data)) {
      dataDescriptor->Size = 4u;
      Single* ptr11 = (Single*)dataBuffer;
      *ptr11 = (Single)data;
      dataDescriptor->Ptr = (UInt64)ptr11;
      break;
    }
    if (rt::is<Double>(data)) {
      dataDescriptor->Size = 8u;
      Double* ptr12 = (Double*)dataBuffer;
      *ptr12 = (Double)data;
      dataDescriptor->Ptr = (UInt64)ptr12;
      break;
    }
    if (rt::is<Boolean>(data)) {
      dataDescriptor->Size = 4u;
      Int32* ptr13 = (Int32*)dataBuffer;
      if ((Boolean)data) {
        *ptr13 = 1;
      } else {
        *ptr13 = 0;
      }
      dataDescriptor->Ptr = (UInt64)ptr13;
      break;
    }
    if (rt::is<Guid>(data)) {
      dataDescriptor->Size = (UInt32)sizeof(Guid);
      Guid* ptr14 = (Guid*)dataBuffer;
      *ptr14 = (Guid)data;
      dataDescriptor->Ptr = (UInt64)ptr14;
      break;
    }
    if (rt::is<Decimal>(data)) {
      dataDescriptor->Size = 16u;
      Decimal* ptr15 = (Decimal*)dataBuffer;
      *ptr15 = (Decimal)data;
      dataDescriptor->Ptr = (UInt64)ptr15;
      break;
    }
    if (rt::is<DateTime>(data)) {
      Int64 num = 0;
      if (((DateTime)data).get_Ticks() > 504911232000000000) {
        num = ((DateTime)data).ToFileTimeUtc();
      }
      dataDescriptor->Size = 8u;
      Int64* ptr16 = (Int64*)dataBuffer;
      *ptr16 = num;
      dataDescriptor->Ptr = (UInt64)ptr16;
      break;
    }
    if (rt::is<Enum>(data)) {
      try {
        Type underlyingType = Enum::in::GetUnderlyingType(data->GetType());
        if (underlyingType == typeof<UInt64>()) {
          data = (UInt64)data;
        } else if (underlyingType == typeof<Int64>()) {
          data = (Int64)data;
        } else {
          data = (Int32)Convert::ToInt64(data);
        }

      } catch (...) {
      }
      continue;
    }
    goto IL_0411;

  IL_0411:
    text = ((data != nullptr) ? data->ToString() : "");
    dataDescriptor->Size = (UInt32)((text->get_Length() + 1) * 2);
    break;
  }
  totalEventSize += dataDescriptor->Size;
  dataDescriptor++;
  dataBuffer += 16;
  Object as = ((Object)text);
  return as != nullptr ? as : ((Object)array);
}

Boolean EventProvider___::WriteEvent(EventDescriptor& eventDescriptor, IntPtr eventHandle, Guid* activityID, Guid* childActivityID, Array<Object> eventPayload) {
  WriteEventErrorCode writeEventErrorCode = WriteEventErrorCode::NoError;
  if (IsEnabled(eventDescriptor.get_Level(), eventDescriptor.get_Keywords())) {
    Int32 num = eventPayload->get_Length();
    if (num > 128) {
      s_returnCode = WriteEventErrorCode::TooManyArgs;
      return false;
    }
    UInt32 totalEventSize = 0u;
    Int32 i = 0;
    List<Int32> list = rt::newobj<List<Int32>>(8);
    List<Object> list2 = rt::newobj<List<Object>>(8);
    EventData as[2 * num] = {};
    EventData* ptr = as;
    for (Int32 j = 0; j < 2 * num; j++) {
      *(ptr + j) = rt::default__;
    }
    EventData* dataDescriptor = ptr;
    Byte is[(Int32)(UInt32)(32 * num)] = {};
    Byte* ptr2 = is;
    Byte* dataBuffer = ptr2;
    Boolean flag = false;
    for (Int32 k = 0; k < eventPayload->get_Length(); k++) {
      if (eventPayload[k] != nullptr) {
        Object obj = EncodeObject(eventPayload[k], dataDescriptor, dataBuffer, totalEventSize);
        if (obj == nullptr) {
          continue;
        }
        Int32 num2 = (Int32)(dataDescriptor - ptr - 1);
        if (!rt::is<String>(obj)) {
          if (eventPayload->get_Length() + num2 + 1 - k > 128) {
            s_returnCode = WriteEventErrorCode::TooManyArgs;
            return false;
          }
          flag = true;
        }
        list2->Add(obj);
        list->Add(num2);
        i++;
        continue;
      }
      s_returnCode = WriteEventErrorCode::NullInput;
      return false;
    }
    num = (Int32)(dataDescriptor - ptr);
    if (totalEventSize > 65482) {
      s_returnCode = WriteEventErrorCode::EventTooBig;
      return false;
    }
    if (!flag && i < 8) {
      for (; i < 8; i++) {
        list2->Add(nullptr);
      }
      {
        Char* ptr3 = (String)list2[0];
        Char* ptr4 = ptr3;
        {
          Char* ptr5 = (String)list2[1];
          Char* ptr6 = ptr5;
          {
            Char* ptr7 = (String)list2[2];
            Char* ptr8 = ptr7;
            {
              Char* ptr9 = (String)list2[3];
              Char* ptr10 = ptr9;
              {
                Char* ptr11 = (String)list2[4];
                Char* ptr12 = ptr11;
                {
                  Char* ptr13 = (String)list2[5];
                  Char* ptr14 = ptr13;
                  {
                    Char* ptr15 = (String)list2[6];
                    Char* ptr16 = ptr15;
                    {
                      Char* ptr17 = (String)list2[7];
                      Char* ptr18 = ptr17;
                      dataDescriptor = ptr;
                      if (list2[0] != nullptr) {
                        *(dataDescriptor + list[0]).Ptr = (UInt64)ptr4;
                      }
                      if (list2[1] != nullptr) {
                        *(dataDescriptor + list[1]).Ptr = (UInt64)ptr6;
                      }
                      if (list2[2] != nullptr) {
                        *(dataDescriptor + list[2]).Ptr = (UInt64)ptr8;
                      }
                      if (list2[3] != nullptr) {
                        *(dataDescriptor + list[3]).Ptr = (UInt64)ptr10;
                      }
                      if (list2[4] != nullptr) {
                        *(dataDescriptor + list[4]).Ptr = (UInt64)ptr12;
                      }
                      if (list2[5] != nullptr) {
                        *(dataDescriptor + list[5]).Ptr = (UInt64)ptr14;
                      }
                      if (list2[6] != nullptr) {
                        *(dataDescriptor + list[6]).Ptr = (UInt64)ptr16;
                      }
                      if (list2[7] != nullptr) {
                        *(dataDescriptor + list[7]).Ptr = (UInt64)ptr18;
                      }
                      writeEventErrorCode = m_eventProvider->EventWriteTransfer(m_regHandle, eventDescriptor, eventHandle, activityID, childActivityID, num, ptr);
                    }
                  }
                }
              }
            }
          }
        }
      }
    } else {
      dataDescriptor = ptr;
      Array<GCHandle> array = rt::newarr<Array<GCHandle>>(i);
      for (Int32 l = 0; l < i; l++) {
        array[l] = GCHandle::Alloc(list2[l], GCHandleType::Pinned);
        if (rt::is<String>(list2[l])) {
          {
            Char* ptr19 = (String)list2[l];
            Char* ptr20 = ptr19;
            *(dataDescriptor + list[l]).Ptr = (UInt64)ptr20;
          }
        } else {
          {
            Byte* ptr21 = (Array<Byte>)list2[l];
            *(dataDescriptor + list[l]).Ptr = (UInt64)ptr21;
          }
        }
      }
      writeEventErrorCode = m_eventProvider->EventWriteTransfer(m_regHandle, eventDescriptor, eventHandle, activityID, childActivityID, num, ptr);
      for (Int32 m = 0; m < i; m++) {
        array[m].Free();
      }
    }
  }
  if (writeEventErrorCode != 0) {
    SetLastError(writeEventErrorCode);
    return false;
  }
  return true;
}

Boolean EventProvider___::WriteEvent(EventDescriptor& eventDescriptor, IntPtr eventHandle, Guid* activityID, Guid* childActivityID, Int32 dataCount, IntPtr data) {
  UInt32 num = 0u;
  WriteEventErrorCode writeEventErrorCode = m_eventProvider->EventWriteTransfer(m_regHandle, eventDescriptor, eventHandle, activityID, childActivityID, dataCount, (EventData*)(void*)data);
  if (writeEventErrorCode != 0) {
    SetLastError(writeEventErrorCode);
    return false;
  }
  return true;
}

Boolean EventProvider___::WriteEventRaw(EventDescriptor& eventDescriptor, IntPtr eventHandle, Guid* activityID, Guid* relatedActivityID, Int32 dataCount, IntPtr data) {
  WriteEventErrorCode writeEventErrorCode = m_eventProvider->EventWriteTransfer(m_regHandle, eventDescriptor, eventHandle, activityID, relatedActivityID, dataCount, (EventData*)(void*)data);
  if (writeEventErrorCode != 0) {
    SetLastError(writeEventErrorCode);
    return false;
  }
  return true;
}

UInt32 EventProvider___::EventRegister(EventSource eventSource, Interop::Advapi32::EtwEnableCallback enableCallback) {
  m_providerName = eventSource->get_Name();
  m_providerId = eventSource->get_Guid();
  m_etwCallback = enableCallback;
  return m_eventProvider->EventRegister(eventSource, enableCallback, nullptr, m_regHandle);
}

void EventProvider___::EventUnregister(Int64 registrationHandle) {
  m_eventProvider->EventUnregister(registrationHandle);
}

Int32 EventProvider___::SetInformation(Interop::Advapi32::EVENT_INFO_CLASS eventInfoClass, IntPtr data, UInt32 dataSize) {
  Int32 result = 50;
  if (!m_setInformationMissing) {
    try {
      result = Interop::Advapi32::EventSetInformation(m_regHandle, eventInfoClass, (void*)data, (Int32)dataSize);
      return result;
    } catch (TypeLoadException) {
    }
  }
  return result;
}

} // namespace System::Private::CoreLib::System::Diagnostics::Tracing::EventProviderNamespace
