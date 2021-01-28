#pragma once

#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/IntPtr.h>
#include <System.Private.CoreLib/System/MdUtf8String.h>
#include <System.Private.CoreLib/System/Object.h>
#include <System.Private.CoreLib/System/Reflection/CerHashtable.h>
#include <System.Private.CoreLib/System/Reflection/TypeInfo.h>
#include <System.Private.CoreLib/System/RuntimeMethodHandleInternal.h>
#include <System.Private.CoreLib/System/UInt32.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System::Reflection {
enum class BindingFlags : int32_t;
enum class CallingConventions : int32_t;
enum class GenericParameterAttributes : int32_t;
enum class MemberTypes : int32_t;
enum class MethodAttributes : int32_t;
enum class TypeAttributes : int32_t;
FORWARD(Assembly)
FORWARD(Binder)
FORWARD(ConstructorInfo)
FORWARD(CustomAttributeData)
FORWARD(EventInfo)
FORWARD(FieldInfo)
FORWARDS(InterfaceMapping)
FORWARD(MemberInfo)
FORWARD(MethodBase)
FORWARD(MethodInfo)
FORWARD(Module)
FORWARDS(ParameterModifier)
FORWARD(PropertyInfo)
FORWARD(RuntimeConstructorInfo)
FORWARD(RuntimeEventInfo)
FORWARD(RuntimeFieldInfo)
FORWARD(RuntimeMethodInfo)
FORWARD(RuntimeModule)
FORWARD(RuntimePropertyInfo)
} // namespace System::Private::CoreLib::System::Reflection
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(Dictionary, TKey, TValue)
FORWARD(IList, T)
FORWARD(List, T)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System::Runtime::InteropServices {
FORWARD(StructLayoutAttribute)
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
namespace System::Private::CoreLib::System::Threading {
enum class StackCrawlMark : int32_t;
} // namespace System::Private::CoreLib::System::Threading
namespace System::Private::CoreLib::System::Globalization {
FORWARD(CultureInfo)
} // namespace System::Private::CoreLib::System::Globalization
namespace System::Private::CoreLib::System {
enum class TypeCode : int32_t;
enum class TypeNameFormatFlags : int32_t;
enum class TypeNameKind : int32_t;
FORWARD_(Array)
FORWARDS(Byte)
FORWARDS(Char)
FORWARD(CtorDelegate)
FORWARD(Exception)
FORWARDS(Guid)
FORWARD(ICloneable)
FORWARDS(Int64)
FORWARD(IRuntimeFieldInfo)
FORWARD(IRuntimeMethodInfo)
FORWARD(OleAutBinder)
FORWARDS(RuntimeFieldHandleInternal)
FORWARDS(RuntimeTypeHandle)
FORWARD(String)
FORWARD(Type)
namespace RuntimeTypeNamespace {
using namespace System::Collections::Generic;
using namespace System::Globalization;
using namespace System::Reflection;
using namespace System::Runtime::InteropServices;
using namespace System::Threading;
CLASS(RuntimeType) : public TypeInfo::in {
  public: using interface = rt::TypeList<ICloneable>;
  public: enum class MemberListType : int32_t {
    All = 0,
    CaseSensitive = 1,
    CaseInsensitive = 2,
    HandleToInfo = 3,
  };
  private: enum class DispatchWrapperType : int32_t {
    Unknown = 1,
    Dispatch = 2,
    Error = 8,
    Currency = 16,
    BStr = 32,
    SafeArray = 65536,
  };
  public: template <class T>
  struct ListBuilder : public valueType<ListBuilder<T>> {
    public: T get_Item(Int32 index);
    public: Int32 get_Count();
    public: explicit ListBuilder(Int32 capacity);
    public: Array<T> ToArray();
    public: void CopyTo(Array<Object> array, Int32 index);
    public: void Add(T item);
    public: explicit ListBuilder() {}
    private: Array<T> _items;
    private: T _item;
    private: Int32 _count;
    private: Int32 _capacity;
  };
  public: CLASS(RuntimeTypeCache) : public object {
    public: enum class CacheType : int32_t {
      Method = 0,
      Constructor = 1,
      Field = 2,
      Property = 3,
      Event = 4,
      Interface = 5,
      NestedType = 6,
    };
    private: struct Filter : public valueType<Filter> {
      public: explicit Filter(Byte* pUtf8Name, Int32 cUtf8Name, MemberListType listType);
      public: Boolean Match(MdUtf8String name);
      public: Boolean RequiresStringComparison();
      public: Boolean CaseSensitive();
      public: UInt32 GetHashToMatch();
      public: explicit Filter() {}
      private: MdUtf8String m_name;
      private: MemberListType m_listType;
      private: UInt32 m_nameHash;
    };
    private: CLASS(MemberInfoCache, T) : public object {
      public: RuntimeType get_ReflectedType();
      public: void ctor(RuntimeTypeCache runtimeTypeCache);
      public: MethodBase AddMethod(RuntimeType declaringType, RuntimeMethodHandleInternal method, CacheType cacheType);
      public: FieldInfo AddField(RuntimeFieldHandleInternal field);
      private: Array<T> Populate(String name, MemberListType listType, CacheType cacheType);
      private: Array<T> GetListByName(Char* pName, Int32 cNameLen, Byte* pUtf8Name, Int32 cUtf8Name, MemberListType listType, CacheType cacheType);
      public: void Insert(Array<T>& list, String name, MemberListType listType);
      private: void MergeWithGlobalList(Array<T> list);
      private: Array<RuntimeMethodInfo> PopulateMethods(Filter filter);
      private: Array<RuntimeConstructorInfo> PopulateConstructors(Filter filter);
      private: Array<RuntimeFieldInfo> PopulateFields(Filter filter);
      private: void PopulateRtFields(Filter filter, RuntimeType declaringType, ListBuilder<RuntimeFieldInfo>& list);
      private: void PopulateRtFields(Filter filter, IntPtr* ppFieldHandles, Int32 count, RuntimeType declaringType, ListBuilder<RuntimeFieldInfo>& list);
      private: void PopulateLiteralFields(Filter filter, RuntimeType declaringType, ListBuilder<RuntimeFieldInfo>& list);
      private: void AddSpecialInterface(ListBuilder<RuntimeType>& list, Filter filter, RuntimeType iList, Boolean addSubInterface);
      private: Array<RuntimeType> PopulateInterfaces(Filter filter);
      private: Array<RuntimeType> PopulateNestedClasses(Filter filter);
      private: Array<RuntimeEventInfo> PopulateEvents(Filter filter);
      private: void PopulateEvents(Filter filter, RuntimeType declaringType, Dictionary<String, RuntimeEventInfo> csEventInfos, ListBuilder<RuntimeEventInfo>& list);
      private: Array<RuntimePropertyInfo> PopulateProperties(Filter filter);
      private: void PopulateProperties(Filter filter, RuntimeType declaringType, Dictionary<String, List<RuntimePropertyInfo>> csPropertyInfos, Array<Boolean> usedSlots, ListBuilder<RuntimePropertyInfo>& list);
      public: Array<T> GetMemberList(MemberListType listType, String name, CacheType cacheType);
      private: CerHashtable<String, Array<T>> m_csMemberInfos;
      private: CerHashtable<String, Array<T>> m_cisMemberInfos;
      private: Array<T> m_allMembers;
      private: Boolean m_cacheComplete;
      private: RuntimeTypeCache m_runtimeTypeCache;
    };
    public: Object get_GenericCache();
    public: void set_GenericCache(Object value);
    public: Boolean get_DomainInitialized();
    public: void set_DomainInitialized(Boolean value);
    public: TypeCode get_TypeCode();
    public: void set_TypeCode(TypeCode value);
    public: Boolean get_IsGlobal();
    public: void ctor(RuntimeType runtimeType);
    private: String ConstructName(String& name, TypeNameFormatFlags formatFlags);
    private: template <class T>
    Array<T> GetMemberList(MemberInfoCache<T>& m_cache, MemberListType listType, String name, CacheType cacheType);
    private: template <class T>
    MemberInfoCache<T> GetMemberCache(MemberInfoCache<T>& m_cache);
    public: String GetName(TypeNameKind kind);
    public: String GetNameSpace();
    public: RuntimeType GetEnclosingType();
    public: RuntimeType GetRuntimeType();
    public: void InvalidateCachedNestedType();
    public: String GetDefaultMemberName();
    public: Array<Object> GetEmptyArray();
    public: MethodInfo GetGenericMethodInfo(RuntimeMethodHandleInternal genericMethod);
    public: Array<RuntimeMethodInfo> GetMethodList(MemberListType listType, String name);
    public: Array<RuntimeConstructorInfo> GetConstructorList(MemberListType listType, String name);
    public: Array<RuntimePropertyInfo> GetPropertyList(MemberListType listType, String name);
    public: Array<RuntimeEventInfo> GetEventList(MemberListType listType, String name);
    public: Array<RuntimeFieldInfo> GetFieldList(MemberListType listType, String name);
    public: Array<RuntimeType> GetInterfaceList(MemberListType listType, String name);
    public: Array<RuntimeType> GetNestedTypeList(MemberListType listType, String name);
    public: MethodBase GetMethod(RuntimeType declaringType, RuntimeMethodHandleInternal method);
    public: MethodBase GetConstructor(RuntimeType declaringType, RuntimeMethodHandleInternal constructor);
    public: FieldInfo GetField(RuntimeFieldHandleInternal field);
    private: RuntimeType m_runtimeType;
    private: RuntimeType m_enclosingType;
    private: TypeCode m_typeCode;
    private: String m_name;
    private: String m_fullname;
    private: String m_toString;
    private: String m_namespace;
    private: Boolean m_isGlobal;
    private: Boolean m_bIsDomainInitialized;
    private: MemberInfoCache<RuntimeMethodInfo> m_methodInfoCache;
    private: MemberInfoCache<RuntimeConstructorInfo> m_constructorInfoCache;
    private: MemberInfoCache<RuntimeFieldInfo> m_fieldInfoCache;
    private: MemberInfoCache<RuntimeType> m_interfaceCache;
    private: MemberInfoCache<RuntimeType> m_nestedClassesCache;
    private: MemberInfoCache<RuntimePropertyInfo> m_propertyInfoCache;
    private: MemberInfoCache<RuntimeEventInfo> m_eventInfoCache;
    private: static CerHashtable<RuntimeMethodInfo, RuntimeMethodInfo> s_methodInstantiations;
    private: static Object s_methodInstantiationsLock;
    private: String m_defaultMemberName;
    private: Object m_genericCache;
    private: Array<Object> _emptyArray;
  };
  private: CLASS(ActivatorCache) : public object {
    public: void ctor(RuntimeMethodHandleInternal rmh);
    private: void Initialize();
    public: void EnsureInitialized();
    public: RuntimeMethodHandleInternal _hCtorMethodHandle;
    public: MethodAttributes _ctorAttributes;
    public: CtorDelegate _ctor;
    public: Boolean _isFullyInitialized;
    private: static ConstructorInfo s_delegateCtorInfo;
  };
  public: Object get_GenericCache();
  public: void set_GenericCache(Object value);
  public: Boolean get_DomainInitialized();
  public: void set_DomainInitialized(Boolean value);
  private: RuntimeTypeCache get_CacheIfExists();
  private: RuntimeTypeCache get_Cache();
  public: Boolean get_IsCollectible();
  public: MethodBase get_DeclaringMethod();
  public: String get_FullName();
  public: String get_AssemblyQualifiedName();
  public: String get_Namespace();
  public: Guid get_GUID();
  public: GenericParameterAttributes get_GenericParameterAttributes();
  public: Boolean get_IsSZArray();
  public: Int32 get_GenericParameterPosition();
  public: Boolean get_ContainsGenericParameters();
  public: StructLayoutAttribute get_StructLayoutAttribute();
  public: String get_Name();
  public: Type get_DeclaringType();
  private: static OleAutBinder get_ForwardCallBinder();
  public: Assembly get_Assembly();
  public: Type get_BaseType();
  public: Boolean get_IsByRefLike();
  public: Boolean get_IsConstructedGenericType();
  public: Boolean get_IsGenericType();
  public: Boolean get_IsGenericTypeDefinition();
  public: Boolean get_IsGenericParameter();
  public: Boolean get_IsTypeDefinition();
  public: Boolean get_IsSecurityCritical();
  public: Boolean get_IsSecuritySafeCritical();
  public: Boolean get_IsSecurityTransparent();
  public: MemberTypes get_MemberType();
  public: Int32 get_MetadataToken();
  public: Module get_Module();
  public: Type get_ReflectedType();
  public: RuntimeTypeHandle get_TypeHandle();
  public: Type get_UnderlyingSystemType();
  public: static RuntimeType GetType(String typeName, Boolean throwOnError, Boolean ignoreCase, StackCrawlMark& stackMark);
  public: static MethodBase GetMethodBase(RuntimeModule scope, Int32 typeMetadataToken);
  public: static MethodBase GetMethodBase(IRuntimeMethodInfo methodHandle);
  public: static MethodBase GetMethodBase(RuntimeType reflectedType, IRuntimeMethodInfo methodHandle);
  public: static MethodBase GetMethodBase(RuntimeType reflectedType, RuntimeMethodHandleInternal methodHandle);
  public: static FieldInfo GetFieldInfo(IRuntimeFieldInfo fieldHandle);
  public: static FieldInfo GetFieldInfo(RuntimeType reflectedType, IRuntimeFieldInfo field);
  private: static PropertyInfo GetPropertyInfo(RuntimeType reflectedType, Int32 tkProperty);
  private: static void ThrowIfTypeNeverValidGenericArgument(RuntimeType type);
  public: static void SanityCheckGenericArguments(Array<RuntimeType> genericArguments, Array<RuntimeType> genericParamters);
  public: static void ValidateGenericArguments(MemberInfo definition, Array<RuntimeType> genericArguments, Exception e);
  private: static void SplitName(String fullname, String& name, String& ns);
  public: static BindingFlags FilterPreCalculate(Boolean isPublic, Boolean isInherited, Boolean isStatic);
  private: static void FilterHelper(BindingFlags bindingFlags, String& name, Boolean allowPrefixLookup, Boolean& prefixLookup, Boolean& ignoreCase, MemberListType& listType);
  private: static void FilterHelper(BindingFlags bindingFlags, String& name, Boolean& ignoreCase, MemberListType& listType);
  private: static Boolean FilterApplyPrefixLookup(MemberInfo memberInfo, String name, Boolean ignoreCase);
  private: static Boolean FilterApplyBase(MemberInfo memberInfo, BindingFlags bindingFlags, Boolean isPublic, Boolean isNonProtectedInternal, Boolean isStatic, String name, Boolean prefixLookup);
  private: static Boolean FilterApplyType(Type type, BindingFlags bindingFlags, String name, Boolean prefixLookup, String ns);
  private: static Boolean FilterApplyMethodInfo(RuntimeMethodInfo method, BindingFlags bindingFlags, CallingConventions callConv, Array<Type> argumentTypes);
  private: static Boolean FilterApplyConstructorInfo(RuntimeConstructorInfo constructor, BindingFlags bindingFlags, CallingConventions callConv, Array<Type> argumentTypes);
  private: static Boolean FilterApplyMethodBase(MethodBase methodBase, BindingFlags methodFlags, BindingFlags bindingFlags, CallingConventions callConv, Array<Type> argumentTypes);
  public: void ctor();
  public: Boolean CacheEquals(Object o);
  private: RuntimeTypeCache InitializeCache();
  private: String GetDefaultMemberName();
  private: ListBuilder<MethodInfo> GetMethodCandidates(String name, Int32 genericParameterCount, BindingFlags bindingAttr, CallingConventions callConv, Array<Type> types, Boolean allowPrefixLookup);
  private: ListBuilder<ConstructorInfo> GetConstructorCandidates(String name, BindingFlags bindingAttr, CallingConventions callConv, Array<Type> types, Boolean allowPrefixLookup);
  private: ListBuilder<PropertyInfo> GetPropertyCandidates(String name, BindingFlags bindingAttr, Array<Type> types, Boolean allowPrefixLookup);
  private: ListBuilder<EventInfo> GetEventCandidates(String name, BindingFlags bindingAttr, Boolean allowPrefixLookup);
  private: ListBuilder<FieldInfo> GetFieldCandidates(String name, BindingFlags bindingAttr, Boolean allowPrefixLookup);
  private: ListBuilder<Type> GetNestedTypeCandidates(String fullname, BindingFlags bindingAttr, Boolean allowPrefixLookup);
  public: Array<MethodInfo> GetMethods(BindingFlags bindingAttr);
  public: Array<ConstructorInfo> GetConstructors(BindingFlags bindingAttr);
  public: Array<PropertyInfo> GetProperties(BindingFlags bindingAttr);
  public: Array<EventInfo> GetEvents(BindingFlags bindingAttr);
  public: Array<FieldInfo> GetFields(BindingFlags bindingAttr);
  public: Array<Type> GetInterfaces();
  public: Array<Type> GetNestedTypes(BindingFlags bindingAttr);
  public: Array<MemberInfo> GetMembers(BindingFlags bindingAttr);
  public: InterfaceMapping GetInterfaceMap(Type ifaceType);
  protected: MethodInfo GetMethodImpl(String name, BindingFlags bindingAttr, Binder binder, CallingConventions callConv, Array<Type> types, Array<ParameterModifier> modifiers);
  protected: MethodInfo GetMethodImpl(String name, Int32 genericParameterCount, BindingFlags bindingAttr, Binder binder, CallingConventions callConv, Array<Type> types, Array<ParameterModifier> modifiers);
  private: MethodInfo GetMethodImplCommon(String name, Int32 genericParameterCount, BindingFlags bindingAttr, Binder binder, CallingConventions callConv, Array<Type> types, Array<ParameterModifier> modifiers);
  protected: ConstructorInfo GetConstructorImpl(BindingFlags bindingAttr, Binder binder, CallingConventions callConvention, Array<Type> types, Array<ParameterModifier> modifiers);
  protected: PropertyInfo GetPropertyImpl(String name, BindingFlags bindingAttr, Binder binder, Type returnType, Array<Type> types, Array<ParameterModifier> modifiers);
  public: EventInfo GetEvent(String name, BindingFlags bindingAttr);
  public: FieldInfo GetField(String name, BindingFlags bindingAttr);
  public: Type GetInterface(String fullname, Boolean ignoreCase);
  public: Type GetNestedType(String fullname, BindingFlags bindingAttr);
  public: Array<MemberInfo> GetMember(String name, MemberTypes type, BindingFlags bindingAttr);
  public: Boolean IsSubclassOf(Type type);
  public: Boolean IsEquivalentTo(Type other);
  private: void GetGUID(Guid& result);
  public: Boolean IsDelegate();
  public: Array<Object> GetEmptyArray();
  public: Array<RuntimeType> GetGenericArgumentsInternal();
  public: Array<Type> GetGenericArguments();
  public: Type MakeGenericType(Array<Type> instantiation);
  public: Array<Type> GetGenericParameterConstraints();
  public: Boolean HasSameMetadataDefinitionAs(MemberInfo other);
  public: Type MakePointerType();
  public: Type MakeByRefType();
  public: Type MakeArrayType();
  public: Type MakeArrayType(Int32 rank);
  private: static Boolean CanValueSpecialCast(RuntimeType valueType, RuntimeType targetType);
  private: static Object AllocateValueType(RuntimeType type, Object value, Boolean fForceTypeChange);
  public: Object CheckValue(Object value, Binder binder, CultureInfo culture, BindingFlags invokeAttr);
  private: Object TryChangeType(Object value, Binder binder, CultureInfo culture, Boolean needsSpecialCast);
  public: Object InvokeMember(String name, BindingFlags bindingFlags, Binder binder, Object target, Array<Object> providedArgs, Array<ParameterModifier> modifiers, CultureInfo culture, Array<String> namedParams);
  public: String ToString();
  private: String GetCachedName(TypeNameKind kind);
  private: void CreateInstanceCheckThis();
  public: Object CreateInstanceImpl(BindingFlags bindingAttr, Binder binder, Array<Object> args, CultureInfo culture);
  private: Object CreateInstanceDefaultCtorSlow(Boolean publicOnly, Boolean wrapExceptions, Boolean fillCache);
  public: Object CreateInstanceDefaultCtor(Boolean publicOnly, Boolean skipCheckThis, Boolean fillCache, Boolean wrapExceptions);
  public: void InvalidateCachedNestedType();
  public: Boolean IsGenericCOMObjectImpl();
  private: static Object _CreateEnum(RuntimeType enumType, Int64 value);
  public: static Object CreateEnum(RuntimeType enumType, Int64 value);
  private: Object InvokeDispMethod(String name, BindingFlags invokeAttr, Object target, Array<Object> args, Array<Boolean> byrefModifiers, Int32 culture, Array<String> namedParameters);
  public: static Type GetTypeFromProgIDImpl(String progID, String server, Boolean throwOnError);
  public: static Type GetTypeFromCLSIDImpl(Guid clsid, String server, Boolean throwOnError);
  private: Object ForwardCallToInvokeMember(String memberName, BindingFlags flags, Object target, Array<Object> aArgs, Array<Boolean> aArgsIsByRef, Array<Int32> aArgsWrapperTypes, Array<Type> aArgsTypes, Type retType);
  private: static void WrapArgsForInvokeCall(Array<Object> aArgs, Array<Int32> aArgsWrapperTypes);
  public: Object Clone();
  public: Boolean Equals(Object obj);
  public: Int32 GetArrayRank();
  protected: TypeAttributes GetAttributeFlagsImpl();
  public: Array<Object> GetCustomAttributes(Boolean inherit);
  public: Array<Object> GetCustomAttributes(Type attributeType, Boolean inherit);
  public: IList<CustomAttributeData> GetCustomAttributesData();
  public: Array<MemberInfo> GetDefaultMembers();
  public: Type GetElementType();
  public: String GetEnumName(Object value);
  public: Array<String> GetEnumNames();
  public: Array<> GetEnumValues();
  public: Type GetEnumUnderlyingType();
  public: Type GetGenericTypeDefinition();
  public: Int32 GetHashCode();
  public: RuntimeModule GetRuntimeModule();
  protected: TypeCode GetTypeCodeImpl();
  protected: Boolean HasElementTypeImpl();
  protected: Boolean IsArrayImpl();
  protected: Boolean IsContextfulImpl();
  public: Boolean IsDefined(Type attributeType, Boolean inherit);
  public: Boolean IsEnumDefined(Object value);
  protected: Boolean IsValueTypeImpl();
  protected: Boolean IsByRefImpl();
  protected: Boolean IsPrimitiveImpl();
  protected: Boolean IsPointerImpl();
  protected: Boolean IsCOMObjectImpl();
  public: Boolean IsInstanceOfType(Object o);
  public: Boolean IsAssignableFrom(TypeInfo typeInfo);
  public: Boolean IsAssignableFrom(Type c);
  private: RuntimeType GetBaseType();
  public: static void cctor();
  private: Object m_keepalive;
  private: IntPtr m_cache;
  public: IntPtr m_handle;
  public: static RuntimeType ValueType;
  private: static RuntimeType ObjectType;
  private: static RuntimeType StringType;
  private: static constexpr Int32 GenericParameterCountAny = -1;
  private: static RuntimeType s_typedRef;
  private: static OleAutBinder s_ForwardCallBinder;
};
} // namespace RuntimeTypeNamespace
using RuntimeType = RuntimeTypeNamespace::RuntimeType;
} // namespace System::Private::CoreLib::System
