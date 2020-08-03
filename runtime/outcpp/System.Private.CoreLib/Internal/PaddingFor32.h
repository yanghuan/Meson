#pragma once

#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::Internal {
namespace PaddingFor32Namespace {
using namespace ::System::Private::CoreLib::System;
struct PaddingFor32 : public valueType<PaddingFor32> {
};
} // namespace PaddingFor32Namespace
using PaddingFor32 = PaddingFor32Namespace::PaddingFor32;
} // namespace System::Private::CoreLib::Internal
