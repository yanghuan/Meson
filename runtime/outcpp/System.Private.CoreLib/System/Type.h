#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Reflection/MemberInfo.h>

namespace System::Private::CoreLib::System::Reflection {
enum class BindingFlags;
enum class CallingConventions;
enum class GenericParameterAttributes;
enum class MemberTypes;
enum class TypeAttributes;
FORWARD(Assembly)
FORWARD(AssemblyName)
FORWARD(Binder)
FORWARD(ConstructorInfo)
FORWARD(EventInfo)
FORWARD(FieldInfo)
FORWARDS(InterfaceMapping)
FORWARD(MemberFilter)
FORWARD(MethodBase)
FORWARD(MethodInfo)
FORWARD(Module)
FORWARDS(ParameterModifier)
FORWARD(PropertyInfo)
FORWARD(TypeFilter)
} // namespace System::Private::CoreLib::System::Reflection
namespace System::Private::CoreLib::System::Runtime::InteropServices {
FORWARD(StructLayoutAttribute)
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
namespace System::Private::CoreLib::System::Globalization {
FORWARD(CultureInfo)
} // namespace System::Private::CoreLib::System::Globalization
namespace System::Private::CoreLib::System {
enum class StringComparison;
enum class TypeCode;
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
FORWARDS(Char)
FORWARD_(Func, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18)
FORWARDS(Guid)
FORWARDS(Int32)
FORWARDS(IntPtr)
FORWARD(Object)
FORWARD(RuntimeType)
FORWARDS(RuntimeTypeHandle)
FORWARD(String)
namespace TypeNamespace {
using namespace Globalization;
using namespace Reflection;
using namespace Runtime::InteropServices;
CLASS(Type) : public MemberInfo::in {
  public: Boolean get_IsInterface();
  public: MemberTypes get_MemberType();
  public: String get_Namespace();
  public: String get_AssemblyQualifiedName();
  public: String get_FullName();
  public: Assembly get_Assembly();
  public: Module get_Module();
  public: Boolean get_IsNested();
  public: Type get_DeclaringType();
  public: MethodBase get_DeclaringMethod();
  public: Type get_ReflectedType();
  public: Type get_UnderlyingSystemType();
  public: Boolean get_IsTypeDefinition();
  public: Boolean get_IsArray();
  public: Boolean get_IsByRef();
  public: Boolean get_IsPointer();
  public: Boolean get_IsConstructedGenericType();
  public: Boolean get_IsGenericParameter();
  public: Boolean get_IsGenericTypeParameter();
  public: Boolean get_IsGenericMethodParameter();
  public: Boolean get_IsGenericType();
  public: Boolean get_IsGenericTypeDefinition();
  public: Boolean get_IsSZArray();
  public: Boolean get_IsVariableBoundArray();
  public: Boolean get_IsByRefLike();
  public: Boolean get_HasElementType();
  public: Array<Type> get_GenericTypeArguments();
  public: Int32 get_GenericParameterPosition();
  public: GenericParameterAttributes get_GenericParameterAttributes();
  public: TypeAttributes get_Attributes();
  public: Boolean get_IsAbstract();
  public: Boolean get_IsImport();
  public: Boolean get_IsSealed();
  public: Boolean get_IsSpecialName();
  public: Boolean get_IsClass();
  public: Boolean get_IsNestedAssembly();
  public: Boolean get_IsNestedFamANDAssem();
  public: Boolean get_IsNestedFamily();
  public: Boolean get_IsNestedFamORAssem();
  public: Boolean get_IsNestedPrivate();
  public: Boolean get_IsNestedPublic();
  public: Boolean get_IsNotPublic();
  public: Boolean get_IsPublic();
  public: Boolean get_IsAutoLayout();
  public: Boolean get_IsExplicitLayout();
  public: Boolean get_IsLayoutSequential();
  public: Boolean get_IsAnsiClass();
  public: Boolean get_IsAutoClass();
  public: Boolean get_IsUnicodeClass();
  public: Boolean get_IsCOMObject();
  public: Boolean get_IsContextful();
  public: Boolean get_IsEnum();
  public: Boolean get_IsMarshalByRef();
  public: Boolean get_IsPrimitive();
  public: Boolean get_IsValueType();
  public: Boolean get_IsSignatureType();
  public: Boolean get_IsSecurityCritical();
  public: Boolean get_IsSecuritySafeCritical();
  public: Boolean get_IsSecurityTransparent();
  public: StructLayoutAttribute get_StructLayoutAttribute();
  public: ConstructorInfo get_TypeInitializer();
  public: RuntimeTypeHandle get_TypeHandle();
  public: Guid get_GUID();
  public: Type get_BaseType();
  public: static Binder get_DefaultBinder();
  public: Boolean get_IsSerializable();
  public: Boolean get_ContainsGenericParameters();
  public: Boolean get_IsVisible();
  public: static Type GetType(String typeName, Boolean throwOnError, Boolean ignoreCase);
  public: static Type GetType(String typeName, Boolean throwOnError);
  public: static Type GetType(String typeName);
  public: static Type GetType(String typeName, Func<AssemblyName, Assembly> assemblyResolver, Func<Assembly, String, Boolean, Type> typeResolver);
  public: static Type GetType(String typeName, Func<AssemblyName, Assembly> assemblyResolver, Func<Assembly, String, Boolean, Type> typeResolver, Boolean throwOnError);
  public: static Type GetType(String typeName, Func<AssemblyName, Assembly> assemblyResolver, Func<Assembly, String, Boolean, Type> typeResolver, Boolean throwOnError, Boolean ignoreCase);
  public: static Type GetTypeFromProgID(String progID, String server, Boolean throwOnError);
  public: static Type GetTypeFromCLSID(Guid clsid, String server, Boolean throwOnError);
  public: RuntimeTypeHandle GetTypeHandleInternal();
  public: static RuntimeType GetTypeFromHandleUnsafe(IntPtr handle);
  public: static Type GetTypeFromHandle(RuntimeTypeHandle handle);
  public: static Boolean op_Equality(Type left, Type right);
  public: static Boolean op_Inequality(Type left, Type right);
  public: Boolean IsRuntimeImplemented();
  protected: void Ctor();
  public: Type GetType();
  protected: Boolean IsArrayImpl();
  protected: Boolean IsByRefImpl();
  protected: Boolean IsPointerImpl();
  protected: Boolean HasElementTypeImpl();
  public: Type GetElementType();
  public: Int32 GetArrayRank();
  public: Type GetGenericTypeDefinition();
  public: Array<Type> GetGenericArguments();
  public: Array<Type> GetGenericParameterConstraints();
  protected: TypeAttributes GetAttributeFlagsImpl();
  protected: Boolean IsCOMObjectImpl();
  protected: Boolean IsContextfulImpl();
  protected: Boolean IsMarshalByRefImpl();
  protected: Boolean IsPrimitiveImpl();
  protected: Boolean IsValueTypeImpl();
  public: ConstructorInfo GetConstructor(Array<Type> types);
  public: ConstructorInfo GetConstructor(BindingFlags bindingAttr, Binder binder, Array<Type> types, Array<ParameterModifier> modifiers);
  public: ConstructorInfo GetConstructor(BindingFlags bindingAttr, Binder binder, CallingConventions callConvention, Array<Type> types, Array<ParameterModifier> modifiers);
  protected: ConstructorInfo GetConstructorImpl(BindingFlags bindingAttr, Binder binder, CallingConventions callConvention, Array<Type> types, Array<ParameterModifier> modifiers);
  public: Array<ConstructorInfo> GetConstructors();
  public: Array<ConstructorInfo> GetConstructors(BindingFlags bindingAttr);
  public: EventInfo GetEvent(String name);
  public: EventInfo GetEvent(String name, BindingFlags bindingAttr);
  public: Array<EventInfo> GetEvents();
  public: Array<EventInfo> GetEvents(BindingFlags bindingAttr);
  public: FieldInfo GetField(String name);
  public: FieldInfo GetField(String name, BindingFlags bindingAttr);
  public: Array<FieldInfo> GetFields();
  public: Array<FieldInfo> GetFields(BindingFlags bindingAttr);
  public: Array<MemberInfo> GetMember(String name);
  public: Array<MemberInfo> GetMember(String name, BindingFlags bindingAttr);
  public: Array<MemberInfo> GetMember(String name, MemberTypes type, BindingFlags bindingAttr);
  public: Array<MemberInfo> GetMembers();
  public: Array<MemberInfo> GetMembers(BindingFlags bindingAttr);
  public: MethodInfo GetMethod(String name);
  public: MethodInfo GetMethod(String name, BindingFlags bindingAttr);
  public: MethodInfo GetMethod(String name, Array<Type> types);
  public: MethodInfo GetMethod(String name, Array<Type> types, Array<ParameterModifier> modifiers);
  public: MethodInfo GetMethod(String name, BindingFlags bindingAttr, Binder binder, Array<Type> types, Array<ParameterModifier> modifiers);
  public: MethodInfo GetMethod(String name, BindingFlags bindingAttr, Binder binder, CallingConventions callConvention, Array<Type> types, Array<ParameterModifier> modifiers);
  protected: MethodInfo GetMethodImpl(String name, BindingFlags bindingAttr, Binder binder, CallingConventions callConvention, Array<Type> types, Array<ParameterModifier> modifiers);
  public: MethodInfo GetMethod(String name, Int32 genericParameterCount, Array<Type> types);
  public: MethodInfo GetMethod(String name, Int32 genericParameterCount, Array<Type> types, Array<ParameterModifier> modifiers);
  public: MethodInfo GetMethod(String name, Int32 genericParameterCount, BindingFlags bindingAttr, Binder binder, Array<Type> types, Array<ParameterModifier> modifiers);
  public: MethodInfo GetMethod(String name, Int32 genericParameterCount, BindingFlags bindingAttr, Binder binder, CallingConventions callConvention, Array<Type> types, Array<ParameterModifier> modifiers);
  protected: MethodInfo GetMethodImpl(String name, Int32 genericParameterCount, BindingFlags bindingAttr, Binder binder, CallingConventions callConvention, Array<Type> types, Array<ParameterModifier> modifiers);
  public: Array<MethodInfo> GetMethods();
  public: Array<MethodInfo> GetMethods(BindingFlags bindingAttr);
  public: Type GetNestedType(String name);
  public: Type GetNestedType(String name, BindingFlags bindingAttr);
  public: Array<Type> GetNestedTypes();
  public: Array<Type> GetNestedTypes(BindingFlags bindingAttr);
  public: PropertyInfo GetProperty(String name);
  public: PropertyInfo GetProperty(String name, BindingFlags bindingAttr);
  public: PropertyInfo GetProperty(String name, Type returnType);
  public: PropertyInfo GetProperty(String name, Array<Type> types);
  public: PropertyInfo GetProperty(String name, Type returnType, Array<Type> types);
  public: PropertyInfo GetProperty(String name, Type returnType, Array<Type> types, Array<ParameterModifier> modifiers);
  public: PropertyInfo GetProperty(String name, BindingFlags bindingAttr, Binder binder, Type returnType, Array<Type> types, Array<ParameterModifier> modifiers);
  protected: PropertyInfo GetPropertyImpl(String name, BindingFlags bindingAttr, Binder binder, Type returnType, Array<Type> types, Array<ParameterModifier> modifiers);
  public: Array<PropertyInfo> GetProperties();
  public: Array<PropertyInfo> GetProperties(BindingFlags bindingAttr);
  public: Array<MemberInfo> GetDefaultMembers();
  public: static RuntimeTypeHandle GetTypeHandle(Object o);
  public: static Array<Type> GetTypeArray(Array<Object> args);
  public: static TypeCode GetTypeCode(Type type);
  protected: TypeCode GetTypeCodeImpl();
  public: static Type GetTypeFromCLSID(Guid clsid);
  public: static Type GetTypeFromCLSID(Guid clsid, Boolean throwOnError);
  public: static Type GetTypeFromCLSID(Guid clsid, String server);
  public: static Type GetTypeFromProgID(String progID);
  public: static Type GetTypeFromProgID(String progID, Boolean throwOnError);
  public: static Type GetTypeFromProgID(String progID, String server);
  public: Object InvokeMember(String name, BindingFlags invokeAttr, Binder binder, Object target, Array<Object> args);
  public: Object InvokeMember(String name, BindingFlags invokeAttr, Binder binder, Object target, Array<Object> args, CultureInfo culture);
  public: Object InvokeMember(String name, BindingFlags invokeAttr, Binder binder, Object target, Array<Object> args, Array<ParameterModifier> modifiers, CultureInfo culture, Array<String> namedParameters);
  public: Type GetInterface(String name);
  public: Type GetInterface(String name, Boolean ignoreCase);
  public: Array<Type> GetInterfaces();
  public: InterfaceMapping GetInterfaceMap(Type interfaceType);
  public: Boolean IsInstanceOfType(Object o);
  public: Boolean IsEquivalentTo(Type other);
  public: Type GetEnumUnderlyingType();
  public: Array<> GetEnumValues();
  public: Type MakeArrayType();
  public: Type MakeArrayType(Int32 rank);
  public: Type MakeByRefType();
  public: Type MakeGenericType(Array<Type> typeArguments);
  public: Type MakePointerType();
  public: static Type MakeGenericSignatureType(Type genericTypeDefinition, Array<Type> typeArguments);
  public: static Type MakeGenericMethodParameter(Int32 position);
  public: String FormatTypeName();
  public: String ToString();
  public: Boolean Equals(Object o);
  public: Int32 GetHashCode();
  public: Boolean Equals(Type o);
  public: static Type ReflectionOnlyGetType(String typeName, Boolean throwIfNotFound, Boolean ignoreCase);
  public: Boolean IsEnumDefined(Object value);
  public: String GetEnumName(Object value);
  public: Array<String> GetEnumNames();
  private: Array<> GetEnumRawConstantValues();
  private: void GetEnumData(Array<String>& enumNames, Array<>& enumValues);
  private: static Int32 BinarySearch(Array<> array, Object value);
  public: static Boolean IsIntegerType(Type t);
  public: Type GetRootElementType();
  public: Array<Type> FindInterfaces(TypeFilter filter, Object filterCriteria);
  public: Array<MemberInfo> FindMembers(MemberTypes memberType, BindingFlags bindingAttr, MemberFilter filter, Object filterCriteria);
  public: Boolean IsSubclassOf(Type c);
  public: Boolean IsAssignableFrom(Type c);
  public: Boolean ImplementInterface(Type ifaceType);
  private: static Boolean FilterAttributeImpl(MemberInfo m, Object filterCriteria);
  private: static Boolean FilterNameImpl(MemberInfo m, Object filterCriteria, StringComparison comparison);
  private: static void SCtor();
  private: static Binder s_defaultBinder;
  public: static Char Delimiter;
  public: static Array<Type> EmptyTypes;
  public: static Object Missing;
  public: static MemberFilter FilterAttribute;
  public: static MemberFilter FilterName;
  public: static MemberFilter FilterNameIgnoreCase;
};
} // namespace TypeNamespace
using Type = TypeNamespace::Type;
} // namespace System::Private::CoreLib::System
