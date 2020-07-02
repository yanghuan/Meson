#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Reflection/Emit/MethodToken.h>

namespace System::Private::CoreLib::System::Reflection {
FORWARD(Module)
enum class MethodAttributes;
enum class CallingConventions;
FORWARD(ICustomAttributeProvider)
FORWARD(ParameterInfo)
enum class MethodImplAttributes;
enum class BindingFlags;
FORWARD(Binder)
FORWARD(MethodInfo)
} // namespace System::Private::CoreLib::System::Reflection
namespace System::Private::CoreLib::System {
FORWARD(Type)
FORWARD(String)
FORWARDS(RuntimeMethodHandle)
FORWARD_(Array, T1, T2)
FORWARD(Object)
FORWARDS(Boolean)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Globalization {
FORWARD(CultureInfo)
} // namespace System::Private::CoreLib::System::Globalization
namespace System::Private::CoreLib::System::Reflection::Emit {
FORWARD(ModuleBuilder)
FORWARD(SignatureHelper)
namespace SymbolMethodNamespace {
using namespace ::System::Private::CoreLib::System::Globalization;
CLASS(SymbolMethod) {
  public: Module get_Module();
  public: Type get_ReflectedType();
  public: String get_Name();
  public: Type get_DeclaringType();
  public: MethodAttributes get_Attributes();
  public: CallingConventions get_CallingConvention();
  public: RuntimeMethodHandle get_MethodHandle();
  public: Type get_ReturnType();
  public: ICustomAttributeProvider get_ReturnTypeCustomAttributes();
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
