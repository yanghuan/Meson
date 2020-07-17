#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Int64.h>

namespace System::Private::CoreLib::System {
FORWARDS(Decimal)
namespace CurrencyNamespace {
struct Currency {
  public: void Ctor(Decimal value);
  public: void Ctor();
  public: Int64 m_value;
};
} // namespace CurrencyNamespace
using Currency = CurrencyNamespace::Currency;
} // namespace System::Private::CoreLib::System
