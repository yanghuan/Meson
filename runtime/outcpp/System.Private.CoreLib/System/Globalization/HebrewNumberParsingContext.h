#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Globalization/HebrewNumber.h>
#include <System.Private.CoreLib/System/Int32.h>

namespace System::Private::CoreLib::System::Globalization {
namespace HebrewNumberParsingContextNamespace {
struct HebrewNumberParsingContext {
  public: explicit HebrewNumberParsingContext(Int32 result);
  public: explicit HebrewNumberParsingContext() {}
  public: HebrewNumber::HS state;
  public: Int32 result;
};
} // namespace HebrewNumberParsingContextNamespace
using HebrewNumberParsingContext = HebrewNumberParsingContextNamespace::HebrewNumberParsingContext;
} // namespace System::Private::CoreLib::System::Globalization
