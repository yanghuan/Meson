#pragma once

#include <System.Private.CoreLib/System/Guid.h>
#include <System.Private.CoreLib/System/Int64.h>
#include <System.Private.CoreLib/System/IntPtr.h>
#include <System.Private.CoreLib/System/Object.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(Int32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::CompilerServices {
FORWARDS(ObjectHandleOnStack)
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
namespace System::Private::CoreLib::System::Collections {
FORWARD(IEnumerable)
} // namespace System::Private::CoreLib::System::Collections
namespace System::Private::CoreLib::System::Runtime::InteropServices {
enum class ComWrappersScenario : int32_t;
enum class CreateComInterfaceFlags : int32_t;
enum class CreateObjectFlags : int32_t;
namespace ComWrappersNamespace {
using namespace System::Collections;
using namespace System::Runtime::CompilerServices;
CLASS(ComWrappers) : public object {
  public: struct ComInterfaceEntry : public valueType<ComInterfaceEntry> {
    public: Guid IID;
    public: IntPtr Vtable;
  };
  public: struct ComInterfaceDispatch : public valueType<ComInterfaceDispatch> {
    private: struct ComInterfaceInstance : public valueType<ComInterfaceInstance> {
      public: IntPtr GcHandle;
    };
    public: template <class T>
    static T GetInstance(ComInterfaceDispatch* dispatchPtr);
    public: IntPtr Vtable;
  };
  public: IntPtr GetOrCreateComInterfaceForObject(Object instance, CreateComInterfaceFlags flags);
  private: static Boolean TryGetOrCreateComInterfaceForObjectInternal(ComWrappers impl, Object instance, CreateComInterfaceFlags flags, IntPtr& retValue);
  private: static Boolean TryGetOrCreateComInterfaceForObjectInternal(ObjectHandleOnStack comWrappersImpl, Int64 wrapperId, ObjectHandleOnStack instance, CreateComInterfaceFlags flags, IntPtr& retValue);
  protected: ComInterfaceEntry* ComputeVtables(Object obj, CreateComInterfaceFlags flags, Int32& count);
  public: static void* CallComputeVtables(ComWrappersScenario scenario, ComWrappers comWrappersImpl, Object obj, CreateComInterfaceFlags flags, Int32& count);
  public: Object GetOrCreateObjectForComInstance(IntPtr externalComObject, CreateObjectFlags flags);
  protected: Object CreateObject(IntPtr externalComObject, CreateObjectFlags flags);
  public: static Object CallCreateObject(ComWrappersScenario scenario, ComWrappers comWrappersImpl, IntPtr externalComObject, CreateObjectFlags flags);
  public: Object GetOrRegisterObjectForComInstance(IntPtr externalComObject, CreateObjectFlags flags, Object wrapper);
  private: static Boolean TryGetOrCreateObjectForComInstanceInternal(ComWrappers impl, IntPtr externalComObject, CreateObjectFlags flags, Object wrapperMaybe, Object& retValue);
  private: static Boolean TryGetOrCreateObjectForComInstanceInternal(ObjectHandleOnStack comWrappersImpl, Int64 wrapperId, IntPtr externalComObject, CreateObjectFlags flags, ObjectHandleOnStack wrapper, ObjectHandleOnStack retValue);
  protected: void ReleaseObjects(IEnumerable objects);
  public: static void CallReleaseObjects(ComWrappers comWrappersImpl, IEnumerable objects);
  public: static void RegisterForTrackerSupport(ComWrappers instance);
  private: static void SetGlobalInstanceRegisteredForTrackerSupport(Int64 id);
  public: static void RegisterForMarshalling(ComWrappers instance);
  private: static void SetGlobalInstanceRegisteredForMarshalling(Int64 id);
  protected: static void GetIUnknownImpl(IntPtr& fpQueryInterface, IntPtr& fpAddRef, IntPtr& fpRelease);
  private: static void GetIUnknownImplInternal(IntPtr& fpQueryInterface, IntPtr& fpAddRef, IntPtr& fpRelease);
  public: static Int32 CallICustomQueryInterface(Object customQueryInterfaceMaybe, Guid& iid, IntPtr& ppObject);
  protected: void ctor();
  private: static ComWrappers s_globalInstanceForTrackerSupport;
  private: static ComWrappers s_globalInstanceForMarshalling;
  private: static Int64 s_instanceCounter;
  private: Int64 id;
};
} // namespace ComWrappersNamespace
using ComWrappers = ComWrappersNamespace::ComWrappers;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
