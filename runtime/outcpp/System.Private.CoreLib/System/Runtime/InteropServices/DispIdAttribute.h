#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Int32.h>

namespace System::Private::CoreLib::System::Runtime::InteropServices {
namespace DispIdAttributeNamespace {
CLASS(DispIdAttribute) {
  public: Int32 get_Value() { return Value; }
  public: void Ctor(Int32 dispId);
  private: Int32 Value;
};
} // namespace DispIdAttributeNamespace
using DispIdAttribute = DispIdAttributeNamespace::DispIdAttribute;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
