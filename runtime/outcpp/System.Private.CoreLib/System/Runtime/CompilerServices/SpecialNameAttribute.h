#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace SpecialNameAttributeNamespace {
CLASS(SpecialNameAttribute) : public Attribute::in {
  public: void Ctor();
};
} // namespace SpecialNameAttributeNamespace
using SpecialNameAttribute = SpecialNameAttributeNamespace::SpecialNameAttribute;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
