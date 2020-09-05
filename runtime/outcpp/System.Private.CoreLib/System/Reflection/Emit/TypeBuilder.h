#pragma once

#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Object.h>
#include <System.Private.CoreLib/System/Reflection/Emit/TypeToken.h>
#include <System.Private.CoreLib/System/Reflection/TypeInfo.h>

namespace System::Private::CoreLib::System::Reflection {
enum class BindingFlags : int32_t;
enum class CallingConventions : int32_t;
enum class EventAttributes : int32_t;
enum class FieldAttributes : int32_t;
enum class GenericParameterAttributes : int32_t;
enum class MemberTypes : int32_t;
enum class MethodAttributes : int32_t;
enum class MethodImplAttributes : int32_t;
enum class MethodSemanticsAttributes : int32_t;
enum class ParameterAttributes : int32_t;
enum class PropertyAttributes : int32_t;
enum class TypeAttributes : int32_t;
FORWARD(Assembly)
FORWARD(Binder)
FORWARD(ConstructorInfo)
FORWARD(EventInfo)
FORWARD(FieldInfo)
FORWARDS(InterfaceMapping)
FORWARD(MemberInfo)
FORWARD(MethodBase)
FORWARD(MethodInfo)
FORWARD(Module)
FORWARDS(ParameterModifier)
FORWARD(PropertyInfo)
} // namespace System::Private::CoreLib::System::Reflection
namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Byte)
FORWARDS(Guid)
FORWARD(RuntimeType)
FORWARDS(RuntimeTypeHandle)
FORWARD(String)
FORWARD(Type)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::CompilerServices {
FORWARDS(ObjectHandleOnStack)
FORWARDS(QCallModule)
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
namespace System::Private::CoreLib::System::Globalization {
FORWARD(CultureInfo)
} // namespace System::Private::CoreLib::System::Globalization
namespace System::Private::CoreLib::System::Runtime::InteropServices {
enum class CallingConvention : int32_t;
enum class CharSet : int32_t;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(List, T)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System::Reflection::Emit {
enum class PackingSize : int32_t;
FORWARD(ConstructorBuilder)
FORWARD(CustomAttributeBuilder)
FORWARD(EventBuilder)
FORWARDS(ExceptionHandler)
FORWARD(FieldBuilder)
FORWARD(GenericTypeParameterBuilder)
FORWARD(MethodBuilder)
FORWARD(ModuleBuilder)
FORWARD(PropertyBuilder)
namespace TypeBuilderNamespace {
using namespace System::Collections::Generic;
using namespace System::Globalization;
using namespace System::Runtime::CompilerServices;
using namespace System::Runtime::InteropServices;
CLASS(TypeBuilder) : public TypeInfo::in {
  private: CLASS(CustAttr) : public object {
    public: void ctor(ConstructorInfo con, Array<Byte> binaryAttribute);
    public: void ctor(CustomAttributeBuilder customBuilder);
    public: void Bake(ModuleBuilder module, Int32 token);
    private: ConstructorInfo m_con;
    private: Array<Byte> m_binaryAttribute;
    private: CustomAttributeBuilder m_customBuilder;
  };
  public: Object get_SyncRoot();
  public: RuntimeType get_BakedRuntimeType();
  public: Type get_DeclaringType();
  public: Type get_ReflectedType();
  public: String get_Name();
  public: Module get_Module();
  public: Boolean get_IsByRefLike();
  public: Int32 get_MetadataTokenInternal();
  public: Guid get_GUID();
  public: Assembly get_Assembly();
  public: RuntimeTypeHandle get_TypeHandle();
  public: String get_FullName();
  public: String get_Namespace();
  public: String get_AssemblyQualifiedName();
  public: Type get_BaseType();
  public: Boolean get_IsTypeDefinition();
  public: Boolean get_IsSZArray();
  public: Boolean get_IsSecurityCritical();
  public: Boolean get_IsSecuritySafeCritical();
  public: Boolean get_IsSecurityTransparent();
  public: Type get_UnderlyingSystemType();
  public: GenericParameterAttributes get_GenericParameterAttributes();
  public: Boolean get_IsGenericTypeDefinition();
  public: Boolean get_IsGenericType();
  public: Boolean get_IsGenericParameter();
  public: Boolean get_IsConstructedGenericType();
  public: Int32 get_GenericParameterPosition();
  public: MethodBase get_DeclaringMethod();
  public: Int32 get_Size();
  public: PackingSize get_PackingSize();
  public: TypeToken get_TypeToken();
  public: Boolean IsAssignableFrom(TypeInfo typeInfo);
  public: static MethodInfo GetMethod(Type type, MethodInfo method);
  public: static ConstructorInfo GetConstructor(Type type, ConstructorInfo constructor);
  public: static FieldInfo GetField(Type type, FieldInfo field);
  private: static void SetParentType(QCallModule module, Int32 tdTypeDef, Int32 tkParent);
  private: static void AddInterfaceImpl(QCallModule module, Int32 tdTypeDef, Int32 tkInterface);
  public: static Int32 DefineMethod(QCallModule module, Int32 tkParent, String name, Array<Byte> signature, Int32 sigLength, MethodAttributes attributes);
  public: static Int32 DefineMethodSpec(QCallModule module, Int32 tkParent, Array<Byte> signature, Int32 sigLength);
  public: static Int32 DefineField(QCallModule module, Int32 tkParent, String name, Array<Byte> signature, Int32 sigLength, FieldAttributes attributes);
  private: static void SetMethodIL(QCallModule module, Int32 tk, Boolean isInitLocals, Array<Byte> body, Int32 bodyLength, Array<Byte> LocalSig, Int32 sigLength, Int32 maxStackSize, Array<ExceptionHandler> exceptions, Int32 numExceptions, Array<Int32> tokenFixups, Int32 numTokenFixups);
  private: static void DefineCustomAttribute(QCallModule module, Int32 tkAssociate, Int32 tkConstructor, Array<Byte> attr, Int32 attrLength, Boolean toDisk, Boolean updateCompilerFlags);
  public: static void DefineCustomAttribute(ModuleBuilder module, Int32 tkAssociate, Int32 tkConstructor, Array<Byte> attr, Boolean toDisk, Boolean updateCompilerFlags);
  public: static Int32 DefineProperty(QCallModule module, Int32 tkParent, String name, PropertyAttributes attributes, Array<Byte> signature, Int32 sigLength);
  public: static Int32 DefineEvent(QCallModule module, Int32 tkParent, String name, EventAttributes attributes, Int32 tkEventType);
  public: static void DefineMethodSemantics(QCallModule module, Int32 tkAssociation, MethodSemanticsAttributes semantics, Int32 tkMethod);
  public: static void DefineMethodImpl(QCallModule module, Int32 tkType, Int32 tkBody, Int32 tkDecl);
  public: static void SetMethodImpl(QCallModule module, Int32 tkMethod, MethodImplAttributes MethodImplAttributes);
  public: static Int32 SetParamInfo(QCallModule module, Int32 tkMethod, Int32 iSequence, ParameterAttributes iParamAttributes, String strParamName);
  public: static Int32 GetTokenFromSig(QCallModule module, Array<Byte> signature, Int32 sigLength);
  public: static void SetFieldLayoutOffset(QCallModule module, Int32 fdToken, Int32 iOffset);
  public: static void SetClassLayout(QCallModule module, Int32 tk, PackingSize iPackingSize, Int32 iTypeSize);
  private: static void SetConstantValue(QCallModule module, Int32 tk, Int32 corType, void* pValue);
  private: static void SetPInvokeData(QCallModule module, String DllName, String name, Int32 token, Int32 linkFlags);
  public: static Boolean IsTypeEqual(Type t1, Type t2);
  public: static void SetConstantValue(ModuleBuilder module, Int32 tk, Type destType, Object value);
  public: void ctor(ModuleBuilder module);
  public: void ctor(String szName, Int32 genParamPos, MethodBuilder declMeth);
  public: void ctor(String szName, Int32 genParamPos, TypeBuilder declType);
  public: void ctor(String fullname, TypeAttributes attr, Type parent, Array<Type> interfaces, ModuleBuilder module, PackingSize iPackingSize, Int32 iTypeSize, TypeBuilder enclosingType);
  private: FieldBuilder DefineDataHelper(String name, Array<Byte> data, Int32 size, FieldAttributes attributes);
  private: void VerifyTypeAttributes(TypeAttributes attr);
  public: Boolean IsCreated();
  private: static Int32 DefineType(QCallModule module, String fullname, Int32 tkParent, TypeAttributes attributes, Int32 tkEnclosingType, Array<Int32> interfaceTokens);
  private: static Int32 DefineGenericParam(QCallModule module, String name, Int32 tkParent, GenericParameterAttributes attributes, Int32 position, Array<Int32> constraints);
  private: static void TermCreateClass(QCallModule module, Int32 tk, ObjectHandleOnStack type);
  public: void ThrowIfCreated();
  public: ModuleBuilder GetModuleBuilder();
  public: void SetGenParamAttributes(GenericParameterAttributes genericParameterAttributes);
  public: void SetGenParamCustomAttribute(ConstructorInfo con, Array<Byte> binaryAttribute);
  public: void SetGenParamCustomAttribute(CustomAttributeBuilder customBuilder);
  private: void SetGenParamCustomAttributeNoLock(CustAttr ca);
  public: String ToString();
  public: Object InvokeMember(String name, BindingFlags invokeAttr, Binder binder, Object target, Array<Object> args, Array<ParameterModifier> modifiers, CultureInfo culture, Array<String> namedParameters);
  protected: ConstructorInfo GetConstructorImpl(BindingFlags bindingAttr, Binder binder, CallingConventions callConvention, Array<Type> types, Array<ParameterModifier> modifiers);
  public: Array<ConstructorInfo> GetConstructors(BindingFlags bindingAttr);
  protected: MethodInfo GetMethodImpl(String name, BindingFlags bindingAttr, Binder binder, CallingConventions callConvention, Array<Type> types, Array<ParameterModifier> modifiers);
  public: Array<MethodInfo> GetMethods(BindingFlags bindingAttr);
  public: FieldInfo GetField(String name, BindingFlags bindingAttr);
  public: Array<FieldInfo> GetFields(BindingFlags bindingAttr);
  public: Type GetInterface(String name, Boolean ignoreCase);
  public: Array<Type> GetInterfaces();
  public: EventInfo GetEvent(String name, BindingFlags bindingAttr);
  public: Array<EventInfo> GetEvents();
  protected: PropertyInfo GetPropertyImpl(String name, BindingFlags bindingAttr, Binder binder, Type returnType, Array<Type> types, Array<ParameterModifier> modifiers);
  public: Array<PropertyInfo> GetProperties(BindingFlags bindingAttr);
  public: Array<Type> GetNestedTypes(BindingFlags bindingAttr);
  public: Type GetNestedType(String name, BindingFlags bindingAttr);
  public: Array<MemberInfo> GetMember(String name, MemberTypes type, BindingFlags bindingAttr);
  public: InterfaceMapping GetInterfaceMap(Type interfaceType);
  public: Array<EventInfo> GetEvents(BindingFlags bindingAttr);
  public: Array<MemberInfo> GetMembers(BindingFlags bindingAttr);
  public: Boolean IsAssignableFrom(Type c);
  protected: TypeAttributes GetAttributeFlagsImpl();
  protected: Boolean IsArrayImpl();
  protected: Boolean IsByRefImpl();
  protected: Boolean IsPointerImpl();
  protected: Boolean IsPrimitiveImpl();
  protected: Boolean IsCOMObjectImpl();
  public: Type GetElementType();
  protected: Boolean HasElementTypeImpl();
  public: Boolean IsSubclassOf(Type c);
  public: Type MakePointerType();
  public: Type MakeByRefType();
  public: Type MakeArrayType();
  public: Type MakeArrayType(Int32 rank);
  public: Array<Object> GetCustomAttributes(Boolean inherit);
  public: Array<Object> GetCustomAttributes(Type attributeType, Boolean inherit);
  public: Boolean IsDefined(Type attributeType, Boolean inherit);
  public: void SetInterfaces(Array<Type> interfaces);
  public: Array<GenericTypeParameterBuilder> DefineGenericParameters(Array<String> names);
  public: Type MakeGenericType(Array<Type> typeArguments);
  public: Array<Type> GetGenericArguments();
  public: Type GetGenericTypeDefinition();
  public: void DefineMethodOverride(MethodInfo methodInfoBody, MethodInfo methodInfoDeclaration);
  private: void DefineMethodOverrideNoLock(MethodInfo methodInfoBody, MethodInfo methodInfoDeclaration);
  public: MethodBuilder DefineMethod(String name, MethodAttributes attributes, Type returnType, Array<Type> parameterTypes);
  public: MethodBuilder DefineMethod(String name, MethodAttributes attributes);
  public: MethodBuilder DefineMethod(String name, MethodAttributes attributes, CallingConventions callingConvention);
  public: MethodBuilder DefineMethod(String name, MethodAttributes attributes, CallingConventions callingConvention, Type returnType, Array<Type> parameterTypes);
  public: MethodBuilder DefineMethod(String name, MethodAttributes attributes, CallingConventions callingConvention, Type returnType, Array<Type> returnTypeRequiredCustomModifiers, Array<Type> returnTypeOptionalCustomModifiers, Array<Type> parameterTypes, Array<Array<Type>> parameterTypeRequiredCustomModifiers, Array<Array<Type>> parameterTypeOptionalCustomModifiers);
  private: MethodBuilder DefineMethodNoLock(String name, MethodAttributes attributes, CallingConventions callingConvention, Type returnType, Array<Type> returnTypeRequiredCustomModifiers, Array<Type> returnTypeOptionalCustomModifiers, Array<Type> parameterTypes, Array<Array<Type>> parameterTypeRequiredCustomModifiers, Array<Array<Type>> parameterTypeOptionalCustomModifiers);
  public: MethodBuilder DefinePInvokeMethod(String name, String dllName, MethodAttributes attributes, CallingConventions callingConvention, Type returnType, Array<Type> parameterTypes, CallingConvention nativeCallConv, CharSet nativeCharSet);
  public: MethodBuilder DefinePInvokeMethod(String name, String dllName, String entryName, MethodAttributes attributes, CallingConventions callingConvention, Type returnType, Array<Type> parameterTypes, CallingConvention nativeCallConv, CharSet nativeCharSet);
  public: MethodBuilder DefinePInvokeMethod(String name, String dllName, String entryName, MethodAttributes attributes, CallingConventions callingConvention, Type returnType, Array<Type> returnTypeRequiredCustomModifiers, Array<Type> returnTypeOptionalCustomModifiers, Array<Type> parameterTypes, Array<Array<Type>> parameterTypeRequiredCustomModifiers, Array<Array<Type>> parameterTypeOptionalCustomModifiers, CallingConvention nativeCallConv, CharSet nativeCharSet);
  private: MethodBuilder DefinePInvokeMethodHelper(String name, String dllName, String importName, MethodAttributes attributes, CallingConventions callingConvention, Type returnType, Array<Type> returnTypeRequiredCustomModifiers, Array<Type> returnTypeOptionalCustomModifiers, Array<Type> parameterTypes, Array<Array<Type>> parameterTypeRequiredCustomModifiers, Array<Array<Type>> parameterTypeOptionalCustomModifiers, CallingConvention nativeCallConv, CharSet nativeCharSet);
  public: ConstructorBuilder DefineTypeInitializer();
  private: ConstructorBuilder DefineTypeInitializerNoLock();
  public: ConstructorBuilder DefineDefaultConstructor(MethodAttributes attributes);
  private: ConstructorBuilder DefineDefaultConstructorNoLock(MethodAttributes attributes);
  public: ConstructorBuilder DefineConstructor(MethodAttributes attributes, CallingConventions callingConvention, Array<Type> parameterTypes);
  public: ConstructorBuilder DefineConstructor(MethodAttributes attributes, CallingConventions callingConvention, Array<Type> parameterTypes, Array<Array<Type>> requiredCustomModifiers, Array<Array<Type>> optionalCustomModifiers);
  private: ConstructorBuilder DefineConstructorNoLock(MethodAttributes attributes, CallingConventions callingConvention, Array<Type> parameterTypes, Array<Array<Type>> requiredCustomModifiers, Array<Array<Type>> optionalCustomModifiers);
  public: TypeBuilder DefineNestedType(String name);
  public: TypeBuilder DefineNestedType(String name, TypeAttributes attr, Type parent, Array<Type> interfaces);
  public: TypeBuilder DefineNestedType(String name, TypeAttributes attr, Type parent);
  public: TypeBuilder DefineNestedType(String name, TypeAttributes attr);
  public: TypeBuilder DefineNestedType(String name, TypeAttributes attr, Type parent, Int32 typeSize);
  public: TypeBuilder DefineNestedType(String name, TypeAttributes attr, Type parent, PackingSize packSize);
  public: TypeBuilder DefineNestedType(String name, TypeAttributes attr, Type parent, PackingSize packSize, Int32 typeSize);
  private: TypeBuilder DefineNestedTypeNoLock(String name, TypeAttributes attr, Type parent, Array<Type> interfaces, PackingSize packSize, Int32 typeSize);
  public: FieldBuilder DefineField(String fieldName, Type type, FieldAttributes attributes);
  public: FieldBuilder DefineField(String fieldName, Type type, Array<Type> requiredCustomModifiers, Array<Type> optionalCustomModifiers, FieldAttributes attributes);
  private: FieldBuilder DefineFieldNoLock(String fieldName, Type type, Array<Type> requiredCustomModifiers, Array<Type> optionalCustomModifiers, FieldAttributes attributes);
  public: FieldBuilder DefineInitializedData(String name, Array<Byte> data, FieldAttributes attributes);
  private: FieldBuilder DefineInitializedDataNoLock(String name, Array<Byte> data, FieldAttributes attributes);
  public: FieldBuilder DefineUninitializedData(String name, Int32 size, FieldAttributes attributes);
  private: FieldBuilder DefineUninitializedDataNoLock(String name, Int32 size, FieldAttributes attributes);
  public: PropertyBuilder DefineProperty(String name, PropertyAttributes attributes, Type returnType, Array<Type> parameterTypes);
  public: PropertyBuilder DefineProperty(String name, PropertyAttributes attributes, CallingConventions callingConvention, Type returnType, Array<Type> parameterTypes);
  public: PropertyBuilder DefineProperty(String name, PropertyAttributes attributes, Type returnType, Array<Type> returnTypeRequiredCustomModifiers, Array<Type> returnTypeOptionalCustomModifiers, Array<Type> parameterTypes, Array<Array<Type>> parameterTypeRequiredCustomModifiers, Array<Array<Type>> parameterTypeOptionalCustomModifiers);
  public: PropertyBuilder DefineProperty(String name, PropertyAttributes attributes, CallingConventions callingConvention, Type returnType, Array<Type> returnTypeRequiredCustomModifiers, Array<Type> returnTypeOptionalCustomModifiers, Array<Type> parameterTypes, Array<Array<Type>> parameterTypeRequiredCustomModifiers, Array<Array<Type>> parameterTypeOptionalCustomModifiers);
  private: PropertyBuilder DefinePropertyNoLock(String name, PropertyAttributes attributes, CallingConventions callingConvention, Type returnType, Array<Type> returnTypeRequiredCustomModifiers, Array<Type> returnTypeOptionalCustomModifiers, Array<Type> parameterTypes, Array<Array<Type>> parameterTypeRequiredCustomModifiers, Array<Array<Type>> parameterTypeOptionalCustomModifiers);
  public: EventBuilder DefineEvent(String name, EventAttributes attributes, Type eventtype);
  private: EventBuilder DefineEventNoLock(String name, EventAttributes attributes, Type eventtype);
  public: TypeInfo CreateTypeInfo();
  public: Type CreateType();
  public: void CheckContext(Array<Array<Type>> typess);
  public: void CheckContext(Array<Type> types);
  private: TypeInfo CreateTypeNoLock();
  public: void SetParent(Type parent);
  public: void AddInterfaceImplementation(Type interfaceType);
  public: void SetCustomAttribute(ConstructorInfo con, Array<Byte> binaryAttribute);
  public: void SetCustomAttribute(CustomAttributeBuilder customBuilder);
  public: static constexpr Int32 UnspecifiedTypeSize = 0;
  private: List<CustAttr> m_ca;
  private: TypeToken m_tdType;
  private: ModuleBuilder m_module;
  private: String m_strName;
  private: String m_strNameSpace;
  private: String m_strFullQualName;
  private: Type m_typeParent;
  private: List<Type> m_typeInterfaces;
  private: TypeAttributes m_iAttr;
  private: GenericParameterAttributes m_genParamAttributes;
  public: List<MethodBuilder> m_listMethods;
  public: Int32 m_lastTokenizedMethod;
  private: Int32 m_constructorCount;
  private: Int32 m_iTypeSize;
  private: PackingSize m_iPackingSize;
  private: TypeBuilder m_DeclaringType;
  private: Type m_enumUnderlyingType;
  public: Boolean m_isHiddenGlobalType;
  private: Boolean m_hasBeenCreated;
  private: RuntimeType m_bakedRuntimeType;
  private: Int32 m_genParamPos;
  private: Array<GenericTypeParameterBuilder> m_inst;
  private: Boolean m_bIsGenParam;
  private: MethodBuilder m_declMeth;
  private: TypeBuilder m_genTypeDef;
};
} // namespace TypeBuilderNamespace
using TypeBuilder = TypeBuilderNamespace::TypeBuilder;
} // namespace System::Private::CoreLib::System::Reflection::Emit
