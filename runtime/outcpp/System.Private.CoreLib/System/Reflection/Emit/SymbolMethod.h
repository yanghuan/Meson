#pragma once

#include <System.Private.CoreLib/System/Reflection/Emit/MethodToken.h>
#include <System.Private.CoreLib/System/Reflection/MethodInfo.h>

namespace System::Private::CoreLib::System::Reflection {
enum class BindingFlags;
enum class CallingConventions;
enum class MethodAttributes;
enum class MethodImplAttributes;
FORWARD(Binder)
FORWARD(ICustomAttributeProvider)
FORWARD(Module)
FORWARD(ParameterInfo)
} // namespace System::Private::CoreLib::System::Reflection
namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
FORWARD(Object)
FORWARDS(RuntimeMethodHandle)
FORWARD(String)
FORWARD(Type)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Globalization {
FORWARD(CultureInfo)
} // namespace System::Private::CoreLib::System::Globalization
namespace System::Private::CoreLib::System::Reflection::Emit {
FORWARD(ModuleBuilder)
FORWARD(SignatureHelper)
namespace SymbolMethodNamespace {
using namespace Globalization;
CLASS(SymbolMethod) : public MethodInfo::in {
  public: Module get_Module();
  public: Type get_ReflectedType();
  public: String get_Name();
  public: Type get_DeclaringType();
  public: MethodAttributes get_Attributes();
  public: CallingConventions get_CallingConvention();
  public: RuntimeMethodHandle get_MethodHandle();
  public: Type get_ReturnType();
  public: ICustomAttributeProvider get_ReturnTypeCustomAttributes();
  public: void Ctor(ModuleBuilder mod, MethodToken token, Type arrayClass, String methodName, CallingConventions callingConvention, Type returnType, Array<Type> parameterTypes);
  public: Array<Type> GetParameterTypes();
  public: MethodToken GetToken(ModuleBuilder mod);
  public: Array<ParameterInfo> GetParameters();
  public: MethodImplAttributes GetMethodImplementationFlags();
  public: Object Invoke(Object obj, BindingFlags invokeAttr, Binder binder, Array<Object> parameters, CultureInfo culture);
  public: MethodInfo GetBaseDefinition();
  public: Array<Object> GetCustomAttributes(Boolean inherit);
  public: Array<Object> GetCustomAttributes(Type attributeType, Boolean inherit);
  public: Boolean IsDefined(Type attributeType, Boolean inherit);
  public: Module GetModule();
  public: MethodToken GetToken();
  private: ModuleBuilder m_module;
  private: Type m_containingType;
  private: String m_name;
  private: CallingConventions m_callingConvention;
  private: Type m_returnType;
  private: MethodToken m_mdMethod;
  private: Array<Type> m_parameterTypes;
  private: SignatureHelper m_signature;
};
} // namespace SymbolMethodNamespace
using SymbolMethod = SymbolMethodNamespace::SymbolMethod;
} // namespace System::Private::CoreLib::System::Reflection::Emit
