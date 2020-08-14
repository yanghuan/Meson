#include "Stopwatch-dep.h"

#include <System.Private.CoreLib/Interop-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Stopwatch-dep.h>
#include <System.Private.CoreLib/System/Double-dep.h>

namespace System::Private::CoreLib::System::Diagnostics::StopwatchNamespace {
Boolean Stopwatch___::get_IsRunning() {
  return _isRunning;
}

TimeSpan Stopwatch___::get_Elapsed() {
  return TimeSpan(GetElapsedDateTimeTicks());
}

Int64 Stopwatch___::get_ElapsedMilliseconds() {
  return GetElapsedDateTimeTicks() / 10000;
}

Int64 Stopwatch___::get_ElapsedTicks() {
  return GetRawElapsedTicks();
}

void Stopwatch___::ctor() {
  Reset();
}

void Stopwatch___::Start() {
  if (!_isRunning) {
    _startTimeStamp = GetTimestamp();
    _isRunning = true;
  }
}

Stopwatch Stopwatch___::StartNew() {
  Stopwatch stopwatch = rt::newobj<Stopwatch>();
  stopwatch->Start();
  return stopwatch;
}

void Stopwatch___::Stop() {
  if (_isRunning) {
    Int64 timestamp = GetTimestamp();
    Int64 num = timestamp - _startTimeStamp;
    _elapsed += num;
    _isRunning = false;
    if (_elapsed < 0) {
      _elapsed = 0;
    }
  }
}

void Stopwatch___::Reset() {
  _elapsed = 0;
  _isRunning = false;
  _startTimeStamp = 0;
}

void Stopwatch___::Restart() {
  _elapsed = 0;
  _startTimeStamp = GetTimestamp();
  _isRunning = true;
}

Int64 Stopwatch___::GetTimestamp() {
  return QueryPerformanceCounter();
}

Int64 Stopwatch___::GetRawElapsedTicks() {
  Int64 num = _elapsed;
  if (_isRunning) {
    Int64 timestamp = GetTimestamp();
    Int64 num2 = timestamp - _startTimeStamp;
    num += num2;
  }
  return num;
}

Int64 Stopwatch___::GetElapsedDateTimeTicks() {
  return (Int64)((Double)GetRawElapsedTicks() * s_tickFrequency);
}

Int64 Stopwatch___::QueryPerformanceFrequency() {
  Int64 result;
  Interop::BOOL bOOL = Interop::Kernel32::QueryPerformanceFrequency(&result);
  return result;
}

Int64 Stopwatch___::QueryPerformanceCounter() {
  Int64 result;
  Interop::BOOL bOOL = Interop::Kernel32::QueryPerformanceCounter(&result);
  return result;
}

void Stopwatch___::cctor() {
  Frequency = QueryPerformanceFrequency();
  IsHighResolution = true;
  s_tickFrequency = 10000000 / (Double)Frequency;
}

} // namespace System::Private::CoreLib::System::Diagnostics::StopwatchNamespace
