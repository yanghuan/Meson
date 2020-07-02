#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Reflection {
FORWARD(RuntimeMethodInfo)
} // namespace System::Private::CoreLib::System::Reflection
namespace System::Private::CoreLib::System::Reflection::Emit {
FORWARD(DynamicMethod)
FORWARD(SignatureHelper)
namespace VarArgMethodNamespace {
CLASS(VarArgMethod) {
  public: RuntimeMethodInfo m_method;
  public: DynamicMethod m_dynamicMethod;
  public: SignatureHelper m_signature;
};
} // namespace VarArgMethodNamespace
using VarArgMethod = VarArgMethodNamespace::VarArgMethod;
} // namespace System::Private::CoreLib::System::Reflection::Emit
