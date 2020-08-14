#include "MemoryMarshal-dep.h"

namespace System::Private::CoreLib::System::Runtime::InteropServices::MemoryMarshalNamespace {
Boolean MemoryMarshal::TryGetString(ReadOnlyMemory<Char> memory, String& text, Int32& start, Int32& length) {
  Int32 start2;
  Int32 length2;
  String text2 = rt::as<String>(memory.GetObjectStartLength(start2, length2));
  if (text2 != nullptr) {
    text = text2;
    start = start2;
    length = length2;
    return true;
  }
  text = nullptr;
  start = 0;
  length = 0;
  return false;
}

} // namespace System::Private::CoreLib::System::Runtime::InteropServices::MemoryMarshalNamespace
