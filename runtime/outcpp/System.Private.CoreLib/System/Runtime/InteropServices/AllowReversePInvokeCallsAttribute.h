#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Runtime::InteropServices {
namespace AllowReversePInvokeCallsAttributeNamespace {
CLASS(AllowReversePInvokeCallsAttribute) {
  public: void Ctor();
};
} // namespace AllowReversePInvokeCallsAttributeNamespace
using AllowReversePInvokeCallsAttribute = AllowReversePInvokeCallsAttributeNamespace::AllowReversePInvokeCallsAttribute;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
