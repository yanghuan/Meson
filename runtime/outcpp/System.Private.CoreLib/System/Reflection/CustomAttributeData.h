#pragma once

#include <System.Private.CoreLib/System/Object.h>
#include <System.Private.CoreLib/System/RuntimeType.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARD(Attribute)
FORWARDS(Boolean)
FORWARDS(Int32)
FORWARD(String)
FORWARD(Type)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(IList, T)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System::Runtime::InteropServices {
FORWARD(DllImportAttribute)
FORWARD(FieldOffsetAttribute)
FORWARD(MarshalAsAttribute)
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
namespace System::Private::CoreLib::System::Runtime::CompilerServices {
FORWARD(TypeForwardedToAttribute)
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
namespace System::Private::CoreLib::System::Reflection {
enum class CustomAttributeEncoding : int32_t;
FORWARD(Assembly)
FORWARDS(ConstArray)
FORWARD(ConstructorInfo)
FORWARDS(CustomAttributeCtorParameter)
FORWARDS(CustomAttributeNamedArgument)
FORWARDS(CustomAttributeNamedParameter)
FORWARDS(CustomAttributeRecord)
FORWARDS(CustomAttributeType)
FORWARDS(CustomAttributeTypedArgument)
FORWARD(MemberInfo)
FORWARDS(MetadataToken)
FORWARD(Module)
FORWARD(ParameterInfo)
FORWARD(RuntimeAssembly)
FORWARD(RuntimeConstructorInfo)
FORWARD(RuntimeEventInfo)
FORWARD(RuntimeFieldInfo)
FORWARD(RuntimeMethodInfo)
FORWARD(RuntimeModule)
FORWARD(RuntimeParameterInfo)
FORWARD(RuntimePropertyInfo)
namespace CustomAttributeDataNamespace {
using namespace Collections::Generic;
using namespace Runtime::CompilerServices;
using namespace Runtime::InteropServices;
using Collections::Generic::IList;
CLASS(CustomAttributeData) : public Object::in {
  public: Type get_AttributeType();
  public: ConstructorInfo get_Constructor();
  public: IList<CustomAttributeTypedArgument> get_ConstructorArguments();
  public: IList<CustomAttributeNamedArgument> get_NamedArguments();
  public: static IList<CustomAttributeData> GetCustomAttributes(MemberInfo target);
  public: static IList<CustomAttributeData> GetCustomAttributes(Module target);
  public: static IList<CustomAttributeData> GetCustomAttributes(Assembly target);
  public: static IList<CustomAttributeData> GetCustomAttributes(ParameterInfo target);
  public: static IList<CustomAttributeData> GetCustomAttributesInternal(RuntimeType target);
  public: static IList<CustomAttributeData> GetCustomAttributesInternal(RuntimeFieldInfo target);
  public: static IList<CustomAttributeData> GetCustomAttributesInternal(RuntimeMethodInfo target);
  public: static IList<CustomAttributeData> GetCustomAttributesInternal(RuntimeConstructorInfo target);
  public: static IList<CustomAttributeData> GetCustomAttributesInternal(RuntimeEventInfo target);
  public: static IList<CustomAttributeData> GetCustomAttributesInternal(RuntimePropertyInfo target);
  public: static IList<CustomAttributeData> GetCustomAttributesInternal(RuntimeModule target);
  public: static IList<CustomAttributeData> GetCustomAttributesInternal(RuntimeAssembly target);
  public: static IList<CustomAttributeData> GetCustomAttributesInternal(RuntimeParameterInfo target);
  private: static IList<CustomAttributeData> GetCombinedList(IList<CustomAttributeData> customAttributes, RuntimeType::in::ListBuilder<Attribute>& pseudoAttributes);
  private: static CustomAttributeEncoding TypeToCustomAttributeEncoding(RuntimeType type);
  private: static CustomAttributeType InitCustomAttributeType(RuntimeType parameterType);
  private: static IList<CustomAttributeData> GetCustomAttributes(RuntimeModule module, Int32 tkTarget);
  public: static Array<CustomAttributeRecord> GetCustomAttributeRecords(RuntimeModule module, Int32 targetToken);
  public: static CustomAttributeTypedArgument Filter(IList<CustomAttributeData> attrs, Type caType, Int32 parameter);
  protected: void ctor();
  private: void ctor(RuntimeModule scope, MetadataToken caCtorToken, ConstArray& blob);
  public: void ctor(Attribute attribute);
  private: void Init(DllImportAttribute dllImport);
  private: void Init(FieldOffsetAttribute fieldOffset);
  private: void Init(MarshalAsAttribute marshalAs);
  private: void Init(TypeForwardedToAttribute forwardedTo);
  private: void Init(Object pca);
  public: String ToString();
  public: Int32 GetHashCode();
  public: Boolean Equals(Object obj);
  private: ConstructorInfo m_ctor;
  private: RuntimeModule m_scope;
  private: Array<MemberInfo> m_members;
  private: Array<CustomAttributeCtorParameter> m_ctorParams;
  private: Array<CustomAttributeNamedParameter> m_namedParams;
  private: IList<CustomAttributeTypedArgument> m_typedCtorArgs;
  private: IList<CustomAttributeNamedArgument> m_namedArgs;
};
} // namespace CustomAttributeDataNamespace
using CustomAttributeData = CustomAttributeDataNamespace::CustomAttributeData;
} // namespace System::Private::CoreLib::System::Reflection
