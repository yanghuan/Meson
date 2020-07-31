#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System::Runtime::InteropServices {
namespace AllowReversePInvokeCallsAttributeNamespace {
CLASS(AllowReversePInvokeCallsAttribute) : public Attribute::in {
  public: void Ctor();
};
} // namespace AllowReversePInvokeCallsAttributeNamespace
using AllowReversePInvokeCallsAttribute = AllowReversePInvokeCallsAttributeNamespace::AllowReversePInvokeCallsAttribute;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
