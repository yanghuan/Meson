#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Attribute.h>
#include <System.Private.CoreLib/System/Int32.h>

namespace System::Private::CoreLib::System {
FORWARDS(Int16)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices {
enum class CharSet;
enum class LayoutKind;
namespace StructLayoutAttributeNamespace {
CLASS(StructLayoutAttribute) : public Attribute::in {
  public: LayoutKind get_Value() { return Value; }
  public: void Ctor(LayoutKind layoutKind);
  public: void Ctor(Int16 layoutKind);
  private: LayoutKind Value;
  public: Int32 Pack;
  public: Int32 Size;
  public: CharSet CharSet;
};
} // namespace StructLayoutAttributeNamespace
using StructLayoutAttribute = StructLayoutAttributeNamespace::StructLayoutAttribute;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
