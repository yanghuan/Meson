#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARDS(Memory, T)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Buffers {
namespace IMemoryOwnerNamespace {
CLASS(IMemoryOwner, T) : public Object::in {
  public: Memory<T> get_Memory();
};
} // namespace IMemoryOwnerNamespace
template <class T>
using IMemoryOwner = IMemoryOwnerNamespace::IMemoryOwner<T>;
} // namespace System::Private::CoreLib::System::Buffers
