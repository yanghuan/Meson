#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Reflection/MetadataImport.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(DateTime)
FORWARDS(Decimal)
FORWARD(IRuntimeMethodInfo)
FORWARD(Object)
FORWARD(Signature)
FORWARD(String)
FORWARD(Type)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(IList, T)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System::Reflection {
enum class ParameterAttributes;
FORWARD(CustomAttributeData)
FORWARD(MemberInfo)
FORWARD(MethodBase)
FORWARD(MethodInfo)
FORWARD(ParameterInfo)
FORWARD(RuntimeModule)
FORWARD(RuntimePropertyInfo)
namespace RuntimeParameterInfoNamespace {
using namespace Collections::Generic;
using Collections::Generic::IList;
CLASS(RuntimeParameterInfo) {
  public: Type get_ParameterType();
  public: String get_Name();
  public: Boolean get_HasDefaultValue();
  public: Object get_DefaultValue();
  public: Object get_RawDefaultValue();
  public: Int32 get_MetadataToken();
  public: static Array<ParameterInfo> GetParameters(IRuntimeMethodInfo method, MemberInfo member, Signature sig);
  public: static ParameterInfo GetReturnParameter(IRuntimeMethodInfo method, MemberInfo member, Signature sig);
  public: static Array<ParameterInfo> GetParameters(IRuntimeMethodInfo methodHandle, MemberInfo member, Signature sig, ParameterInfo& returnParameter, Boolean fetchReturnParameter);
  public: void SetName(String name);
  public: void SetAttributes(ParameterAttributes attributes);
  public: void Ctor(RuntimeParameterInfo accessor, RuntimePropertyInfo property);
  private: void Ctor(RuntimeParameterInfo accessor, MemberInfo member);
  private: void Ctor(Signature signature, MetadataImport scope, Int32 tkParamDef, Int32 position, ParameterAttributes attributes, MemberInfo member);
  public: void Ctor(MethodInfo owner, String name, Type parameterType, Int32 position);
  private: Object GetDefaultValue(Boolean raw);
  private: Object GetDefaultValueInternal(Boolean raw);
  private: static Decimal GetRawDecimalConstant(CustomAttributeData attr);
  private: static DateTime GetRawDateTimeConstant(CustomAttributeData attr);
  private: static Object GetRawConstant(CustomAttributeData attr);
  public: RuntimeModule GetRuntimeModule();
  public: Array<Type> GetRequiredCustomModifiers();
  public: Array<Type> GetOptionalCustomModifiers();
  public: Array<Object> GetCustomAttributes(Boolean inherit);
  public: Array<Object> GetCustomAttributes(Type attributeType, Boolean inherit);
  public: Boolean IsDefined(Type attributeType, Boolean inherit);
  public: IList<CustomAttributeData> GetCustomAttributesData();
  private: static void SCtor();
  private: static Type s_DecimalConstantAttributeType;
  private: static Type s_CustomConstantAttributeType;
  private: Int32 m_tkParamDef;
  private: MetadataImport m_scope;
  private: Signature m_signature;
  private: Boolean m_nameIsCached;
  private: Boolean m_noMetadata;
  private: Boolean m_noDefaultValue;
  private: MethodBase m_originalMember;
};
} // namespace RuntimeParameterInfoNamespace
using RuntimeParameterInfo = RuntimeParameterInfoNamespace::RuntimeParameterInfo;
} // namespace System::Private::CoreLib::System::Reflection
