#include "_PrivateImplementationDetails_-dep.h"

#include <System.Private.CoreLib/System/Int32-dep.h>

namespace System::Private::CoreLib::_PrivateImplementationDetails_Namespace {
using namespace System;

UInt32 _PrivateImplementationDetails____::ComputeStringHash(String s) {
  UInt32 num;
  if (s != nullptr) {
    num = 2166136261u;
    for (Int32 i = 0; i < s->get_Length(); i++) {
      num = (s[i] ^ num) * 16777619;
    }
  }
  return num;
}

} // namespace System::Private::CoreLib::_PrivateImplementationDetails_Namespace
