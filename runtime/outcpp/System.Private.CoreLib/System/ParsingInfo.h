#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/DateTimeParse.h>
#include <System.Private.CoreLib/System/Int32.h>

namespace System::Private::CoreLib::System::Globalization {
FORWARD(Calendar)
} // namespace System::Private::CoreLib::System::Globalization
namespace System::Private::CoreLib::System {
namespace ParsingInfoNamespace {
using namespace Globalization;
struct ParsingInfo {
  public: void Init();
  public: void Ctor();
  public: Calendar calendar;
  public: Int32 dayOfWeek;
  public: DateTimeParse::TM timeMark;
  public: Boolean fUseHour12;
  public: Boolean fUseTwoDigitYear;
  public: Boolean fAllowInnerWhite;
  public: Boolean fAllowTrailingWhite;
  public: Boolean fCustomNumberParser;
  public: DateTimeParse::MatchNumberDelegate parseNumberDelegate;
};
} // namespace ParsingInfoNamespace
using ParsingInfo = ParsingInfoNamespace::ParsingInfo;
} // namespace System::Private::CoreLib::System
