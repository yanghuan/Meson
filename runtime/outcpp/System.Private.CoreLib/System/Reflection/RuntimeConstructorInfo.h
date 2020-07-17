#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/IntPtr.h>
#include <System.Private.CoreLib/System/RuntimeType.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
FORWARDS(Int32)
FORWARD(Object)
FORWARDS(RuntimeMethodHandle)
FORWARDS(RuntimeMethodHandleInternal)
FORWARD(Signature)
FORWARD(String)
FORWARD(Type)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(IList, T)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System::Globalization {
FORWARD(CultureInfo)
} // namespace System::Private::CoreLib::System::Globalization
namespace System::Private::CoreLib::System::Reflection {
enum class BindingFlags;
enum class CallingConventions;
enum class INVOCATION_FLAGS : uint32_t;
enum class MemberTypes;
enum class MethodAttributes;
enum class MethodImplAttributes;
FORWARD(Binder)
FORWARD(CustomAttributeData)
FORWARD(MemberInfo)
FORWARD(MethodBody)
FORWARD(Module)
FORWARD(ParameterInfo)
FORWARD(RuntimeModule)
namespace RuntimeConstructorInfoNamespace {
using namespace Collections::Generic;
using namespace Globalization;
using Collections::Generic::IList;
CLASS(RuntimeConstructorInfo) {
  public: INVOCATION_FLAGS get_InvocationFlags();
  private: RuntimeMethodHandleInternal get_ValueOfIRuntimeMethodInfo();
  private: Signature get_Signature();
  private: RuntimeType get_ReflectedTypeInternal();
  public: BindingFlags get_BindingFlags();
  public: String get_Name();
  public: MemberTypes get_MemberType();
  public: Type get_DeclaringType();
  public: Type get_ReflectedType();
  public: Int32 get_MetadataToken();
  public: Module get_Module();
  public: RuntimeMethodHandle get_MethodHandle();
  public: MethodAttributes get_Attributes();
  public: CallingConventions get_CallingConvention();
  public: Boolean get_IsSecurityCritical();
  public: Boolean get_IsSecuritySafeCritical();
  public: Boolean get_IsSecurityTransparent();
  public: Boolean get_ContainsGenericParameters();
  public: void Ctor(RuntimeMethodHandleInternal handle, RuntimeType declaringType, RuntimeType::in::RuntimeTypeCache reflectedTypeCache, MethodAttributes methodAttributes, BindingFlags bindingFlags);
  public: Boolean CacheEquals(Object o);
  private: void CheckConsistency(Object target);
  public: String ToString();
  public: Array<Object> GetCustomAttributes(Boolean inherit);
  public: Array<Object> GetCustomAttributes(Type attributeType, Boolean inherit);
  public: Boolean IsDefined(Type attributeType, Boolean inherit);
  public: IList<CustomAttributeData> GetCustomAttributesData();
  public: Boolean HasSameMetadataDefinitionAs(MemberInfo other);
  public: RuntimeType GetRuntimeType();
  public: RuntimeModule GetRuntimeModule();
  public: Type GetReturnType();
  public: Array<ParameterInfo> GetParametersNoCopy();
  public: Array<ParameterInfo> GetParameters();
  public: MethodImplAttributes GetMethodImplementationFlags();
  public: static void CheckCanCreateInstance(Type declaringType, Boolean isVarArg);
  public: void ThrowNoInvokeException();
  public: Object Invoke(Object obj, BindingFlags invokeAttr, Binder binder, Array<Object> parameters, CultureInfo culture);
  public: MethodBody GetMethodBody();
  public: Object Invoke(BindingFlags invokeAttr, Binder binder, Array<Object> parameters, CultureInfo culture);
  private: RuntimeType m_declaringType;
  private: RuntimeType::in::RuntimeTypeCache m_reflectedTypeCache;
  private: String m_toString;
  private: Array<ParameterInfo> m_parameters;
  private: Object _empty1;
  private: Object _empty2;
  private: Object _empty3;
  private: IntPtr m_handle;
  private: MethodAttributes m_methodAttributes;
  private: BindingFlags m_bindingFlags;
  private: Signature m_signature;
  private: INVOCATION_FLAGS m_invocationFlags;
};
} // namespace RuntimeConstructorInfoNamespace
using RuntimeConstructorInfo = RuntimeConstructorInfoNamespace::RuntimeConstructorInfo;
} // namespace System::Private::CoreLib::System::Reflection
