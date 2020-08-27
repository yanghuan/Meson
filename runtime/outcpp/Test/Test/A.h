#pragma once

#include <System.Private.CoreLib/System/ValueType.h>

namespace Test::Test {
namespace ANamespace {
using namespace ::System::Private::CoreLib::System;
struct A : public valueType<A> {
};
} // namespace ANamespace
using A = ANamespace::A;
} // namespace Test::Test
