#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Decimal.h>

namespace System::Private::CoreLib::System {
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices {
namespace CurrencyWrapperNamespace {
CLASS(CurrencyWrapper) {
  public: Decimal get_WrappedObject() { return WrappedObject; }
  public: void Ctor(Decimal obj);
  public: void Ctor(Object obj);
  private: Decimal WrappedObject;
};
} // namespace CurrencyWrapperNamespace
using CurrencyWrapper = CurrencyWrapperNamespace::CurrencyWrapper;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
