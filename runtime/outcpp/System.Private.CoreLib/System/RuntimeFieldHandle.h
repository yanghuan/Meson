#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Reflection {
enum class FieldAttributes;
FORWARD(RtFieldInfo)
} // namespace System::Private::CoreLib::System::Reflection
namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(Int32)
FORWARDS(IntPtr)
FORWARD(IRuntimeFieldInfo)
FORWARDS(MdUtf8String)
FORWARD(Object)
FORWARDS(RuntimeFieldHandleInternal)
FORWARD(RuntimeType)
FORWARD(String)
FORWARDS(UInt32)
namespace RuntimeFieldHandleNamespace {
using namespace Reflection;
using namespace Runtime::Serialization;
struct RuntimeFieldHandle {
  public: IntPtr get_Value();
  public: IRuntimeFieldInfo GetRuntimeFieldInfo();
  public: Boolean IsNullHandle();
  public: Int32 GetHashCode();
  public: Boolean Equals(Object obj);
  public: Boolean Equals(RuntimeFieldHandle handle);
  public: static String GetName(RtFieldInfo field);
  private: static void* _GetUtf8Name(RuntimeFieldHandleInternal field);
  public: static MdUtf8String GetUtf8Name(RuntimeFieldHandleInternal field);
  public: static Boolean MatchesNameHash(RuntimeFieldHandleInternal handle, UInt32 hash);
  public: static FieldAttributes GetAttributes(RuntimeFieldHandleInternal field);
  public: static RuntimeType GetApproxDeclaringType(RuntimeFieldHandleInternal field);
  public: static RuntimeType GetApproxDeclaringType(IRuntimeFieldInfo field);
  public: static Int32 GetToken(RtFieldInfo field);
  public: static Object GetValue(RtFieldInfo field, Object instance, RuntimeType fieldType, RuntimeType declaringType, Boolean& domainInitialized);
  public: static Object GetValueDirect(RtFieldInfo field, RuntimeType fieldType, void* pTypedRef, RuntimeType contextType);
  public: static void SetValue(RtFieldInfo field, Object obj, Object value, RuntimeType fieldType, FieldAttributes fieldAttr, RuntimeType declaringType, Boolean& domainInitialized);
  public: static void SetValueDirect(RtFieldInfo field, RuntimeType fieldType, void* pTypedRef, Object value, RuntimeType contextType);
  public: static RuntimeFieldHandleInternal GetStaticFieldForGenericType(RuntimeFieldHandleInternal field, RuntimeType declaringType);
  public: static Boolean AcquiresContextFromThis(RuntimeFieldHandleInternal field);
  public: void GetObjectData(SerializationInfo info, StreamingContext context);
  private: IRuntimeFieldInfo m_ptr;
};
} // namespace RuntimeFieldHandleNamespace
using RuntimeFieldHandle = RuntimeFieldHandleNamespace::RuntimeFieldHandle;
} // namespace System::Private::CoreLib::System
