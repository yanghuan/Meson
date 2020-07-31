#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Byte)
FORWARDS(Guid)
FORWARDS(Int32)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection {
enum class FieldAttributes;
} // namespace System::Private::CoreLib::System::Reflection
namespace System::Private::CoreLib::System::Diagnostics::SymbolStore {
enum class SymAddressKind;
FORWARD(ISymbolDocumentWriter)
FORWARDS(SymbolToken)
namespace ISymbolWriterNamespace {
using namespace Reflection;
CLASS(ISymbolWriter) : public Object::in {
  public: ISymbolDocumentWriter DefineDocument(String url, Guid language, Guid languageVendor, Guid documentType);
  public: void OpenMethod(SymbolToken method);
  public: void CloseMethod();
  public: void DefineSequencePoints(ISymbolDocumentWriter document, Array<Int32> offsets, Array<Int32> lines, Array<Int32> columns, Array<Int32> endLines, Array<Int32> endColumns);
  public: Int32 OpenScope(Int32 startOffset);
  public: void CloseScope(Int32 endOffset);
  public: void DefineLocalVariable(String name, FieldAttributes attributes, Array<Byte> signature, SymAddressKind addrKind, Int32 addr1, Int32 addr2, Int32 addr3, Int32 startOffset, Int32 endOffset);
  public: void UsingNamespace(String fullName);
};
} // namespace ISymbolWriterNamespace
using ISymbolWriter = ISymbolWriterNamespace::ISymbolWriter;
} // namespace System::Private::CoreLib::System::Diagnostics::SymbolStore
