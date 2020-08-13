#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(ISerializable)
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System {
enum class TypeCode : int32_t;
FORWARD(IConvertible)
FORWARD(IFormatProvider)
FORWARD(String)
namespace DBNullNamespace {
using namespace System::Runtime::Serialization;
CLASS(DBNull) : public Object::in {
  public: using interface = rt::TypeList<ISerializable, IConvertible>;
  private: void ctor();
  private: void ctor(SerializationInfo info, StreamingContext context);
  public: void GetObjectData(SerializationInfo info, StreamingContext context);
  public: String ToString();
  public: String ToString(IFormatProvider provider);
  public: TypeCode GetTypeCode();
  private: static void cctor();
  public: static DBNull Value;
};
} // namespace DBNullNamespace
using DBNull = DBNullNamespace::DBNull;
} // namespace System::Private::CoreLib::System
