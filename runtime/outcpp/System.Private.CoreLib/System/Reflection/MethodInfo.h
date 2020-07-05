#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
FORWARD(Delegate)
FORWARDS(Int32)
FORWARD(Object)
FORWARD(Type)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection {
enum class MemberTypes;
FORWARD(ICustomAttributeProvider)
FORWARD(ParameterInfo)
namespace MethodInfoNamespace {
CLASS(MethodInfo) {
  public: MemberTypes get_MemberType();
  public: ParameterInfo get_ReturnParameter();
  public: Type get_ReturnType();
  public: ICustomAttributeProvider get_ReturnTypeCustomAttributes();
  public: Int32 get_GenericParameterCount();
  public: Array<Type> GetGenericArguments();
  public: MethodInfo GetGenericMethodDefinition();
  public: MethodInfo MakeGenericMethod(Array<Type> typeArguments);
  public: MethodInfo GetBaseDefinition();
  public: Delegate CreateDelegate(Type delegateType);
  public: Delegate CreateDelegate(Type delegateType, Object target);
  public: Boolean Equals(Object obj);
  public: Int32 GetHashCode();
};
} // namespace MethodInfoNamespace
using MethodInfo = MethodInfoNamespace::MethodInfo;
} // namespace System::Private::CoreLib::System::Reflection
