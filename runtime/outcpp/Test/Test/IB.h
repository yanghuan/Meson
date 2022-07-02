#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace Test::Test {
namespace IBNamespace {
using namespace ::System::Private::CoreLib::System;
CLASS(IB) : public object {
  public: static constexpr rt::TypeCode code = rt::TypeCode::Interface;
};
} // namespace IBNamespace
using IB = IBNamespace::IB;
} // namespace Test::Test
