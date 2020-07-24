#include "Vector4-dep.h"

#include <System.Private.CoreLib/System/Numerics/Vector4-dep.h>

namespace System::Private::CoreLib::System::Numerics::Vector4Namespace {
Vector4 Vector4::get_Zero() {
  return Vector4();
};

Vector4 Vector4::get_One() {
  return Vector4();
};

Vector4 Vector4::get_UnitX() {
  return Vector4();
};

Vector4 Vector4::get_UnitY() {
  return Vector4();
};

Vector4 Vector4::get_UnitZ() {
  return Vector4();
};

Vector4 Vector4::get_UnitW() {
  return Vector4();
};

Int32 Vector4::GetHashCode() {
  return Int32();
};

Boolean Vector4::Equals(Object obj) {
  return Boolean();
};

String Vector4::ToString() {
  return nullptr;
};

String Vector4::ToString(String format) {
  return nullptr;
};

String Vector4::ToString(String format, IFormatProvider formatProvider) {
  return nullptr;
};

Single Vector4::Length() {
  return Single();
};

Single Vector4::LengthSquared() {
  return Single();
};

Single Vector4::Distance(Vector4 value1, Vector4 value2) {
  return Single();
};

Single Vector4::DistanceSquared(Vector4 value1, Vector4 value2) {
  return Single();
};

Vector4 Vector4::Normalize(Vector4 vector) {
  return Vector4();
};

Vector4 Vector4::Clamp(Vector4 value1, Vector4 min, Vector4 max) {
  return Vector4();
};

Vector4 Vector4::Lerp(Vector4 value1, Vector4 value2, Single amount) {
  return Vector4();
};

Vector4 Vector4::Transform(Vector2 position, Matrix4x4 matrix) {
  return Vector4();
};

Vector4 Vector4::Transform(Vector3 position, Matrix4x4 matrix) {
  return Vector4();
};

Vector4 Vector4::Transform(Vector4 vector, Matrix4x4 matrix) {
  return Vector4();
};

Vector4 Vector4::Transform(Vector2 value, Quaternion rotation) {
  return Vector4();
};

Vector4 Vector4::Transform(Vector3 value, Quaternion rotation) {
  return Vector4();
};

Vector4 Vector4::Transform(Vector4 value, Quaternion rotation) {
  return Vector4();
};

Vector4 Vector4::Add(Vector4 left, Vector4 right) {
  return Vector4();
};

Vector4 Vector4::Subtract(Vector4 left, Vector4 right) {
  return Vector4();
};

Vector4 Vector4::Multiply(Vector4 left, Vector4 right) {
  return Vector4();
};

Vector4 Vector4::Multiply(Vector4 left, Single right) {
  return Vector4();
};

Vector4 Vector4::Multiply(Single left, Vector4 right) {
  return Vector4();
};

Vector4 Vector4::Divide(Vector4 left, Vector4 right) {
  return Vector4();
};

Vector4 Vector4::Divide(Vector4 left, Single divisor) {
  return Vector4();
};

Vector4 Vector4::Negate(Vector4 value) {
  return Vector4();
};

Vector4::Vector4(Single value) {
};

Vector4::Vector4(Single x, Single y, Single z, Single w) {
};

Vector4::Vector4(Vector2 value, Single z, Single w) {
};

Vector4::Vector4(Vector3 value, Single w) {
};

void Vector4::CopyTo(Array<Single> array) {
};

void Vector4::CopyTo(Array<Single> array, Int32 index) {
};

Boolean Vector4::Equals(Vector4 other) {
  return Boolean();
};

Single Vector4::Dot(Vector4 vector1, Vector4 vector2) {
  return Single();
};

Vector4 Vector4::Min(Vector4 value1, Vector4 value2) {
  return Vector4();
};

Vector4 Vector4::Max(Vector4 value1, Vector4 value2) {
  return Vector4();
};

Vector4 Vector4::Abs(Vector4 value) {
  return Vector4();
};

Vector4 Vector4::SquareRoot(Vector4 value) {
  return Vector4();
};

Vector4 Vector4::op_Addition(Vector4 left, Vector4 right) {
  return Vector4();
};

Vector4 Vector4::op_Subtraction(Vector4 left, Vector4 right) {
  return Vector4();
};

Vector4 Vector4::op_Multiply(Vector4 left, Vector4 right) {
  return Vector4();
};

Vector4 Vector4::op_Multiply(Vector4 left, Single right) {
  return Vector4();
};

Vector4 Vector4::op_Multiply(Single left, Vector4 right) {
  return Vector4();
};

Vector4 Vector4::op_Division(Vector4 left, Vector4 right) {
  return Vector4();
};

Vector4 Vector4::op_Division(Vector4 value1, Single value2) {
  return Vector4();
};

Vector4 Vector4::op_UnaryNegation(Vector4 value) {
  return Vector4();
};

Boolean Vector4::op_Equality(Vector4 left, Vector4 right) {
  return Boolean();
};

Boolean Vector4::op_Inequality(Vector4 left, Vector4 right) {
  return Boolean();
};

} // namespace System::Private::CoreLib::System::Numerics::Vector4Namespace
