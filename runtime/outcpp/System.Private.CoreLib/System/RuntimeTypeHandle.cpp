#include "RuntimeTypeHandle-dep.h"

#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/Byte-dep.h>
#include <System.Private.CoreLib/System/GC-dep.h>
#include <System.Private.CoreLib/System/IntPtr-dep.h>
#include <System.Private.CoreLib/System/InvalidOperationException-dep.h>
#include <System.Private.CoreLib/System/PlatformNotSupportedException-dep.h>
#include <System.Private.CoreLib/System/Reflection/CorElementType.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/Marshal-dep.h>
#include <System.Private.CoreLib/System/Runtime/Loader/AssemblyLoadContext-dep.h>
#include <System.Private.CoreLib/System/RuntimeTypeHandle-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/TypeLoadException-dep.h>

namespace System::Private::CoreLib::System::RuntimeTypeHandleNamespace {
using namespace System::Reflection;
using namespace System::Runtime::InteropServices;
using namespace System::Runtime::Loader;

RuntimeMethodHandleInternal RuntimeTypeHandle::IntroducedMethodEnumerator::get_Current() {
  return _handle;
}

RuntimeTypeHandle::IntroducedMethodEnumerator::IntroducedMethodEnumerator(RuntimeType type) {
  _handle = GetFirstIntroducedMethod(type);
  _firstCall = true;
}

Boolean RuntimeTypeHandle::IntroducedMethodEnumerator::MoveNext() {
  if (_firstCall) {
    _firstCall = false;
  } else if (_handle.get_Value() != IntPtr::Zero) {
    GetNextIntroducedMethod(_handle);
  }

  return !(_handle.get_Value() == IntPtr::Zero);
}

RuntimeTypeHandle::IntroducedMethodEnumerator RuntimeTypeHandle::IntroducedMethodEnumerator::GetEnumerator() {
  return *this;
}

IntPtr RuntimeTypeHandle::get_Value() {
  if (!(m_type != nullptr)) {
    return IntPtr::Zero;
  }
  return m_type->m_handle;
}

RuntimeTypeHandle RuntimeTypeHandle::GetNativeHandle() {
  RuntimeType type = m_type;
  if (type == nullptr) {
    rt::throw_exception<ArgumentNullException>(nullptr, SR::get_Arg_InvalidHandle());
  }
  return RuntimeTypeHandle(type);
}

RuntimeType RuntimeTypeHandle::GetTypeChecked() {
  RuntimeType type = m_type;
  if (type == nullptr) {
    rt::throw_exception<ArgumentNullException>(nullptr, SR::get_Arg_InvalidHandle());
  }
  return type;
}

Type RuntimeTypeHandle::GetTypeHelper(Type typeStart, Array<Type> genericArgs, IntPtr pModifiers, Int32 cModifiers) {
  Type type = typeStart;
  if (genericArgs != nullptr) {
    type = type->MakeGenericType(genericArgs);
  }
  if (cModifiers > 0) {
    Int32* value = (Int32*)pModifiers.ToPointer();
    for (Int32 i = 0; i < cModifiers; i++) {
      type = (((Byte)Marshal::ReadInt32((IntPtr)value, i * 4) != 15) ? (((Byte)Marshal::ReadInt32((IntPtr)value, i * 4) != 16) ? (((Byte)Marshal::ReadInt32((IntPtr)value, i * 4) != 29) ? type->MakeArrayType(Marshal::ReadInt32((IntPtr)value, ++i * 4)) : type->MakeArrayType()) : type->MakeByRefType()) : type->MakePointerType());
    }
  }
  return type;
}

Boolean RuntimeTypeHandle::op_Equality(RuntimeTypeHandle left, Object right) {
  return left.Equals(right);
}

Boolean RuntimeTypeHandle::op_Equality(Object left, RuntimeTypeHandle right) {
  return right.Equals(left);
}

Boolean RuntimeTypeHandle::op_Inequality(RuntimeTypeHandle left, Object right) {
  return !left.Equals(right);
}

Boolean RuntimeTypeHandle::op_Inequality(Object left, RuntimeTypeHandle right) {
  return !right.Equals(left);
}

Int32 RuntimeTypeHandle::GetHashCode() {
  if (!(m_type != nullptr)) {
    return 0;
  }
  return m_type->GetHashCode();
}

Boolean RuntimeTypeHandle::Equals(Object obj) {
  if (!rt::is<RuntimeTypeHandle>(obj)) {
    return false;
  }
  return ((RuntimeTypeHandle)obj).m_type == m_type;
}

Boolean RuntimeTypeHandle::Equals(RuntimeTypeHandle handle) {
  return handle.m_type == m_type;
}

RuntimeTypeHandle::RuntimeTypeHandle(RuntimeType type) {
  m_type = type;
}

Boolean RuntimeTypeHandle::IsTypeDefinition(RuntimeType type) {
  CorElementType corElementType = GetCorElementType(type);
  if (((Int32)corElementType < 1 || (Int32)corElementType >= 15) && corElementType != CorElementType::ELEMENT_TYPE_VALUETYPE && corElementType != CorElementType::ELEMENT_TYPE_CLASS && corElementType != CorElementType::ELEMENT_TYPE_TYPEDBYREF && corElementType != CorElementType::ELEMENT_TYPE_I && corElementType != CorElementType::ELEMENT_TYPE_U && corElementType != CorElementType::ELEMENT_TYPE_OBJECT) {
    return false;
  }
  if (HasInstantiation(type) && !IsGenericTypeDefinition(type)) {
    return false;
  }
  return true;
}

Boolean RuntimeTypeHandle::IsPrimitive(RuntimeType type) {
  CorElementType corElementType = GetCorElementType(type);
  if (((Int32)corElementType < 2 || (Int32)corElementType > 13) && corElementType != CorElementType::ELEMENT_TYPE_I) {
    return corElementType == CorElementType::ELEMENT_TYPE_U;
  }
  return true;
}

Boolean RuntimeTypeHandle::IsByRef(RuntimeType type) {
  CorElementType corElementType = GetCorElementType(type);
  return corElementType == CorElementType::ELEMENT_TYPE_BYREF;
}

Boolean RuntimeTypeHandle::IsPointer(RuntimeType type) {
  CorElementType corElementType = GetCorElementType(type);
  return corElementType == CorElementType::ELEMENT_TYPE_PTR;
}

Boolean RuntimeTypeHandle::IsArray(RuntimeType type) {
  CorElementType corElementType = GetCorElementType(type);
  if (corElementType != CorElementType::ELEMENT_TYPE_ARRAY) {
    return corElementType == CorElementType::ELEMENT_TYPE_SZARRAY;
  }
  return true;
}

Boolean RuntimeTypeHandle::IsSZArray(RuntimeType type) {
  CorElementType corElementType = GetCorElementType(type);
  return corElementType == CorElementType::ELEMENT_TYPE_SZARRAY;
}

Boolean RuntimeTypeHandle::HasElementType(RuntimeType type) {
  CorElementType corElementType = GetCorElementType(type);
  if (corElementType != CorElementType::ELEMENT_TYPE_ARRAY && corElementType != CorElementType::ELEMENT_TYPE_SZARRAY && corElementType != CorElementType::ELEMENT_TYPE_PTR) {
    return corElementType == CorElementType::ELEMENT_TYPE_BYREF;
  }
  return true;
}

Array<IntPtr> RuntimeTypeHandle::CopyRuntimeTypeHandles(Array<RuntimeTypeHandle> inHandles, Int32& length) {
  if (inHandles == nullptr || inHandles->get_Length() == 0) {
    length = 0;
    return nullptr;
  }
  Array<IntPtr> array = rt::newarr<Array<IntPtr>>(inHandles->get_Length());
  for (Int32 i = 0; i < inHandles->get_Length(); i++) {
    array[i] = inHandles[i].get_Value();
  }
  length = array->get_Length();
  return array;
}

Array<IntPtr> RuntimeTypeHandle::CopyRuntimeTypeHandles(Array<Type> inHandles, Int32& length) {
  if (inHandles == nullptr || inHandles->get_Length() == 0) {
    length = 0;
    return nullptr;
  }
  Array<IntPtr> array = rt::newarr<Array<IntPtr>>(inHandles->get_Length());
  for (Int32 i = 0; i < inHandles->get_Length(); i++) {
    array[i] = inHandles[i]->GetTypeHandleInternal().get_Value();
  }
  length = array->get_Length();
  return array;
}

RuntimeType RuntimeTypeHandle::GetRuntimeType() {
  return m_type;
}

ModuleHandle RuntimeTypeHandle::GetModuleHandle() {
  return ModuleHandle(GetModule(m_type));
}

RuntimeTypeHandle::IntroducedMethodEnumerator RuntimeTypeHandle::GetIntroducedMethods(RuntimeType type) {
  return IntroducedMethodEnumerator(type);
}

Array<Type> RuntimeTypeHandle::GetConstraints() {
  Array<Type> o = nullptr;
  RuntimeTypeHandle rth = GetNativeHandle();
  GetConstraints(QCallTypeHandle(rth), ObjectHandleOnStack::Create(o));
  return o;
}

IntPtr RuntimeTypeHandle::GetGCHandle(GCHandleType type) {
  RuntimeTypeHandle rth = GetNativeHandle();
  return GetGCHandle(QCallTypeHandle(rth), type);
}

IntPtr RuntimeTypeHandle::FreeGCHandle(IntPtr objHandle) {
  RuntimeTypeHandle rth = GetNativeHandle();
  return FreeGCHandle(QCallTypeHandle(rth), objHandle);
}

void RuntimeTypeHandle::VerifyInterfaceIsImplemented(RuntimeTypeHandle interfaceHandle) {
  RuntimeTypeHandle rth = GetNativeHandle();
  RuntimeTypeHandle rth2 = interfaceHandle.GetNativeHandle();
  VerifyInterfaceIsImplemented(QCallTypeHandle(rth), QCallTypeHandle(rth2));
}

RuntimeMethodHandleInternal RuntimeTypeHandle::GetInterfaceMethodImplementation(RuntimeTypeHandle interfaceHandle, RuntimeMethodHandleInternal interfaceMethodHandle) {
  RuntimeTypeHandle rth = GetNativeHandle();
  RuntimeTypeHandle rth2 = interfaceHandle.GetNativeHandle();
  return GetInterfaceMethodImplementation(QCallTypeHandle(rth), QCallTypeHandle(rth2), interfaceMethodHandle);
}

Boolean RuntimeTypeHandle::IsVisible(RuntimeType type) {
  return _IsVisible(QCallTypeHandle(type));
}

String RuntimeTypeHandle::ConstructName(TypeNameFormatFlags formatFlags) {
  String s = nullptr;
  RuntimeTypeHandle rth = GetNativeHandle();
  ConstructName(QCallTypeHandle(rth), formatFlags, StringHandleOnStack(s));
  return s;
}

MdUtf8String RuntimeTypeHandle::GetUtf8Name(RuntimeType type) {
  return MdUtf8String(_GetUtf8Name(type));
}

RuntimeType RuntimeTypeHandle::GetTypeByName(String name, Boolean throwOnError, Boolean ignoreCase, StackCrawlMark& stackMark) {
  return GetTypeByName(name, throwOnError, ignoreCase, stackMark, AssemblyLoadContext::in::get_CurrentContextualReflectionContext());
}

RuntimeType RuntimeTypeHandle::GetTypeByName(String name, Boolean throwOnError, Boolean ignoreCase, StackCrawlMark& stackMark, AssemblyLoadContext assemblyLoadContext) {
  if (String::in::IsNullOrEmpty(name)) {
    if (throwOnError) {
      rt::throw_exception<TypeLoadException>(SR::get_Arg_TypeLoadNullStr());
    }
    return nullptr;
  }
  RuntimeType o = nullptr;
  Object o2 = nullptr;
  AssemblyLoadContext o3 = assemblyLoadContext;
  GetTypeByName(name, throwOnError, ignoreCase, StackCrawlMarkHandle(stackMark), ObjectHandleOnStack::Create(o3), ObjectHandleOnStack::Create(o), ObjectHandleOnStack::Create(o2));
  GC::KeepAlive(o2);
  return o;
}

RuntimeType RuntimeTypeHandle::GetTypeByNameUsingCARules(String name, RuntimeModule scope) {
  if (String::in::IsNullOrEmpty(name)) {
    rt::throw_exception<ArgumentException>(nullptr, "name");
  }
  RuntimeType o = nullptr;
  GetTypeByNameUsingCARules(name, QCallModule(scope), ObjectHandleOnStack::Create(o));
  return o;
}

Array<RuntimeType> RuntimeTypeHandle::GetInstantiationInternal() {
  Array<RuntimeType> o = nullptr;
  RuntimeTypeHandle rth = GetNativeHandle();
  GetInstantiation(QCallTypeHandle(rth), ObjectHandleOnStack::Create(o), Interop::BOOL::TRUE);
  return o;
}

Array<Type> RuntimeTypeHandle::GetInstantiationPublic() {
  Array<Type> o = nullptr;
  RuntimeTypeHandle rth = GetNativeHandle();
  GetInstantiation(QCallTypeHandle(rth), ObjectHandleOnStack::Create(o), Interop::BOOL::FALSE);
  return o;
}

RuntimeType RuntimeTypeHandle::Instantiate(Array<Type> inst) {
  Int32 length;
  {
    IntPtr* pInst = rt::fixed(CopyRuntimeTypeHandles(inst, length));
    RuntimeType o = nullptr;
    RuntimeTypeHandle rth = GetNativeHandle();
    Instantiate(QCallTypeHandle(rth), pInst, length, ObjectHandleOnStack::Create(o));
    GC::KeepAlive(inst);
    return o;
  }
}

RuntimeType RuntimeTypeHandle::MakeArray(Int32 rank) {
  RuntimeType o = nullptr;
  RuntimeTypeHandle rth = GetNativeHandle();
  MakeArray(QCallTypeHandle(rth), rank, ObjectHandleOnStack::Create(o));
  return o;
}

RuntimeType RuntimeTypeHandle::MakeSZArray() {
  RuntimeType o = nullptr;
  RuntimeTypeHandle rth = GetNativeHandle();
  MakeSZArray(QCallTypeHandle(rth), ObjectHandleOnStack::Create(o));
  return o;
}

RuntimeType RuntimeTypeHandle::MakeByRef() {
  RuntimeType o = nullptr;
  RuntimeTypeHandle rth = GetNativeHandle();
  MakeByRef(QCallTypeHandle(rth), ObjectHandleOnStack::Create(o));
  return o;
}

RuntimeType RuntimeTypeHandle::MakePointer() {
  RuntimeType o = nullptr;
  RuntimeTypeHandle rth = GetNativeHandle();
  MakePointer(QCallTypeHandle(rth), ObjectHandleOnStack::Create(o));
  return o;
}

RuntimeType RuntimeTypeHandle::GetGenericTypeDefinition(RuntimeType type) {
  RuntimeType o = type;
  if (HasInstantiation(o) && !IsGenericTypeDefinition(o)) {
    RuntimeTypeHandle rth = o->GetTypeHandleInternal();
    GetGenericTypeDefinition(QCallTypeHandle(rth), ObjectHandleOnStack::Create(o));
  }
  return o;
}

Int32 RuntimeTypeHandle::GetGenericVariableIndex() {
  RuntimeType typeChecked = GetTypeChecked();
  if (!IsGenericVariable(typeChecked)) {
    rt::throw_exception<InvalidOperationException>(SR::get_Arg_NotGenericParameter());
  }
  return GetGenericVariableIndex(typeChecked);
}

Boolean RuntimeTypeHandle::ContainsGenericVariables() {
  return ContainsGenericVariables(GetTypeChecked());
}

Boolean RuntimeTypeHandle::SatisfiesConstraints(RuntimeType paramType, Array<RuntimeType> typeContext, Array<RuntimeType> methodContext, RuntimeType toType) {
  Array<Type> inHandles = typeContext;
  Int32 length;
  Array<IntPtr> array = CopyRuntimeTypeHandles(inHandles, length);
  inHandles = methodContext;
  Int32 length2;
  Array<IntPtr> array2 = CopyRuntimeTypeHandles(inHandles, length2);
  {
    IntPtr* pTypeContext = rt::fixed(array);
    {
      IntPtr* pMethodContext = rt::fixed(array2);
      Boolean result = SatisfiesConstraints(paramType, pTypeContext, length, pMethodContext, length2, toType);
      GC::KeepAlive(typeContext);
      GC::KeepAlive(methodContext);
      return result;
    }
  }
}

MetadataImport RuntimeTypeHandle::GetMetadataImport(RuntimeType type) {
  return MetadataImport(_GetMetadataImport(type), type);
}

void RuntimeTypeHandle::GetObjectData(SerializationInfo info, StreamingContext context) {
  rt::throw_exception<PlatformNotSupportedException>();
}

} // namespace System::Private::CoreLib::System::RuntimeTypeHandleNamespace
