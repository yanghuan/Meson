#pragma once

#include <System.Private.CoreLib/Interop.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(ISerializable)
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System::Runtime::CompilerServices {
FORWARDS(ObjectHandleOnStack)
FORWARDS(QCallModule)
FORWARDS(QCallTypeHandle)
FORWARDS(StringHandleOnStack)
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
namespace System::Private::CoreLib::System::Threading {
enum class StackCrawlMark : int32_t;
} // namespace System::Private::CoreLib::System::Threading
namespace System::Private::CoreLib::System::Reflection {
enum class MethodAttributes : int32_t;
enum class MethodImplAttributes : int32_t;
FORWARD(LoaderAllocator)
FORWARD(RuntimeMethodBody)
} // namespace System::Private::CoreLib::System::Reflection
namespace System::Private::CoreLib::System {
enum class TypeNameFormatFlags : int32_t;
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
FORWARDS(Int32)
FORWARDS(IntPtr)
FORWARD(IRuntimeMethodInfo)
FORWARDS(MdUtf8String)
FORWARD(Object)
FORWARD(Resolver)
FORWARDS(RuntimeMethodHandleInternal)
FORWARD(RuntimeType)
FORWARD(Signature)
FORWARD(String)
FORWARD(Type)
FORWARDS(UInt32)
namespace RuntimeMethodHandleNamespace {
using namespace Reflection;
using namespace Runtime::CompilerServices;
using namespace Runtime::Serialization;
using namespace Threading;
struct RuntimeMethodHandle : public valueType<RuntimeMethodHandle> {
  public: using interface = rt::TypeList<ISerializable>;
  public: IntPtr get_Value();
  public: static IRuntimeMethodInfo EnsureNonNullMethodInfo(IRuntimeMethodInfo method);
  public: explicit RuntimeMethodHandle(IRuntimeMethodInfo method);
  public: IRuntimeMethodInfo GetMethodInfo();
  private: static IntPtr GetValueInternal(RuntimeMethodHandle rmh);
  public: void GetObjectData(SerializationInfo info, StreamingContext context);
  public: Int32 GetHashCode();
  public: Boolean Equals(Object obj);
  public: static Boolean op_Equality(RuntimeMethodHandle left, RuntimeMethodHandle right);
  public: static Boolean op_Inequality(RuntimeMethodHandle left, RuntimeMethodHandle right);
  public: Boolean Equals(RuntimeMethodHandle handle);
  public: Boolean IsNullHandle();
  public: static IntPtr GetFunctionPointer(RuntimeMethodHandleInternal handle);
  public: IntPtr GetFunctionPointer();
  public: static Interop::BOOL GetIsCollectible(RuntimeMethodHandleInternal handle);
  public: static Interop::BOOL IsCAVisibleFromDecoratedType(QCallTypeHandle attrTypeHandle, RuntimeMethodHandleInternal attrCtor, QCallTypeHandle sourceTypeHandle, QCallModule sourceModule);
  private: static IRuntimeMethodInfo _GetCurrentMethod(StackCrawlMark& stackMark);
  public: static IRuntimeMethodInfo GetCurrentMethod(StackCrawlMark& stackMark);
  public: static MethodAttributes GetAttributes(RuntimeMethodHandleInternal method);
  public: static MethodAttributes GetAttributes(IRuntimeMethodInfo method);
  public: static MethodImplAttributes GetImplAttributes(IRuntimeMethodInfo method);
  private: static void ConstructInstantiation(RuntimeMethodHandleInternal method, TypeNameFormatFlags format, StringHandleOnStack retString);
  public: static String ConstructInstantiation(IRuntimeMethodInfo method, TypeNameFormatFlags format);
  public: static RuntimeType GetDeclaringType(RuntimeMethodHandleInternal method);
  public: static RuntimeType GetDeclaringType(IRuntimeMethodInfo method);
  public: static Int32 GetSlot(RuntimeMethodHandleInternal method);
  public: static Int32 GetSlot(IRuntimeMethodInfo method);
  public: static Int32 GetMethodDef(IRuntimeMethodInfo method);
  public: static String GetName(RuntimeMethodHandleInternal method);
  public: static String GetName(IRuntimeMethodInfo method);
  private: static void* _GetUtf8Name(RuntimeMethodHandleInternal method);
  public: static MdUtf8String GetUtf8Name(RuntimeMethodHandleInternal method);
  public: static Boolean MatchesNameHash(RuntimeMethodHandleInternal method, UInt32 hash);
  public: static Object InvokeMethod(Object target, Array<Object> arguments, Signature sig, Boolean constructor, Boolean wrapExceptions);
  private: static void GetMethodInstantiation(RuntimeMethodHandleInternal method, ObjectHandleOnStack types, Interop::BOOL fAsRuntimeTypeArray);
  public: static Array<RuntimeType> GetMethodInstantiationInternal(IRuntimeMethodInfo method);
  public: static Array<RuntimeType> GetMethodInstantiationInternal(RuntimeMethodHandleInternal method);
  public: static Array<Type> GetMethodInstantiationPublic(IRuntimeMethodInfo method);
  public: static Boolean HasMethodInstantiation(RuntimeMethodHandleInternal method);
  public: static Boolean HasMethodInstantiation(IRuntimeMethodInfo method);
  public: static RuntimeMethodHandleInternal GetStubIfNeeded(RuntimeMethodHandleInternal method, RuntimeType declaringType, Array<RuntimeType> methodInstantiation);
  public: static RuntimeMethodHandleInternal GetMethodFromCanonical(RuntimeMethodHandleInternal method, RuntimeType declaringType);
  public: static Boolean IsGenericMethodDefinition(RuntimeMethodHandleInternal method);
  public: static Boolean IsGenericMethodDefinition(IRuntimeMethodInfo method);
  public: static Boolean IsTypicalMethodDefinition(IRuntimeMethodInfo method);
  private: static void GetTypicalMethodDefinition(RuntimeMethodHandleInternal method, ObjectHandleOnStack outMethod);
  public: static IRuntimeMethodInfo GetTypicalMethodDefinition(IRuntimeMethodInfo method);
  private: static Int32 GetGenericParameterCount(RuntimeMethodHandleInternal method);
  public: static Int32 GetGenericParameterCount(IRuntimeMethodInfo method);
  private: static void StripMethodInstantiation(RuntimeMethodHandleInternal method, ObjectHandleOnStack outMethod);
  public: static IRuntimeMethodInfo StripMethodInstantiation(IRuntimeMethodInfo method);
  public: static Boolean IsDynamicMethod(RuntimeMethodHandleInternal method);
  public: static void Destroy(RuntimeMethodHandleInternal method);
  public: static Resolver GetResolver(RuntimeMethodHandleInternal method);
  public: static RuntimeMethodBody GetMethodBody(IRuntimeMethodInfo method, RuntimeType declaringType);
  public: static Boolean IsConstructor(RuntimeMethodHandleInternal method);
  public: static LoaderAllocator GetLoaderAllocator(RuntimeMethodHandleInternal method);
  public: explicit RuntimeMethodHandle() {}
  private: IRuntimeMethodInfo m_value;
};
} // namespace RuntimeMethodHandleNamespace
using RuntimeMethodHandle = RuntimeMethodHandleNamespace::RuntimeMethodHandle;
} // namespace System::Private::CoreLib::System
