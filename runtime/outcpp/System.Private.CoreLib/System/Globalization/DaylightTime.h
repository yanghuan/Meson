#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/DateTime.h>
#include <System.Private.CoreLib/System/TimeSpan.h>

namespace System::Private::CoreLib::System::Globalization {
namespace DaylightTimeNamespace {
CLASS(DaylightTime) {
  public: DateTime get_Start();
  public: DateTime get_End();
  public: TimeSpan get_Delta();
  private: DateTime _start;
  private: DateTime _end;
  private: TimeSpan _delta;
};
} // namespace DaylightTimeNamespace
using DaylightTime = DaylightTimeNamespace::DaylightTime;
} // namespace System::Private::CoreLib::System::Globalization