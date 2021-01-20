#include "Vector3-dep.h"

#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/Char-dep.h>
#include <System.Private.CoreLib/System/Globalization/CultureInfo-dep.h>
#include <System.Private.CoreLib/System/Globalization/NumberFormatInfo-dep.h>
#include <System.Private.CoreLib/System/HashCode-dep.h>
#include <System.Private.CoreLib/System/MathF-dep.h>
#include <System.Private.CoreLib/System/NullReferenceException-dep.h>
#include <System.Private.CoreLib/System/Numerics/Vector3-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/Text/StringBuilder-dep.h>

namespace System::Private::CoreLib::System::Numerics::Vector3Namespace {
using namespace System::Globalization;
using namespace System::Text;

Vector3 Vector3::get_Zero() {
  return rt::default__;
}

Vector3 Vector3::get_One() {
  return Vector3(1, 1, 1);
}

Vector3 Vector3::get_UnitX() {
  return Vector3(1, 0, 0);
}

Vector3 Vector3::get_UnitY() {
  return Vector3(0, 1, 0);
}

Vector3 Vector3::get_UnitZ() {
  return Vector3(0, 0, 1);
}

Int32 Vector3::GetHashCode() {
  return HashCode::Combine(X, Y, Z);
}

Boolean Vector3::Equals(Object obj) {
  if (rt::is<Vector3>(obj)) {
    Vector3 other = (Vector3)obj;
    return Equals(other);
  }
  return false;
}

String Vector3::ToString() {
  return ToString("G", CultureInfo::in::get_CurrentCulture());
}

String Vector3::ToString(String format) {
  return ToString(format, CultureInfo::in::get_CurrentCulture());
}

String Vector3::ToString(String format, IFormatProvider formatProvider) {
  StringBuilder stringBuilder = rt::newobj<StringBuilder>();
  String numberGroupSeparator = NumberFormatInfo::in::GetInstance(formatProvider)->get_NumberGroupSeparator();
  stringBuilder->Append((Char)u'<');
  stringBuilder->Append(((IFormattable)X)->ToString(format, formatProvider));
  stringBuilder->Append(numberGroupSeparator);
  stringBuilder->Append((Char)u' ');
  stringBuilder->Append(((IFormattable)Y)->ToString(format, formatProvider));
  stringBuilder->Append(numberGroupSeparator);
  stringBuilder->Append((Char)u' ');
  stringBuilder->Append(((IFormattable)Z)->ToString(format, formatProvider));
  stringBuilder->Append((Char)u'>');
  return stringBuilder->ToString();
}

Single Vector3::Length() {
  Single x = Dot(*this, *this);
  return MathF::Sqrt(x);
}

Single Vector3::LengthSquared() {
  return Dot(*this, *this);
}

Single Vector3::Distance(Vector3 value1, Vector3 value2) {
  Vector3 vector = value1 - value2;
  Single x = Dot(vector, vector);
  return MathF::Sqrt(x);
}

Single Vector3::DistanceSquared(Vector3 value1, Vector3 value2) {
  Vector3 vector = value1 - value2;
  return Dot(vector, vector);
}

Vector3 Vector3::Normalize(Vector3 value) {
  Single value2 = value.Length();
  return value / value2;
}

Vector3 Vector3::Cross(Vector3 vector1, Vector3 vector2) {
  return Vector3(vector1.Y * vector2.Z - vector1.Z * vector2.Y, vector1.Z * vector2.X - vector1.X * vector2.Z, vector1.X * vector2.Y - vector1.Y * vector2.X);
}

Vector3 Vector3::Reflect(Vector3 vector, Vector3 normal) {
  Single right = Dot(vector, normal);
  Vector3 right2 = normal * right * 2;
  return vector - right2;
}

Vector3 Vector3::Clamp(Vector3 value1, Vector3 min, Vector3 max) {
  return Min(Max(value1, min), max);
}

Vector3 Vector3::Lerp(Vector3 value1, Vector3 value2, Single amount) {
  Vector3 left = value1 * (1 - amount);
  Vector3 right = value2 * amount;
  return left + right;
}

Vector3 Vector3::Transform(Vector3 position, Matrix4x4 matrix) {
  return Vector3(position.X * matrix.M11 + position.Y * matrix.M21 + position.Z * matrix.M31 + matrix.M41, position.X * matrix.M12 + position.Y * matrix.M22 + position.Z * matrix.M32 + matrix.M42, position.X * matrix.M13 + position.Y * matrix.M23 + position.Z * matrix.M33 + matrix.M43);
}

Vector3 Vector3::TransformNormal(Vector3 normal, Matrix4x4 matrix) {
  return Vector3(normal.X * matrix.M11 + normal.Y * matrix.M21 + normal.Z * matrix.M31, normal.X * matrix.M12 + normal.Y * matrix.M22 + normal.Z * matrix.M32, normal.X * matrix.M13 + normal.Y * matrix.M23 + normal.Z * matrix.M33);
}

Vector3 Vector3::Transform(Vector3 value, Quaternion rotation) {
  Single num = rotation.X + rotation.X;
  Single num2 = rotation.Y + rotation.Y;
  Single num3 = rotation.Z + rotation.Z;
  Single num4 = rotation.W * num;
  Single num5 = rotation.W * num2;
  Single num6 = rotation.W * num3;
  Single num7 = rotation.X * num;
  Single num8 = rotation.X * num2;
  Single num9 = rotation.X * num3;
  Single num10 = rotation.Y * num2;
  Single num11 = rotation.Y * num3;
  Single num12 = rotation.Z * num3;
  return Vector3(value.X * (1 - num10 - num12) + value.Y * (num8 - num6) + value.Z * (num9 + num5), value.X * (num8 + num6) + value.Y * (1 - num7 - num12) + value.Z * (num11 - num4), value.X * (num9 - num5) + value.Y * (num11 + num4) + value.Z * (1 - num7 - num10));
}

Vector3 Vector3::Add(Vector3 left, Vector3 right) {
  return left + right;
}

Vector3 Vector3::Subtract(Vector3 left, Vector3 right) {
  return left - right;
}

Vector3 Vector3::Multiply(Vector3 left, Vector3 right) {
  return left * right;
}

Vector3 Vector3::Multiply(Vector3 left, Single right) {
  return left * right;
}

Vector3 Vector3::Multiply(Single left, Vector3 right) {
  return left * right;
}

Vector3 Vector3::Divide(Vector3 left, Vector3 right) {
  return left / right;
}

Vector3 Vector3::Divide(Vector3 left, Single divisor) {
  return left / divisor;
}

Vector3 Vector3::Negate(Vector3 value) {
  return -value;
}

Vector3::Vector3(Single value) {
}

Vector3::Vector3(Vector2 value, Single z) {
}

Vector3::Vector3(Single x, Single y, Single z) {
  X = x;
  Y = y;
  Z = z;
}

void Vector3::CopyTo(Array<Single> array) {
  CopyTo(array, 0);
}

void Vector3::CopyTo(Array<Single> array, Int32 index) {
  if (array == nullptr) {
    rt::throw_exception<NullReferenceException>(SR::get_Arg_NullArgumentNullRef());
  }
  if (index < 0 || index >= array->get_Length()) {
    rt::throw_exception<ArgumentOutOfRangeException>("index", SR::Format(SR::get_Arg_ArgumentOutOfRangeException(), index));
  }
  if (array->get_Length() - index < 3) {
    rt::throw_exception<ArgumentException>(SR::Format(SR::get_Arg_ElementsInSourceIsGreaterThanDestination(), index));
  }
  array[index] = X;
  array[index + 1] = Y;
  array[index + 2] = Z;
}

Boolean Vector3::Equals(Vector3 other) {
  return *this == other;
}

Single Vector3::Dot(Vector3 vector1, Vector3 vector2) {
  return vector1.X * vector2.X + vector1.Y * vector2.Y + vector1.Z * vector2.Z;
}

Vector3 Vector3::Min(Vector3 value1, Vector3 value2) {
  return Vector3((value1.X < value2.X) ? value1.X : value2.X, (value1.Y < value2.Y) ? value1.Y : value2.Y, (value1.Z < value2.Z) ? value1.Z : value2.Z);
}

Vector3 Vector3::Max(Vector3 value1, Vector3 value2) {
  return Vector3((value1.X > value2.X) ? value1.X : value2.X, (value1.Y > value2.Y) ? value1.Y : value2.Y, (value1.Z > value2.Z) ? value1.Z : value2.Z);
}

Vector3 Vector3::Abs(Vector3 value) {
  return Vector3(MathF::Abs(value.X), MathF::Abs(value.Y), MathF::Abs(value.Z));
}

Vector3 Vector3::SquareRoot(Vector3 value) {
  return Vector3(MathF::Sqrt(value.X), MathF::Sqrt(value.Y), MathF::Sqrt(value.Z));
}

Vector3 Vector3::op_Addition(Vector3 left, Vector3 right) {
  return Vector3(left.X + right.X, left.Y + right.Y, left.Z + right.Z);
}

Vector3 Vector3::op_Subtraction(Vector3 left, Vector3 right) {
  return Vector3(left.X - right.X, left.Y - right.Y, left.Z - right.Z);
}

Vector3 Vector3::op_Multiply(Vector3 left, Vector3 right) {
  return Vector3(left.X * right.X, left.Y * right.Y, left.Z * right.Z);
}

Vector3 Vector3::op_Multiply(Vector3 left, Single right) {
  return left * Vector3(right);
}

Vector3 Vector3::op_Multiply(Single left, Vector3 right) {
  return Vector3(left) * right;
}

Vector3 Vector3::op_Division(Vector3 left, Vector3 right) {
  return Vector3(left.X / right.X, left.Y / right.Y, left.Z / right.Z);
}

Vector3 Vector3::op_Division(Vector3 value1, Single value2) {
  return value1 / Vector3(value2);
}

Vector3 Vector3::op_UnaryNegation(Vector3 value) {
  return get_Zero() - value;
}

Boolean Vector3::op_Equality(Vector3 left, Vector3 right) {
  if (left.X == right.X && left.Y == right.Y) {
    return left.Z == right.Z;
  }
  return false;
}

Boolean Vector3::op_Inequality(Vector3 left, Vector3 right) {
  return !(left == right);
}

} // namespace System::Private::CoreLib::System::Numerics::Vector3Namespace
