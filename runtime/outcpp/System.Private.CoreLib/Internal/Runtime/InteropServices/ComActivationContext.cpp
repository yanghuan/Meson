#include "ComActivationContext-dep.h"

#include <System.Private.CoreLib/Internal/Runtime/InteropServices/ComActivationContext-dep.h>

namespace System::Private::CoreLib::Internal::Runtime::InteropServices::ComActivationContextNamespace {
ComActivationContext ComActivationContext::Create(ComActivationContextInternal& cxtInt) {
  return ComActivationContext();
}

} // namespace System::Private::CoreLib::Internal::Runtime::InteropServices::ComActivationContextNamespace
