#include "ByteEqualityComparer-dep.h"

namespace System::Private::CoreLib::System::Collections::Generic::ByteEqualityComparerNamespace {
Boolean ByteEqualityComparer___::Equals(Byte x, Byte y) {
  return x == y;
}

Int32 ByteEqualityComparer___::GetHashCode(Byte b) {
  return b.GetHashCode();
}

Boolean ByteEqualityComparer___::Equals(Object obj) {
  if (obj != nullptr) {
    return GetType() == obj->GetType();
  }
  return false;
}

Int32 ByteEqualityComparer___::GetHashCode() {
  return GetType()->GetHashCode();
}

void ByteEqualityComparer___::ctor() {
}

} // namespace System::Private::CoreLib::System::Collections::Generic::ByteEqualityComparerNamespace
