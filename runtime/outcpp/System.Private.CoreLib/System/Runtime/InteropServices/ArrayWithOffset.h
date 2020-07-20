#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Int32.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices {
namespace ArrayWithOffsetNamespace {
struct ArrayWithOffset : public rt::ValueType<ArrayWithOffset> {
  public: void Ctor(Object array, Int32 offset);
  public: Object GetArray();
  public: Int32 GetOffset();
  public: Int32 GetHashCode();
  public: Boolean Equals(Object obj);
  public: Boolean Equals(ArrayWithOffset obj);
  public: static Boolean op_Equality(ArrayWithOffset a, ArrayWithOffset b);
  public: static Boolean op_Inequality(ArrayWithOffset a, ArrayWithOffset b);
  public: void Ctor();
  private: Object m_array;
  private: Int32 m_offset;
  private: Int32 m_count;
};
} // namespace ArrayWithOffsetNamespace
using ArrayWithOffset = ArrayWithOffsetNamespace::ArrayWithOffset;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
