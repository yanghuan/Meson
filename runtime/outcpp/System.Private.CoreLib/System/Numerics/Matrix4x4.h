#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Numerics/Vector3.h>
#include <System.Private.CoreLib/System/Single.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(Byte)
FORWARDS(Int32)
FORWARD(Object)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::Intrinsics {
FORWARDS_(Vector128, T1, T2)
} // namespace System::Private::CoreLib::System::Runtime::Intrinsics
namespace System::Private::CoreLib::System::Numerics {
FORWARDS(Quaternion)
FORWARDS(Plane)
namespace Matrix4x4Namespace {
using namespace ::System::Private::CoreLib::System::Runtime::Intrinsics;
struct Matrix4x4 {
  private: struct CanonicalBasis {
    public: Vector3 Row0;
    public: Vector3 Row1;
    public: Vector3 Row2;
  };
  private: struct VectorBasis {
    public: Vector3* Element0;
    public: Vector3* Element1;
    public: Vector3* Element2;
  };
  public: static Matrix4x4 get_Identity();
  public: Boolean get_IsIdentity();
  public: Vector3 get_Translation();
  public: void set_Translation(Vector3 value);
  public: static Matrix4x4 CreateBillboard(Vector3 objectPosition, Vector3 cameraPosition, Vector3 cameraUpVector, Vector3 cameraForwardVector);
  public: static Matrix4x4 CreateConstrainedBillboard(Vector3 objectPosition, Vector3 cameraPosition, Vector3 rotateAxis, Vector3 cameraForwardVector, Vector3 objectForwardVector);
  public: static Matrix4x4 CreateTranslation(Vector3 position);
  public: static Matrix4x4 CreateTranslation(Single xPosition, Single yPosition, Single zPosition);
  public: static Matrix4x4 CreateScale(Single xScale, Single yScale, Single zScale);
  public: static Matrix4x4 CreateScale(Single xScale, Single yScale, Single zScale, Vector3 centerPoint);
  public: static Matrix4x4 CreateScale(Vector3 scales);
  public: static Matrix4x4 CreateScale(Vector3 scales, Vector3 centerPoint);
  public: static Matrix4x4 CreateScale(Single scale);
  public: static Matrix4x4 CreateScale(Single scale, Vector3 centerPoint);
  public: static Matrix4x4 CreateRotationX(Single radians);
  public: static Matrix4x4 CreateRotationX(Single radians, Vector3 centerPoint);
  public: static Matrix4x4 CreateRotationY(Single radians);
  public: static Matrix4x4 CreateRotationY(Single radians, Vector3 centerPoint);
  public: static Matrix4x4 CreateRotationZ(Single radians);
  public: static Matrix4x4 CreateRotationZ(Single radians, Vector3 centerPoint);
  public: static Matrix4x4 CreateFromAxisAngle(Vector3 axis, Single angle);
  public: static Matrix4x4 CreatePerspectiveFieldOfView(Single fieldOfView, Single aspectRatio, Single nearPlaneDistance, Single farPlaneDistance);
  public: static Matrix4x4 CreatePerspective(Single width, Single height, Single nearPlaneDistance, Single farPlaneDistance);
  public: static Matrix4x4 CreatePerspectiveOffCenter(Single left, Single right, Single bottom, Single top, Single nearPlaneDistance, Single farPlaneDistance);
  public: static Matrix4x4 CreateOrthographic(Single width, Single height, Single zNearPlane, Single zFarPlane);
  public: static Matrix4x4 CreateOrthographicOffCenter(Single left, Single right, Single bottom, Single top, Single zNearPlane, Single zFarPlane);
  public: static Matrix4x4 CreateLookAt(Vector3 cameraPosition, Vector3 cameraTarget, Vector3 cameraUpVector);
  public: static Matrix4x4 CreateWorld(Vector3 position, Vector3 forward, Vector3 up);
  public: static Matrix4x4 CreateFromQuaternion(Quaternion quaternion);
  public: static Matrix4x4 CreateFromYawPitchRoll(Single yaw, Single pitch, Single roll);
  public: static Matrix4x4 CreateShadow(Vector3 lightDirection, Plane plane);
  public: static Matrix4x4 CreateReflection(Plane value);
  public: Single GetDeterminant();
  private: static Vector128<Single> Permute(Vector128<Single> value, Byte control);
  public: static Boolean Invert(Matrix4x4 matrix, Matrix4x4& result);
  public: static Boolean Decompose(Matrix4x4 matrix, Vector3& scale, Quaternion& rotation, Vector3& translation);
  public: static Matrix4x4 Transform(Matrix4x4 value, Quaternion rotation);
  public: static Matrix4x4 Transpose(Matrix4x4 matrix);
  public: static Matrix4x4 Lerp(Matrix4x4 matrix1, Matrix4x4 matrix2, Single amount);
  public: static Matrix4x4 Negate(Matrix4x4 value);
  public: static Matrix4x4 Add(Matrix4x4 value1, Matrix4x4 value2);
  public: static Matrix4x4 Subtract(Matrix4x4 value1, Matrix4x4 value2);
  public: static Matrix4x4 Multiply(Matrix4x4 value1, Matrix4x4 value2);
  public: static Matrix4x4 Multiply(Matrix4x4 value1, Single value2);
  public: Boolean Equals(Matrix4x4 other);
  public: Boolean Equals(Object obj);
  public: String ToString();
  public: Int32 GetHashCode();
  public: Single M11;
  public: Single M12;
  public: Single M13;
  public: Single M14;
  public: Single M21;
  public: Single M22;
  public: Single M23;
  public: Single M24;
  public: Single M31;
  public: Single M32;
  public: Single M33;
  public: Single M34;
  public: Single M41;
  public: Single M42;
  public: Single M43;
  public: Single M44;
  private: static Matrix4x4 _identity;
};
} // namespace Matrix4x4Namespace
using Matrix4x4 = Matrix4x4Namespace::Matrix4x4;
} // namespace System::Private::CoreLib::System::Numerics
