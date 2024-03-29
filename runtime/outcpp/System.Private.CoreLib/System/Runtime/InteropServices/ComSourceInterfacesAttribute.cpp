#include "ComSourceInterfacesAttribute-dep.h"

namespace System::Private::CoreLib::System::Runtime::InteropServices::ComSourceInterfacesAttributeNamespace {
void ComSourceInterfacesAttribute___::ctor(String sourceInterfaces) {
  Value = sourceInterfaces;
}

void ComSourceInterfacesAttribute___::ctor(Type sourceInterface) {
  Value = sourceInterface->get_FullName();
}

void ComSourceInterfacesAttribute___::ctor(Type sourceInterface1, Type sourceInterface2) {
  Value = sourceInterface1->get_FullName() + "\0" + sourceInterface2->get_FullName();
}

void ComSourceInterfacesAttribute___::ctor(Type sourceInterface1, Type sourceInterface2, Type sourceInterface3) {
  Value = sourceInterface1->get_FullName() + "\0" + sourceInterface2->get_FullName() + "\0" + sourceInterface3->get_FullName();
}

void ComSourceInterfacesAttribute___::ctor(Type sourceInterface1, Type sourceInterface2, Type sourceInterface3, Type sourceInterface4) {
  Value = sourceInterface1->get_FullName() + "\0" + sourceInterface2->get_FullName() + "\0" + sourceInterface3->get_FullName() + "\0" + sourceInterface4->get_FullName();
}

} // namespace System::Private::CoreLib::System::Runtime::InteropServices::ComSourceInterfacesAttributeNamespace
