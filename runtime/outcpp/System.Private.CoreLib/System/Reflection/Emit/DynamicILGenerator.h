#pragma once

#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Reflection/Emit/ILGenerator.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
FORWARDS(Byte)
FORWARD(RuntimeType)
FORWARD(String)
FORWARD(Type)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection {
enum class CallingConventions : int32_t;
FORWARD(ConstructorInfo)
FORWARD(FieldInfo)
FORWARD(MethodBase)
FORWARD(MethodInfo)
FORWARD(RuntimeConstructorInfo)
FORWARD(RuntimeFieldInfo)
FORWARD(RuntimeMethodInfo)
FORWARD(RuntimeModule)
} // namespace System::Private::CoreLib::System::Reflection
namespace System::Private::CoreLib::System::Runtime::InteropServices {
enum class CallingConvention : int32_t;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
namespace System::Private::CoreLib::System::Diagnostics::SymbolStore {
FORWARD(ISymbolDocumentWriter)
} // namespace System::Private::CoreLib::System::Diagnostics::SymbolStore
namespace System::Private::CoreLib::System::Reflection::Emit {
FORWARD(DynamicMethod)
FORWARD(DynamicScope)
FORWARD(LocalBuilder)
FORWARDS(OpCode)
FORWARD(SignatureHelper)
namespace DynamicILGeneratorNamespace {
using namespace Diagnostics::SymbolStore;
using namespace Runtime::InteropServices;
CLASS(DynamicILGenerator) : public ILGenerator::in {
  public: void ctor(DynamicMethod method, Array<Byte> methodSignature, Int32 size);
  public: void GetCallableMethod(RuntimeModule module, DynamicMethod dm);
  public: LocalBuilder DeclareLocal(Type localType, Boolean pinned);
  public: void Emit(OpCode opcode, MethodInfo meth);
  public: void Emit(OpCode opcode, ConstructorInfo con);
  public: void Emit(OpCode opcode, Type type);
  public: void Emit(OpCode opcode, FieldInfo field);
  public: void Emit(OpCode opcode, String str);
  public: void EmitCalli(OpCode opcode, CallingConventions callingConvention, Type returnType, Array<Type> parameterTypes, Array<Type> optionalParameterTypes);
  public: void EmitCalli(OpCode opcode, CallingConvention unmanagedCallConv, Type returnType, Array<Type> parameterTypes);
  public: void EmitCall(OpCode opcode, MethodInfo methodInfo, Array<Type> optionalParameterTypes);
  public: void Emit(OpCode opcode, SignatureHelper signature);
  public: void BeginExceptFilterBlock();
  public: void BeginCatchBlock(Type exceptionType);
  public: void UsingNamespace(String ns);
  public: void MarkSequencePoint(ISymbolDocumentWriter document, Int32 startLine, Int32 startColumn, Int32 endLine, Int32 endColumn);
  public: void BeginScope();
  public: void EndScope();
  private: Int32 GetMemberRefToken(MethodBase methodInfo, Array<Type> optionalParameterTypes);
  public: SignatureHelper GetMemberRefSignature(CallingConventions call, Type returnType, Array<Type> parameterTypes, Array<Type> optionalParameterTypes);
  public: void RecordTokenFixup();
  private: Int32 GetTokenFor(RuntimeType rtType);
  private: Int32 GetTokenFor(RuntimeFieldInfo runtimeField);
  private: Int32 GetTokenFor(RuntimeFieldInfo runtimeField, RuntimeType rtType);
  private: Int32 GetTokenFor(RuntimeConstructorInfo rtMeth);
  private: Int32 GetTokenFor(RuntimeConstructorInfo rtMeth, RuntimeType rtType);
  private: Int32 GetTokenFor(RuntimeMethodInfo rtMeth);
  private: Int32 GetTokenFor(RuntimeMethodInfo rtMeth, RuntimeType rtType);
  private: Int32 GetTokenFor(DynamicMethod dm);
  private: Int32 GetTokenForVarArgMethod(RuntimeMethodInfo rtMeth, SignatureHelper sig);
  private: Int32 GetTokenForVarArgMethod(DynamicMethod dm, SignatureHelper sig);
  private: Int32 GetTokenForString(String s);
  private: Int32 GetTokenForSig(Array<Byte> sig);
  public: DynamicScope m_scope;
  private: Int32 m_methodSigToken;
};
} // namespace DynamicILGeneratorNamespace
using DynamicILGenerator = DynamicILGeneratorNamespace::DynamicILGenerator;
} // namespace System::Private::CoreLib::System::Reflection::Emit
