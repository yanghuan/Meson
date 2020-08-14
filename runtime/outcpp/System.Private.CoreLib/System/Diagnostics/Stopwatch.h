#pragma once

#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/Int64.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARDS(Double)
FORWARDS(TimeSpan)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Diagnostics {
namespace StopwatchNamespace {
CLASS(Stopwatch) : public Object::in {
  public: Boolean get_IsRunning();
  public: TimeSpan get_Elapsed();
  public: Int64 get_ElapsedMilliseconds();
  public: Int64 get_ElapsedTicks();
  public: void ctor();
  public: void Start();
  public: static Stopwatch StartNew();
  public: void Stop();
  public: void Reset();
  public: void Restart();
  public: static Int64 GetTimestamp();
  private: Int64 GetRawElapsedTicks();
  private: Int64 GetElapsedDateTimeTicks();
  private: static Int64 QueryPerformanceFrequency();
  private: static Int64 QueryPerformanceCounter();
  private: static void cctor();
  private: Int64 _elapsed;
  private: Int64 _startTimeStamp;
  private: Boolean _isRunning;
  public: static Int64 Frequency;
  public: static Boolean IsHighResolution;
  private: static Double s_tickFrequency;
};
} // namespace StopwatchNamespace
using Stopwatch = StopwatchNamespace::Stopwatch;
} // namespace System::Private::CoreLib::System::Diagnostics
