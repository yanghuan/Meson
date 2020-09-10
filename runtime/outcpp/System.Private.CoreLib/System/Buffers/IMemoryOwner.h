#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARD(IDisposable)
FORWARDS(Memory, T)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Buffers {
namespace IMemoryOwnerNamespace {
CLASS(IMemoryOwner, T) : public object {
  public: using interface = rt::TypeList<IDisposable>;
  public: Memory<T> get_Memory();
  public: void Dispose();
  public: static constexpr rt::TypeCode code = rt::TypeCode::Interface;
};
} // namespace IMemoryOwnerNamespace
template <class T>
using IMemoryOwner = IMemoryOwnerNamespace::IMemoryOwner<T>;
} // namespace System::Private::CoreLib::System::Buffers
