#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(AsyncCallback)
FORWARD(Delegate)
FORWARD(IAsyncResult)
FORWARDS(Int32)
FORWARDS(IntPtr)
FORWARD(Object)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(Dictionary, TKey, TValue)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::Internal::Runtime::InteropServices {
FORWARD(IsolatedComponentLoadContext)
namespace ComponentActivatorNamespace {
using namespace ::System::Private::CoreLib::System;
using namespace ::System::Private::CoreLib::System::Collections::Generic;
class ComponentActivator {
  public: CLASS(ComponentEntryPoint) {
    public: Int32 Invoke(IntPtr args, Int32 sizeBytes);
    public: IAsyncResult BeginInvoke(IntPtr args, Int32 sizeBytes, AsyncCallback callback, Object object);
    public: Int32 EndInvoke(IAsyncResult result);
  };
  private: static String MarshalToString(IntPtr arg, String argName);
  public: static Int32 LoadAssemblyAndGetFunctionPointer(IntPtr assemblyPathNative, IntPtr typeNameNative, IntPtr methodNameNative, IntPtr delegateTypeNative, IntPtr reserved, IntPtr functionHandle);
  private: static Delegate CreateDelegate(String assemblyPath, String typeName, String methodName, String delegateTypeName);
  private: static IsolatedComponentLoadContext GetIsolatedComponentLoadContext(String assemblyPath);
  private: static Dictionary<String, IsolatedComponentLoadContext> s_assemblyLoadContexts;
  private: static Dictionary<IntPtr, Delegate> s_delegates;
};
} // namespace ComponentActivatorNamespace
using ComponentActivator = ComponentActivatorNamespace::ComponentActivator;
} // namespace System::Private::CoreLib::Internal::Runtime::InteropServices
