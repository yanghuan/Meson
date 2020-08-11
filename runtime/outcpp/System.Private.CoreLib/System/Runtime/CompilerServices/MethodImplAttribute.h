#pragma once

#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System {
FORWARDS(Int16)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::CompilerServices {
enum class MethodCodeType : int32_t;
enum class MethodImplOptions : int32_t;
namespace MethodImplAttributeNamespace {
CLASS(MethodImplAttribute) : public Attribute::in {
  public: MethodImplOptions get_Value() { return Value; }
  public: void ctor(MethodImplOptions methodImplOptions);
  public: void ctor(Int16 value);
  public: void ctor();
  public: MethodCodeType MethodCodeType;
  private: MethodImplOptions Value;
};
} // namespace MethodImplAttributeNamespace
using MethodImplAttribute = MethodImplAttributeNamespace::MethodImplAttribute;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
