#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Int32.h>

namespace System::Private::CoreLib::System::Reflection {
FORWARD(MethodInfo)
} // namespace System::Private::CoreLib::System::Reflection
namespace System::Private::CoreLib::System {
FORWARD(RuntimeType)
FORWARD_(Array, T1, T2)
FORWARDS(Byte)
FORWARD(String)
FORWARDS(IntPtr)
namespace ResolverNamespace {
using namespace ::System::Private::CoreLib::System::Reflection;
CLASS(Resolver) {
  public: struct CORINFO_EH_CLAUSE {
    public: Int32 Flags;
    public: Int32 TryOffset;
    public: Int32 TryLength;
    public: Int32 HandlerOffset;
    public: Int32 HandlerLength;
    public: Int32 ClassTokenOrFilterOffset;
  };
  public: RuntimeType GetJitContext(Int32& securityControlFlags);
  public: Array<Byte> GetCodeInfo(Int32& stackSize, Int32& initLocals, Int32& EHCount);
  public: Array<Byte> GetLocalsSignature();
  public: void GetEHInfo(Int32 EHNumber, void* exception);
  public: Array<Byte> GetRawEHInfo();
  public: String GetStringLiteral(Int32 token);
  public: void ResolveToken(Int32 token, IntPtr& typeHandle, IntPtr& methodHandle, IntPtr& fieldHandle);
  public: Array<Byte> ResolveSignature(Int32 token, Int32 fromMethod);
  public: MethodInfo GetDynamicMethod();
};
} // namespace ResolverNamespace
using Resolver = ResolverNamespace::Resolver;
} // namespace System::Private::CoreLib::System