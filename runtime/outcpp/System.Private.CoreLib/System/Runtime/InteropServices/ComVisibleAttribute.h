#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Boolean.h>

namespace System::Private::CoreLib::System::Runtime::InteropServices {
namespace ComVisibleAttributeNamespace {
CLASS(ComVisibleAttribute) {
  public: Boolean get_Value() { return Value; }
  public: void Ctor(Boolean visibility);
  private: Boolean Value;
};
} // namespace ComVisibleAttributeNamespace
using ComVisibleAttribute = ComVisibleAttributeNamespace::ComVisibleAttribute;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
