#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
enum class TypeCode;
FORWARDS(Boolean)
FORWARD(Type)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection {
FORWARD(Assembly)
} // namespace System::Private::CoreLib::System::Reflection
namespace System::Private::CoreLib::Microsoft::Reflection {
namespace ReflectionExtensionsNamespace {
using namespace ::System::Private::CoreLib::System;
using namespace ::System::Private::CoreLib::System::Reflection;
class ReflectionExtensions {
  public: static Boolean IsEnum(Type type);
  public: static Boolean IsAbstract(Type type);
  public: static Boolean IsSealed(Type type);
  public: static Boolean IsValueType(Type type);
  public: static Boolean IsGenericType(Type type);
  public: static Type BaseType(Type type);
  public: static Assembly Assembly(Type type);
  public: static TypeCode GetTypeCode(Type type);
  public: static Boolean ReflectionOnly(::System::Private::CoreLib::System::Reflection::Assembly assm);
};
} // namespace ReflectionExtensionsNamespace
using ReflectionExtensions = ReflectionExtensionsNamespace::ReflectionExtensions;
} // namespace System::Private::CoreLib::Microsoft::Reflection
