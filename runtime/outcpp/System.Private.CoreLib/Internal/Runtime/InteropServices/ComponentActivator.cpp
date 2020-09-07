#include "ComponentActivator-dep.h"

#include <System.Private.CoreLib/Internal/Runtime/InteropServices/ComponentActivator-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/Collections/Generic/Dictionary-dep.h>
#include <System.Private.CoreLib/System/Delegate-dep.h>
#include <System.Private.CoreLib/System/Exception-dep.h>
#include <System.Private.CoreLib/System/Func-dep.h>
#include <System.Private.CoreLib/System/InvalidOperationException-dep.h>
#include <System.Private.CoreLib/System/MissingMethodException-dep.h>
#include <System.Private.CoreLib/System/Reflection/BindingFlags.h>
#include <System.Private.CoreLib/System/Reflection/CustomAttributeExtensions-dep.h>
#include <System.Private.CoreLib/System/Reflection/MethodInfo-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/Marshal-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/StringComparer-dep.h>
#include <System.Private.CoreLib/System/Type-dep.h>

namespace System::Private::CoreLib::Internal::Runtime::InteropServices::ComponentActivatorNamespace {
using namespace System;
using namespace System::Collections::Generic;
using namespace System::Reflection;
using namespace System::Runtime::InteropServices;

void ComponentActivator::__c__DisplayClass7_0___::ctor() {
}

Assembly ComponentActivator::__c__DisplayClass7_0___::_InternalGetFunctionPointer_b__0(AssemblyName name) {
  return alc->LoadFromAssemblyName(name);
}

String ComponentActivator::MarshalToString(IntPtr arg, String argName) {
  String text = Marshal::PtrToStringAuto(arg);
  if (text == nullptr) {
    rt::throw_exception<ArgumentNullException>(argName);
  }
  return text;
}

Int32 ComponentActivator::LoadAssemblyAndGetFunctionPointer(IntPtr assemblyPathNative, IntPtr typeNameNative, IntPtr methodNameNative, IntPtr delegateTypeNative, IntPtr reserved, IntPtr functionHandle) {
  try {
    String assemblyPath = MarshalToString(assemblyPathNative, "assemblyPathNative");
    String typeName = MarshalToString(typeNameNative, "typeNameNative");
    String methodName = MarshalToString(methodNameNative, "methodNameNative");
    if (reserved != IntPtr::Zero) {
      rt::throw_exception<ArgumentOutOfRangeException>("reserved");
    }
    if (functionHandle == IntPtr::Zero) {
      rt::throw_exception<ArgumentNullException>("functionHandle");
    }
    AssemblyLoadContext isolatedComponentLoadContext = GetIsolatedComponentLoadContext(assemblyPath);
    *(IntPtr*)(void*)functionHandle = InternalGetFunctionPointer(isolatedComponentLoadContext, typeName, methodName, delegateTypeNative);
  } catch (Exception ex) {
    return ex->get_HResult();
  }
  return 0;
}

Int32 ComponentActivator::GetFunctionPointer(IntPtr typeNameNative, IntPtr methodNameNative, IntPtr delegateTypeNative, IntPtr loadContext, IntPtr reserved, IntPtr functionHandle) {
  try {
    String typeName = MarshalToString(typeNameNative, "typeNameNative");
    String methodName = MarshalToString(methodNameNative, "methodNameNative");
    if (loadContext != IntPtr::Zero) {
      rt::throw_exception<ArgumentOutOfRangeException>("loadContext");
    }
    if (reserved != IntPtr::Zero) {
      rt::throw_exception<ArgumentOutOfRangeException>("reserved");
    }
    if (functionHandle == IntPtr::Zero) {
      rt::throw_exception<ArgumentNullException>("functionHandle");
    }
    *(IntPtr*)(void*)functionHandle = InternalGetFunctionPointer(AssemblyLoadContext::in::get_Default(), typeName, methodName, delegateTypeNative);
  } catch (Exception ex) {
    return ex->get_HResult();
  }
  return 0;
}

IsolatedComponentLoadContext ComponentActivator::GetIsolatedComponentLoadContext(String assemblyPath) {
  {
    rt::lock(s_assemblyLoadContexts);
    IsolatedComponentLoadContext value;
    if (!s_assemblyLoadContexts->TryGetValue(assemblyPath, value)) {
      value = rt::newobj<IsolatedComponentLoadContext>(assemblyPath);
      s_assemblyLoadContexts->Add(assemblyPath, value);
      return value;
    }
    return value;
  }
}

IntPtr ComponentActivator::InternalGetFunctionPointer(AssemblyLoadContext alc, String typeName, String methodName, IntPtr delegateTypeNative) {
  __c__DisplayClass7_0 __c__DisplayClass7_ = rt::newobj<__c__DisplayClass7_0>();
  __c__DisplayClass7_->alc = alc;
  Func<AssemblyName, Assembly> assemblyResolver = __c__DisplayClass7_->_InternalGetFunctionPointer_b__0;
  Type type;
  if (delegateTypeNative == IntPtr::Zero) {
    type = typeof<ComponentEntryPoint>();
  } else if (delegateTypeNative == (IntPtr)(Int32)(-1)) {
    type = nullptr;
  } else {
    String typeName2 = MarshalToString(delegateTypeNative, "delegateTypeNative");
    type = Type::in::GetType(typeName2, assemblyResolver, nullptr, true);
  }

  Type type2 = Type::in::GetType(typeName, assemblyResolver, nullptr, true);
  if (type == nullptr) {
    BindingFlags bindingAttr = BindingFlags::Static | BindingFlags::Public | BindingFlags::NonPublic;
    MethodInfo method = type2->GetMethod(methodName, bindingAttr);
    if (method == nullptr) {
      rt::throw_exception<MissingMethodException>(typeName, methodName);
    }
    if (CustomAttributeExtensions::GetCustomAttribute(method) == nullptr) {
      rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_FunctionMissingUnmanagedCallersOnly());
    }
    return method->get_MethodHandle().GetFunctionPointer();
  }
  Delegate delegate = Delegate::in::CreateDelegate(type, type2, methodName);
  IntPtr functionPointerForDelegate = Marshal::GetFunctionPointerForDelegate(delegate);
  {
    rt::lock(s_delegates);
    s_delegates[functionPointerForDelegate] = delegate;
    return functionPointerForDelegate;
  }
}

void ComponentActivator::cctor() {
  s_assemblyLoadContexts = rt::newobj<Dictionary<String, IsolatedComponentLoadContext>>(StringComparer::in::get_InvariantCulture());
  s_delegates = rt::newobj<Dictionary<IntPtr, Delegate>>();
}

} // namespace System::Private::CoreLib::Internal::Runtime::InteropServices::ComponentActivatorNamespace
