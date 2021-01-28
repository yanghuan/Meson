#include "Matrix4x4-dep.h"

#include <System.Private.CoreLib/Internal/Runtime/CompilerServices/Unsafe-dep.h>
#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/Globalization/CultureInfo-dep.h>
#include <System.Private.CoreLib/System/Math-dep.h>
#include <System.Private.CoreLib/System/MathF-dep.h>
#include <System.Private.CoreLib/System/Numerics/Matrix4x4-dep.h>
#include <System.Private.CoreLib/System/Numerics/Vector4-dep.h>
#include <System.Private.CoreLib/System/Numerics/VectorMath-dep.h>
#include <System.Private.CoreLib/System/Runtime/Intrinsics/X86/Avx-dep.h>
#include <System.Private.CoreLib/System/Runtime/Intrinsics/X86/Sse-dep.h>
#include <System.Private.CoreLib/System/UInt32-dep.h>

namespace System::Private::CoreLib::System::Numerics::Matrix4x4Namespace {
using namespace Internal::Runtime::CompilerServices;
using namespace System::Globalization;
using namespace System::Runtime::Intrinsics::X86;

Matrix4x4 Matrix4x4::get_Identity() {
  return _identity;
}

Boolean Matrix4x4::get_IsIdentity() {
  if (M11 == 1 && M22 == 1 && M33 == 1 && M44 == 1 && M12 == 0 && M13 == 0 && M14 == 0 && M21 == 0 && M23 == 0 && M24 == 0 && M31 == 0 && M32 == 0 && M34 == 0 && M41 == 0 && M42 == 0) {
    return M43 == 0;
  }
  return false;
}

Vector3 Matrix4x4::get_Translation() {
  return Vector3(M41, M42, M43);
}

void Matrix4x4::set_Translation(Vector3 value) {
  M41 = value.X;
  M42 = value.Y;
  M43 = value.Z;
}

Matrix4x4::Matrix4x4(Single m11, Single m12, Single m13, Single m14, Single m21, Single m22, Single m23, Single m24, Single m31, Single m32, Single m33, Single m34, Single m41, Single m42, Single m43, Single m44) {
  M11 = m11;
  M12 = m12;
  M13 = m13;
  M14 = m14;
  M21 = m21;
  M22 = m22;
  M23 = m23;
  M24 = m24;
  M31 = m31;
  M32 = m32;
  M33 = m33;
  M34 = m34;
  M41 = m41;
  M42 = m42;
  M43 = m43;
  M44 = m44;
}

Matrix4x4::Matrix4x4(Matrix3x2 value) {
  M11 = value.M11;
  M12 = value.M12;
  M13 = 0;
  M14 = 0;
  M21 = value.M21;
  M22 = value.M22;
  M23 = 0;
  M24 = 0;
  M31 = 0;
  M32 = 0;
  M33 = 1;
  M34 = 0;
  M41 = value.M31;
  M42 = value.M32;
  M43 = 0;
  M44 = 1;
}

Matrix4x4 Matrix4x4::CreateBillboard(Vector3 objectPosition, Vector3 cameraPosition, Vector3 cameraUpVector, Vector3 cameraForwardVector) {
  Vector3 left = Vector3(objectPosition.X - cameraPosition.X, objectPosition.Y - cameraPosition.Y, objectPosition.Z - cameraPosition.Z);
  Single num = left.LengthSquared();
  left = ((!(num < 0.0001)) ? Vector3::Multiply(left, 1 / MathF::Sqrt(num)) : (-cameraForwardVector));
  Vector3 vector = Vector3::Normalize(Vector3::Cross(cameraUpVector, left));
  Vector3 vector2 = Vector3::Cross(left, vector);
  Matrix4x4 result;
  result.M11 = vector.X;
  result.M12 = vector.Y;
  result.M13 = vector.Z;
  result.M14 = 0;
  result.M21 = vector2.X;
  result.M22 = vector2.Y;
  result.M23 = vector2.Z;
  result.M24 = 0;
  result.M31 = left.X;
  result.M32 = left.Y;
  result.M33 = left.Z;
  result.M34 = 0;
  result.M41 = objectPosition.X;
  result.M42 = objectPosition.Y;
  result.M43 = objectPosition.Z;
  result.M44 = 1;
  return result;
}

Matrix4x4 Matrix4x4::CreateConstrainedBillboard(Vector3 objectPosition, Vector3 cameraPosition, Vector3 rotateAxis, Vector3 cameraForwardVector, Vector3 objectForwardVector) {
  Vector3 left = Vector3(objectPosition.X - cameraPosition.X, objectPosition.Y - cameraPosition.Y, objectPosition.Z - cameraPosition.Z);
  Single num = left.LengthSquared();
  left = ((!(num < 0.0001)) ? Vector3::Multiply(left, 1 / MathF::Sqrt(num)) : (-cameraForwardVector));
  Vector3 vector = rotateAxis;
  Single x = Vector3::Dot(rotateAxis, left);
  Vector3 vector3;
  Vector3 vector2;
  if (MathF::Abs(x) > 0.99825466) {
    vector2 = objectForwardVector;
    x = Vector3::Dot(rotateAxis, vector2);
    if (MathF::Abs(x) > 0.99825466) {
      vector2 = ((MathF::Abs(rotateAxis.Z) > 0.99825466) ? Vector3(1, 0, 0) : Vector3(0, 0, -1));
    }
    vector3 = Vector3::Normalize(Vector3::Cross(rotateAxis, vector2));
    vector2 = Vector3::Normalize(Vector3::Cross(vector3, rotateAxis));
  } else {
    vector3 = Vector3::Normalize(Vector3::Cross(rotateAxis, left));
    vector2 = Vector3::Normalize(Vector3::Cross(vector3, vector));
  }
  Matrix4x4 result;
  result.M11 = vector3.X;
  result.M12 = vector3.Y;
  result.M13 = vector3.Z;
  result.M14 = 0;
  result.M21 = vector.X;
  result.M22 = vector.Y;
  result.M23 = vector.Z;
  result.M24 = 0;
  result.M31 = vector2.X;
  result.M32 = vector2.Y;
  result.M33 = vector2.Z;
  result.M34 = 0;
  result.M41 = objectPosition.X;
  result.M42 = objectPosition.Y;
  result.M43 = objectPosition.Z;
  result.M44 = 1;
  return result;
}

Matrix4x4 Matrix4x4::CreateTranslation(Vector3 position) {
  Matrix4x4 result;
  result.M11 = 1;
  result.M12 = 0;
  result.M13 = 0;
  result.M14 = 0;
  result.M21 = 0;
  result.M22 = 1;
  result.M23 = 0;
  result.M24 = 0;
  result.M31 = 0;
  result.M32 = 0;
  result.M33 = 1;
  result.M34 = 0;
  result.M41 = position.X;
  result.M42 = position.Y;
  result.M43 = position.Z;
  result.M44 = 1;
  return result;
}

Matrix4x4 Matrix4x4::CreateTranslation(Single xPosition, Single yPosition, Single zPosition) {
  Matrix4x4 result;
  result.M11 = 1;
  result.M12 = 0;
  result.M13 = 0;
  result.M14 = 0;
  result.M21 = 0;
  result.M22 = 1;
  result.M23 = 0;
  result.M24 = 0;
  result.M31 = 0;
  result.M32 = 0;
  result.M33 = 1;
  result.M34 = 0;
  result.M41 = xPosition;
  result.M42 = yPosition;
  result.M43 = zPosition;
  result.M44 = 1;
  return result;
}

Matrix4x4 Matrix4x4::CreateScale(Single xScale, Single yScale, Single zScale) {
  Matrix4x4 result;
  result.M11 = xScale;
  result.M12 = 0;
  result.M13 = 0;
  result.M14 = 0;
  result.M21 = 0;
  result.M22 = yScale;
  result.M23 = 0;
  result.M24 = 0;
  result.M31 = 0;
  result.M32 = 0;
  result.M33 = zScale;
  result.M34 = 0;
  result.M41 = 0;
  result.M42 = 0;
  result.M43 = 0;
  result.M44 = 1;
  return result;
}

Matrix4x4 Matrix4x4::CreateScale(Single xScale, Single yScale, Single zScale, Vector3 centerPoint) {
  Single m = centerPoint.X * (1 - xScale);
  Single m2 = centerPoint.Y * (1 - yScale);
  Single m3 = centerPoint.Z * (1 - zScale);
  Matrix4x4 result;
  result.M11 = xScale;
  result.M12 = 0;
  result.M13 = 0;
  result.M14 = 0;
  result.M21 = 0;
  result.M22 = yScale;
  result.M23 = 0;
  result.M24 = 0;
  result.M31 = 0;
  result.M32 = 0;
  result.M33 = zScale;
  result.M34 = 0;
  result.M41 = m;
  result.M42 = m2;
  result.M43 = m3;
  result.M44 = 1;
  return result;
}

Matrix4x4 Matrix4x4::CreateScale(Vector3 scales) {
  Matrix4x4 result;
  result.M11 = scales.X;
  result.M12 = 0;
  result.M13 = 0;
  result.M14 = 0;
  result.M21 = 0;
  result.M22 = scales.Y;
  result.M23 = 0;
  result.M24 = 0;
  result.M31 = 0;
  result.M32 = 0;
  result.M33 = scales.Z;
  result.M34 = 0;
  result.M41 = 0;
  result.M42 = 0;
  result.M43 = 0;
  result.M44 = 1;
  return result;
}

Matrix4x4 Matrix4x4::CreateScale(Vector3 scales, Vector3 centerPoint) {
  Single m = centerPoint.X * (1 - scales.X);
  Single m2 = centerPoint.Y * (1 - scales.Y);
  Single m3 = centerPoint.Z * (1 - scales.Z);
  Matrix4x4 result;
  result.M11 = scales.X;
  result.M12 = 0;
  result.M13 = 0;
  result.M14 = 0;
  result.M21 = 0;
  result.M22 = scales.Y;
  result.M23 = 0;
  result.M24 = 0;
  result.M31 = 0;
  result.M32 = 0;
  result.M33 = scales.Z;
  result.M34 = 0;
  result.M41 = m;
  result.M42 = m2;
  result.M43 = m3;
  result.M44 = 1;
  return result;
}

Matrix4x4 Matrix4x4::CreateScale(Single scale) {
  Matrix4x4 result;
  result.M11 = scale;
  result.M12 = 0;
  result.M13 = 0;
  result.M14 = 0;
  result.M21 = 0;
  result.M22 = scale;
  result.M23 = 0;
  result.M24 = 0;
  result.M31 = 0;
  result.M32 = 0;
  result.M33 = scale;
  result.M34 = 0;
  result.M41 = 0;
  result.M42 = 0;
  result.M43 = 0;
  result.M44 = 1;
  return result;
}

Matrix4x4 Matrix4x4::CreateScale(Single scale, Vector3 centerPoint) {
  Single m = centerPoint.X * (1 - scale);
  Single m2 = centerPoint.Y * (1 - scale);
  Single m3 = centerPoint.Z * (1 - scale);
  Matrix4x4 result;
  result.M11 = scale;
  result.M12 = 0;
  result.M13 = 0;
  result.M14 = 0;
  result.M21 = 0;
  result.M22 = scale;
  result.M23 = 0;
  result.M24 = 0;
  result.M31 = 0;
  result.M32 = 0;
  result.M33 = scale;
  result.M34 = 0;
  result.M41 = m;
  result.M42 = m2;
  result.M43 = m3;
  result.M44 = 1;
  return result;
}

Matrix4x4 Matrix4x4::CreateRotationX(Single radians) {
  Single num = MathF::Cos(radians);
  Single num2 = MathF::Sin(radians);
  Matrix4x4 result;
  result.M11 = 1;
  result.M12 = 0;
  result.M13 = 0;
  result.M14 = 0;
  result.M21 = 0;
  result.M22 = num;
  result.M23 = num2;
  result.M24 = 0;
  result.M31 = 0;
  result.M32 = 0 - num2;
  result.M33 = num;
  result.M34 = 0;
  result.M41 = 0;
  result.M42 = 0;
  result.M43 = 0;
  result.M44 = 1;
  return result;
}

Matrix4x4 Matrix4x4::CreateRotationX(Single radians, Vector3 centerPoint) {
  Single num = MathF::Cos(radians);
  Single num2 = MathF::Sin(radians);
  Single m = centerPoint.Y * (1 - num) + centerPoint.Z * num2;
  Single m2 = centerPoint.Z * (1 - num) - centerPoint.Y * num2;
  Matrix4x4 result;
  result.M11 = 1;
  result.M12 = 0;
  result.M13 = 0;
  result.M14 = 0;
  result.M21 = 0;
  result.M22 = num;
  result.M23 = num2;
  result.M24 = 0;
  result.M31 = 0;
  result.M32 = 0 - num2;
  result.M33 = num;
  result.M34 = 0;
  result.M41 = 0;
  result.M42 = m;
  result.M43 = m2;
  result.M44 = 1;
  return result;
}

Matrix4x4 Matrix4x4::CreateRotationY(Single radians) {
  Single num = MathF::Cos(radians);
  Single num2 = MathF::Sin(radians);
  Matrix4x4 result;
  result.M11 = num;
  result.M12 = 0;
  result.M13 = 0 - num2;
  result.M14 = 0;
  result.M21 = 0;
  result.M22 = 1;
  result.M23 = 0;
  result.M24 = 0;
  result.M31 = num2;
  result.M32 = 0;
  result.M33 = num;
  result.M34 = 0;
  result.M41 = 0;
  result.M42 = 0;
  result.M43 = 0;
  result.M44 = 1;
  return result;
}

Matrix4x4 Matrix4x4::CreateRotationY(Single radians, Vector3 centerPoint) {
  Single num = MathF::Cos(radians);
  Single num2 = MathF::Sin(radians);
  Single m = centerPoint.X * (1 - num) - centerPoint.Z * num2;
  Single m2 = centerPoint.Z * (1 - num) + centerPoint.X * num2;
  Matrix4x4 result;
  result.M11 = num;
  result.M12 = 0;
  result.M13 = 0 - num2;
  result.M14 = 0;
  result.M21 = 0;
  result.M22 = 1;
  result.M23 = 0;
  result.M24 = 0;
  result.M31 = num2;
  result.M32 = 0;
  result.M33 = num;
  result.M34 = 0;
  result.M41 = m;
  result.M42 = 0;
  result.M43 = m2;
  result.M44 = 1;
  return result;
}

Matrix4x4 Matrix4x4::CreateRotationZ(Single radians) {
  Single num = MathF::Cos(radians);
  Single num2 = MathF::Sin(radians);
  Matrix4x4 result;
  result.M11 = num;
  result.M12 = num2;
  result.M13 = 0;
  result.M14 = 0;
  result.M21 = 0 - num2;
  result.M22 = num;
  result.M23 = 0;
  result.M24 = 0;
  result.M31 = 0;
  result.M32 = 0;
  result.M33 = 1;
  result.M34 = 0;
  result.M41 = 0;
  result.M42 = 0;
  result.M43 = 0;
  result.M44 = 1;
  return result;
}

Matrix4x4 Matrix4x4::CreateRotationZ(Single radians, Vector3 centerPoint) {
  Single num = MathF::Cos(radians);
  Single num2 = MathF::Sin(radians);
  Single m = centerPoint.X * (1 - num) + centerPoint.Y * num2;
  Single m2 = centerPoint.Y * (1 - num) - centerPoint.X * num2;
  Matrix4x4 result;
  result.M11 = num;
  result.M12 = num2;
  result.M13 = 0;
  result.M14 = 0;
  result.M21 = 0 - num2;
  result.M22 = num;
  result.M23 = 0;
  result.M24 = 0;
  result.M31 = 0;
  result.M32 = 0;
  result.M33 = 1;
  result.M34 = 0;
  result.M41 = m;
  result.M42 = m2;
  result.M43 = 0;
  result.M44 = 1;
  return result;
}

Matrix4x4 Matrix4x4::CreateFromAxisAngle(Vector3 axis, Single angle) {
  Single x = axis.X;
  Single y = axis.Y;
  Single z = axis.Z;
  Single num = MathF::Sin(angle);
  Single num2 = MathF::Cos(angle);
  Single num3 = x * x;
  Single num4 = y * y;
  Single num5 = z * z;
  Single num6 = x * y;
  Single num7 = x * z;
  Single num8 = y * z;
  Matrix4x4 result;
  result.M11 = num3 + num2 * (1 - num3);
  result.M12 = num6 - num2 * num6 + num * z;
  result.M13 = num7 - num2 * num7 - num * y;
  result.M14 = 0;
  result.M21 = num6 - num2 * num6 - num * z;
  result.M22 = num4 + num2 * (1 - num4);
  result.M23 = num8 - num2 * num8 + num * x;
  result.M24 = 0;
  result.M31 = num7 - num2 * num7 + num * y;
  result.M32 = num8 - num2 * num8 - num * x;
  result.M33 = num5 + num2 * (1 - num5);
  result.M34 = 0;
  result.M41 = 0;
  result.M42 = 0;
  result.M43 = 0;
  result.M44 = 1;
  return result;
}

Matrix4x4 Matrix4x4::CreatePerspectiveFieldOfView(Single fieldOfView, Single aspectRatio, Single nearPlaneDistance, Single farPlaneDistance) {
  if (fieldOfView <= 0 || fieldOfView >= (Single)Math::PI) {
    rt::throw_exception<ArgumentOutOfRangeException>("fieldOfView");
  }
  if (nearPlaneDistance <= 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("nearPlaneDistance");
  }
  if (farPlaneDistance <= 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("farPlaneDistance");
  }
  if (nearPlaneDistance >= farPlaneDistance) {
    rt::throw_exception<ArgumentOutOfRangeException>("nearPlaneDistance");
  }
  Single num = 1 / MathF::Tan(fieldOfView * 0.5);
  Matrix4x4 result;
  Single num2 = (result.M11 = num / aspectRatio);
  result.M12 = (result.M13 = (result.M14 = 0));
  result.M22 = num;
  result.M21 = (result.M23 = (result.M24 = 0));
  result.M31 = (result.M32 = 0);
  Single num3 = (result.M33 = (Single::IsPositiveInfinity(farPlaneDistance) ? (-1) : (farPlaneDistance / (nearPlaneDistance - farPlaneDistance))));
  result.M34 = -1;
  result.M41 = (result.M42 = (result.M44 = 0));
  result.M43 = nearPlaneDistance * num3;
  return result;
}

Matrix4x4 Matrix4x4::CreatePerspective(Single width, Single height, Single nearPlaneDistance, Single farPlaneDistance) {
  if (nearPlaneDistance <= 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("nearPlaneDistance");
  }
  if (farPlaneDistance <= 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("farPlaneDistance");
  }
  if (nearPlaneDistance >= farPlaneDistance) {
    rt::throw_exception<ArgumentOutOfRangeException>("nearPlaneDistance");
  }
  Matrix4x4 result;
  result.M11 = 2 * nearPlaneDistance / width;
  result.M12 = (result.M13 = (result.M14 = 0));
  result.M22 = 2 * nearPlaneDistance / height;
  result.M21 = (result.M23 = (result.M24 = 0));
  Single num = (result.M33 = (Single::IsPositiveInfinity(farPlaneDistance) ? (-1) : (farPlaneDistance / (nearPlaneDistance - farPlaneDistance))));
  result.M31 = (result.M32 = 0);
  result.M34 = -1;
  result.M41 = (result.M42 = (result.M44 = 0));
  result.M43 = nearPlaneDistance * num;
  return result;
}

Matrix4x4 Matrix4x4::CreatePerspectiveOffCenter(Single left, Single right, Single bottom, Single top, Single nearPlaneDistance, Single farPlaneDistance) {
  if (nearPlaneDistance <= 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("nearPlaneDistance");
  }
  if (farPlaneDistance <= 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("farPlaneDistance");
  }
  if (nearPlaneDistance >= farPlaneDistance) {
    rt::throw_exception<ArgumentOutOfRangeException>("nearPlaneDistance");
  }
  Matrix4x4 result;
  result.M11 = 2 * nearPlaneDistance / (right - left);
  result.M12 = (result.M13 = (result.M14 = 0));
  result.M22 = 2 * nearPlaneDistance / (top - bottom);
  result.M21 = (result.M23 = (result.M24 = 0));
  result.M31 = (left + right) / (right - left);
  result.M32 = (top + bottom) / (top - bottom);
  Single num = (result.M33 = (Single::IsPositiveInfinity(farPlaneDistance) ? (-1) : (farPlaneDistance / (nearPlaneDistance - farPlaneDistance))));
  result.M34 = -1;
  result.M43 = nearPlaneDistance * num;
  result.M41 = (result.M42 = (result.M44 = 0));
  return result;
}

Matrix4x4 Matrix4x4::CreateOrthographic(Single width, Single height, Single zNearPlane, Single zFarPlane) {
  Matrix4x4 result;
  result.M11 = 2 / width;
  result.M12 = (result.M13 = (result.M14 = 0));
  result.M22 = 2 / height;
  result.M21 = (result.M23 = (result.M24 = 0));
  result.M33 = 1 / (zNearPlane - zFarPlane);
  result.M31 = (result.M32 = (result.M34 = 0));
  result.M41 = (result.M42 = 0);
  result.M43 = zNearPlane / (zNearPlane - zFarPlane);
  result.M44 = 1;
  return result;
}

Matrix4x4 Matrix4x4::CreateOrthographicOffCenter(Single left, Single right, Single bottom, Single top, Single zNearPlane, Single zFarPlane) {
  Matrix4x4 result;
  result.M11 = 2 / (right - left);
  result.M12 = (result.M13 = (result.M14 = 0));
  result.M22 = 2 / (top - bottom);
  result.M21 = (result.M23 = (result.M24 = 0));
  result.M33 = 1 / (zNearPlane - zFarPlane);
  result.M31 = (result.M32 = (result.M34 = 0));
  result.M41 = (left + right) / (left - right);
  result.M42 = (top + bottom) / (bottom - top);
  result.M43 = zNearPlane / (zNearPlane - zFarPlane);
  result.M44 = 1;
  return result;
}

Matrix4x4 Matrix4x4::CreateLookAt(Vector3 cameraPosition, Vector3 cameraTarget, Vector3 cameraUpVector) {
  Vector3 vector = Vector3::Normalize(cameraPosition - cameraTarget);
  Vector3 vector2 = Vector3::Normalize(Vector3::Cross(cameraUpVector, vector));
  Vector3 vector3 = Vector3::Cross(vector, vector2);
  Matrix4x4 result;
  result.M11 = vector2.X;
  result.M12 = vector3.X;
  result.M13 = vector.X;
  result.M14 = 0;
  result.M21 = vector2.Y;
  result.M22 = vector3.Y;
  result.M23 = vector.Y;
  result.M24 = 0;
  result.M31 = vector2.Z;
  result.M32 = vector3.Z;
  result.M33 = vector.Z;
  result.M34 = 0;
  result.M41 = 0 - Vector3::Dot(vector2, cameraPosition);
  result.M42 = 0 - Vector3::Dot(vector3, cameraPosition);
  result.M43 = 0 - Vector3::Dot(vector, cameraPosition);
  result.M44 = 1;
  return result;
}

Matrix4x4 Matrix4x4::CreateWorld(Vector3 position, Vector3 forward, Vector3 up) {
  Vector3 vector = Vector3::Normalize(-forward);
  Vector3 vector2 = Vector3::Normalize(Vector3::Cross(up, vector));
  Vector3 vector3 = Vector3::Cross(vector, vector2);
  Matrix4x4 result;
  result.M11 = vector2.X;
  result.M12 = vector2.Y;
  result.M13 = vector2.Z;
  result.M14 = 0;
  result.M21 = vector3.X;
  result.M22 = vector3.Y;
  result.M23 = vector3.Z;
  result.M24 = 0;
  result.M31 = vector.X;
  result.M32 = vector.Y;
  result.M33 = vector.Z;
  result.M34 = 0;
  result.M41 = position.X;
  result.M42 = position.Y;
  result.M43 = position.Z;
  result.M44 = 1;
  return result;
}

Matrix4x4 Matrix4x4::CreateFromQuaternion(Quaternion quaternion) {
  Single num = quaternion.X * quaternion.X;
  Single num2 = quaternion.Y * quaternion.Y;
  Single num3 = quaternion.Z * quaternion.Z;
  Single num4 = quaternion.X * quaternion.Y;
  Single num5 = quaternion.Z * quaternion.W;
  Single num6 = quaternion.Z * quaternion.X;
  Single num7 = quaternion.Y * quaternion.W;
  Single num8 = quaternion.Y * quaternion.Z;
  Single num9 = quaternion.X * quaternion.W;
  Matrix4x4 result;
  result.M11 = 1 - 2 * (num2 + num3);
  result.M12 = 2 * (num4 + num5);
  result.M13 = 2 * (num6 - num7);
  result.M14 = 0;
  result.M21 = 2 * (num4 - num5);
  result.M22 = 1 - 2 * (num3 + num);
  result.M23 = 2 * (num8 + num9);
  result.M24 = 0;
  result.M31 = 2 * (num6 + num7);
  result.M32 = 2 * (num8 - num9);
  result.M33 = 1 - 2 * (num2 + num);
  result.M34 = 0;
  result.M41 = 0;
  result.M42 = 0;
  result.M43 = 0;
  result.M44 = 1;
  return result;
}

Matrix4x4 Matrix4x4::CreateFromYawPitchRoll(Single yaw, Single pitch, Single roll) {
  Quaternion quaternion = Quaternion::CreateFromYawPitchRoll(yaw, pitch, roll);
  return CreateFromQuaternion(quaternion);
}

Matrix4x4 Matrix4x4::CreateShadow(Vector3 lightDirection, Plane plane) {
  Plane plane2 = Plane::Normalize(plane);
  Single num = plane2.Normal.X * lightDirection.X + plane2.Normal.Y * lightDirection.Y + plane2.Normal.Z * lightDirection.Z;
  Single num2 = 0 - plane2.Normal.X;
  Single num3 = 0 - plane2.Normal.Y;
  Single num4 = 0 - plane2.Normal.Z;
  Single num5 = 0 - plane2.D;
  Matrix4x4 result;
  result.M11 = num2 * lightDirection.X + num;
  result.M21 = num3 * lightDirection.X;
  result.M31 = num4 * lightDirection.X;
  result.M41 = num5 * lightDirection.X;
  result.M12 = num2 * lightDirection.Y;
  result.M22 = num3 * lightDirection.Y + num;
  result.M32 = num4 * lightDirection.Y;
  result.M42 = num5 * lightDirection.Y;
  result.M13 = num2 * lightDirection.Z;
  result.M23 = num3 * lightDirection.Z;
  result.M33 = num4 * lightDirection.Z + num;
  result.M43 = num5 * lightDirection.Z;
  result.M14 = 0;
  result.M24 = 0;
  result.M34 = 0;
  result.M44 = num;
  return result;
}

Matrix4x4 Matrix4x4::CreateReflection(Plane value) {
  value = Plane::Normalize(value);
  Single x = value.Normal.X;
  Single y = value.Normal.Y;
  Single z = value.Normal.Z;
  Single num = -2 * x;
  Single num2 = -2 * y;
  Single num3 = -2 * z;
  Matrix4x4 result;
  result.M11 = num * x + 1;
  result.M12 = num2 * x;
  result.M13 = num3 * x;
  result.M14 = 0;
  result.M21 = num * y;
  result.M22 = num2 * y + 1;
  result.M23 = num3 * y;
  result.M24 = 0;
  result.M31 = num * z;
  result.M32 = num2 * z;
  result.M33 = num3 * z + 1;
  result.M34 = 0;
  result.M41 = num * value.D;
  result.M42 = num2 * value.D;
  result.M43 = num3 * value.D;
  result.M44 = 1;
  return result;
}

Single Matrix4x4::GetDeterminant() {
  Single m = M11;
  Single m2 = M12;
  Single m3 = M13;
  Single m4 = M14;
  Single m5 = M21;
  Single m6 = M22;
  Single m7 = M23;
  Single m8 = M24;
  Single m9 = M31;
  Single m10 = M32;
  Single m11 = M33;
  Single m12 = M34;
  Single m13 = M41;
  Single m14 = M42;
  Single m15 = M43;
  Single m16 = M44;
  Single num = m11 * m16 - m12 * m15;
  Single num2 = m10 * m16 - m12 * m14;
  Single num3 = m10 * m15 - m11 * m14;
  Single num4 = m9 * m16 - m12 * m13;
  Single num5 = m9 * m15 - m11 * m13;
  Single num6 = m9 * m14 - m10 * m13;
  return m * (m6 * num - m7 * num2 + m8 * num3) - m2 * (m5 * num - m7 * num4 + m8 * num5) + m3 * (m5 * num2 - m6 * num4 + m8 * num6) - m4 * (m5 * num3 - m6 * num5 + m7 * num6);
}

Vector128<Single> Matrix4x4::Permute(Vector128<Single> value, Byte control) {
  if (Avx::in::get_IsSupported()) {
    return Avx::in::Permute(value, control);
  }
  return Sse::in::Shuffle(value, value, control);
}

Boolean Matrix4x4::Invert(Matrix4x4 matrix, Matrix4x4& result) {
  auto SseImpl = [](Matrix4x4 matrix, Matrix4x4& result) -> Boolean {
    Vector128<Single> left = Sse::in::LoadVector128(&matrix.M11);
    Vector128<Single> right = Sse::in::LoadVector128(&matrix.M21);
    Vector128<Single> left2 = Sse::in::LoadVector128(&matrix.M31);
    Vector128<Single> right2 = Sse::in::LoadVector128(&matrix.M41);
    Vector128<Single> left3 = Sse::in::Shuffle(left, right, 68);
    Vector128<Single> left4 = Sse::in::Shuffle(left, right, 238);
    Vector128<Single> right3 = Sse::in::Shuffle(left2, right2, 68);
    Vector128<Single> right4 = Sse::in::Shuffle(left2, right2, 238);
    left = Sse::in::Shuffle(left3, right3, 136);
    right = Sse::in::Shuffle(left3, right3, 221);
    left2 = Sse::in::Shuffle(left4, right4, 136);
    right2 = Sse::in::Shuffle(left4, right4, 221);
    Vector128<Single> left5 = Permute(left2, 80);
    Vector128<Single> right5 = Permute(right2, 238);
    Vector128<Single> left6 = Permute(left, 80);
    Vector128<Single> right6 = Permute(right, 238);
    Vector128<Single> left7 = Sse::in::Shuffle(left2, left, 136);
    Vector128<Single> right7 = Sse::in::Shuffle(right2, right, 221);
    Vector128<Single> left8 = Sse::in::Multiply(left5, right5);
    Vector128<Single> left9 = Sse::in::Multiply(left6, right6);
    Vector128<Single> left10 = Sse::in::Multiply(left7, right7);
    left5 = Permute(left2, 238);
    right5 = Permute(right2, 80);
    left6 = Permute(left, 238);
    right6 = Permute(right, 80);
    left7 = Sse::in::Shuffle(left2, left, 221);
    right7 = Sse::in::Shuffle(right2, right, 136);
    left8 = Sse::in::Subtract(left8, Sse::in::Multiply(left5, right5));
    left9 = Sse::in::Subtract(left9, Sse::in::Multiply(left6, right6));
    left10 = Sse::in::Subtract(left10, Sse::in::Multiply(left7, right7));
    right6 = Sse::in::Shuffle(left8, left10, 93);
    left5 = Permute(right, 73);
    right5 = Sse::in::Shuffle(right6, left8, 50);
    left6 = Permute(left, 18);
    right6 = Sse::in::Shuffle(right6, left8, 153);
    Vector128<Single> left11 = Sse::in::Shuffle(left9, left10, 253);
    left7 = Permute(right2, 73);
    right7 = Sse::in::Shuffle(left11, left9, 50);
    Vector128<Single> left12 = Permute(left2, 18);
    left11 = Sse::in::Shuffle(left11, left9, 153);
    Vector128<Single> left13 = Sse::in::Multiply(left5, right5);
    Vector128<Single> left14 = Sse::in::Multiply(left6, right6);
    Vector128<Single> left15 = Sse::in::Multiply(left7, right7);
    Vector128<Single> left16 = Sse::in::Multiply(left12, left11);
    right6 = Sse::in::Shuffle(left8, left10, 4);
    left5 = Permute(right, 158);
    right5 = Sse::in::Shuffle(left8, right6, 147);
    left6 = Permute(left, 123);
    right6 = Sse::in::Shuffle(left8, right6, 38);
    left11 = Sse::in::Shuffle(left9, left10, 164);
    left7 = Permute(right2, 158);
    right7 = Sse::in::Shuffle(left9, left11, 147);
    left12 = Permute(left2, 123);
    left11 = Sse::in::Shuffle(left9, left11, 38);
    left13 = Sse::in::Subtract(left13, Sse::in::Multiply(left5, right5));
    left14 = Sse::in::Subtract(left14, Sse::in::Multiply(left6, right6));
    left15 = Sse::in::Subtract(left15, Sse::in::Multiply(left7, right7));
    left16 = Sse::in::Subtract(left16, Sse::in::Multiply(left12, left11));
    left5 = Permute(right, 51);
    right5 = Sse::in::Shuffle(left8, left10, 74);
    right5 = Permute(right5, 44);
    left6 = Permute(left, 141);
    right6 = Sse::in::Shuffle(left8, left10, 76);
    right6 = Permute(right6, 147);
    left7 = Permute(right2, 51);
    right7 = Sse::in::Shuffle(left9, left10, 234);
    right7 = Permute(right7, 44);
    left12 = Permute(left2, 141);
    left11 = Sse::in::Shuffle(left9, left10, 236);
    left11 = Permute(left11, 147);
    left5 = Sse::in::Multiply(left5, right5);
    left6 = Sse::in::Multiply(left6, right6);
    left7 = Sse::in::Multiply(left7, right7);
    left12 = Sse::in::Multiply(left12, left11);
    Vector128<Single> right8 = Sse::in::Subtract(left13, left5);
    left13 = Sse::in::Add(left13, left5);
    Vector128<Single> right9 = Sse::in::Add(left14, left6);
    left14 = Sse::in::Subtract(left14, left6);
    Vector128<Single> right10 = Sse::in::Subtract(left15, left7);
    left15 = Sse::in::Add(left15, left7);
    Vector128<Single> right11 = Sse::in::Add(left16, left12);
    left16 = Sse::in::Subtract(left16, left12);
    left13 = Sse::in::Shuffle(left13, right8, 216);
    left14 = Sse::in::Shuffle(left14, right9, 216);
    left15 = Sse::in::Shuffle(left15, right10, 216);
    left16 = Sse::in::Shuffle(left16, right11, 216);
    left13 = Permute(left13, 216);
    left14 = Permute(left14, 216);
    left15 = Permute(left15, 216);
    left16 = Permute(left16, 216);
    right3 = left;
    Single num25 = Vector4::Dot(Vector128<>::AsVector4(left13), Vector128<>::AsVector4(right3));
    if (MathF::Abs(num25) < Single::Epsilon()) {
      result = Matrix4x4(Single::NaN(), Single::NaN(), Single::NaN(), Single::NaN(), Single::NaN(), Single::NaN(), Single::NaN(), Single::NaN(), Single::NaN(), Single::NaN(), Single::NaN(), Single::NaN(), Single::NaN(), Single::NaN(), Single::NaN(), Single::NaN());
      return false;
    }
    Vector128<Single> left17 = Vector128<>::Create(1);
    Vector128<Single> right12 = Vector128<>::Create(num25);
    right12 = Sse::in::Divide(left17, right12);
    left = Sse::in::Multiply(left13, right12);
    right = Sse::in::Multiply(left14, right12);
    left2 = Sse::in::Multiply(left15, right12);
    right2 = Sse::in::Multiply(left16, right12);
    Unsafe::SkipInit<Matrix4x4>(result);
    Vector128<Single>& reference = Unsafe::As<Matrix4x4, Vector128<Single>>(result);
    reference = left;
    Unsafe::Add(reference, 1) = right;
    Unsafe::Add(reference, 2) = left2;
    Unsafe::Add(reference, 3) = right2;
    return true;
  };
  auto SoftwareFallback = [](Matrix4x4 matrix, Matrix4x4& result) -> Boolean {
    Single m = matrix.M11;
    Single m2 = matrix.M12;
    Single m3 = matrix.M13;
    Single m4 = matrix.M14;
    Single m5 = matrix.M21;
    Single m6 = matrix.M22;
    Single m7 = matrix.M23;
    Single m8 = matrix.M24;
    Single m9 = matrix.M31;
    Single m10 = matrix.M32;
    Single m11 = matrix.M33;
    Single m12 = matrix.M34;
    Single m13 = matrix.M41;
    Single m14 = matrix.M42;
    Single m15 = matrix.M43;
    Single m16 = matrix.M44;
    Single num = m11 * m16 - m12 * m15;
    Single num2 = m10 * m16 - m12 * m14;
    Single num3 = m10 * m15 - m11 * m14;
    Single num4 = m9 * m16 - m12 * m13;
    Single num5 = m9 * m15 - m11 * m13;
    Single num6 = m9 * m14 - m10 * m13;
    Single num7 = m6 * num - m7 * num2 + m8 * num3;
    Single num8 = 0 - (m5 * num - m7 * num4 + m8 * num5);
    Single num9 = m5 * num2 - m6 * num4 + m8 * num6;
    Single num10 = 0 - (m5 * num3 - m6 * num5 + m7 * num6);
    Single num11 = m * num7 + m2 * num8 + m3 * num9 + m4 * num10;
    if (MathF::Abs(num11) < Single::Epsilon()) {
      result = Matrix4x4(Single::NaN(), Single::NaN(), Single::NaN(), Single::NaN(), Single::NaN(), Single::NaN(), Single::NaN(), Single::NaN(), Single::NaN(), Single::NaN(), Single::NaN(), Single::NaN(), Single::NaN(), Single::NaN(), Single::NaN(), Single::NaN());
      return false;
    }
    Single num12 = 1 / num11;
    result.M11 = num7 * num12;
    result.M21 = num8 * num12;
    result.M31 = num9 * num12;
    result.M41 = num10 * num12;
    result.M12 = (0 - (m2 * num - m3 * num2 + m4 * num3)) * num12;
    result.M22 = (m * num - m3 * num4 + m4 * num5) * num12;
    result.M32 = (0 - (m * num2 - m2 * num4 + m4 * num6)) * num12;
    result.M42 = (m * num3 - m2 * num5 + m3 * num6) * num12;
    Single num13 = m7 * m16 - m8 * m15;
    Single num14 = m6 * m16 - m8 * m14;
    Single num15 = m6 * m15 - m7 * m14;
    Single num16 = m5 * m16 - m8 * m13;
    Single num17 = m5 * m15 - m7 * m13;
    Single num18 = m5 * m14 - m6 * m13;
    result.M13 = (m2 * num13 - m3 * num14 + m4 * num15) * num12;
    result.M23 = (0 - (m * num13 - m3 * num16 + m4 * num17)) * num12;
    result.M33 = (m * num14 - m2 * num16 + m4 * num18) * num12;
    result.M43 = (0 - (m * num15 - m2 * num17 + m3 * num18)) * num12;
    Single num19 = m7 * m12 - m8 * m11;
    Single num20 = m6 * m12 - m8 * m10;
    Single num21 = m6 * m11 - m7 * m10;
    Single num22 = m5 * m12 - m8 * m9;
    Single num23 = m5 * m11 - m7 * m9;
    Single num24 = m5 * m10 - m6 * m9;
    result.M14 = (0 - (m2 * num19 - m3 * num20 + m4 * num21)) * num12;
    result.M24 = (m * num19 - m3 * num22 + m4 * num23) * num12;
    result.M34 = (0 - (m * num20 - m2 * num22 + m4 * num24)) * num12;
    result.M44 = (m * num21 - m2 * num23 + m3 * num24) * num12;
    return true;
  };
  if (Sse::in::get_IsSupported()) {
    return SseImpl(matrix, result);
  }
  return SoftwareFallback(matrix, result);
}

Boolean Matrix4x4::Decompose(Matrix4x4 matrix, Vector3& scale, Quaternion& rotation, Vector3& translation) {
  Boolean result = true;
  {
    Vector3* ptr = rt::fixed(&scale);
    Single* ptr2 = (Single*)ptr;
    VectorBasis vectorBasis;
    Vector3* ptr3 = (Vector3*)(&vectorBasis);
    Matrix4x4 identity = get_Identity();
    CanonicalBasis canonicalBasis;
    Vector3* ptr4 = &canonicalBasis.Row0;
    canonicalBasis.Row0 = Vector3(1, 0, 0);
    canonicalBasis.Row1 = Vector3(0, 1, 0);
    canonicalBasis.Row2 = Vector3(0, 0, 1);
    translation = Vector3(matrix.M41, matrix.M42, matrix.M43);
    *ptr3 = (Vector3*)(&identity.M11);
    ptr3[1] = (Vector3*)(&identity.M21);
    ptr3[2] = (Vector3*)(&identity.M31);
    *(*ptr3) = Vector3(matrix.M11, matrix.M12, matrix.M13);
    *ptr3[1] = Vector3(matrix.M21, matrix.M22, matrix.M23);
    *ptr3[2] = Vector3(matrix.M31, matrix.M32, matrix.M33);
    scale.X = (*ptr3)->Length();
    scale.Y = ptr3[1]->Length();
    scale.Z = ptr3[2]->Length();
    Single num = *ptr2;
    Single num2 = ptr2[1];
    Single num3 = ptr2[2];
    UInt32 num4;
    UInt32 num5;
    UInt32 num6;
    if (num < num2) {
      if (num2 < num3) {
        num4 = 2u;
        num5 = 1u;
        num6 = 0u;
      } else {
        num4 = 1u;
        if (num < num3) {
          num5 = 2u;
          num6 = 0u;
        } else {
          num5 = 0u;
          num6 = 2u;
        }
      }
    } else if (num < num3) {
      num4 = 2u;
      num5 = 0u;
      num6 = 1u;
    } else {
      num4 = 0u;
      if (num2 < num3) {
        num5 = 2u;
        num6 = 1u;
      } else {
        num5 = 1u;
        num6 = 2u;
      }
    }

    if (*(ptr2 + num4) < 0.0001) {
      **(ptr3 + num4) = *(ptr4 + num4);
    }
    **(ptr3 + num4) = Vector3::Normalize(**(ptr3 + num4));
    if (*(ptr2 + num5) < 0.0001) {
      Single num7 = MathF::Abs(*(ptr3 + num4)->X);
      Single num8 = MathF::Abs(*(ptr3 + num4)->Y);
      Single num9 = MathF::Abs(*(ptr3 + num4)->Z);
      UInt32 num10 = ((num7 < num8) ? ((!(num8 < num9)) ? ((!(num7 < num9)) ? 2u : 0u) : 0u) : ((num7 < num9) ? 1u : ((num8 < num9) ? 1u : 2u)));
      **(ptr3 + num5) = Vector3::Cross(**(ptr3 + num4), *(ptr4 + num10));
    }
    **(ptr3 + num5) = Vector3::Normalize(**(ptr3 + num5));
    if (*(ptr2 + num6) < 0.0001) {
      **(ptr3 + num6) = Vector3::Cross(**(ptr3 + num4), **(ptr3 + num5));
    }
    **(ptr3 + num6) = Vector3::Normalize(**(ptr3 + num6));
    Single num11 = identity.GetDeterminant();
    if (num11 < 0) {
      *(ptr2 + num4) = 0 - *(ptr2 + num4);
      **(ptr3 + num4) = -(**(ptr3 + num4));
      num11 = 0 - num11;
    }
    num11 -= 1;
    num11 *= num11;
    if (0.0001 < num11) {
      rotation = Quaternion::get_Identity();
      result = false;
    } else {
      rotation = Quaternion::CreateFromRotationMatrix(identity);
    }
  }
  return result;
}

Matrix4x4 Matrix4x4::Transform(Matrix4x4 value, Quaternion rotation) {
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
  Single num13 = 1 - num10 - num12;
  Single num14 = num8 - num6;
  Single num15 = num9 + num5;
  Single num16 = num8 + num6;
  Single num17 = 1 - num7 - num12;
  Single num18 = num11 - num4;
  Single num19 = num9 - num5;
  Single num20 = num11 + num4;
  Single num21 = 1 - num7 - num10;
  Matrix4x4 result;
  result.M11 = value.M11 * num13 + value.M12 * num14 + value.M13 * num15;
  result.M12 = value.M11 * num16 + value.M12 * num17 + value.M13 * num18;
  result.M13 = value.M11 * num19 + value.M12 * num20 + value.M13 * num21;
  result.M14 = value.M14;
  result.M21 = value.M21 * num13 + value.M22 * num14 + value.M23 * num15;
  result.M22 = value.M21 * num16 + value.M22 * num17 + value.M23 * num18;
  result.M23 = value.M21 * num19 + value.M22 * num20 + value.M23 * num21;
  result.M24 = value.M24;
  result.M31 = value.M31 * num13 + value.M32 * num14 + value.M33 * num15;
  result.M32 = value.M31 * num16 + value.M32 * num17 + value.M33 * num18;
  result.M33 = value.M31 * num19 + value.M32 * num20 + value.M33 * num21;
  result.M34 = value.M34;
  result.M41 = value.M41 * num13 + value.M42 * num14 + value.M43 * num15;
  result.M42 = value.M41 * num16 + value.M42 * num17 + value.M43 * num18;
  result.M43 = value.M41 * num19 + value.M42 * num20 + value.M43 * num21;
  result.M44 = value.M44;
  return result;
}

Matrix4x4 Matrix4x4::Transpose(Matrix4x4 matrix) {
  if (Sse::in::get_IsSupported()) {
    Vector128<Single> left = Sse::in::LoadVector128(&matrix.M11);
    Vector128<Single> right = Sse::in::LoadVector128(&matrix.M21);
    Vector128<Single> left2 = Sse::in::LoadVector128(&matrix.M31);
    Vector128<Single> right2 = Sse::in::LoadVector128(&matrix.M41);
    Vector128<Single> vector = Sse::in::UnpackLow(left, right);
    Vector128<Single> vector2 = Sse::in::UnpackLow(left2, right2);
    Vector128<Single> vector3 = Sse::in::UnpackHigh(left, right);
    Vector128<Single> vector4 = Sse::in::UnpackHigh(left2, right2);
    Sse::in::Store(&matrix.M11, Sse::in::MoveLowToHigh(vector, vector2));
    Sse::in::Store(&matrix.M21, Sse::in::MoveHighToLow(vector2, vector));
    Sse::in::Store(&matrix.M31, Sse::in::MoveLowToHigh(vector3, vector4));
    Sse::in::Store(&matrix.M41, Sse::in::MoveHighToLow(vector4, vector3));
    return matrix;
  }
  Matrix4x4 result;
  result.M11 = matrix.M11;
  result.M12 = matrix.M21;
  result.M13 = matrix.M31;
  result.M14 = matrix.M41;
  result.M21 = matrix.M12;
  result.M22 = matrix.M22;
  result.M23 = matrix.M32;
  result.M24 = matrix.M42;
  result.M31 = matrix.M13;
  result.M32 = matrix.M23;
  result.M33 = matrix.M33;
  result.M34 = matrix.M43;
  result.M41 = matrix.M14;
  result.M42 = matrix.M24;
  result.M43 = matrix.M34;
  result.M44 = matrix.M44;
  return result;
}

Matrix4x4 Matrix4x4::Lerp(Matrix4x4 matrix1, Matrix4x4 matrix2, Single amount) {
  if (Sse::in::get_IsSupported()) {
    Vector128<Single> t = Vector128<>::Create(amount);
    Sse::in::Store(&matrix1.M11, VectorMath::Lerp(Sse::in::LoadVector128(&matrix1.M11), Sse::in::LoadVector128(&matrix2.M11), t));
    Sse::in::Store(&matrix1.M21, VectorMath::Lerp(Sse::in::LoadVector128(&matrix1.M21), Sse::in::LoadVector128(&matrix2.M21), t));
    Sse::in::Store(&matrix1.M31, VectorMath::Lerp(Sse::in::LoadVector128(&matrix1.M31), Sse::in::LoadVector128(&matrix2.M31), t));
    Sse::in::Store(&matrix1.M41, VectorMath::Lerp(Sse::in::LoadVector128(&matrix1.M41), Sse::in::LoadVector128(&matrix2.M41), t));
    return matrix1;
  }
  Matrix4x4 result;
  result.M11 = matrix1.M11 + (matrix2.M11 - matrix1.M11) * amount;
  result.M12 = matrix1.M12 + (matrix2.M12 - matrix1.M12) * amount;
  result.M13 = matrix1.M13 + (matrix2.M13 - matrix1.M13) * amount;
  result.M14 = matrix1.M14 + (matrix2.M14 - matrix1.M14) * amount;
  result.M21 = matrix1.M21 + (matrix2.M21 - matrix1.M21) * amount;
  result.M22 = matrix1.M22 + (matrix2.M22 - matrix1.M22) * amount;
  result.M23 = matrix1.M23 + (matrix2.M23 - matrix1.M23) * amount;
  result.M24 = matrix1.M24 + (matrix2.M24 - matrix1.M24) * amount;
  result.M31 = matrix1.M31 + (matrix2.M31 - matrix1.M31) * amount;
  result.M32 = matrix1.M32 + (matrix2.M32 - matrix1.M32) * amount;
  result.M33 = matrix1.M33 + (matrix2.M33 - matrix1.M33) * amount;
  result.M34 = matrix1.M34 + (matrix2.M34 - matrix1.M34) * amount;
  result.M41 = matrix1.M41 + (matrix2.M41 - matrix1.M41) * amount;
  result.M42 = matrix1.M42 + (matrix2.M42 - matrix1.M42) * amount;
  result.M43 = matrix1.M43 + (matrix2.M43 - matrix1.M43) * amount;
  result.M44 = matrix1.M44 + (matrix2.M44 - matrix1.M44) * amount;
  return result;
}

Matrix4x4 Matrix4x4::Negate(Matrix4x4 value) {
  return -value;
}

Matrix4x4 Matrix4x4::Add(Matrix4x4 value1, Matrix4x4 value2) {
  return value1 + value2;
}

Matrix4x4 Matrix4x4::Subtract(Matrix4x4 value1, Matrix4x4 value2) {
  return value1 - value2;
}

Matrix4x4 Matrix4x4::Multiply(Matrix4x4 value1, Matrix4x4 value2) {
  return value1 * value2;
}

Matrix4x4 Matrix4x4::Multiply(Matrix4x4 value1, Single value2) {
  return value1 * value2;
}

Matrix4x4 Matrix4x4::op_UnaryNegation(Matrix4x4 value) {
  if (Sse::in::get_IsSupported()) {
    Vector128<Single> zero = Vector128<Single>::get_Zero();
    Sse::in::Store(&value.M11, Sse::in::Subtract(zero, Sse::in::LoadVector128(&value.M11)));
    Sse::in::Store(&value.M21, Sse::in::Subtract(zero, Sse::in::LoadVector128(&value.M21)));
    Sse::in::Store(&value.M31, Sse::in::Subtract(zero, Sse::in::LoadVector128(&value.M31)));
    Sse::in::Store(&value.M41, Sse::in::Subtract(zero, Sse::in::LoadVector128(&value.M41)));
    return value;
  }
  Matrix4x4 result;
  result.M11 = 0 - value.M11;
  result.M12 = 0 - value.M12;
  result.M13 = 0 - value.M13;
  result.M14 = 0 - value.M14;
  result.M21 = 0 - value.M21;
  result.M22 = 0 - value.M22;
  result.M23 = 0 - value.M23;
  result.M24 = 0 - value.M24;
  result.M31 = 0 - value.M31;
  result.M32 = 0 - value.M32;
  result.M33 = 0 - value.M33;
  result.M34 = 0 - value.M34;
  result.M41 = 0 - value.M41;
  result.M42 = 0 - value.M42;
  result.M43 = 0 - value.M43;
  result.M44 = 0 - value.M44;
  return result;
}

Matrix4x4 Matrix4x4::op_Addition(Matrix4x4 value1, Matrix4x4 value2) {
  if (Sse::in::get_IsSupported()) {
    Sse::in::Store(&value1.M11, Sse::in::Add(Sse::in::LoadVector128(&value1.M11), Sse::in::LoadVector128(&value2.M11)));
    Sse::in::Store(&value1.M21, Sse::in::Add(Sse::in::LoadVector128(&value1.M21), Sse::in::LoadVector128(&value2.M21)));
    Sse::in::Store(&value1.M31, Sse::in::Add(Sse::in::LoadVector128(&value1.M31), Sse::in::LoadVector128(&value2.M31)));
    Sse::in::Store(&value1.M41, Sse::in::Add(Sse::in::LoadVector128(&value1.M41), Sse::in::LoadVector128(&value2.M41)));
    return value1;
  }
  Matrix4x4 result;
  result.M11 = value1.M11 + value2.M11;
  result.M12 = value1.M12 + value2.M12;
  result.M13 = value1.M13 + value2.M13;
  result.M14 = value1.M14 + value2.M14;
  result.M21 = value1.M21 + value2.M21;
  result.M22 = value1.M22 + value2.M22;
  result.M23 = value1.M23 + value2.M23;
  result.M24 = value1.M24 + value2.M24;
  result.M31 = value1.M31 + value2.M31;
  result.M32 = value1.M32 + value2.M32;
  result.M33 = value1.M33 + value2.M33;
  result.M34 = value1.M34 + value2.M34;
  result.M41 = value1.M41 + value2.M41;
  result.M42 = value1.M42 + value2.M42;
  result.M43 = value1.M43 + value2.M43;
  result.M44 = value1.M44 + value2.M44;
  return result;
}

Matrix4x4 Matrix4x4::op_Subtraction(Matrix4x4 value1, Matrix4x4 value2) {
  if (Sse::in::get_IsSupported()) {
    Sse::in::Store(&value1.M11, Sse::in::Subtract(Sse::in::LoadVector128(&value1.M11), Sse::in::LoadVector128(&value2.M11)));
    Sse::in::Store(&value1.M21, Sse::in::Subtract(Sse::in::LoadVector128(&value1.M21), Sse::in::LoadVector128(&value2.M21)));
    Sse::in::Store(&value1.M31, Sse::in::Subtract(Sse::in::LoadVector128(&value1.M31), Sse::in::LoadVector128(&value2.M31)));
    Sse::in::Store(&value1.M41, Sse::in::Subtract(Sse::in::LoadVector128(&value1.M41), Sse::in::LoadVector128(&value2.M41)));
    return value1;
  }
  Matrix4x4 result;
  result.M11 = value1.M11 - value2.M11;
  result.M12 = value1.M12 - value2.M12;
  result.M13 = value1.M13 - value2.M13;
  result.M14 = value1.M14 - value2.M14;
  result.M21 = value1.M21 - value2.M21;
  result.M22 = value1.M22 - value2.M22;
  result.M23 = value1.M23 - value2.M23;
  result.M24 = value1.M24 - value2.M24;
  result.M31 = value1.M31 - value2.M31;
  result.M32 = value1.M32 - value2.M32;
  result.M33 = value1.M33 - value2.M33;
  result.M34 = value1.M34 - value2.M34;
  result.M41 = value1.M41 - value2.M41;
  result.M42 = value1.M42 - value2.M42;
  result.M43 = value1.M43 - value2.M43;
  result.M44 = value1.M44 - value2.M44;
  return result;
}

Matrix4x4 Matrix4x4::op_Multiply(Matrix4x4 value1, Matrix4x4 value2) {
  if (Sse::in::get_IsSupported()) {
    Vector128<Single> vector = Sse::in::LoadVector128(&value1.M11);
    Sse::in::Store(&value1.M11, Sse::in::Add(Sse::in::Add(Sse::in::Multiply(Sse::in::Shuffle(vector, vector, 0), Sse::in::LoadVector128(&value2.M11)), Sse::in::Multiply(Sse::in::Shuffle(vector, vector, 85), Sse::in::LoadVector128(&value2.M21))), Sse::in::Add(Sse::in::Multiply(Sse::in::Shuffle(vector, vector, 170), Sse::in::LoadVector128(&value2.M31)), Sse::in::Multiply(Sse::in::Shuffle(vector, vector, Byte::MaxValue()), Sse::in::LoadVector128(&value2.M41)))));
    vector = Sse::in::LoadVector128(&value1.M21);
    Sse::in::Store(&value1.M21, Sse::in::Add(Sse::in::Add(Sse::in::Multiply(Sse::in::Shuffle(vector, vector, 0), Sse::in::LoadVector128(&value2.M11)), Sse::in::Multiply(Sse::in::Shuffle(vector, vector, 85), Sse::in::LoadVector128(&value2.M21))), Sse::in::Add(Sse::in::Multiply(Sse::in::Shuffle(vector, vector, 170), Sse::in::LoadVector128(&value2.M31)), Sse::in::Multiply(Sse::in::Shuffle(vector, vector, Byte::MaxValue()), Sse::in::LoadVector128(&value2.M41)))));
    vector = Sse::in::LoadVector128(&value1.M31);
    Sse::in::Store(&value1.M31, Sse::in::Add(Sse::in::Add(Sse::in::Multiply(Sse::in::Shuffle(vector, vector, 0), Sse::in::LoadVector128(&value2.M11)), Sse::in::Multiply(Sse::in::Shuffle(vector, vector, 85), Sse::in::LoadVector128(&value2.M21))), Sse::in::Add(Sse::in::Multiply(Sse::in::Shuffle(vector, vector, 170), Sse::in::LoadVector128(&value2.M31)), Sse::in::Multiply(Sse::in::Shuffle(vector, vector, Byte::MaxValue()), Sse::in::LoadVector128(&value2.M41)))));
    vector = Sse::in::LoadVector128(&value1.M41);
    Sse::in::Store(&value1.M41, Sse::in::Add(Sse::in::Add(Sse::in::Multiply(Sse::in::Shuffle(vector, vector, 0), Sse::in::LoadVector128(&value2.M11)), Sse::in::Multiply(Sse::in::Shuffle(vector, vector, 85), Sse::in::LoadVector128(&value2.M21))), Sse::in::Add(Sse::in::Multiply(Sse::in::Shuffle(vector, vector, 170), Sse::in::LoadVector128(&value2.M31)), Sse::in::Multiply(Sse::in::Shuffle(vector, vector, Byte::MaxValue()), Sse::in::LoadVector128(&value2.M41)))));
    return value1;
  }
  Matrix4x4 result;
  result.M11 = value1.M11 * value2.M11 + value1.M12 * value2.M21 + value1.M13 * value2.M31 + value1.M14 * value2.M41;
  result.M12 = value1.M11 * value2.M12 + value1.M12 * value2.M22 + value1.M13 * value2.M32 + value1.M14 * value2.M42;
  result.M13 = value1.M11 * value2.M13 + value1.M12 * value2.M23 + value1.M13 * value2.M33 + value1.M14 * value2.M43;
  result.M14 = value1.M11 * value2.M14 + value1.M12 * value2.M24 + value1.M13 * value2.M34 + value1.M14 * value2.M44;
  result.M21 = value1.M21 * value2.M11 + value1.M22 * value2.M21 + value1.M23 * value2.M31 + value1.M24 * value2.M41;
  result.M22 = value1.M21 * value2.M12 + value1.M22 * value2.M22 + value1.M23 * value2.M32 + value1.M24 * value2.M42;
  result.M23 = value1.M21 * value2.M13 + value1.M22 * value2.M23 + value1.M23 * value2.M33 + value1.M24 * value2.M43;
  result.M24 = value1.M21 * value2.M14 + value1.M22 * value2.M24 + value1.M23 * value2.M34 + value1.M24 * value2.M44;
  result.M31 = value1.M31 * value2.M11 + value1.M32 * value2.M21 + value1.M33 * value2.M31 + value1.M34 * value2.M41;
  result.M32 = value1.M31 * value2.M12 + value1.M32 * value2.M22 + value1.M33 * value2.M32 + value1.M34 * value2.M42;
  result.M33 = value1.M31 * value2.M13 + value1.M32 * value2.M23 + value1.M33 * value2.M33 + value1.M34 * value2.M43;
  result.M34 = value1.M31 * value2.M14 + value1.M32 * value2.M24 + value1.M33 * value2.M34 + value1.M34 * value2.M44;
  result.M41 = value1.M41 * value2.M11 + value1.M42 * value2.M21 + value1.M43 * value2.M31 + value1.M44 * value2.M41;
  result.M42 = value1.M41 * value2.M12 + value1.M42 * value2.M22 + value1.M43 * value2.M32 + value1.M44 * value2.M42;
  result.M43 = value1.M41 * value2.M13 + value1.M42 * value2.M23 + value1.M43 * value2.M33 + value1.M44 * value2.M43;
  result.M44 = value1.M41 * value2.M14 + value1.M42 * value2.M24 + value1.M43 * value2.M34 + value1.M44 * value2.M44;
  return result;
}

Matrix4x4 Matrix4x4::op_Multiply(Matrix4x4 value1, Single value2) {
  if (Sse::in::get_IsSupported()) {
    Vector128<Single> right = Vector128<>::Create(value2);
    Sse::in::Store(&value1.M11, Sse::in::Multiply(Sse::in::LoadVector128(&value1.M11), right));
    Sse::in::Store(&value1.M21, Sse::in::Multiply(Sse::in::LoadVector128(&value1.M21), right));
    Sse::in::Store(&value1.M31, Sse::in::Multiply(Sse::in::LoadVector128(&value1.M31), right));
    Sse::in::Store(&value1.M41, Sse::in::Multiply(Sse::in::LoadVector128(&value1.M41), right));
    return value1;
  }
  Matrix4x4 result;
  result.M11 = value1.M11 * value2;
  result.M12 = value1.M12 * value2;
  result.M13 = value1.M13 * value2;
  result.M14 = value1.M14 * value2;
  result.M21 = value1.M21 * value2;
  result.M22 = value1.M22 * value2;
  result.M23 = value1.M23 * value2;
  result.M24 = value1.M24 * value2;
  result.M31 = value1.M31 * value2;
  result.M32 = value1.M32 * value2;
  result.M33 = value1.M33 * value2;
  result.M34 = value1.M34 * value2;
  result.M41 = value1.M41 * value2;
  result.M42 = value1.M42 * value2;
  result.M43 = value1.M43 * value2;
  result.M44 = value1.M44 * value2;
  return result;
}

Boolean Matrix4x4::op_Equality(Matrix4x4 value1, Matrix4x4 value2) {
  if (Sse::in::get_IsSupported()) {
    if (VectorMath::Equal(Sse::in::LoadVector128(&value1.M11), Sse::in::LoadVector128(&value2.M11)) && VectorMath::Equal(Sse::in::LoadVector128(&value1.M21), Sse::in::LoadVector128(&value2.M21)) && VectorMath::Equal(Sse::in::LoadVector128(&value1.M31), Sse::in::LoadVector128(&value2.M31))) {
      return VectorMath::Equal(Sse::in::LoadVector128(&value1.M41), Sse::in::LoadVector128(&value2.M41));
    }
    return false;
  }
  if (value1.M11 == value2.M11 && value1.M22 == value2.M22 && value1.M33 == value2.M33 && value1.M44 == value2.M44 && value1.M12 == value2.M12 && value1.M13 == value2.M13 && value1.M14 == value2.M14 && value1.M21 == value2.M21 && value1.M23 == value2.M23 && value1.M24 == value2.M24 && value1.M31 == value2.M31 && value1.M32 == value2.M32 && value1.M34 == value2.M34 && value1.M41 == value2.M41 && value1.M42 == value2.M42) {
    return value1.M43 == value2.M43;
  }
  return false;
}

Boolean Matrix4x4::op_Inequality(Matrix4x4 value1, Matrix4x4 value2) {
  if (Sse::in::get_IsSupported()) {
    if (!VectorMath::NotEqual(Sse::in::LoadVector128(&value1.M11), Sse::in::LoadVector128(&value2.M11)) && !VectorMath::NotEqual(Sse::in::LoadVector128(&value1.M21), Sse::in::LoadVector128(&value2.M21)) && !VectorMath::NotEqual(Sse::in::LoadVector128(&value1.M31), Sse::in::LoadVector128(&value2.M31))) {
      return VectorMath::NotEqual(Sse::in::LoadVector128(&value1.M41), Sse::in::LoadVector128(&value2.M41));
    }
    return true;
  }
  if (value1.M11 == value2.M11 && value1.M12 == value2.M12 && value1.M13 == value2.M13 && value1.M14 == value2.M14 && value1.M21 == value2.M21 && value1.M22 == value2.M22 && value1.M23 == value2.M23 && value1.M24 == value2.M24 && value1.M31 == value2.M31 && value1.M32 == value2.M32 && value1.M33 == value2.M33 && value1.M34 == value2.M34 && value1.M41 == value2.M41 && value1.M42 == value2.M42 && value1.M43 == value2.M43) {
    return value1.M44 != value2.M44;
  }
  return true;
}

Boolean Matrix4x4::Equals(Matrix4x4 other) {
  return *this == other;
}

Boolean Matrix4x4::Equals(Object obj) {
  if (rt::is<Matrix4x4>(obj)) {
    Matrix4x4 value = (Matrix4x4)obj;
    return *this == value;
  }
  return false;
}

String Matrix4x4::ToString() {
  return String::in::Format(CultureInfo::in::get_CurrentCulture(), "{{ {{M11:{0} M12:{1} M13:{2} M14:{3}}} {{M21:{4} M22:{5} M23:{6} M24:{7}}} {{M31:{8} M32:{9} M33:{10} M34:{11}}} {{M41:{12} M42:{13} M43:{14} M44:{15}}} }}", rt::newarr<Array<Object>>(16, M11, M12, M13, M14, M21, M22, M23, M24, M31, M32, M33, M34, M41, M42, M43, M44));
}

Int32 Matrix4x4::GetHashCode() {
  return M11.GetHashCode() + M12.GetHashCode() + M13.GetHashCode() + M14.GetHashCode() + M21.GetHashCode() + M22.GetHashCode() + M23.GetHashCode() + M24.GetHashCode() + M31.GetHashCode() + M32.GetHashCode() + M33.GetHashCode() + M34.GetHashCode() + M41.GetHashCode() + M42.GetHashCode() + M43.GetHashCode() + M44.GetHashCode();
}

void Matrix4x4::cctor() {
  _identity = Matrix4x4(1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1);
}

Boolean Matrix4x4::_Invert_g__SseImpl59_0(Matrix4x4 matrix, Matrix4x4& result) {
  Vector128<Single> left = Sse::in::LoadVector128(&matrix.M11);
  Vector128<Single> right = Sse::in::LoadVector128(&matrix.M21);
  Vector128<Single> left2 = Sse::in::LoadVector128(&matrix.M31);
  Vector128<Single> right2 = Sse::in::LoadVector128(&matrix.M41);
  Vector128<Single> left3 = Sse::in::Shuffle(left, right, 68);
  Vector128<Single> left4 = Sse::in::Shuffle(left, right, 238);
  Vector128<Single> right3 = Sse::in::Shuffle(left2, right2, 68);
  Vector128<Single> right4 = Sse::in::Shuffle(left2, right2, 238);
  left = Sse::in::Shuffle(left3, right3, 136);
  right = Sse::in::Shuffle(left3, right3, 221);
  left2 = Sse::in::Shuffle(left4, right4, 136);
  right2 = Sse::in::Shuffle(left4, right4, 221);
  Vector128<Single> left5 = Permute(left2, 80);
  Vector128<Single> right5 = Permute(right2, 238);
  Vector128<Single> left6 = Permute(left, 80);
  Vector128<Single> right6 = Permute(right, 238);
  Vector128<Single> left7 = Sse::in::Shuffle(left2, left, 136);
  Vector128<Single> right7 = Sse::in::Shuffle(right2, right, 221);
  Vector128<Single> left8 = Sse::in::Multiply(left5, right5);
  Vector128<Single> left9 = Sse::in::Multiply(left6, right6);
  Vector128<Single> left10 = Sse::in::Multiply(left7, right7);
  left5 = Permute(left2, 238);
  right5 = Permute(right2, 80);
  left6 = Permute(left, 238);
  right6 = Permute(right, 80);
  left7 = Sse::in::Shuffle(left2, left, 221);
  right7 = Sse::in::Shuffle(right2, right, 136);
  left8 = Sse::in::Subtract(left8, Sse::in::Multiply(left5, right5));
  left9 = Sse::in::Subtract(left9, Sse::in::Multiply(left6, right6));
  left10 = Sse::in::Subtract(left10, Sse::in::Multiply(left7, right7));
  right6 = Sse::in::Shuffle(left8, left10, 93);
  left5 = Permute(right, 73);
  right5 = Sse::in::Shuffle(right6, left8, 50);
  left6 = Permute(left, 18);
  right6 = Sse::in::Shuffle(right6, left8, 153);
  Vector128<Single> left11 = Sse::in::Shuffle(left9, left10, 253);
  left7 = Permute(right2, 73);
  right7 = Sse::in::Shuffle(left11, left9, 50);
  Vector128<Single> left12 = Permute(left2, 18);
  left11 = Sse::in::Shuffle(left11, left9, 153);
  Vector128<Single> left13 = Sse::in::Multiply(left5, right5);
  Vector128<Single> left14 = Sse::in::Multiply(left6, right6);
  Vector128<Single> left15 = Sse::in::Multiply(left7, right7);
  Vector128<Single> left16 = Sse::in::Multiply(left12, left11);
  right6 = Sse::in::Shuffle(left8, left10, 4);
  left5 = Permute(right, 158);
  right5 = Sse::in::Shuffle(left8, right6, 147);
  left6 = Permute(left, 123);
  right6 = Sse::in::Shuffle(left8, right6, 38);
  left11 = Sse::in::Shuffle(left9, left10, 164);
  left7 = Permute(right2, 158);
  right7 = Sse::in::Shuffle(left9, left11, 147);
  left12 = Permute(left2, 123);
  left11 = Sse::in::Shuffle(left9, left11, 38);
  left13 = Sse::in::Subtract(left13, Sse::in::Multiply(left5, right5));
  left14 = Sse::in::Subtract(left14, Sse::in::Multiply(left6, right6));
  left15 = Sse::in::Subtract(left15, Sse::in::Multiply(left7, right7));
  left16 = Sse::in::Subtract(left16, Sse::in::Multiply(left12, left11));
  left5 = Permute(right, 51);
  right5 = Sse::in::Shuffle(left8, left10, 74);
  right5 = Permute(right5, 44);
  left6 = Permute(left, 141);
  right6 = Sse::in::Shuffle(left8, left10, 76);
  right6 = Permute(right6, 147);
  left7 = Permute(right2, 51);
  right7 = Sse::in::Shuffle(left9, left10, 234);
  right7 = Permute(right7, 44);
  left12 = Permute(left2, 141);
  left11 = Sse::in::Shuffle(left9, left10, 236);
  left11 = Permute(left11, 147);
  left5 = Sse::in::Multiply(left5, right5);
  left6 = Sse::in::Multiply(left6, right6);
  left7 = Sse::in::Multiply(left7, right7);
  left12 = Sse::in::Multiply(left12, left11);
  Vector128<Single> right8 = Sse::in::Subtract(left13, left5);
  left13 = Sse::in::Add(left13, left5);
  Vector128<Single> right9 = Sse::in::Add(left14, left6);
  left14 = Sse::in::Subtract(left14, left6);
  Vector128<Single> right10 = Sse::in::Subtract(left15, left7);
  left15 = Sse::in::Add(left15, left7);
  Vector128<Single> right11 = Sse::in::Add(left16, left12);
  left16 = Sse::in::Subtract(left16, left12);
  left13 = Sse::in::Shuffle(left13, right8, 216);
  left14 = Sse::in::Shuffle(left14, right9, 216);
  left15 = Sse::in::Shuffle(left15, right10, 216);
  left16 = Sse::in::Shuffle(left16, right11, 216);
  left13 = Permute(left13, 216);
  left14 = Permute(left14, 216);
  left15 = Permute(left15, 216);
  left16 = Permute(left16, 216);
  right3 = left;
  Single num = Vector4::Dot(Vector128<>::AsVector4(left13), Vector128<>::AsVector4(right3));
  if (MathF::Abs(num) < Single::Epsilon()) {
    result = Matrix4x4(Single::NaN(), Single::NaN(), Single::NaN(), Single::NaN(), Single::NaN(), Single::NaN(), Single::NaN(), Single::NaN(), Single::NaN(), Single::NaN(), Single::NaN(), Single::NaN(), Single::NaN(), Single::NaN(), Single::NaN(), Single::NaN());
    return false;
  }
  Vector128<Single> left17 = Vector128<>::Create(1);
  Vector128<Single> right12 = Vector128<>::Create(num);
  right12 = Sse::in::Divide(left17, right12);
  left = Sse::in::Multiply(left13, right12);
  right = Sse::in::Multiply(left14, right12);
  left2 = Sse::in::Multiply(left15, right12);
  right2 = Sse::in::Multiply(left16, right12);
  Unsafe::SkipInit<Matrix4x4>(result);
  Vector128<Single>& reference = Unsafe::As<Matrix4x4, Vector128<Single>>(result);
  reference = left;
  Unsafe::Add(reference, 1) = right;
  Unsafe::Add(reference, 2) = left2;
  Unsafe::Add(reference, 3) = right2;
  return true;
}

Boolean Matrix4x4::_Invert_g__SoftwareFallback59_1(Matrix4x4 matrix, Matrix4x4& result) {
  Single m = matrix.M11;
  Single m2 = matrix.M12;
  Single m3 = matrix.M13;
  Single m4 = matrix.M14;
  Single m5 = matrix.M21;
  Single m6 = matrix.M22;
  Single m7 = matrix.M23;
  Single m8 = matrix.M24;
  Single m9 = matrix.M31;
  Single m10 = matrix.M32;
  Single m11 = matrix.M33;
  Single m12 = matrix.M34;
  Single m13 = matrix.M41;
  Single m14 = matrix.M42;
  Single m15 = matrix.M43;
  Single m16 = matrix.M44;
  Single num = m11 * m16 - m12 * m15;
  Single num2 = m10 * m16 - m12 * m14;
  Single num3 = m10 * m15 - m11 * m14;
  Single num4 = m9 * m16 - m12 * m13;
  Single num5 = m9 * m15 - m11 * m13;
  Single num6 = m9 * m14 - m10 * m13;
  Single num7 = m6 * num - m7 * num2 + m8 * num3;
  Single num8 = 0 - (m5 * num - m7 * num4 + m8 * num5);
  Single num9 = m5 * num2 - m6 * num4 + m8 * num6;
  Single num10 = 0 - (m5 * num3 - m6 * num5 + m7 * num6);
  Single num11 = m * num7 + m2 * num8 + m3 * num9 + m4 * num10;
  if (MathF::Abs(num11) < Single::Epsilon()) {
    result = Matrix4x4(Single::NaN(), Single::NaN(), Single::NaN(), Single::NaN(), Single::NaN(), Single::NaN(), Single::NaN(), Single::NaN(), Single::NaN(), Single::NaN(), Single::NaN(), Single::NaN(), Single::NaN(), Single::NaN(), Single::NaN(), Single::NaN());
    return false;
  }
  Single num12 = 1 / num11;
  result.M11 = num7 * num12;
  result.M21 = num8 * num12;
  result.M31 = num9 * num12;
  result.M41 = num10 * num12;
  result.M12 = (0 - (m2 * num - m3 * num2 + m4 * num3)) * num12;
  result.M22 = (m * num - m3 * num4 + m4 * num5) * num12;
  result.M32 = (0 - (m * num2 - m2 * num4 + m4 * num6)) * num12;
  result.M42 = (m * num3 - m2 * num5 + m3 * num6) * num12;
  Single num13 = m7 * m16 - m8 * m15;
  Single num14 = m6 * m16 - m8 * m14;
  Single num15 = m6 * m15 - m7 * m14;
  Single num16 = m5 * m16 - m8 * m13;
  Single num17 = m5 * m15 - m7 * m13;
  Single num18 = m5 * m14 - m6 * m13;
  result.M13 = (m2 * num13 - m3 * num14 + m4 * num15) * num12;
  result.M23 = (0 - (m * num13 - m3 * num16 + m4 * num17)) * num12;
  result.M33 = (m * num14 - m2 * num16 + m4 * num18) * num12;
  result.M43 = (0 - (m * num15 - m2 * num17 + m3 * num18)) * num12;
  Single num19 = m7 * m12 - m8 * m11;
  Single num20 = m6 * m12 - m8 * m10;
  Single num21 = m6 * m11 - m7 * m10;
  Single num22 = m5 * m12 - m8 * m9;
  Single num23 = m5 * m11 - m7 * m9;
  Single num24 = m5 * m10 - m6 * m9;
  result.M14 = (0 - (m2 * num19 - m3 * num20 + m4 * num21)) * num12;
  result.M24 = (m * num19 - m3 * num22 + m4 * num23) * num12;
  result.M34 = (0 - (m * num20 - m2 * num22 + m4 * num24)) * num12;
  result.M44 = (m * num21 - m2 * num23 + m3 * num24) * num12;
  return true;
}

} // namespace System::Private::CoreLib::System::Numerics::Matrix4x4Namespace
