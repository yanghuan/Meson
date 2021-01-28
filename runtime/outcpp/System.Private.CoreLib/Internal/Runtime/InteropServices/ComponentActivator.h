#pragma once

#include <System.Private.CoreLib/System/MulticastDelegate.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARD(AsyncCallback)
FORWARD(Delegate)
FORWARD(IAsyncResult)
FORWARDS(Int32)
FORWARDS(IntPtr)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection {
FORWARD(Assembly)
FORWARD(AssemblyName)
} // namespace System::Private::CoreLib::System::Reflection
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(Dictionary, TKey, TValue)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::Internal::Runtime::InteropServices {
FORWARD(IsolatedComponentLoadContext)
namespace ComponentActivatorNamespace {
using namespace System;
using namespace System::Collections::Generic;
using namespace System::Reflection;
class ComponentActivator {
  public: CLASS(ComponentEntryPoint) : public MulticastDelegate::in {
    public: void ctor(Object object, IntPtr method);
    public: Int32 Invoke(IntPtr args, Int32 sizeBytes);
    public: IAsyncResult BeginInvoke(IntPtr args, Int32 sizeBytes, AsyncCallback callback, Object object);
    public: Int32 EndInvoke(IAsyncResult result);
    public: static constexpr rt::TypeCode code = rt::TypeCode::Delegate;
  };
  private: CLASS(__c__DisplayClass4_0) : public object {
    public: void ctor();
    public: Assembly _LoadAssemblyAndGetFunctionPointer_b__0(AssemblyName name);
    public: IsolatedComponentLoadContext alc;
  };
  private: static String MarshalToString(IntPtr arg, String argName);
  public: static Int32 LoadAssemblyAndGetFunctionPointer(IntPtr assemblyPathNative, IntPtr typeNameNative, IntPtr methodNameNative, IntPtr delegateTypeNative, IntPtr reserved, IntPtr functionHandle);
  private: static IsolatedComponentLoadContext GetIsolatedComponentLoadContext(String assemblyPath);
  public: static void cctor();
  private: static Dictionary<String, IsolatedComponentLoadContext> s_assemblyLoadContexts;
  private: static Dictionary<IntPtr, Delegate> s_delegates;
};
} // namespace ComponentActivatorNamespace
using ComponentActivator = ComponentActivatorNamespace::ComponentActivator;
} // namespace System::Private::CoreLib::Internal::Runtime::InteropServices
