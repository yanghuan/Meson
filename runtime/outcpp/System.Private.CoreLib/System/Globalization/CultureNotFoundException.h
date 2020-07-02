#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Nullable.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System::Globalization {
namespace CultureNotFoundExceptionNamespace {
using namespace ::System::Private::CoreLib::System::Runtime::Serialization;
CLASS(CultureNotFoundException) {
  public: Nullable<Int32> get_InvalidCultureId();
  public: String get_InvalidCultureName();
  private: static String get_DefaultMessage();
  private: String get_FormattedInvalidCultureId();
  public: String get_Message();
  public: void GetObjectData(SerializationInfo info, StreamingContext context);
  private: String _invalidCultureName;
  private: Nullable<Int32> _invalidCultureId;
};
} // namespace CultureNotFoundExceptionNamespace
using CultureNotFoundException = CultureNotFoundExceptionNamespace::CultureNotFoundException;
} // namespace System::Private::CoreLib::System::Globalization
