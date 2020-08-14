#include "RuntimeHelpers-dep.h"

#include <System.Private.CoreLib/Internal/Runtime/CompilerServices/Unsafe-dep.h>
#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/GC-dep.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/MethodTable-dep.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/QCallTypeHandle-dep.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/RawArrayData-dep.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/RawData-dep.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/RuntimeHelpers-dep.h>
#include <System.Private.CoreLib/System/Runtime/Serialization/SerializationException-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/UInt32-dep.h>

namespace System::Private::CoreLib::System::Runtime::CompilerServices::RuntimeHelpersNamespace {
using namespace Internal::Runtime::CompilerServices;
using namespace System::Runtime::Serialization;

Int32 RuntimeHelpers::get_OffsetToStringData() {
  return 12;
}

void RuntimeHelpers::RunClassConstructor(RuntimeTypeHandle type) {
  _RunClassConstructor(type.GetRuntimeType());
}

void RuntimeHelpers::RunModuleConstructor(ModuleHandle module) {
  _RunModuleConstructor(module.GetRuntimeModule());
}

void RuntimeHelpers::PrepareMethod(RuntimeMethodHandle method) {
  _PrepareMethod(method.GetMethodInfo(), nullptr, 0);
}

void RuntimeHelpers::PrepareMethod(RuntimeMethodHandle method, Array<RuntimeTypeHandle> instantiation) {
  Int32 length;
  {
    IntPtr* pInstantiation = RuntimeTypeHandle::CopyRuntimeTypeHandles(instantiation, length);
    _PrepareMethod(method.GetMethodInfo(), pInstantiation, length);
    GC::KeepAlive(instantiation);
  }
}

Byte& RuntimeHelpers::GetRawData(Object obj) {
  return Unsafe::As<RawData>(obj)->Data;
}

UIntPtr RuntimeHelpers::GetRawObjectDataSize(Object obj) {
  MethodTable* methodTable = GetMethodTable(obj);
  UIntPtr num = (UIntPtr)methodTable->BaseSize - (UIntPtr)(2 * sizeof(IntPtr));
  if (methodTable->get_HasComponentSize()) {
    num += (UIntPtr)((IntPtr)Unsafe::As<RawArrayData>(obj)->Length * (IntPtr)methodTable->ComponentSize);
  }
  GC::KeepAlive(obj);
  return num;
}

Byte& RuntimeHelpers::GetRawArrayData(Array<> array) {
  return Unsafe::AddByteOffset(Unsafe::As<RawData>(array)->Data, (UIntPtr)GetMethodTable(array)->BaseSize - (UIntPtr)(2 * sizeof(IntPtr)));
}

UInt16 RuntimeHelpers::GetElementSize(Array<> array) {
  return GetMethodTable(array)->ComponentSize;
}

Int32& RuntimeHelpers::GetMultiDimensionalArrayBounds(Array<> array) {
  return Unsafe::As<Byte, Int32>(Unsafe::As<RawArrayData>(array)->Data);
}

Int32 RuntimeHelpers::GetMultiDimensionalArrayRank(Array<> array) {
  Int32 multiDimensionalArrayRank = GetMethodTable(array)->get_MultiDimensionalArrayRank();
  GC::KeepAlive(array);
  return multiDimensionalArrayRank;
}

Boolean RuntimeHelpers::ObjectHasComponentSize(Object obj) {
  return GetMethodTable(obj)->get_HasComponentSize();
}

MethodTable* RuntimeHelpers::GetMethodTable(Object obj) {
  return (MethodTable*)(void*)Unsafe::Add(Unsafe::As<Byte, IntPtr>(RuntimeHelpers::GetRawData(obj)), -1);
}

IntPtr RuntimeHelpers::AllocateTypeAssociatedMemory(Type type, Int32 size) {
  RuntimeType type2 = rt::as<RuntimeType>(type);
  if (type2 == nullptr) {
    rt::throw_exception<ArgumentException>(SR::get_Arg_MustBeType(), "type");
  }
  if (size < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("size");
  }
  return AllocateTypeAssociatedMemoryInternal(QCallTypeHandle(type2), (UInt32)size);
}

Object RuntimeHelpers::GetUninitializedObject(Type type) {
  if ((Object)type == nullptr) {
    rt::throw_exception<ArgumentNullException>("type", SR::get_ArgumentNull_Type());
  }
  if (!type->IsRuntimeImplemented()) {
    rt::throw_exception<SerializationException>(SR::Format(SR::get_Serialization_InvalidType(), type->ToString()));
  }
  return GetUninitializedObjectInternal(type);
}

void RuntimeHelpers::ExecuteCodeWithGuaranteedCleanup(TryCode code, CleanupCode backoutCode, Object userData) {
  if (code == nullptr) {
    rt::throw_exception<ArgumentNullException>("code");
  }
  if (backoutCode == nullptr) {
    rt::throw_exception<ArgumentNullException>("backoutCode");
  }
  Boolean exceptionThrown = true;
  try{
    code(userData);
    exceptionThrown = false;
  } finally: {
    backoutCode(userData, exceptionThrown);
  }
}

void RuntimeHelpers::PrepareContractedDelegate(Delegate d) {
}

void RuntimeHelpers::ProbeForSufficientStack() {
}

void RuntimeHelpers::PrepareConstrainedRegions() {
}

void RuntimeHelpers::PrepareConstrainedRegionsNoOP() {
}

Boolean RuntimeHelpers::IsPrimitiveType(CorElementType et) {
}

} // namespace System::Private::CoreLib::System::Runtime::CompilerServices::RuntimeHelpersNamespace
