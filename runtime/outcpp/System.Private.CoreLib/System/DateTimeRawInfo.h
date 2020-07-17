#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/DateTimeParse.h>
#include <System.Private.CoreLib/System/Double.h>
#include <System.Private.CoreLib/System/Int32.h>

namespace System::Private::CoreLib::System {
namespace DateTimeRawInfoNamespace {
struct DateTimeRawInfo {
  public: void Init(Int32* numberBuffer);
  public: void AddNumber(Int32 value);
  public: Int32 GetNumber(Int32 index);
  public: void Ctor();
  private: Int32* num;
  public: Int32 numCount;
  public: Int32 month;
  public: Int32 year;
  public: Int32 dayOfWeek;
  public: Int32 era;
  public: DateTimeParse::TM timeMark;
  public: Double fraction;
  public: Boolean hasSameDateAndTimeSeparators;
};
} // namespace DateTimeRawInfoNamespace
using DateTimeRawInfo = DateTimeRawInfoNamespace::DateTimeRawInfo;
} // namespace System::Private::CoreLib::System
