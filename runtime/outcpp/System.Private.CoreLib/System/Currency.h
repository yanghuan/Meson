#pragma once

#include <System.Private.CoreLib/System/Int64.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System {
FORWARDS(Decimal)
namespace CurrencyNamespace {
struct Currency : public valueType<Currency> {
  public: explicit Currency(Decimal value);
  public: explicit Currency() {}
  public: Int64 m_value;
};
} // namespace CurrencyNamespace
using Currency = CurrencyNamespace::Currency;
} // namespace System::Private::CoreLib::System
