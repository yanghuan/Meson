#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace Test::Test {
namespace IANamespace {
using namespace ::System::Private::CoreLib::System;
CLASS(IA) : public object {
  public: Object get_Current();
  public: void f();
  public: static constexpr rt::TypeCode code = rt::TypeCode::Interface;
};
} // namespace IANamespace
using IA = IANamespace::IA;
} // namespace Test::Test
