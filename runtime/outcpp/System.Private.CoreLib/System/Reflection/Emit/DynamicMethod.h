#pragma once

#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/Reflection/MethodInfo.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARD(Delegate)
FORWARDS(Int32)
FORWARD(IRuntimeMethodInfo)
FORWARD(Object)
FORWARDS(RuntimeMethodHandle)
FORWARD(RuntimeType)
FORWARD(String)
FORWARD(Type)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection {
enum class BindingFlags;
enum class CallingConventions;
enum class MethodAttributes;
enum class MethodImplAttributes;
enum class ParameterAttributes;
FORWARD(Binder)
FORWARD(ICustomAttributeProvider)
FORWARD(Module)
FORWARD(ParameterInfo)
FORWARD(RuntimeModule)
FORWARD(RuntimeParameterInfo)
} // namespace System::Private::CoreLib::System::Reflection
namespace System::Private::CoreLib::System::Globalization {
FORWARD(CultureInfo)
} // namespace System::Private::CoreLib::System::Globalization
namespace System::Private::CoreLib::System::Reflection::Emit {
FORWARD(DynamicILGenerator)
FORWARD(DynamicILInfo)
FORWARD(DynamicResolver)
FORWARD(ILGenerator)
FORWARD(InternalModuleBuilder)
FORWARD(ParameterBuilder)
namespace DynamicMethodNamespace {
using namespace Globalization;
CLASS(DynamicMethod) : public MethodInfo::in {
  public: CLASS(RTDynamicMethod) : public MethodInfo::in {
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
    public: void Ctor(DynamicMethod owner, String name, MethodAttributes attributes, CallingConventions callingConvention);
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
  public: void Ctor(String name, Type returnType, Array<Type> parameterTypes);
  public: void Ctor(String name, Type returnType, Array<Type> parameterTypes, Boolean restrictedSkipVisibility);
  public: void Ctor(String name, Type returnType, Array<Type> parameterTypes, Module m);
  public: void Ctor(String name, Type returnType, Array<Type> parameterTypes, Module m, Boolean skipVisibility);
  public: void Ctor(String name, MethodAttributes attributes, CallingConventions callingConvention, Type returnType, Array<Type> parameterTypes, Module m, Boolean skipVisibility);
  public: void Ctor(String name, Type returnType, Array<Type> parameterTypes, Type owner);
  public: void Ctor(String name, Type returnType, Array<Type> parameterTypes, Type owner, Boolean skipVisibility);
  public: void Ctor(String name, MethodAttributes attributes, CallingConventions callingConvention, Type returnType, Array<Type> parameterTypes, Type owner, Boolean skipVisibility);
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
  private: static void SCtor();
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
