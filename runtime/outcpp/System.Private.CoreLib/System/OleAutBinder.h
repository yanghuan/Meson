#pragma once

#include <System.Private.CoreLib/System/DefaultBinder.h>

namespace System::Private::CoreLib::System::Globalization {
FORWARD(CultureInfo)
} // namespace System::Private::CoreLib::System::Globalization
namespace System::Private::CoreLib::System {
FORWARD(Object)
FORWARD(Type)
namespace OleAutBinderNamespace {
using namespace Globalization;
CLASS(OleAutBinder) : public DefaultBinder::in {
  public: Object ChangeType(Object value, Type type, CultureInfo cultureInfo);
  public: void Ctor();
};
} // namespace OleAutBinderNamespace
using OleAutBinder = OleAutBinderNamespace::OleAutBinder;
} // namespace System::Private::CoreLib::System
