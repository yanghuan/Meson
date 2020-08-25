#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Byte)
FORWARDS(Int32)
FORWARDS(RuntimeFieldHandle)
FORWARDS(RuntimeMethodHandle)
FORWARDS(RuntimeTypeHandle)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(List, T)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System::Reflection::Emit {
FORWARD(DynamicMethod)
FORWARD(VarArgMethod)
namespace DynamicScopeNamespace {
using namespace System::Collections::Generic;
CLASS(DynamicScope) : public object {
  public: Object get_Item(Int32 token);
  public: Int32 GetTokenFor(VarArgMethod varArgMethod);
  public: String GetString(Int32 token);
  public: Array<Byte> ResolveSignature(Int32 token, Int32 fromMethod);
  public: Int32 GetTokenFor(RuntimeMethodHandle method);
  public: Int32 GetTokenFor(RuntimeMethodHandle method, RuntimeTypeHandle typeContext);
  public: Int32 GetTokenFor(DynamicMethod method);
  public: Int32 GetTokenFor(RuntimeFieldHandle field);
  public: Int32 GetTokenFor(RuntimeFieldHandle field, RuntimeTypeHandle typeContext);
  public: Int32 GetTokenFor(RuntimeTypeHandle type);
  public: Int32 GetTokenFor(String literal);
  public: Int32 GetTokenFor(Array<Byte> signature);
  public: void ctor();
  public: List<Object> m_tokens;
};
} // namespace DynamicScopeNamespace
using DynamicScope = DynamicScopeNamespace::DynamicScope;
} // namespace System::Private::CoreLib::System::Reflection::Emit
