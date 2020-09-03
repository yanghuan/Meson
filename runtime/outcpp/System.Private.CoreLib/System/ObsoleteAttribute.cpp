#include "ObsoleteAttribute-dep.h"

namespace System::Private::CoreLib::System::ObsoleteAttributeNamespace {
void ObsoleteAttribute___::ctor() {
}

void ObsoleteAttribute___::ctor(String message) {
  Message = message;
}

void ObsoleteAttribute___::ctor(String message, Boolean error) {
  Message = message;
  IsError = error;
}

} // namespace System::Private::CoreLib::System::ObsoleteAttributeNamespace
