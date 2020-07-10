#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/IntPtr.h>

namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System::Reflection {
FORWARD(MethodInfo)
} // namespace System::Private::CoreLib::System::Reflection
namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
FORWARD(Delegate)
FORWARDS(Int32)
FORWARD(Object)
namespace MulticastDelegateNamespace {
using namespace Reflection;
using namespace Runtime::Serialization;
CLASS(MulticastDelegate) {
  public: Boolean IsUnmanagedFunctionPtr();
  public: Boolean InvocationListLogicallyNull();
  public: void GetObjectData(SerializationInfo info, StreamingContext context);
  public: Boolean Equals(Object obj);
  private: Boolean InvocationListEquals(MulticastDelegate d);
  private: Boolean TrySetSlot(Array<Object> a, Int32 index, Object o);
  private: MulticastDelegate NewMulticastDelegate(Array<Object> invocationList, Int32 invocationCount, Boolean thisIsMultiCastAlready);
  public: MulticastDelegate NewMulticastDelegate(Array<Object> invocationList, Int32 invocationCount);
  public: void StoreDynamicMethod(MethodInfo dynamicMethod);
  protected: Delegate CombineImpl(Delegate follow);
  private: Array<Object> DeleteFromInvocationList(Array<Object> invocationList, Int32 invocationCount, Int32 deleteIndex, Int32 deleteCount);
  private: Boolean EqualInvocationLists(Array<Object> a, Array<Object> b, Int32 start, Int32 count);
  protected: Delegate RemoveImpl(Delegate value);
  public: Array<Delegate> GetInvocationList();
  public: static Boolean op_Equality(MulticastDelegate d1, MulticastDelegate d2);
  public: static Boolean op_Inequality(MulticastDelegate d1, MulticastDelegate d2);
  public: Int32 GetHashCode();
  public: Object GetTarget();
  protected: MethodInfo GetMethodImpl();
  private: static void ThrowNullThisInDelegateToInstance();
  private: void CtorClosed(Object target, IntPtr methodPtr);
  private: void CtorClosedStatic(Object target, IntPtr methodPtr);
  private: void CtorRTClosed(Object target, IntPtr methodPtr);
  private: void CtorOpened(Object target, IntPtr methodPtr, IntPtr shuffleThunk);
  private: void CtorVirtualDispatch(Object target, IntPtr methodPtr, IntPtr shuffleThunk);
  private: void CtorCollectibleClosedStatic(Object target, IntPtr methodPtr, IntPtr gchandle);
  private: void CtorCollectibleOpened(Object target, IntPtr methodPtr, IntPtr shuffleThunk, IntPtr gchandle);
  private: void CtorCollectibleVirtualDispatch(Object target, IntPtr methodPtr, IntPtr shuffleThunk, IntPtr gchandle);
  private: Object _invocationList;
  private: IntPtr _invocationCount;
};
} // namespace MulticastDelegateNamespace
using MulticastDelegate = MulticastDelegateNamespace::MulticastDelegate;
} // namespace System::Private::CoreLib::System
