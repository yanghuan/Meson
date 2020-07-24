#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Byte.h>
#include <System.Private.CoreLib/System/UInt16.h>

namespace System::Private::CoreLib::System::Diagnostics::Tracing {
namespace ManifestEnvelopeNamespace {
struct ManifestEnvelope {
  public: enum class ManifestFormats : uint8_t {
    SimpleXmlFormat = 1,
  };
  public: ManifestFormats Format;
  public: Byte MajorVersion;
  public: Byte MinorVersion;
  public: Byte Magic;
  public: UInt16 TotalChunks;
  public: UInt16 ChunkNumber;
};
} // namespace ManifestEnvelopeNamespace
using ManifestEnvelope = ManifestEnvelopeNamespace::ManifestEnvelope;
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing
