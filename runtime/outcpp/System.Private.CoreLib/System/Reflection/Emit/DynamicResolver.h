#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/RuntimeMethodHandleInternal.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Byte)
FORWARDS(IntPtr)
FORWARD(RuntimeType)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection {
FORWARD(MethodInfo)
} // namespace System::Private::CoreLib::System::Reflection
namespace System::Private::CoreLib::System::Reflection::Emit {
FORWARD(__ExceptionInfo)
FORWARD(DynamicILGenerator)
FORWARD(DynamicILInfo)
FORWARD(DynamicMethod)
FORWARD(DynamicScope)
namespace DynamicResolverNamespace {
CLASS(DynamicResolver) {
  public: enum class SecurityControlFlags {
    Default = 0,
    SkipVisibilityChecks = 1,
    RestrictedSkipVisibilityChecks = 2,
    HasCreationContext = 4,
    CanSkipCSEvaluation = 8,
  };
  private: CLASS(DestroyScout) {
    protected: void Finalize();
    public: void Ctor();
    public: RuntimeMethodHandleInternal m_methodHandle;
  };
  public: void Ctor(DynamicILGenerator ilGenerator);
  public: void Ctor(DynamicILInfo dynamicILInfo);
  protected: void Finalize();
  public: RuntimeType GetJitContext(Int32& securityControlFlags);
  private: static Int32 CalculateNumberOfExceptions(Array<__ExceptionInfo> excp);
  public: Array<Byte> GetCodeInfo(Int32& stackSize, Int32& initLocals, Int32& EHCount);
  public: Array<Byte> GetLocalsSignature();
  public: Array<Byte> GetRawEHInfo();
  public: void GetEHInfo(Int32 excNumber, void* exc);
  public: String GetStringLiteral(Int32 token);
  public: void ResolveToken(Int32 token, IntPtr& typeHandle, IntPtr& methodHandle, IntPtr& fieldHandle);
  public: Array<Byte> ResolveSignature(Int32 token, Int32 fromMethod);
  public: MethodInfo GetDynamicMethod();
  private: Array<__ExceptionInfo> m_exceptions;
  private: Array<Byte> m_exceptionHeader;
  private: DynamicMethod m_method;
  private: Array<Byte> m_code;
  private: Array<Byte> m_localSignature;
  private: Int32 m_stackSize;
  private: DynamicScope m_scope;
};
} // namespace DynamicResolverNamespace
using DynamicResolver = DynamicResolverNamespace::DynamicResolver;
} // namespace System::Private::CoreLib::System::Reflection::Emit
