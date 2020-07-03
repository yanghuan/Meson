#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Int32.h>

namespace System::Private::CoreLib::System::Runtime::InteropServices {
namespace DispIdAttributeNamespace {
CLASS(DispIdAttribute) {
  private: Int32 Value;
};
} // namespace DispIdAttributeNamespace
using DispIdAttribute = DispIdAttributeNamespace::DispIdAttribute;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
