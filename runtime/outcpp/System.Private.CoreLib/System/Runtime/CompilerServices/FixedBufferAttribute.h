#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Int32.h>

namespace System::Private::CoreLib::System {
FORWARD(Type)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace FixedBufferAttributeNamespace {
CLASS(FixedBufferAttribute) {
  private: Type ElementType;
  private: Int32 Length;
};
} // namespace FixedBufferAttributeNamespace
using FixedBufferAttribute = FixedBufferAttributeNamespace::FixedBufferAttribute;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
