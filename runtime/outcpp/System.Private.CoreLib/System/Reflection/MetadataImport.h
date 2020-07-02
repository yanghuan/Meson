#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/IntPtr.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(Guid)
FORWARDS(Int32)
FORWARDS(Int64)
FORWARDS(MdUtf8String)
FORWARD(Object)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices {
enum class UnmanagedType;
enum class VarEnum;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
namespace System::Private::CoreLib::System::Reflection {
FORWARDS(ConstArray)
FORWARDS(MetadataEnumResult)
enum class MetadataTokenType;
enum class CorElementType : uint8_t;
enum class EventAttributes;
enum class FieldAttributes;
enum class PropertyAttributes;
enum class ParameterAttributes;
enum class GenericParameterAttributes;
FORWARDS(MetadataToken)
enum class PInvokeAttributes;
namespace MetadataImportNamespace {
using namespace ::System::Private::CoreLib::System::Runtime::InteropServices;
struct MetadataImport {
  public: Int32 GetHashCode();
  public: Boolean Equals(Object obj);
  private: Boolean Equals(MetadataImport import);
  private: static void _GetMarshalAs(IntPtr pNativeType, Int32 cNativeType, Int32& unmanagedType, Int32& safeArraySubType, String& safeArrayUserDefinedSubType, Int32& arraySubType, Int32& sizeParamIndex, Int32& sizeConst, String& marshalType, String& marshalCookie, Int32& iidParamIndex);
  public: static void GetMarshalAs(ConstArray nativeType, UnmanagedType& unmanagedType, VarEnum& safeArraySubType, String& safeArrayUserDefinedSubType, UnmanagedType& arraySubType, Int32& sizeParamIndex, Int32& sizeConst, String& marshalType, String& marshalCookie, Int32& iidParamIndex);
  public: static void ThrowError(Int32 hResult);
  private: static void _Enum(IntPtr scope, Int32 type, Int32 parent, MetadataEnumResult& result);
  public: void Enum(MetadataTokenType type, Int32 parent, MetadataEnumResult& result);
  public: void EnumNestedTypes(Int32 mdTypeDef, MetadataEnumResult& result);
  public: void EnumCustomAttributes(Int32 mdToken, MetadataEnumResult& result);
  public: void EnumParams(Int32 mdMethodDef, MetadataEnumResult& result);
  public: void EnumFields(Int32 mdTypeDef, MetadataEnumResult& result);
  public: void EnumProperties(Int32 mdTypeDef, MetadataEnumResult& result);
  public: void EnumEvents(Int32 mdTypeDef, MetadataEnumResult& result);
  private: static String _GetDefaultValue(IntPtr scope, Int32 mdToken, Int64& value, Int32& length, Int32& corElementType);
  public: String GetDefaultValue(Int32 mdToken, Int64& value, Int32& length, CorElementType& corElementType);
  private: static void _GetUserString(IntPtr scope, Int32 mdToken, void** name, Int32& length);
  public: String GetUserString(Int32 mdToken);
  private: static void _GetName(IntPtr scope, Int32 mdToken, void** name);
  public: MdUtf8String GetName(Int32 mdToken);
  private: static void _GetNamespace(IntPtr scope, Int32 mdToken, void** namesp);
  public: MdUtf8String GetNamespace(Int32 mdToken);
  private: static void _GetEventProps(IntPtr scope, Int32 mdToken, void** name, Int32& eventAttributes);
  public: void GetEventProps(Int32 mdToken, void*& name, EventAttributes& eventAttributes);
  private: static void _GetFieldDefProps(IntPtr scope, Int32 mdToken, Int32& fieldAttributes);
  public: void GetFieldDefProps(Int32 mdToken, FieldAttributes& fieldAttributes);
  private: static void _GetPropertyProps(IntPtr scope, Int32 mdToken, void** name, Int32& propertyAttributes, ConstArray& signature);
  public: void GetPropertyProps(Int32 mdToken, void*& name, PropertyAttributes& propertyAttributes, ConstArray& signature);
  private: static void _GetParentToken(IntPtr scope, Int32 mdToken, Int32& tkParent);
  public: Int32 GetParentToken(Int32 tkToken);
  private: static void _GetParamDefProps(IntPtr scope, Int32 parameterToken, Int32& sequence, Int32& attributes);
  public: void GetParamDefProps(Int32 parameterToken, Int32& sequence, ParameterAttributes& attributes);
  private: static void _GetGenericParamProps(IntPtr scope, Int32 genericParameter, Int32& flags);
  public: void GetGenericParamProps(Int32 genericParameter, GenericParameterAttributes& attributes);
  private: static void _GetScopeProps(IntPtr scope, Guid& mvid);
  public: void GetScopeProps(Guid& mvid);
  public: ConstArray GetMethodSignature(MetadataToken token);
  private: static void _GetSigOfMethodDef(IntPtr scope, Int32 methodToken, ConstArray& signature);
  public: ConstArray GetSigOfMethodDef(Int32 methodToken);
  private: static void _GetSignatureFromToken(IntPtr scope, Int32 methodToken, ConstArray& signature);
  public: ConstArray GetSignatureFromToken(Int32 token);
  private: static void _GetMemberRefProps(IntPtr scope, Int32 memberTokenRef, ConstArray& signature);
  public: ConstArray GetMemberRefProps(Int32 memberTokenRef);
  private: static void _GetCustomAttributeProps(IntPtr scope, Int32 customAttributeToken, Int32& constructorToken, ConstArray& signature);
  public: void GetCustomAttributeProps(Int32 customAttributeToken, Int32& constructorToken, ConstArray& signature);
  private: static void _GetClassLayout(IntPtr scope, Int32 typeTokenDef, Int32& packSize, Int32& classSize);
  public: void GetClassLayout(Int32 typeTokenDef, Int32& packSize, Int32& classSize);
  private: static Boolean _GetFieldOffset(IntPtr scope, Int32 typeTokenDef, Int32 fieldTokenDef, Int32& offset);
  public: Boolean GetFieldOffset(Int32 typeTokenDef, Int32 fieldTokenDef, Int32& offset);
  private: static void _GetSigOfFieldDef(IntPtr scope, Int32 fieldToken, ConstArray& fieldMarshal);
  public: ConstArray GetSigOfFieldDef(Int32 fieldToken);
  private: static void _GetFieldMarshal(IntPtr scope, Int32 fieldToken, ConstArray& fieldMarshal);
  public: ConstArray GetFieldMarshal(Int32 fieldToken);
  private: static void _GetPInvokeMap(IntPtr scope, Int32 token, Int32& attributes, void** importName, void** importDll);
  public: void GetPInvokeMap(Int32 token, PInvokeAttributes& attributes, String& importName, String& importDll);
  private: static Boolean _IsValidToken(IntPtr scope, Int32 token);
  public: Boolean IsValidToken(Int32 token);
  private: IntPtr m_metadataImport2;
  private: Object m_keepalive;
  public: static MetadataImport EmptyImport;
};
} // namespace MetadataImportNamespace
using MetadataImport = MetadataImportNamespace::MetadataImport;
} // namespace System::Private::CoreLib::System::Reflection
