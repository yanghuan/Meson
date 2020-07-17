#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Int32.h>

namespace System::Private::CoreLib::System::Runtime::CompilerServices {
FORWARDS(StringHandleOnStack)
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System {
FORWARD(Exception)
FORWARD(String)
namespace TypeLoadExceptionNamespace {
using namespace Runtime::CompilerServices;
using namespace Runtime::Serialization;
CLASS(TypeLoadException) {
  public: String get_Message();
  public: String get_TypeName();
  private: void Ctor(String className, String assemblyName, String messageArg, Int32 resourceId);
  private: void SetMessageField();
  private: static void GetTypeLoadExceptionMessage(Int32 resourceId, StringHandleOnStack retString);
  public: void Ctor();
  public: void Ctor(String message);
  public: void Ctor(String message, Exception inner);
  protected: void Ctor(SerializationInfo info, StreamingContext context);
  public: void GetObjectData(SerializationInfo info, StreamingContext context);
  private: String _className;
  private: String _assemblyName;
  private: String _messageArg;
  private: Int32 _resourceId;
};
} // namespace TypeLoadExceptionNamespace
using TypeLoadException = TypeLoadExceptionNamespace::TypeLoadException;
} // namespace System::Private::CoreLib::System
