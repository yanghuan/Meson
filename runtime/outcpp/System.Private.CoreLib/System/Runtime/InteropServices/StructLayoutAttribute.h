#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Int32.h>

namespace System::Private::CoreLib::System::Runtime::InteropServices {
enum class CharSet;
enum class LayoutKind;
namespace StructLayoutAttributeNamespace {
CLASS(StructLayoutAttribute) {
  public: LayoutKind get_Value() { return Value; }
  private: LayoutKind Value;
  public: Int32 Pack;
  public: Int32 Size;
  public: CharSet CharSet;
};
} // namespace StructLayoutAttributeNamespace
using StructLayoutAttribute = StructLayoutAttributeNamespace::StructLayoutAttribute;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
