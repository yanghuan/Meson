#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/Int32.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARD(Delegate)
FORWARD(Object)
FORWARD(Type)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(List, T)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System::Runtime::InteropServices {
namespace ComEventsMethodNamespace {
using namespace ::System::Private::CoreLib::System::Collections::Generic;
CLASS(ComEventsMethod) {
  public: CLASS(DelegateWrapper) {
    public: Object Invoke(Array<Object> args);
    private: void PreProcessSignature();
    private: Boolean _once;
    private: Int32 _expectedParamsCount;
    private: Array<Type> _cachedTargetTypes;
    private: Delegate Delegate;
  };
  public: Boolean get_Empty();
  public: static ComEventsMethod Find(ComEventsMethod methods, Int32 dispid);
  public: static ComEventsMethod Add(ComEventsMethod methods, ComEventsMethod method);
  public: static ComEventsMethod Remove(ComEventsMethod methods, ComEventsMethod method);
  public: void AddDelegate(Delegate d);
  public: void RemoveDelegate(Delegate d);
  public: Object Invoke(Array<Object> args);
  private: List<DelegateWrapper> _delegateWrappers;
  private: Int32 _dispid;
  private: ComEventsMethod _next;
};
} // namespace ComEventsMethodNamespace
using ComEventsMethod = ComEventsMethodNamespace::ComEventsMethod;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
