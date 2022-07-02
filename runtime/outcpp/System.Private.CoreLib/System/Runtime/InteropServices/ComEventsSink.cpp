#include "ComEventsSink-dep.h"

#include <System.Private.CoreLib/System/Boolean-dep.h>
#include <System.Private.CoreLib/System/NotImplementedException-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/ComEventsSink-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/ComTypes/IConnectionPoint.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/ComTypes/IConnectionPointContainer.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/CustomQueryInterfaceMode.h>
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

Int32 ComEventsSink___::GetTypeInfoCountOfIDispatch() {
  return 0;
}

ITypeInfo ComEventsSink___::GetTypeInfoOfIDispatch(Int32 iTInfo, Int32 lcid) {
  rt::throw_exception<NotImplementedException>();
}

void ComEventsSink___::GetIDsOfNamesOfIDispatch(Guid& iid, Array<String> names, Int32 cNames, Int32 lcid, Array<Int32> rgDispId) {
  rt::throw_exception<NotImplementedException>();
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

void ComEventsSink___::InvokeOfIDispatch(Int32 dispid, Guid& riid, Int32 lcid, InvokeFlags wFlags, DISPPARAMS& pDispParams, IntPtr pVarResult, IntPtr pExcepInfo, IntPtr puArgErr) {
  ComEventsMethod comEventsMethod = FindMethod(dispid);
  if (comEventsMethod == nullptr) {
    return;
  }
  Array<Object> array = rt::newarr<Array<Object>>(pDispParams.cArgs);
  Array<Int32> array2 = rt::newarr<Array<Int32>>(pDispParams.cArgs);
  Array<Boolean> array3 = rt::newarr<Array<Boolean>>(pDispParams.cArgs);
  Int32 length = pDispParams.cNamedArgs + pDispParams.cArgs;
  Span<Variant> span = Span<Variant>(pDispParams.rgvarg.ToPointer(), length);
  Span<Int32> span2 = Span<Int32>(pDispParams.rgdispidNamedArgs.ToPointer(), length);
  Int32 num;
  Int32 i;
  for (i = 0; i < pDispParams.cNamedArgs; i++) {
    num = span2[i];
    Variant& variant = GetVariant(span[i]);
    array[num] = variant.ToObject();
    array3[num] = true;
    Int32 num2 = -1;
    if (variant.get_IsByRef()) {
      num2 = i;
    }
    array2[num] = num2;
  }
  num = 0;
  for (; i < pDispParams.cArgs; i++) {
    for (; array3[num]; num++) {
    }
    Variant& variant2 = GetVariant(span[pDispParams.cArgs - 1 - i]);
    array[num] = variant2.ToObject();
    Int32 num3 = -1;
    if (variant2.get_IsByRef()) {
      num3 = pDispParams.cArgs - 1 - i;
    }
    array2[num] = num3;
    num++;
  }
  Object obj = comEventsMethod->Invoke(array);
  if (pVarResult != IntPtr::Zero) {
    Marshal::GetNativeVariantForObject(obj, pVarResult);
  }
  for (i = 0; i < pDispParams.cArgs; i++) {
    Int32 num4 = array2[i];
    if (num4 != -1) {
      GetVariant(span[num4]).CopyFromIndirect(array[i]);
    }
  }
}

CustomQueryInterfaceResult ComEventsSink___::GetInterfaceOfICustomQueryInterface(Guid& iid, IntPtr& ppv) {
  ppv = IntPtr::Zero;
  if (iid == _iidSourceItf || iid == typeof<IDispatch>()->get_GUID()) {
    ppv = Marshal::GetComInterfaceForObject((ComEventsSink)this, typeof<IDispatch>(), CustomQueryInterfaceMode::Ignore);
    return CustomQueryInterfaceResult::Handled;
  }
  return CustomQueryInterfaceResult::NotHandled;
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
  try {
    _connectionPoint->Unadvise(_cookie);
    Marshal::ReleaseComObject(_connectionPoint);
  } catch (...) {
  } finally: {
    _connectionPoint = nullptr;
  }
}

} // namespace System::Private::CoreLib::System::Runtime::InteropServices::ComEventsSinkNamespace
