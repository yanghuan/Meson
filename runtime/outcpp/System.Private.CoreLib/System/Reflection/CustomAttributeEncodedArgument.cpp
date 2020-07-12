#include "CustomAttributeEncodedArgument-dep.h"

#include <System.Private.CoreLib/System/Reflection/CustomAttributeEncodedArgument-dep.h>

namespace System::Private::CoreLib::System::Reflection::CustomAttributeEncodedArgumentNamespace {
CustomAttributeType CustomAttributeEncodedArgument::get_CustomAttributeType() {
  return CustomAttributeType();
};

Int64 CustomAttributeEncodedArgument::get_PrimitiveValue() {
  return Int64();
};

Array<CustomAttributeEncodedArgument> CustomAttributeEncodedArgument::get_ArrayValue() {
  return Array<CustomAttributeEncodedArgument>();
};

String CustomAttributeEncodedArgument::get_StringValue() {
  return nullptr;
};

void CustomAttributeEncodedArgument::ParseAttributeArguments(ConstArray attributeBlob, Array<CustomAttributeCtorParameter>& customAttributeCtorParameters, Array<CustomAttributeNamedParameter>& customAttributeNamedParameters, RuntimeModule customAttributeModule) {
};

} // namespace System::Private::CoreLib::System::Reflection::CustomAttributeEncodedArgumentNamespace
