#pragma once

#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Byte)
FORWARDS(RuntimeFieldHandle)
FORWARDS(RuntimeMethodHandle)
FORWARDS(RuntimeTypeHandle)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection {
FORWARD(RuntimeModule)
} // namespace System::Private::CoreLib::System::Reflection
namespace System::Private::CoreLib::System::Reflection::Emit {
FORWARD(DynamicMethod)
FORWARD(DynamicScope)
namespace DynamicILInfoNamespace {
CLASS(DynamicILInfo) : public object {
  public: Array<Byte> get_LocalSignature();
  public: Array<Byte> get_Exceptions();
  public: Array<Byte> get_Code();
  public: Int32 get_MaxStackSize();
  public: DynamicMethod get_DynamicMethod();
  public: DynamicScope get_DynamicScope();
  public: void ctor(DynamicMethod method, Array<Byte> methodSignature);
  public: void GetCallableMethod(RuntimeModule module, DynamicMethod dm);
  public: void SetCode(Array<Byte> code, Int32 maxStackSize);
  public: void SetCode(Byte* code, Int32 codeSize, Int32 maxStackSize);
  public: void SetExceptions(Array<Byte> exceptions);
  public: void SetExceptions(Byte* exceptions, Int32 exceptionsSize);
  public: void SetLocalSignature(Array<Byte> localSignature);
  public: void SetLocalSignature(Byte* localSignature, Int32 signatureSize);
  public: Int32 GetTokenFor(RuntimeMethodHandle method);
  public: Int32 GetTokenFor(DynamicMethod method);
  public: Int32 GetTokenFor(RuntimeMethodHandle method, RuntimeTypeHandle contextType);
  public: Int32 GetTokenFor(RuntimeFieldHandle field);
  public: Int32 GetTokenFor(RuntimeFieldHandle field, RuntimeTypeHandle contextType);
  public: Int32 GetTokenFor(RuntimeTypeHandle type);
  public: Int32 GetTokenFor(String literal);
  public: Int32 GetTokenFor(Array<Byte> signature);
  private: DynamicMethod m_method;
  private: DynamicScope m_scope;
  private: Array<Byte> m_exceptions;
  private: Array<Byte> m_code;
  private: Array<Byte> m_localSignature;
  private: Int32 m_maxStackSize;
  private: Int32 m_methodSignature;
};
} // namespace DynamicILInfoNamespace
using DynamicILInfo = DynamicILInfoNamespace::DynamicILInfo;
} // namespace System::Private::CoreLib::System::Reflection::Emit
