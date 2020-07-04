#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/IntPtr.h>
#include <System.Private.CoreLib/System/RuntimeType.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
FORWARD(Delegate)
enum class DelegateBindingFlags;
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
namespace System::Private::CoreLib::System::Threading {
enum class StackCrawlMark;
} // namespace System::Private::CoreLib::System::Threading
namespace System::Private::CoreLib::System::Reflection {
enum class INVOCATION_FLAGS : uint32_t;
enum class BindingFlags;
enum class MemberTypes;
FORWARD(Module)
enum class MethodAttributes;
enum class CallingConventions;
FORWARD(ICustomAttributeProvider)
FORWARD(ParameterInfo)
FORWARD(CustomAttributeData)
FORWARD(MemberInfo)
FORWARD(RuntimeModule)
enum class MethodImplAttributes;
FORWARD(MethodBody)
FORWARD(Binder)
FORWARD(MethodInfo)
FORWARD(MethodBase)
namespace RuntimeMethodInfoNamespace {
using namespace ::System::Private::CoreLib::System::Collections::Generic;
using namespace ::System::Private::CoreLib::System::Globalization;
using namespace ::System::Private::CoreLib::System::Threading;
using ::System::Private::CoreLib::System::Collections::Generic::IList;
CLASS(RuntimeMethodInfo) {
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
