#include "MethodBase-dep.h"

#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/DBNull-dep.h>
#include <System.Private.CoreLib/System/Int32-dep.h>
#include <System.Private.CoreLib/System/InvalidOperationException-dep.h>
#include <System.Private.CoreLib/System/NotImplemented-dep.h>
#include <System.Private.CoreLib/System/NotSupportedException-dep.h>
#include <System.Private.CoreLib/System/Reflection/ConstructorInfo-dep.h>
#include <System.Private.CoreLib/System/Reflection/MethodBase-dep.h>
#include <System.Private.CoreLib/System/Reflection/RuntimeMethodInfo-dep.h>
#include <System.Private.CoreLib/System/RuntimeType-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/String-dep.h>
#include <System.Private.CoreLib/System/Threading/StackCrawlMark.h>
#include <System.Private.CoreLib/System/Type-dep.h>

namespace System::Private::CoreLib::System::Reflection::MethodBaseNamespace {
using namespace System::Threading;

MethodImplAttributes MethodBase___::get_MethodImplementationFlags() {
  return GetMethodImplementationFlags();
}

CallingConventions MethodBase___::get_CallingConvention() {
  return CallingConventions::Standard;
}

Boolean MethodBase___::get_IsAbstract() {
}

Boolean MethodBase___::get_IsConstructor() {
  if (rt::is<ConstructorInfo>((MethodBase)this) && !get_IsStatic()) {
  }
  return false;
}

Boolean MethodBase___::get_IsFinal() {
}

Boolean MethodBase___::get_IsHideBySig() {
}

Boolean MethodBase___::get_IsSpecialName() {
}

Boolean MethodBase___::get_IsStatic() {
}

Boolean MethodBase___::get_IsVirtual() {
}

Boolean MethodBase___::get_IsAssembly() {
}

Boolean MethodBase___::get_IsFamily() {
}

Boolean MethodBase___::get_IsFamilyAndAssembly() {
}

Boolean MethodBase___::get_IsFamilyOrAssembly() {
}

Boolean MethodBase___::get_IsPrivate() {
}

Boolean MethodBase___::get_IsPublic() {
}

Boolean MethodBase___::get_IsConstructedGenericMethod() {
  if (get_IsGenericMethod()) {
    return !get_IsGenericMethodDefinition();
  }
  return false;
}

Boolean MethodBase___::get_IsGenericMethod() {
  return false;
}

Boolean MethodBase___::get_IsGenericMethodDefinition() {
  return false;
}

Boolean MethodBase___::get_ContainsGenericParameters() {
  return false;
}

Boolean MethodBase___::get_IsSecurityCritical() {
  rt::throw_exception(NotImplemented::get_ByDesign());
}

Boolean MethodBase___::get_IsSecuritySafeCritical() {
  rt::throw_exception(NotImplemented::get_ByDesign());
}

Boolean MethodBase___::get_IsSecurityTransparent() {
  rt::throw_exception(NotImplemented::get_ByDesign());
}

MethodBase MethodBase___::GetMethodFromHandle(RuntimeMethodHandle handle) {
  if (handle.IsNullHandle()) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_InvalidHandle());
  }
  MethodBase methodBase = RuntimeType::in::GetMethodBase(handle.GetMethodInfo());
}

MethodBase MethodBase___::GetMethodFromHandle(RuntimeMethodHandle handle, RuntimeTypeHandle declaringType) {
  if (handle.IsNullHandle()) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_InvalidHandle());
  }
  return RuntimeType::in::GetMethodBase(declaringType.GetRuntimeType(), handle.GetMethodInfo());
}

MethodBase MethodBase___::GetCurrentMethod() {
  StackCrawlMark stackMark = StackCrawlMark::LookForMyCaller;
  return RuntimeMethodInfo::in::InternalGetCurrentMethod(stackMark);
}

IntPtr MethodBase___::GetMethodDesc() {
  return get_MethodHandle().get_Value();
}

Array<ParameterInfo> MethodBase___::GetParametersNoCopy() {
  return GetParameters();
}

Array<Type> MethodBase___::GetParameterTypes() {
  Array<ParameterInfo> parametersNoCopy = GetParametersNoCopy();
  Array<Type> array = rt::newarr<Array<Type>>(parametersNoCopy->get_Length());
  for (Int32 i = 0; i < parametersNoCopy->get_Length(); i++) {
    array[i] = parametersNoCopy[i]->get_ParameterType();
  }
  return array;
}

Array<Object> MethodBase___::CheckArguments(Array<Object> parameters, Binder binder, BindingFlags invokeAttr, CultureInfo culture, Signature sig) {
  Array<Object> array = rt::newarr<Array<Object>>(parameters->get_Length());
  Array<ParameterInfo> array2 = nullptr;
  for (Int32 i = 0; i < parameters->get_Length(); i++) {
    Object obj = parameters[i];
    RuntimeType runtimeType = sig->get_Arguments()[i];
    if (obj == Type::in::Missing) {
      if (array2 == nullptr) {
        array2 = GetParametersNoCopy();
      }
      if (array2[i]->get_DefaultValue() == DBNull::in::Value) {
        rt::throw_exception<ArgumentException>(SR::get_Arg_VarMissNull(), "parameters");
      }
      obj = array2[i]->get_DefaultValue();
    }
    array[i] = runtimeType->CheckValue(obj, binder, culture, invokeAttr);
  }
  return array;
}

void MethodBase___::ctor() {
}

MethodBody MethodBase___::GetMethodBody() {
  rt::throw_exception<InvalidOperationException>();
}

Array<Type> MethodBase___::GetGenericArguments() {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_SubclassOverride());
}

Object MethodBase___::Invoke(Object obj, Array<Object> parameters) {
  return Invoke(obj, BindingFlags::Default, nullptr, parameters, nullptr);
}

Boolean MethodBase___::Equals(Object obj) {
}

Int32 MethodBase___::GetHashCode() {
}

Boolean MethodBase___::op_Equality(MethodBase left, MethodBase right) {
  if ((Object)right == nullptr) {
    if ((Object)left != nullptr) {
      return false;
    }
    return true;
  }
  if ((Object)left == right) {
    return true;
  }
}

Boolean MethodBase___::op_Inequality(MethodBase left, MethodBase right) {
  return !(left == right);
}

void MethodBase___::AppendParameters(ValueStringBuilder& sbParamList, Array<Type> parameterTypes, CallingConventions callingConvention) {
  String s = "";
}

} // namespace System::Private::CoreLib::System::Reflection::MethodBaseNamespace
