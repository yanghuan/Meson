#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Runtime::CompilerServices {
enum class MethodCodeType;
namespace MethodImplAttributeNamespace {
CLASS(MethodImplAttribute) {
  public: MethodCodeType MethodCodeType;
};
} // namespace MethodImplAttributeNamespace
using MethodImplAttribute = MethodImplAttributeNamespace::MethodImplAttribute;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
