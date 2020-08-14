#include "InterfaceTypeAttribute-dep.h"

namespace System::Private::CoreLib::System::Runtime::InteropServices::InterfaceTypeAttributeNamespace {
void InterfaceTypeAttribute___::ctor(ComInterfaceType interfaceType) {
  Value = interfaceType;
}

void InterfaceTypeAttribute___::ctor(Int16 interfaceType) {
  Value = (ComInterfaceType)interfaceType;
}

} // namespace System::Private::CoreLib::System::Runtime::InteropServices::InterfaceTypeAttributeNamespace
