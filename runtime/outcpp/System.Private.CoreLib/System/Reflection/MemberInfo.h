#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
FORWARDS(Int32)
FORWARD(String)
FORWARD(Type)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(IEnumerable, T)
FORWARD(IList, T)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System::Reflection {
enum class MemberTypes : int32_t;
FORWARD(CustomAttributeData)
FORWARD(ICustomAttributeProvider)
FORWARD(Module)
namespace MemberInfoNamespace {
using namespace System::Collections::Generic;
CLASS(MemberInfo) : public Object::in {
  public: using interface = rt::TypeList<ICustomAttributeProvider>;
  public: MemberTypes get_MemberType();
  public: String get_Name();
  public: Type get_DeclaringType();
  public: Type get_ReflectedType();
  public: Module get_Module();
  public: IEnumerable<CustomAttributeData> get_CustomAttributes();
  public: Boolean get_IsCollectible();
  public: Int32 get_MetadataToken();
  public: Boolean CacheEquals(Object o);
  public: template <class TOther>
  Boolean HasSameMetadataDefinitionAsCore(MemberInfo other);
  protected: void ctor();
  public: Boolean HasSameMetadataDefinitionAs(MemberInfo other);
  public: Boolean IsDefined(Type attributeType, Boolean inherit);
  public: Array<Object> GetCustomAttributes(Boolean inherit);
  public: Array<Object> GetCustomAttributes(Type attributeType, Boolean inherit);
  public: IList<CustomAttributeData> GetCustomAttributesData();
  public: Boolean Equals(Object obj);
  public: Int32 GetHashCode();
  public: static Boolean op_Equality(MemberInfo left, MemberInfo right);
  public: static Boolean op_Inequality(MemberInfo left, MemberInfo right);
};
} // namespace MemberInfoNamespace
using MemberInfo = MemberInfoNamespace::MemberInfo;
} // namespace System::Private::CoreLib::System::Reflection
