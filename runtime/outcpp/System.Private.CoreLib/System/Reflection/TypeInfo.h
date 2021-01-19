#pragma once

#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Object.h>
#include <System.Private.CoreLib/System/Type.h>

namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(IEnumerable, T)
FORWARD(IEnumerator, T)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System::Collections {
FORWARD(IEnumerable)
FORWARD(IEnumerator)
} // namespace System::Private::CoreLib::System::Collections
namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
FORWARD(IDisposable)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection {
FORWARD(ConstructorInfo)
FORWARD(EventInfo)
FORWARD(FieldInfo)
FORWARD(IReflectableType)
FORWARD(MemberInfo)
FORWARD(MethodInfo)
FORWARD(PropertyInfo)
namespace TypeInfoNamespace {
using namespace System::Collections;
using namespace System::Collections::Generic;
template <class T>
using IEnumerable = Collections::Generic::IEnumerable<T>;
using IEnumerable_ = Collections::IEnumerable;
template <class T>
using IEnumerator = Collections::Generic::IEnumerator<T>;
using IEnumerator_ = Collections::IEnumerator;
CLASS(TypeInfo) : public Type::in {
  public: using interface = rt::TypeList<IReflectableType>;
  private: CLASS(_GetDeclaredMethods_d__10) : public object {
    public: using interface = rt::TypeList<IEnumerable<MethodInfo>, IEnumerable_, IEnumerator<MethodInfo>, IDisposable, IEnumerator_>;
    private: MethodInfo get_CurrentOfMethodInfo();
    private: Object get_CurrentOfIEnumerator();
    public: void ctor(Int32 __1__state);
    private: void DisposeOfIDisposable();
    private: Boolean MoveNext();
    private: void ResetOfIEnumerator();
    private: IEnumerator<MethodInfo> GetEnumeratorOfMethodInfo();
    private: IEnumerator_ GetEnumeratorOfIEnumerable();
    private: Int32 __1__state;
    private: MethodInfo __2__current;
    private: Int32 __l__initialThreadId;
    public: TypeInfo __4__this;
    private: String name;
    public: String __3__name;
    private: Array<MethodInfo> __7__wrap1;
    private: Int32 __7__wrap2;
  };
  private: CLASS(_get_DeclaredNestedTypes_d__22) : public object {
    public: using interface = rt::TypeList<IEnumerable<TypeInfo>, IEnumerable_, IEnumerator<TypeInfo>, IDisposable, IEnumerator_>;
    private: TypeInfo get_CurrentOfTypeInfo();
    private: Object get_CurrentOfIEnumerator();
    public: void ctor(Int32 __1__state);
    private: void DisposeOfIDisposable();
    private: Boolean MoveNext();
    private: void ResetOfIEnumerator();
    private: IEnumerator<TypeInfo> GetEnumeratorOfTypeInfo();
    private: IEnumerator_ GetEnumeratorOfIEnumerable();
    private: Int32 __1__state;
    private: TypeInfo __2__current;
    private: Int32 __l__initialThreadId;
    public: TypeInfo __4__this;
    private: Array<Type> __7__wrap1;
    private: Int32 __7__wrap2;
  };
  public: Array<Type> get_GenericTypeParameters();
  public: IEnumerable<ConstructorInfo> get_DeclaredConstructors();
  public: IEnumerable<EventInfo> get_DeclaredEvents();
  public: IEnumerable<FieldInfo> get_DeclaredFields();
  public: IEnumerable<MemberInfo> get_DeclaredMembers();
  public: IEnumerable<MethodInfo> get_DeclaredMethods();
  public: IEnumerable<TypeInfo> get_DeclaredNestedTypes();
  public: IEnumerable<PropertyInfo> get_DeclaredProperties();
  public: IEnumerable<Type> get_ImplementedInterfaces();
  public: void ctor();
  private: TypeInfo GetTypeInfoOfIReflectableType();
  public: Type AsType();
  public: EventInfo GetDeclaredEvent(String name);
  public: FieldInfo GetDeclaredField(String name);
  public: MethodInfo GetDeclaredMethod(String name);
  public: TypeInfo GetDeclaredNestedType(String name);
  public: PropertyInfo GetDeclaredProperty(String name);
  public: IEnumerable<MethodInfo> GetDeclaredMethods(String name);
  public: Boolean IsAssignableFrom(TypeInfo typeInfo);
  public: static String GetRankString(Int32 rank);
  public: static Array<MethodInfo> _GetDeclaredMethods_g__GetDeclaredOnlyMethods10_0(Type type);
  public: static Array<Type> _get_DeclaredNestedTypes_g__GetDeclaredOnlyNestedTypes22_0(Type type);
};
} // namespace TypeInfoNamespace
using TypeInfo = TypeInfoNamespace::TypeInfo;
} // namespace System::Private::CoreLib::System::Reflection
