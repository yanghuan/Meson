#include "Delegate-dep.h"

#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/Delegate-dep.h>
#include <System.Private.CoreLib/System/DelegateBindingFlags.h>
#include <System.Private.CoreLib/System/IntPtr-dep.h>
#include <System.Private.CoreLib/System/IRuntimeMethodInfo.h>
#include <System.Private.CoreLib/System/MulticastNotSupportedException-dep.h>
#include <System.Private.CoreLib/System/PlatformNotSupportedException-dep.h>
#include <System.Private.CoreLib/System/Reflection/BindingFlags.h>
#include <System.Private.CoreLib/System/Reflection/MethodAttributes.h>
#include <System.Private.CoreLib/System/Reflection/RuntimeMethodInfo-dep.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/RuntimeHelpers-dep.h>
#include <System.Private.CoreLib/System/RuntimeMethodHandle-dep.h>
#include <System.Private.CoreLib/System/RuntimeMethodHandleInternal-dep.h>
#include <System.Private.CoreLib/System/RuntimeType-dep.h>
#include <System.Private.CoreLib/System/RuntimeTypeHandle-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>

namespace System::Private::CoreLib::System::DelegateNamespace {
using namespace System::Reflection;
using namespace System::Runtime::CompilerServices;

Object Delegate___::get_Target() {
  return GetTarget();
}

MethodInfo Delegate___::get_Method() {
  return GetMethodImpl();
}

void Delegate___::ctor(Object target, String method) {
  if (target == nullptr) {
    rt::throw_exception<ArgumentNullException>("target");
  }
  if (method == nullptr) {
    rt::throw_exception<ArgumentNullException>("method");
  }
  if (!BindToMethodName(target, (RuntimeType)target->GetType(), method, (DelegateBindingFlags)10)) {
    rt::throw_exception<ArgumentException>(SR::get_Arg_DlgtTargMeth());
  }
}

void Delegate___::ctor(Type target, String method) {
  if (target == nullptr) {
    rt::throw_exception<ArgumentNullException>("target");
  }
  if (target->get_ContainsGenericParameters()) {
    rt::throw_exception<ArgumentException>(SR::get_Arg_UnboundGenParam(), "target");
  }
  if (method == nullptr) {
    rt::throw_exception<ArgumentNullException>("method");
  }
  RuntimeType runtimeType = rt::as<RuntimeType>(target);
  if ((Object)runtimeType == nullptr) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_MustBeRuntimeType(), "target");
  }
  BindToMethodName(nullptr, runtimeType, method, (DelegateBindingFlags)37);
}

Object Delegate___::DynamicInvokeImpl(Array<Object> args) {
  RuntimeMethodInfo runtimeMethodInfo = (RuntimeMethodInfo)RuntimeType::in::GetMethodBase((RuntimeType)GetType(), RuntimeMethodHandleInternal(GetInvokeMethod()));
  return runtimeMethodInfo->Invoke((Delegate)this, BindingFlags::Default, nullptr, args, nullptr);
}

Boolean Delegate___::Equals(Object obj) {
  if (obj == nullptr || !InternalEqualTypes((Delegate)this, obj)) {
    return false;
  }
  Delegate delegate = (Delegate)obj;
  if (_target == delegate->_target && _methodPtr == delegate->_methodPtr && _methodPtrAux == delegate->_methodPtrAux) {
    return true;
  }
  if (_methodPtrAux == IntPtr::Zero) {
    if (delegate->_methodPtrAux != IntPtr::Zero) {
      return false;
    }
    if (_target != delegate->_target) {
      return false;
    }
  } else {
    if (delegate->_methodPtrAux == IntPtr::Zero) {
      return false;
    }
    if (_methodPtrAux == delegate->_methodPtrAux) {
      return true;
    }
  }
  if (_methodBase == nullptr || delegate->_methodBase == nullptr || !rt::is<MethodInfo>(_methodBase) || !rt::is<MethodInfo>(delegate->_methodBase)) {
    return InternalEqualMethodHandles((Delegate)this, delegate);
  }
  return _methodBase->Equals(delegate->_methodBase);
}

Int32 Delegate___::GetHashCode() {
  if (_methodPtrAux == IntPtr::Zero) {
    return ((_target != nullptr) ? (RuntimeHelpers::GetHashCode(_target) * 33) : 0) + GetType()->GetHashCode();
  }
  return GetType()->GetHashCode();
}

MethodInfo Delegate___::GetMethodImpl() {
  if (_methodBase == nullptr || !rt::is<MethodInfo>(_methodBase)) {
    IRuntimeMethodInfo runtimeMethodInfo = FindMethodHandle();
    RuntimeType runtimeType = RuntimeMethodHandle::GetDeclaringType(runtimeMethodInfo);
    if ((RuntimeTypeHandle::IsGenericTypeDefinition(runtimeType) || RuntimeTypeHandle::HasInstantiation(runtimeType)) && (RuntimeMethodHandle::GetAttributes(runtimeMethodInfo) & MethodAttributes::Static) == 0) {
      if (_methodPtrAux == IntPtr::Zero) {
        Type type = _target->GetType();
        Type genericTypeDefinition = runtimeType->GetGenericTypeDefinition();
        while (type != nullptr) {
          if (type->get_IsGenericType() && type->GetGenericTypeDefinition() == genericTypeDefinition) {
            runtimeType = (rt::as<RuntimeType>(type));
            break;
          }
          type = type->get_BaseType();
        }
      } else {
        MethodInfo method = GetType()->GetMethod("Invoke");
        runtimeType = (RuntimeType)method->GetParameters()[0]->get_ParameterType();
      }
    }
    _methodBase = (MethodInfo)RuntimeType::in::GetMethodBase(runtimeType, runtimeMethodInfo);
  }
  return (MethodInfo)_methodBase;
}

Delegate Delegate___::CreateDelegate(Type type, Object target, String method, Boolean ignoreCase, Boolean throwOnBindFailure) {
  if (type == nullptr) {
    rt::throw_exception<ArgumentNullException>("type");
  }
  if (target == nullptr) {
    rt::throw_exception<ArgumentNullException>("target");
  }
  if (method == nullptr) {
    rt::throw_exception<ArgumentNullException>("method");
  }
  RuntimeType runtimeType = rt::as<RuntimeType>(type);
  if ((Object)runtimeType == nullptr) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_MustBeRuntimeType(), "type");
  }
  if (!runtimeType->IsDelegate()) {
    rt::throw_exception<ArgumentException>(SR::get_Arg_MustBeDelegate(), "type");
  }
  Delegate delegate = InternalAlloc(runtimeType);
  if (!delegate->BindToMethodName(target, (RuntimeType)target->GetType(), method, (DelegateBindingFlags)(26 | (ignoreCase ? 32 : 0)))) {
    if (throwOnBindFailure) {
      rt::throw_exception<ArgumentException>(SR::get_Arg_DlgtTargMeth());
    }
    return nullptr;
  }
  return delegate;
}

Delegate Delegate___::CreateDelegate(Type type, Type target, String method, Boolean ignoreCase, Boolean throwOnBindFailure) {
  if (type == nullptr) {
    rt::throw_exception<ArgumentNullException>("type");
  }
  if (target == nullptr) {
    rt::throw_exception<ArgumentNullException>("target");
  }
  if (target->get_ContainsGenericParameters()) {
    rt::throw_exception<ArgumentException>(SR::get_Arg_UnboundGenParam(), "target");
  }
  if (method == nullptr) {
    rt::throw_exception<ArgumentNullException>("method");
  }
  RuntimeType runtimeType = rt::as<RuntimeType>(type);
  if ((Object)runtimeType == nullptr) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_MustBeRuntimeType(), "type");
  }
  RuntimeType runtimeType2 = rt::as<RuntimeType>(target);
  if ((Object)runtimeType2 == nullptr) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_MustBeRuntimeType(), "target");
  }
  if (!runtimeType->IsDelegate()) {
    rt::throw_exception<ArgumentException>(SR::get_Arg_MustBeDelegate(), "type");
  }
  Delegate delegate = InternalAlloc(runtimeType);
  if (!delegate->BindToMethodName(nullptr, runtimeType2, method, (DelegateBindingFlags)(5 | (ignoreCase ? 32 : 0)))) {
    if (throwOnBindFailure) {
      rt::throw_exception<ArgumentException>(SR::get_Arg_DlgtTargMeth());
    }
    return nullptr;
  }
  return delegate;
}

Delegate Delegate___::CreateDelegate(Type type, MethodInfo method, Boolean throwOnBindFailure) {
  if (type == nullptr) {
    rt::throw_exception<ArgumentNullException>("type");
  }
  if (method == nullptr) {
    rt::throw_exception<ArgumentNullException>("method");
  }
  RuntimeType runtimeType = rt::as<RuntimeType>(type);
  if ((Object)runtimeType == nullptr) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_MustBeRuntimeType(), "type");
  }
  RuntimeMethodInfo runtimeMethodInfo = rt::as<RuntimeMethodInfo>(method);
  if ((Object)runtimeMethodInfo == nullptr) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_MustBeRuntimeMethodInfo(), "method");
  }
  if (!runtimeType->IsDelegate()) {
    rt::throw_exception<ArgumentException>(SR::get_Arg_MustBeDelegate(), "type");
  }
  Delegate delegate = CreateDelegateInternal(runtimeType, runtimeMethodInfo, nullptr, (DelegateBindingFlags)68);
  if ((Object)delegate == nullptr && throwOnBindFailure) {
    rt::throw_exception<ArgumentException>(SR::get_Arg_DlgtTargMeth());
  }
  return delegate;
}

Delegate Delegate___::CreateDelegate(Type type, Object firstArgument, MethodInfo method, Boolean throwOnBindFailure) {
  if (type == nullptr) {
    rt::throw_exception<ArgumentNullException>("type");
  }
  if (method == nullptr) {
    rt::throw_exception<ArgumentNullException>("method");
  }
  RuntimeType runtimeType = rt::as<RuntimeType>(type);
  if ((Object)runtimeType == nullptr) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_MustBeRuntimeType(), "type");
  }
  RuntimeMethodInfo runtimeMethodInfo = rt::as<RuntimeMethodInfo>(method);
  if ((Object)runtimeMethodInfo == nullptr) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_MustBeRuntimeMethodInfo(), "method");
  }
  if (!runtimeType->IsDelegate()) {
    rt::throw_exception<ArgumentException>(SR::get_Arg_MustBeDelegate(), "type");
  }
  Delegate delegate = CreateDelegateInternal(runtimeType, runtimeMethodInfo, firstArgument, DelegateBindingFlags::RelaxedSignature);
  if ((Object)delegate == nullptr && throwOnBindFailure) {
    rt::throw_exception<ArgumentException>(SR::get_Arg_DlgtTargMeth());
  }
  return delegate;
}

Delegate Delegate___::CreateDelegateNoSecurityCheck(Type type, Object target, RuntimeMethodHandle method) {
  if (type == nullptr) {
    rt::throw_exception<ArgumentNullException>("type");
  }
  if (method.IsNullHandle()) {
    rt::throw_exception<ArgumentNullException>("method");
  }
  RuntimeType runtimeType = rt::as<RuntimeType>(type);
  if ((Object)runtimeType == nullptr) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_MustBeRuntimeType(), "type");
  }
  if (!runtimeType->IsDelegate()) {
    rt::throw_exception<ArgumentException>(SR::get_Arg_MustBeDelegate(), "type");
  }
  Delegate delegate = InternalAlloc(runtimeType);
  if (!delegate->BindToMethodInfo(target, method.GetMethodInfo(), RuntimeMethodHandle::GetDeclaringType(method.GetMethodInfo()), DelegateBindingFlags::RelaxedSignature)) {
    rt::throw_exception<ArgumentException>(SR::get_Arg_DlgtTargMeth());
  }
  return delegate;
}

Delegate Delegate___::CreateDelegateInternal(RuntimeType rtType, RuntimeMethodInfo rtMethod, Object firstArgument, DelegateBindingFlags flags) {
  Delegate delegate = InternalAlloc(rtType);
  if (delegate->BindToMethodInfo(firstArgument, rtMethod, rtMethod->GetDeclaringTypeInternal(), flags)) {
    return delegate;
  }
  return nullptr;
}

Object Delegate___::GetTarget() {
  if (!(_methodPtrAux == IntPtr::Zero)) {
    return nullptr;
  }
  return _target;
}

Object Delegate___::Clone() {
  return MemberwiseClone();
}

Delegate Delegate___::Combine(Delegate a, Delegate b) {
  if ((Object)a == nullptr) {
    return b;
  }
  return a->CombineImpl(b);
}

Delegate Delegate___::Combine(Array<Delegate> delegates) {
  if (delegates == nullptr || delegates->get_Length() == 0) {
    return nullptr;
  }
  Delegate delegate = delegates[0];
  for (Int32 i = 1; i < delegates->get_Length(); i++) {
    delegate = Combine(delegate, delegates[i]);
  }
  return delegate;
}

Delegate Delegate___::CreateDelegate(Type type, Object firstArgument, MethodInfo method) {
  return CreateDelegate(type, firstArgument, method, true);
}

Delegate Delegate___::CreateDelegate(Type type, MethodInfo method) {
  return CreateDelegate(type, method, true);
}

Delegate Delegate___::CreateDelegate(Type type, Object target, String method) {
  return CreateDelegate(type, target, method, false, true);
}

Delegate Delegate___::CreateDelegate(Type type, Object target, String method, Boolean ignoreCase) {
  return CreateDelegate(type, target, method, ignoreCase, true);
}

Delegate Delegate___::CreateDelegate(Type type, Type target, String method) {
  return CreateDelegate(type, target, method, false, true);
}

Delegate Delegate___::CreateDelegate(Type type, Type target, String method, Boolean ignoreCase) {
  return CreateDelegate(type, target, method, ignoreCase, true);
}

Delegate Delegate___::CombineImpl(Delegate d) {
  rt::throw_exception<MulticastNotSupportedException>(SR::get_Multicast_Combine());
}

Delegate Delegate___::RemoveImpl(Delegate d) {
  if (!d->Equals((Delegate)this)) {
    return (Delegate)this;
  }
  return nullptr;
}

Array<Delegate> Delegate___::GetInvocationList() {
  return rt::newarr<Array<Delegate>>(1);
}

Object Delegate___::DynamicInvoke(Array<Object> args) {
  return DynamicInvokeImpl(args);
}

void Delegate___::GetObjectData(SerializationInfo info, StreamingContext context) {
  rt::throw_exception<PlatformNotSupportedException>();
}

Delegate Delegate___::Remove(Delegate source, Delegate value) {
  if ((Object)source == nullptr) {
    return nullptr;
  }
  if ((Object)value == nullptr) {
    return source;
  }
  if (!InternalEqualTypes(source, value)) {
    rt::throw_exception<ArgumentException>(SR::get_Arg_DlgtTypeMis());
  }
  return source->RemoveImpl(value);
}

Delegate Delegate___::RemoveAll(Delegate source, Delegate value) {
  Delegate delegate;
  do {
    delegate = source;
    source = Remove(source, value);
  } while (delegate != source)
  return delegate;
}

Boolean Delegate___::op_Equality(Delegate d1, Delegate d2) {
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

Boolean Delegate___::op_Inequality(Delegate d1, Delegate d2) {
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

} // namespace System::Private::CoreLib::System::DelegateNamespace
