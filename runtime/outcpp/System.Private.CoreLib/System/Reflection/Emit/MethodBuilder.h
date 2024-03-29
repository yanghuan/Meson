#pragma once

#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/Reflection/Emit/MethodToken.h>
#include <System.Private.CoreLib/System/Reflection/MethodInfo.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array)
FORWARDS(Byte)
FORWARDS(Int32)
FORWARD(Object)
FORWARDS(RuntimeMethodHandle)
FORWARD(String)
FORWARD(Type)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection {
enum class BindingFlags : int32_t;
enum class CallingConventions : int32_t;
enum class MethodAttributes : int32_t;
enum class MethodImplAttributes : int32_t;
enum class ParameterAttributes : int32_t;
FORWARD(Binder)
FORWARD(ConstructorInfo)
FORWARD(ICustomAttributeProvider)
FORWARD(MethodBase)
FORWARD(Module)
FORWARD(ParameterInfo)
} // namespace System::Private::CoreLib::System::Reflection
namespace System::Private::CoreLib::System::Globalization {
FORWARD(CultureInfo)
} // namespace System::Private::CoreLib::System::Globalization
namespace System::Private::CoreLib::System::Reflection::Emit {
FORWARD(__ExceptionInfo)
FORWARD(CustomAttributeBuilder)
FORWARDS(ExceptionHandler)
FORWARD(GenericTypeParameterBuilder)
FORWARD(ILGenerator)
FORWARD(LocalSymInfo)
FORWARD(ModuleBuilder)
FORWARD(ParameterBuilder)
FORWARD(SignatureHelper)
FORWARD(TypeBuilder)
namespace MethodBuilderNamespace {
using namespace System::Globalization;
CLASS(MethodBuilder) : public MethodInfo::in {
  public: Int32 get_ExceptionHandlerCount();
  public: String get_Name();
  public: Int32 get_MetadataTokenInternal();
  public: Module get_Module();
  public: Type get_DeclaringType();
  public: ICustomAttributeProvider get_ReturnTypeCustomAttributes();
  public: Type get_ReflectedType();
  public: MethodAttributes get_Attributes();
  public: CallingConventions get_CallingConvention();
  public: RuntimeMethodHandle get_MethodHandle();
  public: Boolean get_IsSecurityCritical();
  public: Boolean get_IsSecuritySafeCritical();
  public: Boolean get_IsSecurityTransparent();
  public: Type get_ReturnType();
  public: ParameterInfo get_ReturnParameter();
  public: Boolean get_IsGenericMethodDefinition();
  public: Boolean get_ContainsGenericParameters();
  public: Boolean get_IsGenericMethod();
  public: Boolean get_InitLocals();
  public: void set_InitLocals(Boolean value);
  public: String get_Signature();
  public: void ctor(String name, MethodAttributes attributes, CallingConventions callingConvention, Type returnType, Array<Type> returnTypeRequiredCustomModifiers, Array<Type> returnTypeOptionalCustomModifiers, Array<Type> parameterTypes, Array<Array<Type>> parameterTypeRequiredCustomModifiers, Array<Array<Type>> parameterTypeOptionalCustomModifiers, ModuleBuilder mod, TypeBuilder type);
  public: void CheckContext(Array<Array<Type>> typess);
  public: void CheckContext(Array<Type> types);
  public: void CreateMethodBodyHelper(ILGenerator il);
  public: void ReleaseBakedStructures();
  public: Array<Type> GetParameterTypes();
  public: static Type GetMethodBaseReturnType(MethodBase method);
  public: void SetToken(MethodToken token);
  public: Array<Byte> GetBody();
  public: Array<Int32> GetTokenFixups();
  public: SignatureHelper GetMethodSignature();
  public: Array<Byte> GetLocalSignature(Int32& signatureLength);
  public: Int32 GetMaxStack();
  public: Array<ExceptionHandler> GetExceptionHandlers();
  public: static Int32 CalculateNumberOfExceptions(Array<__ExceptionInfo> excp);
  public: Boolean IsTypeCreated();
  public: TypeBuilder GetTypeBuilder();
  public: ModuleBuilder GetModuleBuilder();
  public: Boolean Equals(Object obj);
  public: Int32 GetHashCode();
  public: String ToString();
  public: Object Invoke(Object obj, BindingFlags invokeAttr, Binder binder, Array<Object> parameters, CultureInfo culture);
  public: MethodImplAttributes GetMethodImplementationFlags();
  public: MethodInfo GetBaseDefinition();
  public: Array<ParameterInfo> GetParameters();
  public: Array<Object> GetCustomAttributes(Boolean inherit);
  public: Array<Object> GetCustomAttributes(Type attributeType, Boolean inherit);
  public: Boolean IsDefined(Type attributeType, Boolean inherit);
  public: MethodInfo GetGenericMethodDefinition();
  public: Array<Type> GetGenericArguments();
  public: MethodInfo MakeGenericMethod(Array<Type> typeArguments);
  public: Array<GenericTypeParameterBuilder> DefineGenericParameters(Array<String> names);
  public: void ThrowIfGeneric();
  public: MethodToken GetToken();
  private: MethodToken GetTokenNoLock();
  public: void SetParameters(Array<Type> parameterTypes);
  public: void SetReturnType(Type returnType);
  public: void SetSignature(Type returnType, Array<Type> returnTypeRequiredCustomModifiers, Array<Type> returnTypeOptionalCustomModifiers, Array<Type> parameterTypes, Array<Array<Type>> parameterTypeRequiredCustomModifiers, Array<Array<Type>> parameterTypeOptionalCustomModifiers);
  public: ParameterBuilder DefineParameter(Int32 position, ParameterAttributes attributes, String strParamName);
  public: void SetImplementationFlags(MethodImplAttributes attributes);
  public: ILGenerator GetILGenerator();
  public: ILGenerator GetILGenerator(Int32 size);
  private: void ThrowIfShouldNotHaveBody();
  public: Module GetModule();
  public: void SetCustomAttribute(ConstructorInfo con, Array<Byte> binaryAttribute);
  public: void SetCustomAttribute(CustomAttributeBuilder customBuilder);
  private: static Boolean IsKnownCA(ConstructorInfo con);
  private: void ParseCA(ConstructorInfo con);
  public: String m_strName;
  private: MethodToken m_tkMethod;
  private: ModuleBuilder m_module;
  public: TypeBuilder m_containingType;
  private: Array<Int32> m_mdMethodFixups;
  private: Array<Byte> m_localSignature;
  public: LocalSymInfo m_localSymInfo;
  public: ILGenerator m_ilGenerator;
  private: Array<Byte> m_ubBody;
  private: Array<ExceptionHandler> m_exceptions;
  public: Boolean m_bIsBaked;
  private: Boolean m_fInitLocals;
  private: MethodAttributes m_iAttributes;
  private: CallingConventions m_callingConvention;
  private: MethodImplAttributes m_dwMethodImplFlags;
  private: SignatureHelper m_signature;
  public: Array<Type> m_parameterTypes;
  private: Type m_returnType;
  private: Array<Type> m_returnTypeRequiredCustomModifiers;
  private: Array<Type> m_returnTypeOptionalCustomModifiers;
  private: Array<Array<Type>> m_parameterTypeRequiredCustomModifiers;
  private: Array<Array<Type>> m_parameterTypeOptionalCustomModifiers;
  private: Array<GenericTypeParameterBuilder> m_inst;
  private: Boolean m_bIsGenMethDef;
  public: Boolean m_canBeRuntimeImpl;
  public: Boolean m_isDllImport;
};
} // namespace MethodBuilderNamespace
using MethodBuilder = MethodBuilderNamespace::MethodBuilder;
} // namespace System::Private::CoreLib::System::Reflection::Emit
