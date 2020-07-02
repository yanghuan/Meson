#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Guid)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices {
FORWARD(ComEventsSink)
namespace ComEventsInfoNamespace {
CLASS(ComEventsInfo) {
  protected: void Finalize();
  public: static ComEventsInfo Find(Object rcw);
  public: static ComEventsInfo FromObject(Object rcw);
  public: ComEventsSink FindSink(Guid& iid);
  public: ComEventsSink AddSink(Guid& iid);
  public: ComEventsSink RemoveSink(ComEventsSink sink);
  private: ComEventsSink _sinks;
  private: Object _rcw;
};
} // namespace ComEventsInfoNamespace
using ComEventsInfo = ComEventsInfoNamespace::ComEventsInfo;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices