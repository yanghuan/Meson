#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/RuntimeType.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
FORWARD(Object)
FORWARD(String)
FORWARD(Type)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(IList, T)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System::Reflection {
enum class BindingFlags;
enum class MemberTypes;
FORWARD(Module)
FORWARD(RuntimeModule)
FORWARD(MemberInfo)
FORWARD(CustomAttributeData)
namespace RuntimeFieldInfoNamespace {
using namespace ::System::Private::CoreLib::System::Collections::Generic;
using ::System::Private::CoreLib::System::Collections::Generic::IList;
CLASS(RuntimeFieldInfo) {
  public: BindingFlags get_BindingFlags();
  private: RuntimeType get_ReflectedTypeInternal();
  public: MemberTypes get_MemberType();
  public: Type get_ReflectedType();
  public: Type get_DeclaringType();
  public: Module get_Module();
  public: Boolean get_IsCollectible();
  public: RuntimeType GetDeclaringTypeInternal();
  public: RuntimeType GetRuntimeType();
  public: RuntimeModule GetRuntimeModule();
  public: Boolean HasSameMetadataDefinitionAs(MemberInfo other);
  public: String ToString();
  public: Array<Object> GetCustomAttributes(Boolean inherit);
  public: Array<Object> GetCustomAttributes(Type attributeType, Boolean inherit);
  public: Boolean IsDefined(Type attributeType, Boolean inherit);
  public: IList<CustomAttributeData> GetCustomAttributesData();
  private: BindingFlags m_bindingFlags;
  protected: RuntimeType::in::RuntimeTypeCache m_reflectedTypeCache;
  protected: RuntimeType m_declaringType;
};
} // namespace RuntimeFieldInfoNamespace
using RuntimeFieldInfo = RuntimeFieldInfoNamespace::RuntimeFieldInfo;
} // namespace System::Private::CoreLib::System::Reflection