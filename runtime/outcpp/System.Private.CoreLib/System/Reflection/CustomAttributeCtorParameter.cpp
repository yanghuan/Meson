#include "CustomAttributeCtorParameter-dep.h"

namespace System::Private::CoreLib::System::Reflection::CustomAttributeCtorParameterNamespace {
CustomAttributeEncodedArgument CustomAttributeCtorParameter::get_CustomAttributeEncodedArgument() {
  return m_encodedArgument;
}

CustomAttributeCtorParameter::CustomAttributeCtorParameter(CustomAttributeType type) {
  m_type = type;
  m_encodedArgument = rt::default__;
}

} // namespace System::Private::CoreLib::System::Reflection::CustomAttributeCtorParameterNamespace
