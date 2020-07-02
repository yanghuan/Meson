#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/RuntimeType.h>

namespace System::Private::CoreLib::System {
FORWARD(Type)
FORWARD(Attribute)
FORWARDS(Int32)
FORWARD_(Array, T1, T2)
FORWARD(Object)
FORWARD(String)
FORWARDS(Boolean)
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
FORWARD(ConstructorInfo)
FORWARDS(CustomAttributeTypedArgument)
FORWARDS(CustomAttributeNamedArgument)
FORWARD(MemberInfo)
FORWARD(Module)
FORWARD(Assembly)
FORWARD(ParameterInfo)
FORWARD(RuntimeFieldInfo)
FORWARD(RuntimeMethodInfo)
FORWARD(RuntimeConstructorInfo)
FORWARD(RuntimeEventInfo)
FORWARD(RuntimePropertyInfo)
FORWARD(RuntimeModule)
FORWARD(RuntimeAssembly)
FORWARD(RuntimeParameterInfo)
enum class CustomAttributeEncoding;
FORWARDS(CustomAttributeType)
FORWARDS(CustomAttributeRecord)
FORWARDS(CustomAttributeCtorParameter)
FORWARDS(CustomAttributeNamedParameter)
namespace CustomAttributeDataNamespace {
using namespace ::System::Private::CoreLib::System::Collections::Generic;
using namespace ::System::Private::CoreLib::System::Runtime::CompilerServices;
using namespace ::System::Private::CoreLib::System::Runtime::InteropServices;
using System::Collections::Generic::IList;
CLASS(CustomAttributeData) {
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
