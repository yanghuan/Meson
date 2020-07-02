#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Reflection {
enum class MemberTypes;
FORWARD(Module)
enum class MethodAttributes;
enum class CallingConventions;
FORWARD(ParameterInfo)
FORWARD(ICustomAttributeProvider)
FORWARD(MethodInfo)
enum class MethodImplAttributes;
enum class BindingFlags;
FORWARD(Binder)
} // namespace System::Private::CoreLib::System::Reflection
namespace System::Private::CoreLib::System {
FORWARD(String)
FORWARD(Type)
FORWARDS(RuntimeMethodHandle)
FORWARDS(Boolean)
FORWARD_(Array, T1, T2)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Globalization {
FORWARD(CultureInfo)
} // namespace System::Private::CoreLib::System::Globalization
namespace System::Private::CoreLib::System::Reflection::Emit {
FORWARD(TypeBuilderInstantiation)
namespace MethodOnTypeBuilderInstantiationNamespace {
using namespace ::System::Private::CoreLib::System::Globalization;
CLASS(MethodOnTypeBuilderInstantiation) {
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
