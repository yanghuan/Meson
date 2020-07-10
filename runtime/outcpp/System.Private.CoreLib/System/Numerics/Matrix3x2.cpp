#include "Matrix3x2-dep.h"

#include <System.Private.CoreLib/System/Numerics/Matrix3x2-dep.h>

namespace System::Private::CoreLib::System::Numerics::Matrix3x2Namespace {
Matrix3x2 Matrix3x2::get_Identity() {
  return Matrix3x2();
};
Boolean Matrix3x2::get_IsIdentity() {
  return Boolean();
};
Vector2 Matrix3x2::get_Translation() {
  return Vector2();
};
void Matrix3x2::set_Translation(Vector2 value) {
};
Matrix3x2 Matrix3x2::CreateTranslation(Vector2 position) {
  return Matrix3x2();
};
Matrix3x2 Matrix3x2::CreateTranslation(Single xPosition, Single yPosition) {
  return Matrix3x2();
};
Matrix3x2 Matrix3x2::CreateScale(Single xScale, Single yScale) {
  return Matrix3x2();
};
Matrix3x2 Matrix3x2::CreateScale(Single xScale, Single yScale, Vector2 centerPoint) {
  return Matrix3x2();
};
Matrix3x2 Matrix3x2::CreateScale(Vector2 scales) {
  return Matrix3x2();
};
Matrix3x2 Matrix3x2::CreateScale(Vector2 scales, Vector2 centerPoint) {
  return Matrix3x2();
};
Matrix3x2 Matrix3x2::CreateScale(Single scale) {
  return Matrix3x2();
};
Matrix3x2 Matrix3x2::CreateScale(Single scale, Vector2 centerPoint) {
  return Matrix3x2();
};
Matrix3x2 Matrix3x2::CreateSkew(Single radiansX, Single radiansY) {
  return Matrix3x2();
};
Matrix3x2 Matrix3x2::CreateSkew(Single radiansX, Single radiansY, Vector2 centerPoint) {
  return Matrix3x2();
};
Matrix3x2 Matrix3x2::CreateRotation(Single radians) {
  return Matrix3x2();
};
Matrix3x2 Matrix3x2::CreateRotation(Single radians, Vector2 centerPoint) {
  return Matrix3x2();
};
Single Matrix3x2::GetDeterminant() {
  return Single();
};
Boolean Matrix3x2::Invert(Matrix3x2 matrix, Matrix3x2& result) {
  return Boolean();
};
Matrix3x2 Matrix3x2::Lerp(Matrix3x2 matrix1, Matrix3x2 matrix2, Single amount) {
  return Matrix3x2();
};
Matrix3x2 Matrix3x2::Negate(Matrix3x2 value) {
  return Matrix3x2();
};
Matrix3x2 Matrix3x2::Add(Matrix3x2 value1, Matrix3x2 value2) {
  return Matrix3x2();
};
Matrix3x2 Matrix3x2::Subtract(Matrix3x2 value1, Matrix3x2 value2) {
  return Matrix3x2();
};
Matrix3x2 Matrix3x2::Multiply(Matrix3x2 value1, Matrix3x2 value2) {
  return Matrix3x2();
};
Matrix3x2 Matrix3x2::Multiply(Matrix3x2 value1, Single value2) {
  return Matrix3x2();
};
Matrix3x2 Matrix3x2::op_UnaryNegation(Matrix3x2 value) {
  return Matrix3x2();
};
Matrix3x2 Matrix3x2::op_Addition(Matrix3x2 value1, Matrix3x2 value2) {
  return Matrix3x2();
};
Matrix3x2 Matrix3x2::op_Subtraction(Matrix3x2 value1, Matrix3x2 value2) {
  return Matrix3x2();
};
Matrix3x2 Matrix3x2::op_Multiply(Matrix3x2 value1, Matrix3x2 value2) {
  return Matrix3x2();
};
Matrix3x2 Matrix3x2::op_Multiply(Matrix3x2 value1, Single value2) {
  return Matrix3x2();
};
Boolean Matrix3x2::op_Equality(Matrix3x2 value1, Matrix3x2 value2) {
  return Boolean();
};
Boolean Matrix3x2::op_Inequality(Matrix3x2 value1, Matrix3x2 value2) {
  return Boolean();
};
Boolean Matrix3x2::Equals(Matrix3x2 other) {
  return Boolean();
};
Boolean Matrix3x2::Equals(Object obj) {
  return Boolean();
};
String Matrix3x2::ToString() {
  return nullptr;
};
Int32 Matrix3x2::GetHashCode() {
  return Int32();
};
} // namespace System::Private::CoreLib::System::Numerics::Matrix3x2Namespace
