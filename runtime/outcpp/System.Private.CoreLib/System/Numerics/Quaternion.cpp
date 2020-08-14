#include "Quaternion-dep.h"

#include <System.Private.CoreLib/System/Globalization/CultureInfo-dep.h>
#include <System.Private.CoreLib/System/MathF-dep.h>
#include <System.Private.CoreLib/System/Numerics/Quaternion-dep.h>

namespace System::Private::CoreLib::System::Numerics::QuaternionNamespace {
using namespace System::Globalization;

Quaternion Quaternion::get_Identity() {
  return Quaternion(0, 0, 0, 1);
}

Boolean Quaternion::get_IsIdentity() {
  if (X == 0 && Y == 0 && Z == 0) {
    return W == 1;
  }
  return false;
}

Quaternion::Quaternion(Single x, Single y, Single z, Single w) {
  X = x;
  Y = y;
  Z = z;
  W = w;
}

Quaternion::Quaternion(Vector3 vectorPart, Single scalarPart) {
  X = vectorPart.X;
  Y = vectorPart.Y;
  Z = vectorPart.Z;
  W = scalarPart;
}

Single Quaternion::Length() {
  Single x = X * X + Y * Y + Z * Z + W * W;
  return MathF::Sqrt(x);
}

Single Quaternion::LengthSquared() {
  return X * X + Y * Y + Z * Z + W * W;
}

Quaternion Quaternion::Normalize(Quaternion value) {
  Single x = value.X * value.X + value.Y * value.Y + value.Z * value.Z + value.W * value.W;
  Single num = 1 / MathF::Sqrt(x);
  Quaternion result;
  result.X = value.X * num;
  result.Y = value.Y * num;
  result.Z = value.Z * num;
  result.W = value.W * num;
  return result;
}

Quaternion Quaternion::Conjugate(Quaternion value) {
  Quaternion result;
  result.X = 0 - value.X;
  result.Y = 0 - value.Y;
  result.Z = 0 - value.Z;
  result.W = value.W;
  return result;
}

Quaternion Quaternion::Inverse(Quaternion value) {
  Single num = value.X * value.X + value.Y * value.Y + value.Z * value.Z + value.W * value.W;
  Single num2 = 1 / num;
  Quaternion result;
  result.X = (0 - value.X) * num2;
  result.Y = (0 - value.Y) * num2;
  result.Z = (0 - value.Z) * num2;
  result.W = value.W * num2;
  return result;
}

Quaternion Quaternion::CreateFromAxisAngle(Vector3 axis, Single angle) {
  Single x = angle * 0.5;
  Single num = MathF::Sin(x);
  Single w = MathF::Cos(x);
  Quaternion result;
  result.X = axis.X * num;
  result.Y = axis.Y * num;
  result.Z = axis.Z * num;
  result.W = w;
  return result;
}

Quaternion Quaternion::CreateFromYawPitchRoll(Single yaw, Single pitch, Single roll) {
  Single x = roll * 0.5;
  Single num = MathF::Sin(x);
  Single num2 = MathF::Cos(x);
  Single x2 = pitch * 0.5;
  Single num3 = MathF::Sin(x2);
  Single num4 = MathF::Cos(x2);
  Single x3 = yaw * 0.5;
  Single num5 = MathF::Sin(x3);
  Single num6 = MathF::Cos(x3);
  Quaternion result;
  result.X = num6 * num3 * num2 + num5 * num4 * num;
  result.Y = num5 * num4 * num2 - num6 * num3 * num;
  result.Z = num6 * num4 * num - num5 * num3 * num2;
  result.W = num6 * num4 * num2 + num5 * num3 * num;
  return result;
}

Quaternion Quaternion::CreateFromRotationMatrix(Matrix4x4 matrix) {
  Single num = matrix.M11 + matrix.M22 + matrix.M33;
  Quaternion result = Quaternion();
  if (num > 0) {
    Single num2 = MathF::Sqrt(num + 1);
    result.W = num2 * 0.5;
    num2 = 0.5 / num2;
    result.X = (matrix.M23 - matrix.M32) * num2;
    result.Y = (matrix.M31 - matrix.M13) * num2;
    result.Z = (matrix.M12 - matrix.M21) * num2;
  } else if (matrix.M11 >= matrix.M22 && matrix.M11 >= matrix.M33) {
    Single num3 = MathF::Sqrt(1 + matrix.M11 - matrix.M22 - matrix.M33);
    Single num4 = 0.5 / num3;
    result.X = 0.5 * num3;
    result.Y = (matrix.M12 + matrix.M21) * num4;
    result.Z = (matrix.M13 + matrix.M31) * num4;
    result.W = (matrix.M23 - matrix.M32) * num4;
  } else if (matrix.M22 > matrix.M33) {
    Single num5 = MathF::Sqrt(1 + matrix.M22 - matrix.M11 - matrix.M33);
    Single num6 = 0.5 / num5;
    result.X = (matrix.M21 + matrix.M12) * num6;
    result.Y = 0.5 * num5;
    result.Z = (matrix.M32 + matrix.M23) * num6;
    result.W = (matrix.M31 - matrix.M13) * num6;
  } else {
    Single num7 = MathF::Sqrt(1 + matrix.M33 - matrix.M11 - matrix.M22);
    Single num8 = 0.5 / num7;
    result.X = (matrix.M31 + matrix.M13) * num8;
    result.Y = (matrix.M32 + matrix.M23) * num8;
    result.Z = 0.5 * num7;
    result.W = (matrix.M12 - matrix.M21) * num8;
  }


  return result;
}

Single Quaternion::Dot(Quaternion quaternion1, Quaternion quaternion2) {
  return quaternion1.X * quaternion2.X + quaternion1.Y * quaternion2.Y + quaternion1.Z * quaternion2.Z + quaternion1.W * quaternion2.W;
}

Quaternion Quaternion::Slerp(Quaternion quaternion1, Quaternion quaternion2, Single amount) {
  Single num = quaternion1.X * quaternion2.X + quaternion1.Y * quaternion2.Y + quaternion1.Z * quaternion2.Z + quaternion1.W * quaternion2.W;
  Boolean flag = false;
  if (num < 0) {
    flag = true;
    num = 0 - num;
  }
  Single num2;
  Single num3;
  if (num > 0.999999) {
    num2 = 1 - amount;
    num3 = (flag ? (0 - amount) : amount);
  } else {
    Single num4 = MathF::Acos(num);
    Single num5 = 1 / MathF::Sin(num4);
    num2 = MathF::Sin((1 - amount) * num4) * num5;
    num3 = (flag ? ((0 - MathF::Sin(amount * num4)) * num5) : (MathF::Sin(amount * num4) * num5));
  }
  Quaternion result;
  result.X = num2 * quaternion1.X + num3 * quaternion2.X;
  result.Y = num2 * quaternion1.Y + num3 * quaternion2.Y;
  result.Z = num2 * quaternion1.Z + num3 * quaternion2.Z;
  result.W = num2 * quaternion1.W + num3 * quaternion2.W;
  return result;
}

Quaternion Quaternion::Lerp(Quaternion quaternion1, Quaternion quaternion2, Single amount) {
  Single num = 1 - amount;
  Quaternion result = Quaternion();
  Single num2 = quaternion1.X * quaternion2.X + quaternion1.Y * quaternion2.Y + quaternion1.Z * quaternion2.Z + quaternion1.W * quaternion2.W;
  if (num2 >= 0) {
    result.X = num * quaternion1.X + amount * quaternion2.X;
    result.Y = num * quaternion1.Y + amount * quaternion2.Y;
    result.Z = num * quaternion1.Z + amount * quaternion2.Z;
    result.W = num * quaternion1.W + amount * quaternion2.W;
  } else {
    result.X = num * quaternion1.X - amount * quaternion2.X;
    result.Y = num * quaternion1.Y - amount * quaternion2.Y;
    result.Z = num * quaternion1.Z - amount * quaternion2.Z;
    result.W = num * quaternion1.W - amount * quaternion2.W;
  }
  Single x = result.X * result.X + result.Y * result.Y + result.Z * result.Z + result.W * result.W;
  Single num3 = 1 / MathF::Sqrt(x);
  result.X *= num3;
  result.Y *= num3;
  result.Z *= num3;
  result.W *= num3;
  return result;
}

Quaternion Quaternion::Concatenate(Quaternion value1, Quaternion value2) {
  Single x = value2.X;
  Single y = value2.Y;
  Single z = value2.Z;
  Single w = value2.W;
  Single x2 = value1.X;
  Single y2 = value1.Y;
  Single z2 = value1.Z;
  Single w2 = value1.W;
  Single num = y * z2 - z * y2;
  Single num2 = z * x2 - x * z2;
  Single num3 = x * y2 - y * x2;
  Single num4 = x * x2 + y * y2 + z * z2;
  Quaternion result;
  result.X = x * w2 + x2 * w + num;
  result.Y = y * w2 + y2 * w + num2;
  result.Z = z * w2 + z2 * w + num3;
  result.W = w * w2 - num4;
  return result;
}

Quaternion Quaternion::Negate(Quaternion value) {
  Quaternion result;
  result.X = 0 - value.X;
  result.Y = 0 - value.Y;
  result.Z = 0 - value.Z;
  result.W = 0 - value.W;
  return result;
}

Quaternion Quaternion::Add(Quaternion value1, Quaternion value2) {
  Quaternion result;
  result.X = value1.X + value2.X;
  result.Y = value1.Y + value2.Y;
  result.Z = value1.Z + value2.Z;
  result.W = value1.W + value2.W;
  return result;
}

Quaternion Quaternion::Subtract(Quaternion value1, Quaternion value2) {
  Quaternion result;
  result.X = value1.X - value2.X;
  result.Y = value1.Y - value2.Y;
  result.Z = value1.Z - value2.Z;
  result.W = value1.W - value2.W;
  return result;
}

Quaternion Quaternion::Multiply(Quaternion value1, Quaternion value2) {
  Single x = value1.X;
  Single y = value1.Y;
  Single z = value1.Z;
  Single w = value1.W;
  Single x2 = value2.X;
  Single y2 = value2.Y;
  Single z2 = value2.Z;
  Single w2 = value2.W;
  Single num = y * z2 - z * y2;
  Single num2 = z * x2 - x * z2;
  Single num3 = x * y2 - y * x2;
  Single num4 = x * x2 + y * y2 + z * z2;
  Quaternion result;
  result.X = x * w2 + x2 * w + num;
  result.Y = y * w2 + y2 * w + num2;
  result.Z = z * w2 + z2 * w + num3;
  result.W = w * w2 - num4;
  return result;
}

Quaternion Quaternion::Multiply(Quaternion value1, Single value2) {
  Quaternion result;
  result.X = value1.X * value2;
  result.Y = value1.Y * value2;
  result.Z = value1.Z * value2;
  result.W = value1.W * value2;
  return result;
}

Quaternion Quaternion::Divide(Quaternion value1, Quaternion value2) {
  Single x = value1.X;
  Single y = value1.Y;
  Single z = value1.Z;
  Single w = value1.W;
  Single num = value2.X * value2.X + value2.Y * value2.Y + value2.Z * value2.Z + value2.W * value2.W;
  Single num2 = 1 / num;
  Single num3 = (0 - value2.X) * num2;
  Single num4 = (0 - value2.Y) * num2;
  Single num5 = (0 - value2.Z) * num2;
  Single num6 = value2.W * num2;
  Single num7 = y * num5 - z * num4;
  Single num8 = z * num3 - x * num5;
  Single num9 = x * num4 - y * num3;
  Single num10 = x * num3 + y * num4 + z * num5;
  Quaternion result;
  result.X = x * num6 + num3 * w + num7;
  result.Y = y * num6 + num4 * w + num8;
  result.Z = z * num6 + num5 * w + num9;
  result.W = w * num6 - num10;
  return result;
}

Quaternion Quaternion::op_UnaryNegation(Quaternion value) {
  Quaternion result;
  result.X = 0 - value.X;
  result.Y = 0 - value.Y;
  result.Z = 0 - value.Z;
  result.W = 0 - value.W;
  return result;
}

Quaternion Quaternion::op_Addition(Quaternion value1, Quaternion value2) {
  Quaternion result;
  result.X = value1.X + value2.X;
  result.Y = value1.Y + value2.Y;
  result.Z = value1.Z + value2.Z;
  result.W = value1.W + value2.W;
  return result;
}

Quaternion Quaternion::op_Subtraction(Quaternion value1, Quaternion value2) {
  Quaternion result;
  result.X = value1.X - value2.X;
  result.Y = value1.Y - value2.Y;
  result.Z = value1.Z - value2.Z;
  result.W = value1.W - value2.W;
  return result;
}

Quaternion Quaternion::op_Multiply(Quaternion value1, Quaternion value2) {
  Single x = value1.X;
  Single y = value1.Y;
  Single z = value1.Z;
  Single w = value1.W;
  Single x2 = value2.X;
  Single y2 = value2.Y;
  Single z2 = value2.Z;
  Single w2 = value2.W;
  Single num = y * z2 - z * y2;
  Single num2 = z * x2 - x * z2;
  Single num3 = x * y2 - y * x2;
  Single num4 = x * x2 + y * y2 + z * z2;
  Quaternion result;
  result.X = x * w2 + x2 * w + num;
  result.Y = y * w2 + y2 * w + num2;
  result.Z = z * w2 + z2 * w + num3;
  result.W = w * w2 - num4;
  return result;
}

Quaternion Quaternion::op_Multiply(Quaternion value1, Single value2) {
  Quaternion result;
  result.X = value1.X * value2;
  result.Y = value1.Y * value2;
  result.Z = value1.Z * value2;
  result.W = value1.W * value2;
  return result;
}

Quaternion Quaternion::op_Division(Quaternion value1, Quaternion value2) {
  Single x = value1.X;
  Single y = value1.Y;
  Single z = value1.Z;
  Single w = value1.W;
  Single num = value2.X * value2.X + value2.Y * value2.Y + value2.Z * value2.Z + value2.W * value2.W;
  Single num2 = 1 / num;
  Single num3 = (0 - value2.X) * num2;
  Single num4 = (0 - value2.Y) * num2;
  Single num5 = (0 - value2.Z) * num2;
  Single num6 = value2.W * num2;
  Single num7 = y * num5 - z * num4;
  Single num8 = z * num3 - x * num5;
  Single num9 = x * num4 - y * num3;
  Single num10 = x * num3 + y * num4 + z * num5;
  Quaternion result;
  result.X = x * num6 + num3 * w + num7;
  result.Y = y * num6 + num4 * w + num8;
  result.Z = z * num6 + num5 * w + num9;
  result.W = w * num6 - num10;
  return result;
}

Boolean Quaternion::op_Equality(Quaternion value1, Quaternion value2) {
  if (value1.X == value2.X && value1.Y == value2.Y && value1.Z == value2.Z) {
    return value1.W == value2.W;
  }
  return false;
}

Boolean Quaternion::op_Inequality(Quaternion value1, Quaternion value2) {
  if (value1.X == value2.X && value1.Y == value2.Y && value1.Z == value2.Z) {
    return value1.W != value2.W;
  }
  return true;
}

Boolean Quaternion::Equals(Quaternion other) {
  if (X == other.X && Y == other.Y && Z == other.Z) {
    return W == other.W;
  }
  return false;
}

Boolean Quaternion::Equals(Object obj) {
  if (rt::is<Quaternion>(obj)) {
    return Equals((Quaternion)obj);
  }
  return false;
}

String Quaternion::ToString() {
  return String::in::Format(CultureInfo::in::get_CurrentCulture(), "{{X:{0} Y:{1} Z:{2} W:{3}}}", rt::newarr<Array<Object>>(4, X, Y, Z, W));
}

Int32 Quaternion::GetHashCode() {
  return X.GetHashCode() + Y.GetHashCode() + Z.GetHashCode() + W.GetHashCode();
}

} // namespace System::Private::CoreLib::System::Numerics::QuaternionNamespace
