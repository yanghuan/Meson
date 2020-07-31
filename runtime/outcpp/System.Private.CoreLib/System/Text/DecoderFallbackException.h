#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/ArgumentException.h>
#include <System.Private.CoreLib/System/Int32.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Byte)
FORWARD(Exception)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System::Text {
namespace DecoderFallbackExceptionNamespace {
using namespace Runtime::Serialization;
CLASS(DecoderFallbackException) : public ArgumentException::in {
  public: Array<Byte> get_BytesUnknown();
  public: Int32 get_Index();
  public: void Ctor();
  public: void Ctor(String message);
  public: void Ctor(String message, Exception innerException);
  public: void Ctor(String message, Array<Byte> bytesUnknown, Int32 index);
  private: void Ctor(SerializationInfo serializationInfo, StreamingContext streamingContext);
  private: Array<Byte> _bytesUnknown;
  private: Int32 _index;
};
} // namespace DecoderFallbackExceptionNamespace
using DecoderFallbackException = DecoderFallbackExceptionNamespace::DecoderFallbackException;
} // namespace System::Private::CoreLib::System::Text
