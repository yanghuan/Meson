#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Int32.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
FORWARDS(Byte)
FORWARDS(Double)
FORWARDS(Int16)
FORWARDS(Int64)
FORWARDS(SByte)
FORWARDS(Single)
FORWARD(String)
FORWARD(Type)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection {
enum class CallingConventions;
FORWARD(ConstructorInfo)
FORWARD(FieldInfo)
FORWARD(MethodBase)
FORWARD(MethodInfo)
} // namespace System::Private::CoreLib::System::Reflection
namespace System::Private::CoreLib::System::Runtime::InteropServices {
enum class CallingConvention;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
namespace System::Private::CoreLib::System::Diagnostics::SymbolStore {
FORWARD(ISymbolDocumentWriter)
} // namespace System::Private::CoreLib::System::Diagnostics::SymbolStore
namespace System::Private::CoreLib::System::Reflection::Emit {
FORWARD(__ExceptionInfo)
FORWARDS(__FixupData)
FORWARDS(Label)
FORWARD(LineNumberInfo)
FORWARD(LocalBuilder)
FORWARDS(OpCode)
FORWARD(ScopeTree)
FORWARD(SignatureHelper)
namespace ILGeneratorNamespace {
using namespace Diagnostics::SymbolStore;
using namespace Runtime::InteropServices;
CLASS(ILGenerator) {
  public: Int32 get_CurrExcStackCount();
  public: Array<__ExceptionInfo> get_CurrExcStack();
  public: Int32 get_ILOffset();
  public: void Ctor(MethodInfo methodBuilder);
  public: void Ctor(MethodInfo methodBuilder, Int32 size);
  public: void RecordTokenFixup();
  public: void InternalEmit(OpCode opcode);
  public: void UpdateStackSize(OpCode opcode, Int32 stackchange);
  private: Int32 GetMethodToken(MethodBase method, Array<Type> optionalParameterTypes, Boolean useMethodDef);
  public: SignatureHelper GetMemberRefSignature(CallingConventions call, Type returnType, Array<Type> parameterTypes, Array<Type> optionalParameterTypes);
  private: SignatureHelper GetMemberRefSignature(CallingConventions call, Type returnType, Array<Type> parameterTypes, Array<Type> optionalParameterTypes, Int32 cGenericParameters);
  public: Array<Byte> BakeByteArray();
  public: Array<__ExceptionInfo> GetExceptions();
  public: void EnsureCapacity(Int32 size);
  private: void IncreaseCapacity(Int32 size);
  public: void PutInteger4(Int32 value);
  private: Int32 GetLabelPos(Label lbl);
  private: void AddFixup(Label lbl, Int32 pos, Int32 instSize);
  public: Int32 GetMaxStackSize();
  private: static void SortExceptions(Array<__ExceptionInfo> exceptions);
  public: Array<Int32> GetTokenFixups();
  public: void Emit(OpCode opcode);
  public: void Emit(OpCode opcode, Byte arg);
  public: void Emit(OpCode opcode, SByte arg);
  public: void Emit(OpCode opcode, Int16 arg);
  public: void Emit(OpCode opcode, Int32 arg);
  public: void Emit(OpCode opcode, MethodInfo meth);
  public: void EmitCalli(OpCode opcode, CallingConventions callingConvention, Type returnType, Array<Type> parameterTypes, Array<Type> optionalParameterTypes);
  public: void EmitCalli(OpCode opcode, CallingConvention unmanagedCallConv, Type returnType, Array<Type> parameterTypes);
  public: void EmitCall(OpCode opcode, MethodInfo methodInfo, Array<Type> optionalParameterTypes);
  public: void Emit(OpCode opcode, SignatureHelper signature);
  public: void Emit(OpCode opcode, ConstructorInfo con);
  public: void Emit(OpCode opcode, Type cls);
  public: void Emit(OpCode opcode, Int64 arg);
  public: void Emit(OpCode opcode, Single arg);
  public: void Emit(OpCode opcode, Double arg);
  public: void Emit(OpCode opcode, Label label);
  public: void Emit(OpCode opcode, Array<Label> labels);
  public: void Emit(OpCode opcode, FieldInfo field);
  public: void Emit(OpCode opcode, String str);
  public: void Emit(OpCode opcode, LocalBuilder local);
  public: Label BeginExceptionBlock();
  public: void EndExceptionBlock();
  public: void BeginExceptFilterBlock();
  public: void BeginCatchBlock(Type exceptionType);
  public: void BeginFaultBlock();
  public: void BeginFinallyBlock();
  public: Label DefineLabel();
  public: void MarkLabel(Label loc);
  public: void ThrowException(Type excType);
  private: static Type GetConsoleType();
  public: void EmitWriteLine(String value);
  public: void EmitWriteLine(LocalBuilder localBuilder);
  public: void EmitWriteLine(FieldInfo fld);
  public: LocalBuilder DeclareLocal(Type localType);
  public: LocalBuilder DeclareLocal(Type localType, Boolean pinned);
  public: void UsingNamespace(String usingNamespace);
  public: void MarkSequencePoint(ISymbolDocumentWriter document, Int32 startLine, Int32 startColumn, Int32 endLine, Int32 endColumn);
  public: void BeginScope();
  public: void EndScope();
  private: Int32 m_length;
  private: Array<Byte> m_ILStream;
  private: Array<Int32> m_labelList;
  private: Int32 m_labelCount;
  private: Array<__FixupData> m_fixupData;
  private: Int32 m_fixupCount;
  private: Array<Int32> m_RelocFixupList;
  private: Int32 m_RelocFixupCount;
  private: Int32 m_exceptionCount;
  private: Int32 m_currExcStackCount;
  private: Array<__ExceptionInfo> m_exceptions;
  private: Array<__ExceptionInfo> m_currExcStack;
  public: ScopeTree m_ScopeTree;
  public: LineNumberInfo m_LineNumberInfo;
  public: MethodInfo m_methodBuilder;
  public: Int32 m_localCount;
  public: SignatureHelper m_localSignature;
  private: Int32 m_maxStackSize;
  private: Int32 m_maxMidStack;
  private: Int32 m_maxMidStackCur;
};
} // namespace ILGeneratorNamespace
using ILGenerator = ILGeneratorNamespace::ILGenerator;
} // namespace System::Private::CoreLib::System::Reflection::Emit
