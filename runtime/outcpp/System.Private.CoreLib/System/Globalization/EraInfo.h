#pragma once

#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Int64.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Globalization {
namespace EraInfoNamespace {
CLASS(EraInfo) : public Object::in {
  public: void Ctor(Int32 era, Int32 startYear, Int32 startMonth, Int32 startDay, Int32 yearOffset, Int32 minEraYear, Int32 maxEraYear);
  public: void Ctor(Int32 era, Int32 startYear, Int32 startMonth, Int32 startDay, Int32 yearOffset, Int32 minEraYear, Int32 maxEraYear, String eraName, String abbrevEraName, String englishEraName);
  public: Int32 era;
  public: Int64 ticks;
  public: Int32 yearOffset;
  public: Int32 minEraYear;
  public: Int32 maxEraYear;
  public: String eraName;
  public: String abbrevEraName;
  public: String englishEraName;
};
} // namespace EraInfoNamespace
using EraInfo = EraInfoNamespace::EraInfo;
} // namespace System::Private::CoreLib::System::Globalization
