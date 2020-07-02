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
FORWARD(String)
namespace TypeLoadExceptionNamespace {
using namespace ::System::Private::CoreLib::System::Runtime::CompilerServices;
using namespace ::System::Private::CoreLib::System::Runtime::Serialization;
CLASS(TypeLoadException) {
  public: String get_Message();
  public: String get_TypeName();
  private: void SetMessageField();
  private: static void GetTypeLoadExceptionMessage(Int32 resourceId, StringHandleOnStack retString);
  public: void GetObjectData(SerializationInfo info, StreamingContext context);
  private: String _className;
  private: String _assemblyName;
  private: String _messageArg;
  private: Int32 _resourceId;
};
} // namespace TypeLoadExceptionNamespace
using TypeLoadException = TypeLoadExceptionNamespace::TypeLoadException;
} // namespace System::Private::CoreLib::System