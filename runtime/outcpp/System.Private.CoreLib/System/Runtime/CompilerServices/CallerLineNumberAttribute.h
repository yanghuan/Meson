#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace CallerLineNumberAttributeNamespace {
CLASS(CallerLineNumberAttribute) {
  public: void Ctor();
};
} // namespace CallerLineNumberAttributeNamespace
using CallerLineNumberAttribute = CallerLineNumberAttributeNamespace::CallerLineNumberAttribute;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
