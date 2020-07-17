#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/RuntimeType.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
FORWARD(Object)
FORWARD(Signature)
FORWARD(String)
FORWARD(Type)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(IList, T)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System::Globalization {
FORWARD(CultureInfo)
} // namespace System::Private::CoreLib::System::Globalization
namespace System::Private::CoreLib::System::Reflection {
enum class BindingFlags;
enum class MemberTypes;
enum class PropertyAttributes;
FORWARD(Binder)
FORWARD(CustomAttributeData)
FORWARD(MemberInfo)
FORWARD(MethodInfo)
FORWARD(Module)
FORWARD(ParameterInfo)
FORWARD(RuntimeMethodInfo)
FORWARD(RuntimeModule)
namespace RuntimePropertyInfoNamespace {
using namespace Collections::Generic;
using namespace Globalization;
using Collections::Generic::IList;
CLASS(RuntimePropertyInfo) {
  public: Signature get_Signature();
  public: BindingFlags get_BindingFlags();
  public: MemberTypes get_MemberType();
  public: String get_Name();
  public: Type get_DeclaringType();
  public: Type get_ReflectedType();
  private: RuntimeType get_ReflectedTypeInternal();
  public: Int32 get_MetadataToken();
  public: Module get_Module();
  public: Boolean get_IsCollectible();
  public: Type get_PropertyType();
  public: PropertyAttributes get_Attributes();
  public: Boolean get_CanRead();
  public: Boolean get_CanWrite();
  public: void Ctor(Int32 tkProperty, RuntimeType declaredType, RuntimeType::in::RuntimeTypeCache reflectedTypeCache, Boolean& isPrivate);
  public: Boolean CacheEquals(Object o);
  public: Boolean EqualsSig(RuntimePropertyInfo target);
  public: String ToString();
  public: Array<Object> GetCustomAttributes(Boolean inherit);
  public: Array<Object> GetCustomAttributes(Type attributeType, Boolean inherit);
  public: Boolean IsDefined(Type attributeType, Boolean inherit);
  public: IList<CustomAttributeData> GetCustomAttributesData();
  public: Boolean HasSameMetadataDefinitionAs(MemberInfo other);
  public: RuntimeModule GetRuntimeModule();
  public: Array<Type> GetRequiredCustomModifiers();
  public: Array<Type> GetOptionalCustomModifiers();
  public: Object GetConstantValue(Boolean raw);
  public: Object GetConstantValue();
  public: Object GetRawConstantValue();
  public: Array<MethodInfo> GetAccessors(Boolean nonPublic);
  public: MethodInfo GetGetMethod(Boolean nonPublic);
  public: MethodInfo GetSetMethod(Boolean nonPublic);
  public: Array<ParameterInfo> GetIndexParameters();
  public: Array<ParameterInfo> GetIndexParametersNoCopy();
  public: Object GetValue(Object obj, Array<Object> index);
  public: Object GetValue(Object obj, BindingFlags invokeAttr, Binder binder, Array<Object> index, CultureInfo culture);
  public: void SetValue(Object obj, Object value, Array<Object> index);
  public: void SetValue(Object obj, Object value, BindingFlags invokeAttr, Binder binder, Array<Object> index, CultureInfo culture);
  private: Int32 m_token;
  private: String m_name;
  private: void* m_utf8name;
  private: PropertyAttributes m_flags;
  private: RuntimeType::in::RuntimeTypeCache m_reflectedTypeCache;
  private: RuntimeMethodInfo m_getterMethod;
  private: RuntimeMethodInfo m_setterMethod;
  private: Array<MethodInfo> m_otherMethod;
  private: RuntimeType m_declaringType;
  private: BindingFlags m_bindingFlags;
  private: Signature m_signature;
  private: Array<ParameterInfo> m_parameters;
};
} // namespace RuntimePropertyInfoNamespace
using RuntimePropertyInfo = RuntimePropertyInfoNamespace::RuntimePropertyInfo;
} // namespace System::Private::CoreLib::System::Reflection
