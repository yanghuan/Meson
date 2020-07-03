#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Int32.h>

namespace System::Private::CoreLib::System::Runtime::InteropServices {
namespace FieldOffsetAttributeNamespace {
CLASS(FieldOffsetAttribute) {
  private: Int32 Value;
};
} // namespace FieldOffsetAttributeNamespace
using FieldOffsetAttribute = FieldOffsetAttributeNamespace::FieldOffsetAttribute;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
