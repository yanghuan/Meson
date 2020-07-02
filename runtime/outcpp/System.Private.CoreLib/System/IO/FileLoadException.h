#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
FORWARDS(Int32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::CompilerServices {
FORWARDS(StringHandleOnStack)
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System::IO {
namespace FileLoadExceptionNamespace {
using namespace ::System::Private::CoreLib::System::Runtime::CompilerServices;
using namespace ::System::Private::CoreLib::System::Runtime::Serialization;
CLASS(FileLoadException) {
  public: String get_Message();
  public: static String FormatFileLoadExceptionMessage(String fileName, Int32 hResult);
  private: static void GetFileLoadExceptionMessage(Int32 hResult, StringHandleOnStack retString);
  private: static void GetMessageForHR(Int32 hresult, StringHandleOnStack retString);
  public: String ToString();
  public: void GetObjectData(SerializationInfo info, StreamingContext context);
};
} // namespace FileLoadExceptionNamespace
using FileLoadException = FileLoadExceptionNamespace::FileLoadException;
} // namespace System::Private::CoreLib::System::IO
