#pragma once

#include <System.Private.CoreLib/System/Reflection/Module.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
FORWARDS(Byte)
FORWARDS(Guid)
FORWARDS(Int32)
FORWARDS(IntPtr)
FORWARDS(ModuleHandle)
FORWARD(Object)
FORWARDS(RuntimeMethodHandleInternal)
FORWARDS(RuntimeTypeHandle)
FORWARD(String)
FORWARD(Type)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection {
enum class BindingFlags : int32_t;
enum class CallingConventions : int32_t;
enum class FieldAttributes : int32_t;
enum class ImageFileMachine : int32_t;
enum class MethodAttributes : int32_t;
enum class PortableExecutableKinds : int32_t;
enum class TypeAttributes : int32_t;
FORWARD(Assembly)
FORWARD(Binder)
FORWARD(ConstructorInfo)
FORWARD(CustomAttributeData)
FORWARD(FieldInfo)
FORWARD(MemberInfo)
FORWARD(MethodBase)
FORWARD(MethodInfo)
FORWARDS(ParameterModifier)
FORWARD(RuntimeConstructorInfo)
FORWARD(RuntimeFieldInfo)
FORWARD(RuntimeMethodInfo)
FORWARD(RuntimeModule)
} // namespace System::Private::CoreLib::System::Reflection
namespace System::Private::CoreLib::System::Runtime::CompilerServices {
FORWARDS(QCallModule)
FORWARDS(QCallTypeHandle)
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
namespace System::Private::CoreLib::System::Diagnostics::SymbolStore {
FORWARD(ISymbolDocumentWriter)
FORWARD(ISymbolWriter)
} // namespace System::Private::CoreLib::System::Diagnostics::SymbolStore
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(Dictionary, TKey, TValue)
FORWARD(IEnumerable, T)
FORWARD(IList, T)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System::Runtime::InteropServices {
enum class CallingConvention : int32_t;
enum class CharSet : int32_t;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
namespace System::Private::CoreLib::System::Reflection::Emit {
enum class PackingSize : int32_t;
FORWARD(AssemblyBuilder)
FORWARD(CustomAttributeBuilder)
FORWARD(EnumBuilder)
FORWARD(FieldBuilder)
FORWARDS(FieldToken)
FORWARD(InternalModuleBuilder)
FORWARD(MethodBuilder)
FORWARDS(MethodToken)
FORWARD(ModuleBuilderData)
FORWARD(SignatureHelper)
FORWARDS(SignatureToken)
FORWARDS(StringToken)
FORWARD(TypeBuilder)
FORWARDS(TypeToken)
namespace ModuleBuilderNamespace {
using namespace System::Collections::Generic;
using namespace System::Diagnostics::SymbolStore;
using namespace System::Runtime::CompilerServices;
using namespace System::Runtime::InteropServices;
CLASS(ModuleBuilder) : public Module::in {
  public: AssemblyBuilder get_ContainingAssemblyBuilder();
  public: Object get_SyncRoot();
  public: InternalModuleBuilder get_InternalModule();
  public: String get_FullyQualifiedName();
  public: Int32 get_MDStreamVersion();
  public: Guid get_ModuleVersionId();
  public: Int32 get_MetadataToken();
  public: String get_ScopeName();
  public: String get_Name();
  public: Assembly get_Assembly();
  public: static IntPtr nCreateISymWriterForDynamicModule(Module module, String filename);
  public: static String UnmangleTypeName(String typeName);
  public: void ctor(AssemblyBuilder assemblyBuilder, InternalModuleBuilder internalModuleBuilder);
  public: void AddType(String name, Type type);
  public: void CheckTypeNameConflict(String strTypeName, Type enclosingType);
  private: static Type GetType(String strFormat, Type baseType);
  public: void CheckContext(Array<Array<Type>> typess);
  public: void CheckContext(Array<Type> types);
  private: static Int32 GetTypeRef(QCallModule module, String strFullName, QCallModule refedModule, String strRefedModuleFileName, Int32 tkResolution);
  private: static Int32 GetMemberRef(QCallModule module, QCallModule refedModule, Int32 tr, Int32 defToken);
  private: Int32 GetMemberRef(Module refedModule, Int32 tr, Int32 defToken);
  private: static Int32 GetMemberRefFromSignature(QCallModule module, Int32 tr, String methodName, Array<Byte> signature, Int32 length);
  private: Int32 GetMemberRefFromSignature(Int32 tr, String methodName, Array<Byte> signature, Int32 length);
  private: static Int32 GetMemberRefOfMethodInfo(QCallModule module, Int32 tr, RuntimeMethodHandleInternal method);
  private: Int32 GetMemberRefOfMethodInfo(Int32 tr, RuntimeMethodInfo method);
  private: Int32 GetMemberRefOfMethodInfo(Int32 tr, RuntimeConstructorInfo method);
  private: static Int32 GetMemberRefOfFieldInfo(QCallModule module, Int32 tkType, QCallTypeHandle declaringType, Int32 tkField);
  private: Int32 GetMemberRefOfFieldInfo(Int32 tkType, RuntimeTypeHandle declaringType, RuntimeFieldInfo runtimeField);
  private: static Int32 GetTokenFromTypeSpec(QCallModule pModule, Array<Byte> signature, Int32 length);
  private: Int32 GetTokenFromTypeSpec(Array<Byte> signature, Int32 length);
  private: static Int32 GetArrayMethodToken(QCallModule module, Int32 tkTypeSpec, String methodName, Array<Byte> signature, Int32 sigLength);
  private: static Int32 GetStringConstant(QCallModule module, String str, Int32 length);
  public: static void SetFieldRVAContent(QCallModule module, Int32 fdToken, Array<Byte> data, Int32 length);
  public: Type FindTypeBuilderWithName(String strTypeName, Boolean ignoreCase);
  private: Int32 GetTypeRefNested(Type type, Module refedModule, String strRefedModuleFileName);
  public: MethodToken InternalGetConstructorToken(ConstructorInfo con, Boolean usingRef);
  public: void Init(String strModuleName);
  public: void SetSymWriter(ISymbolWriter writer);
  protected: ModuleHandle GetModuleHandleImpl();
  public: RuntimeModule GetNativeHandle();
  private: static RuntimeModule GetRuntimeModuleFromModule(Module m);
  private: Int32 GetMemberRefToken(MethodBase method, IEnumerable<Type> optionalParameterTypes);
  public: SignatureHelper GetMemberRefSignature(CallingConventions call, Type returnType, Array<Type> parameterTypes, IEnumerable<Type> optionalParameterTypes, Int32 cGenericParameters);
  public: Boolean Equals(Object obj);
  public: Int32 GetHashCode();
  public: Array<Object> GetCustomAttributes(Boolean inherit);
  public: Array<Object> GetCustomAttributes(Type attributeType, Boolean inherit);
  public: Boolean IsDefined(Type attributeType, Boolean inherit);
  public: IList<CustomAttributeData> GetCustomAttributesData();
  public: Array<Type> GetTypes();
  public: Array<Type> GetTypesNoLock();
  public: Type GetType(String className);
  public: Type GetType(String className, Boolean ignoreCase);
  public: Type GetType(String className, Boolean throwOnError, Boolean ignoreCase);
  private: Type GetTypeNoLock(String className, Boolean throwOnError, Boolean ignoreCase);
  public: Array<Byte> ResolveSignature(Int32 metadataToken);
  public: MethodBase ResolveMethod(Int32 metadataToken, Array<Type> genericTypeArguments, Array<Type> genericMethodArguments);
  public: FieldInfo ResolveField(Int32 metadataToken, Array<Type> genericTypeArguments, Array<Type> genericMethodArguments);
  public: Type ResolveType(Int32 metadataToken, Array<Type> genericTypeArguments, Array<Type> genericMethodArguments);
  public: MemberInfo ResolveMember(Int32 metadataToken, Array<Type> genericTypeArguments, Array<Type> genericMethodArguments);
  public: String ResolveString(Int32 metadataToken);
  public: void GetPEKind(PortableExecutableKinds& peKind, ImageFileMachine& machine);
  public: Boolean IsResource();
  public: Array<FieldInfo> GetFields(BindingFlags bindingFlags);
  public: FieldInfo GetField(String name, BindingFlags bindingAttr);
  public: Array<MethodInfo> GetMethods(BindingFlags bindingFlags);
  protected: MethodInfo GetMethodImpl(String name, BindingFlags bindingAttr, Binder binder, CallingConventions callConvention, Array<Type> types, Array<ParameterModifier> modifiers);
  public: TypeBuilder DefineType(String name);
  public: TypeBuilder DefineType(String name, TypeAttributes attr);
  public: TypeBuilder DefineType(String name, TypeAttributes attr, Type parent);
  public: TypeBuilder DefineType(String name, TypeAttributes attr, Type parent, Int32 typesize);
  public: TypeBuilder DefineType(String name, TypeAttributes attr, Type parent, PackingSize packingSize, Int32 typesize);
  public: TypeBuilder DefineType(String name, TypeAttributes attr, Type parent, Array<Type> interfaces);
  private: TypeBuilder DefineTypeNoLock(String name, TypeAttributes attr, Type parent, Array<Type> interfaces, PackingSize packingSize, Int32 typesize);
  public: TypeBuilder DefineType(String name, TypeAttributes attr, Type parent, PackingSize packsize);
  private: TypeBuilder DefineTypeNoLock(String name, TypeAttributes attr, Type parent, PackingSize packsize);
  public: EnumBuilder DefineEnum(String name, TypeAttributes visibility, Type underlyingType);
  private: EnumBuilder DefineEnumNoLock(String name, TypeAttributes visibility, Type underlyingType);
  public: MethodBuilder DefinePInvokeMethod(String name, String dllName, MethodAttributes attributes, CallingConventions callingConvention, Type returnType, Array<Type> parameterTypes, CallingConvention nativeCallConv, CharSet nativeCharSet);
  public: MethodBuilder DefinePInvokeMethod(String name, String dllName, String entryName, MethodAttributes attributes, CallingConventions callingConvention, Type returnType, Array<Type> parameterTypes, CallingConvention nativeCallConv, CharSet nativeCharSet);
  public: MethodBuilder DefineGlobalMethod(String name, MethodAttributes attributes, Type returnType, Array<Type> parameterTypes);
  public: MethodBuilder DefineGlobalMethod(String name, MethodAttributes attributes, CallingConventions callingConvention, Type returnType, Array<Type> parameterTypes);
  public: MethodBuilder DefineGlobalMethod(String name, MethodAttributes attributes, CallingConventions callingConvention, Type returnType, Array<Type> requiredReturnTypeCustomModifiers, Array<Type> optionalReturnTypeCustomModifiers, Array<Type> parameterTypes, Array<Array<Type>> requiredParameterTypeCustomModifiers, Array<Array<Type>> optionalParameterTypeCustomModifiers);
  private: MethodBuilder DefineGlobalMethodNoLock(String name, MethodAttributes attributes, CallingConventions callingConvention, Type returnType, Array<Type> requiredReturnTypeCustomModifiers, Array<Type> optionalReturnTypeCustomModifiers, Array<Type> parameterTypes, Array<Array<Type>> requiredParameterTypeCustomModifiers, Array<Array<Type>> optionalParameterTypeCustomModifiers);
  public: void CreateGlobalFunctions();
  private: void CreateGlobalFunctionsNoLock();
  public: FieldBuilder DefineInitializedData(String name, Array<Byte> data, FieldAttributes attributes);
  private: FieldBuilder DefineInitializedDataNoLock(String name, Array<Byte> data, FieldAttributes attributes);
  public: FieldBuilder DefineUninitializedData(String name, Int32 size, FieldAttributes attributes);
  private: FieldBuilder DefineUninitializedDataNoLock(String name, Int32 size, FieldAttributes attributes);
  public: TypeToken GetTypeTokenInternal(Type type);
  private: TypeToken GetTypeTokenInternal(Type type, Boolean getGenericDefinition);
  public: TypeToken GetTypeToken(Type type);
  private: TypeToken GetTypeTokenWorkerNoLock(Type type, Boolean getGenericDefinition);
  public: TypeToken GetTypeToken(String name);
  public: MethodToken GetMethodToken(MethodInfo method);
  public: MethodToken GetMethodTokenInternal(MethodInfo method);
  private: MethodToken GetMethodTokenNoLock(MethodInfo method, Boolean getGenericTypeDefinition);
  public: Int32 GetMethodTokenInternal(MethodBase method, IEnumerable<Type> optionalParameterTypes, Boolean useMethodDef);
  public: MethodToken GetArrayMethodToken(Type arrayClass, String methodName, CallingConventions callingConvention, Type returnType, Array<Type> parameterTypes);
  private: MethodToken GetArrayMethodTokenNoLock(Type arrayClass, String methodName, CallingConventions callingConvention, Type returnType, Array<Type> parameterTypes);
  public: MethodInfo GetArrayMethod(Type arrayClass, String methodName, CallingConventions callingConvention, Type returnType, Array<Type> parameterTypes);
  public: MethodToken GetConstructorToken(ConstructorInfo con);
  public: FieldToken GetFieldToken(FieldInfo field);
  private: FieldToken GetFieldTokenNoLock(FieldInfo field);
  public: StringToken GetStringConstant(String str);
  public: SignatureToken GetSignatureToken(SignatureHelper sigHelper);
  public: SignatureToken GetSignatureToken(Array<Byte> sigBytes, Int32 sigLength);
  public: void SetCustomAttribute(ConstructorInfo con, Array<Byte> binaryAttribute);
  public: void SetCustomAttribute(CustomAttributeBuilder customBuilder);
  public: ISymbolWriter GetSymWriter();
  public: ISymbolDocumentWriter DefineDocument(String url, Guid language, Guid languageVendor, Guid documentType);
  private: ISymbolDocumentWriter DefineDocumentNoLock(String url, Guid language, Guid languageVendor, Guid documentType);
  public: Boolean IsTransient();
  private: Dictionary<String, Type> _typeBuilderDict;
  private: ISymbolWriter _iSymWriter;
  public: ModuleBuilderData _moduleData;
  public: InternalModuleBuilder _internalModuleBuilder;
  private: AssemblyBuilder _assemblyBuilder;
};
} // namespace ModuleBuilderNamespace
using ModuleBuilder = ModuleBuilderNamespace::ModuleBuilder;
} // namespace System::Private::CoreLib::System::Reflection::Emit
