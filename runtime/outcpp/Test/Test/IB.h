#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace Test::Test {
FORWARD(IA)
namespace IBNamespace {
using namespace ::System::Private::CoreLib::System;
CLASS(IB) : public object {
  public: using interface = rt::TypeList<IA>;
  public: String get_Current();
  public: void f();
  public: static constexpr rt::TypeCode code = rt::TypeCode::Interface;
};
} // namespace IBNamespace
using IB = IBNamespace::IB;
} // namespace Test::Test
