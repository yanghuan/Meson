#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Boolean.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
FORWARD(Type)
FORWARDS(RuntimeMethodHandle)
FORWARD_(Array, T1, T2)
FORWARD(Object)
FORWARD(Delegate)
FORWARDS(Int32)
FORWARD(RuntimeType)
FORWARD(IRuntimeMethodInfo)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection {
FORWARD(Module)
enum class MethodAttributes;
enum class CallingConventions;
FORWARD(ParameterInfo)
FORWARD(ICustomAttributeProvider)
FORWARD(MethodInfo)
enum class MethodImplAttributes;
enum class BindingFlags;
FORWARD(Binder)
FORWARD(RuntimeParameterInfo)
FORWARD(RuntimeModule)
enum class ParameterAttributes;
} // namespace System::Private::CoreLib::System::Reflection
namespace System::Private::CoreLib::System::Globalization {
FORWARD(CultureInfo)
} // namespace System::Private::CoreLib::System::Globalization
namespace System::Private::CoreLib::System::Reflection::Emit {
FORWARD(ParameterBuilder)
FORWARD(DynamicILInfo)
FORWARD(ILGenerator)
FORWARD(DynamicILGenerator)
FORWARD(DynamicResolver)
FORWARD(InternalModuleBuilder)
namespace DynamicMethodNamespace {
using namespace ::System::Private::CoreLib::System::Globalization;
CLASS(DynamicMethod) {
  public: CLASS(RTDynamicMethod) {
    public: String get_Name();
    public: Type get_DeclaringType();
    public: Type get_ReflectedType();
    public: Module get_Module();
    public: RuntimeMethodHandle get_MethodHandle();
    public: MethodAttributes get_Attributes();
    public: CallingConventions get_CallingConvention();
    public: Boolean get_IsSecurityCritical();
    public: Boolean get_IsSecuritySafeCritical();
    public: Boolean get_IsSecurityTransparent();
    public: Type get_ReturnType();
    public: ParameterInfo get_ReturnParameter();
    public: ICustomAttributeProvider get_ReturnTypeCustomAttributes();
    public: String ToString();
    public: MethodInfo GetBaseDefinition();
    public: Array<ParameterInfo> GetParameters();
    public: MethodImplAttributes GetMethodImplementationFlags();
    public: Object Invoke(Object obj, BindingFlags invokeAttr, Binder binder, Array<Object> parameters, CultureInfo culture);
    public: Array<Object> GetCustomAttributes(Type attributeType, Boolean inherit);
    public: Array<Object> GetCustomAttributes(Boolean inherit);
    public: Boolean IsDefined(Type attributeType, Boolean inherit);
    public: Array<RuntimeParameterInfo> LoadParameters();
    public: DynamicMethod m_owner;
    private: Array<RuntimeParameterInfo> m_parameters;
    private: String m_name;
    private: MethodAttributes m_attributes;
    private: CallingConventions m_callingConvention;
  };
  public: String get_Name();
  public: Type get_DeclaringType();
  public: Type get_ReflectedType();
  public: Module get_Module();
  public: RuntimeMethodHandle get_MethodHandle();
  public: MethodAttributes get_Attributes();
  public: CallingConventions get_CallingConvention();
  public: Boolean get_IsSecurityCritical();
  public: Boolean get_IsSecuritySafeCritical();
  public: Boolean get_IsSecurityTransparent();
  public: Type get_ReturnType();
  public: ParameterInfo get_ReturnParameter();
  public: ICustomAttributeProvider get_ReturnTypeCustomAttributes();
  public: Boolean get_InitLocals();
  public: void set_InitLocals(Boolean value);
  private: static void CheckConsistency(MethodAttributes attributes, CallingConventions callingConvention);
  private: static RuntimeModule GetDynamicMethodsModule();
  private: void Init(String name, MethodAttributes attributes, CallingConventions callingConvention, Type returnType, Array<Type> signature, Type owner, Module m, Boolean skipVisibility, Boolean transparentMethod);
  public: Delegate CreateDelegate(Type delegateType);
  public: Delegate CreateDelegate(Type delegateType, Object target);
  public: RuntimeMethodHandle GetMethodDescriptor();
  public: String ToString();
  public: MethodInfo GetBaseDefinition();
  public: Array<ParameterInfo> GetParameters();
  public: MethodImplAttributes GetMethodImplementationFlags();
  public: Object Invoke(Object obj, BindingFlags invokeAttr, Binder binder, Array<Object> parameters, CultureInfo culture);
  public: Array<Object> GetCustomAttributes(Type attributeType, Boolean inherit);
  public: Array<Object> GetCustomAttributes(Boolean inherit);
  public: Boolean IsDefined(Type attributeType, Boolean inherit);
  public: ParameterBuilder DefineParameter(Int32 position, ParameterAttributes attributes, String parameterName);
  public: DynamicILInfo GetDynamicILInfo();
  public: ILGenerator GetILGenerator();
  public: ILGenerator GetILGenerator(Int32 streamSize);
  public: MethodInfo GetMethodInfo();
  private: Array<RuntimeType> m_parameterTypes;
  public: IRuntimeMethodInfo m_methodHandle;
  private: RuntimeType m_returnType;
  private: DynamicILGenerator m_ilGenerator;
  private: DynamicILInfo m_DynamicILInfo;
  private: Boolean m_fInitLocals;
  private: RuntimeModule m_module;
  public: Boolean m_skipVisibility;
  public: RuntimeType m_typeOwner;
  private: RTDynamicMethod m_dynMethod;
  public: DynamicResolver m_resolver;
  public: Boolean m_restrictedSkipVisibility;
  private: static InternalModuleBuilder s_anonymouslyHostedDynamicMethodsModule;
  private: static Object s_anonymouslyHostedDynamicMethodsModuleLock;
};
} // namespace DynamicMethodNamespace
using DynamicMethod = DynamicMethodNamespace::DynamicMethod;
} // namespace System::Private::CoreLib::System::Reflection::Emit
