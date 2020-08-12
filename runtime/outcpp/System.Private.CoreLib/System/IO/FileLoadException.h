#pragma once

#include <System.Private.CoreLib/System/IO/IOException.h>

namespace System::Private::CoreLib::System {
FORWARD(Exception)
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
using namespace System::Runtime::CompilerServices;
using namespace System::Runtime::Serialization;
CLASS(FileLoadException) : public IOException::in {
  public: String get_Message();
  public: String get_FileName() { return FileName; }
  public: String get_FusionLog() { return FusionLog; }
  private: void ctor(String fileName, Int32 hResult);
  public: static String FormatFileLoadExceptionMessage(String fileName, Int32 hResult);
  private: static void GetFileLoadExceptionMessage(Int32 hResult, StringHandleOnStack retString);
  private: static void GetMessageForHR(Int32 hresult, StringHandleOnStack retString);
  public: void ctor();
  public: void ctor(String message);
  public: void ctor(String message, Exception inner);
  public: void ctor(String message, String fileName);
  public: void ctor(String message, String fileName, Exception inner);
  public: String ToString();
  protected: void ctor(SerializationInfo info, StreamingContext context);
  public: void GetObjectData(SerializationInfo info, StreamingContext context);
  private: String FileName;
  private: String FusionLog;
};
} // namespace FileLoadExceptionNamespace
using FileLoadException = FileLoadExceptionNamespace::FileLoadException;
} // namespace System::Private::CoreLib::System::IO
