#pragma once

#include <System.Private.CoreLib/Interop.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System::Reflection {
enum class ImageFileMachine : int32_t;
enum class PortableExecutableKinds : int32_t;
FORWARDS(MetadataImport)
FORWARD(RuntimeModule)
} // namespace System::Private::CoreLib::System::Reflection
namespace System::Private::CoreLib::System::Reflection::Emit {
FORWARD(DynamicMethod)
} // namespace System::Private::CoreLib::System::Reflection::Emit
namespace System::Private::CoreLib::System::Runtime::CompilerServices {
FORWARDS(ObjectHandleOnStack)
FORWARDS(QCallModule)
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
namespace System::Private::CoreLib::System {
FORWARD_(Array)
FORWARDS(Boolean)
FORWARDS(Byte)
FORWARDS(Int32)
FORWARDS(IntPtr)
FORWARD(IRuntimeFieldInfo)
FORWARD(IRuntimeMethodInfo)
FORWARD(Object)
FORWARD(Resolver)
FORWARDS(RuntimeFieldHandle)
FORWARDS(RuntimeMethodHandle)
FORWARDS(RuntimeMethodHandleInternal)
FORWARD(RuntimeType)
FORWARDS(RuntimeTypeHandle)
FORWARD(String)
FORWARDS(UInt32)
namespace ModuleHandleNamespace {
using namespace System::Reflection;
using namespace System::Reflection::Emit;
using namespace System::Runtime::CompilerServices;
struct ModuleHandle : public valueType<ModuleHandle> {
  public: Int32 get_MDStreamVersion();
  private: static ModuleHandle GetEmptyMH();
  public: explicit ModuleHandle(RuntimeModule module);
  public: RuntimeModule GetRuntimeModule();
  public: Int32 GetHashCode();
  public: Boolean Equals(Object obj);
  public: Boolean Equals(ModuleHandle handle);
  public: static Boolean op_Equality(ModuleHandle left, ModuleHandle right);
  public: static Boolean op_Inequality(ModuleHandle left, ModuleHandle right);
  public: static IRuntimeMethodInfo GetDynamicMethod(DynamicMethod method, RuntimeModule module, String name, Array<Byte> sig, Resolver resolver);
  public: static Int32 GetToken(RuntimeModule module);
  private: static void ValidateModulePointer(RuntimeModule module);
  public: RuntimeTypeHandle GetRuntimeTypeHandleFromMetadataToken(Int32 typeToken);
  public: RuntimeTypeHandle ResolveTypeHandle(Int32 typeToken);
  public: RuntimeTypeHandle ResolveTypeHandle(Int32 typeToken, Array<RuntimeTypeHandle> typeInstantiationContext, Array<RuntimeTypeHandle> methodInstantiationContext);
  public: static RuntimeType ResolveTypeHandleInternal(RuntimeModule module, Int32 typeToken, Array<RuntimeTypeHandle> typeInstantiationContext, Array<RuntimeTypeHandle> methodInstantiationContext);
  private: static void ResolveType(QCallModule module, Int32 typeToken, IntPtr* typeInstArgs, Int32 typeInstCount, IntPtr* methodInstArgs, Int32 methodInstCount, ObjectHandleOnStack type);
  public: RuntimeMethodHandle GetRuntimeMethodHandleFromMetadataToken(Int32 methodToken);
  public: RuntimeMethodHandle ResolveMethodHandle(Int32 methodToken);
  public: static IRuntimeMethodInfo ResolveMethodHandleInternal(RuntimeModule module, Int32 methodToken);
  public: RuntimeMethodHandle ResolveMethodHandle(Int32 methodToken, Array<RuntimeTypeHandle> typeInstantiationContext, Array<RuntimeTypeHandle> methodInstantiationContext);
  public: static IRuntimeMethodInfo ResolveMethodHandleInternal(RuntimeModule module, Int32 methodToken, Array<RuntimeTypeHandle> typeInstantiationContext, Array<RuntimeTypeHandle> methodInstantiationContext);
  public: static RuntimeMethodHandleInternal ResolveMethodHandleInternalCore(RuntimeModule module, Int32 methodToken, Array<IntPtr> typeInstantiationContext, Int32 typeInstCount, Array<IntPtr> methodInstantiationContext, Int32 methodInstCount);
  private: static RuntimeMethodHandleInternal ResolveMethod(QCallModule module, Int32 methodToken, IntPtr* typeInstArgs, Int32 typeInstCount, IntPtr* methodInstArgs, Int32 methodInstCount);
  public: RuntimeFieldHandle GetRuntimeFieldHandleFromMetadataToken(Int32 fieldToken);
  public: RuntimeFieldHandle ResolveFieldHandle(Int32 fieldToken);
  public: RuntimeFieldHandle ResolveFieldHandle(Int32 fieldToken, Array<RuntimeTypeHandle> typeInstantiationContext, Array<RuntimeTypeHandle> methodInstantiationContext);
  public: static IRuntimeFieldInfo ResolveFieldHandleInternal(RuntimeModule module, Int32 fieldToken, Array<RuntimeTypeHandle> typeInstantiationContext, Array<RuntimeTypeHandle> methodInstantiationContext);
  private: static void ResolveField(QCallModule module, Int32 fieldToken, IntPtr* typeInstArgs, Int32 typeInstCount, IntPtr* methodInstArgs, Int32 methodInstCount, ObjectHandleOnStack retField);
  private: static Interop::BOOL _ContainsPropertyMatchingHash(QCallModule module, Int32 propertyToken, UInt32 hash);
  public: static Boolean ContainsPropertyMatchingHash(RuntimeModule module, Int32 propertyToken, UInt32 hash);
  public: static void GetModuleType(QCallModule handle, ObjectHandleOnStack type);
  public: static RuntimeType GetModuleType(RuntimeModule module);
  private: static void GetPEKind(QCallModule handle, Int32* peKind, Int32* machine);
  public: static void GetPEKind(RuntimeModule module, PortableExecutableKinds& peKind, ImageFileMachine& machine);
  public: static Int32 GetMDStreamVersion(RuntimeModule module);
  private: static IntPtr _GetMetadataImport(RuntimeModule module);
  public: static MetadataImport GetMetadataImport(RuntimeModule module);
  public: static void cctor();
  public: explicit ModuleHandle() {}
  public: static ModuleHandle EmptyHandle;
  private: RuntimeModule m_ptr;
};
} // namespace ModuleHandleNamespace
using ModuleHandle = ModuleHandleNamespace::ModuleHandle;
} // namespace System::Private::CoreLib::System
