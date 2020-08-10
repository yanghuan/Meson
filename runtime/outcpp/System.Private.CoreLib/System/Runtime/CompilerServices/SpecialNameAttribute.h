#pragma once

#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace SpecialNameAttributeNamespace {
CLASS(SpecialNameAttribute) : public Attribute::in {
  public: void ctor();
};
} // namespace SpecialNameAttributeNamespace
using SpecialNameAttribute = SpecialNameAttributeNamespace::SpecialNameAttribute;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
