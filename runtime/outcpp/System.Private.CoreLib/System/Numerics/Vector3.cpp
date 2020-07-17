#include "Vector3-dep.h"

#include <System.Private.CoreLib/System/Numerics/Vector3-dep.h>

namespace System::Private::CoreLib::System::Numerics::Vector3Namespace {
Vector3 Vector3::get_Zero() {
  return Vector3();
};

Vector3 Vector3::get_One() {
  return Vector3();
};

Vector3 Vector3::get_UnitX() {
  return Vector3();
};

Vector3 Vector3::get_UnitY() {
  return Vector3();
};

Vector3 Vector3::get_UnitZ() {
  return Vector3();
};

Int32 Vector3::GetHashCode() {
  return Int32();
};

Boolean Vector3::Equals(Object obj) {
  return Boolean();
};

String Vector3::ToString() {
  return nullptr;
};

String Vector3::ToString(String format) {
  return nullptr;
};

String Vector3::ToString(String format, IFormatProvider formatProvider) {
  return nullptr;
};

Single Vector3::Length() {
  return Single();
};

Single Vector3::LengthSquared() {
  return Single();
};

Single Vector3::Distance(Vector3 value1, Vector3 value2) {
  return Single();
};

Single Vector3::DistanceSquared(Vector3 value1, Vector3 value2) {
  return Single();
};

Vector3 Vector3::Normalize(Vector3 value) {
  return Vector3();
};

Vector3 Vector3::Cross(Vector3 vector1, Vector3 vector2) {
  return Vector3();
};

Vector3 Vector3::Reflect(Vector3 vector, Vector3 normal) {
  return Vector3();
};

Vector3 Vector3::Clamp(Vector3 value1, Vector3 min, Vector3 max) {
  return Vector3();
};

Vector3 Vector3::Lerp(Vector3 value1, Vector3 value2, Single amount) {
  return Vector3();
};

Vector3 Vector3::Transform(Vector3 position, Matrix4x4 matrix) {
  return Vector3();
};

Vector3 Vector3::TransformNormal(Vector3 normal, Matrix4x4 matrix) {
  return Vector3();
};

Vector3 Vector3::Transform(Vector3 value, Quaternion rotation) {
  return Vector3();
};

Vector3 Vector3::Add(Vector3 left, Vector3 right) {
  return Vector3();
};

Vector3 Vector3::Subtract(Vector3 left, Vector3 right) {
  return Vector3();
};

Vector3 Vector3::Multiply(Vector3 left, Vector3 right) {
  return Vector3();
};

Vector3 Vector3::Multiply(Vector3 left, Single right) {
  return Vector3();
};

Vector3 Vector3::Multiply(Single left, Vector3 right) {
  return Vector3();
};

Vector3 Vector3::Divide(Vector3 left, Vector3 right) {
  return Vector3();
};

Vector3 Vector3::Divide(Vector3 left, Single divisor) {
  return Vector3();
};

Vector3 Vector3::Negate(Vector3 value) {
  return Vector3();
};

void Vector3::Ctor(Single value) {
};

void Vector3::Ctor(Vector2 value, Single z) {
};

void Vector3::Ctor(Single x, Single y, Single z) {
};

void Vector3::CopyTo(Array<Single> array) {
};

void Vector3::CopyTo(Array<Single> array, Int32 index) {
};

Boolean Vector3::Equals(Vector3 other) {
  return Boolean();
};

Single Vector3::Dot(Vector3 vector1, Vector3 vector2) {
  return Single();
};

Vector3 Vector3::Min(Vector3 value1, Vector3 value2) {
  return Vector3();
};

Vector3 Vector3::Max(Vector3 value1, Vector3 value2) {
  return Vector3();
};

Vector3 Vector3::Abs(Vector3 value) {
  return Vector3();
};

Vector3 Vector3::SquareRoot(Vector3 value) {
  return Vector3();
};

Vector3 Vector3::op_Addition(Vector3 left, Vector3 right) {
  return Vector3();
};

Vector3 Vector3::op_Subtraction(Vector3 left, Vector3 right) {
  return Vector3();
};

Vector3 Vector3::op_Multiply(Vector3 left, Vector3 right) {
  return Vector3();
};

Vector3 Vector3::op_Multiply(Vector3 left, Single right) {
  return Vector3();
};

Vector3 Vector3::op_Multiply(Single left, Vector3 right) {
  return Vector3();
};

Vector3 Vector3::op_Division(Vector3 left, Vector3 right) {
  return Vector3();
};

Vector3 Vector3::op_Division(Vector3 value1, Single value2) {
  return Vector3();
};

Vector3 Vector3::op_UnaryNegation(Vector3 value) {
  return Vector3();
};

Boolean Vector3::op_Equality(Vector3 left, Vector3 right) {
  return Boolean();
};

Boolean Vector3::op_Inequality(Vector3 left, Vector3 right) {
  return Boolean();
};

} // namespace System::Private::CoreLib::System::Numerics::Vector3Namespace
