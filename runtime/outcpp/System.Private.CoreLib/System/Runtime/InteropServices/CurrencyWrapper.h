#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Decimal.h>

namespace System::Private::CoreLib::System::Runtime::InteropServices {
namespace CurrencyWrapperNamespace {
CLASS(CurrencyWrapper) {
  public: Decimal get_WrappedObject() { return WrappedObject; }
  private: Decimal WrappedObject;
};
} // namespace CurrencyWrapperNamespace
using CurrencyWrapper = CurrencyWrapperNamespace::CurrencyWrapper;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
