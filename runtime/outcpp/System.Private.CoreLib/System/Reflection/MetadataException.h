#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Exception.h>
#include <System.Private.CoreLib/System/Int32.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection {
namespace MetadataExceptionNamespace {
CLASS(MetadataException) : public Exception::in {
  public: void Ctor(Int32 hr);
  public: String ToString();
  private: Int32 m_hr;
};
} // namespace MetadataExceptionNamespace
using MetadataException = MetadataExceptionNamespace::MetadataException;
} // namespace System::Private::CoreLib::System::Reflection
