#include "ComEventsInfo-dep.h"

#include <System.Private.CoreLib/System/Runtime/InteropServices/ComEventsInfo-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/ComEventsSink-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/Marshal-dep.h>

namespace System::Private::CoreLib::System::Runtime::InteropServices::ComEventsInfoNamespace {
void ComEventsInfo___::ctor(Object rcw) {
  _rcw = rcw;
}

void ComEventsInfo___::Finalize() {
  _sinks = ComEventsSink::in::RemoveAll(_sinks);
}

ComEventsInfo ComEventsInfo___::Find(Object rcw) {
  return (ComEventsInfo)Marshal::GetComObjectData(rcw, rt::typeof<ComEventsInfo>());
}

ComEventsInfo ComEventsInfo___::FromObject(Object rcw) {
  ComEventsInfo comEventsInfo = Find(rcw);
  if (comEventsInfo == nullptr) {
    comEventsInfo = rt::newobj<ComEventsInfo>(rcw);
    Marshal::SetComObjectData(rcw, rt::typeof<ComEventsInfo>(), comEventsInfo);
  }
  return comEventsInfo;
}

ComEventsSink ComEventsInfo___::FindSink(Guid& iid) {
  return ComEventsSink::in::Find(_sinks, iid);
}

ComEventsSink ComEventsInfo___::AddSink(Guid& iid) {
  ComEventsSink sink = rt::newobj<ComEventsSink>(_rcw, iid);
  _sinks = ComEventsSink::in::Add(_sinks, sink);
  return _sinks;
}

ComEventsSink ComEventsInfo___::RemoveSink(ComEventsSink sink) {
  _sinks = ComEventsSink::in::Remove(_sinks, sink);
  return _sinks;
}

} // namespace System::Private::CoreLib::System::Runtime::InteropServices::ComEventsInfoNamespace
