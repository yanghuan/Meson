#include "CurrencyWrapper-dep.h"

#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>

namespace System::Private::CoreLib::System::Runtime::InteropServices::CurrencyWrapperNamespace {
void CurrencyWrapper___::ctor(Decimal obj) {
  WrappedObject = obj;
}

void CurrencyWrapper___::ctor(Object obj) {
  if (!rt::is<Decimal>(obj)) {
    rt::throw_exception<ArgumentException>(SR::get_Arg_MustBeDecimal(), "obj");
  }
  WrappedObject = (Decimal)obj;
}

} // namespace System::Private::CoreLib::System::Runtime::InteropServices::CurrencyWrapperNamespace
