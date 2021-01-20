#pragma once

#include <System.Private.CoreLib/System/ByReference.h>
#include <System.Private.CoreLib/System/Byte.h>
#include <System.Private.CoreLib/System/IntPtr.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System::Reflection {
FORWARD(FieldInfo)
} // namespace System::Private::CoreLib::System::Reflection
namespace System::Private::CoreLib::System {
FORWARD_(Array)
FORWARDS(Boolean)
FORWARDS(Int32)
FORWARD(Object)
FORWARD(RuntimeType)
FORWARDS(RuntimeTypeHandle)
FORWARD(Type)
namespace TypedReferenceNamespace {
using namespace System::Reflection;
struct TypedReference : public valueType<TypedReference> {
  public: Boolean get_IsNull();
  public: static TypedReference MakeTypedReference(Object target, Array<FieldInfo> flds);
  private: static void InternalMakeTypedReference(void* result, Object target, Array<IntPtr> flds, RuntimeType lastFieldType);
  public: Int32 GetHashCode();
  public: Boolean Equals(Object o);
  public: static Object ToObject(TypedReference value);
  public: static Object InternalToObject(void* value);
  public: static Type GetTargetType(TypedReference value);
  public: static RuntimeTypeHandle TargetTypeToken(TypedReference value);
  public: static void SetTypedReference(TypedReference target, Object value);
  private: ByReference<Byte> _value;
  private: IntPtr _type;
};
} // namespace TypedReferenceNamespace
using TypedReference = TypedReferenceNamespace::TypedReference;
} // namespace System::Private::CoreLib::System
