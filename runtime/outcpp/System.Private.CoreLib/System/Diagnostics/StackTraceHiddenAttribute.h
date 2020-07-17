#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Diagnostics {
namespace StackTraceHiddenAttributeNamespace {
CLASS(StackTraceHiddenAttribute) {
  public: void Ctor();
};
} // namespace StackTraceHiddenAttributeNamespace
using StackTraceHiddenAttribute = StackTraceHiddenAttributeNamespace::StackTraceHiddenAttribute;
} // namespace System::Private::CoreLib::System::Diagnostics
