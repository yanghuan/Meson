#include "VarArgMethod-dep.h"

namespace System::Private::CoreLib::System::Reflection::Emit::VarArgMethodNamespace {
void VarArgMethod___::ctor(DynamicMethod dm, SignatureHelper signature) {
  m_dynamicMethod = dm;
  m_signature = signature;
}

void VarArgMethod___::ctor(RuntimeMethodInfo method, SignatureHelper signature) {
  m_method = method;
  m_signature = signature;
}

} // namespace System::Private::CoreLib::System::Reflection::Emit::VarArgMethodNamespace
