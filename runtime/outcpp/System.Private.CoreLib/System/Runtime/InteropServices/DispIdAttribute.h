#pragma once

#include <System.Private.CoreLib/System/Attribute.h>
#include <System.Private.CoreLib/System/Int32.h>

namespace System::Private::CoreLib::System::Runtime::InteropServices {
namespace DispIdAttributeNamespace {
CLASS(DispIdAttribute) : public Attribute::in {
  public: Int32 get_Value() { return Value; }
  public: void ctor(Int32 dispId);
  private: Int32 Value;
};
} // namespace DispIdAttributeNamespace
using DispIdAttribute = DispIdAttributeNamespace::DispIdAttribute;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
