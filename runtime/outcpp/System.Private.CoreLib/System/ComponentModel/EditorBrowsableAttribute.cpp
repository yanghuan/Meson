#include "EditorBrowsableAttribute-dep.h"

#include <System.Private.CoreLib/System/ComponentModel/EditorBrowsableAttribute-dep.h>

namespace System::Private::CoreLib::System::ComponentModel::EditorBrowsableAttributeNamespace {
void EditorBrowsableAttribute___::ctor(EditorBrowsableState state) {
  State = state;
}

void EditorBrowsableAttribute___::ctor() {
}

Boolean EditorBrowsableAttribute___::Equals(Object obj) {
  if (obj == (EditorBrowsableAttribute)this) {
    return true;
  }
  EditorBrowsableAttribute editorBrowsableAttribute = rt::as<EditorBrowsableAttribute>(obj);
  if (editorBrowsableAttribute != nullptr) {
    return editorBrowsableAttribute->get_State() == State;
  }
  return false;
}

Int32 EditorBrowsableAttribute___::GetHashCode() {
  return Attribute::in::GetHashCode();
}

} // namespace System::Private::CoreLib::System::ComponentModel::EditorBrowsableAttributeNamespace
