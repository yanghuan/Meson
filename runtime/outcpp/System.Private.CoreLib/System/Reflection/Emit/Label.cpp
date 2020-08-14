#include "Label-dep.h"

#include <System.Private.CoreLib/System/Reflection/Emit/Label-dep.h>

namespace System::Private::CoreLib::System::Reflection::Emit::LabelNamespace {
Label::Label(Int32 label) {
  m_label = label;
}

Int32 Label::GetLabelValue() {
  return m_label;
}

Int32 Label::GetHashCode() {
  return m_label;
}

Boolean Label::Equals(Object obj) {
  if (rt::is<Label>(obj)) {
    Label obj2 = (Label)obj;
    return Equals(obj2);
  }
  return false;
}

Boolean Label::Equals(Label obj) {
  return obj.m_label == m_label;
}

Boolean Label::op_Equality(Label a, Label b) {
  return a.Equals(b);
}

Boolean Label::op_Inequality(Label a, Label b) {
  return !(a == b);
}

} // namespace System::Private::CoreLib::System::Reflection::Emit::LabelNamespace
