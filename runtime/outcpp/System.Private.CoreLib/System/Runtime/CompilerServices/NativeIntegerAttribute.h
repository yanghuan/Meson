#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace NativeIntegerAttributeNamespace {
CLASS(NativeIntegerAttribute) {
  public: void Ctor();
  public: Array<Boolean> TransformFlags;
};
} // namespace NativeIntegerAttributeNamespace
using NativeIntegerAttribute = NativeIntegerAttributeNamespace::NativeIntegerAttribute;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
