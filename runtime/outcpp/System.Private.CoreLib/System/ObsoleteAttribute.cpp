#include "ObsoleteAttribute-dep.h"

namespace System::Private::CoreLib::System::ObsoleteAttributeNamespace {
void ObsoleteAttribute___::ctor() {
  Message = nullptr;
  IsError = false;
}

void ObsoleteAttribute___::ctor(String message) {
  Message = message;
  IsError = false;
}

void ObsoleteAttribute___::ctor(String message, Boolean error) {
  Message = message;
  IsError = error;
}

} // namespace System::Private::CoreLib::System::ObsoleteAttributeNamespace
