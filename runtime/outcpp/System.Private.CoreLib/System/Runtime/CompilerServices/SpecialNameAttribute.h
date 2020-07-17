#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace SpecialNameAttributeNamespace {
CLASS(SpecialNameAttribute) {
  public: void Ctor();
};
} // namespace SpecialNameAttributeNamespace
using SpecialNameAttribute = SpecialNameAttributeNamespace::SpecialNameAttribute;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
