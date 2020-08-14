#include "MemberNotNullAttribute-dep.h"

namespace System::Private::CoreLib::System::Diagnostics::CodeAnalysis::MemberNotNullAttributeNamespace {
void MemberNotNullAttribute___::ctor(String member) {
  Members = rt::newarr<Array<String>>(1);
}

void MemberNotNullAttribute___::ctor(Array<String> members) {
  Members = members;
}

} // namespace System::Private::CoreLib::System::Diagnostics::CodeAnalysis::MemberNotNullAttributeNamespace
