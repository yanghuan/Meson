#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Runtime::CompilerServices {
enum class MethodCodeType;
enum class MethodImplOptions;
namespace MethodImplAttributeNamespace {
CLASS(MethodImplAttribute) {
  public: MethodCodeType MethodCodeType;
  private: MethodImplOptions Value;
};
} // namespace MethodImplAttributeNamespace
using MethodImplAttribute = MethodImplAttributeNamespace::MethodImplAttribute;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
