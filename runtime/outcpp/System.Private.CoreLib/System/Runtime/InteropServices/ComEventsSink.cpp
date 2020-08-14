#include "ComEventsSink-dep.h"

#include <System.Private.CoreLib/System/Runtime/InteropServices/ComEventsSink-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/ComTypes/IConnectionPoint.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/ComTypes/IConnectionPointContainer.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/Marshal-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/VarEnum.h>
#include <System.Private.CoreLib/System/Span-dep.h>

namespace System::Private::CoreLib::System::Runtime::InteropServices::ComEventsSinkNamespace {
using namespace System::Runtime::InteropServices::ComTypes;

void ComEventsSink___::ctor(Object rcw, Guid iid) {
  _iidSourceItf = iid;
  Advise(rcw);
}

ComEventsSink ComEventsSink___::Find(ComEventsSink sinks, Guid& iid) {
  ComEventsSink comEventsSink = sinks;
  while (comEventsSink != nullptr && comEventsSink->_iidSourceItf != iid) {
    comEventsSink = comEventsSink->_next;
  }
  return comEventsSink;
}

ComEventsSink ComEventsSink___::Add(ComEventsSink sinks, ComEventsSink sink) {
  sink->_next = sinks;
  return sink;
}

ComEventsSink ComEventsSink___::RemoveAll(ComEventsSink sinks) {
  while (sinks != nullptr) {
    sinks->Unadvise();
    sinks = sinks->_next;
  }
  return nullptr;
}

ComEventsSink ComEventsSink___::Remove(ComEventsSink sinks, ComEventsSink sink) {
  ComEventsSink result = sinks;
  if (sink == sinks) {
    result = sinks->_next;
  } else {
    ComEventsSink comEventsSink = sinks;
    while (comEventsSink != nullptr && comEventsSink->_next != sink) {
      comEventsSink = comEventsSink->_next;
    }
    if (comEventsSink != nullptr) {
      comEventsSink->_next = sink->_next;
    }
  }
  sink->Unadvise();
  return result;
}

ComEventsMethod ComEventsSink___::RemoveMethod(ComEventsMethod method) {
  _methods = ComEventsMethod::in::Remove(_methods, method);
  return _methods;
}

ComEventsMethod ComEventsSink___::FindMethod(Int32 dispid) {
  return ComEventsMethod::in::Find(_methods, dispid);
}

ComEventsMethod ComEventsSink___::AddMethod(Int32 dispid) {
  ComEventsMethod comEventsMethod = rt::newobj<ComEventsMethod>(dispid);
  _methods = ComEventsMethod::in::Add(_methods, comEventsMethod);
  return comEventsMethod;
}

Variant& ComEventsSink___::GetVariant(Variant& pSrc) {
  if (pSrc.get_VariantType() == (VarEnum)16396) {
    Span<Variant> span = Span<Variant>(pSrc.get_AsByRefVariant().ToPointer(), 1);
    if ((span[0].get_VariantType() & (VarEnum)20479) == (VarEnum)16396) {
      return span[0];
    }
  }
  return pSrc;
}

void ComEventsSink___::Advise(Object rcw) {
  IConnectionPointContainer connectionPointContainer = (IConnectionPointContainer)rcw;
  IConnectionPoint ppCP;
  connectionPointContainer->FindConnectionPoint(_iidSourceItf, ppCP);
  ppCP->Advise((ComEventsSink)this, _cookie);
  _connectionPoint = ppCP;
}

void ComEventsSink___::Unadvise() {
  if (_connectionPoint == nullptr) {
    return;
  }
  try{
    _connectionPoint->Unadvise(_cookie);
    Marshal::ReleaseComObject(_connectionPoint);
  } catch (...) {
  } finally: {
    _connectionPoint = nullptr;
  }
}

} // namespace System::Private::CoreLib::System::Runtime::InteropServices::ComEventsSinkNamespace
