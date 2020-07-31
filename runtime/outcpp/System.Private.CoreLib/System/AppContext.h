#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(Dictionary, TKey, TValue)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System::Runtime::ExceptionServices {
FORWARD(FirstChanceExceptionEventArgs)
} // namespace System::Private::CoreLib::System::Runtime::ExceptionServices
namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(Char)
FORWARD_(EventHandler, T1, T2)
FORWARDS(Int32)
FORWARD(Object)
FORWARD(String)
FORWARD(UnhandledExceptionEventHandler)
namespace AppContextNamespace {
using namespace Collections::Generic;
using namespace Runtime::ExceptionServices;
class AppContext {
  public: static String get_BaseDirectory();
  public: static String get_TargetFrameworkName();
  public: static Object GetData(String name);
  public: static void SetData(String name, Object data);
  public: static void OnProcessExit();
  public: static Boolean TryGetSwitch(String switchName, Boolean& isEnabled);
  public: static void SetSwitch(String switchName, Boolean isEnabled);
  public: static void Setup(Char** pNames, Char** pValues, Int32 count);
  private: static String GetBaseDirectoryCore();
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
