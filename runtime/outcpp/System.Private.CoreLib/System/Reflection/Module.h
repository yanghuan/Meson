#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
FORWARDS(Byte)
FORWARDS(Guid)
FORWARDS(Int32)
FORWARDS(ModuleHandle)
FORWARD(Object)
FORWARD(String)
enum class StringComparison;
FORWARD(Type)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(IEnumerable, T)
FORWARD(IList, T)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System::Reflection {
FORWARD(Assembly)
FORWARD(CustomAttributeData)
enum class PortableExecutableKinds;
enum class ImageFileMachine;
FORWARD(MethodInfo)
enum class BindingFlags;
FORWARD(Binder)
enum class CallingConventions;
FORWARDS(ParameterModifier)
FORWARD(FieldInfo)
FORWARD(TypeFilter)
FORWARD(MemberInfo)
FORWARD(MethodBase)
namespace ModuleNamespace {
using namespace ::System::Private::CoreLib::System::Collections::Generic;
using namespace ::System::Private::CoreLib::System::Runtime::Serialization;
using ::System::Private::CoreLib::System::Collections::Generic::IList;
CLASS(Module) {
  public: Assembly get_Assembly();
  public: String get_FullyQualifiedName();
  public: String get_Name();
  public: Int32 get_MDStreamVersion();
  public: Guid get_ModuleVersionId();
  public: String get_ScopeName();
  public: ModuleHandle get_ModuleHandle();
  public: IEnumerable<CustomAttributeData> get_CustomAttributes();
  public: Int32 get_MetadataToken();
  protected: ModuleHandle GetModuleHandleImpl();
  public: void GetPEKind(PortableExecutableKinds& peKind, ImageFileMachine& machine);
  public: Boolean IsResource();
  public: Boolean IsDefined(Type attributeType, Boolean inherit);
  public: IList<CustomAttributeData> GetCustomAttributesData();
  public: Array<Object> GetCustomAttributes(Boolean inherit);
  public: Array<Object> GetCustomAttributes(Type attributeType, Boolean inherit);
  public: MethodInfo GetMethod(String name);
  public: MethodInfo GetMethod(String name, Array<Type> types);
  public: MethodInfo GetMethod(String name, BindingFlags bindingAttr, Binder binder, CallingConventions callConvention, Array<Type> types, Array<ParameterModifier> modifiers);
  protected: MethodInfo GetMethodImpl(String name, BindingFlags bindingAttr, Binder binder, CallingConventions callConvention, Array<Type> types, Array<ParameterModifier> modifiers);
  public: Array<MethodInfo> GetMethods();
  public: Array<MethodInfo> GetMethods(BindingFlags bindingFlags);
  public: FieldInfo GetField(String name);
  public: FieldInfo GetField(String name, BindingFlags bindingAttr);
  public: Array<FieldInfo> GetFields();
  public: Array<FieldInfo> GetFields(BindingFlags bindingFlags);
  public: Array<Type> GetTypes();
  public: Type GetType(String className);
  public: Type GetType(String className, Boolean ignoreCase);
  public: Type GetType(String className, Boolean throwOnError, Boolean ignoreCase);
  public: Array<Type> FindTypes(TypeFilter filter, Object filterCriteria);
  public: FieldInfo ResolveField(Int32 metadataToken);
  public: FieldInfo ResolveField(Int32 metadataToken, Array<Type> genericTypeArguments, Array<Type> genericMethodArguments);
  public: MemberInfo ResolveMember(Int32 metadataToken);
  public: MemberInfo ResolveMember(Int32 metadataToken, Array<Type> genericTypeArguments, Array<Type> genericMethodArguments);
  public: MethodBase ResolveMethod(Int32 metadataToken);
  public: MethodBase ResolveMethod(Int32 metadataToken, Array<Type> genericTypeArguments, Array<Type> genericMethodArguments);
  public: Array<Byte> ResolveSignature(Int32 metadataToken);
  public: String ResolveString(Int32 metadataToken);
  public: Type ResolveType(Int32 metadataToken);
  public: Type ResolveType(Int32 metadataToken, Array<Type> genericTypeArguments, Array<Type> genericMethodArguments);
  public: void GetObjectData(SerializationInfo info, StreamingContext context);
  public: Boolean Equals(Object o);
  public: Int32 GetHashCode();
  public: String ToString();
  private: static Boolean FilterTypeNameImpl(Type cls, Object filterCriteria, StringComparison comparison);
  public: static TypeFilter FilterTypeName;
  public: static TypeFilter FilterTypeNameIgnoreCase;
};
} // namespace ModuleNamespace
using Module = ModuleNamespace::Module;
} // namespace System::Private::CoreLib::System::Reflection
