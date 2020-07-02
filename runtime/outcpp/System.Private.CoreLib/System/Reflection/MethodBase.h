#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
FORWARDS(Int32)
FORWARDS(IntPtr)
FORWARD(Object)
FORWARDS(RuntimeMethodHandle)
FORWARDS(RuntimeTypeHandle)
FORWARD(Signature)
FORWARD(Type)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Text {
FORWARDS(ValueStringBuilder)
} // namespace System::Private::CoreLib::System::Text
namespace System::Private::CoreLib::System::Globalization {
FORWARD(CultureInfo)
} // namespace System::Private::CoreLib::System::Globalization
namespace System::Private::CoreLib::System::Reflection {
enum class MethodAttributes;
enum class MethodImplAttributes;
enum class CallingConventions;
FORWARD(ParameterInfo)
FORWARD(Binder)
enum class BindingFlags;
FORWARD(MethodBody)
namespace MethodBaseNamespace {
using namespace ::System::Private::CoreLib::System::Globalization;
using namespace ::System::Private::CoreLib::System::Text;
CLASS(MethodBase) {
  public: MethodAttributes get_Attributes();
  public: MethodImplAttributes get_MethodImplementationFlags();
  public: CallingConventions get_CallingConvention();
  public: Boolean get_IsAbstract();
  public: Boolean get_IsConstructor();
  public: Boolean get_IsFinal();
  public: Boolean get_IsHideBySig();
  public: Boolean get_IsSpecialName();
  public: Boolean get_IsStatic();
  public: Boolean get_IsVirtual();
  public: Boolean get_IsAssembly();
  public: Boolean get_IsFamily();
  public: Boolean get_IsFamilyAndAssembly();
  public: Boolean get_IsFamilyOrAssembly();
  public: Boolean get_IsPrivate();
  public: Boolean get_IsPublic();
  public: Boolean get_IsConstructedGenericMethod();
  public: Boolean get_IsGenericMethod();
  public: Boolean get_IsGenericMethodDefinition();
  public: Boolean get_ContainsGenericParameters();
  public: RuntimeMethodHandle get_MethodHandle();
  public: Boolean get_IsSecurityCritical();
  public: Boolean get_IsSecuritySafeCritical();
  public: Boolean get_IsSecurityTransparent();
  public: static MethodBase GetMethodFromHandle(RuntimeMethodHandle handle);
  public: static MethodBase GetMethodFromHandle(RuntimeMethodHandle handle, RuntimeTypeHandle declaringType);
  public: static MethodBase GetCurrentMethod();
  private: IntPtr GetMethodDesc();
  public: Array<ParameterInfo> GetParametersNoCopy();
  public: static void AppendParameters(ValueStringBuilder& sbParamList, Array<Type> parameterTypes, CallingConventions callingConvention);
  public: Array<Type> GetParameterTypes();
  public: Array<Object> CheckArguments(Array<Object> parameters, Binder binder, BindingFlags invokeAttr, CultureInfo culture, Signature sig);
  public: Array<ParameterInfo> GetParameters();
  public: MethodImplAttributes GetMethodImplementationFlags();
  public: MethodBody GetMethodBody();
  public: Array<Type> GetGenericArguments();
  public: Object Invoke(Object obj, Array<Object> parameters);
  public: Object Invoke(Object obj, BindingFlags invokeAttr, Binder binder, Array<Object> parameters, CultureInfo culture);
  public: Boolean Equals(Object obj);
  public: Int32 GetHashCode();
};
} // namespace MethodBaseNamespace
using MethodBase = MethodBaseNamespace::MethodBase;
} // namespace System::Private::CoreLib::System::Reflection