#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Int32.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
FORWARD(Object)
FORWARD(String)
FORWARD(Type)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(IEnumerable, T)
FORWARD(IList, T)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System::Reflection {
enum class ParameterAttributes;
FORWARD(CustomAttributeData)
FORWARD(MemberInfo)
namespace ParameterInfoNamespace {
using namespace Collections::Generic;
using namespace Runtime::Serialization;
using Collections::Generic::IList;
CLASS(ParameterInfo) {
  public: ParameterAttributes get_Attributes();
  public: MemberInfo get_Member();
  public: String get_Name();
  public: Type get_ParameterType();
  public: Int32 get_Position();
  public: Boolean get_IsIn();
  public: Boolean get_IsLcid();
  public: Boolean get_IsOptional();
  public: Boolean get_IsOut();
  public: Boolean get_IsRetval();
  public: Object get_DefaultValue();
  public: Object get_RawDefaultValue();
  public: Boolean get_HasDefaultValue();
  public: IEnumerable<CustomAttributeData> get_CustomAttributes();
  public: Int32 get_MetadataToken();
  protected: void Ctor();
  public: Boolean IsDefined(Type attributeType, Boolean inherit);
  public: IList<CustomAttributeData> GetCustomAttributesData();
  public: Array<Object> GetCustomAttributes(Boolean inherit);
  public: Array<Object> GetCustomAttributes(Type attributeType, Boolean inherit);
  public: Array<Type> GetOptionalCustomModifiers();
  public: Array<Type> GetRequiredCustomModifiers();
  public: Object GetRealObject(StreamingContext context);
  public: String ToString();
  protected: ParameterAttributes AttrsImpl;
  protected: Type ClassImpl;
  protected: Object DefaultValueImpl;
  protected: MemberInfo MemberImpl;
  protected: String NameImpl;
  protected: Int32 PositionImpl;
};
} // namespace ParameterInfoNamespace
using ParameterInfo = ParameterInfoNamespace::ParameterInfo;
} // namespace System::Private::CoreLib::System::Reflection
