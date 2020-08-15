#include "ComEventsMethod-dep.h"

#include <System.Private.CoreLib/System/Collections/Generic/List-dep.h>
#include <System.Private.CoreLib/System/Enum-dep.h>
#include <System.Private.CoreLib/System/Int32-dep.h>
#include <System.Private.CoreLib/System/Reflection/ParameterInfo-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/ComEventsMethod-dep.h>
#include <System.Private.CoreLib/System/Type-dep.h>

namespace System::Private::CoreLib::System::Runtime::InteropServices::ComEventsMethodNamespace {
using namespace System::Collections::Generic;
using namespace System::Reflection;

void ComEventsMethod___::DelegateWrapper___::ctor(System::Delegate d, Boolean wrapArgs) {
  Delegate = d;
  WrapArgs = wrapArgs;
}

Object ComEventsMethod___::DelegateWrapper___::Invoke(Array<Object> args) {
  if ((Object)Delegate == nullptr) {
    return nullptr;
  }
  if (!_once) {
    PreProcessSignature();
    _once = true;
  }
  if (_cachedTargetTypes != nullptr && _expectedParamsCount == args->get_Length()) {
    for (Int32 i = 0; i < _expectedParamsCount; i++) {
      if (_cachedTargetTypes[i] != nullptr) {
        args[i] = Enum::in::ToObject(_cachedTargetTypes[i], args[i]);
      }
    }
  }
  return Delegate->DynamicInvoke(rt::newarr<Array<Object>>(1, (!WrapArgs) ? args : rt::newarr<Array<Object>>(1)));
}

void ComEventsMethod___::DelegateWrapper___::PreProcessSignature() {
  Array<ParameterInfo> parameters = Delegate->get_Method()->GetParameters();
  _expectedParamsCount = parameters->get_Length();
  Array<Type> array = nullptr;
  for (Int32 i = 0; i < _expectedParamsCount; i++) {
    ParameterInfo parameterInfo = parameters[i];
    if (parameterInfo->get_ParameterType()->get_IsByRef() && parameterInfo->get_ParameterType()->get_HasElementType() && parameterInfo->get_ParameterType()->GetElementType()->get_IsEnum()) {
      if (array == nullptr) {
        array = rt::newarr<Array<Type>>(_expectedParamsCount);
      }
      array[i] = parameterInfo->get_ParameterType()->GetElementType();
    }
  }
  if (array != nullptr) {
    _cachedTargetTypes = array;
  }
}

Boolean ComEventsMethod___::get_Empty() {
  {
    rt::lock(_delegateWrappers);
    return _delegateWrappers->get_Count() == 0;
  }
}

void ComEventsMethod___::ctor(Int32 dispid) {
  _delegateWrappers = rt::newobj<List<DelegateWrapper>>();
  Object::in::ctor();
  _dispid = dispid;
}

ComEventsMethod ComEventsMethod___::Find(ComEventsMethod methods, Int32 dispid) {
  while (methods != nullptr && methods->_dispid != dispid) {
    methods = methods->_next;
  }
  return methods;
}

ComEventsMethod ComEventsMethod___::Add(ComEventsMethod methods, ComEventsMethod method) {
  method->_next = methods;
  return method;
}

ComEventsMethod ComEventsMethod___::Remove(ComEventsMethod methods, ComEventsMethod method) {
  if (methods == method) {
    return methods->_next;
  }
  ComEventsMethod comEventsMethod = methods;
  while (comEventsMethod != nullptr && comEventsMethod->_next != method) {
    comEventsMethod = comEventsMethod->_next;
  }
  if (comEventsMethod != nullptr) {
    comEventsMethod->_next = method->_next;
  }
  return methods;
}

void ComEventsMethod___::AddDelegate(Delegate d, Boolean wrapArgs) {
  {
    rt::lock(_delegateWrappers);
  }
}

void ComEventsMethod___::RemoveDelegate(Delegate d, Boolean wrapArgs) {
  {
    rt::lock(_delegateWrappers);
    Int32 num = -1;
    DelegateWrapper delegateWrapper = nullptr;
    for (Int32 i = 0; i < _delegateWrappers->get_Count(); i++) {
      DelegateWrapper delegateWrapper2 = _delegateWrappers[i];
      if (delegateWrapper2->get_Delegate()->GetType() == d->GetType() && delegateWrapper2->get_WrapArgs() == wrapArgs) {
        num = i;
        delegateWrapper = delegateWrapper2;
        break;
      }
    }
    if (num >= 0) {
      Delegate delegate = Delegate::in::Remove(delegateWrapper->get_Delegate(), d);
      if ((Object)delegate != nullptr) {
        delegateWrapper->set_Delegate = delegate;
      } else {
        _delegateWrappers->RemoveAt(num);
      }
    }
  }
}

Object ComEventsMethod___::Invoke(Array<Object> args) {
  Object result = nullptr;
  {
    rt::lock(_delegateWrappers);
  }
}

} // namespace System::Private::CoreLib::System::Runtime::InteropServices::ComEventsMethodNamespace
