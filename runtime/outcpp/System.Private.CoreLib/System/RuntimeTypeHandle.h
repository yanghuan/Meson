#pragma once

#include <System.Private.CoreLib/Interop.h>
#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/RuntimeMethodHandleInternal.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System::Reflection {
enum class CorElementType : uint8_t;
enum class TypeAttributes;
FORWARDS(MetadataImport)
FORWARD(RuntimeAssembly)
FORWARD(RuntimeModule)
} // namespace System::Private::CoreLib::System::Reflection
namespace System::Private::CoreLib::System::Runtime::CompilerServices {
FORWARDS(ObjectHandleOnStack)
FORWARDS(QCallModule)
FORWARDS(QCallTypeHandle)
FORWARDS(StackCrawlMarkHandle)
FORWARDS(StringHandleOnStack)
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
namespace System::Private::CoreLib::System::Runtime::InteropServices {
enum class GCHandleType;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
namespace System::Private::CoreLib::System::Threading {
enum class StackCrawlMark;
} // namespace System::Private::CoreLib::System::Threading
namespace System::Private::CoreLib::System::Runtime::Loader {
FORWARD(AssemblyLoadContext)
} // namespace System::Private::CoreLib::System::Runtime::Loader
namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System {
enum class TypeNameFormatFlags;
FORWARD_(Array, T1, T2)
FORWARDS(Int32)
FORWARDS(IntPtr)
FORWARD(IRuntimeMethodInfo)
FORWARDS(MdUtf8String)
FORWARDS(ModuleHandle)
FORWARD(Object)
FORWARD(RuntimeType)
FORWARD(String)
FORWARD(Type)
namespace RuntimeTypeHandleNamespace {
using namespace Reflection;
using namespace Runtime::CompilerServices;
using namespace Runtime::InteropServices;
using namespace Runtime::Loader;
using namespace Runtime::Serialization;
using namespace Threading;
struct RuntimeTypeHandle : public valueType<RuntimeTypeHandle> {
  public: struct IntroducedMethodEnumerator : public valueType<IntroducedMethodEnumerator> {
    public: RuntimeMethodHandleInternal get_Current();
    public: explicit IntroducedMethodEnumerator(RuntimeType type);
    public: Boolean MoveNext();
    public: IntroducedMethodEnumerator GetEnumerator();
    public: explicit IntroducedMethodEnumerator() {}
    private: Boolean _firstCall;
    private: RuntimeMethodHandleInternal _handle;
  };
  public: IntPtr get_Value();
  public: RuntimeTypeHandle GetNativeHandle();
  public: RuntimeType GetTypeChecked();
  public: static Boolean IsInstanceOfType(RuntimeType type, Object o);
  public: static Type GetTypeHelper(Type typeStart, Array<Type> genericArgs, IntPtr pModifiers, Int32 cModifiers);
  public: static Boolean op_Equality(RuntimeTypeHandle left, Object right);
  public: static Boolean op_Equality(Object left, RuntimeTypeHandle right);
  public: static Boolean op_Inequality(RuntimeTypeHandle left, Object right);
  public: static Boolean op_Inequality(Object left, RuntimeTypeHandle right);
  public: Int32 GetHashCode();
  public: Boolean Equals(Object obj);
  public: Boolean Equals(RuntimeTypeHandle handle);
  public: static IntPtr GetValueInternal(RuntimeTypeHandle handle);
  public: explicit RuntimeTypeHandle(RuntimeType type);
  public: static Boolean IsTypeDefinition(RuntimeType type);
  public: static Boolean IsPrimitive(RuntimeType type);
  public: static Boolean IsByRef(RuntimeType type);
  public: static Boolean IsPointer(RuntimeType type);
  public: static Boolean IsArray(RuntimeType type);
  public: static Boolean IsSZArray(RuntimeType type);
  public: static Boolean HasElementType(RuntimeType type);
  public: static Array<IntPtr> CopyRuntimeTypeHandles(Array<RuntimeTypeHandle> inHandles, Int32& length);
  public: static Array<IntPtr> CopyRuntimeTypeHandles(Array<Type> inHandles, Int32& length);
  public: static Object CreateInstance(RuntimeType type, Boolean publicOnly, Boolean wrapExceptions, Boolean& canBeCached, RuntimeMethodHandleInternal& ctor, Boolean& hasNoDefaultCtor);
  public: static Object Allocate(RuntimeType type);
  public: static Object CreateInstanceForAnotherGenericParameter(RuntimeType type, RuntimeType genericParameter);
  public: RuntimeType GetRuntimeType();
  public: static CorElementType GetCorElementType(RuntimeType type);
  public: static RuntimeAssembly GetAssembly(RuntimeType type);
  public: static RuntimeModule GetModule(RuntimeType type);
  public: ModuleHandle GetModuleHandle();
  public: static RuntimeType GetBaseType(RuntimeType type);
  public: static TypeAttributes GetAttributes(RuntimeType type);
  public: static RuntimeType GetElementType(RuntimeType type);
  public: static Boolean CompareCanonicalHandles(RuntimeType left, RuntimeType right);
  public: static Int32 GetArrayRank(RuntimeType type);
  public: static Int32 GetToken(RuntimeType type);
  public: static RuntimeMethodHandleInternal GetMethodAt(RuntimeType type, Int32 slot);
  public: static IntroducedMethodEnumerator GetIntroducedMethods(RuntimeType type);
  private: static RuntimeMethodHandleInternal GetFirstIntroducedMethod(RuntimeType type);
  private: static void GetNextIntroducedMethod(RuntimeMethodHandleInternal& method);
  public: static Boolean GetFields(RuntimeType type, IntPtr* result, Int32* count);
  public: static Array<Type> GetInterfaces(RuntimeType type);
  private: static void GetConstraints(QCallTypeHandle handle, ObjectHandleOnStack types);
  public: Array<Type> GetConstraints();
  private: static IntPtr GetGCHandle(QCallTypeHandle handle, GCHandleType type);
  public: IntPtr GetGCHandle(GCHandleType type);
  private: static IntPtr FreeGCHandle(QCallTypeHandle typeHandle, IntPtr objHandle);
  public: IntPtr FreeGCHandle(IntPtr objHandle);
  public: static Int32 GetNumVirtuals(RuntimeType type);
  private: static void VerifyInterfaceIsImplemented(QCallTypeHandle handle, QCallTypeHandle interfaceHandle);
  public: void VerifyInterfaceIsImplemented(RuntimeTypeHandle interfaceHandle);
  private: static RuntimeMethodHandleInternal GetInterfaceMethodImplementation(QCallTypeHandle handle, QCallTypeHandle interfaceHandle, RuntimeMethodHandleInternal interfaceMethodHandle);
  public: RuntimeMethodHandleInternal GetInterfaceMethodImplementation(RuntimeTypeHandle interfaceHandle, RuntimeMethodHandleInternal interfaceMethodHandle);
  public: static Boolean IsComObject(RuntimeType type, Boolean isGenericCOM);
  public: static Boolean IsInterface(RuntimeType type);
  public: static Boolean IsByRefLike(RuntimeType type);
  private: static Boolean _IsVisible(QCallTypeHandle typeHandle);
  public: static Boolean IsVisible(RuntimeType type);
  public: static Boolean IsValueType(RuntimeType type);
  private: static void ConstructName(QCallTypeHandle handle, TypeNameFormatFlags formatFlags, StringHandleOnStack retString);
  public: String ConstructName(TypeNameFormatFlags formatFlags);
  private: static void* _GetUtf8Name(RuntimeType type);
  public: static MdUtf8String GetUtf8Name(RuntimeType type);
  public: static Boolean CanCastTo(RuntimeType type, RuntimeType target);
  public: static RuntimeType GetDeclaringType(RuntimeType type);
  public: static IRuntimeMethodInfo GetDeclaringMethod(RuntimeType type);
  private: static void GetTypeByName(String name, Boolean throwOnError, Boolean ignoreCase, StackCrawlMarkHandle stackMark, ObjectHandleOnStack assemblyLoadContext, ObjectHandleOnStack type, ObjectHandleOnStack keepalive);
  public: static RuntimeType GetTypeByName(String name, Boolean throwOnError, Boolean ignoreCase, StackCrawlMark& stackMark);
  public: static RuntimeType GetTypeByName(String name, Boolean throwOnError, Boolean ignoreCase, StackCrawlMark& stackMark, AssemblyLoadContext assemblyLoadContext);
  private: static void GetTypeByNameUsingCARules(String name, QCallModule scope, ObjectHandleOnStack type);
  public: static RuntimeType GetTypeByNameUsingCARules(String name, RuntimeModule scope);
  public: static void GetInstantiation(QCallTypeHandle type, ObjectHandleOnStack types, Interop::BOOL fAsRuntimeTypeArray);
  public: Array<RuntimeType> GetInstantiationInternal();
  public: Array<Type> GetInstantiationPublic();
  private: static void Instantiate(QCallTypeHandle handle, IntPtr* pInst, Int32 numGenericArgs, ObjectHandleOnStack type);
  public: RuntimeType Instantiate(Array<Type> inst);
  private: static void MakeArray(QCallTypeHandle handle, Int32 rank, ObjectHandleOnStack type);
  public: RuntimeType MakeArray(Int32 rank);
  private: static void MakeSZArray(QCallTypeHandle handle, ObjectHandleOnStack type);
  public: RuntimeType MakeSZArray();
  private: static void MakeByRef(QCallTypeHandle handle, ObjectHandleOnStack type);
  public: RuntimeType MakeByRef();
  private: static void MakePointer(QCallTypeHandle handle, ObjectHandleOnStack type);
  public: RuntimeType MakePointer();
  public: static Interop::BOOL IsCollectible(QCallTypeHandle handle);
  public: static Boolean HasInstantiation(RuntimeType type);
  private: static void GetGenericTypeDefinition(QCallTypeHandle type, ObjectHandleOnStack retType);
  public: static RuntimeType GetGenericTypeDefinition(RuntimeType type);
  public: static Boolean IsGenericTypeDefinition(RuntimeType type);
  public: static Boolean IsGenericVariable(RuntimeType type);
  private: static Int32 GetGenericVariableIndex(RuntimeType type);
  public: Int32 GetGenericVariableIndex();
  public: static Boolean ContainsGenericVariables(RuntimeType handle);
  public: Boolean ContainsGenericVariables();
  private: static Boolean SatisfiesConstraints(RuntimeType paramType, IntPtr* pTypeContext, Int32 typeContextLength, IntPtr* pMethodContext, Int32 methodContextLength, RuntimeType toType);
  public: static Boolean SatisfiesConstraints(RuntimeType paramType, Array<RuntimeType> typeContext, Array<RuntimeType> methodContext, RuntimeType toType);
  private: static IntPtr _GetMetadataImport(RuntimeType type);
  public: static MetadataImport GetMetadataImport(RuntimeType type);
  public: void GetObjectData(SerializationInfo info, StreamingContext context);
  public: static Boolean IsEquivalentTo(RuntimeType rtType1, RuntimeType rtType2);
  public: explicit RuntimeTypeHandle() {}
  public: RuntimeType m_type;
};
} // namespace RuntimeTypeHandleNamespace
using RuntimeTypeHandle = RuntimeTypeHandleNamespace::RuntimeTypeHandle;
} // namespace System::Private::CoreLib::System
