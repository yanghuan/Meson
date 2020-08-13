#include "Currency-dep.h"

namespace System::Private::CoreLib::System::CurrencyNamespace {
Currency::Currency(Decimal value) {
  m_value = Decimal::ToOACurrency(value);
}

} // namespace System::Private::CoreLib::System::CurrencyNamespace
