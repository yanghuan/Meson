#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(ISerializable)
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System {
enum class StringComparison : int32_t;
FORWARD_(Array)
FORWARDS(Boolean)
FORWARDS(Byte)
FORWARDS(Guid)
FORWARDS(Int32)
FORWARDS(ModuleHandle)
FORWARD(String)
FORWARD(Type)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(IEnumerable, T)
FORWARD(IList, T)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System::Reflection {
enum class BindingFlags : int32_t;
enum class CallingConventions : int32_t;
enum class ImageFileMachine : int32_t;
enum class PortableExecutableKinds : int32_t;
FORWARD(Assembly)
FORWARD(Binder)
FORWARD(CustomAttributeData)
FORWARD(FieldInfo)
FORWARD(ICustomAttributeProvider)
FORWARD(MemberInfo)
FORWARD(MethodBase)
FORWARD(MethodInfo)
FORWARDS(ParameterModifier)
FORWARD(TypeFilter)
namespace ModuleNamespace {
using namespace System::Collections::Generic;
using namespace System::Runtime::Serialization;
CLASS(Module) : public object {
  public: using interface = rt::TypeList<ICustomAttributeProvider, ISerializable>;
  private: CLASS(__c) : public object {
    public: static void cctor();
    public: void ctor();
    public: Boolean _cctor_b__61_0(Type m, Object c);
    public: Boolean _cctor_b__61_1(Type m, Object c);
    public: static __c __9;
  };
  public: Assembly get_Assembly();
  public: String get_FullyQualifiedName();
  public: String get_Name();
  public: Int32 get_MDStreamVersion();
  public: Guid get_ModuleVersionId();
  public: String get_ScopeName();
  public: ModuleHandle get_ModuleHandle();
  public: IEnumerable<CustomAttributeData> get_CustomAttributes();
  public: Int32 get_MetadataToken();
  public: void ctor();
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
  public: static Boolean op_Equality(Module left, Module right);
  public: static Boolean op_Inequality(Module left, Module right);
  public: String ToString();
  private: static Boolean FilterTypeNameImpl(Type cls, Object filterCriteria, StringComparison comparison);
  public: static void cctor();
  public: static TypeFilter FilterTypeName;
  public: static TypeFilter FilterTypeNameIgnoreCase;
};
} // namespace ModuleNamespace
using Module = ModuleNamespace::Module;
} // namespace System::Private::CoreLib::System::Reflection
