#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Double.h>

namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System {
namespace NotFiniteNumberExceptionNamespace {
using namespace Runtime::Serialization;
CLASS(NotFiniteNumberException) {
  public: Double get_OffendingNumber();
  public: void GetObjectData(SerializationInfo info, StreamingContext context);
  private: Double _offendingNumber;
};
} // namespace NotFiniteNumberExceptionNamespace
using NotFiniteNumberException = NotFiniteNumberExceptionNamespace::NotFiniteNumberException;
} // namespace System::Private::CoreLib::System
