#pragma once

#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Object.h>
#include <System.Private.CoreLib/System/Reflection/Emit/ParameterToken.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
FORWARDS(Byte)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection {
enum class ParameterAttributes : int32_t;
FORWARD(ConstructorInfo)
} // namespace System::Private::CoreLib::System::Reflection
namespace System::Private::CoreLib::System::Reflection::Emit {
FORWARD(CustomAttributeBuilder)
FORWARD(MethodBuilder)
namespace ParameterBuilderNamespace {
CLASS(ParameterBuilder) : public object {
  public: String get_Name();
  public: Int32 get_Position();
  public: Int32 get_Attributes();
  public: Boolean get_IsIn();
  public: Boolean get_IsOut();
  public: Boolean get_IsOptional();
  public: void SetConstant(Object defaultValue);
  public: void SetCustomAttribute(ConstructorInfo con, Array<Byte> binaryAttribute);
  public: void SetCustomAttribute(CustomAttributeBuilder customBuilder);
  public: void ctor(MethodBuilder methodBuilder, Int32 sequence, ParameterAttributes attributes, String paramName);
  public: ParameterToken GetToken();
  private: String _name;
  private: Int32 _position;
  private: ParameterAttributes _attributes;
  private: MethodBuilder _methodBuilder;
  private: ParameterToken _token;
};
} // namespace ParameterBuilderNamespace
using ParameterBuilder = ParameterBuilderNamespace::ParameterBuilder;
} // namespace System::Private::CoreLib::System::Reflection::Emit
