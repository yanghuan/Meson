#include "ClassInterfaceAttribute-dep.h"

namespace System::Private::CoreLib::System::Runtime::InteropServices::ClassInterfaceAttributeNamespace {
void ClassInterfaceAttribute___::ctor(ClassInterfaceType classInterfaceType) {
  Value = classInterfaceType;
}

void ClassInterfaceAttribute___::ctor(Int16 classInterfaceType) {
  Value = (ClassInterfaceType)classInterfaceType;
}

} // namespace System::Private::CoreLib::System::Runtime::InteropServices::ClassInterfaceAttributeNamespace
