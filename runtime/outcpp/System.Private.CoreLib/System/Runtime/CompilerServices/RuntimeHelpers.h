#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARD(AsyncCallback)
FORWARDS(Boolean)
FORWARDS(Byte)
FORWARD(Delegate)
FORWARD(IAsyncResult)
FORWARDS(Int32)
FORWARDS(Int64)
FORWARDS(IntPtr)
FORWARD(IRuntimeMethodInfo)
FORWARDS(ModuleHandle)
FORWARD(Object)
FORWARDS(Range)
FORWARDS(RuntimeFieldHandle)
FORWARDS(RuntimeMethodHandle)
FORWARDS(RuntimeMethodHandleInternal)
FORWARD(RuntimeType)
FORWARDS(RuntimeTypeHandle)
FORWARD(Type)
FORWARDS(UInt16)
FORWARDS(UInt32)
FORWARDS(UIntPtr)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection {
enum class CorElementType : uint8_t;
FORWARD(RuntimeModule)
} // namespace System::Private::CoreLib::System::Reflection
namespace System::Private::CoreLib::System::Runtime::CompilerServices {
FORWARDS(MethodTable)
FORWARDS(QCallTypeHandle)
FORWARDS(TailCallTls)
namespace RuntimeHelpersNamespace {
using namespace Reflection;
class RuntimeHelpers {
  public: CLASS(TryCode) {
    public: void Ctor(Object object, IntPtr method);
    public: void Invoke(Object userData);
    public: IAsyncResult BeginInvoke(Object userData, AsyncCallback callback, Object object);
    public: void EndInvoke(IAsyncResult result);
  };
  public: CLASS(CleanupCode) {
    public: void Ctor(Object object, IntPtr method);
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
  private: static Object GetUninitializedObjectInternal(Type type);
  public: static Object AllocateUninitializedClone(Object obj);
  public: template <class T>
  static Boolean IsReferenceOrContainsReferences();
  public: template <class T>
  static Boolean IsBitwiseEquatable();
  public: template <class T>
  static Boolean EnumEquals(T x, T y);
  public: template <class T>
  static Int32 EnumCompareTo(T x, T y);
  public: static Byte& GetRawData(Object obj);
  public: static UIntPtr GetRawObjectDataSize(Object obj);
  public: static Byte& GetRawArrayData(Array<> array);
  public: static UInt16 GetElementSize(Array<> array);
  public: static Int32& GetMultiDimensionalArrayBounds(Array<> array);
  public: static Int32 GetMultiDimensionalArrayRank(Array<> array);
  public: static Boolean ObjectHasComponentSize(Object obj);
  public: static MethodTable* GetMethodTable(Object obj);
  public: static IntPtr AllocateTypeAssociatedMemory(Type type, Int32 size);
  private: static IntPtr AllocateTypeAssociatedMemoryInternal(QCallTypeHandle type, UInt32 size);
  private: static IntPtr AllocTailCallArgBuffer(Int32 size, IntPtr gcDesc);
  private: static void FreeTailCallArgBuffer();
  private: static TailCallTls* GetTailCallInfo(IntPtr retAddrSlot, IntPtr* retAddr);
  public: static Int64 GetILBytesJitted();
  public: static Int32 GetMethodsJittedCount();
  public: template <class T>
  static Array<T> GetSubArray(Array<T> array, Range range);
  public: static Object GetUninitializedObject(Type type);
  public: static void ExecuteCodeWithGuaranteedCleanup(TryCode code, CleanupCode backoutCode, Object userData);
  public: static void PrepareContractedDelegate(Delegate d);
  public: static void ProbeForSufficientStack();
  public: static void PrepareConstrainedRegions();
  public: static void PrepareConstrainedRegionsNoOP();
  public: static Boolean IsPrimitiveType(CorElementType et);
};
} // namespace RuntimeHelpersNamespace
using RuntimeHelpers = RuntimeHelpersNamespace::RuntimeHelpers;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
