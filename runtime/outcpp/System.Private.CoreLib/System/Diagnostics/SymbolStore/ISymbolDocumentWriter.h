#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Guid)
FORWARD_(Array, T1, T2)
FORWARDS(Byte)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Diagnostics::SymbolStore {
namespace ISymbolDocumentWriterNamespace {
CLASS(ISymbolDocumentWriter) {
  public: void SetCheckSum(Guid algorithmId, Array<Byte> checkSum);
  public: void SetSource(Array<Byte> source);
};
} // namespace ISymbolDocumentWriterNamespace
using ISymbolDocumentWriter = ISymbolDocumentWriterNamespace::ISymbolDocumentWriter;
} // namespace System::Private::CoreLib::System::Diagnostics::SymbolStore
