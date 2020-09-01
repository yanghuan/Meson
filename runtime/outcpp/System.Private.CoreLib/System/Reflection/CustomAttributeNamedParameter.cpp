#include "CustomAttributeNamedParameter-dep.h"

#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>

namespace System::Private::CoreLib::System::Reflection::CustomAttributeNamedParameterNamespace {
CustomAttributeEncodedArgument CustomAttributeNamedParameter::get_EncodedArgument() {
  return m_encodedArgument;
}

CustomAttributeNamedParameter::CustomAttributeNamedParameter(String argumentName, CustomAttributeEncoding fieldOrProperty, CustomAttributeType type) {
  if (argumentName == nullptr) {
    rt::throw_exception<ArgumentNullException>("argumentName");
  }
  m_argumentName = argumentName;
  m_fieldOrProperty = fieldOrProperty;
  m_padding = fieldOrProperty;
  m_type = type;
  m_encodedArgument = rt::default__;
}

} // namespace System::Private::CoreLib::System::Reflection::CustomAttributeNamedParameterNamespace
