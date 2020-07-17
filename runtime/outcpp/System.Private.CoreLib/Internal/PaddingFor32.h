#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::Internal {
namespace PaddingFor32Namespace {
struct PaddingFor32 {
  public: void Ctor();
};
} // namespace PaddingFor32Namespace
using PaddingFor32 = PaddingFor32Namespace::PaddingFor32;
} // namespace System::Private::CoreLib::Internal
