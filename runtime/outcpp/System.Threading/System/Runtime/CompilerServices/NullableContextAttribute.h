#pragma once

#include <System.Private.CoreLib/System/Attribute.h>
#include <System.Private.CoreLib/System/Byte.h>

namespace System::Threading::System::Runtime::CompilerServices {
namespace NullableContextAttributeNamespace {
using namespace ::System::Private::CoreLib::System;
CLASS(NullableContextAttribute) : public Attribute::in {
  public: void ctor(Byte _);
  public: Byte Flag;
};
} // namespace NullableContextAttributeNamespace
using NullableContextAttribute = NullableContextAttributeNamespace::NullableContextAttribute;
} // namespace System::Threading::System::Runtime::CompilerServices
