#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
FORWARDS(Int32)
FORWARD(String)
FORWARD(Type)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(IEnumerable, T)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System::Reflection {
FORWARD(ConstructorInfo)
FORWARD(EventInfo)
FORWARD(FieldInfo)
FORWARD(MemberInfo)
FORWARD(MethodInfo)
FORWARD(PropertyInfo)
namespace TypeInfoNamespace {
using namespace ::System::Private::CoreLib::System::Collections::Generic;
CLASS(TypeInfo) {
  public: Array<Type> get_GenericTypeParameters();
  public: IEnumerable<ConstructorInfo> get_DeclaredConstructors();
  public: IEnumerable<EventInfo> get_DeclaredEvents();
  public: IEnumerable<FieldInfo> get_DeclaredFields();
  public: IEnumerable<MemberInfo> get_DeclaredMembers();
  public: IEnumerable<MethodInfo> get_DeclaredMethods();
  public: IEnumerable<TypeInfo> get_DeclaredNestedTypes();
  public: IEnumerable<PropertyInfo> get_DeclaredProperties();
  public: IEnumerable<Type> get_ImplementedInterfaces();
  public: Type AsType();
  public: EventInfo GetDeclaredEvent(String name);
  public: FieldInfo GetDeclaredField(String name);
  public: MethodInfo GetDeclaredMethod(String name);
  public: TypeInfo GetDeclaredNestedType(String name);
  public: PropertyInfo GetDeclaredProperty(String name);
  public: IEnumerable<MethodInfo> GetDeclaredMethods(String name);
  public: Boolean IsAssignableFrom(TypeInfo typeInfo);
  public: static String GetRankString(Int32 rank);
};
} // namespace TypeInfoNamespace
using TypeInfo = TypeInfoNamespace::TypeInfo;
} // namespace System::Private::CoreLib::System::Reflection