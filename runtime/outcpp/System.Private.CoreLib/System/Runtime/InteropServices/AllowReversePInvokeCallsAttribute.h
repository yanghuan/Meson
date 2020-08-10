#pragma once

#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System::Runtime::InteropServices {
namespace AllowReversePInvokeCallsAttributeNamespace {
CLASS(AllowReversePInvokeCallsAttribute) : public Attribute::in {
  public: void ctor();
};
} // namespace AllowReversePInvokeCallsAttributeNamespace
using AllowReversePInvokeCallsAttribute = AllowReversePInvokeCallsAttributeNamespace::AllowReversePInvokeCallsAttribute;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
