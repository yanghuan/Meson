#include "Matrix3x2-dep.h"

#include <System.Private.CoreLib/System/Globalization/CultureInfo-dep.h>
#include <System.Private.CoreLib/System/Math-dep.h>
#include <System.Private.CoreLib/System/MathF-dep.h>
#include <System.Private.CoreLib/System/Numerics/Matrix3x2-dep.h>

namespace System::Private::CoreLib::System::Numerics::Matrix3x2Namespace {
using namespace System::Globalization;

Matrix3x2 Matrix3x2::get_Identity() {
  return _identity;
}

Boolean Matrix3x2::get_IsIdentity() {
  if (M11 == 1 && M22 == 1 && M12 == 0 && M21 == 0 && M31 == 0) {
    return M32 == 0;
  }
  return false;
}

Vector2 Matrix3x2::get_Translation() {
  return Vector2(M31, M32);
}

void Matrix3x2::set_Translation(Vector2 value) {
  M31 = value.X;
  M32 = value.Y;
}

Matrix3x2::Matrix3x2(Single m11, Single m12, Single m21, Single m22, Single m31, Single m32) {
  M11 = m11;
  M12 = m12;
  M21 = m21;
  M22 = m22;
  M31 = m31;
  M32 = m32;
}

Matrix3x2 Matrix3x2::CreateTranslation(Vector2 position) {
  Matrix3x2 result;
  result.M11 = 1;
  result.M12 = 0;
  result.M21 = 0;
  result.M22 = 1;
  result.M31 = position.X;
  result.M32 = position.Y;
  return result;
}

Matrix3x2 Matrix3x2::CreateTranslation(Single xPosition, Single yPosition) {
  Matrix3x2 result;
  result.M11 = 1;
  result.M12 = 0;
  result.M21 = 0;
  result.M22 = 1;
  result.M31 = xPosition;
  result.M32 = yPosition;
  return result;
}

Matrix3x2 Matrix3x2::CreateScale(Single xScale, Single yScale) {
  Matrix3x2 result;
  result.M11 = xScale;
  result.M12 = 0;
  result.M21 = 0;
  result.M22 = yScale;
  result.M31 = 0;
  result.M32 = 0;
  return result;
}

Matrix3x2 Matrix3x2::CreateScale(Single xScale, Single yScale, Vector2 centerPoint) {
  Single m = centerPoint.X * (1 - xScale);
  Single m2 = centerPoint.Y * (1 - yScale);
  Matrix3x2 result;
  result.M11 = xScale;
  result.M12 = 0;
  result.M21 = 0;
  result.M22 = yScale;
  result.M31 = m;
  result.M32 = m2;
  return result;
}

Matrix3x2 Matrix3x2::CreateScale(Vector2 scales) {
  Matrix3x2 result;
  result.M11 = scales.X;
  result.M12 = 0;
  result.M21 = 0;
  result.M22 = scales.Y;
  result.M31 = 0;
  result.M32 = 0;
  return result;
}

Matrix3x2 Matrix3x2::CreateScale(Vector2 scales, Vector2 centerPoint) {
  Single m = centerPoint.X * (1 - scales.X);
  Single m2 = centerPoint.Y * (1 - scales.Y);
  Matrix3x2 result;
  result.M11 = scales.X;
  result.M12 = 0;
  result.M21 = 0;
  result.M22 = scales.Y;
  result.M31 = m;
  result.M32 = m2;
  return result;
}

Matrix3x2 Matrix3x2::CreateScale(Single scale) {
  Matrix3x2 result;
  result.M11 = scale;
  result.M12 = 0;
  result.M21 = 0;
  result.M22 = scale;
  result.M31 = 0;
  result.M32 = 0;
  return result;
}

Matrix3x2 Matrix3x2::CreateScale(Single scale, Vector2 centerPoint) {
  Single m = centerPoint.X * (1 - scale);
  Single m2 = centerPoint.Y * (1 - scale);
  Matrix3x2 result;
  result.M11 = scale;
  result.M12 = 0;
  result.M21 = 0;
  result.M22 = scale;
  result.M31 = m;
  result.M32 = m2;
  return result;
}

Matrix3x2 Matrix3x2::CreateSkew(Single radiansX, Single radiansY) {
  Single m = MathF::Tan(radiansX);
  Single m2 = MathF::Tan(radiansY);
  Matrix3x2 result;
  result.M11 = 1;
  result.M12 = m2;
  result.M21 = m;
  result.M22 = 1;
  result.M31 = 0;
  result.M32 = 0;
  return result;
}

Matrix3x2 Matrix3x2::CreateSkew(Single radiansX, Single radiansY, Vector2 centerPoint) {
  Single num = MathF::Tan(radiansX);
  Single num2 = MathF::Tan(radiansY);
  Single m = (0 - centerPoint.Y) * num;
  Single m2 = (0 - centerPoint.X) * num2;
  Matrix3x2 result;
  result.M11 = 1;
  result.M12 = num2;
  result.M21 = num;
  result.M22 = 1;
  result.M31 = m;
  result.M32 = m2;
  return result;
}

Matrix3x2 Matrix3x2::CreateRotation(Single radians) {
  radians = MathF::IEEERemainder(radians, (Single)Math::PI * 2);
  Single num;
  Single num2;
  if (radians > -1.7453294E-05 && radians < 1.7453294E-05) {
    num = 1;
    num2 = 0;
  } else if (radians > 1.570779 && radians < 1.5708138) {
    num = 0;
    num2 = 1;
  } else if (radians < -3.1415753 || radians > 3.1415753) {
    num = -1;
    num2 = 0;
  } else if (radians > -1.5708138 && radians < -1.570779) {
    num = 0;
    num2 = -1;
  } else {
    num = MathF::Cos(radians);
    num2 = MathF::Sin(radians);
  }



  Matrix3x2 result;
  result.M11 = num;
  result.M12 = num2;
  result.M21 = 0 - num2;
  result.M22 = num;
  result.M31 = 0;
  result.M32 = 0;
  return result;
}

Matrix3x2 Matrix3x2::CreateRotation(Single radians, Vector2 centerPoint) {
  radians = MathF::IEEERemainder(radians, (Single)Math::PI * 2);
  Single num;
  Single num2;
  if (radians > -1.7453294E-05 && radians < 1.7453294E-05) {
    num = 1;
    num2 = 0;
  } else if (radians > 1.570779 && radians < 1.5708138) {
    num = 0;
    num2 = 1;
  } else if (radians < -3.1415753 || radians > 3.1415753) {
    num = -1;
    num2 = 0;
  } else if (radians > -1.5708138 && radians < -1.570779) {
    num = 0;
    num2 = -1;
  } else {
    num = MathF::Cos(radians);
    num2 = MathF::Sin(radians);
  }



  Single m = centerPoint.X * (1 - num) + centerPoint.Y * num2;
  Single m2 = centerPoint.Y * (1 - num) - centerPoint.X * num2;
  Matrix3x2 result;
  result.M11 = num;
  result.M12 = num2;
  result.M21 = 0 - num2;
  result.M22 = num;
  result.M31 = m;
  result.M32 = m2;
  return result;
}

Single Matrix3x2::GetDeterminant() {
  return M11 * M22 - M21 * M12;
}

Boolean Matrix3x2::Invert(Matrix3x2 matrix, Matrix3x2& result) {
  Single num = matrix.M11 * matrix.M22 - matrix.M21 * matrix.M12;
  if (MathF::Abs(num) < Single::Epsilon) {
    result = Matrix3x2(Single::NaN, Single::NaN, Single::NaN, Single::NaN, Single::NaN, Single::NaN);
    return false;
  }
  Single num2 = 1 / num;
  result.M11 = matrix.M22 * num2;
  result.M12 = (0 - matrix.M12) * num2;
  result.M21 = (0 - matrix.M21) * num2;
  result.M22 = matrix.M11 * num2;
  result.M31 = (matrix.M21 * matrix.M32 - matrix.M31 * matrix.M22) * num2;
  result.M32 = (matrix.M31 * matrix.M12 - matrix.M11 * matrix.M32) * num2;
  return true;
}

Matrix3x2 Matrix3x2::Lerp(Matrix3x2 matrix1, Matrix3x2 matrix2, Single amount) {
  Matrix3x2 result;
  result.M11 = matrix1.M11 + (matrix2.M11 - matrix1.M11) * amount;
  result.M12 = matrix1.M12 + (matrix2.M12 - matrix1.M12) * amount;
  result.M21 = matrix1.M21 + (matrix2.M21 - matrix1.M21) * amount;
  result.M22 = matrix1.M22 + (matrix2.M22 - matrix1.M22) * amount;
  result.M31 = matrix1.M31 + (matrix2.M31 - matrix1.M31) * amount;
  result.M32 = matrix1.M32 + (matrix2.M32 - matrix1.M32) * amount;
  return result;
}

Matrix3x2 Matrix3x2::Negate(Matrix3x2 value) {
  Matrix3x2 result;
  result.M11 = 0 - value.M11;
  result.M12 = 0 - value.M12;
  result.M21 = 0 - value.M21;
  result.M22 = 0 - value.M22;
  result.M31 = 0 - value.M31;
  result.M32 = 0 - value.M32;
  return result;
}

Matrix3x2 Matrix3x2::Add(Matrix3x2 value1, Matrix3x2 value2) {
  Matrix3x2 result;
  result.M11 = value1.M11 + value2.M11;
  result.M12 = value1.M12 + value2.M12;
  result.M21 = value1.M21 + value2.M21;
  result.M22 = value1.M22 + value2.M22;
  result.M31 = value1.M31 + value2.M31;
  result.M32 = value1.M32 + value2.M32;
  return result;
}

Matrix3x2 Matrix3x2::Subtract(Matrix3x2 value1, Matrix3x2 value2) {
  Matrix3x2 result;
  result.M11 = value1.M11 - value2.M11;
  result.M12 = value1.M12 - value2.M12;
  result.M21 = value1.M21 - value2.M21;
  result.M22 = value1.M22 - value2.M22;
  result.M31 = value1.M31 - value2.M31;
  result.M32 = value1.M32 - value2.M32;
  return result;
}

Matrix3x2 Matrix3x2::Multiply(Matrix3x2 value1, Matrix3x2 value2) {
  Matrix3x2 result;
  result.M11 = value1.M11 * value2.M11 + value1.M12 * value2.M21;
  result.M12 = value1.M11 * value2.M12 + value1.M12 * value2.M22;
  result.M21 = value1.M21 * value2.M11 + value1.M22 * value2.M21;
  result.M22 = value1.M21 * value2.M12 + value1.M22 * value2.M22;
  result.M31 = value1.M31 * value2.M11 + value1.M32 * value2.M21 + value2.M31;
  result.M32 = value1.M31 * value2.M12 + value1.M32 * value2.M22 + value2.M32;
  return result;
}

Matrix3x2 Matrix3x2::Multiply(Matrix3x2 value1, Single value2) {
  Matrix3x2 result;
  result.M11 = value1.M11 * value2;
  result.M12 = value1.M12 * value2;
  result.M21 = value1.M21 * value2;
  result.M22 = value1.M22 * value2;
  result.M31 = value1.M31 * value2;
  result.M32 = value1.M32 * value2;
  return result;
}

Matrix3x2 Matrix3x2::op_UnaryNegation(Matrix3x2 value) {
  Matrix3x2 result;
  result.M11 = 0 - value.M11;
  result.M12 = 0 - value.M12;
  result.M21 = 0 - value.M21;
  result.M22 = 0 - value.M22;
  result.M31 = 0 - value.M31;
  result.M32 = 0 - value.M32;
  return result;
}

Matrix3x2 Matrix3x2::op_Addition(Matrix3x2 value1, Matrix3x2 value2) {
  Matrix3x2 result;
  result.M11 = value1.M11 + value2.M11;
  result.M12 = value1.M12 + value2.M12;
  result.M21 = value1.M21 + value2.M21;
  result.M22 = value1.M22 + value2.M22;
  result.M31 = value1.M31 + value2.M31;
  result.M32 = value1.M32 + value2.M32;
  return result;
}

Matrix3x2 Matrix3x2::op_Subtraction(Matrix3x2 value1, Matrix3x2 value2) {
  Matrix3x2 result;
  result.M11 = value1.M11 - value2.M11;
  result.M12 = value1.M12 - value2.M12;
  result.M21 = value1.M21 - value2.M21;
  result.M22 = value1.M22 - value2.M22;
  result.M31 = value1.M31 - value2.M31;
  result.M32 = value1.M32 - value2.M32;
  return result;
}

Matrix3x2 Matrix3x2::op_Multiply(Matrix3x2 value1, Matrix3x2 value2) {
  Matrix3x2 result;
  result.M11 = value1.M11 * value2.M11 + value1.M12 * value2.M21;
  result.M12 = value1.M11 * value2.M12 + value1.M12 * value2.M22;
  result.M21 = value1.M21 * value2.M11 + value1.M22 * value2.M21;
  result.M22 = value1.M21 * value2.M12 + value1.M22 * value2.M22;
  result.M31 = value1.M31 * value2.M11 + value1.M32 * value2.M21 + value2.M31;
  result.M32 = value1.M31 * value2.M12 + value1.M32 * value2.M22 + value2.M32;
  return result;
}

Matrix3x2 Matrix3x2::op_Multiply(Matrix3x2 value1, Single value2) {
  Matrix3x2 result;
  result.M11 = value1.M11 * value2;
  result.M12 = value1.M12 * value2;
  result.M21 = value1.M21 * value2;
  result.M22 = value1.M22 * value2;
  result.M31 = value1.M31 * value2;
  result.M32 = value1.M32 * value2;
  return result;
}

Boolean Matrix3x2::op_Equality(Matrix3x2 value1, Matrix3x2 value2) {
  if (value1.M11 == value2.M11 && value1.M22 == value2.M22 && value1.M12 == value2.M12 && value1.M21 == value2.M21 && value1.M31 == value2.M31) {
    return value1.M32 == value2.M32;
  }
  return false;
}

Boolean Matrix3x2::op_Inequality(Matrix3x2 value1, Matrix3x2 value2) {
  if (value1.M11 == value2.M11 && value1.M12 == value2.M12 && value1.M21 == value2.M21 && value1.M22 == value2.M22 && value1.M31 == value2.M31) {
    return value1.M32 != value2.M32;
  }
  return true;
}

Boolean Matrix3x2::Equals(Matrix3x2 other) {
  if (M11 == other.M11 && M22 == other.M22 && M12 == other.M12 && M21 == other.M21 && M31 == other.M31) {
    return M32 == other.M32;
  }
  return false;
}

Boolean Matrix3x2::Equals(Object obj) {
  if (rt::is<Matrix3x2>(obj)) {
    return Equals((Matrix3x2)obj);
  }
  return false;
}

String Matrix3x2::ToString() {
  return String::in::Format(CultureInfo::in::get_CurrentCulture(), "{{ {{M11:{0} M12:{1}}} {{M21:{2} M22:{3}}} {{M31:{4} M32:{5}}} }}", rt::newarr<Array<Object>>(6, M11, M12, M21, M22, M31, M32));
}

Int32 Matrix3x2::GetHashCode() {
  return M11.GetHashCode() + M12.GetHashCode() + M21.GetHashCode() + M22.GetHashCode() + M31.GetHashCode() + M32.GetHashCode();
}

void Matrix3x2::cctor() {
  _identity = Matrix3x2(1, 0, 0, 1, 0, 0);
}

} // namespace System::Private::CoreLib::System::Numerics::Matrix3x2Namespace
