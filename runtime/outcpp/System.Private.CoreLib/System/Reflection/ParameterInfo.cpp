#include "ParameterInfo-dep.h"

#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/NotImplemented-dep.h>
#include <System.Private.CoreLib/System/Reflection/MemberTypes.h>
#include <System.Private.CoreLib/System/Reflection/MethodBase-dep.h>
#include <System.Private.CoreLib/System/Reflection/MethodInfo-dep.h>
#include <System.Private.CoreLib/System/Reflection/ParameterInfo-dep.h>
#include <System.Private.CoreLib/System/Reflection/PropertyInfo-dep.h>
#include <System.Private.CoreLib/System/Runtime/Serialization/SerializationException-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>

namespace System::Private::CoreLib::System::Reflection::ParameterInfoNamespace {
using namespace System::Runtime::Serialization;

ParameterAttributes ParameterInfo___::get_Attributes() {
  return AttrsImpl;
}

MemberInfo ParameterInfo___::get_Member() {
  return MemberImpl;
}

String ParameterInfo___::get_Name() {
  return NameImpl;
}

Type ParameterInfo___::get_ParameterType() {
  return ClassImpl;
}

Int32 ParameterInfo___::get_Position() {
  return PositionImpl;
}

Boolean ParameterInfo___::get_IsIn() {
}

Boolean ParameterInfo___::get_IsLcid() {
}

Boolean ParameterInfo___::get_IsOptional() {
}

Boolean ParameterInfo___::get_IsOut() {
}

Boolean ParameterInfo___::get_IsRetval() {
}

Object ParameterInfo___::get_DefaultValue() {
  rt::throw_exception(NotImplemented::get_ByDesign());
}

Object ParameterInfo___::get_RawDefaultValue() {
  rt::throw_exception(NotImplemented::get_ByDesign());
}

Boolean ParameterInfo___::get_HasDefaultValue() {
  rt::throw_exception(NotImplemented::get_ByDesign());
}

IEnumerable<CustomAttributeData> ParameterInfo___::get_CustomAttributes() {
  return GetCustomAttributesData();
}

Int32 ParameterInfo___::get_MetadataToken() {
  return 134217728;
}

void ParameterInfo___::ctor() {
}

Boolean ParameterInfo___::IsDefined(Type attributeType, Boolean inherit) {
  if (attributeType == nullptr) {
    rt::throw_exception<ArgumentNullException>("attributeType");
  }
  return false;
}

IList<CustomAttributeData> ParameterInfo___::GetCustomAttributesData() {
  rt::throw_exception(NotImplemented::get_ByDesign());
}

Array<Object> ParameterInfo___::GetCustomAttributes(Boolean inherit) {
  return Array<>::in::Empty<Object>();
}

Array<Object> ParameterInfo___::GetCustomAttributes(Type attributeType, Boolean inherit) {
  if (attributeType == nullptr) {
    rt::throw_exception<ArgumentNullException>("attributeType");
  }
  return Array<>::in::Empty<Object>();
}

Array<Type> ParameterInfo___::GetOptionalCustomModifiers() {
  return Array<>::in::Empty<Type>();
}

Array<Type> ParameterInfo___::GetRequiredCustomModifiers() {
  return Array<>::in::Empty<Type>();
}

Object ParameterInfo___::GetRealObject(StreamingContext context) {
  if (MemberImpl == nullptr) {
    rt::throw_exception<SerializationException>(SR::get_Serialization_InsufficientState());
  }
  switch (MemberImpl->get_MemberType()) {
    case MemberTypes::Constructor:
    case MemberTypes::Method:
      {
        if (PositionImpl == -1) {
          if (MemberImpl->get_MemberType() == MemberTypes::Method) {
            return ((MethodInfo)MemberImpl)->get_ReturnParameter();
          }
          rt::throw_exception<SerializationException>(SR::get_Serialization_BadParameterInfo());
        }
        Array<ParameterInfo> indexParameters = ((MethodBase)MemberImpl)->GetParametersNoCopy();
        if (indexParameters != nullptr && PositionImpl < indexParameters->get_Length()) {
          return indexParameters[PositionImpl];
        }
        rt::throw_exception<SerializationException>(SR::get_Serialization_BadParameterInfo());
      }case MemberTypes::Property:
      {
        Array<ParameterInfo> indexParameters = ((PropertyInfo)MemberImpl)->GetIndexParameters();
        if (indexParameters != nullptr && PositionImpl > -1 && PositionImpl < indexParameters->get_Length()) {
          return indexParameters[PositionImpl];
        }
        rt::throw_exception<SerializationException>(SR::get_Serialization_BadParameterInfo());
      }default:
      rt::throw_exception<SerializationException>(SR::get_Serialization_NoParameterInfo());
  }
}

String ParameterInfo___::ToString() {
  return get_ParameterType()->FormatTypeName() + " " + get_Name();
}

} // namespace System::Private::CoreLib::System::Reflection::ParameterInfoNamespace
