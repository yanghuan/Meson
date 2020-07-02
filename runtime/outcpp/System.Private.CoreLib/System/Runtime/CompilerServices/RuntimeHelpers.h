#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARD(AsyncCallback)
FORWARDS(Boolean)
FORWARD(Delegate)
FORWARD(IAsyncResult)
FORWARDS(Int32)
FORWARDS(IntPtr)
FORWARD(IRuntimeMethodInfo)
FORWARDS(ModuleHandle)
FORWARD(Object)
FORWARDS(RuntimeFieldHandle)
FORWARDS(RuntimeMethodHandle)
FORWARDS(RuntimeMethodHandleInternal)
FORWARD(RuntimeType)
FORWARDS(RuntimeTypeHandle)
FORWARD(Type)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection {
FORWARD(RuntimeModule)
} // namespace System::Private::CoreLib::System::Reflection
namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace RuntimeHelpersNamespace {
using namespace ::System::Private::CoreLib::System::Reflection;
class RuntimeHelpers {
  public: CLASS(TryCode) {
    public: void Invoke(Object userData);
    public: IAsyncResult BeginInvoke(Object userData, AsyncCallback callback, Object object);
    public: void EndInvoke(IAsyncResult result);
  };
  public: CLASS(CleanupCode) {
    public: void Invoke(Object userData, Boolean exceptionThrown);
    public: IAsyncResult BeginInvoke(Object userData, Boolean exceptionThrown, AsyncCallback callback, Object object);
    public: void EndInvoke(IAsyncResult result);
  };
  public: static Int32 get_OffsetToStringData();
  public: static void InitializeArray(Array<> array, RuntimeFieldHandle fldHandle);
  public: static Object GetObjectValue(Object obj);
  private: static void _RunClassConstructor(RuntimeType type);
  public: static void RunClassConstructor(RuntimeTypeHandle type);
  private: static void _RunModuleConstructor(RuntimeModule module);
  public: static void RunModuleConstructor(ModuleHandle module);
  public: static void _CompileMethod(RuntimeMethodHandleInternal method);
  private: static void _PrepareMethod(IRuntimeMethodInfo method, IntPtr* pInstantiation, Int32 cInstantiation);
  public: static void PrepareMethod(RuntimeMethodHandle method);
  public: static void PrepareMethod(RuntimeMethodHandle method, Array<RuntimeTypeHandle> instantiation);
  public: static void PrepareDelegate(Delegate d);
  public: static Int32 GetHashCode(Object o);
  public: static Boolean Equals(Object o1, Object o2);
  public: static void EnsureSufficientExecutionStack();
  public: static Boolean TryEnsureSufficientExecutionStack();
  public: static void ExecuteCodeWithGuaranteedCleanup(TryCode code, CleanupCode backoutCode, Object userData);
  public: static void ExecuteBackoutCodeHelper(Object backoutCode, Object userData, Boolean exceptionThrown);
  public: static Boolean ObjectHasComponentSize(Object obj);
  private: static IntPtr GetObjectMethodTablePointer(Object obj);
  private: static Object GetUninitializedObjectInternal(Type type);
  public: static Object GetUninitializedObject(Type type);
  public: static void PrepareContractedDelegate(Delegate d);
  public: static void ProbeForSufficientStack();
  public: static void PrepareConstrainedRegions();
  public: static void PrepareConstrainedRegionsNoOP();
};
} // namespace RuntimeHelpersNamespace
using RuntimeHelpers = RuntimeHelpersNamespace::RuntimeHelpers;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
