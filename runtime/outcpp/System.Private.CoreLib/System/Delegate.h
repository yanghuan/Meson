#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/IntPtr.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Reflection {
FORWARD(MethodInfo)
FORWARD(RuntimeMethodInfo)
} // namespace System::Private::CoreLib::System::Reflection
namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System {
enum class DelegateBindingFlags;
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
FORWARDS(Int32)
FORWARD(IRuntimeMethodInfo)
FORWARD(MulticastDelegate)
FORWARDS(RuntimeMethodHandle)
FORWARD(RuntimeType)
FORWARD(String)
FORWARD(Type)
namespace DelegateNamespace {
using namespace Reflection;
using namespace Runtime::Serialization;
CLASS(Delegate) : public Object::in {
  public: Object get_Target();
  public: MethodInfo get_Method();
  protected: void Ctor(Object target, String method);
  protected: void Ctor(Type target, String method);
  protected: Object DynamicInvokeImpl(Array<Object> args);
  public: Boolean Equals(Object obj);
  public: Int32 GetHashCode();
  protected: MethodInfo GetMethodImpl();
  public: static Delegate CreateDelegate(Type type, Object target, String method, Boolean ignoreCase, Boolean throwOnBindFailure);
  public: static Delegate CreateDelegate(Type type, Type target, String method, Boolean ignoreCase, Boolean throwOnBindFailure);
  public: static Delegate CreateDelegate(Type type, MethodInfo method, Boolean throwOnBindFailure);
  public: static Delegate CreateDelegate(Type type, Object firstArgument, MethodInfo method, Boolean throwOnBindFailure);
  public: static Delegate CreateDelegateNoSecurityCheck(Type type, Object target, RuntimeMethodHandle method);
  public: static Delegate CreateDelegateInternal(RuntimeType rtType, RuntimeMethodInfo rtMethod, Object firstArgument, DelegateBindingFlags flags);
  private: Boolean BindToMethodName(Object target, RuntimeType methodType, String method, DelegateBindingFlags flags);
  private: Boolean BindToMethodInfo(Object target, IRuntimeMethodInfo method, RuntimeType methodType, DelegateBindingFlags flags);
  private: static MulticastDelegate InternalAlloc(RuntimeType type);
  public: static MulticastDelegate InternalAllocLike(Delegate d);
  public: static Boolean InternalEqualTypes(Object a, Object b);
  private: void DelegateConstruct(Object target, IntPtr slot);
  public: IntPtr GetMulticastInvoke();
  public: IntPtr GetInvokeMethod();
  public: IRuntimeMethodInfo FindMethodHandle();
  public: static Boolean InternalEqualMethodHandles(Delegate left, Delegate right);
  public: IntPtr AdjustTarget(Object target, IntPtr methodPtr);
  public: IntPtr GetCallStub(IntPtr methodPtr);
  public: Object GetTarget();
  public: static Boolean CompareUnmanagedFunctionPtrs(Delegate d1, Delegate d2);
  public: Object Clone();
  public: static Delegate Combine(Delegate a, Delegate b);
  public: static Delegate Combine(Array<Delegate> delegates);
  public: static Delegate CreateDelegate(Type type, Object firstArgument, MethodInfo method);
  public: static Delegate CreateDelegate(Type type, MethodInfo method);
  public: static Delegate CreateDelegate(Type type, Object target, String method);
  public: static Delegate CreateDelegate(Type type, Object target, String method, Boolean ignoreCase);
  public: static Delegate CreateDelegate(Type type, Type target, String method);
  public: static Delegate CreateDelegate(Type type, Type target, String method, Boolean ignoreCase);
  protected: Delegate CombineImpl(Delegate d);
  protected: Delegate RemoveImpl(Delegate d);
  public: Array<Delegate> GetInvocationList();
  public: Object DynamicInvoke(Array<Object> args);
  public: void GetObjectData(SerializationInfo info, StreamingContext context);
  public: static Delegate Remove(Delegate source, Delegate value);
  public: static Delegate RemoveAll(Delegate source, Delegate value);
  public: static Boolean op_Equality(Delegate d1, Delegate d2);
  public: static Boolean op_Inequality(Delegate d1, Delegate d2);
  public: Object _target;
  public: Object _methodBase;
  public: IntPtr _methodPtr;
  public: IntPtr _methodPtrAux;
};
} // namespace DelegateNamespace
using Delegate = DelegateNamespace::Delegate;
} // namespace System::Private::CoreLib::System
