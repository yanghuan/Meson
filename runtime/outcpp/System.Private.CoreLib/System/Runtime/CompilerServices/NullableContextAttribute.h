#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Attribute.h>
#include <System.Private.CoreLib/System/Byte.h>

namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace NullableContextAttributeNamespace {
CLASS(NullableContextAttribute) : public Attribute::in {
  public: void Ctor(Byte _);
  public: Byte Flag;
};
} // namespace NullableContextAttributeNamespace
using NullableContextAttribute = NullableContextAttributeNamespace::NullableContextAttribute;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
