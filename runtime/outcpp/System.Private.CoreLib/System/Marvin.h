#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Byte)
FORWARDS(Char)
FORWARDS(Int32)
FORWARDS(ReadOnlySpan, T)
FORWARDS(UInt32)
FORWARDS(UInt64)
namespace MarvinNamespace {
class Marvin {
  public: static UInt64 get_DefaultSeed();
  public: static Int32 ComputeHash32(ReadOnlySpan<Byte> data, UInt64 seed);
  public: static Int32 ComputeHash32(Byte& data, UInt32 count, UInt32 p0, UInt32 p1);
  private: static void Block(UInt32& rp0, UInt32& rp1);
  private: static UInt64 GenerateSeed();
  public: static Int32 ComputeHash32OrdinalIgnoreCase(Char& data, Int32 count, UInt32 p0, UInt32 p1);
  private: static Int32 ComputeHash32OrdinalIgnoreCaseSlow(Char& data, Int32 count, UInt32 p0, UInt32 p1);
  private: static void cctor();
  private: static UInt64 DefaultSeed;
};
} // namespace MarvinNamespace
using Marvin = MarvinNamespace::Marvin;
} // namespace System::Private::CoreLib::System
