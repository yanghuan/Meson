#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(Char)
FORWARDS(Int32)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::Uri::System {
namespace UncNameHelperNamespace {
using namespace ::System::Private::CoreLib::System;
class UncNameHelper : public Object::in {
  public: static String ParseCanonicalName(String str, Int32 start, Int32 end, Boolean& loopback);
  public: static Boolean IsValid(Char* name, Int32 start, Int32& returnedEnd, Boolean notImplicitFile);
};
} // namespace UncNameHelperNamespace
using UncNameHelper = UncNameHelperNamespace::UncNameHelper;
} // namespace System::Private::Uri::System
