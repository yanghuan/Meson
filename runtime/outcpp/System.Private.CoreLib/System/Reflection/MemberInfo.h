#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
FORWARDS(Int32)
FORWARD(Object)
FORWARD(String)
FORWARD(Type)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(IEnumerable, T)
FORWARD(IList, T)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System::Reflection {
enum class MemberTypes;
FORWARD(CustomAttributeData)
FORWARD(Module)
namespace MemberInfoNamespace {
using namespace Collections::Generic;
using Collections::Generic::IList;
CLASS(MemberInfo) {
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
  protected: void Ctor();
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
