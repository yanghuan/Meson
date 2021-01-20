#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array)
FORWARDS(Byte)
FORWARDS(Guid)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Diagnostics::SymbolStore {
namespace ISymbolDocumentWriterNamespace {
CLASS(ISymbolDocumentWriter) : public object {
  public: void SetCheckSum(Guid algorithmId, Array<Byte> checkSum);
  public: void SetSource(Array<Byte> source);
  public: static constexpr rt::TypeCode code = rt::TypeCode::Interface;
};
} // namespace ISymbolDocumentWriterNamespace
using ISymbolDocumentWriter = ISymbolDocumentWriterNamespace::ISymbolDocumentWriter;
} // namespace System::Private::CoreLib::System::Diagnostics::SymbolStore
