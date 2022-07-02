#pragma once

#include <System.Private.CoreLib/Interop.h>
#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/Char.h>
#include <System.Private.CoreLib/System/Object.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System::Runtime::CompilerServices {
FORWARDS(ObjectHandleOnStack)
FORWARDS(QCallTypeHandle)
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
namespace System::Private::CoreLib::System::Reflection {
enum class CorElementType : uint8_t;
} // namespace System::Private::CoreLib::System::Reflection
namespace System::Private::CoreLib::System {
enum class TypeCode : int32_t;
FORWARD_(Array)
FORWARDS(Byte)
FORWARDS(DateTime)
FORWARDS(Decimal)
FORWARDS(Double)
FORWARD_(IComparable)
FORWARD(IConvertible)
FORWARD(IFormatProvider)
FORWARD(IFormattable)
FORWARDS(Int16)
FORWARDS(Int32)
FORWARDS(Int64)
FORWARDS(ReadOnlySpan, T)
FORWARD(RuntimeType)
FORWARDS(SByte)
FORWARDS(Single)
FORWARD(String)
FORWARD(Type)
FORWARDS(UInt16)
FORWARDS(UInt32)
FORWARDS(UInt64)
namespace EnumNamespace {
using namespace System::Reflection;
using namespace System::Runtime::CompilerServices;
CLASS(Enum) : public ValueType::in {
  public: using interface = rt::TypeList<IComparable<>, IFormattable, IConvertible>;
  public: CLASS(EnumInfo) : public object {
    public: void ctor(Boolean hasFlagsAttribute, Array<UInt64> values, Array<String> names);
    public: Boolean HasFlagsAttribute;
    public: Array<UInt64> Values;
    public: Array<String> Names;
  };
  private: static void GetEnumValuesAndNames(QCallTypeHandle enumType, ObjectHandleOnStack values, ObjectHandleOnStack names, Interop::BOOL getNames);
  public: Boolean Equals(Object obj);
  private: static Object InternalBoxEnum(RuntimeType enumType, Int64 value);
  private: CorElementType InternalGetCorElementType();
  public: static RuntimeType InternalGetUnderlyingType(RuntimeType enumType);
  private: Boolean InternalHasFlag(Enum flags);
  private: static EnumInfo GetEnumInfo(RuntimeType enumType, Boolean getNames = true);
  private: String ValueToString();
  private: String ValueToHexString();
  private: static String ValueToHexString(Object value);
  public: static String GetEnumName(RuntimeType enumType, UInt64 ulValue);
  private: static String GetEnumName(EnumInfo enumInfo, UInt64 ulValue);
  private: static String InternalFormat(RuntimeType enumType, UInt64 value);
  private: static String InternalFlagsFormat(RuntimeType enumType, UInt64 result);
  private: static String InternalFlagsFormat(RuntimeType enumType, EnumInfo enumInfo, UInt64 resultValue);
  public: static UInt64 ToUInt64(Object value);
  public: template <class TEnum>
  static String GetName(TEnum value);
  public: static String GetName(Type enumType, Object value);
  public: template <class TEnum>
  static Array<String> GetNames();
  public: static Array<String> GetNames(Type enumType);
  public: static Array<String> InternalGetNames(RuntimeType enumType);
  public: static Type GetUnderlyingType(Type enumType);
  public: template <class TEnum>
  static Array<TEnum> GetValues();
  public: static Array<> GetValues(Type enumType);
  public: Boolean HasFlag(Enum flag);
  public: static Array<UInt64> InternalGetValues(RuntimeType enumType);
  public: template <class TEnum>
  static Boolean IsDefined(TEnum value);
  public: static Boolean IsDefined(Type enumType, Object value);
  public: static Object Parse(Type enumType, String value);
  public: static Object Parse(Type enumType, String value, Boolean ignoreCase);
  public: template <class TEnum>
  static TEnum Parse(String value);
  public: template <class TEnum>
  static TEnum Parse(String value, Boolean ignoreCase);
  public: static Boolean TryParse(Type enumType, String value, Object& result);
  public: static Boolean TryParse(Type enumType, String value, Boolean ignoreCase, Object& result);
  private: static Boolean TryParse(Type enumType, String value, Boolean ignoreCase, Boolean throwOnFailure, Object& result);
  public: template <class TEnum>
  static Boolean TryParse(String value, TEnum& result);
  public: template <class TEnum>
  static Boolean TryParse(String value, Boolean ignoreCase, TEnum& result);
  private: template <class TEnum>
  static Boolean TryParse(String value, Boolean ignoreCase, Boolean throwOnFailure, TEnum& result);
  private: static Boolean TryParseInt32Enum(RuntimeType enumType, String originalValueString, ReadOnlySpan<Char> value, Int32 minInclusive, Int32 maxInclusive, Boolean ignoreCase, Boolean throwOnFailure, TypeCode type, Int32& result);
  private: static Boolean TryParseUInt32Enum(RuntimeType enumType, String originalValueString, ReadOnlySpan<Char> value, UInt32 maxInclusive, Boolean ignoreCase, Boolean throwOnFailure, TypeCode type, UInt32& result);
  private: static Boolean TryParseInt64Enum(RuntimeType enumType, String originalValueString, ReadOnlySpan<Char> value, Boolean ignoreCase, Boolean throwOnFailure, Int64& result);
  private: static Boolean TryParseUInt64Enum(RuntimeType enumType, String originalValueString, ReadOnlySpan<Char> value, Boolean ignoreCase, Boolean throwOnFailure, UInt64& result);
  private: static Boolean TryParseRareEnum(RuntimeType enumType, String originalValueString, ReadOnlySpan<Char> value, Boolean ignoreCase, Boolean throwOnFailure, Object& result);
  private: static Boolean TryParseByName(RuntimeType enumType, String originalValueString, ReadOnlySpan<Char> value, Boolean ignoreCase, Boolean throwOnFailure, UInt64& result);
  private: static Boolean StartsNumber(Char c);
  public: static Object ToObject(Type enumType, Object value);
  public: static String Format(Type enumType, Object value, String format);
  public: Object GetValue();
  private: UInt64 ToUInt64();
  public: Int32 GetHashCode();
  public: String ToString();
  public: Int32 CompareTo(Object target);
  public: String ToString(String format, IFormatProvider provider);
  public: String ToString(String format);
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
  public: static Object ToObject(Type enumType, SByte value);
  public: static Object ToObject(Type enumType, Int16 value);
  public: static Object ToObject(Type enumType, Int32 value);
  public: static Object ToObject(Type enumType, Byte value);
  public: static Object ToObject(Type enumType, UInt16 value);
  public: static Object ToObject(Type enumType, UInt32 value);
  public: static Object ToObject(Type enumType, Int64 value);
  public: static Object ToObject(Type enumType, UInt64 value);
  private: static Object ToObject(Type enumType, Char value);
  private: static Object ToObject(Type enumType, Boolean value);
  private: static RuntimeType ValidateRuntimeType(Type enumType);
  public: void ctor();
  private: static constexpr Char EnumSeparatorChar = u',';
};
} // namespace EnumNamespace
using Enum = EnumNamespace::Enum;
} // namespace System::Private::CoreLib::System
