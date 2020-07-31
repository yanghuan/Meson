#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Guid.h>
#include <System.Private.CoreLib/System/IntPtr.h>
#include <System.Private.CoreLib/System/Object.h>

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
enum class ComWrappersScenario;
enum class CreateComInterfaceFlags;
enum class CreateObjectFlags;
namespace ComWrappersNamespace {
using namespace Collections;
using namespace CompilerServices;
CLASS(ComWrappers) : public Object::in {
  public: struct ComInterfaceEntry {
    public: Guid IID;
    public: IntPtr Vtable;
  };
  public: struct ComInterfaceDispatch {
    private: struct ComInterfaceInstance {
      public: IntPtr GcHandle;
    };
    public: template <class T>
    static T GetInstance(ComInterfaceDispatch* dispatchPtr);
    public: IntPtr Vtable;
  };
  public: IntPtr GetOrCreateComInterfaceForObject(Object instance, CreateComInterfaceFlags flags);
  private: static Boolean TryGetOrCreateComInterfaceForObjectInternal(ComWrappers impl, Object instance, CreateComInterfaceFlags flags, IntPtr& retValue);
  private: static Boolean TryGetOrCreateComInterfaceForObjectInternal(ObjectHandleOnStack comWrappersImpl, ObjectHandleOnStack instance, CreateComInterfaceFlags flags, IntPtr& retValue);
  protected: ComInterfaceEntry* ComputeVtables(Object obj, CreateComInterfaceFlags flags, Int32& count);
  public: static void* CallComputeVtables(ComWrappersScenario scenario, ComWrappers comWrappersImpl, Object obj, CreateComInterfaceFlags flags, Int32& count);
  public: Object GetOrCreateObjectForComInstance(IntPtr externalComObject, CreateObjectFlags flags);
  protected: Object CreateObject(IntPtr externalComObject, CreateObjectFlags flags);
  public: static Object CallCreateObject(ComWrappersScenario scenario, ComWrappers comWrappersImpl, IntPtr externalComObject, CreateObjectFlags flags);
  public: Object GetOrRegisterObjectForComInstance(IntPtr externalComObject, CreateObjectFlags flags, Object wrapper);
  private: static Boolean TryGetOrCreateObjectForComInstanceInternal(ComWrappers impl, IntPtr externalComObject, CreateObjectFlags flags, Object wrapperMaybe, Object& retValue);
  private: static Boolean TryGetOrCreateObjectForComInstanceInternal(ObjectHandleOnStack comWrappersImpl, IntPtr externalComObject, CreateObjectFlags flags, ObjectHandleOnStack wrapper, ObjectHandleOnStack retValue);
  protected: void ReleaseObjects(IEnumerable objects);
  public: static void CallReleaseObjects(ComWrappers comWrappersImpl, IEnumerable objects);
  public: static void RegisterForTrackerSupport(ComWrappers instance);
  private: static void SetGlobalInstanceRegisteredForTrackerSupport();
  public: static void RegisterForMarshalling(ComWrappers instance);
  private: static void SetGlobalInstanceRegisteredForMarshalling();
  protected: static void GetIUnknownImpl(IntPtr& fpQueryInterface, IntPtr& fpAddRef, IntPtr& fpRelease);
  private: static void GetIUnknownImplInternal(IntPtr& fpQueryInterface, IntPtr& fpAddRef, IntPtr& fpRelease);
  public: static Int32 CallICustomQueryInterface(Object customQueryInterfaceMaybe, Guid& iid, IntPtr& ppObject);
  protected: void Ctor();
  private: static ComWrappers s_globalInstanceForTrackerSupport;
  private: static ComWrappers s_globalInstanceForMarshalling;
};
} // namespace ComWrappersNamespace
using ComWrappers = ComWrappersNamespace::ComWrappers;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
