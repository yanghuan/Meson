#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(Dictionary, TKey, TValue)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System::Runtime::ExceptionServices {
FORWARD(FirstChanceExceptionEventArgs)
} // namespace System::Private::CoreLib::System::Runtime::ExceptionServices
namespace System::Private::CoreLib::System {
FORWARD(String)
FORWARDS(Char)
FORWARDS(Int32)
FORWARD(Object)
FORWARDS(Boolean)
FORWARD(UnhandledExceptionEventHandler)
FORWARD_(EventHandler, T1, T2)
namespace AppContextNamespace {
using namespace ::System::Private::CoreLib::System::Collections::Generic;
using namespace ::System::Private::CoreLib::System::Runtime::ExceptionServices;
class AppContext {
  public: static String get_BaseDirectory();
  public: static String get_TargetFrameworkName();
  public: static void Setup(Char** pNames, Char** pValues, Int32 count);
  private: static String GetBaseDirectoryCore();
  public: static Object GetData(String name);
  public: static void SetData(String name, Object data);
  public: static void OnProcessExit();
  public: static Boolean TryGetSwitch(String switchName, Boolean& isEnabled);
  public: static void SetSwitch(String switchName, Boolean isEnabled);
  private: static Dictionary<String, Object> s_dataStore;
  private: static Dictionary<String, Boolean> s_switches;
  private: static String s_defaultBaseDirectory;
  private: static UnhandledExceptionEventHandler UnhandledException;
  private: static EventHandler<FirstChanceExceptionEventArgs> FirstChanceException;
  private: static EventHandler<> ProcessExit;
};
} // namespace AppContextNamespace
using AppContext = AppContextNamespace::AppContext;
} // namespace System::Private::CoreLib::System
