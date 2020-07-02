#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
FORWARDS(Int32)
FORWARD(Object)
FORWARD_(Array, T1, T2)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Text {
FORWARD(Encoding)
FORWARD(EncoderFallback)
FORWARD(DecoderFallback)
namespace EncodingProviderNamespace {
CLASS(EncodingProvider) {
  public: Encoding GetEncoding(String name);
  public: Encoding GetEncoding(Int32 codepage);
  public: Encoding GetEncoding(String name, EncoderFallback encoderFallback, DecoderFallback decoderFallback);
  public: Encoding GetEncoding(Int32 codepage, EncoderFallback encoderFallback, DecoderFallback decoderFallback);
  public: static void AddProvider(EncodingProvider provider);
  public: static Encoding GetEncodingFromProvider(Int32 codepage);
  public: static Encoding GetEncodingFromProvider(String encodingName);
  public: static Encoding GetEncodingFromProvider(Int32 codepage, EncoderFallback enc, DecoderFallback dec);
  public: static Encoding GetEncodingFromProvider(String encodingName, EncoderFallback enc, DecoderFallback dec);
  private: static Object s_InternalSyncObject;
  private: static Array<EncodingProvider> s_providers;
};
} // namespace EncodingProviderNamespace
using EncodingProvider = EncodingProviderNamespace::EncodingProvider;
} // namespace System::Private::CoreLib::System::Text
