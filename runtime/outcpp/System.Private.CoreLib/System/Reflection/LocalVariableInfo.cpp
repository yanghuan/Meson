#include "LocalVariableInfo-dep.h"

namespace System::Private::CoreLib::System::Reflection::LocalVariableInfoNamespace {
Type LocalVariableInfo___::get_LocalType() {
  return nullptr;
}

Int32 LocalVariableInfo___::get_LocalIndex() {
  return 0;
}

Boolean LocalVariableInfo___::get_IsPinned() {
  return false;
}

void LocalVariableInfo___::ctor() {
}

String LocalVariableInfo___::ToString() {
  String text = get_LocalType()->ToString() + " (" + get_LocalIndex() + ")";
  if (get_IsPinned()) {
    text += " (pinned)";
  }
  return text;
}

} // namespace System::Private::CoreLib::System::Reflection::LocalVariableInfoNamespace
