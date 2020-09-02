#include "MethodBase-dep.h"

#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/DBNull-dep.h>
#include <System.Private.CoreLib/System/Int32-dep.h>
#include <System.Private.CoreLib/System/InvalidOperationException-dep.h>
#include <System.Private.CoreLib/System/MemoryExtensions-dep.h>
#include <System.Private.CoreLib/System/NotImplemented-dep.h>
#include <System.Private.CoreLib/System/NotSupportedException-dep.h>
#include <System.Private.CoreLib/System/Object-dep.h>
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
  return (get_Attributes() & MethodAttributes::Abstract) != 0;
}

Boolean MethodBase___::get_IsConstructor() {
  if (rt::is<ConstructorInfo>((MethodBase)this) && !get_IsStatic()) {
    return (get_Attributes() & MethodAttributes::RTSpecialName) == MethodAttributes::RTSpecialName;
  }
  return false;
}

Boolean MethodBase___::get_IsFinal() {
  return (get_Attributes() & MethodAttributes::Final) != 0;
}

Boolean MethodBase___::get_IsHideBySig() {
  return (get_Attributes() & MethodAttributes::HideBySig) != 0;
}

Boolean MethodBase___::get_IsSpecialName() {
  return (get_Attributes() & MethodAttributes::SpecialName) != 0;
}

Boolean MethodBase___::get_IsStatic() {
  return (get_Attributes() & MethodAttributes::Static) != 0;
}

Boolean MethodBase___::get_IsVirtual() {
  return (get_Attributes() & MethodAttributes::Virtual) != 0;
}

Boolean MethodBase___::get_IsAssembly() {
  return (get_Attributes() & MethodAttributes::MemberAccessMask) == MethodAttributes::Assembly;
}

Boolean MethodBase___::get_IsFamily() {
  return (get_Attributes() & MethodAttributes::MemberAccessMask) == MethodAttributes::Family;
}

Boolean MethodBase___::get_IsFamilyAndAssembly() {
  return (get_Attributes() & MethodAttributes::MemberAccessMask) == MethodAttributes::FamANDAssem;
}

Boolean MethodBase___::get_IsFamilyOrAssembly() {
  return (get_Attributes() & MethodAttributes::MemberAccessMask) == MethodAttributes::FamORAssem;
}

Boolean MethodBase___::get_IsPrivate() {
  return (get_Attributes() & MethodAttributes::MemberAccessMask) == MethodAttributes::Private;
}

Boolean MethodBase___::get_IsPublic() {
  return (get_Attributes() & MethodAttributes::MemberAccessMask) == MethodAttributes::Public;
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
  Type type = ((Object)methodBase != nullptr) ? methodBase->get_DeclaringType() : nullptr;
  if (type != nullptr && type->get_IsGenericType()) {
    rt::throw_exception<ArgumentException>(SR::Format(SR::get_Argument_MethodDeclaringTypeGeneric(), methodBase, type->GetGenericTypeDefinition()));
  }
  return methodBase;
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
  return MemberInfo::in::Equals(obj);
}

Int32 MethodBase___::GetHashCode() {
  return MemberInfo::in::GetHashCode();
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
  if ((Object)left != nullptr) {
    return left->Equals(right);
  }
  return false;
}

Boolean MethodBase___::op_Inequality(MethodBase left, MethodBase right) {
  return !(left == right);
}

void MethodBase___::AppendParameters(ValueStringBuilder& sbParamList, Array<Type> parameterTypes, CallingConventions callingConvention) {
  String s = "";
  for (Type&& type : *parameterTypes) {
    sbParamList.Append(s);
    String text = type->FormatTypeName();
    if (type->get_IsByRef()) {
      sbParamList.Append(MemoryExtensions::TrimEnd(MemoryExtensions::AsSpan(text), 38));
      sbParamList.Append(" ByRef");
    } else {
      sbParamList.Append(text);
    }
    s = ", ";
  }
  if ((callingConvention & CallingConventions::VarArgs) == CallingConventions::VarArgs) {
    sbParamList.Append(s);
    sbParamList.Append("...");
  }
}

} // namespace System::Private::CoreLib::System::Reflection::MethodBaseNamespace
