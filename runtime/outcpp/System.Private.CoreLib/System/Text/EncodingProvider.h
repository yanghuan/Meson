#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array)
FORWARDS(Int32)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(Dictionary, TKey, TValue)
FORWARD(IEnumerable, T)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System::Text {
FORWARD(DecoderFallback)
FORWARD(EncoderFallback)
FORWARD(Encoding)
FORWARD(EncodingInfo)
namespace EncodingProviderNamespace {
using namespace System::Collections::Generic;
CLASS(EncodingProvider) : public object {
  public: void ctor();
  public: Encoding GetEncoding(String name);
  public: Encoding GetEncoding(Int32 codepage);
  public: Encoding GetEncoding(String name, EncoderFallback encoderFallback, DecoderFallback decoderFallback);
  public: Encoding GetEncoding(Int32 codepage, EncoderFallback encoderFallback, DecoderFallback decoderFallback);
  public: IEnumerable<EncodingInfo> GetEncodings();
  public: static void AddProvider(EncodingProvider provider);
  public: static Encoding GetEncodingFromProvider(Int32 codepage);
  public: static Dictionary<Int32, EncodingInfo> GetEncodingListFromProviders();
  public: static Encoding GetEncodingFromProvider(String encodingName);
  public: static Encoding GetEncodingFromProvider(Int32 codepage, EncoderFallback enc, DecoderFallback dec);
  public: static Encoding GetEncodingFromProvider(String encodingName, EncoderFallback enc, DecoderFallback dec);
  public: static void cctor();
  private: static Object s_InternalSyncObject;
  private: static Array<EncodingProvider> s_providers;
};
} // namespace EncodingProviderNamespace
using EncodingProvider = EncodingProviderNamespace::EncodingProvider;
} // namespace System::Private::CoreLib::System::Text
