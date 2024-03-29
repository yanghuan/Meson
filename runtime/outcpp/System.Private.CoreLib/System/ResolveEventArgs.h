#pragma once

#include <System.Private.CoreLib/System/EventArgs.h>

namespace System::Private::CoreLib::System::Reflection {
FORWARD(Assembly)
} // namespace System::Private::CoreLib::System::Reflection
namespace System::Private::CoreLib::System {
FORWARD(String)
namespace ResolveEventArgsNamespace {
using namespace System::Reflection;
CLASS(ResolveEventArgs) : public EventArgs::in {
  public: String get_Name() { return Name; }
  public: Assembly get_RequestingAssembly() { return RequestingAssembly; }
  public: void ctor(String name);
  public: void ctor(String name, Assembly requestingAssembly);
  private: String Name;
  private: Assembly RequestingAssembly;
};
} // namespace ResolveEventArgsNamespace
using ResolveEventArgs = ResolveEventArgsNamespace::ResolveEventArgs;
} // namespace System::Private::CoreLib::System
