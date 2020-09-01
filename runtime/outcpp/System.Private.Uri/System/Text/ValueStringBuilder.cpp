#include "ValueStringBuilder-dep.h"

#include <System.Private.CoreLib/System/Buffers/ArrayPool-dep.h>
#include <System.Private.CoreLib/System/Math-dep.h>
#include <System.Private.CoreLib/System/UInt32-dep.h>

namespace System::Private::Uri::System::Text::ValueStringBuilderNamespace {
using namespace ::System::Private::CoreLib::System;
using namespace ::System::Private::CoreLib::System::Buffers;

Int32 ValueStringBuilder::get_Length() {
  return _pos;
}

ValueStringBuilder::ValueStringBuilder(Span<Char> initialBuffer) {
  _arrayToReturnToPool = nullptr;
  _chars = initialBuffer;
  _pos = 0;
}

ValueStringBuilder::ValueStringBuilder(Int32 initialCapacity) {
  _arrayToReturnToPool = ArrayPool<Char>::in::get_Shared()->Rent(initialCapacity);
  _chars = _arrayToReturnToPool;
  _pos = 0;
}

void ValueStringBuilder::EnsureCapacity(Int32 capacity) {
  if (capacity > _chars.get_Length()) {
    Grow(capacity - _pos);
  }
}

String ValueStringBuilder::ToString() {
  String result = _chars.Slice(0, _pos).ToString();
  Dispose();
  return result;
}

ReadOnlySpan<Char> ValueStringBuilder::AsSpan() {
  return _chars.Slice(0, _pos);
}

ReadOnlySpan<Char> ValueStringBuilder::AsSpan(Int32 start) {
  return _chars.Slice(start, _pos - start);
}

Boolean ValueStringBuilder::TryCopyTo(Span<Char> destination, Int32& charsWritten) {
  if (_chars.Slice(0, _pos).TryCopyTo(destination)) {
    charsWritten = _pos;
    Dispose();
    return true;
  }
  charsWritten = 0;
  Dispose();
  return false;
}

void ValueStringBuilder::Append(Char c) {
  Int32 pos = _pos;
  if ((UInt32)pos < (UInt32)_chars.get_Length()) {
    _chars[pos] = c;
    _pos = pos + 1;
  } else {
    GrowAndAppend(c);
  }
}

void ValueStringBuilder::Append(ReadOnlySpan<Char> value) {
  Int32 pos = _pos;
  if (pos > _chars.get_Length() - value.get_Length()) {
    Grow(value.get_Length());
  }
  value.CopyTo(_chars.Slice(_pos));
  _pos += value.get_Length();
}

Span<Char> ValueStringBuilder::AppendSpan(Int32 length) {
  Int32 pos = _pos;
  if (pos > _chars.get_Length() - length) {
    Grow(length);
  }
  _pos = pos + length;
  return _chars.Slice(pos, length);
}

void ValueStringBuilder::GrowAndAppend(Char c) {
  Grow(1);
  Append(c);
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
  *this = rt::default__;
  if (arrayToReturnToPool != nullptr) {
    ArrayPool<Char>::in::get_Shared()->Return(arrayToReturnToPool);
  }
}

} // namespace System::Private::Uri::System::Text::ValueStringBuilderNamespace
