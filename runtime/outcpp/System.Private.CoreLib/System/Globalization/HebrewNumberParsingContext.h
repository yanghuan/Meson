#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Globalization/HebrewNumber.h>
#include <System.Private.CoreLib/System/Int32.h>

namespace System::Private::CoreLib::System::Globalization {
namespace HebrewNumberParsingContextNamespace {
struct HebrewNumberParsingContext {
  public: void Ctor(Int32 result);
  public: void Ctor();
  public: HebrewNumber::HS state;
  public: Int32 result;
};
} // namespace HebrewNumberParsingContextNamespace
using HebrewNumberParsingContext = HebrewNumberParsingContextNamespace::HebrewNumberParsingContext;
} // namespace System::Private::CoreLib::System::Globalization
