#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/IntPtr.h>

namespace System::Private::CoreLib::System {
FORWARDS(Int32)
FORWARD(RuntimeType)
FORWARD(String)
FORWARDS(Guid)
FORWARDS(Boolean)
FORWARD_(Array, T1, T2)
FORWARD(Type)
FORWARDS(RuntimeTypeHandle)
FORWARDS(Byte)
FORWARD(Object)
FORWARDS(ModuleHandle)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::CompilerServices {
FORWARDS(QCallModule)
FORWARDS(ObjectHandleOnStack)
FORWARDS(StringHandleOnStack)
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(IList, T)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System::Reflection {
FORWARDS(MetadataImport)
FORWARD(Assembly)
FORWARD(MethodBase)
FORWARD(FieldInfo)
FORWARD(MemberInfo)
enum class PortableExecutableKinds;
enum class ImageFileMachine;
enum class BindingFlags;
FORWARD(Binder)
enum class CallingConventions;
FORWARDS(ParameterModifier)
FORWARD(MethodInfo)
FORWARD(CustomAttributeData)
FORWARD(RuntimeAssembly)
namespace RuntimeModuleNamespace {
using namespace ::System::Private::CoreLib::System::Collections::Generic;
using namespace ::System::Private::CoreLib::System::Runtime::CompilerServices;
using namespace ::System::Private::CoreLib::System::Runtime::Serialization;
using System::Collections::Generic::IList;
CLASS(RuntimeModule) {
  public: Int32 get_MDStreamVersion();
  public: RuntimeType get_RuntimeType();
  public: MetadataImport get_MetadataImport();
  public: String get_FullyQualifiedName();
  public: Guid get_ModuleVersionId();
  public: Int32 get_MetadataToken();
  public: String get_ScopeName();
  public: String get_Name();
  public: Assembly get_Assembly();
  private: static void GetType(QCallModule module, String className, Boolean throwOnError, Boolean ignoreCase, ObjectHandleOnStack type, ObjectHandleOnStack keepAlive);
  private: static Boolean nIsTransientInternal(QCallModule module);
  private: static void GetScopeName(QCallModule module, StringHandleOnStack retString);
  private: static void GetFullyQualifiedName(QCallModule module, StringHandleOnStack retString);
  private: static Array<RuntimeType> GetTypes(RuntimeModule module);
  public: Array<RuntimeType> GetDefinedTypes();
  private: static Boolean IsResource(RuntimeModule module);
  private: static Array<RuntimeTypeHandle> ConvertToTypeHandleArray(Array<Type> genericArguments);
  public: Array<Byte> ResolveSignature(Int32 metadataToken);
  public: MethodBase ResolveMethod(Int32 metadataToken, Array<Type> genericTypeArguments, Array<Type> genericMethodArguments);
  private: FieldInfo ResolveLiteralField(Int32 metadataToken, Array<Type> genericTypeArguments, Array<Type> genericMethodArguments);
  public: FieldInfo ResolveField(Int32 metadataToken, Array<Type> genericTypeArguments, Array<Type> genericMethodArguments);
  public: Type ResolveType(Int32 metadataToken, Array<Type> genericTypeArguments, Array<Type> genericMethodArguments);
  public: MemberInfo ResolveMember(Int32 metadataToken, Array<Type> genericTypeArguments, Array<Type> genericMethodArguments);
  public: String ResolveString(Int32 metadataToken);
  public: void GetPEKind(PortableExecutableKinds& peKind, ImageFileMachine& machine);
  protected: MethodInfo GetMethodImpl(String name, BindingFlags bindingAttr, Binder binder, CallingConventions callConvention, Array<Type> types, Array<ParameterModifier> modifiers);
  public: MethodInfo GetMethodInternal(String name, BindingFlags bindingAttr, Binder binder, CallingConventions callConvention, Array<Type> types, Array<ParameterModifier> modifiers);
  public: Boolean IsTransientInternal();
  public: Array<Object> GetCustomAttributes(Boolean inherit);
  public: Array<Object> GetCustomAttributes(Type attributeType, Boolean inherit);
  public: Boolean IsDefined(Type attributeType, Boolean inherit);
  public: IList<CustomAttributeData> GetCustomAttributesData();
  public: void GetObjectData(SerializationInfo info, StreamingContext context);
  public: Type GetType(String className, Boolean throwOnError, Boolean ignoreCase);
  public: String GetFullyQualifiedName();
  public: Array<Type> GetTypes();
  public: Boolean IsResource();
  public: Array<FieldInfo> GetFields(BindingFlags bindingFlags);
  public: FieldInfo GetField(String name, BindingFlags bindingAttr);
  public: Array<MethodInfo> GetMethods(BindingFlags bindingFlags);
  public: RuntimeAssembly GetRuntimeAssembly();
  protected: ModuleHandle GetModuleHandleImpl();
  public: RuntimeModule GetNativeHandle();
  public: IntPtr GetUnderlyingNativeHandle();
  private: RuntimeType m_runtimeType;
  private: RuntimeAssembly m_runtimeAssembly;
  private: IntPtr m_pRefClass;
  private: IntPtr m_pData;
  private: IntPtr m_pGlobals;
  private: IntPtr m_pFields;
};
} // namespace RuntimeModuleNamespace
using RuntimeModule = RuntimeModuleNamespace::RuntimeModule;
} // namespace System::Private::CoreLib::System::Reflection
