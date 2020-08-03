#pragma once

#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System {
FORWARDS(Int16)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::CompilerServices {
enum class MethodCodeType;
enum class MethodImplOptions;
namespace MethodImplAttributeNamespace {
CLASS(MethodImplAttribute) : public Attribute::in {
  public: MethodImplOptions get_Value() { return Value; }
  public: void Ctor(MethodImplOptions methodImplOptions);
  public: void Ctor(Int16 value);
  public: void Ctor();
  public: MethodCodeType MethodCodeType;
  private: MethodImplOptions Value;
};
} // namespace MethodImplAttributeNamespace
using MethodImplAttribute = MethodImplAttributeNamespace::MethodImplAttribute;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
