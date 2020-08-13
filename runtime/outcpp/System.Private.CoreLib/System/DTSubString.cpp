#include "DTSubString-dep.h"

namespace System::Private::CoreLib::System::DTSubStringNamespace {
Char DTSubString::get_Item(Int32 relativeIndex) {
  return s[index + relativeIndex];
}

} // namespace System::Private::CoreLib::System::DTSubStringNamespace
