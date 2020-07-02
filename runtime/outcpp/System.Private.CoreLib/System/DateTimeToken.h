#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/DateTimeParse.h>
#include <System.Private.CoreLib/System/Int32.h>

namespace System::Private::CoreLib::System {
enum class TokenType;
namespace DateTimeTokenNamespace {
struct DateTimeToken {
  public: DateTimeParse::DTT dtt;
  public: TokenType suffix;
  public: Int32 num;
};
} // namespace DateTimeTokenNamespace
using DateTimeToken = DateTimeTokenNamespace::DateTimeToken;
} // namespace System::Private::CoreLib::System
