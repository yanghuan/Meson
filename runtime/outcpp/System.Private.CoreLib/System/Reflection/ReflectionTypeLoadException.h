#pragma once

#include <System.Private.CoreLib/System/SystemException.h>

namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(ISerializable)
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System {
FORWARD_(Array)
FORWARDS(Boolean)
FORWARD(Exception)
FORWARD(String)
FORWARD(Type)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection {
namespace ReflectionTypeLoadExceptionNamespace {
using namespace System::Runtime::Serialization;
CLASS(ReflectionTypeLoadException) : public SystemException::in {
  public: using interface = rt::TypeList<ISerializable>;
  public: Array<Type> get_Types() { return Types; }
  public: Array<Exception> get_LoaderExceptions() { return LoaderExceptions; }
  public: String get_Message();
  public: void ctor(Array<Type> classes, Array<Exception> exceptions);
  public: void ctor(Array<Type> classes, Array<Exception> exceptions, String message);
  public: void ctor(SerializationInfo info, StreamingContext context);
  public: void GetObjectData(SerializationInfo info, StreamingContext context);
  public: String ToString();
  private: String CreateString(Boolean isMessage);
  private: Array<Type> Types;
  private: Array<Exception> LoaderExceptions;
};
} // namespace ReflectionTypeLoadExceptionNamespace
using ReflectionTypeLoadException = ReflectionTypeLoadExceptionNamespace::ReflectionTypeLoadException;
} // namespace System::Private::CoreLib::System::Reflection
