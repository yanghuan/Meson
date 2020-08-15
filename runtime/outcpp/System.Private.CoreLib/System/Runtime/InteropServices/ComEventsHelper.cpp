#include "ComEventsHelper-dep.h"

#include <System.Private.CoreLib/System/GC-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/ComEventsInfo-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/ComEventsMethod-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/ComEventsSink-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/Marshal-dep.h>

namespace System::Private::CoreLib::System::Runtime::InteropServices::ComEventsHelperNamespace {
void ComEventsHelper::Combine(Object rcw, Guid iid, Int32 dispid, Delegate d) {
  {
    rt::lock(rcw);
    ComEventsInfo comEventsInfo = ComEventsInfo::in::FromObject(rcw);
    auto& default = comEventsInfo->FindSink(iid);
    ComEventsSink comEventsSink = default != nullptr ? default : comEventsInfo->AddSink(iid);
    auto& extern = comEventsSink->FindMethod(dispid);
    ComEventsMethod comEventsMethod = extern != nullptr ? extern : comEventsSink->AddMethod(dispid);
    comEventsMethod->AddDelegate(d);
  }
}

Delegate ComEventsHelper::Remove(Object rcw, Guid iid, Int32 dispid, Delegate d) {
  {
    rt::lock(rcw);
    ComEventsInfo comEventsInfo = ComEventsInfo::in::Find(rcw);
    if (comEventsInfo == nullptr) {
      return nullptr;
    }
    ComEventsSink comEventsSink = comEventsInfo->FindSink(iid);
    if (comEventsSink == nullptr) {
      return nullptr;
    }
    ComEventsMethod comEventsMethod = comEventsSink->FindMethod(dispid);
    if (comEventsMethod == nullptr) {
      return nullptr;
    }
    comEventsMethod->RemoveDelegate(d);
    if (comEventsMethod->get_Empty()) {
      comEventsMethod = comEventsSink->RemoveMethod(comEventsMethod);
    }
    if (comEventsMethod == nullptr) {
      comEventsSink = comEventsInfo->RemoveSink(comEventsSink);
    }
    if (comEventsSink == nullptr) {
      Marshal::SetComObjectData(rcw, rt::typeof<ComEventsInfo>(), nullptr);
      GC::SuppressFinalize(comEventsInfo);
    }
    return d;
  }
}

} // namespace System::Private::CoreLib::System::Runtime::InteropServices::ComEventsHelperNamespace
