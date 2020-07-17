#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Int32.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Byte)
FORWARDS(Double)
FORWARDS(Span, T)
namespace RandomNamespace {
CLASS(Random) {
  public: void Ctor();
  public: void Ctor(Int32 Seed);
  protected: Double Sample();
  private: Int32 InternalSample();
  private: static Int32 GenerateSeed();
  private: static Int32 GenerateGlobalSeed();
  public: Int32 Next();
  private: Double GetSampleForLargeRange();
  public: Int32 Next(Int32 minValue, Int32 maxValue);
  public: Int32 Next(Int32 maxValue);
  public: Double NextDouble();
  public: void NextBytes(Array<Byte> buffer);
  public: void NextBytes(Span<Byte> buffer);
  private: static void SCtor();
  private: Int32 _inext;
  private: Int32 _inextp;
  private: Array<Int32> _seedArray;
  private: static Random t_threadRandom;
  private: static Random s_globalRandom;
};
} // namespace RandomNamespace
using Random = RandomNamespace::Random;
} // namespace System::Private::CoreLib::System
