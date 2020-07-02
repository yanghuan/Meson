#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/Interop.h>

namespace System::Private::CoreLib::System::Reflection {
FORWARD(RuntimeModule)
enum class PortableExecutableKinds;
enum class ImageFileMachine;
FORWARDS(MetadataImport)
} // namespace System::Private::CoreLib::System::Reflection
namespace System::Private::CoreLib::System::Reflection::Emit {
FORWARD(DynamicMethod)
} // namespace System::Private::CoreLib::System::Reflection::Emit
namespace System::Private::CoreLib::System::Runtime::CompilerServices {
FORWARDS(QCallModule)
FORWARDS(ObjectHandleOnStack)
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
namespace System::Private::CoreLib::System {
FORWARDS(Int32)
FORWARD(Object)
FORWARDS(Boolean)
FORWARD(String)
FORWARD_(Array, T1, T2)
FORWARDS(Byte)
FORWARD(Resolver)
FORWARD(IRuntimeMethodInfo)
FORWARDS(RuntimeTypeHandle)
FORWARD(RuntimeType)
FORWARDS(IntPtr)
FORWARDS(RuntimeMethodHandle)
FORWARDS(RuntimeMethodHandleInternal)
FORWARDS(RuntimeFieldHandle)
FORWARD(IRuntimeFieldInfo)
FORWARDS(UInt32)
namespace ModuleHandleNamespace {
using namespace ::System::Private::CoreLib::System::Reflection;
using namespace ::System::Private::CoreLib::System::Reflection::Emit;
using namespace ::System::Private::CoreLib::System::Runtime::CompilerServices;
struct ModuleHandle {
  public: Int32 get_MDStreamVersion();
  private: static ModuleHandle GetEmptyMH();
  public: RuntimeModule GetRuntimeModule();
  public: Int32 GetHashCode();
  public: Boolean Equals(Object obj);
  public: Boolean Equals(ModuleHandle handle);
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
  public: static ModuleHandle EmptyHandle;
  private: RuntimeModule m_ptr;
};
} // namespace ModuleHandleNamespace
using ModuleHandle = ModuleHandleNamespace::ModuleHandle;
} // namespace System::Private::CoreLib::System
