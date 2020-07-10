#include "Matrix4x4-dep.h"

#include <System.Private.CoreLib/System/Numerics/Matrix4x4-dep.h>

namespace System::Private::CoreLib::System::Numerics::Matrix4x4Namespace {
Matrix4x4 Matrix4x4::get_Identity() {
  return Matrix4x4();
};
Boolean Matrix4x4::get_IsIdentity() {
  return Boolean();
};
Vector3 Matrix4x4::get_Translation() {
  return Vector3();
};
void Matrix4x4::set_Translation(Vector3 value) {
};
Matrix4x4 Matrix4x4::CreateBillboard(Vector3 objectPosition, Vector3 cameraPosition, Vector3 cameraUpVector, Vector3 cameraForwardVector) {
  return Matrix4x4();
};
Matrix4x4 Matrix4x4::CreateConstrainedBillboard(Vector3 objectPosition, Vector3 cameraPosition, Vector3 rotateAxis, Vector3 cameraForwardVector, Vector3 objectForwardVector) {
  return Matrix4x4();
};
Matrix4x4 Matrix4x4::CreateTranslation(Vector3 position) {
  return Matrix4x4();
};
Matrix4x4 Matrix4x4::CreateTranslation(Single xPosition, Single yPosition, Single zPosition) {
  return Matrix4x4();
};
Matrix4x4 Matrix4x4::CreateScale(Single xScale, Single yScale, Single zScale) {
  return Matrix4x4();
};
Matrix4x4 Matrix4x4::CreateScale(Single xScale, Single yScale, Single zScale, Vector3 centerPoint) {
  return Matrix4x4();
};
Matrix4x4 Matrix4x4::CreateScale(Vector3 scales) {
  return Matrix4x4();
};
Matrix4x4 Matrix4x4::CreateScale(Vector3 scales, Vector3 centerPoint) {
  return Matrix4x4();
};
Matrix4x4 Matrix4x4::CreateScale(Single scale) {
  return Matrix4x4();
};
Matrix4x4 Matrix4x4::CreateScale(Single scale, Vector3 centerPoint) {
  return Matrix4x4();
};
Matrix4x4 Matrix4x4::CreateRotationX(Single radians) {
  return Matrix4x4();
};
Matrix4x4 Matrix4x4::CreateRotationX(Single radians, Vector3 centerPoint) {
  return Matrix4x4();
};
Matrix4x4 Matrix4x4::CreateRotationY(Single radians) {
  return Matrix4x4();
};
Matrix4x4 Matrix4x4::CreateRotationY(Single radians, Vector3 centerPoint) {
  return Matrix4x4();
};
Matrix4x4 Matrix4x4::CreateRotationZ(Single radians) {
  return Matrix4x4();
};
Matrix4x4 Matrix4x4::CreateRotationZ(Single radians, Vector3 centerPoint) {
  return Matrix4x4();
};
Matrix4x4 Matrix4x4::CreateFromAxisAngle(Vector3 axis, Single angle) {
  return Matrix4x4();
};
Matrix4x4 Matrix4x4::CreatePerspectiveFieldOfView(Single fieldOfView, Single aspectRatio, Single nearPlaneDistance, Single farPlaneDistance) {
  return Matrix4x4();
};
Matrix4x4 Matrix4x4::CreatePerspective(Single width, Single height, Single nearPlaneDistance, Single farPlaneDistance) {
  return Matrix4x4();
};
Matrix4x4 Matrix4x4::CreatePerspectiveOffCenter(Single left, Single right, Single bottom, Single top, Single nearPlaneDistance, Single farPlaneDistance) {
  return Matrix4x4();
};
Matrix4x4 Matrix4x4::CreateOrthographic(Single width, Single height, Single zNearPlane, Single zFarPlane) {
  return Matrix4x4();
};
Matrix4x4 Matrix4x4::CreateOrthographicOffCenter(Single left, Single right, Single bottom, Single top, Single zNearPlane, Single zFarPlane) {
  return Matrix4x4();
};
Matrix4x4 Matrix4x4::CreateLookAt(Vector3 cameraPosition, Vector3 cameraTarget, Vector3 cameraUpVector) {
  return Matrix4x4();
};
Matrix4x4 Matrix4x4::CreateWorld(Vector3 position, Vector3 forward, Vector3 up) {
  return Matrix4x4();
};
Matrix4x4 Matrix4x4::CreateFromQuaternion(Quaternion quaternion) {
  return Matrix4x4();
};
Matrix4x4 Matrix4x4::CreateFromYawPitchRoll(Single yaw, Single pitch, Single roll) {
  return Matrix4x4();
};
Matrix4x4 Matrix4x4::CreateShadow(Vector3 lightDirection, Plane plane) {
  return Matrix4x4();
};
Matrix4x4 Matrix4x4::CreateReflection(Plane value) {
  return Matrix4x4();
};
Single Matrix4x4::GetDeterminant() {
  return Single();
};
Vector128<Single> Matrix4x4::Permute(Vector128<Single> value, Byte control) {
  return Vector128<Single>();
};
Boolean Matrix4x4::Invert(Matrix4x4 matrix, Matrix4x4& result) {
  return Boolean();
};
Boolean Matrix4x4::Decompose(Matrix4x4 matrix, Vector3& scale, Quaternion& rotation, Vector3& translation) {
  return Boolean();
};
Matrix4x4 Matrix4x4::Transform(Matrix4x4 value, Quaternion rotation) {
  return Matrix4x4();
};
Matrix4x4 Matrix4x4::Transpose(Matrix4x4 matrix) {
  return Matrix4x4();
};
Matrix4x4 Matrix4x4::Lerp(Matrix4x4 matrix1, Matrix4x4 matrix2, Single amount) {
  return Matrix4x4();
};
Matrix4x4 Matrix4x4::Negate(Matrix4x4 value) {
  return Matrix4x4();
};
Matrix4x4 Matrix4x4::Add(Matrix4x4 value1, Matrix4x4 value2) {
  return Matrix4x4();
};
Matrix4x4 Matrix4x4::Subtract(Matrix4x4 value1, Matrix4x4 value2) {
  return Matrix4x4();
};
Matrix4x4 Matrix4x4::Multiply(Matrix4x4 value1, Matrix4x4 value2) {
  return Matrix4x4();
};
Matrix4x4 Matrix4x4::Multiply(Matrix4x4 value1, Single value2) {
  return Matrix4x4();
};
Matrix4x4 Matrix4x4::op_UnaryNegation(Matrix4x4 value) {
  return Matrix4x4();
};
Matrix4x4 Matrix4x4::op_Addition(Matrix4x4 value1, Matrix4x4 value2) {
  return Matrix4x4();
};
Matrix4x4 Matrix4x4::op_Subtraction(Matrix4x4 value1, Matrix4x4 value2) {
  return Matrix4x4();
};
Matrix4x4 Matrix4x4::op_Multiply(Matrix4x4 value1, Matrix4x4 value2) {
  return Matrix4x4();
};
Matrix4x4 Matrix4x4::op_Multiply(Matrix4x4 value1, Single value2) {
  return Matrix4x4();
};
Boolean Matrix4x4::op_Equality(Matrix4x4 value1, Matrix4x4 value2) {
  return Boolean();
};
Boolean Matrix4x4::op_Inequality(Matrix4x4 value1, Matrix4x4 value2) {
  return Boolean();
};
Boolean Matrix4x4::Equals(Matrix4x4 other) {
  return Boolean();
};
Boolean Matrix4x4::Equals(Object obj) {
  return Boolean();
};
String Matrix4x4::ToString() {
  return nullptr;
};
Int32 Matrix4x4::GetHashCode() {
  return Int32();
};
} // namespace System::Private::CoreLib::System::Numerics::Matrix4x4Namespace
