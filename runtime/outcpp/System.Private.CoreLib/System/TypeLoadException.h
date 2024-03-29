#pragma once

#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/SystemException.h>

namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(ISerializable)
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System::Runtime::CompilerServices {
FORWARDS(StringHandleOnStack)
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
namespace System::Private::CoreLib::System {
FORWARD(Exception)
FORWARD(String)
namespace TypeLoadExceptionNamespace {
using namespace System::Runtime::CompilerServices;
using namespace System::Runtime::Serialization;
CLASS(TypeLoadException) : public SystemException::in {
  public: using interface = rt::TypeList<ISerializable>;
  public: String get_Message();
  public: String get_TypeName();
  public: void ctor(String className, String assemblyName, String messageArg, Int32 resourceId);
  private: void SetMessageField();
  private: static void GetTypeLoadExceptionMessage(Int32 resourceId, StringHandleOnStack retString);
  public: void ctor();
  public: void ctor(String message);
  public: void ctor(String message, Exception inner);
  public: void ctor(SerializationInfo info, StreamingContext context);
  public: void GetObjectData(SerializationInfo info, StreamingContext context);
  private: String _className;
  private: String _assemblyName;
  private: String _messageArg;
  private: Int32 _resourceId;
};
} // namespace TypeLoadExceptionNamespace
using TypeLoadException = TypeLoadExceptionNamespace::TypeLoadException;
} // namespace System::Private::CoreLib::System
