#pragma once

#include <System.Private.CoreLib/System/ArgumentException.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Nullable.h>

namespace System::Private::CoreLib::System {
FORWARD(Exception)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System::Globalization {
namespace CultureNotFoundExceptionNamespace {
using namespace System::Runtime::Serialization;
CLASS(CultureNotFoundException) : public ArgumentException::in {
  public: Nullable<Int32> get_InvalidCultureId();
  public: String get_InvalidCultureName();
  private: static String get_DefaultMessage();
  private: String get_FormattedInvalidCultureId();
  public: String get_Message();
  public: void ctor();
  public: void ctor(String message);
  public: void ctor(String paramName, String message);
  public: void ctor(String message, Exception innerException);
  public: void ctor(String paramName, String invalidCultureName, String message);
  public: void ctor(String message, String invalidCultureName, Exception innerException);
  public: void ctor(String message, Int32 invalidCultureId, Exception innerException);
  public: void ctor(String paramName, Int32 invalidCultureId, String message);
  public: void ctor(SerializationInfo info, StreamingContext context);
  public: void GetObjectData(SerializationInfo info, StreamingContext context);
  private: String _invalidCultureName;
  private: Nullable<Int32> _invalidCultureId;
};
} // namespace CultureNotFoundExceptionNamespace
using CultureNotFoundException = CultureNotFoundExceptionNamespace::CultureNotFoundException;
} // namespace System::Private::CoreLib::System::Globalization
