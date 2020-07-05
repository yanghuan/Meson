#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Boolean.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Byte)
FORWARDS(Int32)
FORWARD(Object)
FORWARDS(RuntimeMethodHandle)
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
FORWARD(ConstructorInfo)
FORWARD(Module)
FORWARD(ParameterInfo)
} // namespace System::Private::CoreLib::System::Reflection
namespace System::Private::CoreLib::System::Globalization {
FORWARD(CultureInfo)
} // namespace System::Private::CoreLib::System::Globalization
namespace System::Private::CoreLib::System::Reflection::Emit {
FORWARD(CustomAttributeBuilder)
FORWARD(ILGenerator)
FORWARD(MethodBuilder)
FORWARDS(MethodToken)
FORWARD(ParameterBuilder)
FORWARD(TypeBuilder)
namespace ConstructorBuilderNamespace {
using namespace Globalization;
CLASS(ConstructorBuilder) {
  public: Int32 get_MetadataTokenInternal();
  public: Module get_Module();
  public: Type get_ReflectedType();
  public: Type get_DeclaringType();
  public: String get_Name();
  public: MethodAttributes get_Attributes();
  public: RuntimeMethodHandle get_MethodHandle();
  public: CallingConventions get_CallingConvention();
  public: String get_Signature();
  public: Boolean get_InitLocals();
  public: void set_InitLocals(Boolean value);
  public: Array<Type> GetParameterTypes();
  private: TypeBuilder GetTypeBuilder();
  public: String ToString();
  public: Object Invoke(Object obj, BindingFlags invokeAttr, Binder binder, Array<Object> parameters, CultureInfo culture);
  public: Array<ParameterInfo> GetParameters();
  public: MethodImplAttributes GetMethodImplementationFlags();
  public: Object Invoke(BindingFlags invokeAttr, Binder binder, Array<Object> parameters, CultureInfo culture);
  public: Array<Object> GetCustomAttributes(Boolean inherit);
  public: Array<Object> GetCustomAttributes(Type attributeType, Boolean inherit);
  public: Boolean IsDefined(Type attributeType, Boolean inherit);
  public: MethodToken GetToken();
  public: ParameterBuilder DefineParameter(Int32 iSequence, ParameterAttributes attributes, String strParamName);
  public: ILGenerator GetILGenerator();
  public: ILGenerator GetILGenerator(Int32 streamSize);
  public: Module GetModule();
  public: Type GetReturnType();
  public: void SetCustomAttribute(ConstructorInfo con, Array<Byte> binaryAttribute);
  public: void SetCustomAttribute(CustomAttributeBuilder customBuilder);
  public: void SetImplementationFlags(MethodImplAttributes attributes);
  private: MethodBuilder m_methodBuilder;
  public: Boolean m_isDefaultConstructor;
};
} // namespace ConstructorBuilderNamespace
using ConstructorBuilder = ConstructorBuilderNamespace::ConstructorBuilder;
} // namespace System::Private::CoreLib::System::Reflection::Emit
