#include "BStrWrapper-dep.h"

namespace System::Private::CoreLib::System::Runtime::InteropServices::BStrWrapperNamespace {
void BStrWrapper___::ctor(String value) {
  WrappedObject = value;
}

void BStrWrapper___::ctor(Object value) {
  WrappedObject = (String)value;
}

} // namespace System::Private::CoreLib::System::Runtime::InteropServices::BStrWrapperNamespace
