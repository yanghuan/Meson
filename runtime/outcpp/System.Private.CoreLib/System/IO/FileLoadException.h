#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Int32)
FORWARD(String)
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
using namespace Runtime::CompilerServices;
using namespace Runtime::Serialization;
CLASS(FileLoadException) {
  public: String get_Message();
  public: String get_FileName() { return FileName; }
  public: String get_FusionLog() { return FusionLog; }
  public: static String FormatFileLoadExceptionMessage(String fileName, Int32 hResult);
  private: static void GetFileLoadExceptionMessage(Int32 hResult, StringHandleOnStack retString);
  private: static void GetMessageForHR(Int32 hresult, StringHandleOnStack retString);
  public: String ToString();
  public: void GetObjectData(SerializationInfo info, StreamingContext context);
  private: String FileName;
  private: String FusionLog;
};
} // namespace FileLoadExceptionNamespace
using FileLoadException = FileLoadExceptionNamespace::FileLoadException;
} // namespace System::Private::CoreLib::System::IO
