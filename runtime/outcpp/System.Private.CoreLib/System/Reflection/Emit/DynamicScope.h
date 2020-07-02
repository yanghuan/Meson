#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Int32)
FORWARD(Object)
FORWARD(String)
FORWARD_(Array, T1, T2)
FORWARDS(Byte)
FORWARDS(RuntimeMethodHandle)
FORWARDS(RuntimeTypeHandle)
FORWARDS(RuntimeFieldHandle)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(List, T)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System::Reflection::Emit {
FORWARD(VarArgMethod)
FORWARD(DynamicMethod)
namespace DynamicScopeNamespace {
using namespace ::System::Private::CoreLib::System::Collections::Generic;
CLASS(DynamicScope) {
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
  public: List<Object> m_tokens;
};
} // namespace DynamicScopeNamespace
using DynamicScope = DynamicScopeNamespace::DynamicScope;
} // namespace System::Private::CoreLib::System::Reflection::Emit
