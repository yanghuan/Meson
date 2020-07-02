#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(ReadOnlyMemory, T)
FORWARDS(Char)
FORWARD(String)
FORWARDS(Int32)
FORWARDS(Boolean)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices {
namespace MemoryMarshalNamespace {
class MemoryMarshal {
  public: static Boolean TryGetString(ReadOnlyMemory<Char> memory, String& text, Int32& start, Int32& length);
};
} // namespace MemoryMarshalNamespace
using MemoryMarshal = MemoryMarshalNamespace::MemoryMarshal;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
