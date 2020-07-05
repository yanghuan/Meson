#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/RuntimeMethodHandleInternal.h>

namespace System::Private::CoreLib::System::Reflection {
enum class CallingConventions;
} // namespace System::Private::CoreLib::System::Reflection
namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
FORWARD(IRuntimeMethodInfo)
FORWARD(Object)
FORWARDS(RuntimeFieldHandleInternal)
FORWARD(RuntimeType)
FORWARD(Type)
namespace SignatureNamespace {
using namespace Reflection;
CLASS(Signature) {
  public: CallingConventions get_CallingConvention();
  public: Array<RuntimeType> get_Arguments();
  public: RuntimeType get_ReturnType();
  public: RuntimeType get_FieldType();
  private: void GetSignature(void* pCorSig, Int32 cCorSig, RuntimeFieldHandleInternal fieldHandle, IRuntimeMethodInfo methodHandle, RuntimeType declaringType);
  public: static Boolean CompareSig(Signature sig1, Signature sig2);
  public: Array<Type> GetCustomModifiers(Int32 position, Boolean required);
  public: Array<RuntimeType> m_arguments;
  public: RuntimeType m_declaringType;
  public: RuntimeType m_returnTypeORfieldType;
  public: Object m_keepalive;
  public: void* m_sig;
  public: Int32 m_managedCallingConventionAndArgIteratorFlags;
  public: Int32 m_nSizeOfArgStack;
  public: Int32 m_csig;
  public: RuntimeMethodHandleInternal m_pMethod;
};
} // namespace SignatureNamespace
using Signature = SignatureNamespace::Signature;
} // namespace System::Private::CoreLib::System
