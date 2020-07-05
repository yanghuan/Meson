#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Int32.h>
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
enum class EventAttributes;
enum class MemberTypes;
FORWARD(CustomAttributeData)
FORWARD(MemberInfo)
FORWARD(MethodInfo)
FORWARD(Module)
FORWARD(RuntimeMethodInfo)
FORWARD(RuntimeModule)
namespace RuntimeEventInfoNamespace {
using namespace Collections::Generic;
using ::System::Private::CoreLib::System::Collections::Generic::IList;
CLASS(RuntimeEventInfo) {
  public: BindingFlags get_BindingFlags();
  public: MemberTypes get_MemberType();
  public: String get_Name();
  public: Type get_DeclaringType();
  public: Type get_ReflectedType();
  private: RuntimeType get_ReflectedTypeInternal();
  public: Int32 get_MetadataToken();
  public: Module get_Module();
  public: EventAttributes get_Attributes();
  public: Boolean CacheEquals(Object o);
  public: String ToString();
  public: Array<Object> GetCustomAttributes(Boolean inherit);
  public: Array<Object> GetCustomAttributes(Type attributeType, Boolean inherit);
  public: Boolean IsDefined(Type attributeType, Boolean inherit);
  public: IList<CustomAttributeData> GetCustomAttributesData();
  public: Boolean HasSameMetadataDefinitionAs(MemberInfo other);
  public: RuntimeModule GetRuntimeModule();
  public: Array<MethodInfo> GetOtherMethods(Boolean nonPublic);
  public: MethodInfo GetAddMethod(Boolean nonPublic);
  public: MethodInfo GetRemoveMethod(Boolean nonPublic);
  public: MethodInfo GetRaiseMethod(Boolean nonPublic);
  private: Int32 m_token;
  private: EventAttributes m_flags;
  private: String m_name;
  private: void* m_utf8name;
  private: RuntimeType::in::RuntimeTypeCache m_reflectedTypeCache;
  private: RuntimeMethodInfo m_addMethod;
  private: RuntimeMethodInfo m_removeMethod;
  private: RuntimeMethodInfo m_raiseMethod;
  private: Array<MethodInfo> m_otherMethod;
  private: RuntimeType m_declaringType;
  private: BindingFlags m_bindingFlags;
};
} // namespace RuntimeEventInfoNamespace
using RuntimeEventInfo = RuntimeEventInfoNamespace::RuntimeEventInfo;
} // namespace System::Private::CoreLib::System::Reflection
