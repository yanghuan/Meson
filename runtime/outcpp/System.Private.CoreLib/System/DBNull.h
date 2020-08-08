#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(ISerializable)
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System {
enum class TypeCode;
FORWARD(IConvertible)
FORWARD(IFormatProvider)
FORWARD(String)
namespace DBNullNamespace {
using namespace Runtime::Serialization;
CLASS(DBNull) : public Object::in {
  public: using interface = rt::TypeList<ISerializable, IConvertible>;
  private: void Ctor();
  private: void Ctor(SerializationInfo info, StreamingContext context);
  public: void GetObjectData(SerializationInfo info, StreamingContext context);
  public: String ToString();
  public: String ToString(IFormatProvider provider);
  public: TypeCode GetTypeCode();
  private: static void SCtor();
  public: static DBNull Value;
};
} // namespace DBNullNamespace
using DBNull = DBNullNamespace::DBNull;
} // namespace System::Private::CoreLib::System
