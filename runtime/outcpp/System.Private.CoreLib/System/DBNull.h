#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System {
enum class TypeCode;
FORWARD(IFormatProvider)
FORWARD(String)
namespace DBNullNamespace {
using namespace Runtime::Serialization;
CLASS(DBNull) {
  public: void GetObjectData(SerializationInfo info, StreamingContext context);
  public: String ToString();
  public: String ToString(IFormatProvider provider);
  public: TypeCode GetTypeCode();
  public: static DBNull Value;
};
} // namespace DBNullNamespace
using DBNull = DBNullNamespace::DBNull;
} // namespace System::Private::CoreLib::System
