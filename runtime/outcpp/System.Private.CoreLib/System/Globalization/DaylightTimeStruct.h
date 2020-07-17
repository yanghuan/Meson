#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/DateTime.h>
#include <System.Private.CoreLib/System/TimeSpan.h>

namespace System::Private::CoreLib::System::Globalization {
namespace DaylightTimeStructNamespace {
struct DaylightTimeStruct {
  public: void Ctor(DateTime start, DateTime end, TimeSpan delta);
  public: void Ctor();
  public: DateTime Start;
  public: DateTime End;
  public: TimeSpan Delta;
};
} // namespace DaylightTimeStructNamespace
using DaylightTimeStruct = DaylightTimeStructNamespace::DaylightTimeStruct;
} // namespace System::Private::CoreLib::System::Globalization
