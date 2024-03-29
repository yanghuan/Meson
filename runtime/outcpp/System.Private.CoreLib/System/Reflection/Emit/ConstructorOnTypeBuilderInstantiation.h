#pragma once

#include <System.Private.CoreLib/System/Reflection/ConstructorInfo.h>

namespace System::Private::CoreLib::System::Reflection {
enum class BindingFlags : int32_t;
enum class CallingConventions : int32_t;
enum class MemberTypes : int32_t;
enum class MethodAttributes : int32_t;
enum class MethodImplAttributes : int32_t;
FORWARD(Binder)
FORWARD(Module)
FORWARD(ParameterInfo)
} // namespace System::Private::CoreLib::System::Reflection
namespace System::Private::CoreLib::System {
FORWARD_(Array)
FORWARDS(Boolean)
FORWARDS(Int32)
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
namespace ConstructorOnTypeBuilderInstantiationNamespace {
using namespace System::Globalization;
CLASS(ConstructorOnTypeBuilderInstantiation) : public ConstructorInfo::in {
  public: MemberTypes get_MemberType();
  public: String get_Name();
  public: Type get_DeclaringType();
  public: Type get_ReflectedType();
  public: Int32 get_MetadataTokenInternal();
  public: Module get_Module();
  public: RuntimeMethodHandle get_MethodHandle();
  public: MethodAttributes get_Attributes();
  public: CallingConventions get_CallingConvention();
  public: Boolean get_IsGenericMethodDefinition();
  public: Boolean get_ContainsGenericParameters();
  public: Boolean get_IsGenericMethod();
  public: static ConstructorInfo GetConstructor(ConstructorInfo Constructor, TypeBuilderInstantiation type);
  public: void ctor(ConstructorInfo constructor, TypeBuilderInstantiation type);
  public: Array<Type> GetParameterTypes();
  public: Type GetReturnType();
  public: Array<Object> GetCustomAttributes(Boolean inherit);
  public: Array<Object> GetCustomAttributes(Type attributeType, Boolean inherit);
  public: Boolean IsDefined(Type attributeType, Boolean inherit);
  public: Array<ParameterInfo> GetParameters();
  public: MethodImplAttributes GetMethodImplementationFlags();
  public: Object Invoke(Object obj, BindingFlags invokeAttr, Binder binder, Array<Object> parameters, CultureInfo culture);
  public: Array<Type> GetGenericArguments();
  public: Object Invoke(BindingFlags invokeAttr, Binder binder, Array<Object> parameters, CultureInfo culture);
  public: ConstructorInfo m_ctor;
  private: TypeBuilderInstantiation m_type;
};
} // namespace ConstructorOnTypeBuilderInstantiationNamespace
using ConstructorOnTypeBuilderInstantiation = ConstructorOnTypeBuilderInstantiationNamespace::ConstructorOnTypeBuilderInstantiation;
} // namespace System::Private::CoreLib::System::Reflection::Emit
