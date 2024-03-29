#pragma once

#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array)
FORWARD(Delegate)
FORWARD(Type)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(List, T)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System::Runtime::InteropServices {
namespace ComEventsMethodNamespace {
using namespace System::Collections::Generic;
CLASS(ComEventsMethod) : public object {
  public: CLASS(DelegateWrapper) : public object {
    public: Delegate get_Delegate() { return Delegate; }
    public: void set_Delegate(Delegate value) { Delegate = value; }
    public: Boolean get_WrapArgs() { return WrapArgs; }
    private: void set_WrapArgs(Boolean value) { WrapArgs = value; }
    public: void ctor(Delegate d, Boolean wrapArgs);
    public: Object Invoke(Array<Object> args);
    private: void PreProcessSignature();
    private: Boolean _once;
    private: Int32 _expectedParamsCount;
    private: Array<Type> _cachedTargetTypes;
    private: Delegate Delegate;
    private: Boolean WrapArgs;
  };
  public: Boolean get_Empty();
  public: void ctor(Int32 dispid);
  public: static ComEventsMethod Find(ComEventsMethod methods, Int32 dispid);
  public: static ComEventsMethod Add(ComEventsMethod methods, ComEventsMethod method);
  public: static ComEventsMethod Remove(ComEventsMethod methods, ComEventsMethod method);
  public: void AddDelegate(Delegate d, Boolean wrapArgs = false);
  public: void RemoveDelegate(Delegate d, Boolean wrapArgs = false);
  public: Object Invoke(Array<Object> args);
  private: List<DelegateWrapper> _delegateWrappers;
  private: Int32 _dispid;
  private: ComEventsMethod _next;
};
} // namespace ComEventsMethodNamespace
using ComEventsMethod = ComEventsMethodNamespace::ComEventsMethod;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
