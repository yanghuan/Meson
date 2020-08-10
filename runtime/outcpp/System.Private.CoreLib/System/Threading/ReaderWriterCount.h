#pragma once

#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Int64.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Threading {
namespace ReaderWriterCountNamespace {
CLASS(ReaderWriterCount) : public Object::in {
  public: void ctor();
  public: Int64 lockID;
  public: Int32 readercount;
  public: Int32 writercount;
  public: Int32 upgradecount;
  public: ReaderWriterCount next;
};
} // namespace ReaderWriterCountNamespace
using ReaderWriterCount = ReaderWriterCountNamespace::ReaderWriterCount;
} // namespace System::Private::CoreLib::System::Threading
