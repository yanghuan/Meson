#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Int32.h>

namespace System::Private::CoreLib::System::Runtime::InteropServices {
enum class CharSet;
namespace StructLayoutAttributeNamespace {
CLASS(StructLayoutAttribute) {
  public: Int32 Pack;
  public: Int32 Size;
  public: CharSet CharSet;
};
} // namespace StructLayoutAttributeNamespace
using StructLayoutAttribute = StructLayoutAttributeNamespace::StructLayoutAttribute;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
