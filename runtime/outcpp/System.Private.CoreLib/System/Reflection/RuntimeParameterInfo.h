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
FORWARD(MemberInfo)
FORWARD(ParameterInfo)
enum class ParameterAttributes;
FORWARD(CustomAttributeData)
FORWARD(RuntimeModule)
FORWARD(MethodBase)
namespace RuntimeParameterInfoNamespace {
using namespace ::System::Private::CoreLib::System::Collections::Generic;
using ::System::Private::CoreLib::System::Collections::Generic::IList;
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
