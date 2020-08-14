#include "Plane-dep.h"

#include <System.Private.CoreLib/System/Globalization/CultureInfo-dep.h>
#include <System.Private.CoreLib/System/MathF-dep.h>
#include <System.Private.CoreLib/System/Numerics/Plane-dep.h>
#include <System.Private.CoreLib/System/Numerics/Vector-dep.h>
#include <System.Private.CoreLib/System/Numerics/Vector3-dep.h>

namespace System::Private::CoreLib::System::Numerics::PlaneNamespace {
using namespace System::Globalization;

Plane::Plane(Single x, Single y, Single z, Single d) {
  Normal = Vector3(x, y, z);
  D = d;
}

Plane::Plane(Vector3 normal, Single d) {
  Normal = normal;
  D = d;
}

Plane::Plane(Vector4 value) {
  Normal = Vector3(value.X, value.Y, value.Z);
  D = value.W;
}

Plane Plane::CreateFromVertices(Vector3 point1, Vector3 point2, Vector3 point3) {
  if (Vector::get_IsHardwareAccelerated()) {
    Vector3 vector = point2 - point1;
    Vector3 vector2 = point3 - point1;
    Vector3 value = Vector3::Cross(vector, vector2);
    Vector3 vector3 = Vector3::Normalize(value);
    Single d = 0 - Vector3::Dot(vector3, point1);
    return Plane(vector3, d);
  }
  Single num = point2.X - point1.X;
  Single num2 = point2.Y - point1.Y;
  Single num3 = point2.Z - point1.Z;
  Single num4 = point3.X - point1.X;
  Single num5 = point3.Y - point1.Y;
  Single num6 = point3.Z - point1.Z;
  Single num7 = num2 * num6 - num3 * num5;
  Single num8 = num3 * num4 - num * num6;
  Single num9 = num * num5 - num2 * num4;
  Single x = num7 * num7 + num8 * num8 + num9 * num9;
  Single num10 = 1 / MathF::Sqrt(x);
  Vector3 normal = Vector3(num7 * num10, num8 * num10, num9 * num10);
  return Plane(normal, 0 - (normal.X * point1.X + normal.Y * point1.Y + normal.Z * point1.Z));
}

Plane Plane::Normalize(Plane value) {
  if (Vector::get_IsHardwareAccelerated()) {
    Single num = value.Normal.LengthSquared();
    if (MathF::Abs(num - 1) < 1.1920929E-07) {
      return value;
    }
    Single num2 = MathF::Sqrt(num);
    return Plane(value.Normal / num2, value.D / num2);
  }
  Single num3 = value.Normal.X * value.Normal.X + value.Normal.Y * value.Normal.Y + value.Normal.Z * value.Normal.Z;
  if (MathF::Abs(num3 - 1) < 1.1920929E-07) {
    return value;
  }
  Single num4 = 1 / MathF::Sqrt(num3);
  return Plane(value.Normal.X * num4, value.Normal.Y * num4, value.Normal.Z * num4, value.D * num4);
}

Plane Plane::Transform(Plane plane, Matrix4x4 matrix) {
  Matrix4x4 result;
  Matrix4x4::Invert(matrix, result);
  Single x = plane.Normal.X;
  Single y = plane.Normal.Y;
  Single z = plane.Normal.Z;
  Single d = plane.D;
  return Plane(x * result.M11 + y * result.M12 + z * result.M13 + d * result.M14, x * result.M21 + y * result.M22 + z * result.M23 + d * result.M24, x * result.M31 + y * result.M32 + z * result.M33 + d * result.M34, x * result.M41 + y * result.M42 + z * result.M43 + d * result.M44);
}

Plane Plane::Transform(Plane plane, Quaternion rotation) {
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
  Single x = plane.Normal.X;
  Single y = plane.Normal.Y;
  Single z = plane.Normal.Z;
  return Plane(x * num13 + y * num14 + z * num15, x * num16 + y * num17 + z * num18, x * num19 + y * num20 + z * num21, plane.D);
}

Single Plane::Dot(Plane plane, Vector4 value) {
  return plane.Normal.X * value.X + plane.Normal.Y * value.Y + plane.Normal.Z * value.Z + plane.D * value.W;
}

Single Plane::DotCoordinate(Plane plane, Vector3 value) {
  if (Vector::get_IsHardwareAccelerated()) {
    return Vector3::Dot(plane.Normal, value) + plane.D;
  }
  return plane.Normal.X * value.X + plane.Normal.Y * value.Y + plane.Normal.Z * value.Z + plane.D;
}

Single Plane::DotNormal(Plane plane, Vector3 value) {
  if (Vector::get_IsHardwareAccelerated()) {
    return Vector3::Dot(plane.Normal, value);
  }
  return plane.Normal.X * value.X + plane.Normal.Y * value.Y + plane.Normal.Z * value.Z;
}

Boolean Plane::op_Equality(Plane value1, Plane value2) {
  if (value1.Normal.X == value2.Normal.X && value1.Normal.Y == value2.Normal.Y && value1.Normal.Z == value2.Normal.Z) {
    return value1.D == value2.D;
  }
  return false;
}

Boolean Plane::op_Inequality(Plane value1, Plane value2) {
  if (value1.Normal.X == value2.Normal.X && value1.Normal.Y == value2.Normal.Y && value1.Normal.Z == value2.Normal.Z) {
    return value1.D != value2.D;
  }
  return true;
}

Boolean Plane::Equals(Plane other) {
  if (Vector::get_IsHardwareAccelerated()) {
    if (Normal.Equals(other.Normal)) {
      return D == other.D;
    }
    return false;
  }
  if (Normal.X == other.Normal.X && Normal.Y == other.Normal.Y && Normal.Z == other.Normal.Z) {
    return D == other.D;
  }
  return false;
}

Boolean Plane::Equals(Object obj) {
  if (rt::is<Plane>(obj)) {
    return Equals((Plane)obj);
  }
  return false;
}

String Plane::ToString() {
  CultureInfo currentCulture = CultureInfo::in::get_CurrentCulture();
  return String::in::Format(currentCulture, "{{Normal:{0} D:{1}}}", Normal.ToString(), D.ToString(currentCulture));
}

Int32 Plane::GetHashCode() {
  return Normal.GetHashCode() + D.GetHashCode();
}

} // namespace System::Private::CoreLib::System::Numerics::PlaneNamespace
