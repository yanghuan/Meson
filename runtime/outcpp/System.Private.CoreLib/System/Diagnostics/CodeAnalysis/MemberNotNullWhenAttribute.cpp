#include "MemberNotNullWhenAttribute-dep.h"

namespace System::Private::CoreLib::System::Diagnostics::CodeAnalysis::MemberNotNullWhenAttributeNamespace {
void MemberNotNullWhenAttribute___::ctor(Boolean returnValue, String member) {
  ReturnValue = returnValue;
  Members = rt::newarr<Array<String>>(1);
}

void MemberNotNullWhenAttribute___::ctor(Boolean returnValue, Array<String> members) {
  ReturnValue = returnValue;
  Members = members;
}

} // namespace System::Private::CoreLib::System::Diagnostics::CodeAnalysis::MemberNotNullWhenAttributeNamespace
