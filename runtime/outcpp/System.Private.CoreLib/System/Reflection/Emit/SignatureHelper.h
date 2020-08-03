#pragma once

#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Reflection {
enum class CallingConventions;
enum class CorElementType : uint8_t;
enum class MdSigCallingConvention : uint8_t;
FORWARD(Module)
} // namespace System::Private::CoreLib::System::Reflection
namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Byte)
FORWARD(String)
FORWARD(Type)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices {
enum class CallingConvention;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
namespace System::Private::CoreLib::System::Reflection::Emit {
FORWARD(ModuleBuilder)
FORWARDS(TypeToken)
namespace SignatureHelperNamespace {
using namespace Runtime::InteropServices;
CLASS(SignatureHelper) : public Object::in {
  public: Int32 get_ArgumentCount();
  public: static SignatureHelper GetMethodSigHelper(Module mod, Type returnType, Array<Type> parameterTypes);
  public: static SignatureHelper GetMethodSigHelper(Module mod, CallingConventions callingConvention, Type returnType, Int32 cGenericParam);
  public: static SignatureHelper GetMethodSigHelper(Module mod, CallingConventions callingConvention, Type returnType);
  public: static SignatureHelper GetMethodSpecSigHelper(Module scope, Array<Type> inst);
  public: static SignatureHelper GetMethodSigHelper(Module scope, CallingConventions callingConvention, Type returnType, Array<Type> requiredReturnTypeCustomModifiers, Array<Type> optionalReturnTypeCustomModifiers, Array<Type> parameterTypes, Array<Array<Type>> requiredParameterTypeCustomModifiers, Array<Array<Type>> optionalParameterTypeCustomModifiers);
  public: static SignatureHelper GetMethodSigHelper(Module scope, CallingConventions callingConvention, Int32 cGenericParam, Type returnType, Array<Type> requiredReturnTypeCustomModifiers, Array<Type> optionalReturnTypeCustomModifiers, Array<Type> parameterTypes, Array<Array<Type>> requiredParameterTypeCustomModifiers, Array<Array<Type>> optionalParameterTypeCustomModifiers);
  public: static SignatureHelper GetMethodSigHelper(Module mod, CallingConvention unmanagedCallConv, Type returnType);
  public: static SignatureHelper GetLocalVarSigHelper();
  public: static SignatureHelper GetMethodSigHelper(CallingConventions callingConvention, Type returnType);
  public: static SignatureHelper GetMethodSigHelper(CallingConvention unmanagedCallingConvention, Type returnType);
  public: static SignatureHelper GetLocalVarSigHelper(Module mod);
  public: static SignatureHelper GetFieldSigHelper(Module mod);
  public: static SignatureHelper GetPropertySigHelper(Module mod, Type returnType, Array<Type> parameterTypes);
  public: static SignatureHelper GetPropertySigHelper(Module mod, Type returnType, Array<Type> requiredReturnTypeCustomModifiers, Array<Type> optionalReturnTypeCustomModifiers, Array<Type> parameterTypes, Array<Array<Type>> requiredParameterTypeCustomModifiers, Array<Array<Type>> optionalParameterTypeCustomModifiers);
  public: static SignatureHelper GetPropertySigHelper(Module mod, CallingConventions callingConvention, Type returnType, Array<Type> requiredReturnTypeCustomModifiers, Array<Type> optionalReturnTypeCustomModifiers, Array<Type> parameterTypes, Array<Array<Type>> requiredParameterTypeCustomModifiers, Array<Array<Type>> optionalParameterTypeCustomModifiers);
  public: static SignatureHelper GetTypeSigToken(Module module, Type type);
  private: void Ctor(Module mod, MdSigCallingConvention callingConvention);
  private: void Ctor(Module mod, MdSigCallingConvention callingConvention, Int32 cGenericParameters, Type returnType, Array<Type> requiredCustomModifiers, Array<Type> optionalCustomModifiers);
  private: void Ctor(Module mod, MdSigCallingConvention callingConvention, Type returnType, Array<Type> requiredCustomModifiers, Array<Type> optionalCustomModifiers);
  private: void Ctor(Module mod, Type type);
  private: void Init(Module mod);
  private: void Init(Module mod, MdSigCallingConvention callingConvention);
  private: void Init(Module mod, MdSigCallingConvention callingConvention, Int32 cGenericParam);
  private: void AddOneArgTypeHelper(Type argument, Boolean pinned);
  private: void AddOneArgTypeHelper(Type clsArgument, Array<Type> requiredCustomModifiers, Array<Type> optionalCustomModifiers);
  private: void AddOneArgTypeHelper(Type clsArgument);
  private: void AddOneArgTypeHelperWorker(Type clsArgument, Boolean lastWasGenericInst);
  private: void AddData(Int32 data);
  private: void AddElementType(CorElementType cvt);
  private: void AddToken(Int32 token);
  private: void InternalAddTypeToken(TypeToken clsToken, CorElementType CorType);
  private: void InternalAddRuntimeType(Type type);
  private: static Array<Byte> ExpandArray(Array<Byte> inArray);
  private: static Array<Byte> ExpandArray(Array<Byte> inArray, Int32 requiredLength);
  private: void IncrementArgCounts();
  private: void SetNumberOfSignatureElements(Boolean forceCopy);
  public: static Boolean IsSimpleType(CorElementType type);
  public: Array<Byte> InternalGetSignature(Int32& length);
  public: Array<Byte> InternalGetSignatureArray();
  public: void AddArgument(Type clsArgument);
  public: void AddArgument(Type argument, Boolean pinned);
  public: void AddArguments(Array<Type> arguments, Array<Array<Type>> requiredCustomModifiers, Array<Array<Type>> optionalCustomModifiers);
  public: void AddArgument(Type argument, Array<Type> requiredCustomModifiers, Array<Type> optionalCustomModifiers);
  public: void AddSentinel();
  public: Boolean Equals(Object obj);
  public: Int32 GetHashCode();
  public: Array<Byte> GetSignature();
  public: Array<Byte> GetSignature(Boolean appendEndOfSig);
  public: String ToString();
  private: Array<Byte> m_signature;
  private: Int32 m_currSig;
  private: Int32 m_sizeLoc;
  private: ModuleBuilder m_module;
  private: Boolean m_sigDone;
  private: Int32 m_argCount;
};
} // namespace SignatureHelperNamespace
using SignatureHelper = SignatureHelperNamespace::SignatureHelper;
} // namespace System::Private::CoreLib::System::Reflection::Emit
