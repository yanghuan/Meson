#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/UInt32.h>

namespace System::Private::CoreLib::System {
FORWARDS(Int32)
FORWARD(Object)
FORWARDS(Boolean)
namespace HashCodeNamespace {
struct HashCode {
  private: static UInt32 GenerateGlobalSeed();
  private: static void Initialize(UInt32& v1, UInt32& v2, UInt32& v3, UInt32& v4);
  private: static UInt32 Round(UInt32 hash, UInt32 input);
  private: static UInt32 QueueRound(UInt32 hash, UInt32 queuedValue);
  private: static UInt32 MixState(UInt32 v1, UInt32 v2, UInt32 v3, UInt32 v4);
  private: static UInt32 MixEmptyState();
  private: static UInt32 MixFinal(UInt32 hash);
  private: void Add(Int32 value);
  public: Int32 ToHashCode();
  public: Int32 GetHashCode();
  public: Boolean Equals(Object obj);
  private: static UInt32 s_seed;
  private: UInt32 _v1;
  private: UInt32 _v2;
  private: UInt32 _v3;
  private: UInt32 _v4;
  private: UInt32 _queue1;
  private: UInt32 _queue2;
  private: UInt32 _queue3;
  private: UInt32 _length;
};
} // namespace HashCodeNamespace
using HashCode = HashCodeNamespace::HashCode;
} // namespace System::Private::CoreLib::System
