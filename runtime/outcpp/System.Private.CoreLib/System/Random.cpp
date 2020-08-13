#include "Random-dep.h"

#include <System.Private.CoreLib/Interop-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/Byte-dep.h>
#include <System.Private.CoreLib/System/Int64-dep.h>
#include <System.Private.CoreLib/System/Random-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>

namespace System::Private::CoreLib::System::RandomNamespace {
void Random___::ctor() {
}

void Random___::ctor(Int32 Seed) {
  _seedArray = rt::newarr<Array<Int32>>(56);
}

Double Random___::Sample() {
  return (Double)InternalSample() * 4.656612875245797E-10;
}

Int32 Random___::InternalSample() {
  Int32 inext = _inext;
  Int32 inextp = _inextp;
  if (++inext >= 56) {
    inext = 1;
  }
  if (++inextp >= 56) {
    inextp = 1;
  }
  Int32 num = _seedArray[inext] - _seedArray[inextp];
  if (num == Int32::MaxValue) {
    num--;
  }
  if (num < 0) {
    num += Int32::MaxValue;
  }
  _seedArray[inext] = num;
  _inext = inext;
  _inextp = inextp;
  return num;
}

Int32 Random___::GenerateSeed() {
  Random random = t_threadRandom;
  if (random == nullptr) {
    Int32 seed;
  }
  return random->Next();
}

Int32 Random___::GenerateGlobalSeed() {
  Int32 result;
  Interop::GetRandomBytes((Byte*)(&result), 4);
  return result;
}

Int32 Random___::Next() {
  return InternalSample();
}

Double Random___::GetSampleForLargeRange() {
  Int32 num = InternalSample();
  if ((InternalSample() % 2 == 0) ? true : false) {
  }
  Double num2 = num;
  num2 += 2147483646;
  return num2 / 4294967293;
}

Int32 Random___::Next(Int32 minValue, Int32 maxValue) {
  if (minValue > maxValue) {
    rt::throw_exception<ArgumentOutOfRangeException>("minValue", SR::Format(SR::get_Argument_MinMaxValue(), "minValue", "maxValue"));
  }
  Int64 num = (Int64)maxValue - (Int64)minValue;
  if (num <= Int32::MaxValue) {
    return (Int32)(Sample() * (Double)num) + minValue;
  }
  return (Int32)((Int64)(GetSampleForLargeRange() * (Double)num) + minValue);
}

Int32 Random___::Next(Int32 maxValue) {
  if (maxValue < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("maxValue", SR::Format(SR::get_ArgumentOutOfRange_MustBePositive(), "maxValue"));
  }
  return (Int32)(Sample() * (Double)maxValue);
}

Double Random___::NextDouble() {
  return Sample();
}

void Random___::NextBytes(Array<Byte> buffer) {
  if (buffer == nullptr) {
    rt::throw_exception<ArgumentNullException>("buffer");
  }
  for (Int32 i = 0; i < buffer->get_Length(); i++) {
    buffer[i] = (Byte)InternalSample();
  }
}

void Random___::NextBytes(Span<Byte> buffer) {
  for (Int32 i = 0; i < buffer.get_Length(); i++) {
    buffer[i] = (Byte)Next();
  }
}

void Random___::ctor_static() {
  s_globalRandom = rt::newobj<Random>(GenerateGlobalSeed());
}

} // namespace System::Private::CoreLib::System::RandomNamespace
