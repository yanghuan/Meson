#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARDS(Int32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace ITupleNamespace {
CLASS(ITuple) : public Object::in {
  public: Int32 get_Length();
  public: Object get_Item(Int32 index);
  public: static constexpr rt::TypeCode code = rt::TypeCode::Interface;
};
} // namespace ITupleNamespace
using ITuple = ITupleNamespace::ITuple;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
