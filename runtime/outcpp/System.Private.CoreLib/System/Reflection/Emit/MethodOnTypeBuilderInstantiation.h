#pragma once

#include <System.Private.CoreLib/System/Reflection/MethodInfo.h>

namespace System::Private::CoreLib::System::Reflection {
enum class BindingFlags : int32_t;
enum class CallingConventions : int32_t;
enum class MemberTypes : int32_t;
enum class MethodAttributes : int32_t;
enum class MethodImplAttributes : int32_t;
FORWARD(Binder)
FORWARD(ICustomAttributeProvider)
FORWARD(Module)
FORWARD(ParameterInfo)
} // namespace System::Private::CoreLib::System::Reflection
namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
FORWARD(Object)
FORWARDS(RuntimeMethodHandle)
FORWARD(String)
FORWARD(Type)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Globalization {
FORWARD(CultureInfo)
} // namespace System::Private::CoreLib::System::Globalization
namespace System::Private::CoreLib::System::Reflection::Emit {
FORWARD(TypeBuilderInstantiation)
namespace MethodOnTypeBuilderInstantiationNamespace {
using namespace Globalization;
CLASS(MethodOnTypeBuilderInstantiation) : public MethodInfo::in {
  public: MemberTypes get_MemberType();
  public: String get_Name();
  public: Type get_DeclaringType();
  public: Type get_ReflectedType();
  public: Module get_Module();
  public: RuntimeMethodHandle get_MethodHandle();
  public: MethodAttributes get_Attributes();
  public: CallingConventions get_CallingConvention();
  public: Boolean get_IsGenericMethodDefinition();
  public: Boolean get_ContainsGenericParameters();
  public: Boolean get_IsGenericMethod();
  public: Type get_ReturnType();
  public: ParameterInfo get_ReturnParameter();
  public: ICustomAttributeProvider get_ReturnTypeCustomAttributes();
  public: static MethodInfo GetMethod(MethodInfo method, TypeBuilderInstantiation type);
  public: void ctor(MethodInfo method, TypeBuilderInstantiation type);
  public: Array<Type> GetParameterTypes();
  public: Array<Object> GetCustomAttributes(Boolean inherit);
  public: Array<Object> GetCustomAttributes(Type attributeType, Boolean inherit);
  public: Boolean IsDefined(Type attributeType, Boolean inherit);
  public: Array<ParameterInfo> GetParameters();
  public: MethodImplAttributes GetMethodImplementationFlags();
  public: Object Invoke(Object obj, BindingFlags invokeAttr, Binder binder, Array<Object> parameters, CultureInfo culture);
  public: Array<Type> GetGenericArguments();
  public: MethodInfo GetGenericMethodDefinition();
  public: MethodInfo MakeGenericMethod(Array<Type> typeArgs);
  public: MethodInfo GetBaseDefinition();
  public: MethodInfo m_method;
  private: TypeBuilderInstantiation m_type;
};
} // namespace MethodOnTypeBuilderInstantiationNamespace
using MethodOnTypeBuilderInstantiation = MethodOnTypeBuilderInstantiationNamespace::MethodOnTypeBuilderInstantiation;
} // namespace System::Private::CoreLib::System::Reflection::Emit
