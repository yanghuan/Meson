#include "HashCode-dep.h"

namespace System::Private::CoreLib::System::HashCodeNamespace {
UInt32 HashCode::GenerateGlobalSeed() {
  return UInt32();
};
void HashCode::Initialize(UInt32& v1, UInt32& v2, UInt32& v3, UInt32& v4) {
  return void();
};
UInt32 HashCode::Round(UInt32 hash, UInt32 input) {
  return UInt32();
};
UInt32 HashCode::QueueRound(UInt32 hash, UInt32 queuedValue) {
  return UInt32();
};
UInt32 HashCode::MixState(UInt32 v1, UInt32 v2, UInt32 v3, UInt32 v4) {
  return UInt32();
};
UInt32 HashCode::MixEmptyState() {
  return UInt32();
};
UInt32 HashCode::MixFinal(UInt32 hash) {
  return UInt32();
};
void HashCode::Add(Int32 value) {
  return void();
};
Int32 HashCode::ToHashCode() {
  return Int32();
};
Int32 HashCode::GetHashCode() {
  return Int32();
};
Boolean HashCode::Equals(Object obj) {
  return Boolean();
};
} // namespace System::Private::CoreLib::System::HashCodeNamespace
