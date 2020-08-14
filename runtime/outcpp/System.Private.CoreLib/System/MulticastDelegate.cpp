#include "MulticastDelegate-dep.h"

#include <System.Private.CoreLib/Internal/Runtime/CompilerServices/Unsafe-dep.h>
#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/Int32-dep.h>
#include <System.Private.CoreLib/System/IntPtr-dep.h>
#include <System.Private.CoreLib/System/IRuntimeMethodInfo.h>
#include <System.Private.CoreLib/System/MulticastDelegate-dep.h>
#include <System.Private.CoreLib/System/Reflection/Emit/DynamicResolver-dep.h>
#include <System.Private.CoreLib/System/Reflection/LoaderAllocator-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/GCHandle-dep.h>
#include <System.Private.CoreLib/System/Runtime/Serialization/SerializationException-dep.h>
#include <System.Private.CoreLib/System/RuntimeMethodHandle-dep.h>
#include <System.Private.CoreLib/System/RuntimeType-dep.h>
#include <System.Private.CoreLib/System/RuntimeTypeHandle-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/Threading/Interlocked-dep.h>
#include <System.Private.CoreLib/System/ValueType-dep.h>

namespace System::Private::CoreLib::System::MulticastDelegateNamespace {
using namespace Internal::Runtime::CompilerServices;
using namespace System::Reflection;
using namespace System::Reflection::Emit;
using namespace System::Runtime::InteropServices;
using namespace System::Runtime::Serialization;
using namespace System::Threading;

void MulticastDelegate___::ctor(Object target, String method) {
}

void MulticastDelegate___::ctor(Type target, String method) {
}

Boolean MulticastDelegate___::IsUnmanagedFunctionPtr() {
  return _invocationCount == (IntPtr)(-1);
}

Boolean MulticastDelegate___::InvocationListLogicallyNull() {
  if (_invocationList != nullptr && !rt::is<LoaderAllocator>(_invocationList)) {
    return rt::is<DynamicResolver>(_invocationList);
  }
  return true;
}

void MulticastDelegate___::GetObjectData(SerializationInfo info, StreamingContext context) {
  rt::throw_exception<SerializationException>(SR::get_Serialization_DelegatesNotSupported());
}

Boolean MulticastDelegate___::Equals(Object obj) {
  if (obj == nullptr) {
    return false;
  }
  if ((MulticastDelegate)this == obj) {
    return true;
  }
  if (!Delegate::in::InternalEqualTypes((MulticastDelegate)this, obj)) {
    return false;
  }
  MulticastDelegate multicastDelegate = Unsafe::As<MulticastDelegate>(obj);
  if (_invocationCount != (IntPtr)0) {
    if (InvocationListLogicallyNull()) {
      if (IsUnmanagedFunctionPtr()) {
        if (!multicastDelegate->IsUnmanagedFunctionPtr()) {
          return false;
        }
        return Delegate::in::CompareUnmanagedFunctionPtrs((MulticastDelegate)this, multicastDelegate);
      }
      if (rt::is<Delegate>(multicastDelegate->_invocationList)) {
        return Equals(multicastDelegate->_invocationList);
      }
      return Delegate::Equals(obj);
    }
  }
  if (!InvocationListLogicallyNull()) {
    if (!_invocationList->Equals(multicastDelegate->_invocationList)) {
      return false;
    }
    return Delegate::Equals((Object)multicastDelegate);
  }
  if (rt::is<Delegate>(multicastDelegate->_invocationList)) {
    return Equals(multicastDelegate->_invocationList);
  }
  return Delegate::Equals((Object)multicastDelegate);
}

Boolean MulticastDelegate___::InvocationListEquals(MulticastDelegate d) {
  Array<Object> array = (Array<Object>)_invocationList;
  if (d->_invocationCount != _invocationCount) {
    return false;
  }
  Int32 num = (Int32)_invocationCount;
  for (Int32 i = 0; i < num; i++) {
    Delegate delegate = (Delegate)array[i];
    Array<Object> array2 = rt::as<Array<Object>>(d->_invocationList);
    if (!delegate->Equals(array2[i])) {
      return false;
    }
  }
  return true;
}

Boolean MulticastDelegate___::TrySetSlot(Array<Object> a, Int32 index, Object o) {
  if (a[index] == nullptr && Interlocked::CompareExchange<Object>(a[index], o, (Object)nullptr) == nullptr) {
    return true;
  }
  if (a[index] != nullptr) {
    MulticastDelegate multicastDelegate = (MulticastDelegate)o;
    MulticastDelegate multicastDelegate2 = (MulticastDelegate)a[index];
    if (multicastDelegate2->_methodPtr == multicastDelegate->_methodPtr && multicastDelegate2->_target == multicastDelegate->_target && multicastDelegate2->_methodPtrAux == multicastDelegate->_methodPtrAux) {
      return true;
    }
  }
  return false;
}

MulticastDelegate MulticastDelegate___::NewMulticastDelegate(Array<Object> invocationList, Int32 invocationCount, Boolean thisIsMultiCastAlready) {
  MulticastDelegate multicastDelegate = Delegate::in::InternalAllocLike((MulticastDelegate)this);
  if (thisIsMultiCastAlready) {
    multicastDelegate->_methodPtr = _methodPtr;
    multicastDelegate->_methodPtrAux = _methodPtrAux;
  } else {
    multicastDelegate->_methodPtr = GetMulticastInvoke();
    multicastDelegate->_methodPtrAux = GetInvokeMethod();
  }
  multicastDelegate->_target = multicastDelegate;
  multicastDelegate->_invocationList = invocationList;
  multicastDelegate->_invocationCount = (IntPtr)invocationCount;
  return multicastDelegate;
}

MulticastDelegate MulticastDelegate___::NewMulticastDelegate(Array<Object> invocationList, Int32 invocationCount) {
  return NewMulticastDelegate(invocationList, invocationCount, false);
}

void MulticastDelegate___::StoreDynamicMethod(MethodInfo dynamicMethod) {
  if (_invocationCount != (IntPtr)0) {
    MulticastDelegate multicastDelegate = (MulticastDelegate)_invocationList;
    multicastDelegate->_methodBase = dynamicMethod;
  } else {
    _methodBase = dynamicMethod;
  }
}

Delegate MulticastDelegate___::CombineImpl(Delegate follow) {
  if ((Object)follow == nullptr) {
    return (MulticastDelegate)this;
  }
  if (!Delegate::in::InternalEqualTypes((MulticastDelegate)this, follow)) {
    rt::throw_exception<ArgumentException>(SR::get_Arg_DlgtTypeMis());
  }
  MulticastDelegate multicastDelegate = (MulticastDelegate)follow;
  Int32 num = 1;
  Array<Object> array = rt::as<Array<Object>>(multicastDelegate->_invocationList);
  if (array != nullptr) {
    num = (Int32)multicastDelegate->_invocationCount;
  }
  Array<Object> array2 = rt::as<Array<Object>>(_invocationList);
  Int32 num2;
  Array<Object> array3;
  if (array2 == nullptr) {
    num2 = 1 + num;
    array3 = rt::newarr<Array<Object>>(num2);
    array3[0] = (MulticastDelegate)this;
    if (array == nullptr) {
      array3[1] = multicastDelegate;
    } else {
      for (Int32 i = 0; i < num; i++) {
        array3[1 + i] = array[i];
      }
    }
    return NewMulticastDelegate(array3, num2);
  }
  Int32 num3 = (Int32)_invocationCount;
  num2 = num3 + num;
  array3 = nullptr;
  if (num2 <= array2->get_Length()) {
    array3 = array2;
    if (array == nullptr) {
      if (!TrySetSlot(array3, num3, multicastDelegate)) {
        array3 = nullptr;
      }
    } else {
      for (Int32 j = 0; j < num; j++) {
        if (!TrySetSlot(array3, num3 + j, array[j])) {
          array3 = nullptr;
          break;
        }
      }
    }
  }
  if (array3 == nullptr) {
    Int32 num4;
    for (num4 = array2->get_Length(); num4 < num2; num4 *= 2) {
    }
    array3 = rt::newarr<Array<Object>>(num4);
    for (Int32 k = 0; k < num3; k++) {
      array3[k] = array2[k];
    }
    if (array == nullptr) {
      array3[num3] = multicastDelegate;
    } else {
      for (Int32 l = 0; l < num; l++) {
        array3[num3 + l] = array[l];
      }
    }
  }
  return NewMulticastDelegate(array3, num2, true);
}

Array<Object> MulticastDelegate___::DeleteFromInvocationList(Array<Object> invocationList, Int32 invocationCount, Int32 deleteIndex, Int32 deleteCount) {
  Array<Object> array = (Array<Object>)_invocationList;
  Int32 num = array->get_Length();
  while (num / 2 >= invocationCount - deleteCount) {
    num /= 2;
  }
  Array<Object> array2 = rt::newarr<Array<Object>>(num);
  for (Int32 i = 0; i < deleteIndex; i++) {
    array2[i] = invocationList[i];
  }
  for (Int32 j = deleteIndex + deleteCount; j < invocationCount; j++) {
    array2[j - deleteCount] = invocationList[j];
  }
  return array2;
}

Boolean MulticastDelegate___::EqualInvocationLists(Array<Object> a, Array<Object> b, Int32 start, Int32 count) {
  for (Int32 i = 0; i < count; i++) {
    if (!a[start + i]->Equals(b[i])) {
      return false;
    }
  }
  return true;
}

Delegate MulticastDelegate___::RemoveImpl(Delegate value) {
  MulticastDelegate multicastDelegate = rt::as<MulticastDelegate>(value);
  if ((Object)multicastDelegate == nullptr) {
    return (MulticastDelegate)this;
  }
  if (!rt::is<Array<Object>>(multicastDelegate->_invocationList)) {
    Array<Object> array = rt::as<Array<Object>>(_invocationList);
    if (array == nullptr) {
      if (Equals(value)) {
        return nullptr;
      }
    } else {
      Int32 num = (Int32)_invocationCount;
      Int32 num2 = num;
      while (--num2 >= 0) {
        if (value->Equals(array[num2])) {
          if (num == 2) {
            return (Delegate)array[1 - num2];
          }
          Array<Object> invocationList = DeleteFromInvocationList(array, num, num2, 1);
          return NewMulticastDelegate(invocationList, num - 1, true);
        }
      }
    }
  } else {
    Array<Object> array2 = rt::as<Array<Object>>(_invocationList);
    if (array2 != nullptr) {
      Int32 num3 = (Int32)_invocationCount;
      Int32 num4 = (Int32)multicastDelegate->_invocationCount;
      for (Int32 num5 = num3 - num4; num5 >= 0; num5--) {
        if (EqualInvocationLists(array2, rt::as<Array<Object>>(multicastDelegate->_invocationList), num5, num4)) {
          if (num3 - num4 == 0) {
            return nullptr;
          }
          if (num3 - num4 == 1) {
            return (Delegate)array2[(num5 == 0) ? (num3 - 1) : 0];
          }
          Array<Object> invocationList2 = DeleteFromInvocationList(array2, num3, num5, num4);
          return NewMulticastDelegate(invocationList2, num3 - num4, true);
        }
      }
    }
  }
  return (MulticastDelegate)this;
}

Array<Delegate> MulticastDelegate___::GetInvocationList() {
  Array<Object> array = rt::as<Array<Object>>(_invocationList);
  Array<Delegate> array2;
  if (array == nullptr) {
    array2 = rt::newarr<Array<Delegate>>(1);
  } else {
    array2 = rt::newarr<Array<Delegate>>((Int32)_invocationCount);
    for (Int32 i = 0; i < array2->get_Length(); i++) {
      array2[i] = (Delegate)array[i];
    }
  }
  return array2;
}

Boolean MulticastDelegate___::op_Equality(MulticastDelegate d1, MulticastDelegate d2) {
  if ((Object)d2 == nullptr) {
    if ((Object)d1 != nullptr) {
      return false;
    }
    return true;
  }
  if ((Object)d2 != d1) {
    return d2->Equals(d1);
  }
  return true;
}

Boolean MulticastDelegate___::op_Inequality(MulticastDelegate d1, MulticastDelegate d2) {
  if ((Object)d2 == nullptr) {
    if ((Object)d1 != nullptr) {
      return true;
    }
    return false;
  }
  if ((Object)d2 != d1) {
    return !d2->Equals(d1);
  }
  return false;
}

Int32 MulticastDelegate___::GetHashCode() {
  if (IsUnmanagedFunctionPtr()) {
    return ValueType::in::GetHashCodeOfPtr(_methodPtr) ^ ValueType::in::GetHashCodeOfPtr(_methodPtrAux);
  }
  if (_invocationCount != (IntPtr)0) {
    Delegate delegate = rt::as<Delegate>(_invocationList);
    if ((Object)delegate != nullptr) {
      return delegate->GetHashCode();
    }
  }
  Array<Object> array = rt::as<Array<Object>>(_invocationList);
  if (array == nullptr) {
    return Delegate::GetHashCode();
  }
  Int32 num = 0;
  for (Int32 i = 0; i < (Int32)_invocationCount; i++) {
    num = num * 33 + array[i]->GetHashCode();
  }
  return num;
}

Object MulticastDelegate___::GetTarget() {
  if (_invocationCount != (IntPtr)0) {
    if (InvocationListLogicallyNull()) {
      return nullptr;
    }
    Array<Object> array = rt::as<Array<Object>>(_invocationList);
    if (array != nullptr) {
      Int32 num = (Int32)_invocationCount;
      return ((Delegate)array[num - 1])->GetTarget();
    }
    Delegate delegate = rt::as<Delegate>(_invocationList);
    if ((Object)delegate != nullptr) {
      return delegate->GetTarget();
    }
  }
  return Delegate::GetTarget();
}

MethodInfo MulticastDelegate___::GetMethodImpl() {
  if (_invocationCount != (IntPtr)0 && _invocationList != nullptr) {
    Array<Object> array = rt::as<Array<Object>>(_invocationList);
    if (array != nullptr) {
      Int32 num = (Int32)_invocationCount - 1;
      return ((Delegate)array[num])->get_Method();
    }
    MulticastDelegate multicastDelegate = rt::as<MulticastDelegate>(_invocationList);
    if ((Object)multicastDelegate != nullptr) {
      return multicastDelegate->GetMethodImpl();
    }
  } else if (IsUnmanagedFunctionPtr()) {
    if (_methodBase == nullptr || !rt::is<MethodInfo>(_methodBase)) {
      IRuntimeMethodInfo runtimeMethodInfo = FindMethodHandle();
      RuntimeType runtimeType = RuntimeMethodHandle::GetDeclaringType(runtimeMethodInfo);
      if (RuntimeTypeHandle::IsGenericTypeDefinition(runtimeType) || RuntimeTypeHandle::HasInstantiation(runtimeType)) {
        RuntimeType runtimeType2 = (RuntimeType)GetType();
        runtimeType = runtimeType2;
      }
      _methodBase = (MethodInfo)RuntimeType::in::GetMethodBase(runtimeType, runtimeMethodInfo);
    }
    return (MethodInfo)_methodBase;
  }

  return Delegate::GetMethodImpl();
}

void MulticastDelegate___::ThrowNullThisInDelegateToInstance() {
  rt::throw_exception<ArgumentException>(SR::get_Arg_DlgtNullInst());
}

void MulticastDelegate___::CtorClosed(Object target, IntPtr methodPtr) {
  if (target == nullptr) {
    ThrowNullThisInDelegateToInstance();
  }
  _target = target;
  _methodPtr = methodPtr;
}

void MulticastDelegate___::CtorClosedStatic(Object target, IntPtr methodPtr) {
  _target = target;
  _methodPtr = methodPtr;
}

void MulticastDelegate___::CtorRTClosed(Object target, IntPtr methodPtr) {
  _target = target;
  _methodPtr = AdjustTarget(target, methodPtr);
}

void MulticastDelegate___::CtorOpened(Object target, IntPtr methodPtr, IntPtr shuffleThunk) {
  _target = (MulticastDelegate)this;
  _methodPtr = shuffleThunk;
  _methodPtrAux = methodPtr;
}

void MulticastDelegate___::CtorVirtualDispatch(Object target, IntPtr methodPtr, IntPtr shuffleThunk) {
  _target = (MulticastDelegate)this;
  _methodPtr = shuffleThunk;
  _methodPtrAux = GetCallStub(methodPtr);
}

void MulticastDelegate___::CtorCollectibleClosedStatic(Object target, IntPtr methodPtr, IntPtr gchandle) {
  _target = target;
  _methodPtr = methodPtr;
  _methodBase = GCHandle::InternalGet(gchandle);
}

void MulticastDelegate___::CtorCollectibleOpened(Object target, IntPtr methodPtr, IntPtr shuffleThunk, IntPtr gchandle) {
  _target = (MulticastDelegate)this;
  _methodPtr = shuffleThunk;
  _methodPtrAux = methodPtr;
  _methodBase = GCHandle::InternalGet(gchandle);
}

void MulticastDelegate___::CtorCollectibleVirtualDispatch(Object target, IntPtr methodPtr, IntPtr shuffleThunk, IntPtr gchandle) {
  _target = (MulticastDelegate)this;
  _methodPtr = shuffleThunk;
  _methodPtrAux = GetCallStub(methodPtr);
  _methodBase = GCHandle::InternalGet(gchandle);
}

} // namespace System::Private::CoreLib::System::MulticastDelegateNamespace
