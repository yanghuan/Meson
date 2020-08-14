#include "Object-dep.h"

#include <System.Private.CoreLib/System/Buffer-dep.h>
#include <System.Private.CoreLib/System/Byte-dep.h>
#include <System.Private.CoreLib/System/Object-dep.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/RuntimeHelpers-dep.h>
#include <System.Private.CoreLib/System/UIntPtr-dep.h>

namespace System::Private::CoreLib::System::ObjectNamespace {
using namespace System::Runtime::CompilerServices;

Object Object___::MemberwiseClone() {
  Object obj = RuntimeHelpers::AllocateUninitializedClone((Object)this);
  UIntPtr rawObjectDataSize = RuntimeHelpers::GetRawObjectDataSize(obj);
  Byte& rawData = RuntimeHelpers::GetRawData((Object)this);
  Byte& rawData2 = RuntimeHelpers::GetRawData(obj);
  if (RuntimeHelpers::GetMethodTable(obj)->get_ContainsGCPointers()) {
    Buffer::BulkMoveWithWriteBarrier(rawData2, rawData, rawObjectDataSize);
  } else {
    Buffer::Memmove<Byte>(rawData2, rawData, rawObjectDataSize);
  }
  return obj;
}

void Object___::ctor() {
}

void Object___::Finalize() {
}

String Object___::ToString() {
  return GetType()->ToString();
}

Boolean Object___::Equals(Object obj) {
  return RuntimeHelpers::Equals((Object)this, obj);
}

Boolean Object___::Equals(Object objA, Object objB) {
  if (objA == objB) {
    return true;
  }
  if (objA == nullptr || objB == nullptr) {
    return false;
  }
  return objA->Equals(objB);
}

Boolean Object___::ReferenceEquals(Object objA, Object objB) {
  return objA == objB;
}

Int32 Object___::GetHashCode() {
  return RuntimeHelpers::GetHashCode((Object)this);
}

} // namespace System::Private::CoreLib::System::ObjectNamespace
