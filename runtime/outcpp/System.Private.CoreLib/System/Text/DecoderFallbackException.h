#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Int32.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Byte)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Text {
namespace DecoderFallbackExceptionNamespace {
CLASS(DecoderFallbackException) {
  public: Array<Byte> get_BytesUnknown();
  public: Int32 get_Index();
  private: Array<Byte> _bytesUnknown;
  private: Int32 _index;
};
} // namespace DecoderFallbackExceptionNamespace
using DecoderFallbackException = DecoderFallbackExceptionNamespace::DecoderFallbackException;
} // namespace System::Private::CoreLib::System::Text
