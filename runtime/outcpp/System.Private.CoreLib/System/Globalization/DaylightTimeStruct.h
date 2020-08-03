#pragma once

#include <System.Private.CoreLib/System/DateTime.h>
#include <System.Private.CoreLib/System/TimeSpan.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System::Globalization {
namespace DaylightTimeStructNamespace {
struct DaylightTimeStruct : public valueType<DaylightTimeStruct> {
  public: explicit DaylightTimeStruct(DateTime start, DateTime end, TimeSpan delta);
  public: explicit DaylightTimeStruct() {}
  public: DateTime Start;
  public: DateTime End;
  public: TimeSpan Delta;
};
} // namespace DaylightTimeStructNamespace
using DaylightTimeStruct = DaylightTimeStructNamespace::DaylightTimeStruct;
} // namespace System::Private::CoreLib::System::Globalization
