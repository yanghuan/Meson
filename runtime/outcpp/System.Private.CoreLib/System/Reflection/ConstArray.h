#pragma once

#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/IntPtr.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System {
FORWARDS(Byte)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection {
namespace ConstArrayNamespace {
struct ConstArray : public valueType<ConstArray> {
  public: IntPtr get_Signature();
  public: Int32 get_Length();
  public: Byte get_Item(Int32 index);
  public: Int32 m_length;
  public: IntPtr m_constArray;
};
} // namespace ConstArrayNamespace
using ConstArray = ConstArrayNamespace::ConstArray;
} // namespace System::Private::CoreLib::System::Reflection
