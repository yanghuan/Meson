#include "CustomAttributeEncodedArgument-dep.h"

#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/Reflection/CustomAttributeEncodedArgument-dep.h>

namespace System::Private::CoreLib::System::Reflection::CustomAttributeEncodedArgumentNamespace {
CustomAttributeType CustomAttributeEncodedArgument::get_CustomAttributeType() {
  return m_type;
}

Int64 CustomAttributeEncodedArgument::get_PrimitiveValue() {
  return m_primitiveValue;
}

Array<CustomAttributeEncodedArgument> CustomAttributeEncodedArgument::get_ArrayValue() {
  return m_arrayValue;
}

String CustomAttributeEncodedArgument::get_StringValue() {
  return m_stringValue;
}

void CustomAttributeEncodedArgument::ParseAttributeArguments(ConstArray attributeBlob, Array<CustomAttributeCtorParameter>& customAttributeCtorParameters, Array<CustomAttributeNamedParameter>& customAttributeNamedParameters, RuntimeModule customAttributeModule) {
  if (customAttributeModule == nullptr) {
    rt::throw_exception<ArgumentNullException>("customAttributeModule");
  }
  if (customAttributeCtorParameters->get_Length() != 0 || customAttributeNamedParameters->get_Length() != 0) {
    ParseAttributeArguments(attributeBlob.get_Signature(), attributeBlob.get_Length(), customAttributeCtorParameters, customAttributeNamedParameters, (RuntimeAssembly)customAttributeModule->get_Assembly());
  }
}

} // namespace System::Private::CoreLib::System::Reflection::CustomAttributeEncodedArgumentNamespace
