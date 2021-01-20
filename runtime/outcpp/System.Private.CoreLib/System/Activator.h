#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Reflection {
enum class BindingFlags : int32_t;
FORWARD(Binder)
} // namespace System::Private::CoreLib::System::Reflection
namespace System::Private::CoreLib::System::Globalization {
FORWARD(CultureInfo)
} // namespace System::Private::CoreLib::System::Globalization
namespace System::Private::CoreLib::System::Runtime::Remoting {
FORWARD(ObjectHandle)
} // namespace System::Private::CoreLib::System::Runtime::Remoting
namespace System::Private::CoreLib::System::Threading {
enum class StackCrawlMark : int32_t;
} // namespace System::Private::CoreLib::System::Threading
namespace System::Private::CoreLib::System {
FORWARD_(Array)
FORWARDS(Boolean)
FORWARD(Object)
FORWARD(String)
FORWARD(Type)
namespace ActivatorNamespace {
using namespace System::Globalization;
using namespace System::Reflection;
using namespace System::Runtime::Remoting;
using namespace System::Threading;
class Activator {
  public: static Object CreateInstance(Type type, BindingFlags bindingAttr, Binder binder, Array<Object> args, CultureInfo culture);
  public: static Object CreateInstance(Type type, Array<Object> args);
  public: static Object CreateInstance(Type type, Array<Object> args, Array<Object> activationAttributes);
  public: static Object CreateInstance(Type type);
  public: static ObjectHandle CreateInstanceFrom(String assemblyFile, String typeName);
  public: static ObjectHandle CreateInstanceFrom(String assemblyFile, String typeName, Array<Object> activationAttributes);
  public: static ObjectHandle CreateInstanceFrom(String assemblyFile, String typeName, Boolean ignoreCase, BindingFlags bindingAttr, Binder binder, Array<Object> args, CultureInfo culture, Array<Object> activationAttributes);
  public: static Object CreateInstance(Type type, BindingFlags bindingAttr, Binder binder, Array<Object> args, CultureInfo culture, Array<Object> activationAttributes);
  public: static ObjectHandle CreateInstance(String assemblyName, String typeName);
  public: static ObjectHandle CreateInstance(String assemblyName, String typeName, Boolean ignoreCase, BindingFlags bindingAttr, Binder binder, Array<Object> args, CultureInfo culture, Array<Object> activationAttributes);
  public: static ObjectHandle CreateInstance(String assemblyName, String typeName, Array<Object> activationAttributes);
  public: static Object CreateInstance(Type type, Boolean nonPublic);
  public: static Object CreateInstance(Type type, Boolean nonPublic, Boolean wrapExceptions);
  private: static ObjectHandle CreateInstanceInternal(String assemblyString, String typeName, Boolean ignoreCase, BindingFlags bindingAttr, Binder binder, Array<Object> args, CultureInfo culture, Array<Object> activationAttributes, StackCrawlMark& stackMark);
  public: template <class T>
  static T CreateInstance();
  private: template <class T>
  static T CreateDefaultInstance();
};
} // namespace ActivatorNamespace
using Activator = ActivatorNamespace::Activator;
} // namespace System::Private::CoreLib::System
