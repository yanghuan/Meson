#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(ISerializable)
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System {
enum class TypeCode : int32_t;
FORWARDS(Boolean)
FORWARDS(Byte)
FORWARDS(Char)
FORWARDS(DateTime)
FORWARDS(Decimal)
FORWARDS(Double)
FORWARD(IConvertible)
FORWARD(IFormatProvider)
FORWARDS(Int16)
FORWARDS(Int32)
FORWARDS(Int64)
FORWARDS(SByte)
FORWARDS(Single)
FORWARD(String)
FORWARD(Type)
FORWARDS(UInt16)
FORWARDS(UInt32)
FORWARDS(UInt64)
namespace DBNullNamespace {
using namespace System::Runtime::Serialization;
CLASS(DBNull) : public object {
  public: using interface = rt::TypeList<ISerializable, IConvertible>;
  public: void ctor();
  public: void ctor(SerializationInfo info, StreamingContext context);
  public: void GetObjectData(SerializationInfo info, StreamingContext context);
  public: String ToString();
  public: String ToString(IFormatProvider provider);
  public: TypeCode GetTypeCode();
  private: Boolean ToBooleanOfIConvertible(IFormatProvider provider);
  private: Char ToCharOfIConvertible(IFormatProvider provider);
  private: SByte ToSByteOfIConvertible(IFormatProvider provider);
  private: Byte ToByteOfIConvertible(IFormatProvider provider);
  private: Int16 ToInt16OfIConvertible(IFormatProvider provider);
  private: UInt16 ToUInt16OfIConvertible(IFormatProvider provider);
  private: Int32 ToInt32OfIConvertible(IFormatProvider provider);
  private: UInt32 ToUInt32OfIConvertible(IFormatProvider provider);
  private: Int64 ToInt64OfIConvertible(IFormatProvider provider);
  private: UInt64 ToUInt64OfIConvertible(IFormatProvider provider);
  private: Single ToSingleOfIConvertible(IFormatProvider provider);
  private: Double ToDoubleOfIConvertible(IFormatProvider provider);
  private: Decimal ToDecimalOfIConvertible(IFormatProvider provider);
  private: DateTime ToDateTimeOfIConvertible(IFormatProvider provider);
  private: Object ToTypeOfIConvertible(Type type, IFormatProvider provider);
  public: static void cctor();
  public: static DBNull Value;
};
} // namespace DBNullNamespace
using DBNull = DBNullNamespace::DBNull;
} // namespace System::Private::CoreLib::System
