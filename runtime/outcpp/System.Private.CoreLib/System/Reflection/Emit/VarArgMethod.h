#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Reflection {
FORWARD(RuntimeMethodInfo)
} // namespace System::Private::CoreLib::System::Reflection
namespace System::Private::CoreLib::System::Reflection::Emit {
FORWARD(DynamicMethod)
FORWARD(SignatureHelper)
namespace VarArgMethodNamespace {
CLASS(VarArgMethod) : public object {
  public: void ctor(DynamicMethod dm, SignatureHelper signature);
  public: void ctor(RuntimeMethodInfo method, SignatureHelper signature);
  public: RuntimeMethodInfo m_method;
  public: DynamicMethod m_dynamicMethod;
  public: SignatureHelper m_signature;
};
} // namespace VarArgMethodNamespace
using VarArgMethod = VarArgMethodNamespace::VarArgMethod;
} // namespace System::Private::CoreLib::System::Reflection::Emit
