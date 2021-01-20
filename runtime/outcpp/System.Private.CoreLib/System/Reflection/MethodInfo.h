#pragma once

#include <System.Private.CoreLib/System/Reflection/MethodBase.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array)
FORWARDS(Boolean)
FORWARD(Delegate)
FORWARDS(Int32)
FORWARD(Object)
FORWARD(Type)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection {
enum class MemberTypes : int32_t;
FORWARD(ICustomAttributeProvider)
FORWARD(ParameterInfo)
namespace MethodInfoNamespace {
CLASS(MethodInfo) : public MethodBase::in {
  public: MemberTypes get_MemberType();
  public: ParameterInfo get_ReturnParameter();
  public: Type get_ReturnType();
  public: ICustomAttributeProvider get_ReturnTypeCustomAttributes();
  public: Int32 get_GenericParameterCount();
  public: void ctor();
  public: Array<Type> GetGenericArguments();
  public: MethodInfo GetGenericMethodDefinition();
  public: MethodInfo MakeGenericMethod(Array<Type> typeArguments);
  public: MethodInfo GetBaseDefinition();
  public: Delegate CreateDelegate(Type delegateType);
  public: Delegate CreateDelegate(Type delegateType, Object target);
  public: template <class T>
  T CreateDelegate();
  public: template <class T>
  T CreateDelegate(Object target);
  public: Boolean Equals(Object obj);
  public: Int32 GetHashCode();
  public: static Boolean op_Equality(MethodInfo left, MethodInfo right);
  public: static Boolean op_Inequality(MethodInfo left, MethodInfo right);
};
} // namespace MethodInfoNamespace
using MethodInfo = MethodInfoNamespace::MethodInfo;
} // namespace System::Private::CoreLib::System::Reflection
