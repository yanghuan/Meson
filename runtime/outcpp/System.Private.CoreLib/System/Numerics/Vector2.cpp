#include "Vector2-dep.h"

#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/Globalization/CultureInfo-dep.h>
#include <System.Private.CoreLib/System/Globalization/NumberFormatInfo-dep.h>
#include <System.Private.CoreLib/System/HashCode-dep.h>
#include <System.Private.CoreLib/System/MathF-dep.h>
#include <System.Private.CoreLib/System/NullReferenceException-dep.h>
#include <System.Private.CoreLib/System/Numerics/Vector2-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/Text/StringBuilder-dep.h>

namespace System::Private::CoreLib::System::Numerics::Vector2Namespace {
using namespace System::Globalization;
using namespace System::Text;

Vector2 Vector2::get_Zero() {
  return Vector2();
}

Vector2 Vector2::get_One() {
  return Vector2(1, 1);
}

Vector2 Vector2::get_UnitX() {
  return Vector2(1, 0);
}

Vector2 Vector2::get_UnitY() {
  return Vector2(0, 1);
}

Int32 Vector2::GetHashCode() {
  return HashCode::Combine(X.GetHashCode(), Y.GetHashCode());
}

Boolean Vector2::Equals(Object obj) {
  if (rt::is<Vector2>(obj)) {
    Vector2 other = (Vector2)obj;
    return Equals(other);
  }
  return false;
}

String Vector2::ToString() {
  return ToString("G", CultureInfo::in::get_CurrentCulture());
}

String Vector2::ToString(String format) {
  return ToString(format, CultureInfo::in::get_CurrentCulture());
}

String Vector2::ToString(String format, IFormatProvider formatProvider) {
  StringBuilder stringBuilder = rt::newobj<StringBuilder>();
  String numberGroupSeparator = NumberFormatInfo::in::GetInstance(formatProvider)->get_NumberGroupSeparator();
  stringBuilder->Append(60);
  stringBuilder->Append(X.ToString(format, formatProvider));
  stringBuilder->Append(numberGroupSeparator);
  stringBuilder->Append(32);
  stringBuilder->Append(Y.ToString(format, formatProvider));
  stringBuilder->Append(62);
  return stringBuilder->ToString();
}

Single Vector2::Length() {
  Single x = Dot(*this, *this);
  return MathF::Sqrt(x);
}

Single Vector2::LengthSquared() {
  return Dot(*this, *this);
}

Single Vector2::Distance(Vector2 value1, Vector2 value2) {
  Vector2 vector = value1 - value2;
  Single x = Dot(vector, vector);
  return MathF::Sqrt(x);
}

Single Vector2::DistanceSquared(Vector2 value1, Vector2 value2) {
  Vector2 vector = value1 - value2;
  return Dot(vector, vector);
}

Vector2 Vector2::Normalize(Vector2 value) {
  Single value2 = value.Length();
  return value / value2;
}

Vector2 Vector2::Reflect(Vector2 vector, Vector2 normal) {
  Single num = Dot(vector, normal);
  return vector - 2 * num * normal;
}

Vector2 Vector2::Clamp(Vector2 value1, Vector2 min, Vector2 max) {
  return Min(Max(value1, min), max);
}

Vector2 Vector2::Lerp(Vector2 value1, Vector2 value2, Single amount) {
  return value1 + (value2 - value1) * amount;
}

Vector2 Vector2::Transform(Vector2 position, Matrix3x2 matrix) {
  return Vector2(position.X * matrix.M11 + position.Y * matrix.M21 + matrix.M31, position.X * matrix.M12 + position.Y * matrix.M22 + matrix.M32);
}

Vector2 Vector2::Transform(Vector2 position, Matrix4x4 matrix) {
  return Vector2(position.X * matrix.M11 + position.Y * matrix.M21 + matrix.M41, position.X * matrix.M12 + position.Y * matrix.M22 + matrix.M42);
}

Vector2 Vector2::TransformNormal(Vector2 normal, Matrix3x2 matrix) {
  return Vector2(normal.X * matrix.M11 + normal.Y * matrix.M21, normal.X * matrix.M12 + normal.Y * matrix.M22);
}

Vector2 Vector2::TransformNormal(Vector2 normal, Matrix4x4 matrix) {
  return Vector2(normal.X * matrix.M11 + normal.Y * matrix.M21, normal.X * matrix.M12 + normal.Y * matrix.M22);
}

Vector2 Vector2::Transform(Vector2 value, Quaternion rotation) {
  Single num = rotation.X + rotation.X;
  Single num2 = rotation.Y + rotation.Y;
  Single num3 = rotation.Z + rotation.Z;
  Single num4 = rotation.W * num3;
  Single num5 = rotation.X * num;
  Single num6 = rotation.X * num2;
  Single num7 = rotation.Y * num2;
  Single num8 = rotation.Z * num3;
  return Vector2(value.X * (1 - num7 - num8) + value.Y * (num6 - num4), value.X * (num6 + num4) + value.Y * (1 - num5 - num8));
}

Vector2 Vector2::Add(Vector2 left, Vector2 right) {
  return left + right;
}

Vector2 Vector2::Subtract(Vector2 left, Vector2 right) {
  return left - right;
}

Vector2 Vector2::Multiply(Vector2 left, Vector2 right) {
  return left * right;
}

Vector2 Vector2::Multiply(Vector2 left, Single right) {
  return left * right;
}

Vector2 Vector2::Multiply(Single left, Vector2 right) {
  return left * right;
}

Vector2 Vector2::Divide(Vector2 left, Vector2 right) {
  return left / right;
}

Vector2 Vector2::Divide(Vector2 left, Single divisor) {
  return left / divisor;
}

Vector2 Vector2::Negate(Vector2 value) {
  return -value;
}

Vector2::Vector2(Single value) {
}

Vector2::Vector2(Single x, Single y) {
  X = x;
  Y = y;
}

void Vector2::CopyTo(Array<Single> array) {
  CopyTo(array, 0);
}

void Vector2::CopyTo(Array<Single> array, Int32 index) {
  if (array == nullptr) {
    rt::throw_exception<NullReferenceException>(SR::get_Arg_NullArgumentNullRef());
  }
  if (index < 0 || index >= array->get_Length()) {
    rt::throw_exception<ArgumentOutOfRangeException>("index", SR::Format(SR::get_Arg_ArgumentOutOfRangeException(), index));
  }
  if (array->get_Length() - index < 2) {
    rt::throw_exception<ArgumentException>(SR::Format(SR::get_Arg_ElementsInSourceIsGreaterThanDestination(), index));
  }
  array[index] = X;
  array[index + 1] = Y;
}

Boolean Vector2::Equals(Vector2 other) {
  return *this == other;
}

Single Vector2::Dot(Vector2 value1, Vector2 value2) {
  return value1.X * value2.X + value1.Y * value2.Y;
}

Vector2 Vector2::Min(Vector2 value1, Vector2 value2) {
  return Vector2((value1.X < value2.X) ? value1.X : value2.X, (value1.Y < value2.Y) ? value1.Y : value2.Y);
}

Vector2 Vector2::Max(Vector2 value1, Vector2 value2) {
  return Vector2((value1.X > value2.X) ? value1.X : value2.X, (value1.Y > value2.Y) ? value1.Y : value2.Y);
}

Vector2 Vector2::Abs(Vector2 value) {
  return Vector2(MathF::Abs(value.X), MathF::Abs(value.Y));
}

Vector2 Vector2::SquareRoot(Vector2 value) {
  return Vector2(MathF::Sqrt(value.X), MathF::Sqrt(value.Y));
}

Vector2 Vector2::op_Addition(Vector2 left, Vector2 right) {
  return Vector2(left.X + right.X, left.Y + right.Y);
}

Vector2 Vector2::op_Subtraction(Vector2 left, Vector2 right) {
  return Vector2(left.X - right.X, left.Y - right.Y);
}

Vector2 Vector2::op_Multiply(Vector2 left, Vector2 right) {
  return Vector2(left.X * right.X, left.Y * right.Y);
}

Vector2 Vector2::op_Multiply(Single left, Vector2 right) {
  return Vector2(left, left) * right;
}

Vector2 Vector2::op_Multiply(Vector2 left, Single right) {
  return left * Vector2(right, right);
}

Vector2 Vector2::op_Division(Vector2 left, Vector2 right) {
  return Vector2(left.X / right.X, left.Y / right.Y);
}

Vector2 Vector2::op_Division(Vector2 value1, Single value2) {
  return value1 / Vector2(value2);
}

Vector2 Vector2::op_UnaryNegation(Vector2 value) {
  return get_Zero() - value;
}

Boolean Vector2::op_Equality(Vector2 left, Vector2 right) {
  if (left.X == right.X) {
    return left.Y == right.Y;
  }
  return false;
}

Boolean Vector2::op_Inequality(Vector2 left, Vector2 right) {
  return !(left == right);
}

} // namespace System::Private::CoreLib::System::Numerics::Vector2Namespace
