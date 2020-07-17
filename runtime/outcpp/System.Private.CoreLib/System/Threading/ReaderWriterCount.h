#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Int64.h>

namespace System::Private::CoreLib::System::Threading {
namespace ReaderWriterCountNamespace {
CLASS(ReaderWriterCount) {
  public: void Ctor();
  public: Int64 lockID;
  public: Int32 readercount;
  public: Int32 writercount;
  public: Int32 upgradecount;
  public: ReaderWriterCount next;
};
} // namespace ReaderWriterCountNamespace
using ReaderWriterCount = ReaderWriterCountNamespace::ReaderWriterCount;
} // namespace System::Private::CoreLib::System::Threading
