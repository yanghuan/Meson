#pragma once

#include <System.Private.CoreLib/System/Decimal.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Runtime::InteropServices {
namespace CurrencyWrapperNamespace {
CLASS(CurrencyWrapper) : public Object::in {
  public: Decimal get_WrappedObject() { return WrappedObject; }
  public: void Ctor(Decimal obj);
  public: void Ctor(Object obj);
  private: Decimal WrappedObject;
};
} // namespace CurrencyWrapperNamespace
using CurrencyWrapper = CurrencyWrapperNamespace::CurrencyWrapper;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
