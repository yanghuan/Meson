#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(Int32)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::ComponentModel {
namespace EditorBrowsableAttributeNamespace {
CLASS(EditorBrowsableAttribute) {
  public: Boolean Equals(Object obj);
  public: Int32 GetHashCode();
};
} // namespace EditorBrowsableAttributeNamespace
using EditorBrowsableAttribute = EditorBrowsableAttributeNamespace::EditorBrowsableAttribute;
} // namespace System::Private::CoreLib::System::ComponentModel
