#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Reflection {
FORWARD(Binder)
enum class BindingFlags;
} // namespace System::Private::CoreLib::System::Reflection
namespace System::Private::CoreLib::System::Globalization {
FORWARD(CultureInfo)
} // namespace System::Private::CoreLib::System::Globalization
namespace System::Private::CoreLib::System::Runtime::Remoting {
FORWARD(ObjectHandle)
} // namespace System::Private::CoreLib::System::Runtime::Remoting
namespace System::Private::CoreLib::System::Threading {
enum class StackCrawlMark;
} // namespace System::Private::CoreLib::System::Threading
namespace System::Private::CoreLib::System {
FORWARD(Type)
FORWARD_(Array, T1, T2)
FORWARD(Object)
FORWARD(String)
FORWARDS(Boolean)
namespace ActivatorNamespace {
using namespace ::System::Private::CoreLib::System::Globalization;
using namespace ::System::Private::CoreLib::System::Reflection;
using namespace ::System::Private::CoreLib::System::Runtime::Remoting;
using namespace ::System::Private::CoreLib::System::Threading;
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
};
} // namespace ActivatorNamespace
using Activator = ActivatorNamespace::Activator;
} // namespace System::Private::CoreLib::System
