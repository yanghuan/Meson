#pragma once

#include <System.Private.CoreLib/System/Reflection/FieldInfo.h>
#include <System.Private.CoreLib/System/RuntimeType.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array)
FORWARDS(Boolean)
FORWARD(Object)
FORWARD(String)
FORWARD(Type)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(IList, T)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System::Reflection {
enum class BindingFlags : int32_t;
enum class MemberTypes : int32_t;
FORWARD(CustomAttributeData)
FORWARD(MemberInfo)
FORWARD(Module)
FORWARD(RuntimeModule)
namespace RuntimeFieldInfoNamespace {
using namespace System::Collections::Generic;
CLASS(RuntimeFieldInfo) : public FieldInfo::in {
  public: BindingFlags get_BindingFlags();
  private: RuntimeType get_ReflectedTypeInternal();
  public: MemberTypes get_MemberType();
  public: Type get_ReflectedType();
  public: Type get_DeclaringType();
  public: Module get_Module();
  public: Boolean get_IsCollectible();
  public: void ctor(RuntimeType::in::RuntimeTypeCache reflectedTypeCache, RuntimeType declaringType, BindingFlags bindingFlags);
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
