#pragma once

#include <System.Private.CoreLib/System/DateTimeParse.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System {
enum class TokenType : int32_t;
namespace DateTimeTokenNamespace {
struct DateTimeToken : public valueType<DateTimeToken> {
  public: DateTimeParse::DTT dtt;
  public: TokenType suffix;
  public: Int32 num;
};
} // namespace DateTimeTokenNamespace
using DateTimeToken = DateTimeTokenNamespace::DateTimeToken;
} // namespace System::Private::CoreLib::System
