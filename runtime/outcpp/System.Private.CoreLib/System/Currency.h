#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Int64.h>

namespace System::Private::CoreLib::System {
namespace CurrencyNamespace {
struct Currency {
  public: Int64 m_value;
};
} // namespace CurrencyNamespace
using Currency = CurrencyNamespace::Currency;
} // namespace System::Private::CoreLib::System
