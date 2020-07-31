#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Reflection/Emit/PropertyToken.h>
#include <System.Private.CoreLib/System/Reflection/PropertyInfo.h>

namespace System::Private::CoreLib::System::Reflection {
enum class BindingFlags;
enum class MethodSemanticsAttributes;
enum class PropertyAttributes;
FORWARD(Binder)
FORWARD(ConstructorInfo)
FORWARD(MethodInfo)
FORWARD(Module)
FORWARD(ParameterInfo)
} // namespace System::Private::CoreLib::System::Reflection
namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
FORWARDS(Byte)
FORWARD(Object)
FORWARD(String)
FORWARD(Type)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Globalization {
FORWARD(CultureInfo)
} // namespace System::Private::CoreLib::System::Globalization
namespace System::Private::CoreLib::System::Reflection::Emit {
FORWARD(CustomAttributeBuilder)
FORWARD(MethodBuilder)
FORWARD(ModuleBuilder)
FORWARD(SignatureHelper)
FORWARD(TypeBuilder)
namespace PropertyBuilderNamespace {
using namespace Globalization;
CLASS(PropertyBuilder) : public PropertyInfo::in {
  public: PropertyToken get_PropertyToken();
  public: Module get_Module();
  public: Type get_PropertyType();
  public: PropertyAttributes get_Attributes();
  public: Boolean get_CanRead();
  public: Boolean get_CanWrite();
  public: String get_Name();
  public: Type get_DeclaringType();
  public: Type get_ReflectedType();
  public: void Ctor(ModuleBuilder mod, String name, SignatureHelper sig, PropertyAttributes attr, Type returnType, PropertyToken prToken, TypeBuilder containingType);
  public: void SetConstant(Object defaultValue);
  private: void SetMethodSemantics(MethodBuilder mdBuilder, MethodSemanticsAttributes semantics);
  public: void SetGetMethod(MethodBuilder mdBuilder);
  public: void SetSetMethod(MethodBuilder mdBuilder);
  public: void AddOtherMethod(MethodBuilder mdBuilder);
  public: void SetCustomAttribute(ConstructorInfo con, Array<Byte> binaryAttribute);
  public: void SetCustomAttribute(CustomAttributeBuilder customBuilder);
  public: Object GetValue(Object obj, Array<Object> index);
  public: Object GetValue(Object obj, BindingFlags invokeAttr, Binder binder, Array<Object> index, CultureInfo culture);
  public: void SetValue(Object obj, Object value, Array<Object> index);
  public: void SetValue(Object obj, Object value, BindingFlags invokeAttr, Binder binder, Array<Object> index, CultureInfo culture);
  public: Array<MethodInfo> GetAccessors(Boolean nonPublic);
  public: MethodInfo GetGetMethod(Boolean nonPublic);
  public: MethodInfo GetSetMethod(Boolean nonPublic);
  public: Array<ParameterInfo> GetIndexParameters();
  public: Array<Object> GetCustomAttributes(Boolean inherit);
  public: Array<Object> GetCustomAttributes(Type attributeType, Boolean inherit);
  public: Boolean IsDefined(Type attributeType, Boolean inherit);
  private: String m_name;
  private: PropertyToken m_prToken;
  private: Int32 m_tkProperty;
  private: ModuleBuilder m_moduleBuilder;
  private: SignatureHelper m_signature;
  private: PropertyAttributes m_attributes;
  private: Type m_returnType;
  private: MethodInfo m_getMethod;
  private: MethodInfo m_setMethod;
  private: TypeBuilder m_containingType;
};
} // namespace PropertyBuilderNamespace
using PropertyBuilder = PropertyBuilderNamespace::PropertyBuilder;
} // namespace System::Private::CoreLib::System::Reflection::Emit
