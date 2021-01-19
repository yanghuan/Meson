#include "EventPipeInternal-dep.h"

#include <System.Private.CoreLib/System/Char-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/EventPipeInternal-dep.h>
#include <System.Private.CoreLib/System/IntPtr-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/Marshal-dep.h>
#include <System.Private.CoreLib/System/Span-dep.h>

namespace System::Private::CoreLib::System::Diagnostics::Tracing::EventPipeInternalNamespace {
using namespace System::Runtime::InteropServices;

void EventPipeInternal::EventPipeProviderConfigurationNative::MarshalToNative(EventPipeProviderConfiguration managed, EventPipeProviderConfigurationNative& native) {
  native.m_pProviderName = (Char*)(void*)Marshal::StringToCoTaskMemUni(managed.get_ProviderName());
  native.m_keywords = managed.get_Keywords();
  native.m_loggingLevel = managed.get_LoggingLevel();
  native.m_pFilterData = (Char*)(void*)Marshal::StringToCoTaskMemUni(managed.get_FilterData());
}

void EventPipeInternal::EventPipeProviderConfigurationNative::Release() {
  if (m_pProviderName != nullptr) {
    Marshal::FreeCoTaskMem((IntPtr)m_pProviderName);
  }
  if (m_pFilterData != nullptr) {
    Marshal::FreeCoTaskMem((IntPtr)m_pFilterData);
  }
}

UInt64 EventPipeInternal::Enable(String outputFile, EventPipeSerializationFormat format, UInt32 circularBufferSizeInMB, Array<EventPipeProviderConfiguration> providers) {
  Span<EventPipeProviderConfigurationNative> span = Span<EventPipeProviderConfigurationNative>((void*)Marshal::AllocCoTaskMem(sizeof(EventPipeProviderConfigurationNative) * providers->get_Length()), providers->get_Length());
  span.Clear();
  try {
    for (Int32 i = 0; i < providers->get_Length(); i++) {
      EventPipeProviderConfigurationNative::MarshalToNative(providers[i], span[i]);
    }
    {
      Char* ptr = outputFile;
      Char* outputFile2 = ptr;
      {
        EventPipeProviderConfigurationNative* providers2 = span;
        return Enable(outputFile2, format, circularBufferSizeInMB, providers2, (UInt32)span.get_Length());
      }
    }
  } catch (...) {
  } finally: {
    for (Int32 j = 0; j < providers->get_Length(); j++) {
      span[j].Release();
    }
    {
      EventPipeProviderConfigurationNative* value = span;
      Marshal::FreeCoTaskMem((IntPtr)value);
    }
  }
}

} // namespace System::Private::CoreLib::System::Diagnostics::Tracing::EventPipeInternalNamespace
