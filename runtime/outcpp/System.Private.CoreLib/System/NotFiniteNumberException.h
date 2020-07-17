#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Double.h>

namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System {
FORWARD(Exception)
FORWARD(String)
namespace NotFiniteNumberExceptionNamespace {
using namespace Runtime::Serialization;
CLASS(NotFiniteNumberException) {
  public: Double get_OffendingNumber();
  public: void Ctor();
  public: void Ctor(Double offendingNumber);
  public: void Ctor(String message);
  public: void Ctor(String message, Double offendingNumber);
  public: void Ctor(String message, Exception innerException);
  public: void Ctor(String message, Double offendingNumber, Exception innerException);
  protected: void Ctor(SerializationInfo info, StreamingContext context);
  public: void GetObjectData(SerializationInfo info, StreamingContext context);
  private: Double _offendingNumber;
};
} // namespace NotFiniteNumberExceptionNamespace
using NotFiniteNumberException = NotFiniteNumberExceptionNamespace::NotFiniteNumberException;
} // namespace System::Private::CoreLib::System
