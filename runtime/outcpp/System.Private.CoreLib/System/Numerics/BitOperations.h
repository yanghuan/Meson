#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(ReadOnlySpan, T)
FORWARDS(Byte)
FORWARDS(UInt32)
FORWARDS(Int32)
FORWARDS(UInt64)
FORWARDS(Int64)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Numerics {
namespace BitOperationsNamespace {
class BitOperations {
  private: static ReadOnlySpan<Byte> get_s_TrailingZeroCountDeBruijn();
  private: static ReadOnlySpan<Byte> get_s_Log2DeBruijn();
  public: static Int32 LeadingZeroCount(UInt32 value);
  public: static Int32 LeadingZeroCount(UInt64 value);
  public: static Int32 Log2(UInt32 value);
  public: static Int32 Log2(UInt64 value);
  private: static Int32 Log2SoftwareFallback(UInt32 value);
  public: static Int32 PopCount(UInt32 value);
  public: static Int32 PopCount(UInt64 value);
  public: static Int32 TrailingZeroCount(Int32 value);
  public: static Int32 TrailingZeroCount(UInt32 value);
  public: static Int32 TrailingZeroCount(Int64 value);
  public: static Int32 TrailingZeroCount(UInt64 value);
  public: static UInt32 RotateLeft(UInt32 value, Int32 offset);
  public: static UInt64 RotateLeft(UInt64 value, Int32 offset);
  public: static UInt32 RotateRight(UInt32 value, Int32 offset);
  public: static UInt64 RotateRight(UInt64 value, Int32 offset);
};
} // namespace BitOperationsNamespace
using BitOperations = BitOperationsNamespace::BitOperations;
} // namespace System::Private::CoreLib::System::Numerics
