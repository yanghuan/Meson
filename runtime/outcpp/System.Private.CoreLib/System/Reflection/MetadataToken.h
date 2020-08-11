#pragma once

#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection {
enum class MetadataTokenType : int32_t;
namespace MetadataTokenNamespace {
struct MetadataToken : public valueType<MetadataToken> {
  public: Boolean get_IsGlobalTypeDefToken();
  public: MetadataTokenType get_TokenType();
  public: Boolean get_IsTypeRef();
  public: Boolean get_IsTypeDef();
  public: Boolean get_IsFieldDef();
  public: Boolean get_IsMethodDef();
  public: Boolean get_IsMemberRef();
  public: Boolean get_IsEvent();
  public: Boolean get_IsProperty();
  public: Boolean get_IsParamDef();
  public: Boolean get_IsTypeSpec();
  public: Boolean get_IsMethodSpec();
  public: Boolean get_IsString();
  public: Boolean get_IsSignature();
  public: Boolean get_IsGenericPar();
  public: static Int32 op_Implicit(MetadataToken token);
  public: static MetadataToken op_Implicit(Int32 token);
  public: static Boolean IsNullToken(Int32 token);
  public: explicit MetadataToken(Int32 token);
  public: String ToString();
  public: explicit MetadataToken() {}
  public: Int32 Value;
};
} // namespace MetadataTokenNamespace
using MetadataToken = MetadataTokenNamespace::MetadataToken;
} // namespace System::Private::CoreLib::System::Reflection
