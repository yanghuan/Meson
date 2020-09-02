#include "AppContext-dep.h"

#include <System.Private.CoreLib/System/AppContext-dep.h>
#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/Collections/Generic/Dictionary-dep.h>
#include <System.Private.CoreLib/System/EventHandler-dep.h>
#include <System.Private.CoreLib/System/IO/Path-dep.h>
#include <System.Private.CoreLib/System/Object-dep.h>
#include <System.Private.CoreLib/System/Reflection/Assembly-dep.h>
#include <System.Private.CoreLib/System/Reflection/CustomAttributeExtensions-dep.h>
#include <System.Private.CoreLib/System/Runtime/Loader/AssemblyLoadContext-dep.h>
#include <System.Private.CoreLib/System/Runtime/Versioning/TargetFrameworkAttribute-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/Threading/Interlocked-dep.h>

namespace System::Private::CoreLib::System::AppContextNamespace {
using namespace System::Collections::Generic;
using namespace System::IO;
using namespace System::Reflection;
using namespace System::Runtime::Loader;
using namespace System::Runtime::Versioning;
using namespace System::Threading;

String AppContext::get_BaseDirectory() {
  String as = s_defaultBaseDirectory;
  String is = (rt::as<String>(GetData("APP_CONTEXT_BASE_DIRECTORY")));
  return is != nullptr ? is : as != nullptr ? as : (s_defaultBaseDirectory = GetBaseDirectoryCore());
}

String AppContext::get_TargetFrameworkName() {
  Assembly entryAssembly = Assembly::in::GetEntryAssembly();
  if ((Object)entryAssembly == nullptr) {
    return nullptr;
  }
  TargetFrameworkAttribute customAttribute = CustomAttributeExtensions::GetCustomAttribute(entryAssembly);
  if (customAttribute == nullptr) {
    return nullptr;
  }
  return customAttribute->get_FrameworkName();
}

Object AppContext::GetData(String name) {
  if (name == nullptr) {
    rt::throw_exception<ArgumentNullException>("name");
  }
  if (s_dataStore == nullptr) {
    return nullptr;
  }
  {
    rt::lock(s_dataStore);
    Object value;
    s_dataStore->TryGetValue(name, value);
    return value;
  }
}

void AppContext::SetData(String name, Object data) {
  if (name == nullptr) {
    rt::throw_exception<ArgumentNullException>("name");
  }
  if (s_dataStore == nullptr) {
    Interlocked::CompareExchange(s_dataStore, rt::newobj<Dictionary<String, Object>>(), (Dictionary<String, Object>)nullptr);
  }
  {
    rt::lock(s_dataStore);
    s_dataStore[name] = data;
  }
}

void AppContext::OnProcessExit() {
  AssemblyLoadContext::in::OnProcessExit();
}

Boolean AppContext::TryGetSwitch(String switchName, Boolean& isEnabled) {
  if (switchName == nullptr) {
    rt::throw_exception<ArgumentNullException>("switchName");
  }
  if (switchName->get_Length() == 0) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_EmptyName(), "switchName");
  }
  if (s_switches != nullptr) {
    {
      rt::lock(s_switches);
      if (s_switches->TryGetValue(switchName, isEnabled)) {
        return true;
      }
    }
  }
  String text = rt::as<String>(GetData(switchName));
  if (text != nullptr && Boolean::TryParse(text, isEnabled)) {
    return true;
  }
  isEnabled = false;
  return false;
}

void AppContext::SetSwitch(String switchName, Boolean isEnabled) {
  if (switchName == nullptr) {
    rt::throw_exception<ArgumentNullException>("switchName");
  }
  if (switchName->get_Length() == 0) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_EmptyName(), "switchName");
  }
  if (s_switches == nullptr) {
    Interlocked::CompareExchange(s_switches, rt::newobj<Dictionary<String, Boolean>>(), (Dictionary<String, Boolean>)nullptr);
  }
  {
    rt::lock(s_switches);
    s_switches[switchName] = isEnabled;
  }
}

void AppContext::Setup(Char** pNames, Char** pValues, Int32 count) {
  s_dataStore = rt::newobj<Dictionary<String, Object>>(count);
  for (Int32 i = 0; i < count; i++) {
    s_dataStore->Add(rt::newobj<String>(*(pNames + i)), rt::newobj<String>(*(pValues + i)));
  }
}

String AppContext::GetBaseDirectoryCore() {
  Assembly entryAssembly = Assembly::in::GetEntryAssembly();
  String text = Path::GetDirectoryName(((Object)entryAssembly != nullptr) ? entryAssembly->get_Location() : nullptr);
  if (text == nullptr) {
    return String::in::Empty;
  }
  if (!Path::EndsInDirectorySeparator(text)) {
    text += "\\";
  }
  return text;
}

} // namespace System::Private::CoreLib::System::AppContextNamespace
