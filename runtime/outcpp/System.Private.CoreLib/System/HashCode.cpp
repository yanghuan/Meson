#include "HashCode-dep.h"

#include <System.Private.CoreLib/Interop-dep.h>
#include <System.Private.CoreLib/System/Byte-dep.h>
#include <System.Private.CoreLib/System/NotSupportedException-dep.h>
#include <System.Private.CoreLib/System/Numerics/BitOperations-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>

namespace System::Private::CoreLib::System::HashCodeNamespace {
using namespace System::Numerics;

UInt32 HashCode::GenerateGlobalSeed() {
  UInt32 result;
  Interop::GetRandomBytes((Byte*)(&result), 4);
  return result;
}

void HashCode::Initialize(UInt32& v1, UInt32& v2, UInt32& v3, UInt32& v4) {
  v1 = (UInt32)((Int32)s_seed + -1640531535 + -2048144777);
  v2 = s_seed + 2246822519u;
  v3 = s_seed;
  v4 = s_seed - 2654435761u;
}

UInt32 HashCode::Round(UInt32 hash, UInt32 input) {
  return BitOperations::RotateLeft(hash + (UInt32)((Int32)input * -2048144777), 13) * 2654435761u;
}

UInt32 HashCode::QueueRound(UInt32 hash, UInt32 queuedValue) {
  return BitOperations::RotateLeft(hash + (UInt32)((Int32)queuedValue * -1028477379), 17) * 668265263;
}

UInt32 HashCode::MixState(UInt32 v1, UInt32 v2, UInt32 v3, UInt32 v4) {
  return BitOperations::RotateLeft(v1, 1) + BitOperations::RotateLeft(v2, 7) + BitOperations::RotateLeft(v3, 12) + BitOperations::RotateLeft(v4, 18);
}

UInt32 HashCode::MixEmptyState() {
  return s_seed + 374761393;
}

UInt32 HashCode::MixFinal(UInt32 hash) {
  hash ^= hash >> 15;
  hash *= 2246822519u;
  hash ^= hash >> 13;
  hash *= 3266489917u;
  hash ^= hash >> 16;
  return hash;
}

void HashCode::Add(Int32 value) {
  UInt32 num = _length++;
  switch (num % 4u.get()) {
    case 0u:
      _queue1 = (UInt32)value;
      return;
    case 1u:
      _queue2 = (UInt32)value;
      return;
    case 2u:
      _queue3 = (UInt32)value;
      return;
  }
  if (num == 3) {
    Initialize(_v1, _v2, _v3, _v4);
  }
  _v1 = Round(_v1, _queue1);
  _v2 = Round(_v2, _queue2);
  _v3 = Round(_v3, _queue3);
  _v4 = Round(_v4, (UInt32)value);
}

Int32 HashCode::ToHashCode() {
  UInt32 length = _length;
  UInt32 num = length % 4u;
  UInt32 num2 = (length < 4) ? MixEmptyState() : MixState(_v1, _v2, _v3, _v4);
  num2 += length * 4;
  if (num != 0) {
    num2 = QueueRound(num2, _queue1);
    if (num > 1) {
      num2 = QueueRound(num2, _queue2);
      if (num > 2) {
        num2 = QueueRound(num2, _queue3);
      }
    }
  }
  return (Int32)MixFinal(num2);
}

Int32 HashCode::GetHashCode() {
  rt::throw_exception<NotSupportedException>(SR::get_HashCode_HashCodeNotSupported());
}

Boolean HashCode::Equals(Object obj) {
  rt::throw_exception<NotSupportedException>(SR::get_HashCode_EqualityNotSupported());
}

void HashCode::ctor_static() {
  s_seed = GenerateGlobalSeed();
}

} // namespace System::Private::CoreLib::System::HashCodeNamespace
