#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Byte)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace NullableAttributeNamespace {
CLASS(NullableAttribute) {
  public: void Ctor(Byte _);
  public: void Ctor(Array<Byte> _);
  public: Array<Byte> NullableFlags;
};
} // namespace NullableAttributeNamespace
using NullableAttribute = NullableAttributeNamespace::NullableAttribute;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
