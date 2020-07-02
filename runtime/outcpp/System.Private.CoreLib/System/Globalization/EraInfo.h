#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Int64.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Globalization {
namespace EraInfoNamespace {
CLASS(EraInfo) {
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
