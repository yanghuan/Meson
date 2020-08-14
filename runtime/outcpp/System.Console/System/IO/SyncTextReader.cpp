#include "SyncTextReader-dep.h"

#include <System.Console/System/IO/SyncTextReader-dep.h>
#include <System.Console/System/SR-dep.h>
#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>

namespace System::Console::System::IO::SyncTextReaderNamespace {
using namespace ::System::Private::CoreLib::System;

SyncTextReader SyncTextReader___::GetSynchronizedTextReader(TextReader reader) {
  auto default = (rt::as<SyncTextReader>(reader));
  if (default != nullptr) default = rt::newobj<SyncTextReader>(reader);

  return default;
}

void SyncTextReader___::ctor(TextReader t) {
  _in = t;
}

void SyncTextReader___::Dispose(Boolean disposing) {
  if (disposing) {
    {
      rt::lock((SyncTextReader)this);
      _in->Dispose();
    }
  }
}

Int32 SyncTextReader___::Peek() {
  {
    rt::lock((SyncTextReader)this);
    return _in->Peek();
  }
}

Int32 SyncTextReader___::Read() {
  {
    rt::lock((SyncTextReader)this);
    return _in->Read();
  }
}

Int32 SyncTextReader___::Read(Array<Char> buffer, Int32 index, Int32 count) {
  {
    rt::lock((SyncTextReader)this);
    return _in->Read(buffer, index, count);
  }
}

Int32 SyncTextReader___::ReadBlock(Array<Char> buffer, Int32 index, Int32 count) {
  {
    rt::lock((SyncTextReader)this);
    return _in->ReadBlock(buffer, index, count);
  }
}

String SyncTextReader___::ReadLine() {
  {
    rt::lock((SyncTextReader)this);
    return _in->ReadLine();
  }
}

String SyncTextReader___::ReadToEnd() {
  {
    rt::lock((SyncTextReader)this);
    return _in->ReadToEnd();
  }
}

Task<String> SyncTextReader___::ReadLineAsync() {
  return Task::in::FromResult(ReadLine());
}

Task<String> SyncTextReader___::ReadToEndAsync() {
  return Task::in::FromResult(ReadToEnd());
}

Task<Int32> SyncTextReader___::ReadBlockAsync(Array<Char> buffer, Int32 index, Int32 count) {
  if (buffer == nullptr) {
    rt::throw_exception<ArgumentNullException>("buffer", SR::get_ArgumentNull_Buffer());
  }
  if (index < 0 || count < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>((index < 0) ? "index" : "count", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  if (buffer->get_Length() - index < count) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_InvalidOffLen());
  }
  return Task::in::FromResult(ReadBlock(buffer, index, count));
}

Task<Int32> SyncTextReader___::ReadAsync(Array<Char> buffer, Int32 index, Int32 count) {
  if (buffer == nullptr) {
    rt::throw_exception<ArgumentNullException>("buffer", SR::get_ArgumentNull_Buffer());
  }
  if (index < 0 || count < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>((index < 0) ? "index" : "count", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  if (buffer->get_Length() - index < count) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_InvalidOffLen());
  }
  return Task::in::FromResult(Read(buffer, index, count));
}

} // namespace System::Console::System::IO::SyncTextReaderNamespace
