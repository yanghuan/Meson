#include "ValueStringBuilder-dep.h"

#include <System.Console/System/Text/ValueStringBuilder-dep.h>
#include <System.Private.CoreLib/System/Buffers/ArrayPool-dep.h>
#include <System.Private.CoreLib/System/Math-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/MemoryMarshal-dep.h>

namespace System::Console::System::Text::ValueStringBuilderNamespace {
using namespace ::System::Private::CoreLib::System;
using namespace ::System::Private::CoreLib::System::Buffers;
using namespace ::System::Private::CoreLib::System::Runtime::InteropServices;

void ValueStringBuilder::set_Length(Int32 value) {
  _pos = value;
}

Int32 ValueStringBuilder::get_Capacity() {
  return _chars.get_Length();
}

ValueStringBuilder::ValueStringBuilder(Span<Char> initialBuffer) {
  _arrayToReturnToPool = nullptr;
  _chars = initialBuffer;
  _pos = 0;
}

void ValueStringBuilder::EnsureCapacity(Int32 capacity) {
  if (capacity > _chars.get_Length()) {
    Grow(capacity - _pos);
  }
}

Char& ValueStringBuilder::GetPinnableReference() {
  return MemoryMarshal::GetReference(_chars);
}

String ValueStringBuilder::ToString() {
  String result = _chars.Slice(0, _pos).ToString();
  Dispose();
  return result;
}

void ValueStringBuilder::Grow(Int32 additionalCapacityBeyondPos) {
  Array<Char> array = ArrayPool<Char>::in::get_Shared()->Rent(Math::Max(_pos + additionalCapacityBeyondPos, _chars.get_Length() * 2));
  _chars.Slice(0, _pos).CopyTo(array);
  Array<Char> arrayToReturnToPool = _arrayToReturnToPool;
  _chars = (_arrayToReturnToPool = array);
  if (arrayToReturnToPool != nullptr) {
    ArrayPool<Char>::in::get_Shared()->Return(arrayToReturnToPool);
  }
}

void ValueStringBuilder::Dispose() {
  Array<Char> arrayToReturnToPool = _arrayToReturnToPool;
  *this = ValueStringBuilder();
  if (arrayToReturnToPool != nullptr) {
    ArrayPool<Char>::in::get_Shared()->Return(arrayToReturnToPool);
  }
}

} // namespace System::Console::System::Text::ValueStringBuilderNamespace
