#include "ProcessorIdCache-dep.h"

#include <System.Private.CoreLib/System/Diagnostics/Stopwatch-dep.h>
#include <System.Private.CoreLib/System/Double-dep.h>
#include <System.Private.CoreLib/System/Environment-dep.h>
#include <System.Private.CoreLib/System/Int64-dep.h>
#include <System.Private.CoreLib/System/Math-dep.h>
#include <System.Private.CoreLib/System/Threading/Thread-dep.h>

namespace System::Private::CoreLib::System::Threading::ProcessorIdCacheNamespace {
using namespace System::Diagnostics;

Int32 ProcessorIdCache::RefreshCurrentProcessorId() {
  Int32 num = Thread::in::GetCurrentProcessorNumber();
  if (num < 0) {
    num = Environment::get_CurrentManagedThreadId();
  }
  t_currentProcessorIdCache = ((num << 16) & 2147483647) | s_processorIdRefreshRate;
  return num;
}

Int32 ProcessorIdCache::GetCurrentProcessorId() {
  Int32 num = t_currentProcessorIdCache--;
  if ((num & 65535) == 0) {
    return RefreshCurrentProcessorId();
  }
  return num >> 16;
}

Boolean ProcessorIdCache::ProcessorNumberSpeedCheck() {
  Double num = Double::MaxValue;
  Double num2 = Double::MaxValue;
  UninlinedThreadStatic();
  if (Thread::in::GetCurrentProcessorNumber() < 0) {
    s_processorIdRefreshRate = 65535;
    return false;
  }
  Int64 num3 = Stopwatch::in::Frequency / 1000000 + 1;
  for (Int32 i = 0; i < 10; i++) {
    Int32 num4 = 8;
    Int64 timestamp;
    do {
      num4 *= 2;
      timestamp = Stopwatch::in::GetTimestamp();
      for (Int32 j = 0; j < num4; j++) {
        Thread::in::GetCurrentProcessorNumber();
      }
      timestamp = Stopwatch::in::GetTimestamp() - timestamp;
    } while (timestamp < num3);
    num = Math::Min(num, (Double)timestamp / (Double)num4);
    num4 /= 4;
    do {
      num4 *= 2;
      timestamp = Stopwatch::in::GetTimestamp();
      for (Int32 k = 0; k < num4; k++) {
        UninlinedThreadStatic();
      }
      timestamp = Stopwatch::in::GetTimestamp() - timestamp;
    } while (timestamp < num3);
    num2 = Math::Min(num2, (Double)timestamp / (Double)num4);
  }
  s_processorIdRefreshRate = Math::Min((Int32)(num * 5 / num2), 5000);
  return s_processorIdRefreshRate <= 5;
}

Int32 ProcessorIdCache::UninlinedThreadStatic() {
  return t_currentProcessorIdCache;
}

} // namespace System::Private::CoreLib::System::Threading::ProcessorIdCacheNamespace
