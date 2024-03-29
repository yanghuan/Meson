#pragma once

#include <System.Private.CoreLib/System/IO/TextReader.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array)
FORWARDS(Boolean)
FORWARDS(Char)
FORWARDS(Int32)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading::Tasks {
FORWARD_(Task)
} // namespace System::Private::CoreLib::System::Threading::Tasks
namespace System::Console::System::IO {
namespace SyncTextReaderNamespace {
using namespace ::System::Private::CoreLib::System;
using namespace ::System::Private::CoreLib::System::IO;
using namespace ::System::Private::CoreLib::System::Threading::Tasks;
CLASS(SyncTextReader) : public TextReader::in {
  public: static SyncTextReaderNamespace::SyncTextReader GetSynchronizedTextReader(TextReader reader);
  public: void ctor(TextReader t);
  protected: void Dispose(Boolean disposing);
  public: Int32 Peek();
  public: Int32 Read();
  public: Int32 Read(Array<Char> buffer, Int32 index, Int32 count);
  public: Int32 ReadBlock(Array<Char> buffer, Int32 index, Int32 count);
  public: String ReadLine();
  public: String ReadToEnd();
  public: Task<String> ReadLineAsync();
  public: Task<String> ReadToEndAsync();
  public: Task<Int32> ReadBlockAsync(Array<Char> buffer, Int32 index, Int32 count);
  public: Task<Int32> ReadAsync(Array<Char> buffer, Int32 index, Int32 count);
  public: TextReader _in;
};
} // namespace SyncTextReaderNamespace
using SyncTextReader = SyncTextReaderNamespace::SyncTextReader;
} // namespace System::Console::System::IO
