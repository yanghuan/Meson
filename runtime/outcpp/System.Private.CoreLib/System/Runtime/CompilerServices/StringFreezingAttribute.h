#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace StringFreezingAttributeNamespace {
CLASS(StringFreezingAttribute) {
  public: void Ctor();
};
} // namespace StringFreezingAttributeNamespace
using StringFreezingAttribute = StringFreezingAttributeNamespace::StringFreezingAttribute;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
