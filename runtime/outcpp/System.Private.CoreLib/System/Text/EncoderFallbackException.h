#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Char.h>
#include <System.Private.CoreLib/System/Int32.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARD(Exception)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System::Text {
namespace EncoderFallbackExceptionNamespace {
using namespace Runtime::Serialization;
CLASS(EncoderFallbackException) {
  public: Char get_CharUnknown();
  public: Char get_CharUnknownHigh();
  public: Char get_CharUnknownLow();
  public: Int32 get_Index();
  public: void Ctor();
  public: void Ctor(String message);
  public: void Ctor(String message, Exception innerException);
  public: void Ctor(String message, Char charUnknown, Int32 index);
  public: void Ctor(String message, Char charUnknownHigh, Char charUnknownLow, Int32 index);
  private: void Ctor(SerializationInfo serializationInfo, StreamingContext streamingContext);
  public: Boolean IsUnknownSurrogate();
  private: Char _charUnknown;
  private: Char _charUnknownHigh;
  private: Char _charUnknownLow;
  private: Int32 _index;
};
} // namespace EncoderFallbackExceptionNamespace
using EncoderFallbackException = EncoderFallbackExceptionNamespace::EncoderFallbackException;
} // namespace System::Private::CoreLib::System::Text
