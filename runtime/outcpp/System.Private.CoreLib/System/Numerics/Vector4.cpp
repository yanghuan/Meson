#include "Vector4-dep.h"

#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/Globalization/CultureInfo-dep.h>
#include <System.Private.CoreLib/System/Globalization/NumberFormatInfo-dep.h>
#include <System.Private.CoreLib/System/HashCode-dep.h>
#include <System.Private.CoreLib/System/MathF-dep.h>
#include <System.Private.CoreLib/System/NullReferenceException-dep.h>
#include <System.Private.CoreLib/System/Numerics/Vector4-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/Text/StringBuilder-dep.h>

namespace System::Private::CoreLib::System::Numerics::Vector4Namespace {
using namespace System::Globalization;
using namespace System::Text;

Vector4 Vector4::get_Zero() {
  return Vector4();
}

Vector4 Vector4::get_One() {
  return Vector4(1, 1, 1, 1);
}

Vector4 Vector4::get_UnitX() {
  return Vector4(1, 0, 0, 0);
}

Vector4 Vector4::get_UnitY() {
  return Vector4(0, 1, 0, 0);
}

Vector4 Vector4::get_UnitZ() {
  return Vector4(0, 0, 1, 0);
}

Vector4 Vector4::get_UnitW() {
  return Vector4(0, 0, 0, 1);
}

Int32 Vector4::GetHashCode() {
  return HashCode::Combine(X.GetHashCode(), Y.GetHashCode(), Z.GetHashCode(), W.GetHashCode());
}

Boolean Vector4::Equals(Object obj) {
  if (rt::is<Vector4>(obj)) {
    Vector4 other = (Vector4)obj;
    return Equals(other);
  }
  return false;
}

String Vector4::ToString() {
  return ToString("G", CultureInfo::in::get_CurrentCulture());
}

String Vector4::ToString(String format) {
  return ToString(format, CultureInfo::in::get_CurrentCulture());
}

String Vector4::ToString(String format, IFormatProvider formatProvider) {
  StringBuilder stringBuilder = rt::newobj<StringBuilder>();
  String numberGroupSeparator = NumberFormatInfo::in::GetInstance(formatProvider)->get_NumberGroupSeparator();
  stringBuilder->Append(60);
  stringBuilder->Append(X.ToString(format, formatProvider));
  stringBuilder->Append(numberGroupSeparator);
  stringBuilder->Append(32);
  stringBuilder->Append(Y.ToString(format, formatProvider));
  stringBuilder->Append(numberGroupSeparator);
  stringBuilder->Append(32);
  stringBuilder->Append(Z.ToString(format, formatProvider));
  stringBuilder->Append(numberGroupSeparator);
  stringBuilder->Append(32);
  stringBuilder->Append(W.ToString(format, formatProvider));
  stringBuilder->Append(62);
  return stringBuilder->ToString();
}

Single Vector4::Length() {
  Single x = Dot(*this, *this);
  return MathF::Sqrt(x);
}

Single Vector4::LengthSquared() {
  return Dot(*this, *this);
}

Single Vector4::Distance(Vector4 value1, Vector4 value2) {
  Vector4 vector = value1 - value2;
  Single x = Dot(vector, vector);
  return MathF::Sqrt(x);
}

Single Vector4::DistanceSquared(Vector4 value1, Vector4 value2) {
  Vector4 vector = value1 - value2;
  return Dot(vector, vector);
}

Vector4 Vector4::Normalize(Vector4 vector) {
  Single value = vector.Length();
  return vector / value;
}

Vector4 Vector4::Clamp(Vector4 value1, Vector4 min, Vector4 max) {
  return Min(Max(value1, min), max);
}

Vector4 Vector4::Lerp(Vector4 value1, Vector4 value2, Single amount) {
  return value1 + (value2 - value1) * amount;
}

Vector4 Vector4::Transform(Vector2 position, Matrix4x4 matrix) {
  return Vector4(position.X * matrix.M11 + position.Y * matrix.M21 + matrix.M41, position.X * matrix.M12 + position.Y * matrix.M22 + matrix.M42, position.X * matrix.M13 + position.Y * matrix.M23 + matrix.M43, position.X * matrix.M14 + position.Y * matrix.M24 + matrix.M44);
}

Vector4 Vector4::Transform(Vector3 position, Matrix4x4 matrix) {
  return Vector4(position.X * matrix.M11 + position.Y * matrix.M21 + position.Z * matrix.M31 + matrix.M41, position.X * matrix.M12 + position.Y * matrix.M22 + position.Z * matrix.M32 + matrix.M42, position.X * matrix.M13 + position.Y * matrix.M23 + position.Z * matrix.M33 + matrix.M43, position.X * matrix.M14 + position.Y * matrix.M24 + position.Z * matrix.M34 + matrix.M44);
}

Vector4 Vector4::Transform(Vector4 vector, Matrix4x4 matrix) {
  return Vector4(vector.X * matrix.M11 + vector.Y * matrix.M21 + vector.Z * matrix.M31 + vector.W * matrix.M41, vector.X * matrix.M12 + vector.Y * matrix.M22 + vector.Z * matrix.M32 + vector.W * matrix.M42, vector.X * matrix.M13 + vector.Y * matrix.M23 + vector.Z * matrix.M33 + vector.W * matrix.M43, vector.X * matrix.M14 + vector.Y * matrix.M24 + vector.Z * matrix.M34 + vector.W * matrix.M44);
}

Vector4 Vector4::Transform(Vector2 value, Quaternion rotation) {
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
  return Vector4(value.X * (1 - num10 - num12) + value.Y * (num8 - num6), value.X * (num8 + num6) + value.Y * (1 - num7 - num12), value.X * (num9 - num5) + value.Y * (num11 + num4), 1);
}

Vector4 Vector4::Transform(Vector3 value, Quaternion rotation) {
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
  return Vector4(value.X * (1 - num10 - num12) + value.Y * (num8 - num6) + value.Z * (num9 + num5), value.X * (num8 + num6) + value.Y * (1 - num7 - num12) + value.Z * (num11 - num4), value.X * (num9 - num5) + value.Y * (num11 + num4) + value.Z * (1 - num7 - num10), 1);
}

Vector4 Vector4::Transform(Vector4 value, Quaternion rotation) {
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
  return Vector4(value.X * (1 - num10 - num12) + value.Y * (num8 - num6) + value.Z * (num9 + num5), value.X * (num8 + num6) + value.Y * (1 - num7 - num12) + value.Z * (num11 - num4), value.X * (num9 - num5) + value.Y * (num11 + num4) + value.Z * (1 - num7 - num10), value.W);
}

Vector4 Vector4::Add(Vector4 left, Vector4 right) {
  return left + right;
}

Vector4 Vector4::Subtract(Vector4 left, Vector4 right) {
  return left - right;
}

Vector4 Vector4::Multiply(Vector4 left, Vector4 right) {
  return left * right;
}

Vector4 Vector4::Multiply(Vector4 left, Single right) {
  return left * Vector4(right, right, right, right);
}

Vector4 Vector4::Multiply(Single left, Vector4 right) {
  return Vector4(left, left, left, left) * right;
}

Vector4 Vector4::Divide(Vector4 left, Vector4 right) {
  return left / right;
}

Vector4 Vector4::Divide(Vector4 left, Single divisor) {
  return left / divisor;
}

Vector4 Vector4::Negate(Vector4 value) {
}

Vector4::Vector4(Single value) {
}

Vector4::Vector4(Single x, Single y, Single z, Single w) {
  W = w;
  X = x;
  Y = y;
  Z = z;
}

Vector4::Vector4(Vector2 value, Single z, Single w) {
  X = value.X;
  Y = value.Y;
  Z = z;
  W = w;
}

Vector4::Vector4(Vector3 value, Single w) {
  X = value.X;
  Y = value.Y;
  Z = value.Z;
  W = w;
}

void Vector4::CopyTo(Array<Single> array) {
  CopyTo(array, 0);
}

void Vector4::CopyTo(Array<Single> array, Int32 index) {
  if (array == nullptr) {
    rt::throw_exception<NullReferenceException>(SR::get_Arg_NullArgumentNullRef());
  }
  if (index < 0 || index >= array->get_Length()) {
    rt::throw_exception<ArgumentOutOfRangeException>("index", SR::Format(SR::get_Arg_ArgumentOutOfRangeException(), index));
  }
  if (array->get_Length() - index < 4) {
    rt::throw_exception<ArgumentException>(SR::Format(SR::get_Arg_ElementsInSourceIsGreaterThanDestination(), index));
  }
  array[index] = X;
  array[index + 1] = Y;
  array[index + 2] = Z;
  array[index + 3] = W;
}

Boolean Vector4::Equals(Vector4 other) {
  return *this == other;
}

Single Vector4::Dot(Vector4 vector1, Vector4 vector2) {
  return vector1.X * vector2.X + vector1.Y * vector2.Y + vector1.Z * vector2.Z + vector1.W * vector2.W;
}

Vector4 Vector4::Min(Vector4 value1, Vector4 value2) {
  return Vector4((value1.X < value2.X) ? value1.X : value2.X, (value1.Y < value2.Y) ? value1.Y : value2.Y, (value1.Z < value2.Z) ? value1.Z : value2.Z, (value1.W < value2.W) ? value1.W : value2.W);
}

Vector4 Vector4::Max(Vector4 value1, Vector4 value2) {
  return Vector4((value1.X > value2.X) ? value1.X : value2.X, (value1.Y > value2.Y) ? value1.Y : value2.Y, (value1.Z > value2.Z) ? value1.Z : value2.Z, (value1.W > value2.W) ? value1.W : value2.W);
}

Vector4 Vector4::Abs(Vector4 value) {
  return Vector4(MathF::Abs(value.X), MathF::Abs(value.Y), MathF::Abs(value.Z), MathF::Abs(value.W));
}

Vector4 Vector4::SquareRoot(Vector4 value) {
  return Vector4(MathF::Sqrt(value.X), MathF::Sqrt(value.Y), MathF::Sqrt(value.Z), MathF::Sqrt(value.W));
}

Vector4 Vector4::op_Addition(Vector4 left, Vector4 right) {
  return Vector4(left.X + right.X, left.Y + right.Y, left.Z + right.Z, left.W + right.W);
}

Vector4 Vector4::op_Subtraction(Vector4 left, Vector4 right) {
  return Vector4(left.X - right.X, left.Y - right.Y, left.Z - right.Z, left.W - right.W);
}

Vector4 Vector4::op_Multiply(Vector4 left, Vector4 right) {
  return Vector4(left.X * right.X, left.Y * right.Y, left.Z * right.Z, left.W * right.W);
}

Vector4 Vector4::op_Multiply(Vector4 left, Single right) {
  return left * Vector4(right);
}

Vector4 Vector4::op_Multiply(Single left, Vector4 right) {
  return Vector4(left) * right;
}

Vector4 Vector4::op_Division(Vector4 left, Vector4 right) {
  return Vector4(left.X / right.X, left.Y / right.Y, left.Z / right.Z, left.W / right.W);
}

Vector4 Vector4::op_Division(Vector4 value1, Single value2) {
  return value1 / Vector4(value2);
}

Vector4 Vector4::op_UnaryNegation(Vector4 value) {
  return get_Zero() - value;
}

Boolean Vector4::op_Equality(Vector4 left, Vector4 right) {
  if (left.X == right.X && left.Y == right.Y && left.Z == right.Z) {
    return left.W == right.W;
  }
  return false;
}

Boolean Vector4::op_Inequality(Vector4 left, Vector4 right) {
  return !(left == right);
}

} // namespace System::Private::CoreLib::System::Numerics::Vector4Namespace
