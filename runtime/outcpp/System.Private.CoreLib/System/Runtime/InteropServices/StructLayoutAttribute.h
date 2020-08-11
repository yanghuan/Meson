#pragma once

#include <System.Private.CoreLib/System/Attribute.h>
#include <System.Private.CoreLib/System/Int32.h>

namespace System::Private::CoreLib::System {
FORWARDS(Int16)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices {
enum class CharSet : int32_t;
enum class LayoutKind : int32_t;
namespace StructLayoutAttributeNamespace {
CLASS(StructLayoutAttribute) : public Attribute::in {
  public: LayoutKind get_Value() { return Value; }
  public: void ctor(LayoutKind layoutKind);
  public: void ctor(Int16 layoutKind);
  private: LayoutKind Value;
  public: Int32 Pack;
  public: Int32 Size;
  public: CharSet CharSet;
};
} // namespace StructLayoutAttributeNamespace
using StructLayoutAttribute = StructLayoutAttributeNamespace::StructLayoutAttribute;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
