#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Runtime::CompilerServices {
enum class MethodImplOptions;
enum class MethodCodeType;
namespace MethodImplAttributeNamespace {
CLASS(MethodImplAttribute) {
  public: MethodImplOptions get_Value() { return Value; }
  public: MethodCodeType MethodCodeType;
  private: MethodImplOptions Value;
};
} // namespace MethodImplAttributeNamespace
using MethodImplAttribute = MethodImplAttributeNamespace::MethodImplAttribute;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
