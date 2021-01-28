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
#include <System.Private.CoreLib/System/Runtime/InteropServices/UnmanagedCallersOnlyAttribute-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/StringComparer-dep.h>
#include <System.Private.CoreLib/System/Type-dep.h>

namespace System::Private::CoreLib::Internal::Runtime::InteropServices::ComponentActivatorNamespace {
using namespace System;
using namespace System::Collections::Generic;
using namespace System::Reflection;
using namespace System::Runtime::InteropServices;

void ComponentActivator::__c__DisplayClass4_0___::ctor() {
}

Assembly ComponentActivator::__c__DisplayClass4_0___::_LoadAssemblyAndGetFunctionPointer_b__0(AssemblyName name) {
  return alc->LoadFromAssemblyName(name);
}

String ComponentActivator::MarshalToString(IntPtr arg, String argName) {
  if (arg == IntPtr::Zero) {
    rt::throw_exception<ArgumentNullException>(argName);
  }
  String text = Marshal::PtrToStringUni(arg);
  if (text == nullptr) {
    rt::throw_exception<ArgumentNullException>(argName);
  }
  return text;
}

Int32 ComponentActivator::LoadAssemblyAndGetFunctionPointer(IntPtr assemblyPathNative, IntPtr typeNameNative, IntPtr methodNameNative, IntPtr delegateTypeNative, IntPtr reserved, IntPtr functionHandle) {
  try {
    __c__DisplayClass4_0 __c__DisplayClass4_ = rt::newobj<__c__DisplayClass4_0>();
    String assemblyPath = MarshalToString(assemblyPathNative, "assemblyPathNative");
    __c__DisplayClass4_->alc = GetIsolatedComponentLoadContext(assemblyPath);
    Func<AssemblyName, Assembly> assemblyResolver = {__c__DisplayClass4_, &__c__DisplayClass4_0::in::_LoadAssemblyAndGetFunctionPointer_b__0};
    String text = MarshalToString(typeNameNative, "typeNameNative");
    Type type = Type::in::GetType(text, assemblyResolver, nullptr, true);
    String text2 = MarshalToString(methodNameNative, "methodNameNative");
    Type type2;
    if (delegateTypeNative == IntPtr::Zero) {
      type2 = typeof<ComponentEntryPoint>();
    } else if (delegateTypeNative == (IntPtr)(Int32)(-1)) {
      type2 = nullptr;
    } else {
      String typeName = MarshalToString(delegateTypeNative, "delegateTypeNative");
      type2 = Type::in::GetType(typeName, assemblyResolver, nullptr, true);
    }

    if (reserved != IntPtr::Zero) {
      rt::throw_exception<ArgumentOutOfRangeException>("reserved");
    }
    if (functionHandle == IntPtr::Zero) {
      rt::throw_exception<ArgumentNullException>("functionHandle");
    }
    IntPtr intPtr;
    if (type2 == nullptr) {
      BindingFlags bindingAttr = BindingFlags::Static | BindingFlags::Public | BindingFlags::NonPublic;
      MethodInfo method = type->GetMethod(text2, bindingAttr);
      if (method == nullptr) {
        rt::throw_exception<MissingMethodException>(text, text2);
      }
      if (CustomAttributeExtensions::GetCustomAttribute<UnmanagedCallersOnlyAttribute>(method) == nullptr) {
        rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_FunctionMissingUnmanagedCallersOnly());
      }
      intPtr = method->get_MethodHandle().GetFunctionPointer();
    } else {
      Delegate delegate = Delegate::in::CreateDelegate(type2, type, text2);
      intPtr = Marshal::GetFunctionPointerForDelegate(delegate);
      {
        rt::lock(s_delegates);
        s_delegates[intPtr] = delegate;
      }
    }
    *(IntPtr*)(void*)functionHandle = intPtr;
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

void ComponentActivator::cctor() {
  s_assemblyLoadContexts = rt::newobj<Dictionary<String, IsolatedComponentLoadContext>>(StringComparer::in::get_InvariantCulture());
  s_delegates = rt::newobj<Dictionary<IntPtr, Delegate>>();
}

} // namespace System::Private::CoreLib::Internal::Runtime::InteropServices::ComponentActivatorNamespace
