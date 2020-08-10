#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(Int32)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Diagnostics {
FORWARD(ICustomDebuggerNotification)
namespace DebuggerNamespace {
class Debugger {
  private: CLASS(CrossThreadDependencyNotification) : public Object::in {
    public: using interface = rt::TypeList<ICustomDebuggerNotification>;
    public: void ctor();
  };
  public: static Boolean get_IsAttached();
  public: static void Break();
  private: static void BreakCanThrow();
  private: static void BreakInternal();
  public: static Boolean Launch();
  private: static void NotifyOfCrossThreadDependencySlow();
  public: static void NotifyOfCrossThreadDependency();
  private: static Boolean LaunchInternal();
  public: static void Log(Int32 level, String category, String message);
  public: static Boolean IsLogging();
  private: static void CustomNotification(ICustomDebuggerNotification data);
  public: static String DefaultCategory;
};
} // namespace DebuggerNamespace
using Debugger = DebuggerNamespace::Debugger;
} // namespace System::Private::CoreLib::System::Diagnostics
