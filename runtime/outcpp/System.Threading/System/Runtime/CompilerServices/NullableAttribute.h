#pragma once

#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Byte)
} // namespace System::Private::CoreLib::System
namespace System::Threading::System::Runtime::CompilerServices {
namespace NullableAttributeNamespace {
using namespace ::System::Private::CoreLib::System;
CLASS(NullableAttribute) : public Attribute::in {
  public: void ctor(Byte _);
  public: void ctor(Array<Byte> _);
  public: Array<Byte> NullableFlags;
};
} // namespace NullableAttributeNamespace
using NullableAttribute = NullableAttributeNamespace::NullableAttribute;
} // namespace System::Threading::System::Runtime::CompilerServices
