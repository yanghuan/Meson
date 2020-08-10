#pragma once

#include <System.Private.CoreLib/System/IntPtr.h>
#include <System.Private.CoreLib/System/Reflection/MethodInfo.h>
#include <System.Private.CoreLib/System/RuntimeType.h>

namespace System::Private::CoreLib::System {
enum class DelegateBindingFlags;
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
FORWARD(Delegate)
FORWARDS(Int32)
FORWARD(IRuntimeMethodInfo)
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
namespace System::Private::CoreLib::System::Threading {
enum class StackCrawlMark;
} // namespace System::Private::CoreLib::System::Threading
namespace System::Private::CoreLib::System::Reflection {
enum class BindingFlags;
enum class CallingConventions;
enum class INVOCATION_FLAGS : uint32_t;
enum class MemberTypes;
enum class MethodAttributes;
enum class MethodImplAttributes;
FORWARD(Binder)
FORWARD(CustomAttributeData)
FORWARD(ICustomAttributeProvider)
FORWARD(MemberInfo)
FORWARD(MethodBase)
FORWARD(MethodBody)
FORWARD(Module)
FORWARD(ParameterInfo)
FORWARD(RuntimeModule)
namespace RuntimeMethodInfoNamespace {
using namespace Collections::Generic;
using namespace Globalization;
using namespace Threading;
using Collections::Generic::IList;
CLASS(RuntimeMethodInfo) : public MethodInfo::in {
  public: using interface = rt::TypeList<IRuntimeMethodInfo>;
  public: INVOCATION_FLAGS get_InvocationFlags();
  private: RuntimeMethodHandleInternal get_ValueOfIRuntimeMethodInfo();
  private: RuntimeType get_ReflectedTypeInternal();
  public: Signature get_Signature();
  public: BindingFlags get_BindingFlags();
  public: Int32 get_GenericParameterCount();
  public: String get_Name();
  public: Type get_DeclaringType();
  public: Type get_ReflectedType();
  public: MemberTypes get_MemberType();
  public: Int32 get_MetadataToken();
  public: Module get_Module();
  public: Boolean get_IsSecurityCritical();
  public: Boolean get_IsSecuritySafeCritical();
  public: Boolean get_IsSecurityTransparent();
  public: RuntimeMethodHandle get_MethodHandle();
  public: MethodAttributes get_Attributes();
  public: CallingConventions get_CallingConvention();
  public: Type get_ReturnType();
  public: ICustomAttributeProvider get_ReturnTypeCustomAttributes();
  public: ParameterInfo get_ReturnParameter();
  public: Boolean get_IsCollectible();
  public: Boolean get_IsGenericMethod();
  public: Boolean get_IsGenericMethodDefinition();
  public: Boolean get_ContainsGenericParameters();
  private: static Boolean IsDisallowedByRefType(Type type);
  public: void ctor(RuntimeMethodHandleInternal handle, RuntimeType declaringType, RuntimeType::in::RuntimeTypeCache reflectedTypeCache, MethodAttributes methodAttributes, BindingFlags bindingFlags, Object keepalive);
  private: Array<ParameterInfo> FetchNonReturnParameters();
  private: ParameterInfo FetchReturnParameter();
  public: Boolean CacheEquals(Object o);
  public: RuntimeMethodInfo GetParentDefinition();
  public: RuntimeType GetDeclaringTypeInternal();
  public: String ToString();
  public: Int32 GetHashCode();
  public: Boolean Equals(Object obj);
  public: Array<Object> GetCustomAttributes(Boolean inherit);
  public: Array<Object> GetCustomAttributes(Type attributeType, Boolean inherit);
  public: Boolean IsDefined(Type attributeType, Boolean inherit);
  public: IList<CustomAttributeData> GetCustomAttributesData();
  public: Boolean HasSameMetadataDefinitionAs(MemberInfo other);
  public: RuntimeType GetRuntimeType();
  public: RuntimeModule GetRuntimeModule();
  public: Array<ParameterInfo> GetParametersNoCopy();
  public: Array<ParameterInfo> GetParameters();
  public: MethodImplAttributes GetMethodImplementationFlags();
  public: MethodBody GetMethodBody();
  private: void CheckConsistency(Object target);
  private: void ThrowNoInvokeException();
  public: Object Invoke(Object obj, BindingFlags invokeAttr, Binder binder, Array<Object> parameters, CultureInfo culture);
  private: Array<Object> InvokeArgumentsCheck(Object obj, BindingFlags invokeAttr, Binder binder, Array<Object> parameters, CultureInfo culture);
  public: MethodInfo GetBaseDefinition();
  public: Delegate CreateDelegate(Type delegateType);
  public: Delegate CreateDelegate(Type delegateType, Object target);
  private: Delegate CreateDelegateInternal(Type delegateType, Object firstArgument, DelegateBindingFlags bindingFlags);
  public: MethodInfo MakeGenericMethod(Array<Type> methodInstantiation);
  public: Array<RuntimeType> GetGenericArgumentsInternal();
  public: Array<Type> GetGenericArguments();
  public: MethodInfo GetGenericMethodDefinition();
  public: static MethodBase InternalGetCurrentMethod(StackCrawlMark& stackMark);
  private: IntPtr m_handle;
  private: RuntimeType::in::RuntimeTypeCache m_reflectedTypeCache;
  private: String m_name;
  private: String m_toString;
  private: Array<ParameterInfo> m_parameters;
  private: ParameterInfo m_returnParameter;
  private: BindingFlags m_bindingFlags;
  private: MethodAttributes m_methodAttributes;
  private: Signature m_signature;
  private: RuntimeType m_declaringType;
  private: Object m_keepalive;
  private: INVOCATION_FLAGS m_invocationFlags;
};
} // namespace RuntimeMethodInfoNamespace
using RuntimeMethodInfo = RuntimeMethodInfoNamespace::RuntimeMethodInfo;
} // namespace System::Private::CoreLib::System::Reflection
