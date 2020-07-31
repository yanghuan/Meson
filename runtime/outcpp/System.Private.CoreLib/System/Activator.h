#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Reflection {
enum class BindingFlags;
FORWARD(Binder)
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
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
FORWARD(String)
FORWARD(Type)
namespace ActivatorNamespace {
using namespace Globalization;
using namespace Reflection;
using namespace Runtime::Remoting;
using namespace Threading;
class Activator : public Object::in {
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
