#include "ModuleHandle-dep.h"

#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/GC-dep.h>
#include <System.Private.CoreLib/System/IntPtr-dep.h>
#include <System.Private.CoreLib/System/InvalidOperationException-dep.h>
#include <System.Private.CoreLib/System/ModuleHandle-dep.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/ObjectHandleOnStack-dep.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/QCallModule-dep.h>
#include <System.Private.CoreLib/System/RuntimeMethodHandleInternal-dep.h>
#include <System.Private.CoreLib/System/RuntimeMethodInfoStub-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>

namespace System::Private::CoreLib::System::ModuleHandleNamespace {
using namespace System::Runtime::CompilerServices;

Int32 ModuleHandle::get_MDStreamVersion() {
  return GetMDStreamVersion(GetRuntimeModule()->GetNativeHandle());
}

ModuleHandle ModuleHandle::GetEmptyMH() {
  return rt::default__;
}

ModuleHandle::ModuleHandle(RuntimeModule module) {
  m_ptr = module;
}

RuntimeModule ModuleHandle::GetRuntimeModule() {
  return m_ptr;
}

Int32 ModuleHandle::GetHashCode() {
  if (!(m_ptr != nullptr)) {
    return 0;
  }
  return m_ptr->GetHashCode();
}

Boolean ModuleHandle::Equals(Object obj) {
  if (!rt::is<ModuleHandle>(obj)) {
    return false;
  }
  return ((ModuleHandle)obj).m_ptr == m_ptr;
}

Boolean ModuleHandle::Equals(ModuleHandle handle) {
  return handle.m_ptr == m_ptr;
}

Boolean ModuleHandle::op_Equality(ModuleHandle left, ModuleHandle right) {
  return left.Equals(right);
}

Boolean ModuleHandle::op_Inequality(ModuleHandle left, ModuleHandle right) {
  return !left.Equals(right);
}

void ModuleHandle::ValidateModulePointer(RuntimeModule module) {
  if (module == nullptr) {
    rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_NullModuleHandle());
  }
}

RuntimeTypeHandle ModuleHandle::GetRuntimeTypeHandleFromMetadataToken(Int32 typeToken) {
  return ResolveTypeHandle(typeToken);
}

RuntimeTypeHandle ModuleHandle::ResolveTypeHandle(Int32 typeToken) {
  return RuntimeTypeHandle(ResolveTypeHandleInternal(GetRuntimeModule(), typeToken, nullptr, nullptr));
}

RuntimeTypeHandle ModuleHandle::ResolveTypeHandle(Int32 typeToken, Array<RuntimeTypeHandle> typeInstantiationContext, Array<RuntimeTypeHandle> methodInstantiationContext) {
  return RuntimeTypeHandle(ResolveTypeHandleInternal(GetRuntimeModule(), typeToken, typeInstantiationContext, methodInstantiationContext));
}

RuntimeType ModuleHandle::ResolveTypeHandleInternal(RuntimeModule module, Int32 typeToken, Array<RuntimeTypeHandle> typeInstantiationContext, Array<RuntimeTypeHandle> methodInstantiationContext) {
  ValidateModulePointer(module);
  if (!GetMetadataImport(module).IsValidToken(typeToken)) {
    rt::throw_exception<ArgumentOutOfRangeException>("typeToken", SR::Format(SR::get_Argument_InvalidToken(), typeToken, ModuleHandle(module)));
  }
  Int32 length;
  Array<IntPtr> array = RuntimeTypeHandle::CopyRuntimeTypeHandles(typeInstantiationContext, length);
  Int32 length2;
  Array<IntPtr> array2 = RuntimeTypeHandle::CopyRuntimeTypeHandles(methodInstantiationContext, length2);
  {
    IntPtr* typeInstArgs = rt::fixed(array);
    {
      IntPtr* methodInstArgs = rt::fixed(array2);
      RuntimeType o = nullptr;
      ResolveType(QCallModule(module), typeToken, typeInstArgs, length, methodInstArgs, length2, ObjectHandleOnStack::Create(o));
      GC::KeepAlive(typeInstantiationContext);
      GC::KeepAlive(methodInstantiationContext);
      return o;
    }
  }
}

RuntimeMethodHandle ModuleHandle::GetRuntimeMethodHandleFromMetadataToken(Int32 methodToken) {
  return ResolveMethodHandle(methodToken);
}

RuntimeMethodHandle ModuleHandle::ResolveMethodHandle(Int32 methodToken) {
  return ResolveMethodHandle(methodToken, nullptr, nullptr);
}

IRuntimeMethodInfo ModuleHandle::ResolveMethodHandleInternal(RuntimeModule module, Int32 methodToken) {
  return ResolveMethodHandleInternal(module, methodToken, nullptr, nullptr);
}

RuntimeMethodHandle ModuleHandle::ResolveMethodHandle(Int32 methodToken, Array<RuntimeTypeHandle> typeInstantiationContext, Array<RuntimeTypeHandle> methodInstantiationContext) {
  return RuntimeMethodHandle(ResolveMethodHandleInternal(GetRuntimeModule(), methodToken, typeInstantiationContext, methodInstantiationContext));
}

IRuntimeMethodInfo ModuleHandle::ResolveMethodHandleInternal(RuntimeModule module, Int32 methodToken, Array<RuntimeTypeHandle> typeInstantiationContext, Array<RuntimeTypeHandle> methodInstantiationContext) {
  Int32 length;
  Array<IntPtr> typeInstantiationContext2 = RuntimeTypeHandle::CopyRuntimeTypeHandles(typeInstantiationContext, length);
  Int32 length2;
  Array<IntPtr> methodInstantiationContext2 = RuntimeTypeHandle::CopyRuntimeTypeHandles(methodInstantiationContext, length2);
  RuntimeMethodHandleInternal runtimeMethodHandleInternal = ResolveMethodHandleInternalCore(module, methodToken, typeInstantiationContext2, length, methodInstantiationContext2, length2);
  IRuntimeMethodInfo result = rt::newobj<RuntimeMethodInfoStub>(runtimeMethodHandleInternal, RuntimeMethodHandle::GetLoaderAllocator(runtimeMethodHandleInternal));
  GC::KeepAlive(typeInstantiationContext);
  GC::KeepAlive(methodInstantiationContext);
  return result;
}

RuntimeMethodHandleInternal ModuleHandle::ResolveMethodHandleInternalCore(RuntimeModule module, Int32 methodToken, Array<IntPtr> typeInstantiationContext, Int32 typeInstCount, Array<IntPtr> methodInstantiationContext, Int32 methodInstCount) {
  ValidateModulePointer(module);
  if (!GetMetadataImport(module->GetNativeHandle()).IsValidToken(methodToken)) {
    rt::throw_exception<ArgumentOutOfRangeException>("methodToken", SR::Format(SR::get_Argument_InvalidToken(), methodToken, ModuleHandle(module)));
  }
  {
    IntPtr* typeInstArgs = rt::fixed(typeInstantiationContext);
    {
      IntPtr* methodInstArgs = rt::fixed(methodInstantiationContext);
      return ResolveMethod(QCallModule(module), methodToken, typeInstArgs, typeInstCount, methodInstArgs, methodInstCount);
    }
  }
}

RuntimeFieldHandle ModuleHandle::GetRuntimeFieldHandleFromMetadataToken(Int32 fieldToken) {
  return ResolveFieldHandle(fieldToken);
}

RuntimeFieldHandle ModuleHandle::ResolveFieldHandle(Int32 fieldToken) {
  return RuntimeFieldHandle(ResolveFieldHandleInternal(GetRuntimeModule(), fieldToken, nullptr, nullptr));
}

RuntimeFieldHandle ModuleHandle::ResolveFieldHandle(Int32 fieldToken, Array<RuntimeTypeHandle> typeInstantiationContext, Array<RuntimeTypeHandle> methodInstantiationContext) {
  return RuntimeFieldHandle(ResolveFieldHandleInternal(GetRuntimeModule(), fieldToken, typeInstantiationContext, methodInstantiationContext));
}

IRuntimeFieldInfo ModuleHandle::ResolveFieldHandleInternal(RuntimeModule module, Int32 fieldToken, Array<RuntimeTypeHandle> typeInstantiationContext, Array<RuntimeTypeHandle> methodInstantiationContext) {
  ValidateModulePointer(module);
  if (!GetMetadataImport(module->GetNativeHandle()).IsValidToken(fieldToken)) {
    rt::throw_exception<ArgumentOutOfRangeException>("fieldToken", SR::Format(SR::get_Argument_InvalidToken(), fieldToken, ModuleHandle(module)));
  }
  Int32 length;
  Array<IntPtr> array = RuntimeTypeHandle::CopyRuntimeTypeHandles(typeInstantiationContext, length);
  Int32 length2;
  Array<IntPtr> array2 = RuntimeTypeHandle::CopyRuntimeTypeHandles(methodInstantiationContext, length2);
  {
    IntPtr* typeInstArgs = rt::fixed(array);
    {
      IntPtr* methodInstArgs = rt::fixed(array2);
      IRuntimeFieldInfo o = nullptr;
      ResolveField(QCallModule(module), fieldToken, typeInstArgs, length, methodInstArgs, length2, ObjectHandleOnStack::Create(o));
      GC::KeepAlive(typeInstantiationContext);
      GC::KeepAlive(methodInstantiationContext);
      return o;
    }
  }
}

Boolean ModuleHandle::ContainsPropertyMatchingHash(RuntimeModule module, Int32 propertyToken, UInt32 hash) {
  return _ContainsPropertyMatchingHash(QCallModule(module), propertyToken, hash) != Interop::BOOL::FALSE;
}

RuntimeType ModuleHandle::GetModuleType(RuntimeModule module) {
  RuntimeType o = nullptr;
  GetModuleType(QCallModule(module), ObjectHandleOnStack::Create(o));
  return o;
}

void ModuleHandle::GetPEKind(RuntimeModule module, PortableExecutableKinds& peKind, ImageFileMachine& machine) {
  Int32 num;
  Int32 num2;
  GetPEKind(QCallModule(module), &num, &num2);
  peKind = (PortableExecutableKinds)num;
  machine = (ImageFileMachine)num2;
}

MetadataImport ModuleHandle::GetMetadataImport(RuntimeModule module) {
  return MetadataImport(_GetMetadataImport(module->GetNativeHandle()), module);
}

void ModuleHandle::cctor() {
  EmptyHandle = GetEmptyMH();
}

} // namespace System::Private::CoreLib::System::ModuleHandleNamespace
