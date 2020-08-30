#pragma once

#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
} // namespace System::Private::CoreLib::System
namespace Test::System::Runtime::CompilerServices {
namespace NativeIntegerAttributeNamespace {
using namespace ::System::Private::CoreLib::System;
CLASS(NativeIntegerAttribute) : public Attribute::in {
  public: void ctor();
  public: void ctor(Array<Boolean> _);
  public: Array<Boolean> TransformFlags;
};
} // namespace NativeIntegerAttributeNamespace
using NativeIntegerAttribute = NativeIntegerAttributeNamespace::NativeIntegerAttribute;
} // namespace Test::System::Runtime::CompilerServices
