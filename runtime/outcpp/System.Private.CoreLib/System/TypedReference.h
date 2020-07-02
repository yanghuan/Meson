#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/IntPtr.h>

namespace System::Private::CoreLib::System::Reflection {
FORWARD(FieldInfo)
} // namespace System::Private::CoreLib::System::Reflection
namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARD(Object)
FORWARD_(Array, T1, T2)
FORWARD(RuntimeType)
FORWARDS(Int32)
FORWARD(Type)
FORWARDS(RuntimeTypeHandle)
namespace TypedReferenceNamespace {
using namespace ::System::Private::CoreLib::System::Reflection;
struct TypedReference {
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
  public: static void InternalSetTypedReference(void* target, Object value);
  private: IntPtr Value;
  private: IntPtr Type;
};
} // namespace TypedReferenceNamespace
using TypedReference = TypedReferenceNamespace::TypedReference;
} // namespace System::Private::CoreLib::System
