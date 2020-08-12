#pragma once

#include <System.Private.CoreLib/System/ArithmeticException.h>
#include <System.Private.CoreLib/System/Double.h>

namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System {
FORWARD(Exception)
FORWARD(String)
namespace NotFiniteNumberExceptionNamespace {
using namespace System::Runtime::Serialization;
CLASS(NotFiniteNumberException) : public ArithmeticException::in {
  public: Double get_OffendingNumber();
  public: void ctor();
  public: void ctor(Double offendingNumber);
  public: void ctor(String message);
  public: void ctor(String message, Double offendingNumber);
  public: void ctor(String message, Exception innerException);
  public: void ctor(String message, Double offendingNumber, Exception innerException);
  protected: void ctor(SerializationInfo info, StreamingContext context);
  public: void GetObjectData(SerializationInfo info, StreamingContext context);
  private: Double _offendingNumber;
};
} // namespace NotFiniteNumberExceptionNamespace
using NotFiniteNumberException = NotFiniteNumberExceptionNamespace::NotFiniteNumberException;
} // namespace System::Private::CoreLib::System
