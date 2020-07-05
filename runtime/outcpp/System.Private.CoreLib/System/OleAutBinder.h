#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Globalization {
FORWARD(CultureInfo)
} // namespace System::Private::CoreLib::System::Globalization
namespace System::Private::CoreLib::System {
FORWARD(Object)
FORWARD(Type)
namespace OleAutBinderNamespace {
using namespace Globalization;
CLASS(OleAutBinder) {
  public: Object ChangeType(Object value, Type type, CultureInfo cultureInfo);
};
} // namespace OleAutBinderNamespace
using OleAutBinder = OleAutBinderNamespace::OleAutBinder;
} // namespace System::Private::CoreLib::System
